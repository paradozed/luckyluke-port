#ifndef LL_LEVEL_H
#define LL_LEVEL_H

#include "renderer.h"
#include "cod.h"
#include "object.h"
#include "bib.h"

/*
 * Level management for the native Linux port.
 *
 * The original game uses a screen/state selector (DAT_004e8914).  State 1 is
 * the main menu; state 2 is the first level, Abilene
 * (abilene\abilene.cod).  This module loads Abilene assets from KXP archives
 * and COD scripts, and renders the level, falling back to procedural drawing
 * when assets are unavailable.
 */

typedef struct LL_Level {
    int state;               /* Current game state (1 = menu, 2 = Abilene, ...) */
    int enabled;             /* 1 when the level module is active for the current state */
    LL_Renderer renderer;    /* OpenGL presenter for level surfaces */
    unsigned char *bg_rgba;  /* Decoded background RGBA pixels (when loaded) */
    int bg_width;
    int bg_height;
    int bg_loaded;           /* 1 when background pixels are ready */
    LL_CodFile cod;          /* Parsed COD script (when available) */
    int cod_loaded;          /* 1 when COD script has been parsed */
    const unsigned char *archive_data;  /* KXP archive data (abilene.kxp) */
    size_t archive_size;     /* Size of archive data */
    int archive_loaded;      /* 1 when archive data has been set */
    const unsigned char *fixgfx_data;   /* KXP archive data (fixgfx.kxp) */
    size_t fixgfx_size;      /* Size of fixgfx archive data */
    int fixgfx_loaded;       /* 1 when fixgfx archive data has been set */
    LL_CodClut clut;         /* CLUT built from fixgfx.kxp palette */
    int clut_loaded;         /* 1 when CLUT has been built */
    LL_BibFile bib;          /* Parsed BIB sections, SOOL index, and 3DX data */
    int bib_loaded;          /* 1 when BIB structural parsing succeeded */
} LL_Level;

/* Initialize the level module.  Returns 1 on success. */
int ll_level_init(LL_Level *level, int renderer_width, int renderer_height);

/* Shut down the level module, releasing all resources. */
void ll_level_destroy(LL_Level *level);

/* Switch to a new game state.  Returns 1 if the state was recognized and
 * level assets were loaded (or are being loaded), 0 otherwise. */
int ll_level_set_state(LL_Level *level, int state);

/* Returns 1 when level assets (background) are loaded and ready to render. */
int ll_level_has_assets(const LL_Level *level);

/* Returns 1 when the COD script has been parsed and objects spawned. */
int ll_level_has_cod(const LL_Level *level);

/* Returns 1 when a KXP archive has been set for sprite loading. */
int ll_level_has_archive(const LL_Level *level);

/* Render the current level state.  Should be called each frame from the
 * render loop.  Returns 1 on success. */
int ll_level_render(LL_Level *level);

/* Try to load and decode the Abilene background PCX from the archive buffer.
 * Returns 1 on success.  This is a no-op when no archive data is provided. */
int ll_level_load_background_from_archive(LL_Level *level,
                                          const unsigned char *archive_data,
                                          size_t archive_size,
                                          const char *member_name);

/* Load a loose PCX image into the level background. */
int ll_level_load_background_from_pcx(LL_Level *level,
                                      const unsigned char *pcx_data,
                                      size_t pcx_size);

/* Set the KXP archive data for sprite loading.  The buffer must remain valid
 * for the lifetime of the level.  Returns 1 on success. */
int ll_level_set_archive(LL_Level *level,
                         const unsigned char *archive_data,
                         size_t archive_size);

/* Load a PCX member from the archive into an LL_MenuTexture.  Returns 1 on
 * success, 0 if the archive is not set or the member is not found. */
int ll_level_load_sprite(LL_Level *level,
                         const char *member_name,
                         LL_MenuTexture *tex);

/* Set the fixgfx KXP archive data for player sprite loading.  The buffer
 * must remain valid for the lifetime of the level.  Returns 1 on success. */
int ll_level_set_fixgfx_archive(LL_Level *level,
                                const unsigned char *archive_data,
                                size_t archive_size);

/* Returns 1 when the fixgfx KXP archive has been set. */
int ll_level_has_fixgfx(const LL_Level *level);

/* Load a PCX member from the fixgfx archive into an LL_MenuTexture.
 * Returns 1 on success, 0 if the archive is not set or the member is not
 * found. */
int ll_level_load_fixgfx_sprite(LL_Level *level,
                                const char *member_name,
                                LL_MenuTexture *tex);

/* Load and parse a COD script from a memory buffer.  Returns 1 on success.
 * The COD file defines object placement for the level (e.g.
 * abilene\abilene.cod). */
int ll_level_load_cod_from_memory(LL_Level *level,
                                  const unsigned char *cod_data,
                                  size_t cod_size);

/* Spawn game objects from the loaded COD script.  Returns the number of
 * objects spawned. */
int ll_level_spawn_cod_objects(LL_Level *level);

/* Returns a pointer to the raw COD texture page data for the given page
 * index, or NULL if not available.  Each page is 0x8000 bytes. */
const unsigned char *ll_level_get_cod_texture_page(const LL_Level *level,
                                                   uint32_t page_index,
                                                   size_t *out_size);

/* Build a CLUT from a PCX palette member in the fixgfx.kxp archive.
 * The palette member should contain 256 RGB entries (768 bytes).  Returns 1
 * on success, 0 if fixgfx archive is not set or the member is not found. */
int ll_level_build_clut_from_fixgfx_palette(LL_Level *level,
                                            const char *palette_member);

/* Decode a COD texture page to RGBA pixels using the level's CLUT.
 * Output is written to rgba_out which must hold at least 128*128*4 bytes.
 * Returns 1 on success, 0 if CLUT or texture page is not available. */
int ll_level_decode_cod_texture_page(LL_Level *level,
                                     uint32_t page_index,
                                     unsigned char *rgba_out);

/* Load and parse the BIB selector sections, SOOL records, and 3DX model data
 * from a memory buffer. The input data must remain valid until level destroy. */
int ll_level_load_bib_from_memory(LL_Level *level,
                                  const unsigned char *bib_data,
                                  size_t bib_size);

/* Returns 1 when the BIB's recognized container and section data were parsed. */
int ll_level_has_bib(const LL_Level *level);

#endif
