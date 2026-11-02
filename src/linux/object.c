#include "object.h"
#include "pcx.h"

#include <SDL2/SDL_opengl.h>

#include <stdlib.h>
#include <string.h>

LL_Object *ll_object_list = NULL;

LL_Object *ll_object_create(LL_ObjectType type, float x, float y,
                            float w, float h)
{
    LL_Object *obj;

    obj = (LL_Object *)calloc(1, sizeof(*obj));
    if (obj == NULL) {
        return NULL;
    }

    obj->type = type;
    obj->alive = 1;
    obj->x = x;
    obj->y = y;
    obj->w = w;
    obj->h = h;
    obj->next = ll_object_list;
    ll_object_list = obj;

    return obj;
}

void ll_object_destroy(LL_Object *obj)
{
    LL_Object **pp;

    if (obj == NULL) {
        return;
    }

    if (obj->destroy != NULL) {
        obj->destroy(obj);
    }
    if (obj->sprite.loaded) {
        ll_menu_art_destroy(&obj->sprite);
    }

    for (pp = &ll_object_list; *pp != NULL; pp = &(*pp)->next) {
        if (*pp == obj) {
            *pp = obj->next;
            free(obj);
            return;
        }
    }
}

void ll_object_clear(void)
{
    while (ll_object_list != NULL) {
        ll_object_destroy(ll_object_list);
    }
}

void ll_object_update_all(float dt)
{
    LL_Object *obj;

    obj = ll_object_list;
    while (obj != NULL) {
        LL_Object *next = obj->next;
        if (obj->alive && obj->update != NULL) {
            if (!obj->update(obj, dt)) {
                ll_object_destroy(obj);
            }
        }
        obj = next;
    }
}

void ll_object_render_all(void)
{
    LL_Object *obj;

    obj = ll_object_list;
    while (obj != NULL) {
        if (obj->alive && obj->render != NULL) {
            obj->render(obj);
        }
        obj = obj->next;
    }
}

int ll_object_set_sprite(LL_Object *obj, const unsigned char *pcx_data,
                         size_t pcx_size)
{
    if (obj == NULL || pcx_data == NULL) {
        return 0;
    }

    if (obj->sprite.loaded) {
        ll_menu_art_destroy(&obj->sprite);
    }

    return ll_menu_art_load_from_memory(pcx_data, pcx_size, &obj->sprite);
}

LL_Object *ll_object_find_player(void)
{
    LL_Object *obj;

    obj = ll_object_list;
    while (obj != NULL) {
        if (obj->alive && obj->type == LL_OBJ_PLAYER) {
            return obj;
        }
        obj = obj->next;
    }
    return NULL;
}
