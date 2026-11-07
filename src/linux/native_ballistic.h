#ifndef LL_NATIVE_BALLISTIC_H
#define LL_NATIVE_BALLISTIC_H

#include <stdint.h>

typedef struct {
    int32_t velocity[3];
    uint16_t bounce_count;
    uint8_t positive_bounce;
} LL_NativeBallistic;

/* FUN_00409650/004095d0: one script query using the frame's elapsed60-Hz
 * ticks. The floor decision uses the incoming Y, after publishing movement.
 * Returns the native AX:0 moving/bouncing,1 stopped; -1 for invalid pointers. */
int ll_native_ballistic_step(LL_NativeBallistic *state, int32_t position[3],
                               int32_t floor_y, int16_t drag, int16_t gravity,
                               int32_t elapsed_ticks);

#endif
