#ifndef LL_BIZ_H
#define LL_BIZ_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint16_t sprite_index;
    uint16_t tile_index;
} LL_BizObject;

typedef struct {
    uint16_t field_00;
    uint16_t field_02;
    int16_t width_units; /* engine/extractor scales by four */
    int16_t height;
    uint16_t field_08;
    uint16_t field_0a;
    uint16_t field_0c;
    uint16_t field_0e;
    uint8_t texture_x;
    uint8_t texture_y;
    uint8_t palette_slot;
    uint8_t field_13;
} LL_BizSprite;

typedef struct {
    int16_t palette_x;
    int16_t palette_y;
    uint16_t fields[4];
    uint16_t texture_page_raw;
    uint16_t field_0e;
    uint16_t texture_page_index; /* engine masks raw value to five bits */
} LL_BizTile;

typedef struct {
    char name[33];
    uint32_t sample_rate;
    uint32_t declared_size;
    const unsigned char *frames; /* borrowed, excludes the flag-7 terminator */
    size_t frame_count;
    size_t sample_count; /* mono signed 16-bit samples after decoding */
} LL_BizSound;

typedef struct {
    const unsigned char *raw_data;
    size_t raw_size;
    uint32_t header_offset;
    uint32_t counts[7];
    uint32_t object_offset;
    uint32_t sprite_offset;
    uint32_t tile_offset;
    uint32_t page_offset;
    uint32_t page_size;
    int valid;
    char error[192];
} LL_BizFile;

/* Parse and bounds-check the BIZ tables. Input remains owned by the caller. */
int ll_biz_open(LL_BizFile *biz, const unsigned char *data, size_t size);
void ll_biz_close(LL_BizFile *biz);
const char *ll_biz_error(const LL_BizFile *biz);
int ll_biz_get_object(const LL_BizFile *biz, uint32_t index, LL_BizObject *out);
int ll_biz_get_sprite(const LL_BizFile *biz, uint32_t index, LL_BizSprite *out);
int ll_biz_get_tile(const LL_BizFile *biz, uint32_t index, LL_BizTile *out);
const unsigned char *ll_biz_get_page(const LL_BizFile *biz, uint32_t index,
                                     size_t *out_size);
/* Decode a sprite rectangle using the palette selected by its BIZ tile.
 * Pixels are tightly packed RGBA8888; dimensions are returned on success. */
int ll_biz_decode_sprite(const LL_BizFile *biz, uint32_t sprite_index,
                         uint32_t tile_index, unsigned char *rgba,
                         size_t rgba_capacity, uint32_t *out_width,
                         uint32_t *out_height);

/* Sound bank at file DWORD +4. Failure reports details through ll_biz_error
 * without invalidating the already parsed graphics. */
int ll_biz_get_sound_count(LL_BizFile *biz, uint32_t *out_count);
int ll_biz_get_sound(LL_BizFile *biz, uint32_t index, LL_BizSound *out);
/* Decode into caller-owned mono PCM; capacity is measured in samples.
 * Uses native floating predictor history and truncation/wrapping, not clipping.
 * On failure output may contain a partial decode; do not play it. */
int ll_biz_decode_sound(LL_BizFile *biz, uint32_t index, int16_t *pcm,
                        size_t sample_capacity, LL_BizSound *out);

#endif
