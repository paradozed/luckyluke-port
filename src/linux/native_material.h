#ifndef LL_NATIVE_MATERIAL_H
#define LL_NATIVE_MATERIAL_H

#include <stdint.h>

typedef struct {
    int32_t multiplier; /* Descriptor+54; command30 sign-extends its SOOL word. */
    uint8_t applied;
} LL_NativeMaterial;

/* 48efc0/48e5e0: derive from the packed source, never from the last tint.
 * Preserve native low-byte wrap and the primitive's command byte. */
static inline uint32_t ll_native_material_flat(uint32_t source, int32_t multiplier)
{
    uint32_t result=source&0xff000000u;
    for (unsigned shift=0;shift<24;shift+=8)
        result|=((((source>>shift)&255u)*(uint32_t)multiplier>>8)&255u)<<shift;
    return result;
}

/* 48dcc0/48c510: logical shift, deliberately no mask before combining. */
static inline uint32_t ll_native_material_textured(uint32_t source, int32_t multiplier)
{
    uint32_t half=(uint32_t)multiplier>>1;
    return (source&0xff000000u)|half|(half<<8)|(half<<16);
}

#endif
