#include "native_rng.h"

static uint32_t words[55];
static unsigned first, second;
static int initialized;

void ll_native_rng_reset(void)
{
    /* 46d7b0 leaves slot34 untouched: the 0..53 permutation even overwrites
     * seeded slot54. Reseeding intentionally retains that native history. */
    uint32_t seed=0x09a4ec86u,next=1;
    words[54]=seed;
    for (unsigned i=0;i<54;i++) {
        unsigned index=(i*21u)%55u;
        words[index]=next;
        next=seed-next;
        seed=words[index];
    }
    for (unsigned pass=0;pass<4;pass++)
        for (unsigned i=0;i<55;i++) words[i]-=words[(i+31u)%55u];
    first=0;second=31;initialized=1;
}

uint16_t ll_native_rng_word(void)
{
    if (!initialized) ll_native_rng_reset();
    first=(first+1u)%55u;second=(second+1u)%55u;
    words[first]-=words[second];
    return (uint16_t)(words[first]%0x7fffu);
}

int ll_native_rng_bounded(int16_t bound, uint16_t *out_value)
{
    if (!out_value) return 0;
    uint16_t value=ll_native_rng_word();
    if (!bound) return 0;
    int32_t remainder=(int32_t)value%(int32_t)bound;
    *out_value=(uint16_t)(int16_t)remainder;
    return 1;
}
