#ifndef LL_GAMEPLAY_H
#define LL_GAMEPLAY_H

#include "object.h"
#include "level.h"

/*
 * Gameplay logic for the first level (Abilene).
 *
 * Handles player creation/movement/rendering, coin spawning/collection,
 * and basic collision against the level background.  Falls back to
 * procedural rendering when original assets are unavailable.
 */

/* Initialize gameplay for the current level.  Returns 1 on success. */
int ll_gameplay_init(void);

/* Associate a level module with gameplay so that sprites can be loaded
 * from its KXP archive.  The level pointer is not owned by gameplay. */
void ll_gameplay_set_level(LL_Level *level);

/* Shut down gameplay, removing all objects. */
void ll_gameplay_shutdown(void);

/* Update gameplay each frame.  dt is seconds since the last frame. */
void ll_gameplay_update(float dt);

/* Render gameplay objects each frame. */
void ll_gameplay_render(void);

/* Handle a key press for gameplay. */
void ll_gameplay_key_down(int key);

/* Handle a key release for gameplay. */
void ll_gameplay_key_up(int key);

/* Assign gameplay update/render callbacks to a COD-spawned object based on
 * its type.  Also loads sprites from the fixgfx.kxp archive or COD texture
 * pages when available.  Returns 1 if callbacks were assigned, 0 if the
 * type is not handled by gameplay. */
int ll_gameplay_setup_cod_object(LL_Object *obj, LL_Level *level);

/* Returns 1 when gameplay is active (we are in a level state). */
int ll_gameplay_is_active(void);

/* Returns 1 when a player object exists in the object list. */
int ll_gameplay_has_player(void);

#endif
