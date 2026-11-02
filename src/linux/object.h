#ifndef LL_OBJECT_H
#define LL_OBJECT_H

#include "renderer.h"
#include "menu_art.h"

/*
 * Game object system for the native Linux port.
 *
 * The original game uses a COD script interpreter to spawn and control
 * level objects (player, coins, platforms, enemies, etc.).  This module
 * provides a native object list with update/render callbacks, sprite
 * loading from PCX data, and basic transform state.
 */

typedef struct LL_Object LL_Object;

/* Object type identifiers. */
typedef enum {
    LL_OBJ_NONE = 0,
    LL_OBJ_PLAYER,
    LL_OBJ_COIN,
    LL_OBJ_PLATFORM,
    LL_OBJ_BACKGROUND,
    LL_OBJ_MAX
} LL_ObjectType;

/* Update callback: returns 1 if the object should remain alive, 0 to remove. */
typedef int (*LL_ObjectUpdate)(LL_Object *obj, float dt);

/* Render callback. */
typedef void (*LL_ObjectRender)(const LL_Object *obj);

/* Destroy callback. */
typedef void (*LL_ObjectDestroy)(LL_Object *obj);

struct LL_Object {
    LL_ObjectType type;
    int alive;
    unsigned int flags;     /* COD sprite flags / object state */
    uint16_t cod_texture_page;  /* COD texture page index for this sprite */
    float x, y;        /* Position in world coordinates */
    float vx, vy;      /* Velocity */
    float w, h;        /* Size */
    LL_MenuTexture sprite;  /* Loaded sprite texture (optional) */
    LL_ObjectUpdate update;
    LL_ObjectRender render;
    LL_ObjectDestroy destroy;
    void *user_data;   /* Type-specific data */
    LL_Object *next;
};

/* Object list head. */
extern LL_Object *ll_object_list;

/* Create a new object and add it to the object list. */
LL_Object *ll_object_create(LL_ObjectType type, float x, float y,
                            float w, float h);

/* Destroy an object and remove it from the list. */
void ll_object_destroy(LL_Object *obj);

/* Remove all objects from the list. */
void ll_object_clear(void);

/* Update all objects (call once per frame). */
void ll_object_update_all(float dt);

/* Render all objects (call once per frame). */
void ll_object_render_all(void);

/* Load a sprite from PCX data into an object's texture.  Returns 1 on success. */
int ll_object_set_sprite(LL_Object *obj, const unsigned char *pcx_data,
                         size_t pcx_size);

/* Find the player object, if any. */
LL_Object *ll_object_find_player(void);

#endif
