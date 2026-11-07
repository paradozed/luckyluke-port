#include "native_ballistic.h"

#include <string.h>

static int32_t signed32(uint32_t bits)
{
    int32_t result;memcpy(&result,&bits,sizeof(result));return result;
}

static int32_t add(int32_t a, int32_t b) { return signed32((uint32_t)a+(uint32_t)b); }
static int32_t sub(int32_t a, int32_t b) { return signed32((uint32_t)a-(uint32_t)b); }
static int32_t mul(int32_t a, int32_t b) { return signed32((uint32_t)a*(uint32_t)b); }
static int32_t absolute(int32_t value) { return value<0?sub(0,value):value; }

int ll_native_ballistic_step(LL_NativeBallistic *state, int32_t position[3],
                               int32_t floor_y, int16_t drag, int16_t gravity,
                               int32_t elapsed_ticks)
{
    if (!state || !position) return -1;
    int32_t before[3];memcpy(before,state->velocity,sizeof(before));
    int32_t incoming_y=position[1];
    int32_t quarter_square=mul(elapsed_ticks,elapsed_ticks)/4;
    int32_t half_ticks=signed32((uint32_t)elapsed_ticks<<8)/2;
    int32_t displacement[3];
    for (unsigned axis=0;axis<3;axis++) {
        int16_t acceleration=axis==1?gravity:drag;
        displacement[axis]=axis!=1 && absolute(before[axis])<=drag?0:
            add(mul(quarter_square,acceleration)/2,mul(half_ticks,before[axis])/256);
    }
    for (unsigned axis=0;axis<3;axis++) position[axis]=add(position[axis],displacement[axis]);
    if (position[1]>floor_y) position[1]=add(floor_y,1);
    int32_t friction=mul(half_ticks,drag)/256;
    for (unsigned axis=0;axis<3;axis+=2) {
        if (absolute(before[axis])<drag) state->velocity[axis]=0;
        else if (before[axis]) state->velocity[axis]=before[axis]<0?
            add(before[axis],friction):sub(before[axis],friction);
        /* Native equality with zero leaves the temporary displacement (0). */
        else state->velocity[axis]=displacement[axis];
    }
    if (incoming_y<floor_y) {
        state->velocity[1]=add(before[1],mul(half_ticks,gravity)/256);
        if (state->velocity[1]>300) state->velocity[1]=300;
        return 0;
    }
    int16_t remaining=(int16_t)state->bounce_count;
    if (remaining<=0) { memset(state->velocity,0,sizeof(state->velocity));return 1; }
    for (unsigned axis=0;axis<3;axis+=2) if (state->velocity[axis])
        state->velocity[axis]=sub(state->positive_bounce?20:-20,remaining);
    state->velocity[1]=remaining-10;
    state->bounce_count=(uint16_t)(state->bounce_count-1u);return 0;
}
