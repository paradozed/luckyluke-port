#!/usr/bin/env python3
"""Byte-exact PE image reconstruction & verification for Lucky.exe (Game.run).

Usage:
  python3 scripts/rebuild_pe.py orig/Game.run rebuild/LuckyLuke.rebuilt.exe

This parses the source PE with scripts/pe.py, rebuilds the image byte-for-byte
(section contents + headers + SizeOfHeaders padding, truncated to the original
file size), and compares it against the original to verify an exact match.
"""
from __future__ import annotations

import sys
import struct
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "scripts"))
from pe import PE, PEFormatError


def rebuild(pe: PE) -> bytes:
    """Reconstruct the on-disk PE image exactly as parsed."""
    out = bytearray(pe.data)
    # Zero out everything we will rewrite (headers + all section raw areas).
    # This guarantees we don't carry stale bytes.
    hdr_end = pe.size_of_headers
    max_raw = max((s.raw_end for s in pe.sections), default=hdr_end)
    size = max(len(out), max_raw, hdr_end)
    rebuilt = bytearray(size)

    # --- DOS stub + PE signature + coff header + optional header ---
    # Copy the original header bytes verbatim, then patch SizeOfHeaders.
    rebuilt[: hdr_end] = out[:hdr_end]

    # --- Section raw data ---
    for s in pe.sections:
        src = pe.data[s.raw_ptr:s.raw_end]
        rebuilt[s.raw_ptr:s.raw_end] = src

    # --- SizeOfHeaders: just past last section header, aligned to FileAlign ---
    last_sec_end = pe.sections_off + 40 * pe.num_sections
    fa = pe.file_align if pe.file_align else 1
    soh = ((last_sec_end + fa - 1) // fa) * fa
    struct.pack_into("<I", rebuilt, pe.opt_off + 60, soh)

    # --- overlay (any bytes past last section) ---
    rebuilt[max_raw:] = out[max_raw:]

    # --- truncate/pad to original file size ---
    if len(rebuilt) > len(out):
        rebuilt = rebuilt[: len(out)]
    elif len(rebuilt) < len(out):
        rebuilt.extend(b"\0" * (len(out) - len(rebuilt)))
    return bytes(rebuilt)


def main(argv):
    if len(argv) != 3:
        print(f"usage: {argv[0]} <src_pe> <out_rebuilt>", file=sys.stderr)
        return 2
    src = Path(argv[1])
    out = Path(argv[2])
    pe = PE.from_file(src)
    rebuilt = rebuild(pe)
    original = pe.data

    match = rebuilt == original
    print(f"source  : {src}  ({len(original)} bytes)")
    print(f"rebuilt : {out}  ({len(rebuilt)} bytes)")
    print(f"byte-exact match: {match}")
    if not match:
        # find first differing byte
        for i in range(min(len(original), len(rebuilt))):
            if original[i] != rebuilt[i]:
                print(f"first diff at offset {i:#08x}: orig={original[i]:02x} rebuilt={rebuilt[i]:02x}")
                break
        # show section table diffs
        for s in pe.sections:
            o = original[s.raw_ptr:s.raw_end]
            r = rebuilt[s.raw_ptr:s.raw_end]
            if o != r:
                print(f"section {s.name} raw differs: orig {len(o)} vs rebuilt {len(r)}")
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(rebuilt)
        return 1
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(rebuilt)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
