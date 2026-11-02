#!/usr/bin/env python3
"""Extract one validated member from a Lucky Luke KXP archive."""

from __future__ import annotations

import argparse
import struct
from pathlib import Path


class KXPError(Exception):
    pass


ENCRYPTED_HEADER = bytes.fromhex(
    "4d 46 53 54 52 46 4b 4a 48 50 28 25 5e 25 31 32 "
    "37 36 23 7d 2b bd 9d 61 6f 69 62 6e 32 34 3c 3e"
)


def extract_member(archive_path: Path, member_name: str, key: bytes) -> bytes:
    data = archive_path.read_bytes()
    if len(data) < 0x29 or data[:3] != b"KXP" or data[3] != 1:
        raise KXPError("invalid or unsupported KXP header")

    encrypted = data[5] != 0
    if encrypted:
        if not key:
            raise KXPError("encrypted KXP archive requires a key")
        decoded_header = bytes(
            value ^ key[offset % len(key)]
            for offset, value in enumerate(data[5:5 + len(ENCRYPTED_HEADER)])
        )
        if decoded_header != ENCRYPTED_HEADER:
            raise KXPError("encrypted KXP header discriminator does not match the game")
    index_offset = struct.unpack_from("<I", data, 0x25)[0]
    if index_offset > len(data) - 3 or data[index_offset] != ord("I"):
        raise KXPError("KXP index offset or signature is invalid")

    entry_count = struct.unpack_from("<H", data, index_offset + 1)[0]
    entries_offset = index_offset + 3
    entries_size = entry_count * 17
    if entries_size > len(data) - entries_offset:
        raise KXPError("KXP member index is truncated")

    expected_name = member_name.encode("ascii").upper()
    member_offset = None
    for index in range(entry_count):
        entry_offset = entries_offset + index * 17
        raw_name = data[entry_offset:entry_offset + 13]
        name = raw_name.split(b"\0", 1)[0].upper()
        payload_offset = struct.unpack_from("<I", data, entry_offset + 13)[0]
        if name == expected_name:
            member_offset = payload_offset
            break

    if member_offset is None:
        raise KXPError(f"member not found in KXP archive: {member_name}")
    if member_offset > len(data) - 9:
        raise KXPError(f"member header is out of bounds: {member_name}")

    payload_size = struct.unpack_from("<I", data, member_offset + 5)[0]
    payload_start = member_offset + 9
    if payload_size == 0 or payload_size > len(data) - payload_start:
        raise KXPError(f"member payload is truncated or invalid: {member_name}")

    payload = bytearray(data[payload_start:payload_start + payload_size])
    if encrypted:
        if not key:
            raise KXPError("encrypted KXP archive requires a key")
        for offset in range(len(payload)):
            key_byte = key[offset % len(key)]
            if payload[offset] != 0 and payload[offset] != key_byte:
                payload[offset] ^= key_byte
    return bytes(payload)


def validate_pcx(data: bytes) -> tuple[int, int]:
    if len(data) < 128 or data[0] != 0x0A:
        raise KXPError("member is not a complete PCX image")
    if data[2] != 1 or data[3] != 8 or data[65] not in (1, 3):
        raise KXPError("only 8-bit indexed or three-plane RGB PCX images are supported")

    xmin, ymin, xmax, ymax = struct.unpack_from("<4H", data, 4)
    width = xmax - xmin + 1
    height = ymax - ymin + 1
    bytes_per_line = struct.unpack_from("<H", data, 66)[0]
    if width <= 0 or height <= 0 or bytes_per_line < width:
        raise KXPError("invalid PCX dimensions or scanline stride")
    if data[65] == 1 and data[-769] != 0x0C:
        raise KXPError("PCX palette marker is missing")
    return width, height


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("archive", type=Path)
    parser.add_argument("member")
    parser.add_argument("output", type=Path)
    parser.add_argument("--key", default="lucky")
    args = parser.parse_args()

    try:
        payload = extract_member(args.archive, args.member, args.key.encode("ascii"))
        width, height = validate_pcx(payload)
    except (OSError, UnicodeEncodeError, struct.error, KXPError) as error:
        parser.error(str(error))

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(payload)
    print(f"Extracted {args.member}: {width}x{height}, {len(payload)} bytes -> {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
