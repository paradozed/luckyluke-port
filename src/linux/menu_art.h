#ifndef LL_MENU_ART_H
#define LL_MENU_ART_H

#include <GL/gl.h>
#include <stddef.h>

/*
 * Menu art helpers.
 *
 * Loads original PCX menu textures (extracted from localized KXP archives such
 * as win\graphics\newmenu.kxp and win\graphics\menu_e.kxp) into OpenGL textures
 * and draws them as textured quads.  All functions fail gracefully: if a PCX
 * file cannot be found or decoded, the caller should fall back to procedural
 * rendering.
 */

typedef struct {
    unsigned int texture;
    int width;
    int height;
    int loaded;
} LL_MenuTexture;

/* Load a PCX file from disk into an OpenGL texture.  Returns 1 on success and
 * fills in texture/width/height.  Returns 0 on any error (missing file,
 * invalid PCX, GL failure).  The texture uses nearest filtering and clamp
 * wrapping, matching the original game's pixel-art look. */
int ll_menu_art_load(const char *path, LL_MenuTexture *tex);

/* Load a PCX image from a memory buffer into an OpenGL texture.  Returns 1 on
 * success and fills in texture/width/height.  Returns 0 on any error. */
int ll_menu_art_load_from_memory(const unsigned char *pcx_data, size_t pcx_size,
                                 LL_MenuTexture *tex);

/* Load raw RGBA8888 pixel data into an OpenGL texture.  Returns 1 on success
 * and fills in texture/width/height.  Returns 0 on any error. */
int ll_menu_art_load_from_rgba(const unsigned char *rgba_data,
                               int width, int height,
                               LL_MenuTexture *tex);

/* Draw a loaded texture as an axis-aligned quad.  No-op if not loaded. */
void ll_menu_art_draw(const LL_MenuTexture *tex, float x, float y,
                      float width, float height);

/* Release the OpenGL texture. */
void ll_menu_art_destroy(LL_MenuTexture *tex);

#endif
