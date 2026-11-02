#ifndef LL_COD_H
#define LL_COD_H

#include <stddef.h>
#include <stdint.h>

/*
 * Experimental port-side parser for a guessed level-data schema.
 *
 * This schema is NOT confirmed for original .cod files: those begin with
 * "SOOL" and are sent to the SOOL runtime. The original object/sprite/tile/
 * texture layout is read from .biz files by FUN_0044b320. This parser's CRC3
 * footer and header assumptions do not match the original .cod or .biz files.
 *
 * Experimental format currently accepted by ll_cod_open():
 *
 *   Offset 0:               uint32  offset_to_header_fields
 *   At offset_to_header_fields:
 *     Offset 0:   uint32  num_objects        (4 bytes per object)
 *     Offset 4:   uint32  num_sprites        (20 bytes per sprite)
 *     Offset 8:   uint32  num_tiles          (16 bytes per tile)
 *     Offset 12:  uint32  num_texture_pages  (0x8000 bytes per page)
 *     Offset 16-27: 3 more uint32 header fields
 *   After header fields (28 bytes):
 *     Object array:     num_objects * 4 bytes   (uint16 type each, padded)
 *     Sprite array:     num_sprites * 20 bytes  (0x14 per sprite)
 *     Tile array:       num_tiles * 16 bytes    (0x10 per tile)
 *     Texture pages:    num_texture_pages * 0x8000 bytes (nibble-packed pixels)
 *   End - 8:            "CRC3" signature (0x33435243)
 *   End - 4:            CRC-32 over bytes [0 .. end-8)
 *
 *   Sprite entry (20 bytes):
 *     uint16  field_0   object type
 *     uint16  field_2   x position
 *     uint16  field_4   y position
 *     uint16  field_6   width / frame count
 *     uint16  field_8   height / frame count
 *     uint16  field_a   unknown
 *     uint16  field_c   texture page index (& 0x1f)
 *     int16   field_e   unknown
 *     int16   field_10  unknown
 *     uint8   field_12  flags / state
 *
 * Texture page pixel data is nibble-packed: each 32-bit value contains
 * 8 pixels (4 bits each), which are indices into a CLUT.  The CLUT is
 * built from PCX palettes loaded from KXP archives.  Without the CLUT,
 * texture pages cannot be decoded to RGBA.
 *
 * All integer fields are little-endian.
 *
 * This module reads an experimental buffer from memory. It must not be
 * treated as a parser for original Lucky Luke scene files.
 */

typedef struct {
    uint16_t type;
    int16_t x;
    int16_t y;
    uint16_t w;
    uint16_t h;
    uint16_t field_a;
    uint16_t texture_page;  /* texture page index (& 0x1f) */
    int16_t field_e;
    int16_t field_10;
    uint8_t  flags;         /* flags / state */
} LL_CodSprite;

/* Parsed experimental data contents. */
typedef struct {
    uint32_t num_objects;
    uint32_t num_sprites;
    uint32_t num_tiles;
    uint32_t num_texture_pages;
    uint32_t header_field_4;
    uint32_t header_field_5;
    uint32_t header_field_6;

    uint16_t *object_types;       /* num_objects entries */
    LL_CodSprite *sprites;        /* num_sprites entries */
    uint8_t *tile_data;           /* num_tiles * 16 bytes */
    uint8_t *texture_page_data;   /* num_texture_pages * 0x8000 bytes */

    const uint8_t *raw_data;      /* pointer into file buffer (not owned) */
    size_t raw_size;
} LL_CodFile;

/* Open and parse a COD file from a memory buffer.  Returns 1 on success,
 * 0 on any error (bad signature, truncated data, CRC mismatch).  The
 * buffer must remain valid for the lifetime of the LL_CodFile. */
int ll_cod_open(LL_CodFile *cod, const unsigned char *data, size_t data_size);

/* Release resources held by a COD file (frees internally allocated arrays). */
void ll_cod_close(LL_CodFile *cod);

/* Returns 1 if the COD file was successfully opened. */
int ll_cod_is_valid(const LL_CodFile *cod);

/* Returns a pointer to the raw texture page data for the given page index,
 * or NULL if the index is out of range.  Each page is 0x8000 bytes. */
const unsigned char *ll_cod_get_texture_page(const LL_CodFile *cod,
                                             uint32_t page_index,
                                             size_t *out_size);

/* CLUT (Color Look-Up Table) built from PCX palette data.
 * The original game converts each PCX palette entry (RGB bytes) to 5-bit
 * values, packs them with FUN_004318a0 into a 16-bit color, then uses the
 * CLUT to look up colors when rendering nibble-packed texture pages. */
typedef struct {
    unsigned char rgba[256][4];  /* 256 RGBA entries */
    int valid;                   /* 1 when CLUT has been built */
} LL_CodClut;

/* Build a CLUT from PCX palette data.  The palette is 256 entries of 3 bytes
 * each (RGB).  Each channel is shifted right by 3 to get 5-bit values, then
 * packed with FUN_004318a0 semantics (RGB555 with alpha bit).  Returns 1 on
 * success. */
int ll_cod_clut_build_from_pcx_palette(LL_CodClut *clut,
                                       const unsigned char *palette_rgb,
                                       int palette_entries);

/* Decode a COD texture page to RGBA pixels.
 *
 * COD texture pages are 128x128 pixels stored as 16-bit RGB555 values
 * (2 bytes per pixel, 0x8000 bytes total).  Each 16-bit value has the
 * layout B[4:0] | G[4:0]<<5 | R[4:0]<<10 (matching FUN_004318a0's
 * non-"Soft" branch).  Output is written to rgba_out which must hold at
 * least 128 * 128 * 4 bytes.  Returns 1 on success. */
int ll_cod_decode_texture_page(const unsigned char *page_data,
                               size_t page_size,
                               unsigned char *rgba_out);

#endif
