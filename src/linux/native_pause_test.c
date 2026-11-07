#include "native_pause.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void tick(LL_NativePause *pause, unsigned keys, unsigned pressed)
{
    ll_native_pause_update(pause,1,(uint8_t)keys,(uint16_t)pressed);
}

int main(int argc, char **argv)
{
    assert(argc==1 || argc==2);
    LL_NativePause pause={0};LL_PauseQuad quads[2];
    assert(!ll_native_pause_register(&pause) && strstr(pause.error,"KXP"));
    pause.ready=1;assert(ll_native_pause_register(&pause));
    tick(&pause,LL_PAUSE_KEY,0);assert(!pause.paused);
    tick(&pause,0,0);assert(pause.paused && !pause.continue_menu);
    assert(ll_native_pause_quads(&pause,quads)==2 && quads[0].image==LL_PAUSE_TITLE && quads[1].image==LL_PAUSE_QUIT);
    assert(quads[0].rectangle[0]==288 && quads[0].rectangle[1]==104 && quads[1].rectangle[3]==16);
    tick(&pause,0,0);assert(pause.paused);
    tick(&pause,0,8);assert(pause.paused);
    tick(&pause,LL_PAUSE_KEY,0);assert(pause.paused);
    tick(&pause,0,0);assert(!pause.paused && !ll_native_pause_quads(&pause,quads));
    tick(&pause,LL_PAUSE_KEY,0);tick(&pause,0,0);assert(pause.paused);
    tick(&pause,LL_PAUSE_EXIT_KEY,0);tick(&pause,0,0);
    assert(pause.paused && pause.continue_menu && !pause.exit_latch);
    tick(&pause,0,8);assert(!pause.paused);

    /* Escape enters on release, with Continue and No selected by default. */
    tick(&pause,LL_PAUSE_EXIT_KEY,0);assert(!pause.paused && pause.continue_menu);
    tick(&pause,0,0);assert(pause.paused);
    assert(ll_native_pause_quads(&pause,quads)==1 && quads[0].image==LL_PAUSE_CONTC);
    tick(&pause,0,0x20);
    assert(ll_native_pause_quads(&pause,quads)==1 && quads[0].image==LL_PAUSE_CONTQ);
    tick(&pause,0,8);assert(pause.quit_menu && !pause.continue_menu);
    assert(ll_native_pause_quads(&pause,quads)==1 && quads[0].image==LL_PAUSE_EXITN);
    tick(&pause,0,0);assert(!pause.exit_requested);
    tick(&pause,0,0x80);assert(pause.quit_selection);
    assert(ll_native_pause_quads(&pause,quads)==1 && quads[0].image==LL_PAUSE_EXITY);
    tick(&pause,0,0x20);tick(&pause,0,8);
    assert(pause.paused && pause.continue_menu && !pause.quit_menu && !pause.exit_requested);
    tick(&pause,0,0x20);tick(&pause,0,8);
    /* Escape while confirming returns to the Continue/Quit page. */
    tick(&pause,LL_PAUSE_EXIT_KEY,0);assert(pause.continue_menu);
    tick(&pause,0,8);assert(!pause.paused && !pause.exit_requested);

    ll_native_pause_update(&pause,0,LL_PAUSE_EXIT_KEY,0);
    tick(&pause,0,0);assert(!pause.paused && !pause.exit_latch);
    tick(&pause,LL_PAUSE_EXIT_KEY,0);tick(&pause,0,0);
    tick(&pause,0,0x20);tick(&pause,0,0x4000);
    tick(&pause,0,0x80);tick(&pause,0,0x4000);
    assert(pause.exit_requested && !pause.paused && !pause.registered);
    assert(!ll_native_pause_quads(&pause,quads));
    ll_native_pause_reset(&pause);assert(pause.ready && !pause.exit_requested);
    ll_native_pause_close(&pause);

    if (argc==2) {
        FILE *file=fopen(argv[1],"rb");assert(file);
        assert(!fseek(file,0,SEEK_END));long length=ftell(file);assert(length>0);
        assert(!fseek(file,0,SEEK_SET));unsigned char *data=malloc((size_t)length);assert(data);
        assert(fread(data,1,(size_t)length,file)==(size_t)length);fclose(file);
        assert(ll_native_pause_open(&pause,data,(size_t)length));
        for (unsigned i=0;i<LL_PAUSE_IMAGES;i++) {
            assert(pause.images[i].rgba_pixels && pause.images[i].width>0 && pause.images[i].height>0);
            assert(pause.images[i].width<=256 && pause.images[i].height<=256);
        }
        unsigned char *original=pause.images[0].rgba_pixels;
        assert(!ll_native_pause_open(&pause,data,10) && pause.ready && pause.images[0].rgba_pixels==original);
        assert(ll_native_pause_register(&pause));
        assert(!ll_native_pause_open(&pause,data,(size_t)length) && pause.registered);
        assert(!ll_native_pause_register(&pause) && pause.registered);
        ll_native_pause_close(&pause);free(data);
    }
    puts("Native pause key release, selection, confirmation, cancellation and localized PCX resources: OK");
    return 0;
}
