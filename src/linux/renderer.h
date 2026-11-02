#ifndef LL_RENDERER_H
#define LL_RENDERER_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
    LL_PIXEL_INDEX8,
    LL_PIXEL_RGB555,
    LL_PIXEL_RGB565,
    LL_PIXEL_RGBA8888
} LL_PixelFormat;

typedef struct {
    unsigned int texture;
    unsigned char *rgba_pixels;
    int width;
    int height;
} LL_Renderer;

int ll_renderer_init(LL_Renderer *renderer, int width, int height);
void ll_renderer_destroy(LL_Renderer *renderer);
int ll_renderer_present(LL_Renderer *renderer,
                        const void *pixels,
                        size_t pixels_size,
                        size_t pitch,
                        LL_PixelFormat format,
                        const unsigned char palette_rgba[256][4]);
int ll_renderer_present_fit(LL_Renderer *renderer,
                            const void *pixels,
                            size_t pixels_size,
                            size_t pitch,
                            LL_PixelFormat format,
                            const unsigned char palette_rgba[256][4]);

/* Present RGBA pixels directly to screen with given dimensions.
 * Used by the surface module for presenting surfaces. */
int ll_renderer_present_pixels(LL_Renderer *renderer,
                               const unsigned char *pixels,
                               int width, int height, int pitch,
                               LL_PixelFormat format,
                               int drawable_width, int drawable_height);

#endif
