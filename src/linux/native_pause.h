#ifndef LL_NATIVE_PAUSE_H
#define LL_NATIVE_PAUSE_H

#include "pcx.h"

enum { LL_PAUSE_KEY=1, LL_PAUSE_EXIT_KEY=2 };
enum { LL_PAUSE_EXITY, LL_PAUSE_EXITN, LL_PAUSE_CONTC, LL_PAUSE_CONTQ,
       LL_PAUSE_BACKY, LL_PAUSE_BACKN, LL_PAUSE_TITLE, LL_PAUSE_QUIT,
       LL_PAUSE_RETY, LL_PAUSE_RETN, LL_PAUSE_IMAGES };

/* Original413780 resources and406210/4775f0 state; no SDL/GL dependency. */
typedef struct {
    LL_PcxImage images[LL_PAUSE_IMAGES];
    uint8_t ready, registered, paused, exit_requested;
    uint8_t continue_menu, quit_menu, continue_selection, quit_selection;
    uint8_t pause_latch, exit_latch, allow_toggle, previous_keys;
    char error[192];
} LL_NativePause;

typedef struct { unsigned image; int16_t rectangle[4]; } LL_PauseQuad;

int ll_native_pause_open(LL_NativePause *pause, const unsigned char *archive, size_t size);
void ll_native_pause_close(LL_NativePause *pause);
void ll_native_pause_reset(LL_NativePause *pause);
int ll_native_pause_register(LL_NativePause *pause);
void ll_native_pause_update(LL_NativePause *pause, uint8_t enabled, uint8_t keys,
                            uint16_t pressed);
unsigned ll_native_pause_quads(const LL_NativePause *pause, LL_PauseQuad quads[2]);

#endif
