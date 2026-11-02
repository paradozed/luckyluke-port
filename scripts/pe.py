#!/usr/bin/env python3
"""Minimal, strict PE32 parser for the Lucky Luke project.

Used by the decompilation pipeline to describe and byte-exactly rebuild
`Lucky.exe` (shipped on the CD as `Game.run`).

Only the features actually present in the target are implemented, and every
field is range-checked so that malformed input produces an actionable error
instead of a wrong answer.
"""
from __future__ import annotations

import struct
import sys
from dataclasses import dataclass, field


class PEFormatError(Exception):
    """Raised when the input is not a well-formed PE image we can handle."""


@dataclass
class Section:
    name: str
    virt_size: int
    virt_addr: int
    raw_size: int
    raw_ptr: int
    reloc_ptr: int
    reloc_count: int
    characteristics: int
    index: int
    header_ptr: int = 0

    @property
    def raw_end(self) -> int:
        return self.raw_ptr + self.raw_size

    @property
    def virt_end(self) -> int:
        return self.virt_addr + self.virt_size

    @property
    def spans(self) -> bool:
        return self.virt_size > self.raw_size


@dataclass
class DebugEntry:
    characteristics: int
    timestamp: int
    major: int
    minor: int
    type: int
    size: int
    rva: int
    file_ptr: int
    payload: bytes = b""


@dataclass
class PE:
    data: bytes
    dos_off: int
    coff_off: int
    opt_off: int
    machine: int
    num_sections: int
    timestamp: int
    sym_table_ptr: int
    num_symbols: int
    opt_size: int
    characteristics: int
    magic: int
    entry_rva: int
    base_of_code: int
    base_of_data: int
    image_base: int
    section_align: int
    file_align: int
    opt_extra: dict
    data_dirs: list[tuple[int, int]]
    sections: list[Section] = field(default_factory=list)
    sections_off: int = 0
    header_size: int = 0  # offset of `SizeOfHeaders`, i.e. end of headers incl. padding
    size_of_headers: int = 0

    # -- construction ---------------------------------------------------
    @classmethod
    def parse(cls, data: bytes) -> "PE":
        if len(data) < 0x40 or data[:2] != b"MZ":
            raise PEFormatError("missing MZ signature")
        dos_off = struct.unpack_from("<I", data, 0x3C)[0]
        if dos_off + 4 > len(data):
            raise PEFormatError(f"e_lfanew {dos_off:#x} out of range")
        if data[dos_off:dos_off + 4] != b"PE\0\0":
            raise PEFormatError(f"missing PE signature at {dos_off:#x}")
        coff_off = dos_off + 4
        (machine, num_sections, timestamp, sym_ptr, num_sym, opt_size,
         chars) = struct.unpack_from("<HHIIIHH", data, coff_off)
        opt_off = coff_off + 20
        if opt_off + opt_size > len(data):
            raise PEFormatError("optional header truncated")
        magic = struct.unpack_from("<H", data, opt_off)[0]
        if magic != 0x10B:
            raise PEFormatError(f"unsupported optional header magic {magic:#x}")

        entry_rva = struct.unpack_from("<I", data, opt_off + 16)[0]
        base_of_code = struct.unpack_from("<I", data, opt_off + 20)[0]
        base_of_data = struct.unpack_from("<I", data, opt_off + 24)[0]
        image_base = struct.unpack_from("<I", data, opt_off + 28)[0]
        section_align = struct.unpack_from("<I", data, opt_off + 32)[0]
        file_align = struct.unpack_from("<I", data, opt_off + 36)[0]
        if opt_size < 96:
            raise PEFormatError("optional header too small for data directories")
        num_dirs = struct.unpack_from("<I", data, opt_off + 92)[0]
        num_dirs = min(num_dirs, 16)
        dirs = [struct.unpack_from("<II", data, opt_off + 96 + 8 * i)
                for i in range(num_dirs)]
        extra = {
            "os_version": struct.unpack_from("<HH", data, opt_off + 40),
            "image_version": struct.unpack_from("<HH", data, opt_off + 44),
            "subsystem_version": struct.unpack_from("<HH", data, opt_off + 48),
            "win32_version": struct.unpack_from("<I", data, opt_off + 52)[0],
            "size_of_image": struct.unpack_from("<I", data, opt_off + 56)[0],
            "size_of_headers": struct.unpack_from("<I", data, opt_off + 60)[0],
            "checksum": struct.unpack_from("<I", data, opt_off + 64)[0],
            "subsystem": struct.unpack_from("<H", data, opt_off + 68)[0],
            "dll_characteristics": struct.unpack_from("<H", data, opt_off + 70)[0],
            "stack_reserve": struct.unpack_from("<I", data, opt_off + 72)[0],
            "stack_commit": struct.unpack_from("<I", data, opt_off + 76)[0],
            "heap_reserve": struct.unpack_from("<I", data, opt_off + 80)[0],
            "heap_commit": struct.unpack_from("<I", data, opt_off + 84)[0],
            "loader_flags": struct.unpack_from("<I", data, opt_off + 88)[0],
            "num_rva_and_sizes": struct.unpack_from("<I", data, opt_off + 92)[0],
        }
        pe = cls(data=data, dos_off=dos_off, coff_off=coff_off, opt_off=opt_off,
                 machine=machine, num_sections=num_sections, timestamp=timestamp,
                 sym_table_ptr=sym_ptr, num_symbols=num_sym, opt_size=opt_size,
                 characteristics=chars, magic=magic, entry_rva=entry_rva,
                 base_of_code=base_of_code, base_of_data=base_of_data,
                 image_base=image_base, section_align=section_align,
                 file_align=file_align, opt_extra=extra, data_dirs=dirs)
        pe.sections_off = opt_off + opt_size
        pe.size_of_headers = extra["size_of_headers"]
        pe.header_size = extra["size_of_headers"]
        for i in range(num_sections):
            off = pe.sections_off + 40 * i
            if off + 40 > len(data):
                raise PEFormatError(f"section header {i} truncated")
            name = data[off:off + 8].split(b"\0")[0].decode("latin1")
            (vsz, va, rsz, rptr, relptr, lnum_ptr, nrel, nl) = \
                struct.unpack_from("<IIIIIIHH", data, off + 8)
            sch = struct.unpack_from("<I", data, off + 36)[0]
            sec = Section(name, vsz, va, rsz, rptr, relptr, nrel, sch, i, off)
            if rptr + rsz > len(data) and rsz:
                raise PEFormatError(
                    f"section {name} raw range {rptr:#x}+{rsz:#x} exceeds file size {len(data):#x}")
            pe.sections.append(sec)
        return pe

    @classmethod
    def from_file(cls, path: str) -> "PE":
        with open(path, "rb") as fh:
            return cls.parse(fh.read())

    # -- helpers --------------------------------------------------------
    def rva_to_off(self, rva: int) -> int:
        for s in self.sections:
            if s.virt_addr <= rva < s.virt_end:
                delta = rva - s.virt_addr
                if delta >= s.raw_size:
                    raise PEFormatError(
                        f"rva {rva:#x} in {s.name} is inside virtual padding (no file bytes)")
                return s.raw_ptr + delta
        if rva < self.size_of_headers:
            return rva
        raise PEFormatError(f"rva {rva:#x} not mapped by any section")

    def off_to_rva(self, off: int) -> int:
        for s in self.sections:
            if s.raw_ptr <= off < s.raw_end:
                return s.virt_addr + (off - s.raw_ptr)
        if off < self.size_of_headers:
            return off
        raise PEFormatError(f"file offset {off:#x} not mapped")

    def off_to_va(self, off: int) -> int:
        return self.image_base + self.off_to_rva(off)

    def read_rva(self, rva: int, size: int) -> bytes:
        off = self.rva_to_off(rva)
        if off + size > len(self.data):
            raise PEFormatError("read past end of file")
        return self.data[off:off + size]

    def cstring_rva(self, rva: int, limit: int = 4096) -> str:
        off = self.rva_to_off(rva)
        end = self.data.find(b"\0", off)
        if end < 0:
            raise PEFormatError("unterminated string")
        return self.data[off:min(end, off + limit)].decode("latin1")

    @property
    def header_padding(self) -> bytes:
        """Bytes between the end of the optional header and SizeOfHeaders."""
        end = self.sections_off + 40 * self.num_sections
        return self.data[end:self.size_of_headers]

    def overlay(self) -> bytes:
        end = max((s.raw_end for s in self.sections), default=self.size_of_headers)
        return self.data[end:]

    # -- directory helpers ---------------------------------------------
    DIR_NAMES = ("export", "import", "resource", "exception", "security",
                 "basereloc", "debug", "architecture", "globalptr", "tls",
                 "load_config", "bound_import", "iat", "delay_import",
                 "clr", "reserved")

    def directory(self, name: str) -> tuple[int, int]:
        return self.data_dirs[self.DIR_NAMES.index(name)]

    def imports(self) -> list[tuple[str, list[str]]]:
        """Return [(dll_name, [import names...])] from the import directory."""
        rva, size = self.directory("import")
        if not rva:
            return []
        out = []
        off = self.rva_to_off(rva)
        while True:
            oft, ts, fc, name_rva, first_thunk = struct.unpack_from("<IIIII", self.data, off)
            if not (oft or name_rva or first_thunk):
                break
            dll = self.cstring_rva(name_rva)
            names = []
            thunk_rva = oft or first_thunk
            t = self.rva_to_off(thunk_rva)
            while True:
                v = struct.unpack_from("<I", self.data, t)[0]
                if v == 0:
                    break
                if v & 0x80000000:
                    names.append(f"ordinal#{v & 0xffff}")
                else:
                    names.append(self.cstring_rva(v + 2))
                t += 4
            out.append((dll, names))
            off += 20
        return out

    def exports(self) -> list[tuple[int, str]]:
        rva, size = self.directory("export")
        if not rva:
            return []
        e = self.rva_to_off(rva)
        (flags, ts, maj, mnr, name_rva, base, nfunc, nname, afunc, aname, aord) = \
            struct.unpack_from("<IIHHIIIIIII", self.data, e)
        funcs = [struct.unpack_from("<I", self.data, self.rva_to_off(afunc) + 4 * i)[0]
                 for i in range(nfunc)]
        names = [(struct.unpack_from("<I", self.data, self.rva_to_off(aname) + 4 * i)[0],
                  struct.unpack_from("<H", self.data, self.rva_to_off(aord) + 2 * i)[0])
                 for i in range(nname)]
        out = []
        for n_rva, idx in names:
            out.append((funcs[idx] if idx < len(funcs) else 0, self.cstring_rva(n_rva)))
        return out

    def debug_entries(self) -> list[DebugEntry]:
        rva, size = self.directory("debug")
        if not rva or not size:
            return []
        off = self.rva_to_off(rva)
        res = []
        for i in range(size // 28):
            e = off + 28 * i
            ch, ts, maj, mnr, typ, sz, drva, ptr = struct.unpack_from("<IIHHIIII", self.data, e)
            de = DebugEntry(ch, ts, maj, mnr, typ, sz, drva, ptr)
            de.payload = self.data[ptr:ptr + sz]
            res.append(de)
        return res

    def relocations(self):
        """Yield (page_rva, [(type, offset_in_page)...])."""
        rva, size = self.directory("basereloc")
        if not rva:
            return
        off = self.rva_to_off(rva)
        end = off + size
        while off + 8 <= end:
            page, blocksize = struct.unpack_from("<II", self.data, off)
            if blocksize < 8 or off + blocksize > end:
                raise PEFormatError(f"bad relocation block at {off:#x}")
            items = []
            for j in range((blocksize - 8) // 2):
                w = struct.unpack_from("<H", self.data, off + 8 + 2 * j)[0]
                items.append((w >> 12, w & 0xFFF))
            yield page, items
            off += blocksize

    # -- reporting ------------------------------------------------------
    def summary(self) -> str:
        lines = []
        a = lines.append
        a(f"File size            : {len(self.data)} bytes")
        a(f"e_lfanew             : {self.dos_off:#010x}")
        a(f"Machine              : {self.machine:#06x}")
        a(f"NumberOfSections     : {self.num_sections}")
        a(f"TimeDateStamp        : {self.timestamp:#010x}")
        a(f"Characteristics      : {self.characteristics:#06x}")
        a(f"ImageBase            : {self.image_base:#010x}")
        a(f"EntryPoint RVA       : {self.entry_rva:#010x} (VA {self.image_base + self.entry_rva:#010x})")
        a(f"SizeOfImage          : {self.opt_extra['size_of_image']:#x}")
        a(f"SizeOfHeaders        : {self.size_of_headers:#x}")
        a(f"Subsystem            : {self.opt_extra['subsystem']}")
        a(f"Linker/OS version    : {self.opt_extra['os_version']} image {self.opt_extra['image_version']}"
          f" subsystem {self.opt_extra['subsystem_version']}")
        a("Sections:")
        for s in self.sections:
            a(f"  [{s.index}] {s.name:<8} VA {s.virt_addr:#08x} VSize {s.virt_size:#08x}"
              f" Raw {s.raw_ptr:#08x}+{s.raw_size:#08x} Chars {s.characteristics:#08x}")
        a("Data directories:")
        for i, (rva, size) in enumerate(self.data_dirs):
            if rva or size:
                a(f"  {self.DIR_NAMES[i]:<12} RVA {rva:#08x} Size {size:#010x}")
        return "\n".join(lines)


def main(argv):
    if len(argv) < 2:
        print(f"usage: {argv[0]} <pe file>", file=sys.stderr)
        return 2
    pe = PE.from_file(argv[1])
    print(pe.summary())
    print("Imports:")
    for dll, names in pe.imports():
        print(f"  {dll} ({len(names)})")
        for n in names:
            print(f"    {n}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
