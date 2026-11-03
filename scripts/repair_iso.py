#!/usr/bin/env python3
"""Convert / repair a raw 2352-byte/sector Mode 1 CD image into a standard 2048-byte/sector ISO."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

CD_SYNC_PATTERN = bytes.fromhex("00 ff ff ff ff ff ff ff ff ff ff 00")
CD_RAW_SECTOR = 2352
ISO_STANDARD_SECTOR = 2048
ISO_IDENTIFIER = b"\x01CD001\x01"
PVD_OFFSET_IN_SECTOR_RAW = 16


class RepairISOError(Exception):
    """Raised when ISO validation or repair fails."""


def validate_and_repair_iso(
    input_path: Path, output_path: Path, keep_backup: bool = True
) -> None:
    if not input_path.is_file():
        raise RepairISOError(f"Input file not found: {input_path}")

    file_size = input_path.stat().st_size
    if file_size == 0:
        raise RepairISOError(f"Input file is empty: {input_path}")

    # Check if already a standard 2048-byte ISO
    if file_size % ISO_STANDARD_SECTOR == 0:
        with open(input_path, "rb") as f:
            f.seek(16 * ISO_STANDARD_SECTOR)
            pvd = f.read(ISO_STANDARD_SECTOR)
            if pvd[: len(ISO_IDENTIFIER)] == ISO_IDENTIFIER:
                raise RepairISOError(
                    f"'{input_path.name}' is already a valid standard 2048-byte/sector ISO9660 image."
                )

    if file_size % CD_RAW_SECTOR != 0:
        raise RepairISOError(
            f"File size {file_size} is neither a multiple of {CD_RAW_SECTOR} (raw CD) "
            f"nor {ISO_STANDARD_SECTOR} (cooked ISO)."
        )

    total_sectors = file_size // CD_RAW_SECTOR

    # Validate header and PVD
    with open(input_path, "rb") as f:
        sec0 = f.read(CD_RAW_SECTOR)
        if len(sec0) != CD_RAW_SECTOR or sec0[:12] != CD_SYNC_PATTERN:
            raise RepairISOError("First sector does not have a valid CD sync pattern")
        if sec0[15] != 1:
            raise RepairISOError(
                f"Unsupported CD-ROM mode {sec0[15]}; only Mode 1 (2352 bytes/sector) is supported"
            )

        if total_sectors <= 16:
            raise RepairISOError("Image is too small to contain an ISO 9660 PVD")

        f.seek(16 * CD_RAW_SECTOR)
        sec16 = f.read(CD_RAW_SECTOR)
        if (
            len(sec16) != CD_RAW_SECTOR
            or sec16[:12] != CD_SYNC_PATTERN
            or sec16[PVD_OFFSET_IN_SECTOR_RAW : PVD_OFFSET_IN_SECTOR_RAW + len(ISO_IDENTIFIER)]
            != ISO_IDENTIFIER
        ):
            raise RepairISOError(
                "Sector 16 is missing CD sync or ISO 9660 Primary Volume Descriptor signature"
            )

    temp_output = output_path.with_name(f"{output_path.name}.tmp")

    try:
        with open(input_path, "rb") as fin, open(temp_output, "wb") as fout:
            for sec_idx in range(total_sectors):
                chunk = fin.read(CD_RAW_SECTOR)
                if len(chunk) != CD_RAW_SECTOR:
                    raise RepairISOError(f"Unexpected EOF reading sector {sec_idx}")
                if chunk[:12] != CD_SYNC_PATTERN:
                    raise RepairISOError(f"Sector {sec_idx} does not have valid CD sync pattern")
                if chunk[15] != 1:
                    raise RepairISOError(f"Sector {sec_idx} mode is not Mode 1")
                fout.write(chunk[16:2064])

        out_size = temp_output.stat().st_size
        expected_size = total_sectors * ISO_STANDARD_SECTOR
        if out_size != expected_size:
            raise RepairISOError(
                f"Output size mismatch: expected {expected_size}, got {out_size}"
            )

        with open(temp_output, "rb") as f:
            f.seek(16 * ISO_STANDARD_SECTOR)
            pvd = f.read(ISO_STANDARD_SECTOR)
            if pvd[: len(ISO_IDENTIFIER)] != ISO_IDENTIFIER:
                raise RepairISOError("Repaired ISO missing valid PVD at sector 16")

        if input_path.resolve() == output_path.resolve():
            backup_path = input_path.with_suffix(".bin")
            if keep_backup:
                print(f"Original raw 2352-byte/sector image preserved as: {backup_path.name}")
                input_path.rename(backup_path)
            else:
                input_path.unlink()
            temp_output.rename(output_path)
        else:
            temp_output.replace(output_path)

    except Exception:
        if temp_output.exists():
            temp_output.unlink()
        raise


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Convert raw 2352-byte/sector CD image into standard 2048-byte/sector ISO."
    )
    parser.add_argument(
        "--input",
        type=Path,
        default=Path("LuckyLuke (Track 01).iso"),
        help="Input image path (default: LuckyLuke (Track 01).iso)",
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=None,
        help="Output ISO path (default: same as input, backing up raw to .bin)",
    )
    parser.add_argument(
        "--no-backup",
        action="store_true",
        help="Do not keep raw image backup when replacing in-place",
    )

    args = parser.parse_args()
    output_path = args.output if args.output is not None else args.input

    try:
        validate_and_repair_iso(args.input, output_path, keep_backup=not args.no_backup)
        print(f"Successfully repaired ISO image: {output_path}")
        return 0
    except RepairISOError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
