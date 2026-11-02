#include "surface.h"

#include <stdlib.h>
#include <string.h>

static size_t bytes_per_pixel(LL_PixelFormat format)
{
    switch (format) {
    case LL_PIXEL_INDEX8:
        return 1;
    case LL_PIXEL_RGB555:
    case LL_PIXEL_RGB565:
        return 2;
    case LL_PIXEL_RGBA8888:
        return 4;
    default:
        return 0;
    }
}

struct LL_Surface {
    LL_PixelFormat format;
    int width;
    int height;
    int pitch;              /* bytes per row */
    unsigned char *pixels;  /* pixel buffer */
    int locked;             /* 1 if locked */
    unsigned char *lock_ptr; /* pointer returned by lock */
    int dirty;              /* 1 if pixels modified since last present */
};

LL_Surface *ll_surface_create(int width, int height, LL_PixelFormat format)
{
    LL_Surface *surf;
    size_t pixel_size;

    if (width <= 0 || height <= 0) {
        return NULL;
    }

    pixel_size = bytes_per_pixel(format);
    if (pixel_size == 0) {
        return NULL;
    }

    surf = (LL_Surface *)calloc(1, sizeof(*surf));
    if (surf == NULL) {
        return NULL;
    }

    surf->format = format;
    surf->width = width;
    surf->height = height;
    surf->pitch = (int)((size_t)width * pixel_size);
    surf->pixels = (unsigned char *)calloc(1, (size_t)width * (size_t)height * pixel_size);
    if (surf->pixels == NULL) {
        free(surf);
        return NULL;
    }

    return surf;
}

void ll_surface_destroy(LL_Surface *surface)
{
    if (surface == NULL) {
        return;
    }
    free(surface->pixels);
    memset(surface, 0, sizeof(*surface));
    free(surface);
}

unsigned char *ll_surface_lock(LL_Surface *surface)
{
    if (surface == NULL || surface->locked) {
        return NULL;
    }
    surface->locked = 1;
    surface->pixels = surface->pixels; /* ensure pointer is valid */
    return surface->pixels;
}

int ll_surface_unlock(LL_Surface *surface)
{
    if (surface == NULL || !surface->locked) {
        return 0;
    }
    surface->locked = 0;
    surface->dirty = 1;
    return 1;
}

int ll_surface_blit(LL_Surface *dst, int dst_x, int dst_y,
                    LL_Surface *src, int src_x, int src_y,
                    int width, int height)
{
    if (dst == NULL || src == NULL || dst->locked || src->locked) {
        return 0;
    }
    if (width <= 0 || height <= 0) {
        return 0;
    }

    /* Bounds check destination */
    if (dst_x < 0 || dst_y < 0 ||
        dst_x + width > dst->width ||
        dst_y + height > dst->height) {
        return 0;
    }
    /* Bounds check source */
    if (src_x < 0 || src_y < 0 ||
        src_x + width > src->width ||
        src_y + height > src->height) {
        return 0;
    }

    /* Both surfaces must have same pixel format for direct copy */
    if (dst->format != src->format) {
        return 0;
    }

    for (int row = 0; row < height; row++) {
        unsigned char *dst_row = dst->pixels +
            (size_t)(dst_y + row) * dst->pitch +
            (size_t)dst_x * bytes_per_pixel(dst->format);
        const unsigned char *src_row = src->pixels +
            (size_t)(src_y + row) * src->pitch +
            (size_t)src_x * bytes_per_pixel(src->format);
        memcpy(dst_row, src_row, (size_t)width * bytes_per_pixel(dst->format));
    }

    dst->dirty = 1;
    return 1;
}

int ll_surface_flip(LL_Surface *surface1, LL_Surface *surface2)
{
    if (surface1 == NULL || surface2 == NULL) {
        return 0;
    }
    if (surface1->locked || surface2->locked) {
        return 0;
    }

    /* Swap all fields except format (format should match) */
    unsigned char *tmp_pixels = surface1->pixels;
    int tmp_width = surface1->width;
    int tmp_height = surface1->height;
    int tmp_pitch = surface1->pitch;

    surface1->pixels = surface2->pixels;
    surface1->width = surface2->width;
    surface1->height = surface2->height;
    surface1->pitch = surface2->pitch;

    surface2->pixels = tmp_pixels;
    surface2->width = tmp_width;
    surface2->height = tmp_height;
    surface2->pitch = tmp_pitch;

    /* Mark both as dirty since they now have new content */
    surface1->dirty = 1;
    surface2->dirty = 1;

    return 1;
}

int ll_surface_present(LL_Renderer *renderer,
                       LL_Surface *surface,
                       int drawable_width, int drawable_height)
{
    if (renderer == NULL || surface == NULL || surface->pixels == NULL) {
        return 0;
    }

    return ll_renderer_present_pixels(renderer, surface->pixels,
                        surface->width, surface->height,
                        surface->pitch, surface->format,
                        drawable_width, drawable_height);
}

LL_SurfaceManager *ll_surface_manager_create(int width, int height,
                                              LL_PixelFormat format)
{
    LL_SurfaceManager *mgr;

    mgr = (LL_SurfaceManager *)calloc(1, sizeof(*mgr));
    if (mgr == NULL) {
        return NULL;
    }

    mgr->primary = ll_surface_create(width, height, format);
    if (mgr->primary == NULL) {
        free(mgr);
        return NULL;
    }

    mgr->backbuffer = ll_surface_create(width, height, format);
    if (mgr->backbuffer == NULL) {
        ll_surface_destroy(mgr->primary);
        free(mgr);
        return NULL;
    }

    mgr->offscreen_count = 0;
    return mgr;
}

void ll_surface_manager_destroy(LL_SurfaceManager *mgr)
{
    if (mgr == NULL) {
        return;
    }
    ll_surface_destroy(mgr->primary);
    ll_surface_destroy(mgr->backbuffer);
    for (int i = 0; i < mgr->offscreen_count; i++) {
        ll_surface_destroy(mgr->offscreen[i]);
    }
    free(mgr);
}

LL_Surface *ll_surface_manager_primary(LL_SurfaceManager *mgr)
{
    if (mgr == NULL) {
        return NULL;
    }
    return mgr->primary;
}

LL_Surface *ll_surface_manager_backbuffer(LL_SurfaceManager *mgr)
{
    if (mgr == NULL) {
        return NULL;
    }
    return mgr->backbuffer;
}

LL_Surface *ll_surface_manager_offscreen(LL_SurfaceManager *mgr,
                                          int index)
{
    if (mgr == NULL || index < 0 || index >= mgr->offscreen_count) {
        return NULL;
    }
    return mgr->offscreen[index];
}