#include "native_pause.h"
#include "kxp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *const image_names[LL_PAUSE_IMAGES]={
    "exity.pcx","exitn.pcx","contc.pcx","contq.pcx","backy.pcx",
    "backn.pcx","pause.pcx","quit.pcx","rety.pcx","retn.pcx"
};

static int pause_fail(LL_NativePause *pause, const char *message)
{
    snprintf(pause->error,sizeof(pause->error),"%s",message);return 0;
}

void ll_native_pause_close(LL_NativePause *pause)
{
    if (!pause) return;
    for (unsigned i=0;i<LL_PAUSE_IMAGES;i++) ll_pcx_destroy(&pause->images[i]);
    memset(pause,0,sizeof(*pause));
}

void ll_native_pause_reset(LL_NativePause *pause)
{
    pause->registered=pause->paused=pause->exit_requested=0;
    pause->continue_menu=pause->quit_menu=0;
    pause->continue_selection=pause->quit_selection=0;
    pause->pause_latch=pause->exit_latch=pause->previous_keys=0;pause->allow_toggle=1;
}

int ll_native_pause_open(LL_NativePause *pause, const unsigned char *data, size_t size)
{
    LL_KxpArchive archive;
    if (!ll_kxp_open(&archive,data,size,"lucky")) return pause_fail(pause,"invalid localized pause KXP archive");
    if (pause->registered) return pause_fail(pause,"cannot replace registered pause resources");
    LL_NativePause prepared={0};
    for (unsigned i=0;i<LL_PAUSE_IMAGES;i++) {
        const unsigned char *payload;size_t length;
        if (!ll_kxp_find(&archive,image_names[i],&payload,&length) || length>16u*1024u*1024u) {
            snprintf(pause->error,sizeof(pause->error),"missing or oversized pause resource %s",image_names[i]);goto failed;
        }
        unsigned char *decoded=malloc(length);
        if (!decoded) { pause_fail(pause,"cannot allocate pause PCX data");goto failed; }
        memcpy(decoded,payload,length);
        if (archive.encrypted) ll_kxp_decrypt(decoded,length,"lucky");
        int ok=ll_pcx_decode(decoded,length,&prepared.images[i]);free(decoded);
        if (!ok || prepared.images[i].width>256 || prepared.images[i].height>256) {
            snprintf(pause->error,sizeof(pause->error),"invalid or oversized pause PCX %s",image_names[i]);goto failed;
        }
    }
    prepared.ready=1;ll_native_pause_reset(&prepared);
    ll_native_pause_close(pause);*pause=prepared;return 1;
failed:
    ll_native_pause_close(&prepared);return 0;
}

int ll_native_pause_register(LL_NativePause *pause)
{
    if (!pause->ready) return pause_fail(pause,"pause interface requires its localized MENU_*.KXP resources");
    if (pause->registered) return pause_fail(pause,"repeated native pause interface registration is not ported");
    ll_native_pause_reset(pause);pause->registered=1;return 1;
}

/* Original4775f0 returns AX=0 on continue or confirmed level exit. */
static int pause_menu(LL_NativePause *pause, uint8_t keys, uint16_t pressed)
{
    if (keys&LL_PAUSE_EXIT_KEY) pause->continue_menu=1;
    if (!pause->continue_menu && !pause->quit_menu) { pause->allow_toggle=1;return 1; }
    if (pause->continue_menu) {
        pause->allow_toggle=0;
        if (pressed&0x20) pause->continue_selection=1;
        if (pressed&0x80) pause->continue_selection=0;
        if (pressed&(0x4000|8)) {
            if (pause->continue_selection) {
                pause->quit_menu=1;pause->continue_menu=0;pause->continue_selection=0;return 1;
            }
            pause->continue_menu=pause->quit_menu=0;pause->continue_selection=0;
            pause->allow_toggle=1;return 0;
        }
    }
    if (pause->quit_menu) {
        if (pressed&0x20) pause->quit_selection=0;
        if (pressed&0x80) pause->quit_selection=1;
        if (pressed&(0x4000|8)) {
            if (pause->quit_selection) {
                pause->exit_requested=1;pause->registered=0;
                pause->continue_menu=pause->quit_menu=pause->quit_selection=0;
                pause->allow_toggle=1;return 0;
            }
            pause->quit_menu=0;pause->continue_menu=1;pause->quit_selection=0;
        }
    }
    return 1;
}

void ll_native_pause_update(LL_NativePause *pause, uint8_t enabled, uint8_t keys,
                            uint16_t pressed)
{
    uint8_t released=(uint8_t)(pause->previous_keys&(uint8_t)~keys);pause->previous_keys=keys;
    if (!pause->registered || !enabled || pause->exit_requested) return;
    int toggle=pause->paused && !pause_menu(pause,keys,pressed);
    if (keys&(LL_PAUSE_KEY|LL_PAUSE_EXIT_KEY)) {
        if (keys&LL_PAUSE_KEY) pause->pause_latch=1;
        if ((keys&LL_PAUSE_EXIT_KEY) && !pause->continue_menu) {
            pause->continue_menu=1;pause->exit_latch=1;
        }
    } else {
        if (pause->pause_latch) { pause->pause_latch=0;toggle=1; }
        if (pause->exit_latch) { pause->exit_latch=0;toggle=1; }
    }
    /* 004f58d9 is keyboard release[DIK_P=0x19], not an any-key flag. */
    if (pause->paused && (released&LL_PAUSE_KEY) && !pause->continue_menu && !pause->quit_menu) toggle=1;
    if (toggle && pause->allow_toggle) {
        pause->paused^=1;
        if (!pause->paused) pause->continue_menu=0;
    }
}

unsigned ll_native_pause_quads(const LL_NativePause *pause, LL_PauseQuad quads[2])
{
    if (!pause->ready || !pause->registered || !pause->paused) return 0;
    if (pause->continue_menu || pause->quit_menu) {
        quads[0]=(LL_PauseQuad){pause->continue_menu ?
            (pause->continue_selection?LL_PAUSE_CONTQ:LL_PAUSE_CONTC):
            (pause->quit_selection?LL_PAUSE_EXITY:LL_PAUSE_EXITN),{256,224,128,32}};
        return 1;
    }
    quads[0]=(LL_PauseQuad){LL_PAUSE_TITLE,{288,104,64,32}};
    quads[1]=(LL_PauseQuad){LL_PAUSE_QUIT,{256,352,128,16}};
    return 2;
}
