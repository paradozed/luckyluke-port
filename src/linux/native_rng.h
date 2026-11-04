#ifndef LL_NATIVE_RNG_H
#define LL_NATIVE_RNG_H

#include <stdint.h>

/* FUN_0046d7b0/0046d700 global subtractive RNG used by menu and level SOOL. */
void ll_native_rng_reset(void);
uint16_t ll_native_rng_word(void);
int ll_native_rng_bounded(int16_t bound, uint16_t *out_value);

#endif
