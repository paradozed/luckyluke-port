#ifndef LL_NATIVE_BACKGROUND_H
#define LL_NATIVE_BACKGROUND_H

#include "bib.h"
#include "biz.h"

#define LL_BACKGROUND_LAYERS 16
#define LL_BACKGROUND_PRIMITIVES 32

typedef struct {
    int16_t rectangle[4], source[4];
    uint8_t color[4][3], type; /* Native types0 texture,1 flat,2 Gouraud. */
    uint16_t object;
} LL_BackgroundPrimitive;

typedef struct {
    int16_t rectangle[4], order, phase[2], origin[2], factor[2];
    int8_t speed[2];
    uint8_t enabled, flags, tint[3];
    unsigned primitive_count;
    LL_BackgroundPrimitive primitives[LL_BACKGROUND_PRIMITIVES];
} LL_BackgroundLayer;

typedef struct {
    uint16_t wrapper_word;
    int16_t reference_y;
    int32_t camera[2];
    unsigned layer_count;
    LL_BackgroundLayer layers[LL_BACKGROUND_LAYERS];
    char error[192];
} LL_NativeBackground;

typedef struct {
    int16_t position[4][2], uv[4][2]; /* Pixel coordinates on the640x480 surface. */
    uint8_t color[4][3], textured;
    uint16_t object;
} LL_BackgroundQuad;

void ll_native_background_init(LL_NativeBackground *background, uint16_t word, int16_t height);
int ll_native_background_layer(LL_NativeBackground *background, const uint16_t args[5], uint16_t *index);
int ll_native_background_command(LL_NativeBackground *background, uint16_t command,
    const uint16_t *args, size_t argc, const LL_BibFile *bib, const LL_BizFile *biz);
/* Native490f0/48e30, once per registered callback; never advanced by rendering. */
void ll_native_background_update(LL_NativeBackground *background, const int32_t reference[3],
    int16_t pitch, int16_t yaw, uint16_t projection);
/* Native single wrap, signed pixel quantization and color modulation. */
int ll_native_background_quad(const LL_NativeBackground *background, unsigned layer,
    unsigned primitive, LL_BackgroundQuad *quad);

#endif
