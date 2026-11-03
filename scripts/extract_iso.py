#!/usr/bin/env python3
"""Extract files from a Lucky Luke CD-ROM ISO image (raw Mode 1 or standard ISO)."""

from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
from pathlib import Path

CD_SYNC_PATTERN = bytes.fromhex("00 ff ff ff ff ff ff ff ff ff ff 00")
ISO_STANDARD_SECTOR = 2048
CD_RAW_SECTOR = 2352
PVD_OFFSET_IN_SECTOR_COOKED = 0
PVD_OFFSET_IN_SECTOR_RAW = 16
ISO_IDENTIFIER = b"\x01CD001\x01"


class ISOExtractionError(Exception):
    """Raised when ISO validation or extraction fails."""


def validate_and_extract_iso(iso_path: Path, output_dir: Path) -> int:
    """Validate ISO signatures and extract contents into output_dir."""
    if not iso_path.is_file():
        raise ISOExtractionError(f"ISO image not found: {iso_path}")

    file_size = iso_path.stat().st_size
    if file_size == 0:
        raise ISOExtractionError(f"ISO image is empty: {iso_path}")

    # Determine sector mode by checking file size and signatures
    is_raw_mode1 = False
    if file_size % CD_RAW_SECTOR == 0:
        with open(iso_path, "rb") as f:
            first_sector = f.read(CD_RAW_SECTOR)
            if len(first_sector) == CD_RAW_SECTOR and first_sector[:12] == CD_SYNC_PATTERN:
                mode = first_sector[15]
                if mode != 1:
                    raise ISOExtractionError(
                        f"Unsupported CD-ROM mode {mode}; only Mode 1 (2352 bytes/sector) is supported"
                    )
                # Verify ISO Primary Volume Descriptor at sector 16
                f.seek(16 * CD_RAW_SECTOR)
                sec16 = f.read(CD_RAW_SECTOR)
                if (
                    len(sec16) == CD_RAW_SECTOR
                    and sec16[:12] == CD_SYNC_PATTERN
                    and sec16[PVD_OFFSET_IN_SECTOR_RAW : PVD_OFFSET_IN_SECTOR_RAW + len(ISO_IDENTIFIER)]
                    == ISO_IDENTIFIER
                ):
                    is_raw_mode1 = True
    elif file_size % ISO_STANDARD_SECTOR == 0:
        with open(iso_path, "rb") as f:
            f.seek(16 * ISO_STANDARD_SECTOR)
            sec16 = f.read(ISO_STANDARD_SECTOR)
            if sec16[:len(ISO_IDENTIFIER)] == ISO_IDENTIFIER:
                is_raw_mode1 = False
            else:
                raise ISOExtractionError(
                    "Missing ISO 9660 Primary Volume Descriptor signature at sector 16"
                )
    else:
        raise ISOExtractionError(
            f"File size {file_size} is not a multiple of {CD_RAW_SECTOR} or {ISO_STANDARD_SECTOR}"
        )

    # Check for extraction tool (bsdtar)
    bsdtar = shutil.which("bsdtar")
    if not bsdtar:
        raise ISOExtractionError(
            "External tool 'bsdtar' not found. Please install libarchive/bsdtar to extract ISO images."
        )

    output_dir.mkdir(parents=True, exist_ok=True)

    cmd = [bsdtar, "-xf", "-", "-C", str(output_dir)]
    proc = subprocess.Popen(cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    file_count = 0
    with open(iso_path, "rb") as f:
        while True:
            chunk = f.read(CD_RAW_SECTOR if is_raw_mode1 else ISO_STANDARD_SECTOR)
            if not chunk:
                break
            if is_raw_mode1:
                if len(chunk) != CD_RAW_SECTOR:
                    raise ISOExtractionError("Truncated sector encountered in raw ISO image")
                data = chunk[16:2064]
            else:
                if len(chunk) != ISO_STANDARD_SECTOR:
                    raise ISOExtractionError("Truncated sector encountered in standard ISO image")
                data = chunk
            try:
                proc.stdin.write(data)
            except BrokenPipeError:
                break

    proc.stdin.close()
    out, err = proc.communicate()

    if proc.returncode != 0:
        error_msg = err.decode("utf-8", errors="replace").strip()
        raise ISOExtractionError(f"bsdtar extraction failed with code {proc.returncode}: {error_msg}")

    # Count extracted files
    for _, _, files in os.walk(output_dir):
        file_count += len(files)

    return file_count


def main() -> int:
    parser = argparse.ArgumentParser(description="Extract Lucky Luke CD ISO image.")
    parser.add_argument(
        "--iso",
        type=Path,
        default=Path("LuckyLuke (Track 01).iso"),
        help="Path to ISO image (default: LuckyLuke (Track 01).iso)",
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=Path("iso_extract"),
        help="Destination directory (default: iso_extract)",
    )

    args = parser.parse_args()

    try:
        count = validate_and_extract_iso(args.iso, args.output)
        print(f"Successfully extracted {count} files to {args.output}")
        return 0
    except ISOExtractionError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
