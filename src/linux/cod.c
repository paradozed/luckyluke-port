#include "cod.h"

#include <stdlib.h>
#include <string.h>

/* CRC32 lookup table used by the original game (at 0x4b81fc in the PE).
 * This is the standard reflected CRC32 table with polynomial 0xEDB88320. */
static uint32_t cod_crc32_table[256];

static int cod_crc_table_init = 0;

static void cod_init_crc_table(void)
{
    uint32_t crc;
    int i;
    int j;

    if (cod_crc_table_init) {
        return;
    }

    for (i = 0; i < 256; i++) {
        crc = (uint32_t)i;
        for (j = 0; j < 8; j++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320u;
            } else {
                crc = crc >> 1;
            }
        }
        cod_crc32_table[i] = crc;
    }

    cod_crc_table_init = 1;
}

static uint32_t cod_crc32(const unsigned char *data, size_t len, uint32_t crc)
{
    size_t i;

    cod_init_crc_table();

    crc = crc ^ 0xffffffffu;
    for (i = 0; i < len; i++) {
        crc = cod_crc32_table[(crc ^ data[i]) & 0xff] ^ (crc >> 8);
    }
    return crc ^ 0xffffffffu;
}

static uint32_t read_u32le(const unsigned char *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static uint16_t read_u16le(const unsigned char *p)
{
    return (uint16_t)((uint32_t)p[0] | ((uint32_t)p[1] << 8));
}

static int16_t read_i16le(const unsigned char *p)
{
    return (int16_t)read_u16le(p);
}

/* Experimental buffer layout (not the original COD or BIZ format):
 *
 *   Offset 0:               uint32  offset_to_header_fields
 *   Offset offset_to_hdr:   uint32  num_objects        (4 bytes per object)
 *   Offset offset_to_hdr+4: uint32  num_sprites        (20 bytes per sprite)
 *   Offset offset_to_hdr+8: uint32  num_tiles          (16 bytes per tile)
 *   Offset offset_to_hdr+12: uint32 num_texture_pages  (0x8000 bytes per page)
 *   Offset offset_to_hdr+16..27: 3 more uint32 header fields
 *   After header fields:    object array   (num_objects * 4 bytes, uint16 type each)
 *   After object array:     sprite array   (num_sprites * 20 bytes)
 *   After sprite array:     tile array     (num_tiles * 16 bytes)
 *   After tile array:       texture pages  (num_texture_pages * 0x8000 bytes)
 *   End - 8:                "CRC3" signature (0x33435243)
 *   End - 4:                CRC-32 value over bytes [0 .. end-8)
 */

#define COD_SIGNATURE_OFFSET(data_size) ((data_size) - 8)
#define COD_CRC_OFFSET(data_size)       ((data_size) - 4)
#define COD_MIN_SIZE 12  /* 4 (offset) + 8 (CRC footer) */
#define COD_TEXTURE_PAGE_SIZE 0x8000u  /* 32768 bytes per texture page */

int ll_cod_open(LL_CodFile *cod, const unsigned char *data, size_t data_size)
{
    uint32_t offset;
    uint32_t stored_crc;
    uint32_t computed_crc;
    const unsigned char *base;
    size_t needed;
    size_t arrays_start;

    if (cod == NULL || data == NULL) {
        return 0;
    }

    memset(cod, 0, sizeof(*cod));

    cod->raw_data = data;
    cod->raw_size = data_size;

    /* Minimum size: offset field + CRC footer */
    if (data_size < COD_MIN_SIZE) {
        return 0;
    }

    /* Validate CRC3 signature at end - 8 */
    if (read_u32le(data + COD_SIGNATURE_OFFSET(data_size)) != 0x33435243u) {
        return 0;
    }

    /* Read and validate CRC-32 */
    stored_crc = read_u32le(data + COD_CRC_OFFSET(data_size));
    computed_crc = cod_crc32(data, COD_SIGNATURE_OFFSET(data_size), 0);
    if (computed_crc != stored_crc) {
        return 0;
    }

    /* Read offset to header fields */
    offset = read_u32le(data + 0);
    if (offset > data_size - COD_SIGNATURE_OFFSET(data_size) - 7 * 4) {
        return 0;
    }

    base = data + offset;

    /* Read the 7 header count fields */
    cod->num_objects = read_u32le(base + 0);
    cod->num_sprites = read_u32le(base + 4);
    cod->num_tiles = read_u32le(base + 8);
    cod->num_texture_pages = read_u32le(base + 12);
    cod->header_field_4 = read_u32le(base + 16);
    cod->header_field_5 = read_u32le(base + 20);
    cod->header_field_6 = read_u32le(base + 24);

    /* Arrays start after the 7 header fields */
    arrays_start = (size_t)offset + 28;

    /* Validate that all arrays fit within the file bounds (before CRC footer) */
    needed = (size_t)cod->num_objects * 4u +
             (size_t)cod->num_sprites * 20u +
             (size_t)cod->num_tiles * 16u +
             (size_t)cod->num_texture_pages * COD_TEXTURE_PAGE_SIZE;

    if (arrays_start + needed > COD_SIGNATURE_OFFSET(data_size)) {
        return 0;
    }

    /* Parse object types: num_objects * 4 bytes, each entry is uint16 type
     * followed by 2 unused bytes (per original game layout). */
    if (cod->num_objects > 0) {
        size_t obj_size = (size_t)cod->num_objects * sizeof(uint16_t);
        cod->object_types = (uint16_t *)malloc(obj_size);
        if (cod->object_types == NULL) {
            return 0;
        }
        {
            size_t i;
            const unsigned char *obj_base = data + arrays_start;
            for (i = 0; i < cod->num_objects; i++) {
                cod->object_types[i] = read_u16le(obj_base + i * 4);
            }
        }
    }

    /* Parse sprites: num_sprites * 20 bytes (0x14) */
    if (cod->num_sprites > 0) {
        size_t spr_offset = (size_t)cod->num_objects * 4u;
        size_t spr_size = (size_t)cod->num_sprites * sizeof(LL_CodSprite);
        cod->sprites = (LL_CodSprite *)malloc(spr_size);
        if (cod->sprites == NULL) {
            free(cod->object_types);
            cod->object_types = NULL;
            return 0;
        }

        {
            size_t i;
            const unsigned char *spr_base = data + arrays_start + spr_offset;
            for (i = 0; i < cod->num_sprites; i++) {
                const unsigned char *e = spr_base + i * 20;
                cod->sprites[i].type = read_u16le(e + 0);
                cod->sprites[i].x = read_i16le(e + 2);
                cod->sprites[i].y = read_i16le(e + 4);
                cod->sprites[i].w = read_u16le(e + 6);
                cod->sprites[i].h = read_u16le(e + 8);
                cod->sprites[i].field_a = read_u16le(e + 10);
                cod->sprites[i].texture_page = read_u16le(e + 12) & 0x1fu;
                cod->sprites[i].field_e = read_i16le(e + 14);
                cod->sprites[i].field_10 = read_i16le(e + 16);
                cod->sprites[i].flags = e[18];
            }
        }
    }

    /* Tile data: num_tiles * 16 bytes */
    if (cod->num_tiles > 0) {
        size_t tile_offset = (size_t)cod->num_objects * 4u +
                             (size_t)cod->num_sprites * 20u;
        cod->tile_data = (uint8_t *)malloc((size_t)cod->num_tiles * 16u);
        if (cod->tile_data == NULL) {
            free(cod->object_types);
            free(cod->sprites);
            cod->object_types = NULL;
            cod->sprites = NULL;
            return 0;
        }
        memcpy(cod->tile_data, data + arrays_start + tile_offset,
               (size_t)cod->num_tiles * 16u);
    }

    /* Texture page data: num_texture_pages * 0x8000 bytes (nibble-packed) */
    if (cod->num_texture_pages > 0) {
        size_t tp_offset = (size_t)cod->num_objects * 4u +
                           (size_t)cod->num_sprites * 20u +
                           (size_t)cod->num_tiles * 16u;
        size_t tp_size = (size_t)cod->num_texture_pages * COD_TEXTURE_PAGE_SIZE;
        cod->texture_page_data = (uint8_t *)malloc(tp_size);
        if (cod->texture_page_data == NULL) {
            free(cod->object_types);
            free(cod->sprites);
            free(cod->tile_data);
            cod->object_types = NULL;
            cod->sprites = NULL;
            cod->tile_data = NULL;
            return 0;
        }
        memcpy(cod->texture_page_data, data + arrays_start + tp_offset, tp_size);
    }

    return 1;
}

const unsigned char *ll_cod_get_texture_page(const LL_CodFile *cod,
                                             uint32_t page_index,
                                             size_t *out_size)
{
    if (cod == NULL || cod->texture_page_data == NULL) {
        return NULL;
    }
    if (page_index >= cod->num_texture_pages) {
        return NULL;
    }
    if (out_size != NULL) {
        *out_size = COD_TEXTURE_PAGE_SIZE;
    }
    return cod->texture_page_data + (size_t)page_index * COD_TEXTURE_PAGE_SIZE;
}

void ll_cod_close(LL_CodFile *cod)
{
    if (cod == NULL) {
        return;
    }
    free(cod->object_types);
    cod->object_types = NULL;
    free(cod->sprites);
    cod->sprites = NULL;
    free(cod->tile_data);
    cod->tile_data = NULL;
    free(cod->texture_page_data);
    cod->texture_page_data = NULL;
    memset(cod, 0, sizeof(*cod));
}

int ll_cod_is_valid(const LL_CodFile *cod)
{
    if (cod == NULL) {
        return 0;
    }
    return cod->raw_data != NULL;
}

/* Expand a 5-bit color channel (0-31) to 8-bit (0-255). */
static unsigned char cod_expand_5_to_8(unsigned int value)
{
    return (unsigned char)((value << 3) | (value >> 2));
}

/* Pack 5-bit RGB values into a 16-bit RGB555 color, matching FUN_004318a0
 * (the non-"Soft" branch): B[4:0] | G[4:0]<<5 | R[4:0]<<10 | alpha<<15. */
static uint16_t cod_pack_rgb555(unsigned int r, unsigned int g,
                                unsigned int b, unsigned int alpha)
{
    return (uint16_t)(b | (g << 5) | (r << 10) | (alpha << 15));
}

/* Build a CLUT from PCX palette data.
 *
 * The original game reads PCX palette entries as 3 bytes (RGB), shifts each
 * right by 3 to get 5-bit values, then packs them with FUN_004318a0 into a
 * 16-bit color.  This function stores expanded RGBA values directly.
 *
 * palette_rgb: 256 entries of 3 bytes each (R, G, B), or fewer if
 *              palette_entries < 256.
 * palette_entries: number of valid palette entries (0-256).
 * Returns 1 on success, 0 on invalid arguments. */
int ll_cod_clut_build_from_pcx_palette(LL_CodClut *clut,
                                       const unsigned char *palette_rgb,
                                       int palette_entries)
{
    int i;

    if (clut == NULL || palette_rgb == NULL) {
        return 0;
    }

    if (palette_entries < 0) {
        palette_entries = 0;
    }
    if (palette_entries > 256) {
        palette_entries = 256;
    }

    /* Initialize all entries to transparent black. */
    for (i = 0; i < 256; i++) {
        clut->rgba[i][0] = 0;
        clut->rgba[i][1] = 0;
        clut->rgba[i][2] = 0;
        clut->rgba[i][3] = 0;
    }

    /* Fill in palette entries. */
    for (i = 0; i < palette_entries; i++) {
        unsigned int r = palette_rgb[i * 3] >> 3;
        unsigned int g = palette_rgb[i * 3 + 1] >> 3;
        unsigned int b = palette_rgb[i * 3 + 2] >> 3;
        uint16_t packed = cod_pack_rgb555(r, g, b, 1);

        /* Expand 5-bit channels back to 8-bit for RGBA output. */
        clut->rgba[i][0] = cod_expand_5_to_8((packed >> 10) & 0x1f); /* R */
        clut->rgba[i][1] = cod_expand_5_to_8((packed >> 5) & 0x1f);  /* G */
        clut->rgba[i][2] = cod_expand_5_to_8(packed & 0x1f);         /* B */
        clut->rgba[i][3] = 255;                                      /* A */
    }

    clut->valid = 1;
    return 1;
}

/* Decode a COD texture page to RGBA pixels.
 *
 * COD texture pages are 128x128 pixels stored as 16-bit RGB555 values
 * (2 bytes per pixel, 0x8000 bytes total).  Each 16-bit value has the
 * layout B[4:0] | G[4:0]<<5 | R[4:0]<<10 (matching FUN_004318a0's
 * non-"Soft" branch).  Output is written to rgba_out which must hold at
 * least 128*128*4 bytes.  Returns 1 on success. */
int ll_cod_decode_texture_page(const unsigned char *page_data,
                               size_t page_size,
                               unsigned char *rgba_out)
{
    size_t i;
    size_t pixel_index;

    if (page_data == NULL || rgba_out == NULL ||
        page_size < COD_TEXTURE_PAGE_SIZE) {
        return 0;
    }

    pixel_index = 0;
    for (i = 0; i < COD_TEXTURE_PAGE_SIZE / 2; i++) {
        uint16_t packed = (uint16_t)(page_data[i * 2] |
                                     (page_data[i * 2 + 1] << 8));
        unsigned int b = packed & 0x1f;
        unsigned int g = (packed >> 5) & 0x1f;
        unsigned int r = (packed >> 10) & 0x1f;
        unsigned int alpha = (packed >> 15) & 1;

        rgba_out[pixel_index * 4] = cod_expand_5_to_8(r);
        rgba_out[pixel_index * 4 + 1] = cod_expand_5_to_8(g);
        rgba_out[pixel_index * 4 + 2] = cod_expand_5_to_8(b);
        rgba_out[pixel_index * 4 + 3] = alpha ? 255 : 0;
        pixel_index++;
    }

    return 1;
}
