#include "level.h"
#include "kxp.h"
#include "pcx.h"
#include "gameplay.h"

#include <SDL2/SDL_opengl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Abilene (state 2) asset loading from KXP archives and an experimental
 * port-side data parser. The original .cod file is a SOOL program; the
 * original object/sprite/tile/page data is stored in .biz and is not parsed
 * by ll_cod_open().
 *
 * The original game loads these from abilene\abilene.kxp via FUN_00441560:
 *   back.pcx        - level background (state 2 and 3)
 *   coin1..coin11.pcx - animated coins (state 2 only)
 * From win\graphics\fixgfx.kxp:
 *   wood.pcx, moon.pcx, wanted.pcx (state 2)
 *
 * Original program selection:
 *   FUN_00405350 maps state 2 -> "abilene\\abilene.cod" (SOOL runtime)
 *   FUN_0044b320 parses the corresponding BIZ resources for scene data
 *
 * When assets are unavailable (no game installation present), the level
 * falls back to procedural rendering handled by the caller.
 */

int ll_level_init(LL_Level *level, int renderer_width, int renderer_height)
{
    if (level == NULL || renderer_width <= 0 || renderer_height <= 0) {
        return 0;
    }

    memset(level, 0, sizeof(*level));

    level->state = 1;
    level->enabled = 0;
    level->bg_rgba = NULL;
    level->bg_width = 0;
    level->bg_height = 0;
    level->bg_loaded = 0;
    level->cod_loaded = 0;
    level->clut_loaded = 0;
    level->bib_loaded = 0;

    if (!ll_renderer_init(&level->renderer, renderer_width, renderer_height)) {
        return 0;
    }

    return 1;
}

void ll_level_destroy(LL_Level *level)
{
    if (level == NULL) {
        return;
    }
    free(level->bg_rgba);
    level->bg_rgba = NULL;
    level->bg_width = 0;
    level->bg_height = 0;
    level->bg_loaded = 0;
    ll_cod_close(&level->cod);
    level->cod_loaded = 0;
    ll_bib_close(&level->bib);
    level->bib_loaded = 0;
    level->archive_data = NULL;
    level->archive_size = 0;
    level->archive_loaded = 0;
    level->fixgfx_data = NULL;
    level->fixgfx_size = 0;
    level->fixgfx_loaded = 0;
    level->clut_loaded = 0;
    ll_renderer_destroy(&level->renderer);
    memset(level, 0, sizeof(*level));
}

static int decode_pcx_to_rgba(const unsigned char *pcx_data, size_t pcx_size,
                              unsigned char **out_rgba, int *out_width,
                              int *out_height)
{
    LL_PcxImage image;
    unsigned char *rgba;
    size_t pixel_count;

    if (pcx_data == NULL || out_rgba == NULL || out_width == NULL ||
        out_height == NULL) {
        return 0;
    }

    if (!ll_pcx_decode(pcx_data, pcx_size, &image)) {
        return 0;
    }

    pixel_count = (size_t)image.width * (size_t)image.height;
    rgba = (unsigned char *)malloc(pixel_count * 4);
    if (rgba == NULL) {
        ll_pcx_destroy(&image);
        return 0;
    }

    /* PCX decoder already produces RGBA with alpha=255.  Copy as-is. */
    memcpy(rgba, image.rgba_pixels, pixel_count * 4);

    *out_rgba = rgba;
    *out_width = image.width;
    *out_height = image.height;

    ll_pcx_destroy(&image);
    return 1;
}

static int store_background(LL_Level *level, unsigned char *rgba, int width, int height)
{
    /* The presenter reads its own dimensions, not the window dimensions.
     * An original 512x256 title cannot be uploaded as a 640x480 surface. */
    if (level->renderer.width!=width || level->renderer.height!=height) {
        LL_Renderer renderer={0};
        if (!ll_renderer_init(&renderer,width,height)) { free(rgba);return 0; }
        ll_renderer_destroy(&level->renderer);level->renderer=renderer;
    }
    free(level->bg_rgba);
    level->bg_rgba=rgba;level->bg_width=width;level->bg_height=height;
    level->bg_loaded=1;
    return 1;
}

int ll_level_load_background_from_archive(LL_Level *level,
                                          const unsigned char *archive_data,
                                          size_t archive_size,
                                          const char *member_name)
{
    LL_KxpArchive arch;
    const unsigned char *payload = NULL;
    size_t payload_size = 0;
    unsigned char *payload_copy = NULL;
    unsigned char *rgba = NULL;
    int width = 0;
    int height = 0;

    if (level == NULL || archive_data == NULL || member_name == NULL) {
        return 0;
    }

    if (!ll_kxp_open(&arch, archive_data, archive_size, "lucky")) {
        return 0;
    }

    if (!ll_kxp_find(&arch, member_name, &payload, &payload_size)) {
        ll_kxp_close(&arch);
        return 0;
    }

    /* Copy the payload so it can be decrypted without modifying the archive. */
    payload_copy = (unsigned char *)malloc(payload_size);
    if (payload_copy == NULL) {
        ll_kxp_close(&arch);
        return 0;
    }
    memcpy(payload_copy, payload, payload_size);

    /* Encrypted archives use the repeating-key XOR scheme with key "lucky". */
    if (arch.encrypted) {
        if (!ll_kxp_decrypt(payload_copy, payload_size, "lucky")) {
            free(payload_copy);
            ll_kxp_close(&arch);
            return 0;
        }
    }

    ll_kxp_close(&arch);

    if (!decode_pcx_to_rgba(payload_copy, payload_size, &rgba, &width, &height)) {
        free(payload_copy);
        return 0;
    }
    free(payload_copy);

    return store_background(level,rgba,width,height);
}

int ll_level_load_background_from_pcx(LL_Level *level,
                                      const unsigned char *pcx_data,
                                      size_t pcx_size)
{
    unsigned char *rgba = NULL;
    int width = 0, height = 0;
    if (level == NULL || pcx_data == NULL || pcx_size == 0 ||
        !decode_pcx_to_rgba(pcx_data, pcx_size, &rgba, &width, &height)) return 0;
    return store_background(level,rgba,width,height);
}

int ll_level_set_state(LL_Level *level, int state)
{
    if (level == NULL) {
        return 0;
    }

    level->state = state;

    /* State 2 is Abilene, the first level.  Other states are not yet ported. */
    level->enabled = (state == 2) ? 1 : 0;
    return level->enabled;
}

int ll_level_has_assets(const LL_Level *level)
{
    if (level == NULL) {
        return 0;
    }
    return level->bg_loaded;
}

int ll_level_has_cod(const LL_Level *level)
{
    if (level == NULL) {
        return 0;
    }
    return level->cod_loaded;
}

int ll_level_load_cod_from_memory(LL_Level *level,
                                  const unsigned char *cod_data,
                                  size_t cod_size)
{
    if (level == NULL || cod_data == NULL) {
        return 0;
    }

    /* Close any previously loaded COD file. */
    ll_cod_close(&level->cod);
    level->cod_loaded = 0;

    if (!ll_cod_open(&level->cod, cod_data, cod_size)) {
        return 0;
    }

    level->cod_loaded = 1;
    return 1;
}

int ll_level_spawn_cod_objects(LL_Level *level)
{
    int spawned = 0;
    uint32_t i;

    if (level == NULL || !level->cod_loaded || !ll_cod_is_valid(&level->cod)) {
        return 0;
    }

    /* Spawn one game object per COD sprite entry.  Each sprite defines an
     * object type, position, size, and texture page reference. */
    for (i = 0; i < level->cod.num_sprites; i++) {
        const LL_CodSprite *spr = &level->cod.sprites[i];
        LL_Object *obj;

        obj = ll_object_create((LL_ObjectType)spr->type,
                               (float)spr->x, (float)spr->y,
                               (float)spr->w, (float)spr->h);
        if (obj == NULL) {
            continue;
        }

        obj->flags = spr->flags;
        obj->cod_texture_page = spr->texture_page;

        /* Assign gameplay callbacks (player movement, coin animation/collection)
         * based on the COD object type. */
        ll_gameplay_setup_cod_object(obj, level);

        spawned++;
    }

    return spawned;
}

int ll_level_render(LL_Level *level)
{
    if (level == NULL || !level->enabled) {
        return 0;
    }

    if (level->bg_loaded && level->bg_rgba != NULL) {
        /* Present the decoded background as a fitted texture. */
        if (!ll_renderer_present_fit(&level->renderer, level->bg_rgba,
                                     (size_t)level->bg_width *
                                         (size_t)level->bg_height * 4,
                                     (size_t)level->bg_width * 4,
                                     LL_PIXEL_RGBA8888, NULL)) {
            return 0;
        }
        return 1;
    }

    /* No assets available: caller should fall back to procedural rendering. */
    return 0;
}

int ll_level_has_archive(const LL_Level *level)
{
    if (level == NULL) {
        return 0;
    }
    return level->archive_loaded;
}

int ll_level_set_archive(LL_Level *level,
                         const unsigned char *archive_data,
                         size_t archive_size)
{
    if (level == NULL || archive_data == NULL || archive_size == 0) {
        return 0;
    }

    /* Validate that the buffer looks like a KXP archive before storing it. */
    LL_KxpArchive test_arch;
    if (!ll_kxp_open(&test_arch, archive_data, archive_size, "lucky")) {
        return 0;
    }
    ll_kxp_close(&test_arch);

    level->archive_data = archive_data;
    level->archive_size = archive_size;
    level->archive_loaded = 1;
    return 1;
}

int ll_level_load_sprite(LL_Level *level,
                         const char *member_name,
                         LL_MenuTexture *tex)
{
    LL_KxpArchive arch;
    const unsigned char *payload = NULL;
    size_t payload_size = 0;
    unsigned char *payload_copy = NULL;

    if (level == NULL || !level->archive_loaded || member_name == NULL ||
        tex == NULL) {
        return 0;
    }

    if (!ll_kxp_open(&arch, level->archive_data, level->archive_size,
                     "lucky")) {
        return 0;
    }

    if (!ll_kxp_find(&arch, member_name, &payload, &payload_size)) {
        ll_kxp_close(&arch);
        return 0;
    }

    /* Copy the payload so it can be decrypted without modifying the archive. */
    payload_copy = (unsigned char *)malloc(payload_size);
    if (payload_copy == NULL) {
        ll_kxp_close(&arch);
        return 0;
    }
    memcpy(payload_copy, payload, payload_size);

    /* Encrypted archives use the repeating-key XOR scheme with key "lucky". */
    if (arch.encrypted) {
        if (!ll_kxp_decrypt(payload_copy, payload_size, "lucky")) {
            free(payload_copy);
            ll_kxp_close(&arch);
            return 0;
        }
    }

    ll_kxp_close(&arch);

    /* Load the decoded PCX into an OpenGL texture. */
    int result = ll_menu_art_load_from_memory(payload_copy, payload_size, tex);
    free(payload_copy);
    return result;
}

int ll_level_set_fixgfx_archive(LL_Level *level,
                                const unsigned char *archive_data,
                                size_t archive_size)
{
    if (level == NULL || archive_data == NULL || archive_size == 0) {
        return 0;
    }

    /* Validate that the buffer looks like a KXP archive before storing it. */
    LL_KxpArchive test_arch;
    if (!ll_kxp_open(&test_arch, archive_data, archive_size, "lucky")) {
        return 0;
    }
    ll_kxp_close(&test_arch);

    level->fixgfx_data = archive_data;
    level->fixgfx_size = archive_size;
    level->fixgfx_loaded = 1;
    return 1;
}

int ll_level_has_fixgfx(const LL_Level *level)
{
    if (level == NULL) {
        return 0;
    }
    return level->fixgfx_loaded;
}

int ll_level_load_fixgfx_sprite(LL_Level *level,
                                const char *member_name,
                                LL_MenuTexture *tex)
{
    LL_KxpArchive arch;
    const unsigned char *payload = NULL;
    size_t payload_size = 0;
    unsigned char *payload_copy = NULL;

    if (level == NULL || !level->fixgfx_loaded || member_name == NULL ||
        tex == NULL) {
        return 0;
    }

    if (!ll_kxp_open(&arch, level->fixgfx_data, level->fixgfx_size,
                     "lucky")) {
        return 0;
    }

    if (!ll_kxp_find(&arch, member_name, &payload, &payload_size)) {
        ll_kxp_close(&arch);
        return 0;
    }

    /* Copy the payload so it can be decrypted without modifying the archive. */
    payload_copy = (unsigned char *)malloc(payload_size);
    if (payload_copy == NULL) {
        ll_kxp_close(&arch);
        return 0;
    }
    memcpy(payload_copy, payload, payload_size);

    /* Encrypted archives use the repeating-key XOR scheme with key "lucky". */
    if (arch.encrypted) {
        if (!ll_kxp_decrypt(payload_copy, payload_size, "lucky")) {
            free(payload_copy);
            ll_kxp_close(&arch);
            return 0;
        }
    }

    ll_kxp_close(&arch);

    /* Load the decoded PCX into an OpenGL texture. */
    int result = ll_menu_art_load_from_memory(payload_copy, payload_size, tex);
    free(payload_copy);
    return result;
}

const unsigned char *ll_level_get_cod_texture_page(const LL_Level *level,
                                                   uint32_t page_index,
                                                   size_t *out_size)
{
    if (level == NULL || !level->cod_loaded) {
        return NULL;
    }
    return ll_cod_get_texture_page(&level->cod, page_index, out_size);
}

int ll_level_build_clut_from_fixgfx_palette(LL_Level *level,
                                            const char *palette_member)
{
    LL_KxpArchive arch;
    const unsigned char *payload = NULL;
    size_t payload_size = 0;
    unsigned char *payload_copy = NULL;
    unsigned char palette[768];
    int palette_entries;

    if (level == NULL || !level->fixgfx_loaded || palette_member == NULL) {
        return 0;
    }

    if (!ll_kxp_open(&arch, level->fixgfx_data, level->fixgfx_size,
                     "lucky")) {
        return 0;
    }

    if (!ll_kxp_find(&arch, palette_member, &payload, &payload_size)) {
        ll_kxp_close(&arch);
        return 0;
    }

    /* Copy the payload so it can be decrypted without modifying the archive. */
    payload_copy = (unsigned char *)malloc(payload_size);
    if (payload_copy == NULL) {
        ll_kxp_close(&arch);
        return 0;
    }
    memcpy(payload_copy, payload, payload_size);

    /* Encrypted archives use the repeating-key XOR scheme with key "lucky". */
    if (arch.encrypted) {
        if (!ll_kxp_decrypt(payload_copy, payload_size, "lucky")) {
            free(payload_copy);
            ll_kxp_close(&arch);
            return 0;
        }
    }

    ll_kxp_close(&arch);

    /* Extract the PCX palette. */
    palette_entries = ll_pcx_extract_palette(payload_copy, payload_size,
                                             palette);
    free(payload_copy);

    if (palette_entries <= 0) {
        return 0;
    }

    /* Build the CLUT from the palette. */
    if (!ll_cod_clut_build_from_pcx_palette(&level->clut, palette,
                                            palette_entries)) {
        return 0;
    }

    level->clut_loaded = 1;
    return 1;
}

int ll_level_decode_cod_texture_page(LL_Level *level,
                                     uint32_t page_index,
                                     unsigned char *rgba_out)
{
    const unsigned char *page_data;
    size_t page_size;

    if (level == NULL || !level->cod_loaded || rgba_out == NULL) {
        return 0;
    }

    page_data = ll_level_get_cod_texture_page(level, page_index, &page_size);
    if (page_data == NULL) {
        return 0;
    }

    return ll_cod_decode_texture_page(page_data, page_size, rgba_out);
}

/* ---- BIB container and menu 3DX catalogue ---- */

int ll_level_load_bib_from_memory(LL_Level *level,
                                  const unsigned char *bib_data,
                                  size_t bib_size)
{
    if (level == NULL || bib_data == NULL) {
        return 0;
    }

    ll_bib_close(&level->bib);
    level->bib_loaded = 0;

    if (!ll_bib_open(&level->bib, bib_data, bib_size)) {
        return 0;
    }

    level->bib_loaded = 1;
    return 1;
}

int ll_level_has_bib(const LL_Level *level)
{
    if (level == NULL) {
        return 0;
    }
    return level->bib_loaded;
}
