#include "renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdint.h>
#include <stdio.h>
#include <string.h>

static int expect_color(LL_Renderer *renderer,
                        const void *pixels,
                        size_t pixels_size,
                        size_t pitch,
                        LL_PixelFormat format,
                        const unsigned char palette[256][4],
                        const unsigned char expected[4])
{
    unsigned char sample[4];

    if (!ll_renderer_present(renderer, pixels, pixels_size, pitch, format, palette)) {
        return 0;
    }
    glReadBuffer(GL_BACK);
    glReadPixels(1, 1, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, sample);
    return glGetError() == GL_NO_ERROR && memcmp(sample, expected, 4) == 0;
}

int main(void)
{
    const unsigned char rgba_pixels[16] = {
        255, 0, 0, 255, 0, 255, 0, 255,
        0, 0, 255, 255, 255, 255, 255, 255
    };
    const uint16_t rgb555_pixels[4] = {0x7c00, 0x7c00, 0x7c00, 0x7c00};
    const uint16_t rgb565_pixels[4] = {0x07e0, 0x07e0, 0x07e0, 0x07e0};
    const unsigned char indexed_pixels[4] = {7, 7, 7, 7};
    const unsigned char expected_green[4] = {0, 255, 0, 255};
    const unsigned char expected_red[4] = {255, 0, 0, 255};
    const unsigned char expected_palette[4] = {23, 45, 67, 255};
    unsigned char palette[256][4] = {{0}};
    LL_Renderer renderer;
    SDL_Window *window;
    SDL_GLContext context;
    int result = 1;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL init failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 0);
    window = SDL_CreateWindow("renderer test", 0, 0, 2, 2,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN);
    if (window == NULL) {
        fprintf(stderr, "SDL window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    context = SDL_GL_CreateContext(window);
    if (context == NULL) {
        fprintf(stderr, "OpenGL context creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    glViewport(0, 0, 2, 2);
    if (!ll_renderer_init(&renderer, 2, 2)) {
        fprintf(stderr, "renderer initialization failed\n");
        goto cleanup_context;
    }

    if (ll_renderer_present(&renderer, rgba_pixels, sizeof(rgba_pixels) - 1, 8,
                            LL_PIXEL_RGBA8888, NULL)) {
        fprintf(stderr, "renderer accepted a truncated input buffer\n");
        goto cleanup_renderer;
    }
    if (ll_renderer_present(&renderer, rgba_pixels, sizeof(rgba_pixels), 7,
                            LL_PIXEL_RGBA8888, NULL)) {
        fprintf(stderr, "renderer accepted a short row pitch\n");
        goto cleanup_renderer;
    }
    if (!expect_color(&renderer, rgba_pixels, sizeof(rgba_pixels), 8,
                      LL_PIXEL_RGBA8888, NULL, expected_green)) {
        fprintf(stderr, "RGBA surface presentation failed\n");
        goto cleanup_renderer;
    }
    if (!expect_color(&renderer, rgb555_pixels, sizeof(rgb555_pixels), 4,
                      LL_PIXEL_RGB555, NULL, expected_red)) {
        fprintf(stderr, "RGB555 conversion failed\n");
        goto cleanup_renderer;
    }
    if (!expect_color(&renderer, rgb565_pixels, sizeof(rgb565_pixels), 4,
                      LL_PIXEL_RGB565, NULL, expected_green)) {
        fprintf(stderr, "RGB565 conversion failed\n");
        goto cleanup_renderer;
    }
    palette[7][0] = expected_palette[0];
    palette[7][1] = expected_palette[1];
    palette[7][2] = expected_palette[2];
    palette[7][3] = expected_palette[3];
    if (!expect_color(&renderer, indexed_pixels, sizeof(indexed_pixels), 2,
                      LL_PIXEL_INDEX8,
                      (const unsigned char (*)[4])palette, expected_palette)) {
        fprintf(stderr, "indexed palette expansion failed\n");
        goto cleanup_renderer;
    }

    result = 0;
    printf("renderer smoke test passed\n");

cleanup_renderer:
    ll_renderer_destroy(&renderer);
cleanup_context:
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return result;
}
