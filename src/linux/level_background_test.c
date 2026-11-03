#include "level.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO)) { fprintf(stderr,"SDL: %s\n",SDL_GetError());return 1; }
    SDL_Window *window=SDL_CreateWindow("level background test",0,0,64,48,
        SDL_WINDOW_OPENGL|SDL_WINDOW_HIDDEN);
    if (!window) { fprintf(stderr,"SDL window: %s\n",SDL_GetError());SDL_Quit();return 1; }
    SDL_GLContext context=SDL_GL_CreateContext(window);
    if (!context) { fprintf(stderr,"GL context: %s\n",SDL_GetError());SDL_DestroyWindow(window);SDL_Quit();return 1; }
    LL_Level level={0};int result=1;
    /* A 2x1 indexed PCX, contrasting with the initial 64x48 presenter. */
    unsigned char pcx[128+2+769]={0};
    pcx[0]=10;pcx[1]=5;pcx[2]=0;pcx[3]=8;pcx[8]=1;
    pcx[65]=1;pcx[66]=2;pcx[128]=1;pcx[129]=1;
    pcx[130]=12;pcx[131+3]=255;
    if (!ll_level_init(&level,64,48)) goto done;
    if (!ll_level_load_background_from_pcx(&level,pcx,sizeof(pcx)) ||
        level.renderer.width!=2 || level.renderer.height!=1) goto done;
    ll_level_set_state(&level,2);glViewport(0,0,64,48);
    if (!ll_level_render(&level)) goto done;
    unsigned char pixel[4];glReadPixels(32,24,1,1,GL_RGBA,GL_UNSIGNED_BYTE,pixel);
    if (glGetError()!=GL_NO_ERROR || pixel[0]!=255 || pixel[1] || pixel[2]) goto done;
    result=0;puts("Level background source dimensions and presentation: OK");
done:
    if (result) fprintf(stderr,"level background resize/presentation failed\n");
    ll_level_destroy(&level);SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);SDL_Quit();return result;
}
