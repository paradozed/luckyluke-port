#ifndef LL_SURFACE_H
#define LL_SURFACE_H

#include <stddef.h>
#include <stdint.h>
#include "renderer.h"

/*
 * DirectDraw surface emulation for the native Linux port.
 *
 * The original game uses DirectDraw surfaces for offscreen rendering,
 * double buffering, and texture management. This module implements a
 * software surface layer that mimics the DirectDraw surface API:
 *
 *   - Surfaces hold pixel data in system memory
 *   * Lock/Unlock provide direct pixel access
 *   * Blit copies between surfaces
 *   * Flip swaps two surfaces (used for double buffering)
 *   * Present uploads a surface to OpenGL and draws it
 *
 * Surface types:
 *   PRIMARY  - The front buffer, presented to screen each frame
 *   BACKBUFFER - The back buffer, drawn to then flipped with primary
 *   OFFSCREEN  - Offscreen surface for sprites, textures, etc.
 */

typedef struct LL_Surface LL_Surface;
typedef struct LL_SurfaceManager LL_SurfaceManager;

typedef enum {
    LL_SURFACE_PRIMARY,
    LL_SURFACE_BACKBUFFER,
    LL_SURFACE_OFFSCREEN
} LL_SurfaceType;

/* Create a surface with the given dimensions and pixel format.
 * Returns NULL on allocation failure. */
LL_Surface *ll_surface_create(int width, int height, LL_PixelFormat format);

/* Destroy a surface and release all resources. */
void ll_surface_destroy(LL_Surface *surface);

/* Lock a surface for direct pixel access.
 * Returns a pointer to the pixel data, or NULL on failure.
 * The surface must be unlocked with ll_surface_unlock before
 * it can be presented or used in blits. */
unsigned char *ll_surface_lock(LL_Surface *surface);

/* Unlock a surface after modification. Marks the surface as dirty
 * so it will be re-uploaded on next present. Returns 1 on success. */
int ll_surface_unlock(LL_Surface *surface);

/* Blit (copy) a rectangular region from source surface to destination.
 * Returns 1 on success, 0 on failure. */
int ll_surface_blit(LL_Surface *dst, int dst_x, int dst_y,
                    LL_Surface *src, int src_x, int src_y,
                    int width, int height);

/* Flip two surfaces by swapping their pixel buffers.
 * Used for double buffering: flip primary and backbuffer.
 * Returns 1 on success, 0 on failure. */
int ll_surface_flip(LL_Surface *surface1, LL_Surface *surface2);

/* Present a surface to the screen via OpenGL.
 * drawable_width/drawable_height are the window drawable dimensions.
 * Returns 1 on success, 0 on failure. */
int ll_surface_present(LL_Surface *surface,
                       int drawable_width, int drawable_height);

/* Surface manager: holds primary, backbuffer, and optional offscreen
 * surfaces. Provides convenient access and lifecycle management. */
struct LL_SurfaceManager {
    LL_Surface *primary;
    LL_Surface *backbuffer;
    LL_Surface *offscreen[32];
    int offscreen_count;
};

/* Create a surface manager with primary and backbuffer surfaces.
 * Returns NULL on allocation failure. */
LL_SurfaceManager *ll_surface_manager_create(int width, int height,
                                              LL_PixelFormat format);

/* Destroy a surface manager and all its surfaces. */
void ll_surface_manager_destroy(LL_SurfaceManager *mgr);

/* Accessors */
LL_Surface *ll_surface_manager_primary(LL_SurfaceManager *mgr);
LL_Surface *ll_surface_manager_backbuffer(LL_SurfaceManager *mgr);
LL_Surface *ll_surface_manager_offscreen(LL_SurfaceManager *mgr,
                                          int index);

#endif
