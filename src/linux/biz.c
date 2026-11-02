#include "biz.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

#define BIZ_HEADER_BYTES 28u
#define BIZ_OBJECT_BYTES 4u
#define BIZ_SPRITE_BYTES 20u
#define BIZ_TILE_BYTES 16u
#define BIZ_PAGE_BYTES 0x8000u
#define BIZ_MAX_ENTRIES 1000000u

static uint16_t u16(const unsigned char *p)
{
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

static uint32_t u32(const unsigned char *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static int span(size_t total, uint64_t offset, uint64_t length)
{
    return offset <= total && length <= (uint64_t)total - offset;
}

static int biz_fail(LL_BizFile *biz, const char *message)
{
    snprintf(biz->error, sizeof(biz->error), "%s", message);
    biz->valid = 0;
    biz->raw_data = NULL;
    biz->raw_size = 0;
    return 0;
}

static int sound_fail(LL_BizFile *biz, const char *message)
{
    if (biz) snprintf(biz->error,sizeof(biz->error),"BIZ sound: %s",message);
    return 0;
}

int ll_biz_get_sound_count(LL_BizFile *biz, uint32_t *out_count)
{
    if (!biz || !biz->valid || !out_count || biz->raw_size<8)
        return sound_fail(biz,"invalid handle or missing bank pointer");
    *out_count=0;
    uint32_t offset=u32(biz->raw_data+4);
    if (!offset) return 1;
    if (!span(biz->raw_size,offset,4)) return sound_fail(biz,"bank count exceeds file bounds");
    uint32_t count=u32(biz->raw_data+offset);
    if (count>60 || !span(biz->raw_size,offset,4u+(uint64_t)count*4u))
        return sound_fail(biz,"bank directory exceeds 60 slots or file bounds");
    *out_count=count;
    return 1;
}

int ll_biz_get_sound(LL_BizFile *biz, uint32_t index, LL_BizSound *out)
{
    uint32_t count;
    if (!out) return sound_fail(biz,"null output descriptor");
    memset(out,0,sizeof(*out));
    if (!ll_biz_get_sound_count(biz,&count)) return 0;
    if (index>=count) return sound_fail(biz,"sample index is outside the bank directory");
    uint32_t bank=u32(biz->raw_data+4);
    uint64_t begin=(uint64_t)bank+u32(biz->raw_data+bank+4u+index*4u);
    uint64_t end=biz->raw_size;
    if (begin<(uint64_t)bank+4u+count*4u || !span(biz->raw_size,begin,64))
        return sound_fail(biz,"sample header overlaps the directory or exceeds file bounds");
    for (uint32_t i=0;i<count;i++) {
        uint64_t other=(uint64_t)bank+u32(biz->raw_data+bank+4u+i*4u);
        if (i!=index && other==begin) return sound_fail(biz,"duplicate sample offsets");
        if (other>begin && other<end) end=other;
    }
    if (end-begin<64) return sound_fail(biz,"sample header overlaps the next sample");
    const unsigned char *header=biz->raw_data+(size_t)begin;
    if (memcmp(header,"VAGp",4)) return sound_fail(biz,"sample is missing VAGp signature");
    uint32_t rate=(uint32_t)header[16]<<24 | (uint32_t)header[17]<<16 |
                  (uint32_t)header[18]<<8 | header[19];
    if (!rate || rate>192000) return sound_fail(biz,"sample rate is outside 1..192000 Hz");
    size_t frames=0;
    for (uint64_t cursor=begin+64;span((size_t)end,cursor,16);cursor+=16) {
        const unsigned char *frame=biz->raw_data+(size_t)cursor;
        if (frame[1]==7) {
            memcpy(out->name,header+32,32);
            out->sample_rate=rate;out->declared_size=u32(header+12);
            out->frames=header+64;out->frame_count=frames;out->sample_count=frames*28u;
            return 1;
        }
        if ((frame[0]>>4)>4 || (frame[0]&15)>12)
            return sound_fail(biz,"ADPCM predictor or shift is unsupported");
        frames++;
    }
    return sound_fail(biz,"sample has no complete flag-7 terminator before its boundary");
}

int ll_biz_decode_sound(LL_BizFile *biz, uint32_t index, int16_t *pcm,
                        size_t sample_capacity, LL_BizSound *out)
{
    LL_BizSound sound;
    if (!ll_biz_get_sound(biz,index,&sound)) return 0;
    if (!pcm || sample_capacity<sound.sample_count)
        return sound_fail(biz,"PCM output buffer is null or too small");
    /* Doubles from Game.run 004c6da8, as consumed by FUN_00492610.
     * History retains the unrounded value even when PCM wraps to 16 bits. */
    static const double coefficients[5][2]={
        {0,0},{0.9375,0},{1.796875,-0.8125},
        {1.53125,-0.859375},{1.90625,-0.9375}
    };
    double previous=0, older=0;
    size_t output=0;
    for (size_t block=0;block<sound.frame_count;block++) {
        const unsigned char *frame=sound.frames+block*16u;
        unsigned predictor=frame[0]>>4, shift=frame[0]&15u;
        for (unsigned sample=0;sample<28;sample++) {
            unsigned packed=frame[2u+sample/2u];
            int nibble=(int)((packed>>((sample&1u)*4u))&15u);
            if (nibble>=8) nibble-=16;
            double value=older*coefficients[predictor][1]+
                         previous*coefficients[predictor][0]+
                         nibble*(int)(4096u>>shift);
            if (!isfinite(value) || value<INT32_MIN || value>INT32_MAX)
                return sound_fail(biz,"ADPCM predictor exceeded the supported numeric range");
            older=previous;previous=value;
            uint16_t bits=(uint16_t)(int64_t)value;
            pcm[output++]=(int16_t)(bits>=32768u ? (int32_t)bits-65536 : bits);
        }
    }
    if (out) *out=sound;
    return 1;
}

int ll_biz_open(LL_BizFile *biz, const unsigned char *data, size_t size)
{
    uint64_t cursor, bytes;
    if (biz == NULL) return 0;
    memset(biz, 0, sizeof(*biz));
    if (data == NULL || size < 4) return biz_fail(biz, "BIZ file is truncated before header offset");
    biz->raw_data = data;
    biz->raw_size = size;
    biz->header_offset = u32(data);
    if (!span(size, biz->header_offset, BIZ_HEADER_BYTES))
        return biz_fail(biz, "BIZ seven-DWORD header is out of bounds");
    for (uint32_t i = 0; i < 7; i++) {
        biz->counts[i] = u32(data + biz->header_offset + i * 4u);
        if (biz->counts[i] > BIZ_MAX_ENTRIES)
            return biz_fail(biz, "BIZ table count exceeds supported bounds");
    }
    if (biz->counts[3] == 0 || biz->counts[3] > 16)
        return biz_fail(biz, "BIZ texture page count is outside the supported range");
    cursor = (uint64_t)biz->header_offset + BIZ_HEADER_BYTES;
    biz->object_offset = (uint32_t)cursor;
    bytes = (uint64_t)biz->counts[0] * BIZ_OBJECT_BYTES;
    if (!span(size, cursor, bytes)) return biz_fail(biz, "BIZ object table exceeds file bounds");
    cursor += bytes;
    biz->sprite_offset = (uint32_t)cursor;
    bytes = (uint64_t)biz->counts[1] * BIZ_SPRITE_BYTES;
    if (!span(size, cursor, bytes)) return biz_fail(biz, "BIZ sprite table exceeds file bounds");
    cursor += bytes;
    biz->tile_offset = (uint32_t)cursor;
    bytes = (uint64_t)biz->counts[2] * BIZ_TILE_BYTES;
    if (!span(size, cursor, bytes)) return biz_fail(biz, "BIZ tile table exceeds file bounds");
    cursor += bytes;
    biz->page_offset = (uint32_t)cursor;
    biz->page_size = BIZ_PAGE_BYTES;
    bytes = (uint64_t)biz->counts[3] * BIZ_PAGE_BYTES;
    if (!span(size, cursor, bytes)) return biz_fail(biz, "BIZ texture pages exceed file bounds");
    biz->valid = 1;
    return 1;
}

void ll_biz_close(LL_BizFile *biz)
{
    if (biz != NULL) memset(biz, 0, sizeof(*biz));
}

const char *ll_biz_error(const LL_BizFile *biz)
{
    return biz != NULL ? biz->error : "BIZ handle is null";
}

int ll_biz_get_object(const LL_BizFile *biz, uint32_t index, LL_BizObject *out)
{
    const unsigned char *p;
    if (biz == NULL || !biz->valid || out == NULL || index >= biz->counts[0]) return 0;
    p = biz->raw_data + biz->object_offset + (size_t)index * BIZ_OBJECT_BYTES;
    out->sprite_index = u16(p);
    out->tile_index = u16(p + 2);
    return out->sprite_index < biz->counts[1] && out->tile_index < biz->counts[2];
}

int ll_biz_get_sprite(const LL_BizFile *biz, uint32_t index, LL_BizSprite *out)
{
    const unsigned char *p;
    if (biz == NULL || !biz->valid || out == NULL || index >= biz->counts[1]) return 0;
    p = biz->raw_data + biz->sprite_offset + (size_t)index * BIZ_SPRITE_BYTES;
    out->field_00 = u16(p); out->field_02 = u16(p + 2);
    out->width_units = (int16_t)u16(p + 4); out->height = (int16_t)u16(p + 6);
    out->field_08 = u16(p + 8); out->field_0a = u16(p + 10);
    out->field_0c = u16(p + 12); out->field_0e = u16(p + 14);
    out->texture_x = p[16]; out->texture_y = p[17];
    out->palette_slot = p[18]; out->field_13 = p[19];
    return 1;
}

int ll_biz_get_tile(const LL_BizFile *biz, uint32_t index, LL_BizTile *out)
{
    const unsigned char *p;
    if (biz == NULL || !biz->valid || out == NULL || index >= biz->counts[2]) return 0;
    p = biz->raw_data + biz->tile_offset + (size_t)index * BIZ_TILE_BYTES;
    out->palette_x = (int16_t)u16(p); out->palette_y = (int16_t)u16(p + 2);
    for (uint32_t i = 0; i < 4; i++) out->fields[i] = u16(p + 4 + i * 2u);
    out->texture_page_raw = u16(p + 12);
    out->field_0e = u16(p + 14);
    out->texture_page_index = out->texture_page_raw & 0x1fu;
    return out->texture_page_index < biz->counts[3];
}

const unsigned char *ll_biz_get_page(const LL_BizFile *biz, uint32_t index,
                                     size_t *out_size)
{
    if (biz == NULL || !biz->valid || index >= biz->counts[3]) return NULL;
    if (out_size != NULL) *out_size = biz->page_size;
    return biz->raw_data + biz->page_offset + (size_t)index * biz->page_size;
}

static unsigned char nibble_pixel(const unsigned char *page, uint32_t pixel)
{
    unsigned char packed = page[pixel >> 1];
    return (pixel & 1u) ? (unsigned char)(packed >> 4) : (unsigned char)(packed & 15u);
}

int ll_biz_decode_sprite(const LL_BizFile *biz, uint32_t sprite_index,
                         uint32_t tile_index, unsigned char *rgba,
                         size_t rgba_capacity, uint32_t *out_width,
                         uint32_t *out_height)
{
    LL_BizSprite sprite;
    LL_BizTile tile;
    const unsigned char *page;
    const unsigned char *texture_page;
    uint32_t width, height;
    unsigned char palette[16][4];
    size_t needed;
    if (biz == NULL || rgba == NULL || !ll_biz_get_sprite(biz, sprite_index, &sprite) ||
        !ll_biz_get_tile(biz, tile_index, &tile)) return 0;
    if (sprite.width_units <= 0 || sprite.height <= 0 ||
        tile.palette_x < 0 || tile.palette_y < 0 ||
        (uint32_t)tile.palette_x * 4u + 64u > 256u || tile.palette_y >= 256)
        return 0;
    width = (uint32_t)sprite.width_units * 4u;
    height = (uint32_t)sprite.height;
    if (width > 256u - sprite.texture_x) width = 256u - sprite.texture_x;
    if (height > 256u - sprite.texture_y) height = 256u - sprite.texture_y;
    needed = (size_t)width * height * 4u;
    if (width == 0 || height == 0 || needed > rgba_capacity) return 0;
    page = ll_biz_get_page(biz, tile.texture_page_index, NULL);
    /* FUN_0044b320 relocates sprite +0x0e through the page registry.
     * Tile +0x0c identifies the palette page, not the sprite pixel page. */
    texture_page = ll_biz_get_page(biz, sprite.field_0e, NULL);
    if (page == NULL || texture_page == NULL) return 0;
    for (uint32_t i = 0; i < 16; i++) {
        uint32_t p = (uint32_t)tile.palette_y * 256u +
                     (uint32_t)tile.palette_x * 4u + i * 4u;
        uint16_t rgb555 = (uint16_t)nibble_pixel(page, p) |
                          (uint16_t)(nibble_pixel(page, p + 1u) << 4) |
                          (uint16_t)(nibble_pixel(page, p + 2u) << 8) |
                          (uint16_t)(nibble_pixel(page, p + 3u) << 12);
        /* FUN_0044aaa0 moves the source low five bits into the output
         * red channel. BIZ CLUT words use R in bits 0..4, B in 10..14. */
        unsigned r = rgb555 & 31u, g = (rgb555 >> 5) & 31u, b = (rgb555 >> 10) & 31u;
        palette[i][0] = (unsigned char)((r * 255u + 15u) / 31u);
        palette[i][1] = (unsigned char)((g * 255u + 15u) / 31u);
        palette[i][2] = (unsigned char)((b * 255u + 15u) / 31u);
        palette[i][3] = (rgb555 & 0x7fffu) == 0 ? 0 : 255;
    }
    for (uint32_t y = 0; y < height; y++) for (uint32_t x = 0; x < width; x++) {
        uint32_t source_pixel = (uint32_t)(sprite.texture_y + y) * 256u + sprite.texture_x + x;
        unsigned char index = nibble_pixel(texture_page, source_pixel);
        memcpy(rgba + ((size_t)y * width + x) * 4u, palette[index], 4u);
    }
    if (out_width != NULL) *out_width = width;
    if (out_height != NULL) *out_height = height;
    return 1;
}
