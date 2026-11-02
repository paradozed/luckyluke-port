#include "gameplay.h"
#include "level.h"
#include "kxp.h"
#include "pcx.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*
 * Gameplay constants.
 *
 * These mirror the feel of the original game's platformer physics
 * (gravity, move speed, jump strength) but are tuned for the native
 * 640x480 OpenGL viewport.
 */

#define PLAYER_W 32.0f
#define PLAYER_H 48.0f
#define PLAYER_SPEED 180.0f   /* pixels per second */
#define PLAYER_JUMP 330.0f    /* initial upward velocity */
#define PLAYER_GRAVITY 900.0f /* pixels per second^2 */
#define COIN_W 24.0f
#define COIN_H 24.0f
#define COIN_BOB_SPEED 3.0f
#define COIN_BOB_AMPLITUDE 8.0f
#define COIN_SPIN_SPEED 6.0f  /* radians per second */

/* Input state. */
static int key_left = 0;
static int key_right = 0;
static int key_jump = 0;

/* Gameplay state. */
static int gameplay_active = 0;
static int player_spawned = 0;
static LL_Object *player_obj = NULL;
static float coin_timer = 0.0f;
static LL_Level *gameplay_level = NULL;

/* Procedural fallback: draw a colored rectangle with a simple outline. */
static void draw_procedural_sprite(float x, float y, float w, float h,
                                   float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}

/* --- Player update --- */

#define PLAYER_ANIM_FRAMES 4
#define PLAYER_ANIM_INTERVAL 0.12f  /* seconds between run animation frames */

int player_update(LL_Object *obj, float dt)
{
    float nx = obj->x;
    float ny = obj->y;
    float nvy = obj->vy;
    int on_ground = 0;
    int moving = 0;

    /* Track animation frame for running. */
    static float anim_timer = 0.0f;
    int *frame = (int *)obj->user_data;

    /* Horizontal movement. */
    if (key_left) {
        nx -= PLAYER_SPEED * dt;
        moving = 1;
    }
    if (key_right) {
        nx += PLAYER_SPEED * dt;
        moving = 1;
    }

    /* Jump. */
    if (key_jump && obj->vy == 0.0f) {
        nvy = -PLAYER_JUMP;
    }

    /* Apply gravity. */
    nvy += PLAYER_GRAVITY * dt;
    ny += nvy * dt;

    /* Simple ground clamp (procedural floor at y = 400). */
    if (ny + obj->h > 400.0f) {
        ny = 400.0f - obj->h;
        nvy = 0.0f;
        on_ground = 1;
    }

    obj->x = nx;
    obj->y = ny;
    obj->vy = nvy;
    (void)on_ground;

    /* Advance animation frame while moving. */
    if (frame != NULL && moving && on_ground) {
        anim_timer += dt;
        if (anim_timer >= PLAYER_ANIM_INTERVAL) {
            anim_timer = 0.0f;
            *frame = (*frame + 1) % PLAYER_ANIM_FRAMES;
            /* The mounted FIXGFX archive contains no RUN*.PCX sequence. Keep
             * the procedural fallback instead of probing absent filenames on
             * every animation frame. */
        }
    }

    return 1;
}

void player_render(const LL_Object *obj)
{
    if (obj->sprite.loaded) {
        ll_menu_art_draw(&obj->sprite, obj->x, obj->y, obj->w, obj->h);
    }
    else {
        draw_procedural_sprite(obj->x, obj->y, obj->w, obj->h,
                               0.9f, 0.7f, 0.3f);
    }
}

/* --- Coin update --- */

#define COIN_ANIM_FRAMES 11
#define COIN_ANIM_INTERVAL 0.1f  /* seconds between animation frames */

int coin_update(LL_Object *obj, float dt)
{
    /* Animate through coin1.pcx..coin11.pcx frames.
     * The frame index is stored in obj->user_data as a small integer. */
    intptr_t frame_val = (intptr_t)obj->user_data;
    int frame = (int)frame_val;

    static float anim_timer = 0.0f;
    anim_timer += dt;
    if (anim_timer >= COIN_ANIM_INTERVAL) {
        anim_timer = 0.0f;
        frame = (frame + 1) % COIN_ANIM_FRAMES;
        obj->user_data = (void *)(intptr_t)frame;
        /* Reload the sprite for the new animation frame. */
        if (gameplay_level != NULL) {
            char member[32];
            snprintf(member, sizeof(member), "COIN%d.PCX", frame + 1);
            ll_menu_art_destroy(&obj->sprite);
            ll_level_load_sprite(gameplay_level, member, &obj->sprite);
        }
    }

    obj->y += sinf(SDL_GetTicks() * 0.001f * COIN_BOB_SPEED) * 0.5f * dt * 60.0f;

    /* Simple spin effect: width oscillates. */
    float spin = cosf(SDL_GetTicks() * 0.001f * COIN_SPIN_SPEED);
    obj->w = COIN_W * (0.5f + 0.5f * fabsf(spin));

    /* Collection: check against player. */
    LL_Object *player = ll_object_find_player();
    if (player != NULL && player->alive) {
        if (obj->x < player->x + player->w &&
            obj->x + obj->w > player->x &&
            obj->y < player->y + player->h &&
            obj->y + obj->h > player->y) {
            obj->alive = 0;
        }
    }

    return obj->alive;
}

void coin_render(const LL_Object *obj)
{
    if (obj->sprite.loaded) {
        ll_menu_art_draw(&obj->sprite, obj->x, obj->y, obj->w, obj->h);
    }
    else {
        draw_procedural_sprite(obj->x, obj->y, obj->w, obj->h,
                               1.0f, 0.85f, 0.2f);
    }
}

/* Assign gameplay callbacks to a COD-spawned object based on its type.
 * Also loads sprites from the fixgfx.kxp archive or COD texture pages when
 * available. */
int ll_gameplay_setup_cod_object(LL_Object *obj, LL_Level *level)
{
    if (obj == NULL) {
        return 0;
    }

    switch (obj->type) {
    case LL_OBJ_PLAYER:
        obj->update = player_update;
        obj->render = player_render;
        /* Initialize animation frame data. */
        obj->user_data = (void *)(intptr_t)0;
        /* Try to load player sprite from COD texture page first. */
        if (level != NULL && obj->cod_texture_page < 16 && !obj->sprite.loaded) {
            unsigned char rgba[128 * 128 * 4];
            if (ll_level_decode_cod_texture_page(level, obj->cod_texture_page,
                                                 rgba)) {
                (void)ll_menu_art_load_from_rgba(rgba, 128, 128, &obj->sprite);
            }
        }
        /* The mounted FIXGFX.KXP has character parts but no RUN*.PCX frames;
         * render the procedural fallback until BIZ models are connected. */
        return 1;
    case LL_OBJ_COIN:
        obj->update = coin_update;
        obj->render = coin_render;
        /* The mounted disc has no ABILENE KXP coin archive; keep the
         * procedural coin unless a compatible archive was supplied. */
        if (level != NULL && !obj->sprite.loaded) {
            (void)ll_level_load_sprite(level, "COIN1.PCX", &obj->sprite);
        }
        /* Fall back to COD texture page. */
        if (level != NULL && obj->cod_texture_page < 16 && !obj->sprite.loaded) {
            unsigned char rgba[128 * 128 * 4];
            if (ll_level_decode_cod_texture_page(level, obj->cod_texture_page,
                                                 rgba)) {
                (void)ll_menu_art_load_from_rgba(rgba, 128, 128, &obj->sprite);
            }
        }
        return 1;
    default:
        /* Other object types are static level geometry with no callbacks. */
        return 0;
    }
}

/* Returns 1 when a player object exists in the object list. */
int ll_gameplay_has_player(void)
{
    return ll_object_find_player() != NULL;
}

void ll_gameplay_set_level(LL_Level *level)
{
    gameplay_level = level;
}

/* --- Public API --- */

int ll_gameplay_init(void)
{
    gameplay_active = 1;
    player_spawned = 0;
    player_obj = NULL;
    coin_timer = 0.0f;
    return 1;
}

void ll_gameplay_shutdown(void)
{
    ll_object_clear();
    gameplay_active = 0;
    player_spawned = 0;
    player_obj = NULL;
}

void ll_gameplay_update(float dt)
{
    if (!gameplay_active) {
        return;
    }

    /* Spawn the player only if no player exists yet (e.g. none was defined
     * in the COD script). */
    if (!ll_gameplay_has_player()) {
        player_obj = ll_object_create(LL_OBJ_PLAYER, 100.0f, 300.0f,
                                      PLAYER_W, PLAYER_H);
        if (player_obj != NULL) {
            player_obj->update = player_update;
            player_obj->render = player_render;
            player_obj->user_data = (void *)(intptr_t)0;
            /* Try to load player run sprite from fixgfx.kxp archive. */
            if (gameplay_level != NULL) {
                (void)ll_level_load_fixgfx_sprite(gameplay_level, "RUN1.PCX",
                                                  &player_obj->sprite);
            }
        }
    }

    /* Periodically spawn coins. */
    coin_timer += dt;
    if (coin_timer > 2.0f) {
        coin_timer = 0.0f;
        LL_Object *coin = ll_object_create(LL_OBJ_COIN, 300.0f + (float)(rand() % 200),
                                           250.0f + (float)(rand() % 100),
                                           COIN_W, COIN_H);
        if (coin != NULL) {
            coin->cod_texture_page = 0xFFFF;
            ll_gameplay_setup_cod_object(coin, gameplay_level);
        }
    }

    ll_object_update_all(dt);
}

void ll_gameplay_render(void)
{
    if (!gameplay_active) {
        return;
    }
    ll_object_render_all();
}

void ll_gameplay_key_down(int key)
{
    switch (key) {
    case SDLK_LEFT:
    case SDLK_a:
        key_left = 1;
        break;
    case SDLK_RIGHT:
    case SDLK_d:
        key_right = 1;
        break;
    case SDLK_SPACE:
    case SDLK_UP:
    case SDLK_w:
        key_jump = 1;
        break;
    default:
        break;
    }
}

void ll_gameplay_key_up(int key)
{
    switch (key) {
    case SDLK_LEFT:
    case SDLK_a:
        key_left = 0;
        break;
    case SDLK_RIGHT:
    case SDLK_d:
        key_right = 0;
        break;
    case SDLK_SPACE:
    case SDLK_UP:
    case SDLK_w:
        key_jump = 0;
        break;
    default:
        break;
    }
}

int ll_gameplay_is_active(void)
{
    return gameplay_active;
}
