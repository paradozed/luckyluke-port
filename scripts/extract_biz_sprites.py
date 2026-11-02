#!/usr/bin/env python3
"""Extract the eight animated option-menu sprites from a Lucky Luke BIZ file."""

from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path


class BIZError(Exception):
    pass


MENU_OBJECTS = (
    (15, 0x120),
    (16, 0x12A),
    (17, 0x11E),
    (18, 0x122),
    (19, 0x11F),
    (20, 0x126),
    (21, 0x121),
    (22, 0x12E),
)
PAGE_BYTES = 0x8000
PAGE_PIXELS = 0x10000
PAGE_SIZE = 256


def u16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<H", data, offset)[0]


def s16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<h", data, offset)[0]


def checked_region(data: bytes, offset: int, size: int, description: str) -> None:
    if offset < 0 or size < 0 or offset > len(data) or size > len(data) - offset:
        raise BIZError(f"{description} is out of bounds (offset 0x{offset:x}, size 0x{size:x})")


def load_biz(data: bytes) -> tuple[int, int, int, int, int, int, int, int, int, int]:
    if len(data) < 4:
        raise BIZError("file is too short to contain a BIZ header offset")
    header = struct.unpack_from("<I", data, 0)[0]
    checked_region(data, header, 28, "BIZ seven-DWORD header")
    object_count, sprite_count, tile_count, page_count, *_ = struct.unpack_from(
        "<7I", data, header
    )
    if not (1 <= page_count <= 16):
        raise BIZError(f"unsupported texture page count: {page_count}")

    object_offset = header + 28
    object_bytes = object_count * 4
    sprite_offset = object_offset + object_bytes
    sprite_bytes = sprite_count * 20
    tile_offset = sprite_offset + sprite_bytes
    tile_bytes = tile_count * 16
    page_offset = tile_offset + tile_bytes
    checked_region(data, object_offset, object_bytes, "BIZ object table")
    checked_region(data, sprite_offset, sprite_bytes, "BIZ sprite table")
    checked_region(data, tile_offset, tile_bytes, "BIZ tile table")
    checked_region(data, page_offset, page_count * PAGE_BYTES, "BIZ texture pages")
    return (
        object_count,
        sprite_count,
        tile_count,
        page_count,
        object_offset,
        sprite_offset,
        tile_offset,
        page_offset,
        header,
        len(data),
    )


def expand_page(data: bytes, offset: int) -> bytearray:
    packed = data[offset : offset + PAGE_BYTES]
    pixels = bytearray(PAGE_PIXELS)
    for index, value in enumerate(packed):
        pixels[index * 2] = value & 0x0F
        pixels[index * 2 + 1] = value >> 4
    return pixels


def build_page_palette(
    pages: list[bytearray], tile_data: bytes, tile_offset: int, tile_id: int
) -> list[tuple[int, int, int, int]]:
    record = tile_offset + tile_id * 16
    x, y = s16(tile_data, record), s16(tile_data, record + 2)
    page_id = u16(tile_data, record + 12) & 0x1F
    if page_id >= len(pages):
        raise BIZError(f"tile {tile_id} refers to missing texture page {page_id}")
    if x < 0 or y < 0 or x * 4 + 64 > PAGE_SIZE or y >= PAGE_SIZE:
        raise BIZError(f"tile {tile_id} has an invalid palette rectangle")

    pixels = pages[page_id]
    palette: list[tuple[int, int, int, int]] = []
    for color_index in range(16):
        base = y * PAGE_SIZE + x * 4 + color_index * 4
        packed = (
            pixels[base]
            | (pixels[base + 1] << 4)
            | (pixels[base + 2] << 8)
            | (pixels[base + 3] << 12)
        )
        red = packed & 0x1F
        green = (packed >> 5) & 0x1F
        blue = (packed >> 10) & 0x1F
        alpha = 0 if red + green + blue == 0 else 255
        palette.append((red * 255 // 31, green * 255 // 31, blue * 255 // 31, alpha))
    return palette


def object_tiles(data: bytes, offset: int, count: int) -> dict[int, list[int]]:
    result: dict[int, list[int]] = {}
    for index in range(count):
        record = offset + index * 4
        sprite_id, tile_id = u16(data, record), u16(data, record + 2)
        entries = result.setdefault(sprite_id, [])
        if tile_id not in entries:
            entries.append(tile_id)
    return result


def extract_sprite(
    data: bytes,
    pages: list[bytearray],
    sprite_offset: int,
    tile_offset: int,
    sprite_id: int,
    palette_tile_id: int,
    sprite_tiles: dict[int, list[int]],
):
    from PIL import Image

    record = sprite_offset + sprite_id * 20
    u, v = data[record + 16], data[record + 17]
    width = s16(data, record + 4) * 4
    height = s16(data, record + 6)
    if width <= 0 or height <= 0:
        raise BIZError(f"sprite {sprite_id} has invalid dimensions {width}x{height}")
    width = min(width, PAGE_SIZE - u)
    height = min(height, PAGE_SIZE - v)

    palette_slot = data[record + 18]
    choices = sprite_tiles.get(sprite_id, [])
    if palette_slot >= len(choices):
        raise BIZError(
            f"sprite {sprite_id} palette slot {palette_slot} has only {len(choices)} tile choices"
        )
    selected_tile = choices[palette_slot]
    if selected_tile != palette_tile_id:
        raise BIZError(
            f"object refers to tile {palette_tile_id}, but sprite {sprite_id} selects tile {selected_tile}"
        )

    tile_record = tile_offset + selected_tile * 16
    page_id = u16(data, tile_record + 12) & 0x1F
    if page_id >= len(pages):
        raise BIZError(f"tile {selected_tile} refers to missing texture page {page_id}")
    palette = build_page_palette(pages, data, tile_offset, selected_tile)
    pixel_page_id = u16(data, record + 14)
    if pixel_page_id >= len(pages):
        raise BIZError(f"sprite {sprite_id} refers to missing pixel page {pixel_page_id}")
    source = pages[pixel_page_id]
    image = Image.new("RGBA", (width, height))
    for y in range(height):
        row = (v + y) * PAGE_SIZE + u
        for x in range(width):
            image.putpixel((x, y), palette[source[row + x]])
    return image, page_id, selected_tile, u, v


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("biz", type=Path, help="localized menu BIZ file, for example option_f.biz")
    parser.add_argument("output", type=Path, help="PNG contact sheet to write")
    args = parser.parse_args()

    try:
        from PIL import Image, ImageDraw

        data = args.biz.read_bytes()
        (
            object_count,
            sprite_count,
            tile_count,
            page_count,
            object_offset,
            sprite_offset,
            tile_offset,
            page_offset,
            _header,
            _file_size,
        ) = load_biz(data)
        for instance_id, object_id in MENU_OBJECTS:
            if object_id >= object_count:
                raise BIZError(f"menu object {object_id} is outside {object_count} BIZ objects")

        pages = [expand_page(data, page_offset + i * PAGE_BYTES) for i in range(page_count)]
        choices = object_tiles(data, object_offset, object_count)
        sheet = Image.new("RGB", (4 * 220, 2 * 180), (35, 35, 40))
        draw = ImageDraw.Draw(sheet)

        for index, (instance_id, object_id) in enumerate(MENU_OBJECTS):
            object_record = object_offset + object_id * 4
            sprite_id = u16(data, object_record)
            tile_id = u16(data, object_record + 2)
            if sprite_id >= sprite_count or tile_id >= tile_count:
                raise BIZError(f"object {object_id} contains an out-of-range sprite or tile index")
            image, page_id, selected_tile, u, v = extract_sprite(
                data,
                pages,
                sprite_offset,
                tile_offset,
                sprite_id,
                tile_id,
                choices,
            )
            preview = image.resize(
                (image.width * 3, image.height * 3), Image.Resampling.NEAREST
            )
            col, row = index % 4, index // 4
            x, y = col * 220 + 8, row * 180 + 8
            sheet.paste(preview.convert("RGB"), (x, y), preview.getchannel("A"))
            draw.text(
                (x, y + preview.height + 6),
                f"ID {instance_id} / sprite {sprite_id} / tile {tile_id}",
                fill="white",
            )
            print(
                f"instance {instance_id}: object {object_id}, sprite {sprite_id}, "
                f"tile {selected_tile}, page {page_id}, UV ({u}, {v}) "
                f"{image.width}x{image.height}"
            )

        args.output.parent.mkdir(parents=True, exist_ok=True)
        sheet.save(args.output)
    except (OSError, struct.error, BIZError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1
    except ImportError as error:
        print("error: Pillow is required to write the PNG contact sheet", file=sys.stderr)
        return 1

    print(f"Wrote sprite contact sheet: {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
