#include "level_script.h"
#include "native_rng.h"
#include <stdlib.h>
#include <string.h>

static int fail(LL_LevelScript *script, const char *message)
{
    snprintf(script->error,sizeof(script->error),"%s",message);
    return 0;
}

static uint32_t animation_clock(uint32_t update)
{
    return (uint32_t)(((uint64_t)update*60u/24u)*31u);
}

static int sprite_frame_apply(LL_LevelScript *script, LL_LevelScriptObject *object,
                              uint16_t frame_index)
{
    LL_BibSpriteFrame frame;LL_BizObject biz_object;LL_BizSprite sprite;
    if (!ll_bib_get_sprite_frame(&script->bib,object->sprite_selector,frame_index,&frame) ||
        !ll_biz_get_object(&script->biz,frame.object_index,&biz_object) ||
        !ll_biz_get_sprite(&script->biz,biz_object.sprite_index,&sprite)) return 0;
    object->sprite_frame=frame_index;object->biz_object=frame.object_index;
    object->biz_sprite=biz_object.sprite_index;object->sprite_offset[0]=frame.offset_x;
    object->sprite_offset[1]=frame.offset_y;
    object->sprite_width=(uint16_t)((uint16_t)sprite.width_units*4u);
    object->sprite_height=(uint16_t)sprite.height;
    return 1;
}

void ll_level_script_close(LL_LevelScript *script)
{
    if (!script) return;
    ll_sool_program_close(&script->program);
    ll_bib_close(&script->bib);
    ll_biz_close(&script->biz);
    free(script->contexts);free(script->condition_vm);
    free(script->code_data);free(script->bib_data);free(script->biz_data);
    free(script->model_poses);
    free(script->model_bounds);
    memset(script,0,sizeof(*script));
}

int ll_level_script_open(LL_LevelScript *script,
                          const unsigned char *code, size_t code_size,
                          const unsigned char *bib, size_t bib_size, FILE *trace)
{
    if (!script) return 0;
    memset(script,0,sizeof(*script));
    script->trace=trace;
    if (!code || !code_size || code_size>64u*1024u*1024u)
        return fail(script,"Abilene SOOL input is missing or too large");
    script->code_data=malloc(code_size);
    if (!script->code_data) return fail(script,"cannot allocate Abilene SOOL input");
    memcpy(script->code_data,code,code_size);
    if (!ll_sool_program_open(&script->program,script->code_data,code_size))
        return fail(script,ll_sool_program_error(&script->program));
    if (script->program.function_count>256)
        return fail(script,"level runtime supports at most256 SOOL function banks");
    if (bib) {
        if (!bib_size || bib_size>64u*1024u*1024u) return fail(script,"Abilene BIB input size is invalid (limit64 MiB)");
        script->bib_data=malloc(bib_size);
        if (!script->bib_data) return fail(script,"cannot allocate Abilene BIB input");
        memcpy(script->bib_data,bib,bib_size);
        if (!ll_bib_open(&script->bib,script->bib_data,bib_size))
            return fail(script,ll_bib_error(&script->bib));
        script->model_poses=calloc(script->bib.model_count,sizeof(*script->model_poses));
        script->model_bounds=calloc(script->bib.model_count,sizeof(*script->model_bounds));
        if (script->bib.model_count && (!script->model_poses || !script->model_bounds))
            return fail(script,"cannot allocate mutable scene-root poses");
        for (unsigned i=0;i<script->bib.model_count;i++) {
            memcpy(script->model_poses[i].position,script->bib.models[i].anchor,
                sizeof(script->model_poses[i].position));
            memcpy(script->model_bounds[i],script->bib.models[i].bounds_min,3*sizeof(int32_t));
            memcpy(script->model_bounds[i]+3,script->bib.models[i].bounds_max,3*sizeof(int32_t));
        }
    }
    script->contexts=calloc(script->program.function_count,sizeof(*script->contexts));
    script->condition_vm=calloc(1,sizeof(*script->condition_vm));
    if (!script->contexts || !script->condition_vm)
        return fail(script,"cannot allocate persistent Abilene SOOL contexts");
    for (unsigned i=0;i<script->program.function_count;i++) {
        const LL_SoolFunction *fn=&script->program.functions[i];
        LL_LevelScriptContext *context=&script->contexts[i];
        context->state=fn->initial_state;
        context->instance=UINT16_MAX;
        if (fn->initial_state==UINT16_MAX) {
            context->body_done=1;context->vm.state_flags|=2u;
        }
        /* Local words use byte offsets and alias the function's header/data. */
        for (unsigned local=0;local<256 && local+1u<fn->code_start;local++) {
            const unsigned char *p=script->program.data+fn->offset+local;
            context->vm.locals[local]=(uint16_t)(p[0]|((uint16_t)p[1]<<8));
        }
    }
    script->loaded=1;
    return 1;
}

int ll_level_script_set_biz(LL_LevelScript *script,
                            const unsigned char *biz, size_t biz_size)
{
    if (!script || !script->loaded || !biz || !biz_size ||
        biz_size>64u*1024u*1024u || script->updates)
        return script ? fail(script,"BIZ must be attached before bounded SOOL updates") : 0;
    unsigned char *owned=malloc(biz_size);
    if (!owned) return fail(script,"cannot allocate Abilene BIZ input");
    memcpy(owned,biz,biz_size);
    LL_BizFile parsed={0};
    if (!ll_biz_open(&parsed,owned,biz_size)) {
        snprintf(script->error,sizeof(script->error),"%s",ll_biz_error(&parsed));
        ll_biz_close(&parsed);free(owned);return 0;
    }
    ll_biz_close(&script->biz);free(script->biz_data);
    script->biz=parsed;script->biz_data=owned;
    return 1;
}

static int command(LL_LevelScript *script, uint16_t id, const uint16_t *args, size_t argc)
{
    LL_LevelNativeSetup *state=&script->native;
    uint16_t current=script->contexts[script->dispatch_context].instance;
    LL_LevelScriptObject *object=current<260 && script->objects[current].present ? &script->objects[current] : NULL;
#define ARITY(n) do { if (argc!=(n)) return fail(script,"wrong native command arity"); } while (0)
    switch (id) {
    case 0x16: case 0x11: case 0x17: {
        ARITY(2);
        if (!object || !object->bounds) return fail(script,"bounds setter requires a scene object");
        unsigned axis=id==0x16 ? 0u : id==0x11 ? 1u : 2u;
        object->bounds[axis]=(int16_t)args[0];object->bounds[axis+3]=(int16_t)args[1];
        return 1;
    }
    case 0x1a: case 0x1c:
        ARITY(3);
        if (!object || !object->pose) return fail(script,"root setter requires a scene object");
        for (unsigned i=0;i<3;i++) {
            if (id==0x1a) object->pose->angles[i]=(int16_t)args[i];
            else object->pose->position[i]=(int16_t)args[i]*100;
        }
        return 1;
    case 0x18:
        ARITY(4);
        if (!object) return fail(script,"motion setter requires a scene object");
        for (unsigned i=0;i<3;i++) object->motion[i]=(int16_t)args[i];
        object->motion_word=args[3];return 1;
    case 0x2d:
        ARITY(2);
        if (!object) return fail(script,"wrapper flags setter requires a scene object");
        object->wrapper_flags=(uint16_t)((object->wrapper_flags&~4u)|(args[0]?4u:0u));return 1;
    case 0x10:
        ARITY(2);
        if (args[0]<260 && script->objects[args[0]].present)
            script->objects[args[0]].visible=args[1]!=0;
        return 1; /* FUN_004101e0 explicitly ignores absent targets. */
    case 0x32: /* FUN_00411800: register the scene-sprite callback manager. */
        ARITY(0);
        state->scene_sprite_capacity=16;
        memset(state->scene_sprite_slots,0,sizeof(state->scene_sprite_slots));
        state->scene_sprite_manager_registered=1;
        return 1;
    case 0xf5: { /* FUN_004165e0: register a bounded collision callback link. */
        ARITY(2);
        if (args[0]>=script->program.function_count ||
            script->contexts[args[0]].instance>=260 ||
            !script->objects[script->contexts[args[0]].instance].present)
            return fail(script,"collision link target is not a registered wrapper context");
        LL_LevelScriptContext *owner=&script->contexts[script->dispatch_context];
        uint16_t flags=(uint16_t)args[1];
        uint8_t mode=(uint8_t)(flags&7u);
        unsigned slot=3;
        for (unsigned i=0;i<3;i++) {
            if (owner->collision_links[i].active &&
                owner->collision_links[i].target_context==args[0]) { slot=i;break; }
            if (!owner->collision_links[i].active && slot==3) slot=i;
        }
        if (slot==3) return fail(script,"collision callback context has no free link slot");
        LL_LevelCollisionLink *link=&owner->collision_links[slot];
        if (mode==7) {
            if (link->active && (link->flags&0xc0u))
                return fail(script,"collision detach requires unported target flag callbacks");
            memset(link,0,sizeof(*link));
            return 1;
        }
        link->active=1;link->target_context=args[0];
        link->flags=(uint16_t)(flags&0x138u);
        link->callback_mode=(uint8_t)(mode<=3?mode:0xffu);
        return 1;
    }
    case 0x72: { /* FUN_00418620: toggle a registered wrapper callback. */
        ARITY(2);
        if (args[0]>=260 || !script->objects[args[0]].present)
            return fail(script,"callback toggle requires a registered wrapper");
        LL_LevelScriptObject *target=&script->objects[args[0]];
        int enabled=args[1]!=0;
        /* Constructors set the native callback-active byte to1. The observed
         * Abilene calls only request this already-active state; transitions
         * also reset/register native engine callbacks and are not yet ported. */
        if (target->native_callback_enabled!=(uint8_t)enabled)
            return fail(script,"callback state transition requires native wrapper dispatch");
        return 1;
    }
    case 0x11e: { /* FUN_004156c0: select a BIB pose as the camera target. */
        ARITY(2);
        LL_BibScenePose target;
        if (!ll_bib_get_scene_pose(&script->bib,args[0],args[1],&target))
            return 1; /* Native lookup failure leaves the previous target intact. */
        memcpy(state->camera_target,target.position,sizeof(state->camera_target));
        state->camera_target_active=1;
        return 1;
    }
    case 0x5b: /* FUN_00414240 */
        ARITY(1);
        if (!args[0]) state->native_flags|=1u;
        else state->native_flags=0;
        return 1;
    case 0x45: { /* FUN_004118b0: bind a wrapper slot and set its +0x14 word. */
        ARITY(3);
        if (args[0]>=260 || args[1]>=256 || !script->objects[args[0]].present)
            return fail(script,"wrapper registration needs a live instance and slot0..255");
        state->object_registry[args[1]]=(uint16_t)(args[0]+1u);
        script->objects[args[0]].native_wrapper_word=args[2];
        script->objects[args[0]].visible=args[2]!=0;
        return 1;
    }
    case 0x2a: /* FUN_0040b400 / DAT_004e8580 */
        ARITY(1);state->level_event_latch=(uint8_t)args[0];return 1;
    case 0x0b: case 0x14: case 0x1b: { /* Native skeletal animation scheduler. */
        ARITY(id==0x14?3:1);
        if (!object || !object->pose || object->kind==5 || object->kind==7)
            return fail(script,"skeletal animation requires a registered model instance");
        uint16_t selector=args[0];
        const LL_BibAnimationTable *table=ll_bib_get_animation_table(&script->bib,selector);
        if (!table || !table->record_count || !table->record_type)
            return fail(script,"animation selector has no bounded frame table");
        if (table->loop_displacement[0] || table->loop_displacement[1] || table->loop_displacement[2])
            return fail(script,"animation loop root displacement is not implemented");
        uint16_t first=0,last=(uint16_t)(table->record_count-1u);
        if (id==0x14) {
            first=args[1];last=args[2];
            if (last==UINT16_MAX) last=(uint16_t)(table->record_count-1u);
            if (first>last || last>=table->record_count)
                return fail(script,"animation range is outside the bounded frame table");
        }
        if (id!=0x1b || object->animation_selector!=selector) {
            object->animation_started=animation_clock(script->updates);
            object->animation_frame=UINT16_MAX;
        }
        object->animation_selector=selector;object->animation_first=first;
        object->animation_last=last;object->animation_active=1;
        object->animation_once=(uint8_t)(id!=0x1b);
        LL_LevelScriptContext *owner=&script->contexts[script->dispatch_context];
        if (id!=0x1b) {
            object->animation_callback_owner=(uint16_t)(script->dispatch_context+1u);
            owner->vm.host_animation_wait=1;owner->vm.host_yield=1;
        } else owner->vm.host_animation_wait=0;
        return 1;
    }
    case 0x6b: { /* FUN_0041b740: restart the full BIB sequence on a sprite. */
        ARITY(3);
        if (!object || (object->kind!=5 && object->kind!=7))
            return fail(script,"BIB sequence command requires a world or screen sprite");
        LL_BibSelector section;
        uint16_t previous_selector=object->sprite_selector;
        object->sprite_selector=args[0];
        if (!ll_bib_get_selector(&script->bib,args[0],&section) || !section.is_section ||
            section.size<12u || !sprite_frame_apply(script,object,(uint16_t)0)) {
            object->sprite_selector=previous_selector;
            return fail(script,"BIB sprite sequence lacks a bounded frame header or BIZ record");
        }
        const unsigned char *header=script->bib.raw_data+section.offset;
        uint16_t frame_count=(uint16_t)(header[2]|((uint16_t)header[3]<<8));
        if (!frame_count || frame_count>(section.size-12u)/12u) {
            object->sprite_selector=previous_selector;
            return fail(script,"BIB sprite sequence frame count exceeds its section");
        }
        object->sprite_animation_first=0;
        object->sprite_animation_last=(uint16_t)(frame_count-1u);
        object->sprite_animation_started_ms=(uint32_t)((uint64_t)script->updates*1000u/24u);
        object->sprite_animation_active=1;object->sprite_scale=(int16_t)args[2];
        return 1;
    }
    case 0x66: { /* FUN_00418920: register the bounded player model/root record. */
        ARITY(4);
        if (args[3]!=0)
            return fail(script,"only Abilene's original player variant0 is ported");
        uint16_t instance=args[1];uint32_t offset;
        if (!script->bib.valid || instance>=260 || script->objects[instance].present ||
            !ll_bib_get_selector_offset(&script->bib,args[0],&offset))
            return fail(script,"player constructor needs a free instance and valid BIB model selector");
        unsigned model=0;
        while (model<script->bib.model_count && script->bib.models[model].descriptor_offset!=offset) model++;
        if (model==script->bib.model_count)
            return fail(script,"player selector does not name a bounded model descriptor");
        LL_LevelScriptObject *player=&script->objects[instance];
        player->present=1;player->cloned=1;player->model_index=model;
        player->kind=script->bib.models[model].type;player->player_control_index=args[2];
        player->private_pose=script->model_poses[model];player->pose=&player->private_pose;
        memcpy(player->private_bounds,script->model_bounds[model],sizeof(player->private_bounds));
        player->bounds=player->private_bounds;player->wrapper_flags=3;
        player->visible=1;player->update_enabled=1;player->native_callback_enabled=1;
        script->contexts[script->dispatch_context].instance=instance;
        script->object_count++;return 1;
    }
    case 0x6e: case 0x71: { /* FUN_00418350 / screen-sprite sibling constructor. */
        ARITY(3);
        uint16_t instance=args[0],selector=args[1];
        if (!script->bib.valid || !script->biz.valid || instance>=260 ||
            script->objects[instance].present)
            return fail(script,"sprite constructor needs BIB/BIZ resources and a free instance");
        LL_BibSpriteFrame frame;
        LL_BizObject object_record;
        LL_BizSprite sprite_record;
        if (!ll_bib_get_sprite_frame(&script->bib,selector,0,&frame) ||
            !ll_biz_get_object(&script->biz,frame.object_index,&object_record) ||
            !ll_biz_get_sprite(&script->biz,object_record.sprite_index,&sprite_record))
            return fail(script,"sprite selector references an invalid BIB/BIZ frame or object");
        LL_LevelScriptObject *created=&script->objects[instance];
        created->present=1;created->kind=id==0x6e?5:7;created->visible=(uint8_t)(id==0x71);
        created->update_enabled=(uint8_t)(id==0x6e);created->wrapper_flags=1;
        created->native_callback_enabled=1;
        created->pose=&created->private_pose;
        created->sprite_selector=selector;created->biz_object=frame.object_index;
        created->biz_sprite=object_record.sprite_index;created->sprite_scale=(int16_t)args[2];
        created->sprite_frame=0;created->sprite_offset[0]=frame.offset_x;
        created->sprite_offset[1]=frame.offset_y;
        created->sprite_width=(uint16_t)((uint16_t)sprite_record.width_units*4u);
        created->sprite_height=(uint16_t)sprite_record.height;
        script->contexts[script->dispatch_context].instance=instance;
        script->object_count++;return 1;
    }
    case 0x6f: { /* FUN_00418580 -> FUN_00479de0: wake an ordinary model wrapper. */
        ARITY(2);
        if (args[0]>=260 || !script->objects[args[0]].present) return 1;
        LL_LevelScriptObject *target=&script->objects[args[0]];
        target->callback_kind=(uint8_t)args[1];
        if ((target->wrapper_flags&1u) && target->kind!=5 && target->kind!=7) {
            if (target->reduced)
                return fail(script,"reduced model wake requires native descriptor expansion");
            target->update_enabled=1;
        }
        return 1;
    }
    case 0x0a: /* FUN_00418e00/00418da0/00483cf0: resolve frame offsets once.
                * The bounded BIB reader already retains resolved record spans. */
        ARITY(1);
        if (args[0]>=LL_BIB_MAX_SELECTORS || !ll_bib_get_animation_table(&script->bib,args[0]))
            return fail(script,"animation preload selector has no bounded frame directory");
        script->animation_preloaded[args[0]]=1;
        return 1;
    case 0x64: /* FUN_0041a680: retain validated catalogue/grid as scene data.
                * Rendering, relocation into world cells and collisions remain separate. */
        ARITY(2);
        if (!script->bib.valid || args[0]!=script->bib.grid_selector)
            return fail(script,"static scene selector does not match BIB grid");
        script->grid_loaded=1;script->static_model_count=0;
        for (unsigned i=0;i<script->bib.model_count;i++)
            script->static_model_count+=script->bib.models[i].type==0;
        return 1;
    case 0x65: case 0x68: { /* FUN_00418030/00418160: shared vs copied root. */
        ARITY(2);uint32_t offset;
        if (!script->grid_loaded || args[1]>=260 ||
            !ll_bib_get_selector_offset(&script->bib,args[0],&offset))
            return fail(script,"model constructor needs a loaded grid and valid selector/instance");
        unsigned model=0;
        while (model<script->bib.model_count && script->bib.models[model].descriptor_offset!=offset) model++;
        if (model==script->bib.model_count || script->objects[args[1]].present)
            return fail(script,"model descriptor missing or instance already registered");
        object=&script->objects[args[1]];
        object->present=1;object->cloned=id==0x68;object->model_index=model;
        object->kind=script->bib.models[model].type;
        object->private_pose=script->model_poses[model];
        object->pose=object->cloned ? &object->private_pose : &script->model_poses[model];
        memcpy(object->private_bounds,script->model_bounds[model],sizeof(object->private_bounds));
        object->bounds=object->cloned ? object->private_bounds : script->model_bounds[model];
        object->wrapper_flags=1;object->visible=1;object->update_enabled=1;
        object->native_callback_enabled=1;
        script->contexts[script->dispatch_context].instance=args[1];
        script->object_count++;return 1;
    }
    case 0x2e: { /* FUN_00411400 ->00473140 ->00411c90/00411680. */
        ARITY(2);int found=0;
        for (unsigned i=0;i<state->pose_count;i++) if (state->pose_groups[i]==args[0]) found=1;
        uint16_t instance=script->contexts[script->dispatch_context].instance;
        LL_BibScenePose pose;
        if (!found || instance>=260 || !script->objects[instance].present ||
            !ll_bib_get_scene_pose(&script->bib,args[0],args[1],&pose))
            return fail(script,"model pose requires registered group, instance and bounded pose index");
        *script->objects[instance].pose=pose;return 1;
    }
    case 0xb9: /* FUN_00416120/00416040: scheduler/cleanup and camera defaults. */
        ARITY(0);
        memset(state,0,sizeof(*state));
        state->initialized=1;state->callback_capacity=250;
        state->world_cell=0x137;state->depth=6000;
        state->camera_speed=512;state->camera_word=80;
        state->camera_limit=100;
        return 1;
    case 0x36: /* FUN_00411d90: arg4 is consumed but not read. */
        ARITY(3);
        if (!args[1]) return fail(script,"SOOL projection is zero (native division by zero)");
        state->projection_mode=(uint8_t)args[0];
        state->projection=(uint32_t)(int32_t)(int16_t)args[1]&0xffffffu;
        state->reciprocal_projection=0x100000u/state->projection;
        return 1;
    case 0x70: /* FUN_004188d0, spatial cell selector. */
        ARITY(1);state->world_cell=(int16_t)args[0];return 1;
    case 0xe6: /* FUN_00416190: empty path registries, capacities10/10. */
        ARITY(0);state->path_capacity=10;return 1;
    case 0xf0: /* FUN_00416550: empty ten-entry pose-group registry. */
        ARITY(0);state->pose_capacity=10;state->pose_count=0;return 1;
    case 0xf1: { /* FUN_00416590/004730a0: bounded BIB pose registration. */
        ARITY(1);LL_BibSelector selector;
        if (!state->pose_capacity || state->pose_count>=state->pose_capacity ||
            !ll_bib_get_selector(&script->bib,args[0],&selector) || !selector.is_section)
            return fail(script,"pose registry is full/uninitialized or BIB selector is invalid");
        state->pose_groups[state->pose_count++]=args[0];return 1;
    }
    case 0x132: /* FUN_0041c230: configure callback, not camera movement. */
        ARITY(2);
        if (state->camera_lock==1 && args[0]!=10) return 1;
        if (args[0]==10) { state->camera_lock=(uint8_t)args[1];return 1; }
        if (args[0]<=5 || args[0]==6 || args[0]==9) state->camera_mode=(int16_t)args[0];
        if (args[0]<=5) {
            int speed=(int16_t)args[1];
            state->camera_speed=(int16_t)(speed<128?128:speed>1023?1023:speed);
        } else if (args[0]==9) state->camera_speed=(int16_t)args[1];
        return 1;
    case 0x13c: /* FUN_0041cbe0 */
        ARITY(4);
        if (state->camera_lock!=1)
            for (unsigned i=0;i<4;i++) state->camera_bounds[i]=(int16_t)args[i]*100;
        return 1;
    case 0x138: /* FUN_0041ca10 */
        ARITY(1);if (state->camera_lock!=1) state->camera_word=args[0];return 1;
    case 0x13e: { /* FUN_0041cd50 sign extends, then clamps UNSIGNED. */
        ARITY(1);uint32_t limit=(uint32_t)(int32_t)(int16_t)args[0];
        if (state->camera_lock!=1) state->camera_limit=(uint16_t)(limit>200?200:limit<10?10:limit);
        return 1;
    }
    case 0xa1: ARITY(1);state->object_mode=(uint8_t)args[0];return 1; /* FUN_004186f0 */
    case 0x58: ARITY(1);state->player_word=args[0];return 1; /* FUN_004141c0 */
    default:
        return fail(script,"native handler not ported");
    }
#undef ARITY
}

static int object_aabb(LL_LevelScript *script, const LL_LevelScriptObject *object,
                      uint16_t mode, int32_t bounds[6])
{
    if (!object || !object->present || !object->pose) return 0;
    if (mode==0) {
        if (!object->bounds) return 0;
        for (unsigned i=0;i<6;i++)
            bounds[i]=(int32_t)((uint32_t)object->bounds[i]+
                                (uint32_t)object->pose->position[i%3]);
        return 1;
    }
    if (mode!=1 || object->kind==5 || object->kind==7 ||
        object->model_index>=script->bib.model_count) return 0;
    const LL_Bib3dxModel *model=ll_bib_get_model(&script->bib,object->model_index);
    if (!model || model->geometry_model_index>=script->bib.model_count) return 0;
    const LL_Bib3dxModel *geometry=ll_bib_get_model(&script->bib,model->geometry_model_index);
    if (!geometry || !geometry->vertices || geometry->vertex_count<=4) return 0;
    for (unsigned axis=0;axis<3;axis++) {
        bounds[axis]=INT32_MAX;bounds[axis+3]=INT32_MIN;
    }
    /* FUN_0047fbe0 scans source vertices [2, count-2), then FUN_0040d950
     * translates the resulting local AABB by the wrapper root. */
    for (uint32_t i=2;i<geometry->vertex_count-2;i++)
        for (unsigned axis=0;axis<3;axis++) {
            int32_t value=geometry->vertices[i].position[axis];
            if (value<bounds[axis]) bounds[axis]=value;
            if (value>bounds[axis+3]) bounds[axis+3]=value;
        }
    for (unsigned axis=0;axis<3;axis++) {
        bounds[axis]=(int32_t)((uint32_t)bounds[axis]+(uint32_t)object->pose->position[axis]);
        bounds[axis+3]=(int32_t)((uint32_t)bounds[axis+3]+(uint32_t)object->pose->position[axis]);
    }
    return 1;
}

static int native_variable(LL_LevelScript *script, uint16_t id,
                           const uint16_t *args, size_t argc, uint16_t *result)
{
    LL_LevelNativeSetup *state=&script->native;
    switch (id) {
    case 0x0b: /* FUN_00408c70: RNG word modulo signed SOOL bound. */
        if (argc!=1) return fail(script,"wrong native variable arity");
        if (!ll_native_rng_bounded((int16_t)args[0],result))
            return fail(script,"native random variable divides by a zero bound");
        return 1;
    case 0x38: /* FUN_0040bdc0 */
        if (argc) return fail(script,"wrong native variable arity");
        *result=(uint16_t)((state->native_flags&1u)!=0);
        if (*result) state->native_flags|=4u;
        return 1;
    case 0x44: /* FUN_0040c360 */
        if (argc) return fail(script,"wrong native variable arity");
        *result=state->native_word_44?state->native_word_44:3;
        return 1;
    case 0x64: { /* FUN_0040ddb0 -> FUN_0040da10/FUN_0040d810: AABB overlap. */
        if (argc!=4 || args[0]>=script->program.function_count ||
            args[2]>=script->program.function_count)
            return fail(script,"AABB overlap requires two registered wrapper contexts and modes");
        uint16_t first=script->contexts[args[0]].instance;
        uint16_t second=script->contexts[args[2]].instance;
        if (first>=260 || second>=260) return fail(script,"AABB overlap wrapper has no live instance");
        int32_t a[6],b[6];
        if (!object_aabb(script,&script->objects[first],args[1],a) ||
            !object_aabb(script,&script->objects[second],args[3],b))
            return fail(script,"AABB overlap mode requires bounded model geometry or descriptor bounds");
        *result=1;
        for (unsigned axis=0;axis<3;axis++)
            if (a[axis+3]<b[axis] || b[axis+3]<a[axis]) { *result=0;break; }
        return 1;
    }
    case 0x2a: /* FUN_0040b3d0 */
        if (argc) return fail(script,"wrong native variable arity");
        *result=state->level_event_latch;return 1;
    case 0x26: { /* FUN_0040aca0: inclusive AABB test against a BIB pose box. */
        if (argc!=3 || args[0]>=260 || !script->objects[args[0]].present)
            return fail(script,"collision query requires a registered object and pose index");
        LL_LevelScriptObject *object=&script->objects[args[0]];
        if (!object->bounds || !object->pose)
            return fail(script,"collision query target has no model bounds/root pose");
        LL_BibScenePose box;
        if (!ll_bib_get_scene_pose(&script->bib,args[1],args[2],&box)) {
            *result=0;return 1; /* Native null pose result is explicitly false. */
        }
        for (unsigned axis=0;axis<3;axis++) {
            int32_t object_min=(int32_t)((uint32_t)object->bounds[axis]+
                                         (uint32_t)object->pose->position[axis]);
            int32_t object_max=(int32_t)((uint32_t)object->bounds[axis+3]+
                                         (uint32_t)object->pose->position[axis]);
            int32_t query_min=axis==0?box.position[0]:axis==1?box.position[1]:box.position[2];
            int32_t query_max=axis==0?box.angles[0]:axis==1?box.angles[1]:box.angles[2];
            if (object_max<query_min || query_max<object_min) { *result=0;return 1; }
        }
        *result=1;return 1;
    }
    default:
        (void)args;
        return fail(script,"native variable not ported");
    }
}

static int dispatch(uint8_t opcode, uint16_t *stack, size_t *size,
                     size_t capacity, void *userdata)
{
    LL_LevelScript *script=userdata;
    LL_SoolVM *vm=script->in_conditions ? script->condition_vm :
        &script->contexts[script->dispatch_context].vm;
    int variable=opcode>=0x50;
    size_t count=opcode-(variable ? 0x4fu : 0x3bu);
    if (!count || count>*size) return fail(script,"native call stack underflow");
    uint16_t id=stack[*size-1u], args[14];
    for (size_t i=0;i+1<count;i++) args[i]=stack[*size-2u-i];
    script->calls++;
    /* Every executed call records its real stack arguments, not guessed IDs
     * from linear disassembly. Unsupported calls leave the stack untouched. */
    uint16_t result=0;
    int ok=variable ? native_variable(script,id,args,count-1,&result) : command(script,id,args,count-1);
    if (script->trace || !ok) {
        FILE *out=script->trace ? script->trace : stderr;
        fprintf(out,"%s: ABILENE tick=%u context=%u function=%u state=%u %s pc=+0x%x opcode=0x%02x %s=0x%x args=[",
            ok?"TRACE":"BLOCKED",script->updates,script->dispatch_context,vm->last_function,
            script->contexts[script->dispatch_context].state,
            script->in_conditions?"conditions":"body",vm->last_instruction_offset,opcode,
            variable?"variable":"command",id);
        for (size_t i=0;i+1<count;i++) fprintf(out,"%s%d",i?",":"",(int16_t)args[i]);
        fprintf(out,"] %s%s\n",ok?"supported":"",ok?"":script->error);
    }
    if (!ok) return 0;
    script->supported_calls++;
    *size-=count;
    if (variable) {
        if (*size>=capacity) return fail(script,"native variable result exceeds SOOL stack capacity");
        stack[(*size)++]=result;
    }
    (void)capacity;
    return 1;
}

static void shared_in(LL_LevelScript *script, LL_SoolVM *vm)
{
    for (unsigned i=0;i<script->program.function_count;i++) {
        memcpy(vm->members[i],script->contexts[i].vm.locals,sizeof(vm->locals));
        vm->member_states[i]=script->contexts[i].state;
        vm->member_disabled[i]=(uint8_t)(script->contexts[i].vm.state_flags&1u);
    }
    memset(vm->member_state_requested,0,sizeof(vm->member_state_requested));
    memset(vm->member_disable_requested,0,sizeof(vm->member_disable_requested));
    vm->has_pending_transition=0;
}

static void set_state(LL_LevelScriptContext *context, uint16_t state)
{
    context->state=state;context->body_done=0;
    context->vm.suspended=0;context->vm.return_depth=0;
    context->vm.stack_size=0;
    context->vm.host_animation_wait=0;context->vm.host_yield=0;
    context->vm.state_flags&=(uint16_t)~2u;
    if (state==UINT16_MAX) { context->body_done=1;context->vm.state_flags|=2u; }
}

static void shared_out(LL_LevelScript *script, LL_SoolVM *vm, unsigned owner)
{
    for (unsigned i=0;i<script->program.function_count;i++) {
        LL_LevelScriptContext *context=&script->contexts[i];
        if (i!=owner) memcpy(context->vm.locals,vm->members[i],sizeof(vm->locals));
        if (vm->member_disable_requested[i])
            context->vm.state_flags=(uint16_t)((context->vm.state_flags&~1u)|vm->member_disabled[i]);
        if (vm->member_state_requested[i]) {
            context->requested_state=vm->member_states[i];context->state_requested=1;
        }
    }
}

static void blocked(LL_LevelScript *script, unsigned index, LL_SoolVM *vm)
{
    LL_LevelScriptContext *context=&script->contexts[index];
    context->blocked=1;script->blocked_count++;
    snprintf(context->error,sizeof(context->error),"function%u state%u +0x%x opcode0x%02x: %.160s",
        vm->last_function,context->state,vm->last_instruction_offset,vm->last_opcode,
        script->error[0]?script->error:"unsupported/malformed VM instruction");
    if (!script->error[0]) fprintf(script->trace?script->trace:stderr,
        "BLOCKED: ABILENE context%u %s\n",index,context->error);
}

void ll_level_script_update(LL_LevelScript *script)
{
    if (!script || !script->loaded) return;
    script->updates++;
    uint32_t clock=animation_clock(script->updates);
    uint32_t elapsed_ms=(uint32_t)((uint64_t)script->updates*1000u/24u);
    for (unsigned i=0;i<260;i++) {
        LL_LevelScriptObject *object=&script->objects[i];
        if (!object->present || !object->sprite_animation_active) continue;
        uint64_t total=0;
        for (unsigned f=object->sprite_animation_first;f<=object->sprite_animation_last;f++) {
            LL_BibSpriteFrame record;
            if (!ll_bib_get_sprite_frame(&script->bib,object->sprite_selector,f,&record)) { total=0;break; }
            total+=record.duration;
        }
        if (!total) { object->sprite_animation_active=0;continue; }
        uint64_t elapsed=(uint32_t)(elapsed_ms-object->sprite_animation_started_ms)%total;
        unsigned frame=object->sprite_animation_first;
        for (;frame<=object->sprite_animation_last;frame++) {
            LL_BibSpriteFrame record;
            if (!ll_bib_get_sprite_frame(&script->bib,object->sprite_selector,frame,&record)) break;
            if (elapsed<record.duration) break;
            elapsed-=record.duration;
        }
        if (frame>object->sprite_animation_last) frame=object->sprite_animation_first;
        if (frame!=object->sprite_frame && !sprite_frame_apply(script,object,(uint16_t)frame))
            object->sprite_animation_active=0;
    }
    for (unsigned i=0;i<260;i++) {
        LL_LevelScriptObject *object=&script->objects[i];
        if (!object->present || !object->animation_active) continue;
        const LL_BibAnimationTable *table=ll_bib_get_animation_table(&script->bib,object->animation_selector);
        if (!table || object->animation_last>=table->record_count) continue;
        uint64_t total=0,elapsed=(uint32_t)(clock-object->animation_started);
        for (unsigned frame=object->animation_first;frame<=object->animation_last;frame++)
            total+=(uint64_t)table->records[frame].sample_count*32u;
        if (!total) continue;
        if (object->animation_once) { if (elapsed>=total) elapsed=total-1u; }
        else elapsed%=total;
        unsigned frame=object->animation_first;
        while (frame<object->animation_last) {
            uint64_t duration=(uint64_t)table->records[frame].sample_count*32u;
            if (elapsed<duration) break;
            elapsed-=duration;frame++;
        }
        object->animation_frame=(uint16_t)frame;
        uint16_t owner=object->animation_callback_owner;
        if (owner && owner<=script->program.function_count && object->animation_once) {
            uint64_t completion=0;
            unsigned end=object->animation_last>object->animation_first ? object->animation_last-1u : object->animation_last;
            for (unsigned f=object->animation_first;f<=end;f++)
                completion+=(uint64_t)table->records[f].sample_count*32u;
            if ((uint32_t)(clock-object->animation_started)>=completion) {
                script->contexts[owner-1u].vm.host_animation_wait=0;
                object->animation_callback_owner=0;
                if (object->animation_selector==table->selector && object->animation_last+1u<table->record_count)
                    object->animation_last=(uint16_t)(table->record_count-1u);
            }
        }
    }
    /* FUN_004219b0: pending states are applied at the next engine iteration,
     * then bodies, then separate conditions. No unbounded startup chaining. */
    for (unsigned i=0;i<script->program.function_count;i++) {
        LL_SoolVM *vm=&script->contexts[i].vm;
        if (vm->has_pending_transition) {
            uint16_t target=vm->pending_function,state=vm->pending_state;
            vm->has_pending_transition=0;
            if (target<script->program.function_count &&
                (state==UINT16_MAX || state<script->program.functions[target].state_count)) {
                script->contexts[target].requested_state=state;
                script->contexts[target].state_requested=1;
            }
            else { script->error[0]=0;blocked(script,i,vm); }
        }
    }
    for (unsigned i=0;i<script->program.function_count;i++)
        if (script->contexts[i].state_requested) {
            set_state(&script->contexts[i],script->contexts[i].requested_state);
            script->contexts[i].state_requested=0;
        }
    for (unsigned phase=0;phase<2;phase++)
        for (unsigned i=0;i<script->program.function_count;i++) {
            LL_LevelScriptContext *context=&script->contexts[i];
            const LL_SoolFunction *fn=&script->program.functions[i];
            if (context->blocked || (context->vm.state_flags&1u)) continue;
            if (!phase && context->vm.host_animation_wait) continue;
            if ((!phase && context->body_done) || (phase && fn->conditions_start==UINT16_MAX)) continue;
            script->in_conditions=(int)phase;script->dispatch_context=(uint16_t)i;
            LL_SoolVM *vm=&context->vm;
            if (phase) {
                memcpy(script->condition_vm,vm,sizeof(*vm));vm=script->condition_vm;
                vm->stack_size=0;vm->suspended=0;vm->return_depth=0;
            }
            shared_in(script,vm);vm->current_state=(int16_t)context->state;
            script->error[0]=0;
            int ok=phase ? ll_sool_execute_conditions(&script->program,(uint16_t)i,vm,dispatch,script) :
                ll_sool_execute_state(&script->program,(uint16_t)i,context->state,vm,dispatch,script);
            if (phase) {
                memcpy(context->vm.locals,vm->locals,sizeof(vm->locals));
                if (vm->has_pending_transition) {
                    context->vm.has_pending_transition=1;
                    context->vm.pending_function=vm->pending_function;
                    context->vm.pending_state=vm->pending_state;
                }
            }
            shared_out(script,vm,i);
            if (!ok) { blocked(script,i,vm);continue; }
            if (!phase) {
                context->body_done=!vm->suspended;
                if (context->body_done) context->vm.state_flags|=2u;
            }
        }
}

void ll_level_script_report(const LL_LevelScript *script, FILE *out)
{
    if (!script || !out) return;
    fprintf(out,"ABILENE SOOL: loaded=%d functions=%u updates=%u calls=%u supported=%u blocked=%u objects=%u static_models=%u\n",
        script->loaded,script->program.function_count,script->updates,script->calls,
        script->supported_calls,script->blocked_count,script->object_count,script->static_model_count);
    for (unsigned i=0;script->contexts && i<script->program.function_count;i++)
        if (script->contexts[i].blocked) fprintf(out,"  context%u %s\n",i,script->contexts[i].error);
}
