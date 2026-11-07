#ifndef LL_NATIVE_COLLISION_H
#define LL_NATIVE_COLLISION_H

#include <stdint.h>

typedef struct {
    uint16_t target_instance, flags;
    uint8_t active, callback_mode; /* 0..3 contact,4..7 corresponding riding callback. */
} LL_NativeCollisionLink;

typedef struct {
    int32_t position[3], previous[3], bounds[6]; /* Retained local AABB. */
    uint32_t flags; /* Model payload+0x10. */
} LL_NativeCollisionBody;

/* Native457eb0/4584d0/458890/458c40 and their riding callbacks.
 * Returns setter mask (1 owner,2 target), or-1 for an unsupported callback.
 * Flags and callback state can change without a position setter. */
int ll_native_collision_step(LL_NativeCollisionLink *link,
                             LL_NativeCollisionBody *owner, LL_NativeCollisionBody *target);

#endif
