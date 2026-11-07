#include "level_script.h"
#include "native_rng.h"
#include "native_camera.h"
#include "native_animation.h"
#include <stdlib.h>
#include <string.h>

static int fail(LL_LevelScript *script, const char *message)
{
    snprintf(script->error,sizeof(script->error),"%s",message);
    return 0;
}

static void object_visibility_set(LL_LevelScriptObject *object, int visible)
{
    object->visible=(uint8_t)(visible!=0);
    object->native_wrapper_word=(uint16_t)((object->native_wrapper_word&0xff00u)|object->visible);
}

static uint32_t animation_clock(uint32_t update)
{
    return (uint32_t)(((uint64_t)update*60u/24u)*31u);
}

int ll_level_path_next_segment(const LL_BibFile *bib, uint32_t selector,
                               unsigned current, const int32_t position[3],
                               uint16_t heading, unsigned *next)
{
    LL_BibPathSegment segment;
    int32_t projected[3],along;
    if (!next || !ll_bib_get_path_segment(bib,selector,current,&segment) ||
        !ll_bib_project_path_segment(&segment,position,projected,&along)) return -1;
    int32_t length;memcpy(&length,&segment.length,sizeof(length));
    if (along>=0 && along<=length) { *next=current;return 1; }
    int before=along<0;
    uint32_t endpoint=before?segment.start_reference:segment.end_reference;
    const int32_t *origin=before?segment.start:segment.end;
    unsigned selected=current,fallback=current;
    int found=0,has_fallback=0,best=4096;
    for (unsigned link=0;link<segment.link_count;link++) {
        unsigned index;LL_BibPathSegment candidate;
        if (!ll_bib_get_path_link(bib,selector,current,link,&index) ||
            !ll_bib_get_path_segment(bib,selector,index,&candidate)) return -1;
        if ((segment.flags&255u)==1 && (candidate.flags&255u)==1) {
            fallback=index;has_fallback=1;
        }
        const int32_t *other;
        if (candidate.start_reference==endpoint) other=candidate.end;
        else if (candidate.end_reference==endpoint) other=candidate.start;
        else continue;
        uint32_t word=(uint32_t)other[0]-(uint32_t)origin[0];
        int32_t dx,dz;memcpy(&dx,&word,sizeof(word));
        word=(uint32_t)other[2]-(uint32_t)origin[2];memcpy(&dz,&word,sizeof(word));
        int angle=(ll_native_angle(dz,dx)+1024)&4095;
        int difference=(int)(heading&4095u)-angle;
        if (difference<0) difference=-difference;
        if (difference>2048) difference=4096-difference;
        if (difference<best) { best=difference;selected=index;found=1; }
    }
    *next=found?selected:has_fallback?fallback:current;
    return found?2:has_fallback?3:0;
}

static int32_t path_wrapped(uint32_t word)
{
    int32_t value;memcpy(&value,&word,sizeof(value));return value;
}

static int32_t wrapped_shift(uint32_t word, unsigned shift)
{
    int32_t value=path_wrapped(word);
    return value>=0 ? value/(int32_t)(1u<<shift) :
        (int32_t)(-((-(int64_t)value+(1u<<shift)-1u)/(1u<<shift)));
}

unsigned ll_level_player_direction(uint16_t actions)
{
    switch (actions&0xf0u) {
    case 0x20:return 0;case 0x30:return 1;case 0x10:return 2;case 0x90:return 3;
    case 0x80:return 4;case 0xc0:return 5;case 0x40:return 6;case 0x60:return 7;
    default:return 8;
    }
}

void ll_level_script_set_input(LL_LevelScript *script, uint16_t actions)
{
    if (!script) return;
    if ((actions&0xa0u)==0xa0u) actions&=(uint16_t)~0xa0u;
    if ((actions&0x50u)==0x50u) actions&=(uint16_t)~0x50u;
    script->input_actions=actions;
}

int ll_level_player_accelerate(int32_t *speed, int32_t *displacement,
                                int32_t target, int32_t acceleration, uint8_t projection_mode)
{
    if (!speed || !displacement) return 0;
    int reached=*speed==target;
    uint32_t sum=0;
    for (unsigned i=0;i<=(unsigned)projection_mode;i++) {
        if (*speed<target) {
            *speed=path_wrapped((uint32_t)*speed+(uint32_t)acceleration);
            if (*speed>target) *speed=target;
        } else if (*speed>target) {
            *speed=path_wrapped((uint32_t)*speed-(uint32_t)acceleration);
            if (*speed<target) *speed=target;
        }
        sum+=(uint32_t)*speed;
    }
    *displacement=path_wrapped(sum);
    return reached;
}

int ll_level_player_facing(const LL_BibFile *bib, uint16_t selector, unsigned segment,
                            int16_t distance, int16_t path_yaw, int16_t camera_yaw,
                            uint16_t actions, int16_t *yaw)
{
    unsigned direction=ll_level_player_direction(actions);
    if (!yaw) return -1;
    if (direction==8) return 0;
    unsigned view=(uint16_t)camera_yaw&4095u;
    unsigned desired=(1024u+direction*512u+((view>=1024 && view<=3072)?2048u:0u))&4095u;
    int difference=(int)desired-path_yaw;
    if (difference<0) difference=-difference;
    if (!(difference>682 && difference<1365) && !(difference>2730 && difference<3413)) {
        if (difference>2048) difference=4096-difference;
        *yaw=(int16_t)((path_yaw+(difference<1024?0:2048))&4095);
        return 1;
    }
    /* Perpendicular input can select a junction only within the native
     * 600-unit endpoint window, in the original link order. */
    LL_BibPathSegment current;
    if (!ll_bib_get_path_segment(bib,selector,segment,&current)) return -1;
    uint32_t along=(uint32_t)(int32_t)distance;
    if (along>=601u && along<current.length-600u) return 0;
    uint32_t endpoint=along<601u ? current.start_reference : current.end_reference;
    const int32_t *origin=along<601u ? current.start : current.end;
    desired=(1024u+direction*512u+(uint16_t)camera_yaw)&4095u;
    for (unsigned i=0;i<current.link_count;i++) {
        unsigned index;LL_BibPathSegment candidate;
        if (!ll_bib_get_path_link(bib,selector,segment,i,&index) ||
            !ll_bib_get_path_segment(bib,selector,index,&candidate)) return -1;
        const int32_t *other=candidate.start_reference==endpoint ? candidate.end :
            candidate.end_reference==endpoint ? candidate.start : NULL;
        if (!other) continue;
        int32_t dx=path_wrapped((uint32_t)other[0]-(uint32_t)origin[0]);
        int32_t dz=path_wrapped((uint32_t)other[2]-(uint32_t)origin[2]);
        unsigned angle=(ll_native_angle(dz,dx)+1024)&4095;
        int delta=(int)desired-(int)angle;if (delta<0) delta=-delta;
        if (delta>2048) delta=4096-delta;
        if (delta<341) { *yaw=(int16_t)(path_yaw+(along<600u?2048:0));return 1; }
    }
    return 0;
}

int ll_level_path_floor_segment(const LL_BibFile *bib, uint32_t selector,
                                unsigned current, const int32_t position[3],
                                unsigned *next)
{
    LL_BibPathSegment original;
    if (!position || !next || !ll_bib_get_path_segment(bib,selector,current,&original)) return -1;
    int32_t best=INT32_MAX;
    unsigned selected=current;int found=0;
    for (unsigned link=0;link<original.link_count;link++) {
        LL_BibPathSegment candidate;unsigned index;
        if (!ll_bib_get_path_link(bib,selector,current,link,&index) ||
            !ll_bib_get_path_segment(bib,selector,index,&candidate)) return -1;
        if (candidate.start_reference==original.start_reference ||
            candidate.end_reference==original.start_reference ||
            candidate.start_reference==original.end_reference ||
            candidate.end_reference==original.end_reference) continue;
        int32_t delta[3],relative[3];
        for (unsigned i=0;i<3;i++) {
            delta[i]=path_wrapped((uint32_t)candidate.end[i]-(uint32_t)candidate.start[i]);
            relative[i]=path_wrapped((uint32_t)position[i]-(uint32_t)candidate.start[i]);
        }
        int64_t ax=delta[0]<0?-(int64_t)delta[0]:delta[0];
        int64_t az=delta[2]<0?-(int64_t)delta[2]:delta[2];
        unsigned axis=ax>az?0u:2u;
        int32_t length=path_wrapped(candidate.length);
        if (!delta[axis] || !length) return -1;
        int32_t product=path_wrapped((uint32_t)relative[axis]*(uint32_t)length);
        int64_t along=(int64_t)product/delta[axis];
        if (along<INT32_MIN || along>INT32_MAX) return -1;
        if (along<=0 || along>=length) continue;
        product=path_wrapped((uint32_t)delta[1]*(uint32_t)along);
        int64_t offset=(int64_t)product/length;
        if (offset<INT32_MIN || offset>INT32_MAX) return -1;
        int32_t height=path_wrapped((uint32_t)candidate.start[1]+(uint32_t)offset);
        if (relative[1]<offset && height<best) {
            best=height;selected=index;found=1;
        }
    }
    if (found) *next=selected;
    return found;
}

int ll_level_path_constrain(const LL_BibPathSegment *segment, const int32_t position[3],
                            uint32_t payload_flags, uint32_t path_flags,
                            int type4_override, LL_LevelPathConstraint *out)
{
    LL_LevelPathConstraint result;
    int32_t along;
    if (!out || !ll_bib_project_path_segment(segment,position,result.position,&along)) return 0;
    unsigned word=(uint32_t)along&65535u;
    result.distance=(int16_t)(word<32768?(int32_t)word:(int32_t)word-65536);
    if (result.distance<0) memcpy(result.position,segment->start,sizeof(result.position));
    int32_t length=path_wrapped(segment->length);
    if (result.distance>length) memcpy(result.position,segment->end,sizeof(result.position));
    int32_t y=position[1];
    if (!(path_flags&1u)) {
        if (!(payload_flags&0x20u) || (payload_flags&8u)) {
            if (result.position[1]<y) {
                if ((segment->flags&255u)==4 && !type4_override) {
                    payload_flags|=0x100u;path_flags|=1u;
                } else {
                    y=result.position[1];
                    if (payload_flags&0x40u) payload_flags|=0x20u;
                }
            }
            result.position[1]=y;
        }
    } else result.position[1]=y;
    result.payload_flags=payload_flags;result.path_flags=path_flags;
    *out=result;return 1;
}

int ll_level_path_step(const LL_BibFile *bib, uint32_t selector, unsigned current,
                       const int32_t position[3], uint16_t heading,
                       uint32_t payload_flags, uint32_t path_flags,
                       int type4_override, LL_LevelPathStep *out)
{
    if (!out) return 0;
    unsigned selected=current;
    int status=ll_level_path_next_segment(bib,selector,current,position,heading,&selected);
    if (status<0) return 0;
    LL_BibPathSegment segment;
    if (!ll_bib_get_path_segment(bib,selector,selected,&segment)) return 0;
    int orientation_reset=status==2 || status==3;
    if (status==0) {
        int floor=ll_level_path_floor_segment(bib,selector,current,position,&selected);
        if (floor<0) return 0;
        orientation_reset=floor!=0;
        if (floor && !(payload_flags&8u)) payload_flags&=~0x20u;
    } else if (status==2 && (segment.flags&255u)==1 && !(payload_flags&0x20u)) {
        selected=current; /* Native rejects this branch and resets the old segment. */
    }
    if (!ll_bib_get_path_segment(bib,selector,selected,&segment)) return 0;
    LL_NativePathSegmentState reset;
    ll_native_path_segment_reset(segment.start,segment.end,segment.length,&reset);
    if (status==3) {
        reset.yaw=(int16_t)((reset.yaw+2048)&4095);
        payload_flags|=0x20u;
    }
    LL_LevelPathStep result;
    if (!ll_level_path_constrain(&segment,position,payload_flags,path_flags,
            type4_override,&result.constraint)) return 0;
    result.segment=selected;result.yaw=reset.yaw;result.pitch=reset.pitch;
    result.orientation_reset=orientation_reset;
    *out=result;return 1;
}

int ll_level_path_obstacle(const LL_BibPathSegment *current,
                           const LL_BibPathSegment *candidate,
                           const int32_t position[3], const int32_t previous[3],
                           int32_t corrected[3])
{
    if (!current || !candidate || !position || !previous || !corrected) return -1;
    if (candidate->start_reference==current->start_reference ||
        candidate->end_reference==current->start_reference ||
        candidate->start_reference==current->end_reference ||
        candidate->end_reference==current->end_reference ||
        candidate->start[1]>current->start[1] || (candidate->flags&255u)==1) return 0;
    int32_t delta[3],relative[3],old[3];
    for (unsigned i=0;i<3;i++) {
        delta[i]=path_wrapped((uint32_t)candidate->end[i]-(uint32_t)candidate->start[i]);
        relative[i]=path_wrapped((uint32_t)position[i]-(uint32_t)candidate->start[i]);
        old[i]=path_wrapped((uint32_t)previous[i]-(uint32_t)candidate->start[i]);
    }
    int64_t ax=delta[0]<0?-(int64_t)delta[0]:delta[0];
    int64_t az=delta[2]<0?-(int64_t)delta[2]:delta[2];
    unsigned axis=ax>az?0u:2u;
    int32_t length=path_wrapped(candidate->length);
    if (!delta[axis] || !length) return -1;
    int64_t along=(int64_t)path_wrapped((uint32_t)relative[axis]*(uint32_t)length)/delta[axis];
    int64_t before=(int64_t)path_wrapped((uint32_t)old[axis]*(uint32_t)length)/delta[axis];
    if (along<INT32_MIN || along>INT32_MAX || before<INT32_MIN || before>INT32_MAX) return -1;
    if (along<=0 || along>=length) return 0;
    int64_t height=(int64_t)path_wrapped((uint32_t)delta[1]*(uint32_t)along)/length;
    if (height<INT32_MIN || height>INT32_MAX) return -1;
    int32_t gap=path_wrapped((uint32_t)relative[1]-(uint32_t)height);
    if (gap<0) return 1;
    uint32_t clearance=(candidate->flags>>16)+1800u;
    if (gap>=(int32_t)clearance) return 0;
    int32_t output[3];
    if (before<1 || before>=length) {
        const int32_t *endpoint=along<length/2?candidate->start:candidate->end;
        memcpy(output,endpoint,sizeof(output));output[1]=position[1];
    } else {
        memcpy(output,position,sizeof(output));
        output[1]=path_wrapped((uint32_t)candidate->start[1]+clearance+(uint32_t)height);
    }
    memcpy(corrected,output,sizeof(output));return 2;
}

int ll_level_path_update(const LL_BibFile *bib, uint32_t selector, unsigned current,
                         const int32_t position[3], const int32_t previous[3],
                         uint16_t heading, uint32_t payload_flags, uint32_t path_flags,
                         int type4_override, LL_LevelPathStep *out)
{
    if (!position || !previous || !out) return 0;
    LL_BibPathSegment original;
    if (!ll_bib_get_path_segment(bib,selector,current,&original)) return 0;
    int32_t adjusted[3];memcpy(adjusted,position,sizeof(adjusted));
    unsigned selected=current;int reset_orientation=0;
    for (unsigned link=0;link<original.link_count;link++) {
        LL_BibPathSegment candidate;unsigned index;
        if (!ll_bib_get_path_link(bib,selector,current,link,&index) ||
            !ll_bib_get_path_segment(bib,selector,index,&candidate)) return 0;
        int contact=ll_level_path_obstacle(&original,&candidate,position,previous,adjusted);
        if (contact<0) return 0;
        if (contact==1) { selected=index;reset_orientation=1;break; }
        if (contact==2) break;
    }
    unsigned next=selected;
    int status=ll_level_path_next_segment(bib,selector,selected,adjusted,heading,&next);
    if (status<0) return 0;
    LL_BibPathSegment segment;
    if (!ll_bib_get_path_segment(bib,selector,next,&segment)) return 0;
    if (status==0) {
        int floor=ll_level_path_floor_segment(bib,selector,selected,adjusted,&next);
        if (floor<0) return 0;
        if (floor) {
            reset_orientation=1;
            if (!(payload_flags&8u)) payload_flags&=~0x20u;
        }
    } else if (status==2) {
        reset_orientation=1;
        if ((segment.flags&255u)==1 && !(payload_flags&0x20u)) next=current;
    } else if (status==3) {
        reset_orientation=1;payload_flags|=0x20u;
    }
    if (!ll_bib_get_path_segment(bib,selector,next,&segment)) return 0;
    LL_LevelPathStep result;
    if (!ll_level_path_constrain(&segment,adjusted,payload_flags,path_flags,
            type4_override,&result.constraint)) return 0;
    LL_NativePathSegmentState state;
    ll_native_path_segment_reset(segment.start,segment.end,segment.length,&state);
    result.segment=next;result.yaw=state.yaw;result.pitch=state.pitch;
    if (status==3) result.yaw=(int16_t)((result.yaw+2048)&4095);
    result.orientation_reset=reset_orientation;
    *out=result;return 1;
}

static int sprite_bounds_apply(LL_LevelScriptObject *object, const LL_BizSprite *sprite, int initial)
{
    if (!object || object->kind!=5 || !sprite) return 0;
    int x=initial?0:object->sprite_offset[0],y=initial?0:object->sprite_offset[1];
    uint8_t width=(uint8_t)((uint16_t)sprite->width_units*4u);
    uint8_t height=(uint8_t)sprite->height;
    if (!width) width=0xff;
    if (!height) height=0xff;
    if ((unsigned)sprite->texture_x+width>0xffu)
        width=(uint8_t)(0xffu-sprite->texture_x);
    if ((unsigned)sprite->texture_y+height>0xffu)
        height=(uint8_t)(0xffu-sprite->texture_y);

    int16_t rectangle_width=initial?width:(int16_t)(width-2);
    int16_t rectangle_height=initial?height:(int16_t)(height-2);
    /* 486410 starts at0,0. 4862e0 replaces that with the BIB frame offsets
     * and dimensions minus2; atlas UVs are used only for texture sampling.
     * FUN_00485e70 applies the object scale in 16-bit fields, then Abilene's
     * game-state2 projection scales X by 640/512. Its sprite bounds store the
     * min/max of the resulting rectangle coordinates in the third axis. */
    int16_t sx=(int16_t)(uint16_t)(x*object->sprite_scale);
    int16_t sy=(int16_t)(uint16_t)(y*object->sprite_scale);
    int16_t sw=(int16_t)(uint16_t)(rectangle_width*object->sprite_scale);
    int16_t sh=(int16_t)(uint16_t)(rectangle_height*object->sprite_scale);
    sx=(int16_t)((uint32_t)((int32_t)sx*640)>>9);
    sw=(int16_t)((uint32_t)((int32_t)sw*640)>>9);
    int right=(int)sx+(int)sw,bottom=(int)sy+(int)sh;
    object->private_bounds[0]=sx;object->private_bounds[1]=sy;
    int minimum=sx<sy?sx:sy,maximum=right>bottom?right:bottom;
    if (initial || minimum<object->private_bounds[2]) object->private_bounds[2]=minimum;
    object->private_bounds[3]=right;object->private_bounds[4]=bottom;
    if (initial || maximum>object->private_bounds[5]) object->private_bounds[5]=maximum;
    object->bounds=object->private_bounds;
    return 1;
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
    if (object->kind==5) sprite_bounds_apply(object,&sprite,0);
    object->sprite_frame_applied=1;
    object->sprite_primitives_present=1;
    return 1;
}

int ll_level_script_world_sprite_vertices(const LL_LevelScript *script,
                                           const LL_LevelScriptObject *sprite,
                                           const int16_t *view, const int32_t translation[3],
                                           int32_t vertices[4][3])
{
    LL_BizSprite resource;
    if (!script || !sprite || sprite->kind!=5 || !sprite->pose || !view || !translation ||
        !vertices || !ll_biz_get_sprite(&script->biz,sprite->biz_sprite,&resource)) return 0;
    unsigned width=(uint8_t)((unsigned)resource.width_units*4u),height=(uint8_t)resource.height;
    if (!width) width=255;
    if (!height) height=255;
    if (width>255u-resource.texture_x) width=255u-resource.texture_x;
    if (height>255u-resource.texture_y) height=255u-resource.texture_y;
    if (width<2 || height<2) return 0;
    int16_t x=(int16_t)(uint16_t)((sprite->sprite_frame_applied?sprite->sprite_offset[0]:0)*sprite->sprite_scale);
    int16_t y=(int16_t)(uint16_t)((sprite->sprite_frame_applied?sprite->sprite_offset[1]:0)*sprite->sprite_scale);
    int16_t w=(int16_t)(uint16_t)((int)(width-(sprite->sprite_frame_applied?2u:0u))*sprite->sprite_scale);
    int16_t h=(int16_t)(uint16_t)((int)(height-(sprite->sprite_frame_applied?2u:0u))*sprite->sprite_scale);
    x=(int16_t)wrapped_shift((uint32_t)((int32_t)x*640),9);
    w=(int16_t)wrapped_shift((uint32_t)((int32_t)w*640),9);
    static const int16_t identity[9]={4096,0,0,0,4096,0,0,0,4096};
    static const int16_t billboard[9]={4096,0,0,0,2944,0,0,0,4096};
    int16_t unused[9];int32_t root[3];
    ll_native_camera_model_view(view,translation,identity,sprite->pose->position,unused,root);
    for (unsigned i=0;i<4;i++) {
        int16_t point[3]={(int16_t)(uint16_t)(x+((i&1u)?w:0)),
            (int16_t)(uint16_t)(y+((i&2u)?h:0)),17};
        ll_native_camera_vertex(billboard,root,point,vertices[i]);
    }
    return 1;
}

static int projectile_pool_initialize(LL_LevelScript *script, const uint16_t selectors[2])
{
    if (script->projectiles.initialized) return fail(script,"projectile pool replacement is not implemented");
    /* FUN_00412c80 resolves two sprite sequences, not skeletal animations.
     * Validate every frame before publishing any of the twenty descriptors. */
    for (unsigned s=0;s<2;s++) {
        LL_BibSelector section;
        if (!ll_bib_get_selector(&script->bib,selectors[s],&section) || !section.is_section ||
            section.size<12 || script->bib.raw_data[section.offset+4u]!=1)
            return fail(script,"projectile pool requires bounded offset-bearing sprite sequences");
        unsigned count=(unsigned)script->bib.raw_data[section.offset+2u]|
            ((unsigned)script->bib.raw_data[section.offset+3u]<<8);
        if (!count) return fail(script,"projectile pool has an empty sprite sequence");
        for (unsigned f=0;f<count;f++) {
            LL_BibSpriteFrame frame;LL_BizObject object;LL_BizSprite sprite;
            if (!ll_bib_get_sprite_frame(&script->bib,selectors[s],f,&frame) ||
                !ll_biz_get_object(&script->biz,frame.object_index,&object) ||
                !ll_biz_get_sprite(&script->biz,object.sprite_index,&sprite))
                return fail(script,"projectile pool references an invalid BIB/BIZ sprite frame");
        }
    }
    for (unsigned i=0;i<10;i++) {
        LL_LevelProjectile *slot=&script->projectiles.slots[i];
        for (unsigned s=0;s<2;s++) {
            LL_LevelScriptObject *sprite=s?&slot->flash:&slot->ball;
            sprite->present=1;sprite->kind=5;sprite->sprite_selector=selectors[s];sprite->sprite_scale=16;
            sprite->pose=&sprite->private_pose;
            sprite_frame_apply(script,sprite,0);
        }
        static const int32_t bounds[6]={-30,-30,-60,30,30,60};
        memcpy(slot->ball.private_bounds,bounds,sizeof(bounds));slot->ball.bounds=slot->ball.private_bounds;
    }
    script->projectiles.initialized=1;script->projectiles.owner_context=script->dispatch_context;
    return 1;
}

static int player_damage(LL_LevelScript *script, uint16_t mode, int16_t amount, uint8_t *accepted);
static void player_blocked(LL_LevelScript *script, const char *message);

static uint16_t projectile_spawn(LL_LevelScript *script, const int32_t origin[3], int16_t yaw,
                                  int16_t angle, uint16_t targets, uint16_t flags)
{
    int ball_found=0,flash_found=0;
    uint16_t result=0; /* Native476b40 also returns0 when the ball pool is exhausted. */
    uint32_t clock=animation_clock(script->updates)>>5;
    for (unsigned i=0;i<10 && (!ball_found || !flash_found);i++) {
        LL_LevelProjectile *slot=&script->projectiles.slots[i];
        if (!slot->flags && !ball_found) {
            slot->flags=flags;slot->target_count=targets;slot->first_frame=1;ball_found=1;result=(uint16_t)i;
            slot->ball.sprite_scale=4;sprite_frame_apply(script,&slot->ball,0);
            static const int32_t bounds[6]={-30,-30,-60,30,30,60};
            memcpy(slot->ball.private_bounds,bounds,sizeof(bounds));
            memcpy(slot->ball.pose->position,origin,3*sizeof(*origin));slot->ball_started=clock;
            int16_t horizontal=(int16_t)(uint16_t)(yaw-1024);
            slot->velocity[0]=wrapped_shift((uint32_t)((int32_t)ll_native_cosine(horizontal)*ll_native_cosine(angle)),16);
            slot->velocity[2]=wrapped_shift((uint32_t)((int32_t)ll_native_sine(horizontal)*ll_native_cosine(angle)),16);
            slot->velocity[1]=wrapped_shift((uint32_t)(-(int32_t)ll_native_sine(angle)),4);
            script->projectiles.shots_fired++;
            if (!(flags&2u)) script->projectiles.enemy_shots_fired++;
        }
        if (!slot->flash_active && !flash_found) {
            slot->flash_active=1;flash_found=1;
            slot->flash.sprite_scale=4;sprite_frame_apply(script,&slot->flash,0);
            memcpy(slot->flash.pose->position,origin,3*sizeof(*origin));slot->flash_started=clock;
        }
    }
    if (!ball_found) script->projectiles.shots_dropped++;
    return result;
}

static void projectile_collide(LL_LevelScript *script, unsigned index)
{
    LL_LevelProjectile *slot=&script->projectiles.slots[index];
    unsigned count=(slot->flags&2u)?250u:slot->target_count;
    for (unsigned entry=0;entry<count;entry++) {
        unsigned i=(slot->flags&2u)?entry:slot->targets[entry];
        if (i>=260) continue;
        LL_LevelScriptObject *target=&script->objects[i];
        unsigned mask=(slot->flags&2u)?4u:6u;
        if (!target->present || !(target->wrapper_flags&mask) || !target->pose || !target->bounds) continue;
        int overlap=1;
        for (unsigned axis=0;axis<3;axis++) {
            int32_t a=path_wrapped((uint32_t)slot->ball.pose->position[axis]+(uint32_t)slot->ball.bounds[axis]);
            int32_t b=path_wrapped((uint32_t)slot->ball.pose->position[axis]+(uint32_t)slot->ball.bounds[axis+3]);
            int32_t c=path_wrapped((uint32_t)target->pose->position[axis]+(uint32_t)target->bounds[axis]);
            int32_t d=path_wrapped((uint32_t)target->pose->position[axis]+(uint32_t)target->bounds[axis+3]);
            if (a>d || c>b) { overlap=0;break; }
        }
        if (overlap) {
            uint16_t flags=slot->flags;slot->flags=0;
            if (!(flags&2u) && (target->wrapper_flags&2u)) {
                uint8_t accepted;
                if (!player_damage(script,1,1,&accepted)) player_blocked(script,script->error);
            }
            else {
                target->wrapper_flags|=1u;
                if (flags&2u) {
                    script->projectiles.hit_slot=(uint16_t)index;
                    script->native.collision_event_latch=(uint16_t)i;
                } else {
                    slot->target_count--;
                    script->projectiles.enemy_hit_instance=(uint16_t)i;
                    script->projectiles.enemy_hit_slot=(uint16_t)index;
                }
            }
            break;
        }
    }
}

static void projectile_animation(LL_LevelScript *script, LL_LevelScriptObject *sprite,
                                  uint32_t started, uint8_t *flash_active)
{
    LL_BibSelector section;LL_BibSpriteFrame record;
    if (!ll_bib_get_selector(&script->bib,sprite->sprite_selector,&section)) return;
    unsigned count=(unsigned)script->bib.raw_data[section.offset+2u]|
        ((unsigned)script->bib.raw_data[section.offset+3u]<<8);
    uint64_t total=0;
    for (unsigned f=0;f<count;f++) {
        if (!ll_bib_get_sprite_frame(&script->bib,sprite->sprite_selector,f,&record)) return;
        total+=record.duration;
    }
    if (!total) return;
    uint64_t elapsed=(uint32_t)((animation_clock(script->updates)>>5)-started);
    /* FUN_00485430 advances only when elapsed>duration, including the last
     * frame. A flash's callback clears activity once; balls keep looping. */
    if (flash_active && elapsed>total) {
        if (sprite->sprite_frame+1u!=count) sprite_frame_apply(script,sprite,(uint16_t)(count-1u));
        *flash_active=0;return;
    }
    if (elapsed) elapsed=(elapsed-1u)%total+1u;
    unsigned frame=0;
    for (;frame+1u<count;frame++) {
        ll_bib_get_sprite_frame(&script->bib,sprite->sprite_selector,frame,&record);
        if (elapsed<=record.duration) break;
        elapsed-=record.duration;
    }
    if (frame!=sprite->sprite_frame) {
        int32_t bounds[6];memcpy(bounds,sprite->private_bounds,sizeof(bounds));
        sprite_frame_apply(script,sprite,(uint16_t)frame);
        if (!flash_active) memcpy(sprite->private_bounds,bounds,sizeof(bounds));
    }
}

static void projectiles_update(LL_LevelScript *script)
{
    if (!script->projectiles.initialized) return;
    const LL_LevelNativeSetup *camera=&script->native;
    int16_t view[3][3];int32_t translation[3];
    ll_native_camera_view(camera->camera_view_pitch,camera->camera_view_yaw,
        camera->camera_render_reference,camera->depth,view,translation);
    for (unsigned i=0;i<10;i++) {
        LL_LevelProjectile *slot=&script->projectiles.slots[i];
        if (slot->flags) {
            for (unsigned axis=0;axis<3;axis++)
                slot->ball.pose->position[axis]=path_wrapped((uint32_t)slot->ball.pose->position[axis]+(uint32_t)slot->velocity[axis]);
            projectile_collide(script,i);
            int32_t z=slot->ball.pose->position[2];
            if (!slot->first_frame && ((camera->camera_output_active &&
                    (slot->screen[0]<0 || slot->screen[0]>640 || slot->screen[1]<0 || slot->screen[1]>480)) ||
                    z< -3000 || z>20000)) {
                slot->flags=0;memset(slot->ball.pose->position,0,sizeof(slot->ball.pose->position));
            }
            slot->first_frame=0;
        }
        /* These sequence updates run in FUN_00476060's draw callback. Keep
         * them deterministic in the headless tracer as well as the renderer. */
        if (slot->flags) {
            projectile_animation(script,&slot->ball,slot->ball_started,NULL);
            int32_t vertices[4][3];
            if (camera->camera_output_active && ll_level_script_world_sprite_vertices(script,&slot->ball,
                    &view[0][0],translation,vertices)) {
                const int32_t focal[2]={(int32_t)((uint16_t)camera->projection*(640.0f/448.0f)),
                    (int32_t)((uint16_t)camera->projection*2.0f)};
                for (unsigned axis=0;axis<2;axis++) {
                    int32_t product=path_wrapped((uint32_t)vertices[0][axis]*(uint32_t)focal[axis]);
                    int32_t projected=vertices[0][2] ? (int32_t)((int64_t)product/vertices[0][2]) : product;
                    slot->screen[axis]=(int16_t)(uint16_t)((uint32_t)projected+(axis?240u:320u));
                }
            }
        }
        slot->flash_visible=slot->flash_active;
        if (slot->flash_active) projectile_animation(script,&slot->flash,slot->flash_started,&slot->flash_active);
    }
}

int ll_level_script_group_member_bounds(const LL_LevelScript *script,
                                        unsigned instance, unsigned member,
                                        int32_t bounds[6])
{
    if (!script || !script->loaded || !bounds || instance>=260) return 0;
    const LL_LevelOrbitalGroup *group=&script->orbital_groups[instance];
    if (!group->present || !group->has_member_positions || !group->has_sprite_bounds ||
        member>=group->member_count || member>=64) return 0;
    int32_t translated[6];
    for (unsigned i=0;i<6;i++) {
        /* Native coordinate arithmetic wraps at32 bits. */
        const int32_t *local=group->sprites?group->sprites[member].bounds:group->sprite_bounds;
        uint32_t word=(uint32_t)local[i]+
            (uint32_t)group->member_roots[member][i%3];
        memcpy(&translated[i],&word,sizeof(word));
    }
    memcpy(bounds,translated,sizeof(translated));
    return 1;
}

int ll_level_script_group_overlap(const LL_LevelScript *script, unsigned instance,
                                  const int32_t bounds[6])
{
    if (!script || !script->loaded || !bounds || instance>=260) return -2;
    const LL_LevelOrbitalGroup *group=&script->orbital_groups[instance];
    if (!group->present || !group->has_member_positions || !group->has_sprite_bounds ||
        !group->member_count || group->member_count>64) return -2;
    for (unsigned axis=0;axis<3;axis++)
        if (bounds[axis]>bounds[axis+3]) return -2;
    for (unsigned member=0;member<group->member_count;member++) {
        if (!group->member_active[member]) continue;
        int32_t candidate[6];
        if (!ll_level_script_group_member_bounds(script,instance,member,candidate)) return -2;
        int overlap=1;
        for (unsigned axis=0;axis<3;axis++)
            if (candidate[axis+3]<bounds[axis] || bounds[axis+3]<candidate[axis]) {
                overlap=0;break;
            }
        if (overlap) return (int)member;
    }
    return -1;
}

int ll_level_script_group_contact(LL_LevelScript *script, unsigned instance,
                                  const int32_t bounds[6])
{
    int member=ll_level_script_group_overlap(script,instance,bounds);
    if (member<0) return member;
    LL_LevelOrbitalGroup *group=&script->orbital_groups[instance];
    /* FUN_0040ae50 gates contact effects on both the wrapper callback and
     * the group's byte at+2. In particular, command0x4e(0) must suppress
     * contact without consuming a member or requesting its hit animation. */
    if (!group->callback_registered || !group->native_byte_2) return -1;
    if (script->native.player_word) {
        LL_BibSelector section;LL_BibSpriteFrame frame;
        unsigned selector=script->native.player_word;
        if (!group->sprites || !ll_bib_get_selector(&script->bib,selector,&section) || section.size<12)
            return -3;
        unsigned count=(unsigned)script->bib.raw_data[section.offset+2u]|
            ((unsigned)script->bib.raw_data[section.offset+3u]<<8);
        if (!count) return -3;
        for (unsigned f=0;f<count;f++) if (!ll_bib_get_sprite_frame(&script->bib,selector,f,&frame)) return -3;
        LL_LevelScriptObject prepared=group->sprites[member];
        prepared.sprite_selector=(uint16_t)selector;prepared.sprite_scale=32;
        if (!sprite_frame_apply(script,&prepared,0)) return -3;
        group->sprites[member]=prepared;
        group->sprites[member].bounds=group->sprites[member].private_bounds;
        group->member_started[member]=animation_clock(script->updates)>>5;
        group->member_effect[member]=1;
    }
    group->member_active[member]=0;
    if (!script->native.player_word) group->member_visible[member]=0;
    return member;
}

static void sprite_groups_update(LL_LevelScript *script)
{
    for (unsigned i=0;i<260;i++) {
        LL_LevelOrbitalGroup *group=&script->orbital_groups[i];
        if (!group->sprites || !group->callback_registered || !group->native_byte_2) continue;
        for (unsigned m=0;m<group->member_count;m++) {
            if (!group->member_visible[m]) continue;
            if (group->member_effect[m]==2) { group->member_visible[m]=0;continue; }
            LL_LevelScriptObject *sprite=&group->sprites[m];
            uint8_t active=1;
            projectile_animation(script,sprite,group->member_started[m],group->member_effect[m]?&active:NULL);
            if (group->member_effect[m]) {
                LL_BibSelector section;
                if (ll_bib_get_selector(&script->bib,sprite->sprite_selector,&section) && section.size>=12) {
                    unsigned count=(unsigned)script->bib.raw_data[section.offset+2u]|
                        ((unsigned)script->bib.raw_data[section.offset+3u]<<8);
                    if (!active || sprite->sprite_frame+1u==count) group->member_effect[m]=2;
                }
            }
        }
    }
}

void ll_level_script_close(LL_LevelScript *script)
{
    if (!script) return;
    for (unsigned i=0;i<260;i++) free(script->backgrounds[i]);
    for (unsigned i=0;i<260;i++) free(script->orbital_groups[i].sprites);
    ll_native_pause_close(&script->pause);
    ll_native_audio_close(&script->audio);
    ll_sool_program_close(&script->program);
    ll_bib_close(&script->bib);
    ll_biz_close(&script->biz);
    free(script->contexts);free(script->condition_vm);
    free(script->code_data);free(script->bib_data);free(script->biz_data);
    free(script->model_poses);
    free(script->model_rotations);
    free(script->model_bounds);
    free(script->model_materials);
    memset(script,0,sizeof(*script));
}

int ll_level_script_open(LL_LevelScript *script,
                          const unsigned char *code, size_t code_size,
                          const unsigned char *bib, size_t bib_size, FILE *trace)
{
    if (!script) return 0;
    memset(script,0,sizeof(*script));
    ll_native_audio_init(&script->audio);
    script->native.native_word_44=3;script->native.player_lives=5;
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
        script->model_rotations=calloc(script->bib.model_count,sizeof(*script->model_rotations));
        script->model_bounds=calloc(script->bib.model_count,sizeof(*script->model_bounds));
        script->model_materials=calloc(script->bib.model_count,sizeof(*script->model_materials));
        if (script->bib.model_count && (!script->model_poses || !script->model_bounds || !script->model_rotations || !script->model_materials))
            return fail(script,"cannot allocate mutable scene-root poses");
        for (unsigned i=0;i<script->bib.model_count;i++) {
            const LL_Bib3dxModel *model=&script->bib.models[i];
            script->model_materials[i].multiplier=model->color_multiplier;
            script->model_materials[i].applied=model->type==1;
            if (model->type==1 && !model->color_multiplier)
                script->model_materials[i].multiplier=256; /* 47ec50 expansion. */
            memcpy(script->model_rotations[i],script->bib.models[i].root_rotation,
                sizeof(script->model_rotations[i]));
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
    if (!ll_native_audio_open(&script->audio,&parsed)) {
        snprintf(script->error,sizeof(script->error),"%s",script->audio.error);
        ll_biz_close(&parsed);free(owned);return 0;
    }
    ll_biz_close(&script->biz);free(script->biz_data);
    script->biz=parsed;script->biz_data=owned;
    return 1;
}

int ll_level_script_replace(LL_LevelScript *script,
    const unsigned char *code, size_t code_size, const unsigned char *bib, size_t bib_size,
    const unsigned char *biz, size_t biz_size, const unsigned char *pause, size_t pause_size)
{
    if (!script) return 0;
    if (!bib || !bib_size || (!pause && pause_size)) return fail(script,"next SOOL scene has missing resources");
    LL_LevelScript *next=calloc(1,sizeof(*next));
    if (!next) return fail(script,"cannot allocate next SOOL scene");
    int ok=ll_level_script_open(next,code,code_size,bib,bib_size,script->trace) &&
        ll_level_script_set_biz(next,biz,biz_size) &&
        (!pause || ll_level_script_set_pause_archive(next,pause,pause_size));
    if (!ok) {
        snprintf(script->error,sizeof(script->error),"%s",next->error);
        ll_level_script_close(next);free(next);return 0;
    }
    if (script->loaded) {
        next->native.player_lives=script->native.player_lives;
        next->native.player_money=script->native.player_money;next->native.player_cards=script->native.player_cards;
        next->native.player_invincible=script->native.player_invincible;
        next->native.force_full_display=script->native.force_full_display;
        next->native.player_health_dirty=script->native.player_health_dirty;
        next->native.dynamite_dirty=script->native.dynamite_dirty;next->native.money_dirty=script->native.money_dirty;
        next->native.cards_dirty=script->native.cards_dirty;next->native.money_timer=script->native.money_timer;
        next->native.control_profile=script->native.control_profile;
        next->native.saved_control_profile=script->native.saved_control_profile;
        next->native.previous_control_profile=script->native.previous_control_profile;
        next->audio.effects_enabled=script->audio.effects_enabled;next->audio.stereo=script->audio.stereo;
        next->audio.master_volume=script->audio.master_volume;
    }
    /* 4067e0 seeds46d7b0(09a4ec86) before every outer scene load/restart. */
    ll_native_rng_reset();
    ll_level_script_close(script);*script=*next;free(next);return 1;
}

static int sound_position(const LL_LevelScript *script, uint16_t instance, int32_t screen[2])
{
    if (instance>=260 || !script->objects[instance].present || !script->objects[instance].pose) return 0;
    const LL_LevelNativeSetup *camera=&script->native;
    ll_native_camera_screen(script->objects[instance].pose->position,camera->camera_render_reference,
        camera->camera_view_pitch,camera->camera_view_yaw,camera->depth,(uint16_t)camera->projection,screen);
    return 1;
}

static int sound_play(LL_LevelScript *script, const uint16_t args[6], uint16_t *slot)
{
    /* FUN_0041f5e0 checks the driver and volume before resolving the owner
     * or sample. The positional argument is narrowed to a byte. */
    *slot=0;
    if (!script->audio.enabled || !args[3]) return 1;
    if ((uint8_t)args[5]==1) {
        int32_t screen[2];
        if (!sound_position(script,args[0],screen))
            return fail(script,"positional sound requires a registered wrapper root");
        if (screen[0]<0 || screen[0]>640) return 1;
    }
    if (!ll_native_audio_play(&script->audio,args[1],(int16_t)args[2],args[3],args[4],slot))
        return fail(script,script->audio.error);
    if (*slot && getenv("LL_TRACE_AUDIO")) {
        unsigned sample=(uint16_t)(args[1]-script->audio.base);
        fprintf(stderr,"TRACE: Abilene sound %s voice%u owner%u pitch%d volume%u pan%u\n",
            script->audio.samples[sample].name,*slot,args[0],(int16_t)args[2],args[3],args[4]);
    }
    return 1;
}

static int model_vertices(const LL_LevelScript *script,
                                    const LL_LevelScriptObject *object,
                                    LL_BibVertex *vertices, size_t capacity, const int16_t *root)
{
    if (!script || !object || !vertices || !ll_bib_build_neutral_vertices(&script->bib,
            object->model_index,vertices,capacity)) return 0;
    if (!object->animation_pose_present) return !root ||
        ll_native_model_pose_vertices_rooted(&script->bib,object->model_index,NULL,0,vertices,capacity,root);
    const LL_BibAnimationTable *table=ll_bib_get_animation_table(&script->bib,object->animation_selector);
    if (!table) return 0;
    LL_BibPackedPose *retained=NULL;
    if (!object->animation_active || root) {
        retained=calloc(table->record_type,sizeof(*retained));if (!retained) return 0;
    }
    int seam=0;
    if (object->animation_active) {
        if (object->animation_reverse) {
            if (!object->animation_frame && object->animation_next_frame==table->record_count-1u) seam=-1;
        } else if (object->animation_frame==table->record_count-1u && !object->animation_next_frame) seam=1;
    }
    int ok=ll_native_animation_vertices_motion(&script->bib,object->model_index,
        object->animation_selector,object->animation_frame,object->animation_next_frame,
        object->animation_fraction,vertices,capacity,NULL,0,retained,
        object->animation_active && object->animation_root_motion?object->animation_root_axis:-1,seam);
    if (ok && retained) {
        /* FUN_004851b0/00485230 preserve expanded channels on release,
         * except for part1's three translation components. */
        if (!object->animation_active && table->record_type>1) {
            retained[1].present_groups|=2u;memset(&retained[1].channels[3],0,3*sizeof(retained[1].channels[0]));
        }
        ok=ll_bib_build_neutral_vertices(&script->bib,object->model_index,vertices,capacity) &&
            ll_native_model_pose_vertices_rooted(&script->bib,object->model_index,retained,table->record_type,vertices,capacity,root);
    }
    free(retained);return ok;
}

int ll_level_script_model_vertices(const LL_LevelScript *script,
                                    const LL_LevelScriptObject *object,
                                    LL_BibVertex *vertices, size_t capacity)
{
    return model_vertices(script,object,vertices,capacity,NULL);
}

static int animation_motion_prepare(LL_LevelScript *script, const LL_LevelScriptObject *object,
                                     const LL_BibAnimationTable *table, uint16_t first,
                                     uint8_t *enabled, uint8_t *axis, int32_t *reference)
{
    *enabled=0;*axis=1;*reference=0;
    if (table->loop_displacement[0]) *axis=0;
    else if (table->loop_displacement[2]) *axis=2;
    if (!object->root_rotation || object->kind!=1 || table->record_type<2) {
        if (table->loop_displacement[0] || table->loop_displacement[1] || table->loop_displacement[2])
            return fail(script,"animation root motion requires a skeletal root and part1");
        return 1;
    }
    int16_t root[3];
    if (!ll_native_animation_root_translation(&script->bib,table->selector,first,first,0,0,root))
        return fail(script,"animation root motion has an invalid initial packed pose");
    *enabled=1;*reference=root[*axis];return 1;
}

static LL_LevelSkeletalAttachment *skeletal_attachment(LL_LevelScript *script, unsigned child)
{
    for (unsigned i=0;i<script->skeletal_attachment_count;i++)
        if (script->skeletal_attachments[i].child_instance==child) return &script->skeletal_attachments[i];
    return NULL;
}

int ll_level_script_model_presented(const LL_LevelScript *script, unsigned instance)
{
    if (!script || instance>=260) return 0;
    for (unsigned depth=0;depth<260;depth++) {
        unsigned parent=instance;
        for (unsigned i=0;i<script->skeletal_attachment_count;i++)
            if (script->skeletal_attachments[i].child_instance==instance) {
                parent=script->skeletal_attachments[i].parent_instance;break;
            }
        if (parent==instance) {
            const LL_LevelScriptObject *root=&script->objects[instance];
            return root->present && root->visible && root->update_enabled &&
                root->native_callback_enabled && !root->draw_suppressed;
        }
        if (parent>=260) return 0;
        instance=parent;
    }
    return 0;
}

static int attachment_pivot(const LL_LevelScript *script, const LL_LevelScriptObject *object,
                              uint16_t part_index, int16_t pivot[3])
{
    const LL_Bib3dxModel *model=ll_bib_get_model(&script->bib,object->model_index);
    LL_BibModelPart part;
    if (!object->root_rotation || !model ||
        !ll_bib_get_model_part(&script->bib,object->model_index,part_index,&part) ||
        part.pivot_vertex>=model->vertex_count) return 0;
    LL_BibVertex *vertices=calloc(model->vertex_count,sizeof(*vertices));
    if (!vertices) return 0;
    int ok=model_vertices(script,object,vertices,model->vertex_count,object->root_rotation);
    if (ok) memcpy(pivot,vertices[part.pivot_vertex].position,3*sizeof(*pivot));
    free(vertices);return ok;
}

static void model_position_set(LL_LevelScript *script, LL_LevelScriptObject *object, const int32_t position[3])
{
    unsigned instance=(unsigned)(object-script->objects);
    LL_LevelSkeletalAttachment *attachment=skeletal_attachment(script,instance);
    /* FUN_00457ab0/00457b70: attached writes are deferred local offsets. */
    memcpy(attachment?attachment->root_offset:object->pose->position,position,3*sizeof(*position));
}

static int command(LL_LevelScript *script, uint16_t id, const uint16_t *args, size_t argc)
{
    LL_LevelNativeSetup *state=&script->native;
    uint16_t current=script->contexts[script->dispatch_context].instance;
    LL_LevelScriptObject *object=current<260 && script->objects[current].present ? &script->objects[current] : NULL;
#define ARITY(n) do { if (argc!=(n)) return fail(script,"wrong native command arity"); } while (0)
    switch (id) {
    case 0x12: /* 410250: defer the scene change until the outer loop owns the VMs again. */
        ARITY(1);
        if (args[0]<1 || args[0]>3) return fail(script,"requested outer scene is not ported");
        script->requested_scene=args[0];script->scene_requested=1;return 1;
    case 0x1e: /* 410740/477aa0: register the empty50-entry timer manager. */
        ARITY(0);
        if (state->timer_manager_registered) return fail(script,"timer manager replacement is not ported");
        state->timer_manager_registered=1;return 1;
    case 0x51: /* 413f70: keyboard action profile and its two saved bytes. */
        ARITY(1);
        if ((uint8_t)args[0]>2) return fail(script,"control profile exceeds the three native keyboard tables");
        state->previous_control_profile=state->saved_control_profile;
        state->control_profile=state->saved_control_profile=(uint8_t)args[0];return 1;
    case 0x33: { /* 411ac0: five (byte offset,context) destinations, read below the ordinary arity. */
        ARITY(10);
        for (unsigned i=0;i<5;i++)
            if (args[i*2u]>255 || args[i*2u+1u]>=script->program.function_count)
                return fail(script,"inventory snapshot destination exceeds a retained SOOL data bank");
        LL_SoolVM *vm=script->in_conditions?script->condition_vm:&script->contexts[script->dispatch_context].vm;
        const uint16_t values[5]={(uint16_t)state->player_lives,state->native_word_44,(uint16_t)state->player_money,
            (uint16_t)state->player_dynamite,(uint16_t)state->player_cards};
        /* The original writes cards first and lives last, which matters for aliases. */
        for (unsigned n=5;n;n--) {
            unsigned i=n-1u,bank=args[i*2u+1u];
            ll_sool_write_word(bank==script->dispatch_context?vm->locals:vm->members[bank],(uint8_t)args[i*2u],values[i]);
        }
        return 1;
    }
    case 0x14a: { /* 41d020: add to the retained camera Y or the bounded follow-height DWORD. */
        ARITY(1);
        if (state->camera_lock==1) return 1;
        if (state->camera_vertical_mode==0 || state->camera_vertical_mode==3 || !state->camera_follow_instance_plus_one)
            state->camera_follow_reference[1]=path_wrapped((uint32_t)state->camera_follow_reference[1]+(uint32_t)(int32_t)(int16_t)args[0]);
        else {
            int height=(int)state->camera_follow_height+(int16_t)args[0];
            state->camera_follow_height=(int16_t)(height< -6000?-6000:height>6000?6000:height);
        }
        return 1;
    }
    case 0x35: { /* 411930: signed-word inventory updates and HUD invalidation flags. */
        ARITY(2);int16_t amount=(int16_t)args[1];
        switch (args[0]) {
        case 0:
            state->player_dynamite=(int16_t)(uint16_t)((uint16_t)state->player_dynamite+args[1]);
            state->dynamite_dirty=1;break;
        case 1:
            if ((int16_t)state->native_word_44<(amount<0?4:3))
                state->native_word_44=(uint16_t)(state->native_word_44+args[1]);
            if ((int16_t)state->native_word_44>3) state->native_word_44=3;
            state->player_health_dirty=1;break;
        case 2:state->player_lives=(int16_t)(uint16_t)((uint16_t)state->player_lives+args[1]);break;
        case 3:
            state->player_money=(int16_t)(uint16_t)((uint16_t)state->player_money+args[1]);
            if (state->player_money<0) state->player_money=0;
            state->money_dirty=1;state->money_timer=0;break;
        case 4:
            state->player_cards=(int16_t)(uint16_t)((uint16_t)state->player_cards+args[1]);
            state->cards_dirty=1;break;
        }
        return 1;
    }
    case 0xba: /* 416a20 replaces the global main controller; argument0 is unused. */
        ARITY(2);
        if (args[1]==4 || args[1]>15) return 1; /* No switch case: leave the callback unchanged. */
        if (args[1]>3 && args[1]!=8 && args[1]!=15)
            return fail(script,"requested BA controller entry is not ported");
        if (!script->player.present)
            return fail(script,"BA controller entry requires the registered player");
        script->player.controller_entry=(uint8_t)(args[1]+1u);return 1;
    case 0x30: { /* 4116d0 ->47d700: descriptor intensity and retained primitive RGB. */
        ARITY(2);
        if (args[0]>=260 || !script->objects[args[0]].present)
            return fail(script,"model intensity requires a registered instance");
        LL_LevelScriptObject *target=&script->objects[args[0]];
        if (!target->material || target->model_index>=script->bib.model_count)
            return fail(script,"model intensity requires a retained model descriptor");
        const LL_Bib3dxModel *model=&script->bib.models[target->model_index];
        for (unsigned g=0;g<model->group_count;g++)
            if (model->groups[g].type>3 && model->groups[g].element_count)
                return fail(script,"Gouraud primitive intensity requires verification of the native hardware dispatch");
        target->material->multiplier=(int16_t)args[1];
        target->material->applied=1;return 1;
    }
    case 0x4c: /* FUN_00413780: five legacy BIB arguments are unused on Windows. */
        ARITY(5);
        if (!ll_native_pause_register(&script->pause)) return fail(script,script->pause.error);
        state->pause_enabled=1;return 1;
    case 0x122: { /* FUN_00415a60/00446390: background manager, not a BIB selector. */
        ARITY(2);
        unsigned owner=script->dispatch_context;
        if (owner>=260 || script->backgrounds[owner])
            return fail(script,"repeated native background construction requires another callback registration");
        LL_NativeBackground *background=calloc(1,sizeof(*background));
        if (!background) return fail(script,"cannot allocate native background manager");
        ll_native_background_init(background,args[0],(int16_t)args[1]);
        script->backgrounds[owner]=background;state->background_enabled=1;return 1;
    }
    case 0x123: case 0x124: case 0x125: case 0x126: case 0x128: case 0x12c: {
        LL_NativeBackground *background=script->backgrounds[script->dispatch_context];
        if (!background) return fail(script,"native background command requires its context's manager");
        if (!ll_native_background_command(background,id,args,argc,&script->bib,&script->biz))
            return fail(script,background->error);
        return 1;
    }
    case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xce: case 0xcf: case 0xd0: case 0xda:
        if (!ll_native_audio_control(&script->audio,id,args,argc)) return fail(script,script->audio.error);
        return 1;
    case 0xe8: { /* FUN_004162d0 -> FUN_00456f30: checked, immutable path data. */
        ARITY(1);
        LL_BibPathView path;
        if (!object || !object->pose || !object->root_rotation)
            return fail(script,"path attachment requires a registered model root");
        if (!state->path_capacity)
            return fail(script,"path attachment requires the 0xe6 path registry setup");
        if (state->path_count>=state->path_capacity) return 1; /* Native full registry leaves model unchanged. */
        if (object->path.attached)
            return fail(script,"repeated attachment requires multiple native path callbacks");
        if (!ll_bib_get_path_view(&script->bib,args[0],&path))
            return fail(script,"path selector has a truncated table or out-of-range relative reference");
        for (unsigned i=0;i<path.record_count;i++) {
            LL_BibPathSegment segment;
            if (!ll_bib_get_path_segment(&script->bib,args[0],i,&segment))
                return fail(script,"path segment endpoints exceed the bounded coordinate payload");
            for (unsigned link=0;link<segment.link_count;link++) {
                unsigned target;
                if (!ll_bib_get_path_link(&script->bib,args[0],i,link,&target))
                    return fail(script,"path link does not reference a segment record boundary");
            }
        }
        LL_BibPathAnchor anchor;
        if (!ll_bib_prepare_path_anchor(&script->bib,args[0],object->pose->position,&anchor))
            return fail(script,"path segment selection encountered invalid or degenerate projection data");
        LL_BibPathSegment selected;
        if (!ll_bib_get_path_segment(&script->bib,args[0],anchor.segment_index,&selected))
            return fail(script,"selected path segment is invalid");
        LL_NativePathSegmentState segment_state;
        ll_native_path_segment_reset(selected.start,selected.end,selected.length,&segment_state);
        LL_LevelObjectPath attached={0};
        attached.attached=1;attached.selector=args[0];attached.owner_context=script->dispatch_context;
        attached.segment=anchor.segment_index;attached.distance=anchor.distance;
        attached.yaw=segment_state.yaw;attached.pitch=segment_state.pitch;
        memcpy(attached.previous_position,anchor.position,sizeof(attached.previous_position));
        object->path=attached;
        memcpy(object->pose->position,anchor.position,sizeof(anchor.position));
        object->native_payload_flags=(object->native_payload_flags|0x20u)&~8u;
        state->path_count++;
        return 1;
    }
    case 0x41: { /* FUN_00412f20: screen-sprite root in the native640x480 viewport. */
        ARITY(3);
        if (!object || object->kind!=7 || !object->pose)
            return fail(script,"screen positioning requires a registered screen sprite");
        int32_t x=(int16_t)args[0],y=(int16_t)args[1];
        int16_t projected_x=(int16_t)((uint32_t)(x*640)>>9);
        int16_t projected_y=(int16_t)((uint32_t)(y*480)>>8);
        object->pose->position[0]=projected_x;
        object->pose->position[1]=projected_y;
        object->pose->position[2]=(int16_t)args[2];
        return 1;
    }
    case 0xdd: { /* FUN_00416990: set/clear a sign-extended model payload mask. */
        ARITY(3);
        if (args[0]>=260 || !script->objects[args[0]].present ||
            !script->objects[args[0]].pose || script->objects[args[0]].kind==5 ||
            script->objects[args[0]].kind==7)
            return fail(script,"payload flag setter requires a registered model wrapper");
        uint32_t mask=(uint32_t)(int32_t)(int16_t)args[1];
        if (args[2]) script->objects[args[0]].native_payload_flags|=mask;
        else script->objects[args[0]].native_payload_flags&=~mask;
        return 1;
    }
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
        int32_t position[3];
        for (unsigned i=0;i<3;i++) {
            if (id==0x1a) object->pose->angles[i]=(int16_t)args[i];
            else position[i]=(int16_t)args[i]*100;
        }
        if (id==0x1c) model_position_set(script,object,position);
        if (id==0x1a && object->root_rotation) {
            int16_t rows[3][3];
            ll_native_model_rotation(object->pose->angles,rows);
            memcpy(object->root_rotation,rows,sizeof(rows));
        }
        return 1;
    case 0x18:
        ARITY(4);
        if (!object) return fail(script,"motion setter requires a scene object");
        for (unsigned i=0;i<3;i++) object->motion[i]=(int16_t)args[i];
        object->motion_word=args[3];return 1;
    case 0x19: /* FUN_004104a0: low byte at motion payload+16. */
        ARITY(1);
        if (!object) return fail(script,"bounce direction requires a registered model wrapper");
        object->motion_positive_bounce=(uint8_t)args[0];return 1;
    case 0x2d:
        ARITY(2);
        if (!object) return fail(script,"wrapper flags setter requires a scene object");
        object->wrapper_flags=(uint16_t)((object->wrapper_flags&~4u)|(args[0]?4u:0u));return 1;
    case 0x10:
        ARITY(2);
        if (args[0]<260 && script->objects[args[0]].present)
            object_visibility_set(&script->objects[args[0]],args[1]!=0);
        return 1; /* FUN_004101e0 explicitly ignores absent targets. */
    case 0x15: /* FUN_004195b0 -> FUN_004851b0: release active model animation data. */
        ARITY(1);
        if (object && object->animation_active) {
            uint16_t owner=object->animation_callback_owner;
            if (owner && owner<=script->program.function_count)
                script->contexts[owner-1u].vm.host_animation_wait=0;
            object->animation_active=0;object->animation_callback_owner=0;
        }
        return 1;
    case 0x40: /* FUN_00412c80: ten balls and ten independent muzzle effects. */
        ARITY(2);
        return projectile_pool_initialize(script,args);
    case 0x32: /* FUN_00411800: register the scene-sprite callback manager. */
        ARITY(0);
        state->scene_sprite_capacity=16;
        memset(state->scene_sprite_slots,0,sizeof(state->scene_sprite_slots));
        state->scene_sprite_manager_registered=1;
        return 1;
    case 0xf5: { /* FUN_004165e0: register a bounded collision callback link. */
        ARITY(2);
        if (args[0]>=260 || !script->objects[args[0]].present)
            return fail(script,"collision link target is not a registered wrapper instance");
        if (!object || !object->pose || !object->bounds || object->kind==5 || object->kind==7 ||
            !script->objects[args[0]].pose || !script->objects[args[0]].bounds ||
            script->objects[args[0]].kind==5 || script->objects[args[0]].kind==7 || current==args[0])
            return fail(script,"collision callback requires distinct bounded model wrappers");
        LL_LevelScriptObject *owner=object;
        uint16_t flags=(uint16_t)args[1];
        uint8_t mode=(uint8_t)(flags&7u);
        if (mode>3 && mode!=7) return fail(script,"collision registration mode4..6 has no native callback");
        unsigned slot=3;
        for (unsigned i=0;i<3;i++) {
            if (owner->collision_links[i].active &&
                owner->collision_links[i].target_instance==args[0]) { slot=i;break; }
            if (!owner->collision_links[i].active) { slot=i;break; }
        }
        if (slot==3) return fail(script,"collision callback context has no free link slot");
        LL_LevelCollisionLink *link=&owner->collision_links[slot];
        if (mode==7) {
            if (link->active && (link->flags&0xc0u)) {
                LL_LevelScriptObject *target=&script->objects[link->target_instance];
                if (target->kind==5 || target->kind==7)
                    return fail(script,"collision detach flag cleanup requires a model payload");
                /* FUN_004165e0 clears the callback's effects on the target
                 * payload, preserving every unrelated bit. */
                if (link->flags&0x40u) target->native_payload_flags&=~0x14u;
                if (link->flags&0x80u) target->native_payload_flags&=~0x10028u;
            }
            memset(link,0,sizeof(*link));
            return 1;
        }
        link->active=1;link->target_instance=args[0];
        link->flags=(uint16_t)(flags&0x120u);
        if ((flags&0x18u)==8 || (flags&0x18u)==16) link->flags|=flags&0x18u;
        link->callback_mode=mode;owner->collision_registered=1;
        owner->collision_owner_context=script->dispatch_context;
        return 1;
    }
    case 0x72: { /* FUN_00418620: wrapper+13 suppresses presentation when nonzero. */
        ARITY(2);
        if (args[0]>=260 || !script->objects[args[0]].present)
            return fail(script,"callback toggle requires a registered wrapper");
        LL_LevelScriptObject *target=&script->objects[args[0]];
        if (!args[1] && target->draw_suppressed && target->reduced)
            return fail(script,"resuming a reduced model requires native descriptor expansion");
        target->draw_suppressed=args[1]!=0;
        return 1;
    }
    case 0x96: { /* FUN_0041b970: pose-driven sprite group setup. */
        ARITY(6);
        int registered=0;
        for (unsigned i=0;i<state->pose_count;i++)
            if (state->pose_groups[i]==args[0]) registered=1;
        const unsigned char *record;
        size_t size;
        uint32_t descriptor;
        if (!registered || args[2]>=260 ||
            !ll_bib_get_indexed_record(&script->bib,args[0],args[1],&record,&size) || size<4)
            return fail(script,"sprite group requires a registered BIB group and bounded record");
        unsigned count=(unsigned)record[0]|((unsigned)record[1]<<8);
        if (!count || count>64 || size<4u+16u*count)
            return fail(script,"sprite group position record is truncated or exceeds 64 members");
        if (!ll_bib_get_selector_offset(&script->bib,args[4],&descriptor))
            return fail(script,"sprite group resource selector is invalid");
        LL_LevelScriptObject sprite={0};
        sprite.kind=5;sprite.sprite_selector=args[4];sprite.sprite_scale=(int16_t)args[3];
        if (!sprite_frame_apply(script,&sprite,0))
            return fail(script,"sprite group needs a valid first BIB frame and BIZ texture");
        LL_BizSprite resource;
        if (!ll_biz_get_sprite(&script->biz,sprite.biz_sprite,&resource))
            return fail(script,"sprite group first texture is invalid");
        sprite_bounds_apply(&sprite,&resource,1); /* Native486410 constructor extent is retained in Z. */
        if (!sprite_frame_apply(script,&sprite,0)) return fail(script,"sprite group frame is invalid");
        LL_LevelScriptObject *members=calloc(count,sizeof(*members));
        if (!members) return fail(script,"cannot allocate sprite group members");
        LL_LevelOrbitalGroup *group=&script->orbital_groups[args[2]];
        if (!group->present) script->orbital_group_count++;
        free(group->sprites);
        memset(group,0,sizeof(*group));
        group->sprites=members;
        group->present=1;group->callback_registered=1;group->native_byte_2=1;
        group->wrapper_instance=args[2];group->model_index=UINT16_MAX;
        group->model_selector=args[4];group->descriptor_offset=descriptor;
        group->member_count=(uint16_t)count;group->scale=(int16_t)args[3];
        group->member_parameter=args[5];group->has_member_positions=1;
        memset(group->member_active,1,count);
        memset(group->member_visible,1,count);
        group->has_sprite_bounds=1;group->biz_object=sprite.biz_object;
        group->biz_sprite=sprite.biz_sprite;
        memcpy(group->sprite_bounds,sprite.private_bounds,sizeof(group->sprite_bounds));
        for (unsigned member=0;member<count;member++)
            for (unsigned axis=0;axis<3;axis++) {
                const unsigned char *p=record+4u+16u*member+4u*axis;
                uint32_t word=(uint32_t)p[0]|((uint32_t)p[1]<<8)|
                    ((uint32_t)p[2]<<16)|((uint32_t)p[3]<<24);
                memcpy(&group->member_positions[member][axis],&word,sizeof(word));
            }
        memcpy(group->member_roots,group->member_positions,sizeof(group->member_roots));
        for (unsigned m=0;m<count;m++) {
            members[m]=sprite;members[m].present=1;
            members[m].bounds=members[m].private_bounds;members[m].pose=&members[m].private_pose;
            memcpy(members[m].pose->position,group->member_roots[m],sizeof(group->member_roots[m]));
            group->member_started[m]=animation_clock(script->updates)>>5;
        }
        return 1;
    }
    case 0x97: { /* FUN_0041be30: position members relative to their saved origins. */
        ARITY(4);
        if (args[0]>=260)
            return fail(script,"sprite group translation instance exceeds registry bounds");
        LL_LevelOrbitalGroup *group=&script->orbital_groups[args[0]];
        if (!group->present) {
            if (script->objects[args[0]].present)
                return fail(script,"sprite group translation target is an ordinary wrapper");
            return 1; /* Native absent-wrapper lookup is explicitly ignored. */
        }
        if (!group->has_member_positions || group->member_count>64)
            return fail(script,"sprite group translation requires decoded member origins");
        for (unsigned member=0;member<group->member_count;member++)
            for (unsigned axis=0;axis<3;axis++) {
                /* Preserve x86 32-bit addition without signed C overflow.
                 * Native offsets are raw units; they are not multiplied by100.
                 * Saved positions stay fixed across repeated calls. */
                uint32_t word=(uint32_t)group->member_positions[member][axis]+
                    (uint32_t)(int32_t)(int16_t)args[axis+1];
                memcpy(&group->member_roots[member][axis],&word,sizeof(word));
                if (group->sprites) group->sprites[member].pose->position[axis]=group->member_roots[member][axis];
            }
        return 1;
    }
    case 0x39: { /* FUN_004121d0: configure an orbital sprite-group wrapper. */
        ARITY(10);
        if (!args[3] || args[3]>64 || args[9]>=260)
            return fail(script,"orbital group needs 1..64 members and wrapper instance0..259");
        uint32_t descriptor_offset;
        if (!ll_bib_get_selector_offset(&script->bib,args[0],&descriptor_offset))
            return fail(script,"orbital group selector is outside the bounded BIB selector table");
        unsigned model=0;
        while (model<script->bib.model_count &&
               script->bib.models[model].descriptor_offset!=descriptor_offset) model++;
        LL_LevelOrbitalGroup *group=&script->orbital_groups[args[9]];
        if (!group->present) {
            if (script->orbital_group_count>=260)
                return fail(script,"orbital group registry is full");
            script->orbital_group_count++;
        }
        free(group->sprites);memset(group,0,sizeof(*group));
        group->present=1;group->callback_registered=1;
        group->wrapper_instance=args[9];
        group->model_index=(uint16_t)(model<script->bib.model_count?model:UINT16_MAX);
        group->model_selector=args[0];group->member_count=args[3];
        group->scale=(int16_t)args[1];group->member_parameter=args[2];
        group->group_parameter=args[4];group->extra_parameter=args[8];
        group->angle_step=(int16_t)(360u/args[3]);
        group->descriptor_offset=descriptor_offset;
        for (unsigned axis=0;axis<3;axis++)
            group->center[axis]=(int32_t)(int16_t)args[5u+axis]*100;
        return 1;
    }
    case 0x4e: { /* FUN_00413eb0: set the orbital wrapper's native byte at+2. */
        ARITY(1);
        LL_LevelOrbitalGroup *group=NULL;
        for (unsigned i=0;i<260;i++) {
            if (script->orbital_groups[i].present &&
                script->orbital_groups[i].wrapper_instance==script->dispatch_context) {
                group=&script->orbital_groups[i];break;
            }
        }
        if (!group)
            return fail(script,"orbital group byte setter requires its preceding 0x39 setup");
        group->native_byte_2=(uint8_t)args[0];
        return 1;
    }
    case 0x53: { /* FUN_00412540: set four words on this orbital group. */
        ARITY(4);
        LL_LevelOrbitalGroup *group=NULL;
        for (unsigned i=0;i<260;i++) {
            if (script->orbital_groups[i].present &&
                script->orbital_groups[i].wrapper_instance==script->dispatch_context) {
                group=&script->orbital_groups[i];break;
            }
        }
        if (!group)
            return fail(script,"orbital group word setter requires its preceding 0x39 setup");
        for (unsigned i=0;i<4;i++) group->native_words[i]=args[i];
        return 1;
    }
    case 0x7a: { /* FUN_00419fc0/00419a50: parent part, child wrapper, child part, mode. */
        ARITY(4);
        if (args[3]!=2 && args[3]!=12)
            return fail(script,"skeletal attachment mode requires an unported matrix callback");
        uint16_t parent=script->contexts[script->dispatch_context].instance;
        uint16_t child=args[1]; /* Native global wrapper table, not a SOOL context binding. */
        if (parent>=260 || child>=260 || parent==child ||
            !script->objects[parent].present || !script->objects[child].present ||
            !script->objects[parent].pose || !script->objects[child].pose ||
            script->objects[parent].kind!=1 || script->objects[child].kind!=1)
            return fail(script,"skeletal attachment requires two registered model wrappers");
        if (skeletal_attachment(script,child))
            return fail(script,"skeletal child must be detached before another attachment");
        unsigned ancestor=parent;
        for (unsigned depth=0;depth<260;depth++) {
            LL_LevelSkeletalAttachment *link=skeletal_attachment(script,ancestor);
            if (!link) break;
            ancestor=link->parent_instance;
            if (ancestor==child || depth==259) return fail(script,"skeletal attachment would form a cycle");
        }
        int16_t parent_pivot[3],child_pivot[3];
        if (!attachment_pivot(script,&script->objects[parent],args[0],parent_pivot) ||
            ((int16_t)args[2]>0 && !attachment_pivot(script,&script->objects[child],args[2],child_pivot)))
            return fail(script,"skeletal attachment references an invalid original part pivot");
        if (script->skeletal_attachment_count>=256)
            return fail(script,"skeletal attachment registry is full");
        LL_LevelSkeletalAttachment *attachment=&script->skeletal_attachments[script->skeletal_attachment_count++];
        memset(attachment,0,sizeof(*attachment));
        attachment->child_instance=child;attachment->parent_instance=parent;
        attachment->owner_context=script->dispatch_context;
        attachment->parent_part=args[0];attachment->child_part=args[2];attachment->attachment_mode=2;
        memcpy(attachment->root_rotation,script->objects[child].root_rotation,sizeof(attachment->root_rotation));
        if (args[3]<10) for (unsigned axis=0;axis<3;axis++)
            attachment->root_offset[axis]=path_wrapped((uint32_t)script->objects[child].pose->position[axis]-
                (uint32_t)(int32_t)parent_pivot[axis]-(uint32_t)script->objects[parent].pose->position[axis]);
        /* FUN_00419c90 installs parent/child part selectors, not blend settings. */
        state->animation_transition[0]=(int16_t)args[0];
        state->animation_transition[1]=-1;
        state->animation_transition[2]=(int16_t)args[2];
        state->animation_transition[3]=-1;
        state->animation_transition[4]=2;
        return 1;
    }
    case 0x7b: { /* FUN_0041a050/00486d00: detach, retain last world root and orientation. */
        ARITY(1);
        if (args[0]>=260 || !script->objects[args[0]].present || !object)
            return fail(script,"skeletal detach requires registered parent and child wrappers");
        LL_LevelScriptObject *child=&script->objects[args[0]];
        if (!child->pose || !child->root_rotation || child->kind!=1)
            return fail(script,"skeletal detach requires a skeletal child root");
        LL_LevelSkeletalAttachment *attachment=skeletal_attachment(script,args[0]);
        if (attachment && attachment->parent_instance!=current)
            return fail(script,"skeletal detach parent does not own this child");
        if (attachment) {
            unsigned index=(unsigned)(attachment-script->skeletal_attachments);
            memmove(attachment,attachment+1,(script->skeletal_attachment_count-index-1u)*sizeof(*attachment));
            script->skeletal_attachment_count--;
        }
        memcpy(child->root_rotation,child->attachment_rotation,sizeof(child->attachment_rotation));
        child->native_callback_enabled=1;return 1;
    }
    case 0x15e: { /* FUN_0041d240 -> FUN_00454d50: transition to a followed root. */
        ARITY(6);
        if (state->camera_lock==1) return 1;
        if (args[0]>=260 || !script->objects[args[0]].present) return 1;
        if (state->camera_vertical_mode==0 || state->camera_vertical_mode==3)
            return fail(script,"camera transition vertical mode requires unported terrain-height queries");
        LL_LevelNativeSetup saved=*state;
        if (saved.camera_clamp_active) saved.camera_lookat[0]=saved.camera_clamp_target_x;
        if (!command(script,0x137,args,5)) return 0;
        LL_LevelNativeSetup prepared=*state;
        prepared.camera_lead_offset=saved.camera_lead_offset;
        prepared.camera_motion_mode=saved.camera_motion_mode;
        prepared.camera_follow_yaw=saved.camera_follow_yaw;
        if (saved.camera_clamp_active) prepared.camera_clamp_active=0;
        *state=saved;
        unsigned speed=(uint32_t)(int32_t)(int16_t)args[5];
        if (speed>200) speed=200;
        if (speed<10) speed=10;
        unsigned ticks=205u-speed;
        for (unsigned i=0;i<3;i++) {
            uint32_t delta=(uint32_t)prepared.camera_follow_reference[i]-(uint32_t)saved.camera_follow_reference[i];
            int32_t fixed=path_wrapped(delta<<12)/(int32_t)ticks;
            prepared.camera_reference_step[i]=fixed>=0?fixed/4096:(int32_t)(-((-(int64_t)fixed+4095)/4096));
            delta=(uint32_t)prepared.camera_follow_target[i]-(uint32_t)saved.camera_lookat[i];
            fixed=path_wrapped(delta<<12)/(int32_t)ticks;
            prepared.camera_lookat_step[i]=fixed>=0?fixed/4096:(int32_t)(-((-(int64_t)fixed+4095)/4096));
        }
        memcpy(prepared.camera_follow_reference,saved.camera_follow_reference,sizeof(saved.camera_follow_reference));
        memcpy(prepared.camera_lookat,saved.camera_lookat,sizeof(saved.camera_lookat));
        prepared.camera_transition_remaining=(uint16_t)ticks;prepared.camera_transition_complete=0;
        prepared.camera_transition_target=args[0];prepared.camera_transition_active=1;
        prepared.camera_transition_absolute=0;
        *state=prepared;return 1;
    }
    case 0x160: { /* FUN_0041d680/0041d430 ->004547b0: absolute position/angle transition. */
        ARITY(6);
        if (state->camera_lock==1) return 1;
        int32_t destination[3];
        for (unsigned axis=0;axis<3;axis++) {
            int32_t value=(int32_t)(int16_t)args[axis]*100;
            int32_t minimum=axis<2?state->camera_bounds[axis*2]:state->camera_z_bounds[0];
            int32_t maximum=axis<2?state->camera_bounds[axis*2+1]:state->camera_z_bounds[1];
            if (value>maximum) value=maximum;
            if (value<minimum) value=minimum;
            destination[axis]=value;
        }
        int pitch=(int16_t)args[3],yaw=(int16_t)args[4];
        if (pitch>800) pitch=800;
        if (pitch< -800) pitch=-800;
        if (yaw>1600) yaw=1600;
        if (yaw< -1600) yaw=-1600;
        if (state->camera_side==2) yaw=(int16_t)(yaw+state->camera_side_yaw);
        uint32_t speed=(uint32_t)(int32_t)(int16_t)args[5];
        if (speed>200) speed=200;
        if (speed<10) speed=10;
        uint32_t ticks=205u-speed;
        /* 41d430 consumes the retained look-ahead once before deriving steps. */
        state->camera_follow_reference[0]=path_wrapped((uint32_t)state->camera_follow_reference[0]+(uint32_t)state->camera_lead_offset);
        state->camera_lead_offset=0;
        for (unsigned axis=0;axis<3;axis++) {
            uint32_t delta=(uint32_t)destination[axis]-(uint32_t)state->camera_follow_reference[axis];
            int32_t divided=path_wrapped(delta<<12)/(int32_t)ticks;
            state->camera_reference_step[axis]=wrapped_shift((uint32_t)divided,12);
        }
        const int16_t current[2]={state->camera_follow_pitch,state->camera_follow_yaw};
        const int16_t desired[2]={(int16_t)pitch,(int16_t)yaw};
        for (unsigned axis=0;axis<2;axis++) {
            uint32_t delta=(uint32_t)(int32_t)desired[axis]-(uint32_t)(int32_t)current[axis];
            state->camera_angle_step[axis]=path_wrapped(delta<<12)/(int32_t)ticks;
            state->camera_angle_fixed[axis]=path_wrapped((uint32_t)(int32_t)current[axis]<<12);
        }
        memcpy(state->camera_lookat,destination,sizeof(destination));
        state->camera_follow_instance_plus_one=0;state->camera_transition_target=0;
        state->camera_transition_remaining=(uint16_t)ticks;state->camera_transition_complete=0;
        state->camera_transition_active=state->camera_transition_absolute=1;
        state->camera_callback_enabled=state->camera_reference_active=1;
        return 1;
    }
    case 0x15f: { /* FUN_0041d370: unsigned depth target and per-callback step. */
        ARITY(2);
        if (state->camera_lock==1) return 1;
        uint32_t depth=(uint32_t)(int32_t)(int16_t)args[0];
        uint32_t step=(uint32_t)(int32_t)(int16_t)args[1];
        state->camera_depth_target=depth>10000?10000:depth<1500?1500:depth;
        state->camera_depth_step=step>500?500:step<50?50:step;
        state->camera_depth_transition=1;return 1;
    }
    case 0x161: /* FUN_0041d190: signed bounds targets and unclamped step. */
        ARITY(5);
        if (state->camera_lock==1) return 1;
        for (unsigned axis=0;axis<4;axis++) state->camera_bounds_target[axis]=(int32_t)(int16_t)args[axis]*100;
        state->camera_bounds_step=(int16_t)args[4];state->camera_bounds_transition=1;
        return 1;
    case 0x136: { /* FUN_0041c670 -> FUN_0041c3e0: absolute camera reference. */
        ARITY(5);
        if (state->camera_lock==1) return 1;
        int32_t reference[3];
        for (unsigned i=0;i<3;i++) reference[i]=(int32_t)(int16_t)args[i]*100;
        for (unsigned axis=0;axis<2;axis++) {
            if (reference[axis]>state->camera_bounds[axis*2+1])
                reference[axis]=state->camera_bounds[axis*2+1];
            if (reference[axis]<state->camera_bounds[axis*2])
                reference[axis]=state->camera_bounds[axis*2];
        }
        int pitch=(int16_t)args[3];if (pitch>800) pitch=800;if (pitch< -800) pitch=-800;
        int yaw=(int16_t)args[4];if (yaw>1600) yaw=1600;if (yaw< -1600) yaw=-1600;
        if (state->camera_side==2) yaw=(int16_t)(yaw+state->camera_side_yaw);
        if (yaw== -1024) yaw=-1023;
        int cx=ll_native_cosine((int16_t)yaw),cy=ll_native_cosine((int16_t)pitch);
        if (!cx || !cy) return fail(script,"absolute camera angle causes native tangent division by zero");
        int tx=(ll_native_sine((int16_t)yaw)*4096)/cx;
        int ty=(ll_native_sine((int16_t)pitch)*-4096)/cy;
        int32_t px=path_wrapped((uint32_t)tx*state->camera_follow_distance);
        int32_t py=path_wrapped((uint32_t)ty*state->camera_follow_distance);
        int32_t ox=px>=0?px/4096:(int32_t)(-((-(int64_t)px+4095)/4096));
        int32_t oy=py>=0?py/4096:(int32_t)(-((-(int64_t)py+4095)/4096));
        int32_t target[3];memcpy(target,reference,sizeof(target));
        target[0]=path_wrapped((uint32_t)target[0]-(uint32_t)ox);
        target[1]=path_wrapped((uint32_t)target[1]-(uint32_t)oy);
        uint32_t distance=state->camera_follow_distance;
        target[2]=path_wrapped((uint32_t)target[2]+(state->camera_side==2?0u-distance:distance));
        memcpy(state->camera_follow_reference,reference,sizeof(reference));
        memcpy(state->camera_lookat,target,sizeof(target));
        state->camera_follow_pitch=(int16_t)pitch;state->camera_follow_yaw=(int16_t)yaw;
        state->camera_follow_instance_plus_one=0;state->camera_reference_active=1;
        state->camera_lead_offset=0;
        state->camera_transition_active=0;state->camera_callback_enabled=1;
        return 1;
    }
    case 0x137: { /* FUN_0041c6f0: initialize camera-follow reference. */
        ARITY(5);
        if (state->camera_lock==1) return 1;
        if (args[0]>=260 || !script->objects[args[0]].present) return 1;
        const LL_LevelScriptObject *target=&script->objects[args[0]];
        if (!target->pose) return fail(script,"camera follow target has no registered root");
        uint32_t distance=(uint32_t)(int32_t)(int16_t)args[3];
        if (distance>30000) distance=30000;
        if (!distance) distance=1;
        int height=(int16_t)args[4];if (height>6000) height=6000;if (height< -6000) height=-6000;
        int pitch=(int16_t)args[1];if (pitch>800) pitch=800;if (pitch< -800) pitch=-800;
        int yaw=(int16_t)args[2];if (yaw>1600) yaw=1600;if (yaw< -1600) yaw=-1600;
        if (state->camera_side==2) yaw+=state->camera_side_yaw;
        if (yaw== -1024) yaw=-1023;
        int cosine_yaw=ll_native_cosine((int16_t)yaw);
        int cosine_pitch=ll_native_cosine((int16_t)pitch);
        if (!cosine_yaw || !cosine_pitch)
            return fail(script,"camera follow angle causes native tangent division by zero");
        int32_t reference[3],follow_target[3];
        memcpy(follow_target,target->pose->position,sizeof(follow_target));
        follow_target[1]=path_wrapped((uint32_t)follow_target[1]+(uint32_t)height);
        memcpy(reference,follow_target,sizeof(reference));
        reference[2]=path_wrapped((uint32_t)reference[2]+(state->camera_side==2?distance:0u-distance));
        int tangent_y=(ll_native_sine((int16_t)pitch)*-4096)/cosine_pitch;
        int tangent_x=(ll_native_sine((int16_t)yaw)*4096)/cosine_yaw;
        int32_t product_y=path_wrapped((uint32_t)tangent_y*distance);
        int32_t product_x=path_wrapped((uint32_t)tangent_x*distance);
        int32_t offset_y=product_y>=0?product_y/4096:(int32_t)(-((-(int64_t)product_y+4095)/4096));
        int32_t offset_x=product_x>=0?product_x/4096:(int32_t)(-((-(int64_t)product_x+4095)/4096));
        reference[0]=path_wrapped((uint32_t)reference[0]+(uint32_t)offset_x);
        reference[1]=path_wrapped((uint32_t)reference[1]+(uint32_t)offset_y);
        state->camera_follow_instance_plus_one=(uint16_t)(args[0]+1u);
        state->camera_follow_distance=distance;state->camera_follow_height=(int16_t)height;
        state->camera_follow_pitch=(int16_t)pitch;
        memcpy(state->camera_follow_target,follow_target,sizeof(follow_target));
        memcpy(state->camera_follow_reference,reference,sizeof(reference));
        state->camera_reference_active=1;
        state->camera_transition_active=0;state->camera_callback_enabled=1;
        state->camera_lead_offset=0;
        if (state->camera_motion_mode<2 || state->camera_motion_mode>5) state->camera_motion_mode=0;
        return 1;
    }
    case 0x11e: { /* FUN_004156c0: retain a BIB pose for player reset (0x48). */
        ARITY(2);
        LL_BibScenePose target;
        if (!ll_bib_get_scene_pose(&script->bib,args[0],args[1],&target))
            return 1; /* Native lookup failure leaves the previous reset position intact. */
        memcpy(state->player_reset_position,target.position,sizeof(state->player_reset_position));
        state->player_reset_position_active=1;
        return 1;
    }
    case 0x48: { /* FUN_00413580 ->00457740/00452f50: return to the script checkpoint. */
        ARITY(1);
        if (args[0]) {
            if (state->player_lives<=0) return fail(script,"original game-over scene is not implemented");
            state->level_event_latch=0;state->native_flags&=0xfffau;
            if (state->player_instance_plus_one && state->player_instance_plus_one<=260)
                script->objects[state->player_instance_plus_one-1u].native_payload_flags&=~0x100u;
            script->scene_requested=script->scene_reload=1;return 1;
        }
        if (state->player_lives<=0) return fail(script,"original game-over scene is not implemented");
        unsigned registered=state->player_instance_plus_one;
        if (!registered || registered>260 || !script->objects[registered-1u].present)
            return fail(script,"player reset requires the registered native wrapper");
        LL_LevelScriptObject *target=&script->objects[registered-1u];
        LL_BibPathAnchor anchor;
        LL_BibPathSegment segment;
        if (state->player_reset_position_active && (!target->pose || !target->path.attached ||
            !ll_bib_prepare_path_anchor(&script->bib,target->path.selector,state->player_reset_position,&anchor) ||
            !ll_bib_get_path_segment(&script->bib,target->path.selector,anchor.segment_index,&segment)))
            return fail(script,"player reset requires the checkpoint's native path anchor");
        state->level_event_latch=0;
        state->native_flags&=0xfffau;target->native_payload_flags&=~0x100u;
        if (state->player_reset_position_active) {
            target->path.segment=anchor.segment_index;target->path.distance=anchor.distance;
            LL_NativePathSegmentState orientation;
            ll_native_path_segment_reset(segment.start,segment.end,segment.length,&orientation);
            target->path.yaw=orientation.yaw;target->path.pitch=orientation.pitch;
            target->path.flags&=~1u;target->native_payload_flags|=0x20u;
            target->native_payload_flags&=~8u;
            memcpy(target->pose->position,anchor.position,sizeof(anchor.position));
            memcpy(target->path.previous_position,anchor.position,sizeof(anchor.position));
            /* 452f50 resets camera mode bytes and the dead-camera lock. The
             * original script immediately supplies its restored follow root. */
            state->camera_lock=0;state->camera_vertical_mode=1;
        }
        script->player.yaw=target->path.yaw;
        static const unsigned hud_slots[4]={0,3,4,1};
        for (unsigned i=0;i<4;i++) {
            unsigned wrapper=state->object_registry[hud_slots[i]];
            if (wrapper && wrapper<=260 && script->objects[wrapper-1u].present)
                script->objects[wrapper-1u].visible=1;
        }
        return 1;
    }
    case 0x4d: /* FUN_00413a80: only the low byte controls pause availability. */
        ARITY(1);state->pause_enabled=(uint8_t)args[0];return 1;
    case 0x10e: /* FUN_00415080 ->00440f30/70: primary display fade. */
        ARITY(1);state->fade_direction=(uint8_t)(args[0]?1:2);
        state->fade_alpha=(uint8_t)(args[0]?255:0);return 1;
    case 0x12d: /* FUN_00415980: background primitive manager enable byte. */
        ARITY(1);state->background_enabled=(uint8_t)args[0];return 1;
    case 0xd5: /* FUN_00417710/004200e0: pause the CD device; no track is opened here. */
        ARITY(1);state->cd_paused=(uint8_t)args[0];return 1;
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
    case 0x05: case 0x08: case 0x0b: case 0x14: case 0x1b: { /* Native skeletal animation scheduler. */
        ARITY(id==0x14?3:1);
        if (!object || !object->pose || object->kind==5 || object->kind==7)
            return fail(script,"skeletal animation requires a registered model instance");
        if (id==0x08 && !object->animation_pose_present)
            return fail(script,"nonblocking skeletal animation requires an existing native animation buffer");
        uint16_t selector=args[0];
        const LL_BibAnimationTable *table=ll_bib_get_animation_table(&script->bib,selector);
        if (!table || !table->record_count || !table->record_type)
            return fail(script,"animation selector has no bounded frame table");
        uint16_t first=0,last=(uint16_t)(table->record_count-1u);
        if (id==0x05) { first=last;last=0; }
        if (id==0x14) {
            first=args[1];last=args[2];
            if (last==UINT16_MAX) last=(uint16_t)(table->record_count-1u);
            if (first>last || last>=table->record_count)
                return fail(script,"animation range is outside the bounded frame table");
        }
        uint8_t motion_enabled,motion_axis;int32_t motion_reference;
        if (!animation_motion_prepare(script,object,table,first,&motion_enabled,&motion_axis,&motion_reference)) return 0;
        object->animation_started=animation_clock(script->updates);
        object->animation_frame=first;
        object->animation_next_frame=id==0x05 ? (first?(uint16_t)(first-1u):first) :
            (first<last ? (uint16_t)(first+1u) : first);
        object->animation_fraction=0;
        object->animation_root_motion=motion_enabled;object->animation_root_axis=motion_axis;
        object->animation_motion_reference=motion_reference;object->animation_motion_cycles=0;
        object->animation_motion_owner=script->dispatch_context;
        object->animation_selector=selector;object->animation_first=first;
        object->animation_last=last;object->animation_active=1;object->animation_pose_present=1;
        object->animation_reverse=(uint8_t)(id==0x05);
        object->animation_once=(uint8_t)(id==0x08 || id==0x0b || id==0x14);
        LL_LevelScriptContext *owner=&script->contexts[script->dispatch_context];
        if (object->animation_once) {
            object->animation_callback_owner=(uint16_t)(script->dispatch_context+1u);
            owner->vm.host_animation_wait=(uint8_t)(id!=0x08);
            if (id!=0x08) owner->vm.host_yield=1;
        } else owner->vm.host_animation_wait=0;
        return 1;
    }
    case 0x6a: /* 41b930/41b880/485d00: sprite sequence argument is unused for kinds5/7. */
        ARITY(1);
        if (!object || (object->kind!=5 && object->kind!=7))
            return fail(script,"model sequence release through6A is not ported");
        object->sprite_animation_active=object->sprite_animation_owner=0;
        object->sprite_primitives_present=0;
        if (object->kind==5) object_visibility_set(object,0);
        return 1;
    case 0x42: { /* FUN_00412fe0 -> FUN_004856f0: fixed frame, existing scale. */
        ARITY(2);
        if (!object || (object->kind!=5 && object->kind!=7))
            return fail(script,"fixed sprite frame requires a registered sprite wrapper");
        if (object->sprite_animation_owner)
            return fail(script,"fixed frame replacement during a completion wait is not implemented");
        LL_LevelScriptObject prepared=*object;
        prepared.sprite_selector=args[0];
        if (!sprite_frame_apply(script,&prepared,args[1]))
            return fail(script,"fixed sprite frame references an invalid BIB/BIZ record");
        prepared.sprite_animation_first=args[1];prepared.sprite_animation_last=args[1];
        prepared.sprite_animation_active=0;prepared.sprite_animation_once=0;
        *object=prepared;
        if (object->kind==5) object->bounds=object->private_bounds;
        return 1;
    }
    case 0x69: case 0x74: { /* 41b530/41b650: identical bounded sprite sequence completion waits. */
        ARITY(5);
        LL_BibSelector section;
        if (!object || (object->kind!=5 && object->kind!=7) || args[1]!=0 ||
            !ll_bib_get_selector(&script->bib,args[0],&section) || !section.is_section || section.size<12)
            return fail(script,"waiting sprite sequence requires a sprite and supported resource mode0");
        const unsigned char *header=script->bib.raw_data+section.offset;
        unsigned count=(unsigned)header[2]|((unsigned)header[3]<<8);
        unsigned first=args[3],length=(int16_t)args[4]>0?args[4]:0;
        if (!count || first>=count || (length && length>count-first))
            return fail(script,"waiting sprite sequence range exceeds its BIB frames");
        uint16_t setup[3]={args[0],args[1],args[2]};
        if (!command(script,0x6b,setup,3)) return 0;
        object->sprite_animation_first=(uint16_t)first;
        object->sprite_animation_last=(uint16_t)(length?first+length-1:count-1);
        object->sprite_animation_once=1;
        object->sprite_animation_owner=(uint16_t)(script->dispatch_context+1u);
        sprite_frame_apply(script,object,(uint16_t)first);
        script->contexts[script->dispatch_context].vm.host_animation_wait=1;
        script->contexts[script->dispatch_context].vm.host_yield=1;
        return 1;
    }
    case 0x6b: { /* FUN_0041b740: restart the full BIB sequence on a sprite. */
        ARITY(3);
        if (!object || (object->kind!=5 && object->kind!=7))
            return fail(script,"BIB sequence command requires a world or screen sprite");
        LL_BibSelector section;
        LL_LevelScriptObject prepared=*object;
        prepared.sprite_selector=args[0];
        prepared.sprite_scale=(int16_t)args[2];
        if (!ll_bib_get_selector(&script->bib,args[0],&section) || !section.is_section ||
            section.size<12u || !sprite_frame_apply(script,&prepared,(uint16_t)0)) {
            return fail(script,"BIB sprite sequence lacks a bounded frame header or BIZ record");
        }
        const unsigned char *header=script->bib.raw_data+section.offset;
        uint16_t frame_count=(uint16_t)(header[2]|((uint16_t)header[3]<<8));
        if (!frame_count || frame_count>(section.size-12u)/12u) {
            return fail(script,"BIB sprite sequence frame count exceeds its section");
        }
        for (unsigned frame=0;frame<frame_count;frame++) {
            LL_BibSpriteFrame entry;
            LL_BizObject resource;
            LL_BizSprite texture;
            if (!ll_bib_get_sprite_frame(&script->bib,args[0],frame,&entry) ||
                !ll_biz_get_object(&script->biz,entry.object_index,&resource) ||
                !ll_biz_get_sprite(&script->biz,resource.sprite_index,&texture)) {
                snprintf(script->error,sizeof(script->error),
                    "sprite sequence selector%u frame%u has an invalid BIB/BIZ reference",
                    args[0],frame);
                return 0;
            }
        }
        *object=prepared;
        if (object->kind==5) object->bounds=object->private_bounds;
        object->sprite_animation_first=0;
        object->sprite_animation_once=0;object->sprite_animation_owner=0;
        object->sprite_animation_last=(uint16_t)(frame_count-1u);
        object->sprite_animation_started=animation_clock(script->updates)>>5;
        object->sprite_animation_active=1;object->sprite_scale=(int16_t)args[2];
        object->native_wrapper_word=(uint16_t)((object->native_wrapper_word&0xff00u)|1u);
        object->visible=1;
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
        memcpy(player->private_root_rotation,script->model_rotations[model],sizeof(player->private_root_rotation));
        player->root_rotation=player->private_root_rotation;
        player->private_material=script->model_materials[model];
        player->material=&player->private_material;
        memcpy(player->attachment_rotation,script->bib.models[model].orientation,sizeof(player->attachment_rotation));
        memcpy(player->private_bounds,script->model_bounds[model],sizeof(player->private_bounds));
        player->bounds=player->private_bounds;player->wrapper_flags=3;
        player->visible=1;player->update_enabled=1;player->native_callback_enabled=1;
        state->player_instance_plus_one=(uint16_t)(instance+1u);
        memset(&script->player,0,sizeof(script->player));
        script->player.present=1;script->player.owner_context=script->dispatch_context;
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
        created->sprite_primitives_present=1;
        if (created->kind==5) sprite_bounds_apply(created,&sprite_record,1);
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
        memcpy(object->private_root_rotation,script->model_rotations[model],sizeof(object->private_root_rotation));
        object->root_rotation=object->cloned ? object->private_root_rotation : script->model_rotations[model];
        object->private_material=(LL_NativeMaterial){256,1}; /* 418160 resets +54. */
        object->material=object->cloned ? &object->private_material : &script->model_materials[model];
        memcpy(object->attachment_rotation,script->bib.models[model].orientation,sizeof(object->attachment_rotation));
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
        *script->objects[instance].pose=pose;
        if (script->objects[instance].root_rotation) {
            int16_t rows[3][3];
            ll_native_model_rotation(pose.angles,rows);
            memcpy(script->objects[instance].root_rotation,rows,sizeof(rows));
        }
        return 1;
    }
    case 0xb9: { /* FUN_00416120/00416040: scheduler/cleanup and camera defaults. */
        ARITY(0);
        script->skeletal_attachment_count=0;
        for (unsigned i=0;i<260;i++) { free(script->backgrounds[i]);script->backgrounds[i]=NULL; }
        ll_native_pause_reset(&script->pause);
        for (unsigned i=0;i<260;i++) {
            LL_LevelScriptObject *owner=&script->objects[i];
            for (unsigned slot=0;slot<3;slot++) {
                LL_LevelCollisionLink *link=&owner->collision_links[slot];
                if (link->active && link->target_instance<260) {
                    LL_LevelScriptObject *target=&script->objects[link->target_instance];
                    if (link->flags&0x40u) target->native_payload_flags&=~0x14u;
                    if (link->flags&0x80u) target->native_payload_flags&=~0x10028u;
                }
            }
            memset(owner->collision_links,0,sizeof(owner->collision_links));
            owner->collision_registered=owner->collision_blocked=0;owner->collision_error[0]=0;
        }
        LL_LevelNativeSetup preserved=*state;
        memset(state,0,sizeof(*state));
        state->native_word_44=3;state->player_lives=preserved.player_lives;
        state->force_full_display=preserved.force_full_display;
        state->player_health_dirty=preserved.player_health_dirty;state->player_invincible=preserved.player_invincible;
        /* 474970 clears dynamite and restores health; money/cards persist. */
        state->player_money=preserved.player_money;state->player_cards=preserved.player_cards;
        state->dynamite_dirty=preserved.dynamite_dirty;state->money_dirty=preserved.money_dirty;
        state->cards_dirty=preserved.cards_dirty;state->money_timer=preserved.money_timer;
        state->control_profile=preserved.control_profile;
        state->saved_control_profile=preserved.saved_control_profile;
        state->previous_control_profile=preserved.previous_control_profile;
        state->initialized=1;state->callback_capacity=250;
        state->world_cell=0x137;state->depth=6000;
        state->camera_speed=512;state->camera_word=80;
        state->camera_limit=100;
        state->camera_follow_distance=4000;state->camera_follow_pitch=80;
        state->camera_follow_height=-1500;state->camera_vertical_mode=1;
        state->camera_lead_range=2000;state->camera_side_direction=1;
        state->camera_lookat[1]=state->camera_follow_target[1]=-1500;
        state->camera_lookat[2]=state->camera_follow_target[2]=4000;
        state->camera_z_bounds[0]=-800000;state->camera_z_bounds[1]=800000;
        state->camera_transition_complete=1;
        return 1;
    }
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
        ARITY(0);state->path_capacity=10;state->path_count=0;return 1;
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
            state->camera_callback_enabled=1;state->camera_transition_active=0;
            state->camera_motion_mode=args[0]<=1?0:args[0];
            if (args[0]<=1) state->camera_lead_enabled=(uint8_t)(args[0]!=0);
            int speed=(int16_t)args[1];
            state->camera_speed=(int16_t)(speed<128?128:speed>1023?1023:speed);
        } else if (args[0]==6) {
            state->camera_callback_enabled=0;state->camera_transition_active=0;
        } else if (args[0]==9) return fail(script,"editor camera callback is not implemented");
        return 1;
    case 0x13c: /* FUN_0041cbe0 */
        ARITY(4);
        if (state->camera_lock!=1) {
            for (unsigned i=0;i<4;i++) state->camera_bounds[i]=(int16_t)args[i]*100;
            memcpy(state->camera_bounds_target,state->camera_bounds,sizeof(state->camera_bounds));
            state->camera_bounds_transition=0;
        }
        return 1;
    case 0x139: { /* FUN_0041ca60: signed camera pitch clamp. */
        ARITY(1);
        if (state->camera_lock==1) return 1;
        int pitch=(int16_t)args[0];
        if (pitch>800) pitch=800;
        if (pitch< -800) pitch=-800;
        state->camera_follow_pitch=(int16_t)pitch;return 1;
    }
    case 0x138: /* FUN_0041ca10 */
        ARITY(1);if (state->camera_lock!=1) state->camera_word=args[0];return 1;
    case 0x13a: { /* FUN_0041cae0: signed horizontal lead distance. */
        ARITY(1);
        int range=(int16_t)args[0];
        if (state->camera_lock!=1) state->camera_lead_range=range<0?0:range>2000?2000:range;
        return 1;
    }
    case 0x13b: { /* FUN_0041cb60: followed target's vertical offset. */
        ARITY(1);
        int height=(int16_t)args[0];
        if (state->camera_lock!=1) state->camera_follow_height=(int16_t)(height< -6000?-6000:height>6000?6000:height);
        return 1;
    }
    case 0x13d: { /* FUN_0041ccd0: unsigned distance from the projection plane. */
        ARITY(1);
        uint32_t depth=(uint32_t)(int32_t)(int16_t)args[0];
        if (state->camera_lock!=1) {
            state->depth=depth>20000?20000:depth?depth:1;state->camera_depth_target=state->depth;
            state->camera_depth_transition=0;
        }
        return 1;
    }
    case 0x13f: { /* FUN_0041cdd0: opposite side and yaw center. */
        ARITY(1);
        if (state->camera_lock==1) return 1;
        unsigned old=state->camera_side?state->camera_side:1;
        state->camera_side=args[0];
        if (old==1 && args[0]==2) {
            state->camera_follow_reference[2]=path_wrapped((uint32_t)state->camera_follow_reference[2]+state->camera_follow_distance*2u);
            state->camera_side_yaw=2048;state->camera_side_direction=-1;
        } else if (old==2 && args[0]==1) {
            state->camera_follow_reference[2]=path_wrapped((uint32_t)state->camera_follow_reference[2]-state->camera_follow_distance*2u);
            state->camera_side_yaw=0;state->camera_side_direction=1;
        }
        return 1;
    }
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

static int object_aabb(LL_LevelScript *script, LL_LevelScriptObject *object,
                      uint16_t mode, int32_t bounds[6])
{
    if (!object || !object->present || !object->pose) return 0;
    if (mode==0 || object->kind==5) {
        if (!object->bounds) return 0;
        for (unsigned i=0;i<6;i++) bounds[i]=path_wrapped((uint32_t)object->bounds[i]+
            (uint32_t)object->pose->position[i%3]);
        return 1;
    }
    if (object->kind==7) return 0;
    uint32_t clock=animation_clock(script->updates)>>5;
    if (object->query_bounds_valid && object->query_bounds_clock==clock && object->query_bounds_mode==mode) {
        memcpy(bounds,object->query_bounds,sizeof(object->query_bounds));return 1;
    }
    const LL_Bib3dxModel *model=ll_bib_get_model(&script->bib,object->model_index);
    if (!model || model->vertex_count<=4 || !object->root_rotation) return 0;
    unsigned first=2,count=model->vertex_count-4;
    if (mode!=1) {
        LL_BibModelPart part;
        if ((int16_t)mode<0 || !ll_bib_get_model_part(&script->bib,object->model_index,mode,&part)) return 0;
        first=part.first_vertex;count=part.vertex_count;
    }
    LL_BibVertex *vertices=calloc(model->vertex_count,sizeof(*vertices));
    if (!vertices) return 0;
    /* 4821d0/47f6d0 writes the rooted skeletal vertices into +BC. The
     * 47fbe0/47fec0 queries scan that expanded buffer, not packed BIB vertices. */
    if (!model_vertices(script,object,vertices,model->vertex_count,object->root_rotation)) { free(vertices);return 0; }
    for (unsigned axis=0;axis<3;axis++) { bounds[axis]=INT32_MAX;bounds[axis+3]=INT32_MIN; }
    for (unsigned i=first;i<first+count;i++) for (unsigned axis=0;axis<3;axis++) {
        int32_t value=vertices[i].position[axis];
        if (value<bounds[axis]) bounds[axis]=value;
        if (value>bounds[axis+3]) bounds[axis+3]=value;
    }
    free(vertices);
    for (unsigned i=0;i<6;i++) bounds[i]=path_wrapped((uint32_t)bounds[i]+(uint32_t)object->pose->position[i%3]);
    memcpy(object->query_bounds,bounds,sizeof(object->query_bounds));
    object->query_bounds_clock=clock;object->query_bounds_mode=mode;object->query_bounds_valid=1;
    return 1;
}

static int native_variable(LL_LevelScript *script, uint16_t id,
                           const uint16_t *args, size_t argc, uint16_t *result)
{
    LL_LevelNativeSetup *state=&script->native;
    switch (id) {
    case 0xbf: /* 40fde0: store AL and explicitly return AX=1 (omitted by Ghidra). */
        if (argc!=1) return fail(script,"full display override requires one word");
        state->force_full_display=(uint8_t)args[0];*result=1;return 1;
    case 0x3e: /* 40c1c0: zero-extend the global keyboard action-profile byte. */
        if (argc) return fail(script,"control profile query takes no arguments");
        *result=state->control_profile;return 1;
    case 0x2b: /* 40b400 stores AL but explicitly returns AX=0. */
        if (argc!=1) return fail(script,"event latch setter requires one word");
        state->level_event_latch=(uint8_t)args[0];*result=0;return 1;
    case 0x0f: { /* FUN_00409650/004095d0: script-owned ballistic movement. */
        if (argc!=4 || args[1]>=260 || !script->objects[args[1]].present)
            return fail(script,"ballistic step requires floor, model instance, drag and gravity");
        LL_LevelScriptObject *object=&script->objects[args[1]];
        if (!object->pose || object->kind==5 || object->kind==7)
            return fail(script,"ballistic step requires a model root");
        LL_NativeBallistic ballistic={.bounce_count=object->motion_word,
            .positive_bounce=object->motion_positive_bounce};
        memcpy(ballistic.velocity,object->motion,sizeof(ballistic.velocity));
        int32_t position[3];memcpy(position,object->pose->position,sizeof(position));
        int32_t ticks=(int32_t)((uint64_t)script->updates*60u/24u-
            (uint64_t)(script->updates-1u)*60u/24u);
        *result=(uint16_t)ll_native_ballistic_step(&ballistic,position,(int32_t)(int16_t)args[0]*100,
            (int16_t)args[2],(int16_t)args[3],ticks);
        model_position_set(script,object,position);
        memcpy(object->motion,ballistic.velocity,sizeof(object->motion));object->motion_word=ballistic.bounce_count;
        return 1;
    }
    case 0x23: { /* FUN_0040ac50 ->00468c20; Abilene discards all11 results. */
        if (argc!=2) return fail(script,"native damage requires mode and signed health amount");
        const LL_SoolVM *vm=script->in_conditions ? script->condition_vm :
            &script->contexts[script->dispatch_context].vm;
        const LL_SoolFunction *function=&script->program.functions[vm->last_function];
        uint32_t next=vm->last_instruction_offset+1u;
        uint32_t end=function->code_end;
        for (unsigned state=0;state<function->state_count;state++)
            if (function->state_offsets[state]>vm->last_instruction_offset && function->state_offsets[state]<end)
                end=function->state_offsets[state];
        if (script->in_conditions && function->conditions_start!=UINT16_MAX &&
            vm->last_instruction_offset>=function->conditions_start)
            end=function->virtual_count?function->virtual_start:function->size;
        /* 468c20 defines AL only. AH can retain allocator address bits, so
         * do not invent a full-word return for bytecode that observes AX. */
        if (next>=end || script->program.data[function->offset+next]!=0x3b)
            return fail(script,"native damage AX return is not ported; only discarded results are supported");
        uint8_t accepted;
        if (!player_damage(script,args[0],(int16_t)args[1],&accepted)) return 0;
        *result=accepted;return 1;
    }
    case 0x50: { /* FUN_0040ca80/004471b0 returns the previous layer-count word. */
        LL_NativeBackground *background=script->backgrounds[script->dispatch_context];
        if (argc!=5 || !background) return fail(script,"background layer creation requires five words and its manager");
        if (!ll_native_background_layer(background,args,result)) return fail(script,background->error);
        return 1;
    }
    case 0x33: { /* FUN_0040b760: create a targeted ball at an animated part's pivot. */
        if (argc!=4 || args[0]>=260 || args[3]>5 || !script->projectiles.initialized)
            return fail(script,"enemy projectile requires a wrapper, up to5 targets and command0x40's pool");
        const LL_LevelScriptObject *object=&script->objects[args[0]];
        const LL_Bib3dxModel *model=ll_bib_get_model(&script->bib,object->model_index);
        LL_BibModelPart part;
        if (!object->present || object->kind!=1 || !object->pose || !object->root_rotation || !model ||
            !ll_bib_get_model_part(&script->bib,object->model_index,args[1],&part) || part.pivot_vertex>=model->vertex_count)
            return fail(script,"enemy projectile references an invalid skeletal model or part pivot");
        LL_BibVertex *vertices=calloc(model->vertex_count,sizeof(*vertices));
        if (!vertices) return fail(script,"cannot allocate enemy projectile pose");
        int ok=ll_level_script_model_vertices(script,object,vertices,model->vertex_count);
        int16_t yaw,pivot[3];const int32_t zero[3]={0,0,0};
        if (ok) ok=ll_native_model_yaw(object->root_rotation,&yaw);
        if (ok) ll_native_vertex_transform(object->root_rotation,vertices[part.pivot_vertex].position,zero,NULL,pivot);
        free(vertices);
        if (!ok) return fail(script,"enemy projectile cannot evaluate its original pose or native yaw");
        int32_t origin[3];
        for (unsigned a=0;a<3;a++) origin[a]=path_wrapped((uint32_t)object->pose->position[a]+(uint32_t)(int32_t)pivot[a]);
        /* Argument4 (args[2]) is consumed but not read by0040b760. */
        *result=projectile_spawn(script,origin,yaw,0,args[3],1);return 1;
    }
    case 0x34: /* FUN_0040b980: replace one target in the selected pool slot. */
        if (argc!=3 || args[0]>=10 || args[1]>=5 || args[2]>=260 || !script->projectiles.initialized)
            return fail(script,"projectile target requires a pool slot0..9, target slot0..4 and wrapper0..259");
        script->projectiles.slots[args[0]].targets[args[1]]=args[2];
        *result=1;return 1;
    case 0x35: { /* FUN_0040b9e0: consume a targeted-ball contact for this slot. */
        if (argc!=2) return fail(script,"wrong native projectile-contact arity");
        int match=args[0]==script->projectiles.enemy_hit_instance && args[1]==script->projectiles.enemy_hit_slot;
        if (match) script->projectiles.enemy_hit_instance=0;
        *result=(uint16_t)match;return 1;
    }
    case 0x39: { /* FUN_0040be10: test a pool ball against a BIB world box. */
        if (argc!=3 || args[0]>=10 || !script->projectiles.initialized)
            return fail(script,"projectile box query requires command0x40's pool and a slot0..9");
        LL_BibScenePose box;
        *result=0;
        if (!ll_bib_get_scene_pose(&script->bib,args[1],args[2],&box)) return 1;
        LL_LevelProjectile *slot=&script->projectiles.slots[args[0]];
        if (!slot->ball.bounds || !slot->ball.pose)
            return fail(script,"projectile box query requires the pool's bounds and root");
        /* The native query deliberately does not gate on the ball's active
         * flags; a retained position can still match and decrement the word. */
        for (unsigned axis=0;axis<3;axis++) {
            int32_t minimum=path_wrapped((uint32_t)slot->ball.bounds[axis]+(uint32_t)slot->ball.pose->position[axis]);
            int32_t maximum=path_wrapped((uint32_t)slot->ball.bounds[axis+3]+(uint32_t)slot->ball.pose->position[axis]);
            if (maximum<box.position[axis] || box.angles[axis]<minimum) return 1;
        }
        slot->target_count=(uint16_t)(slot->target_count-1u);slot->flags=0;
        *result=1;return 1;
    }
    case 0x73: case 0x74: { /* FUN_0040e450/0040e4c0 inspect the native next-frame cursor. */
        if (argc!=1 || args[0]>=260 || !script->objects[args[0]].present ||
            script->objects[args[0]].kind==5 || script->objects[args[0]].kind==7)
            return fail(script,"animation cursor query requires a registered model wrapper");
        const LL_LevelScriptObject *object=&script->objects[args[0]];
        if (!object->animation_active) {
            if (id==0x73) return fail(script,"animation cursor requires an allocated animation buffer");
            *result=1;return 1; /* Native74 explicitly returns1 when C4 is null. */
        }
        *result=id==0x73 ? object->animation_next_frame :
            (uint16_t)(object->animation_next_frame==(object->animation_reverse?0:object->animation_last));
        return 1;
    }
    case 0x98: { /* FUN_0040d390/0041f460: pan from the two projected roots. */
        int32_t a[2],b[2];
        if (argc!=2 || !sound_position(script,args[0],a) || !sound_position(script,args[1],b))
            return fail(script,"sound pan requires two registered wrapper roots");
        *result=ll_native_screen_pan(a,b);return 1;
    }
    case 0x99: /* FUN_0040d3e0/0041f5e0: original BIZ sample, pitch, volume and pan. */
        if (argc!=6) return fail(script,"wrong native sound-play arity");
        return sound_play(script,args,result);
    case 0x9a: /* FUN_0040d470/0041fbb0: one-based voice, narrowed to a byte. */
        if (argc!=1) return fail(script,"wrong native sound-query arity");
        if (script->audio.enabled && (uint8_t)args[0]>64)
            return fail(script,"native sound query exceeds64 voices");
        *result=ll_native_audio_active(&script->audio,args[0]);return 1;
    case 0x9b: /* FUN_0040d4b0/0041fd20: count neither playing nor reserved. */
        if (argc) return fail(script,"wrong native sound-query arity");
        *result=ll_native_audio_free_voices(&script->audio);return 1;
    case 0xa2: /* FUN_0040d570/0041ff20: effects preference, separate from driver. */
        if (argc) return fail(script,"wrong native sound-query arity");
        *result=script->audio.effects_enabled;return 1;
    case 0x46: /* FUN_0040e8b0/FUN_0040e850: transition completion query. */
        if (argc!=1) return fail(script,"wrong native variable arity");
        if (args[0]==UINT16_MAX) *result=(uint16_t)(state->camera_transition_remaining==0);
        else *result=(uint16_t)((args[0]&0xff00u)|
            (args[0]==state->camera_transition_target?state->camera_transition_complete:0));
        return 1;
    case 0x08: { /* 408a00/408630: script-driven X approach, preserving word arithmetic. */
        unsigned instance=script->contexts[script->dispatch_context].instance;
        if (argc!=2 || instance>=260 || !script->objects[instance].present ||
            !script->objects[instance].pose || script->objects[instance].kind==5 ||
            script->objects[instance].kind==7)
            return fail(script,"scripted X approach requires a registered model root, target and speed");
        LL_LevelScriptObject *object=&script->objects[instance];
        int32_t target=(int32_t)(int16_t)args[0]*100,position[3];
        memcpy(position,object->pose->position,sizeof(position));
        int32_t ticks=(int32_t)((uint64_t)script->updates*60u/24u-
            (uint64_t)(script->updates-1u)*60u/24u);
        uint16_t step=(uint16_t)((int32_t)(int16_t)args[1]*ticks/((int)state->projection_mode+1));
        /* The native helper chooses its branch using only the signed low
         * word of target-current, then performs signed DWORD comparisons.
         * Within one step it reports completion without snapping the root. */
        int negative=(int16_t)(uint16_t)((uint32_t)target-(uint32_t)position[0])<0;
        int32_t threshold=path_wrapped((uint32_t)target+(negative?(uint32_t)step:0u-(uint32_t)step));
        *result=(uint16_t)(negative?position[0]<=threshold:position[0]>=threshold);
        if (!*result) {
            position[0]=path_wrapped((uint32_t)position[0]+(negative?0u-(uint32_t)step:(uint32_t)step));
            model_position_set(script,object,position);
        }
        return 1;
    }
    case 0x07: { /* FUN_00408440: native matrix-based turn towards target. */
        unsigned current=script->contexts[script->dispatch_context].instance;
        if (argc!=3 || current>=260 || args[2]>=260)
            return fail(script,"turn query requires current and target wrapper instances");
        LL_LevelScriptObject *source=&script->objects[current];
        const LL_LevelScriptObject *target=&script->objects[args[2]];
        if (!source->present || !target->present || !source->pose || !target->pose ||
            !source->root_rotation)
            return fail(script,"turn query requires a model rotation and two registered roots");
        int16_t yaw;int changed,converged;
        if (!ll_native_turn_towards(source->root_rotation,source->pose->position,
                target->pose->position,args[0],(int16_t)args[1],&yaw,&changed,&converged))
            return fail(script,"turn query matrix exceeds native inverse-angle domain");
        if (changed) {
            source->pose->angles[0]=0;source->pose->angles[1]=yaw;source->pose->angles[2]=0;
            int16_t rows[3][3];ll_native_model_rotation(source->pose->angles,rows);
            memcpy(source->root_rotation,rows,sizeof(rows));
        }
        *result=(uint16_t)converged;return 1;
    }
    case 0x96: case 0x97: { /* FUN_0041f020/0041f260: signed/scaled and linear distance gains. */
        if (argc!=(id==0x96?5u:4u) || args[0]>=260 || args[1]>=260)
            return fail(script,"distance attenuation requires two wrapper instances, range and amplitude");
        const LL_LevelScriptObject *a=&script->objects[args[0]],*b=&script->objects[args[1]];
        if (!a->present || !b->present || !a->pose || !b->pose)
            return fail(script,"distance attenuation requires registered wrapper roots");
        uint16_t distance=ll_native_distance100(a->pose->position,b->pose->position);
        if (distance>args[2]) { *result=id==0x96?args[3]:0;return 1; }
        if (!args[2]) return fail(script,"distance attenuation range causes native division by zero");
        if (id==0x96) {
            int16_t peak=(int16_t)args[3];
            int16_t gain=(int16_t)((int32_t)(int16_t)distance*peak/(int16_t)args[2]);
            if (peak>=0) gain=(int16_t)(uint16_t)(peak-gain);
            gain=(int16_t)((int32_t)gain*(int16_t)args[4]/256);
            int magnitude=gain<0?-(int)gain:gain,limit=peak<0?-(int)peak:peak;
            *result=(uint16_t)(magnitude>limit?peak:gain);return 1;
        }
        *result=(uint16_t)(args[3]-((uint32_t)distance*args[3])/args[2]);
        return 1;
    }
    case 0x83: { /* 40cd40: masked low payload word, not a normalized boolean. */
        if (argc!=2 || args[0]>=260 || !script->objects[args[0]].present ||
            !script->objects[args[0]].pose || script->objects[args[0]].kind==5 ||
            script->objects[args[0]].kind==7)
            return fail(script,"payload flag query requires a registered model wrapper and mask");
        *result=(uint16_t)(script->objects[args[0]].native_payload_flags&args[1]);return 1;
    }
    case 0x8e: { /* FUN_0040cb90: first matching collision link's bit0x80. */
        if (argc!=1 || args[0]>=260 || !script->objects[args[0]].present)
            return fail(script,"collision link query requires a registered target wrapper");
        unsigned instance=script->contexts[script->dispatch_context].instance;
        if (instance>=260 || !script->objects[instance].present)
            return fail(script,"collision link query requires its current model wrapper");
        const LL_LevelScriptObject *owner=&script->objects[instance];
        *result=0;
        for (unsigned i=0;i<3;i++) {
            const LL_LevelCollisionLink *link=&owner->collision_links[i];
            if (link->active && link->target_instance==args[0]) {
                *result=(uint16_t)(link->flags&0x80u);break;
            }
        }
        return 1;
    }
    case 0xc0: { /* FUN_0040fe20: retain this model as the shared native target. */
        if (argc) return fail(script,"wrong native variable arity");
        uint16_t instance=script->contexts[script->dispatch_context].instance;
        if (instance>=260 || !script->objects[instance].present ||
            !script->objects[instance].pose || script->objects[instance].kind==5 ||
            script->objects[instance].kind==7)
            return fail(script,"shared model target requires a registered model wrapper");
        state->selected_model_instance_plus_one=(uint16_t)(instance+1u);
        *result=1;return 1;
    }
    case 0x28: { /* FUN_0040ae50: consume the first active group/player contact. */
        if (argc) return fail(script,"wrong native variable arity");
        unsigned instance=script->dispatch_context;
        if (instance>=260 || !script->orbital_groups[instance].present)
            return fail(script,"group contact requires a registered sprite group");
        LL_LevelOrbitalGroup *group=&script->orbital_groups[instance];
        if (!group->callback_registered || !group->native_byte_2) {
            *result=0;return 1;
        }
        unsigned player=state->player_instance_plus_one;
        int32_t bounds[6];
        if (!player || player>260 ||
            !object_aabb(script,&script->objects[player-1u],0,bounds))
            return fail(script,"group contact requires the registered player's bounded root");
        int contact=ll_level_script_group_contact(script,instance,bounds);
        if (contact==-2) return fail(script,"group contact requires decoded member bounds and roots");
        if (contact==-3) return fail(script,"group contact hit animation is not implemented");
        *result=(uint16_t)(contact>=0);return 1;
    }
    case 0x0c: case 0x24: case 0x25: { /* 408cc0/408e40/408ec0: signed XYZ/100, truncation toward zero. */
        if (argc!=1 || args[0]>=260 || !script->objects[args[0]].present ||
            !script->objects[args[0]].pose)
            return fail(script,"coordinate query requires a registered wrapper root");
        unsigned axis=id==0x0c?0u:id==0x24?1u:2u;
        *result=(uint16_t)(script->objects[args[0]].pose->position[axis]/100);
        return 1;
    }
    case 0x16: /* FUN_00409430: first X < second X + signed margin*100. */
    case 0x17: { /* FUN_00409500: first Y > second Y - signed margin*100. */
        if (argc!=3 || args[0]>=260 || args[1]>=260)
            return fail(script,"vertical comparison requires two bounded wrapper instances and a margin");
        const LL_LevelScriptObject *first=&script->objects[args[0]];
        const LL_LevelScriptObject *second=&script->objects[args[1]];
        if (!first->present || !second->present || !first->pose || !second->pose ||
            first->kind==5 || first->kind==7 || second->kind==5 || second->kind==7)
            return fail(script,"vertical comparison requires two registered model roots");
        unsigned axis=id==0x16?0u:1u;
        uint32_t margin=(uint32_t)((int32_t)(int16_t)args[2]*100);
        uint32_t word=id==0x16 ? (uint32_t)second->pose->position[axis]+margin :
            (uint32_t)second->pose->position[axis]-margin;
        int32_t threshold;
        memcpy(&threshold,&word,sizeof(word));
        *result=(uint16_t)(id==0x16 ? first->pose->position[axis]<threshold :
            first->pose->position[axis]>threshold);
        return 1;
    }
    case 0x0b: /* FUN_00408c70: RNG word modulo signed SOOL bound. */
        if (argc!=1) return fail(script,"wrong native variable arity");
        if (!ll_native_rng_bounded((int16_t)args[0],result))
            return fail(script,"native random variable divides by a zero bound");
        return 1;
    case 0x0e: { /* FUN_00408f40: strict signed X interval, both bounds times100. */
        if (argc!=3 || args[2]>=260)
            return fail(script,"X interval query requires two bounds and a wrapper instance0..259");
        uint16_t instance=args[2];
        if (instance>=260 || !script->objects[instance].present ||
            !script->objects[instance].pose)
            return fail(script,"orbital X selection target has no bounded model root");
        int32_t minimum=(int32_t)(int16_t)args[0]*100;
        int32_t maximum=(int32_t)(int16_t)args[1]*100;
        int32_t x=script->objects[instance].pose->position[0];
        *result=(uint16_t)(x>minimum && x<maximum);
        return 1;
    }
    case 0x00: case 0x01: /* FUN_00407650/00407690: controller held/pressed words. */
        if (argc!=1 || args[0]!=0)
            return fail(script,"native input query requires the ported controller index0");
        *result=id==0 ? script->input_actions : script->input_pressed;return 1;
    case 0x36: { /* FUN_0040ba60 consumes the collision event latch on match. */
        if (argc!=1) return fail(script,"wrong native variable arity");
        int matched=(int16_t)args[0]==(int16_t)state->collision_event_latch;
        *result=(uint16_t)matched;
        if (matched) state->collision_event_latch=0;
        return 1;
    }
    case 0x38: /* FUN_0040bdc0 */
        if (argc) return fail(script,"wrong native variable arity");
        *result=(uint16_t)((state->native_flags&1u)!=0);
        if (*result) state->native_flags|=4u;
        return 1;
    case 0x44: /* FUN_0040c360 */
        if (argc) return fail(script,"wrong native variable arity");
        *result=state->native_word_44;
        return 1;
    case 0x4c: /* FUN_0040c8b0/004411c0: display fade still running. */
        if (argc) return fail(script,"wrong native fade-query arity");
        *result=script->native.fade_direction!=0;return 1;
    case 0x64: { /* FUN_0040ddb0 -> FUN_0040da10/FUN_0040d810: AABB overlap. */
        if (argc!=4 || args[0]>=260 || args[2]>=260)
            return fail(script,"AABB overlap requires two wrapper instances0..259 and modes");
        uint16_t first=args[0];
        uint16_t second=args[2];
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
    case 0x66: { /* FUN_0040de60: current wrapper bounds versus a target wrapper. */
        if (argc!=3 || args[1]>=260)
            return fail(script,"sprite collision query requires a target wrapper instance0..259");
        uint16_t first=script->contexts[script->dispatch_context].instance;
        uint16_t second=args[1];
        if (first>=260 || second>=260) return fail(script,"sprite collision wrapper has no live instance");
        int32_t a[6],b[6];
        if (!object_aabb(script,&script->objects[first],args[0],a) ||
            !object_aabb(script,&script->objects[second],args[2],b))
            return fail(script,"sprite collision mode requires bounded wrapper geometry");
        *result=1;
        for (unsigned axis=0;axis<3;axis++)
            if (a[axis+3]<b[axis] || b[axis+3]<a[axis]) { *result=0;break; }
        return 1;
    }
    case 0x2a: /* FUN_0040b3d0 */
        if (argc) return fail(script,"wrong native variable arity");
        *result=state->level_event_latch;return 1;
    case 0x27: /* FUN_0040adb0: remove the first occupied scene-sprite slot. */
        if (argc!=1 || args[0]>=260 || !script->objects[args[0]].present || !script->objects[args[0]].pose)
            return fail(script,"scene-sprite removal requires a registered wrapper root");
        /* The root argument is dereferenced but is not compared to the list.
         * Original x86 always returns AX=0, even after a successful removal. */
        for (unsigned i=0;i<5;i++) if (state->scene_sprite_slots[i]) {
            state->scene_sprite_slots[i]=0;break;
        }
        *result=0;return 1;
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
    size_t argument_count=!variable && id==0x33?10u:count-1u;
    if (argument_count+1u>*size) return fail(script,"native inventory snapshot requires five complete destination pairs");
    for (size_t i=0;i<argument_count;i++) args[i]=stack[*size-2u-i];
    script->calls++;
    /* Every executed call records its real stack arguments, not guessed IDs
     * from linear disassembly. Unsupported calls leave the stack untouched. */
    uint16_t result=0;
    int ok=variable ? native_variable(script,id,args,argument_count,&result) : command(script,id,args,argument_count);
    if (script->trace || !ok) {
        FILE *out=script->trace ? script->trace : stderr;
        fprintf(out,"%s: ABILENE tick=%u context=%u function=%u state=%u %s pc=+0x%x opcode=0x%02x %s=0x%x args=[",
            ok?"TRACE":"BLOCKED",script->updates,script->dispatch_context,vm->last_function,
            script->contexts[script->dispatch_context].state,
            script->in_conditions?"conditions":"body",vm->last_instruction_offset,opcode,
            variable?"variable":"command",id);
        for (size_t i=0;i<argument_count;i++) fprintf(out,"%s%d",i?",":"",(int16_t)args[i]);
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

static void animation_motion_update(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    if (!object->animation_root_motion || !ll_level_script_model_presented(script,(unsigned)(object-script->objects))) return;
    const LL_BibAnimationTable *table=ll_bib_get_animation_table(&script->bib,object->animation_selector);
    int loop_direction=object->animation_reverse ?
        (object->animation_frame==0 && object->animation_next_frame==table->record_count-1u?-1:0) :
        (object->animation_frame==table->record_count-1u && object->animation_next_frame==0?1:0);
    int16_t translation[3];
    if (!object->pose || !object->root_rotation ||
        !ll_native_animation_root_translation(&script->bib,object->animation_selector,
            object->animation_frame,object->animation_next_frame,object->animation_fraction,loop_direction,translation)) {
        object->animation_active=0;
        fail(script,"native animation root motion encountered an invalid packed frame");
        unsigned owner=object->animation_motion_owner;
        if (owner<script->program.function_count && !script->contexts[owner].blocked)
            blocked(script,owner,&script->contexts[owner].vm);
        return;
    }
    unsigned axis=object->animation_root_axis;
    uint32_t cycles=object->animation_motion_cycles;
    uint32_t displacement=(uint32_t)(int32_t)table->loop_displacement[axis];
    uint32_t shift=cycles*displacement;
    if (object->animation_reverse) shift=0u-shift;
    int32_t current=path_wrapped((uint32_t)(int32_t)translation[axis]+shift);
    int16_t local[3]={0,0,0},world[3];const int32_t zero[3]={0,0,0};
    local[axis]=(int16_t)(uint16_t)((uint32_t)current-(uint32_t)object->animation_motion_reference);
    LL_LevelSkeletalAttachment *attachment=skeletal_attachment(script,(unsigned)(object-script->objects));
    ll_native_vertex_transform(attachment?attachment->root_rotation:object->root_rotation,local,zero,NULL,world);
    int32_t *destination=attachment?attachment->root_offset:object->pose->position;
    for (unsigned a=0;a<3;a++) destination[a]=path_wrapped((uint32_t)destination[a]+(uint32_t)(int32_t)world[a]);
    object->animation_motion_reference=current;
}

static void camera_blocked(LL_LevelScript *script, const char *message)
{
    LL_LevelNativeSetup *camera=&script->native;
    if (camera->camera_blocked) return;
    camera->camera_blocked=1;
    snprintf(camera->camera_error,sizeof(camera->camera_error),"%s",message);
    fprintf(script->trace?script->trace:stderr,"BLOCKED: ABILENE camera callback: %s\n",message);
}

/* FUN_00453190 clamps its input. Ordinary follow callers supply a copy;
 * rootless/absolute callers copy the published result back to their reference. */
static void camera_publish(LL_LevelNativeSetup *camera, const int32_t reference[3],
                             int16_t pitch, int16_t yaw)
{
    /* FUN_00453190 advances depth and bounds even while dead-camera lock
     * suppresses the final clamp. Comparisons retain their native signedness. */
    if (camera->camera_depth_transition) {
        uint32_t target=camera->camera_depth_target,step=camera->camera_depth_step;
        if (camera->depth<target) {
            camera->depth+=step;if (camera->depth>target) camera->depth=target;
        } else if (camera->depth>target) {
            camera->depth-=step;if (camera->depth<target) camera->depth=target;
        }
    }
    if (camera->camera_bounds_transition) for (unsigned i=0;i<4;i++) {
        int32_t current=camera->camera_bounds[i],target=camera->camera_bounds_target[i];
        if (current<target) {
            current=path_wrapped((uint32_t)current+(uint32_t)camera->camera_bounds_step);
            if (current>target) current=target;
        } else if (current>target) {
            current=path_wrapped((uint32_t)current-(uint32_t)camera->camera_bounds_step);
            if (current<target) current=target;
        }
        camera->camera_bounds[i]=current;
    }
    memcpy(camera->camera_render_reference,reference,sizeof(camera->camera_render_reference));
    if (camera->camera_lock==0) {
        for (unsigned axis=0;axis<3;axis++) {
            int32_t minimum=axis<2?camera->camera_bounds[axis*2]:camera->camera_z_bounds[0];
            int32_t maximum=axis<2?camera->camera_bounds[axis*2+1]:camera->camera_z_bounds[1];
            if (camera->camera_render_reference[axis]>maximum) camera->camera_render_reference[axis]=maximum;
            if (camera->camera_render_reference[axis]<minimum) camera->camera_render_reference[axis]=minimum;
        }
    }
    camera->camera_view_pitch=pitch;camera->camera_view_yaw=yaw;
    camera->camera_output_active=1;
}

static int32_t camera_approach(int32_t current, int32_t target, uint16_t step)
{
    if (current<target) {
        current=path_wrapped((uint32_t)current+step);
        if (current>target) current=target;
    } else if (current>target) {
        current=path_wrapped((uint32_t)current-step);
        if (current<target) current=target;
    }
    return current;
}

static int camera_center_heading(int16_t yaw)
{
    return (yaw> -100 && yaw<100) || (yaw>1948 && yaw<2148) || (yaw>3996 && yaw<4196);
}

static void camera_idle_recenter(LL_LevelScript *script, int32_t horizontal)
{
    LL_LevelNativeSetup *camera=&script->native;
    if (script->player.present && script->player.mode==1) {
        camera->camera_idle_counter++;
        if (camera->camera_idle_counter==camera->camera_word && horizontal!=0)
            camera->camera_motion_mode=8;
    } else camera->camera_idle_counter=0;
}

static void camera_follow_update(LL_LevelScript *script)
{
    LL_LevelNativeSetup *camera=&script->native;
    unsigned instance=camera->camera_follow_instance_plus_one;
    if (!instance) {
        camera_publish(camera,camera->camera_follow_reference,camera->camera_follow_pitch,camera->camera_follow_yaw);
        memcpy(camera->camera_follow_reference,camera->camera_render_reference,sizeof(camera->camera_follow_reference));
        return;
    }
    if (instance>260 || !script->objects[instance-1u].present || !script->objects[instance-1u].pose) {
        camera_blocked(script,"followed wrapper has no model root");return;
    }
    const LL_LevelScriptObject *object=&script->objects[instance-1u];
    int is_player=script->player.present && instance==camera->player_instance_plus_one;
    int16_t heading=0;
    if ((is_player || camera->camera_motion_mode==2 || camera->camera_motion_mode==3 || camera->camera_motion_mode==7) &&
        (!object->root_rotation || !ll_native_model_yaw(object->root_rotation,&heading))) {
        camera_blocked(script,"followed model rotation has no native yaw");return;
    }
    if (camera->camera_vertical_mode==2 && script->player.mode!=4 && script->player.mode!=5)
        camera->camera_vertical_mode=1; /* FUN_004544b0: keep mode2 during jump/fall callbacks. */
    if (camera->camera_vertical_mode==0 || camera->camera_vertical_mode==3) {
        camera_blocked(script,"terrain-anchored vertical camera callback is not implemented");return;
    }
    int32_t target[3];memcpy(target,object->pose->position,sizeof(target));
    int32_t dx=path_wrapped((uint32_t)target[0]-(uint32_t)camera->camera_follow_target[0]);
    int32_t dy=path_wrapped((uint32_t)target[1]-((uint32_t)camera->camera_follow_target[1]-(uint32_t)(int32_t)camera->camera_follow_height));
    if (is_player && ((int64_t)dx>5000 || (int64_t)dx< -5000 || (int64_t)dy>5000 || (int64_t)dy< -5000)) {
        camera_blocked(script,"native camera recovery after a player teleport is not implemented");return;
    }
    target[1]=path_wrapped((uint32_t)target[1]+(uint32_t)(int32_t)camera->camera_follow_height);
    memcpy(camera->camera_lookat,target,sizeof(target));
    int32_t vector[3];
    for (unsigned axis=0;axis<3;axis++)
        vector[axis]=path_wrapped((uint32_t)target[axis]-(uint32_t)camera->camera_follow_reference[axis]);
    if (camera->camera_motion_mode!=3) {
        int yaw=ll_native_angle(vector[0],vector[2]);
        if (yaw>1024) yaw-=4096;
        camera->camera_follow_yaw=(int16_t)-yaw;
    }
    if (camera->camera_motion_mode!=4) {
        if (camera->camera_vertical_mode==1 || camera->camera_vertical_mode==4)
            camera->camera_follow_reference[1]=path_wrapped((uint32_t)camera->camera_follow_reference[1]+
                (uint32_t)target[1]-(uint32_t)camera->camera_follow_target[1]);
        camera->camera_follow_reference[2]=path_wrapped((uint32_t)camera->camera_follow_reference[2]+
            (uint32_t)target[2]-(uint32_t)camera->camera_follow_target[2]);
    }
    int direction=heading>512 && heading<1536 ? 1 : heading>2560 && heading<3584 ? -1 : 0;
    int relative_yaw=(int)camera->camera_follow_yaw-camera->camera_side_yaw;
    int absolute_yaw=relative_yaw<0?-relative_yaw:relative_yaw;
    switch (camera->camera_motion_mode) {
    case 0:
        if (is_player) {
            camera_idle_recenter(script,vector[0]);
            if (camera_center_heading(heading)) {
                camera->camera_lead_offset=camera_approach(camera->camera_lead_offset,0,camera->camera_limit);
                camera->camera_follow_reference[0]=camera_approach(camera->camera_follow_reference[0],target[0],camera->camera_limit);
            } else if (camera->camera_lead_enabled)
                camera->camera_lead_offset=camera_approach(camera->camera_lead_offset,
                    direction*camera->camera_lead_range,camera->camera_limit);
        }
        if (absolute_yaw>camera->camera_speed) {
            camera->camera_follow_reference[0]=path_wrapped((uint32_t)camera->camera_follow_reference[0]+(uint32_t)dx);
            camera->camera_motion_mode=7;
        }
        break;
    case 2:case 3:
        camera->camera_follow_reference[0]=path_wrapped((uint32_t)camera->camera_follow_reference[0]+(uint32_t)dx);
        camera->camera_lead_offset=camera_approach(camera->camera_lead_offset,
            direction*camera->camera_lead_range,camera->camera_limit);
        if (camera->camera_motion_mode==2) camera->camera_follow_yaw=camera->camera_side_yaw;
        break;
    case 4:case 5:
        if (camera->camera_motion_mode==4) {
            camera->camera_follow_pitch=ll_native_angle(vector[1],vector[2]);
            if (camera->camera_side==2)
                camera->camera_follow_pitch=(int16_t)(camera->camera_side_yaw-camera->camera_follow_pitch);
        }
        if (absolute_yaw>camera->camera_speed) {
            if (!camera->camera_clamp_active) camera->camera_clamp_target_x=target[0];
            camera->camera_clamp_active=1;
            if (relative_yaw>camera->camera_speed) relative_yaw=camera->camera_speed;
            if (relative_yaw< -camera->camera_speed) relative_yaw=-camera->camera_speed;
            camera->camera_follow_yaw=(int16_t)(relative_yaw+camera->camera_side_yaw);
        } else camera->camera_clamp_active=0;
        break;
    case 7:
        if (path_wrapped((uint32_t)dx*(uint32_t)camera->camera_last_dx)<0 || camera_center_heading(heading))
            camera->camera_motion_mode=0;
        else {
            camera_idle_recenter(script,vector[0]);
            camera->camera_follow_reference[0]=path_wrapped((uint32_t)camera->camera_follow_reference[0]+(uint32_t)dx);
            int side=camera->camera_side_direction;
            camera->camera_follow_yaw=(int16_t)(camera->camera_side_yaw+(relative_yaw<0?-camera->camera_speed:camera->camera_speed));
            camera->camera_lead_offset=camera_approach(camera->camera_lead_offset,
                (relative_yaw<0?side:-side)*camera->camera_lead_range,camera->camera_limit);
        }
        break;
    case 8:
        camera->camera_follow_reference[0]=camera_approach(camera->camera_follow_reference[0],target[0],camera->camera_limit);
        if (!camera->camera_lead_enabled)
            camera->camera_lead_offset=camera_approach(camera->camera_lead_offset,0,camera->camera_limit);
        if (!script->player.present || script->player.mode!=1 || (vector[0]==0 && camera->camera_lead_offset==0))
            camera->camera_motion_mode=0;
        break;
    }
    if (dx) camera->camera_last_dx=dx;
    memcpy(camera->camera_follow_target,target,sizeof(target));
    int32_t output[3];memcpy(output,camera->camera_follow_reference,sizeof(output));
    output[0]=path_wrapped((uint32_t)output[0]+(uint32_t)camera->camera_lead_offset);
    camera_publish(camera,output,camera->camera_follow_pitch,camera->camera_follow_yaw);
}

static void camera_transition_update(LL_LevelScript *script)
{
    LL_LevelNativeSetup *state=&script->native;
    if (state->camera_transition_absolute) {
        if (!state->camera_transition_remaining) return;
        for (unsigned axis=0;axis<3;axis++)
            state->camera_follow_reference[axis]=path_wrapped((uint32_t)state->camera_follow_reference[axis]+
                (uint32_t)state->camera_reference_step[axis]);
        int16_t angle[2];
        for (unsigned axis=0;axis<2;axis++) {
            state->camera_angle_fixed[axis]=path_wrapped((uint32_t)state->camera_angle_fixed[axis]+
                (uint32_t)state->camera_angle_step[axis]);
            angle[axis]=(int16_t)(uint16_t)wrapped_shift((uint32_t)state->camera_angle_fixed[axis],12);
        }
        state->camera_follow_pitch=angle[0];state->camera_follow_yaw=angle[1];
        camera_publish(state,state->camera_follow_reference,angle[0],angle[1]);
        memcpy(state->camera_follow_reference,state->camera_render_reference,sizeof(state->camera_follow_reference));
        if (--state->camera_transition_remaining==0) {
            /* Native547b0 keeps the reached values, including truncation,
             * then reconstructs the normal callback's virtual look-at root. */
            int16_t pitch=angle[0]==-1024?-1023:angle[0],yaw=angle[1]==-1024?-1023:angle[1];
            int cp=ll_native_cosine(pitch),cy=ll_native_cosine(yaw);
            if (!cp || !cy) { camera_blocked(script,"absolute camera transition ends at a native tangent division by zero");return; }
            int32_t tangent_pitch=-(int32_t)ll_native_sine(pitch)*4096/cp;
            int32_t tangent_yaw=(int32_t)ll_native_sine(yaw)*4096/cy;
            int32_t offset_y=wrapped_shift((uint32_t)tangent_pitch*state->camera_follow_distance,12);
            int32_t offset_x=wrapped_shift((uint32_t)tangent_yaw*state->camera_follow_distance,12);
            memcpy(state->camera_lookat,state->camera_follow_reference,sizeof(state->camera_lookat));
            state->camera_lookat[0]=path_wrapped((uint32_t)state->camera_lookat[0]-(uint32_t)offset_x);
            state->camera_lookat[1]=path_wrapped((uint32_t)state->camera_lookat[1]-(uint32_t)offset_y);
            uint32_t distance=state->camera_follow_distance;
            state->camera_lookat[2]=path_wrapped((uint32_t)state->camera_lookat[2]+(state->camera_side==2?0u-distance:distance));
            memcpy(state->camera_follow_target,state->camera_lookat,sizeof(state->camera_lookat));
            state->camera_follow_pitch=pitch;state->camera_follow_yaw=yaw;
            state->camera_transition_complete=1;state->camera_transition_active=0;
            if (state->camera_motion_mode<2 || state->camera_motion_mode>5) state->camera_motion_mode=0;
        }
        return;
    }
    unsigned instance=state->camera_follow_instance_plus_one;
    if (!state->camera_transition_active || !state->camera_transition_remaining || !instance || instance>260) return;
    const LL_LevelScriptObject *target=&script->objects[instance-1u];
    if (!target->present || !target->pose) return;
    int32_t position[3];memcpy(position,target->pose->position,sizeof(position));
    position[1]=path_wrapped((uint32_t)position[1]+(uint32_t)(int32_t)state->camera_follow_height);
    int32_t direction[3];
    for (unsigned i=0;i<3;i++) {
        uint32_t movement=(uint32_t)position[i]-(uint32_t)state->camera_follow_target[i];
        state->camera_follow_reference[i]=path_wrapped((uint32_t)state->camera_follow_reference[i]+
            movement+(uint32_t)state->camera_reference_step[i]);
        state->camera_lookat[i]=path_wrapped((uint32_t)state->camera_lookat[i]+
            movement+(uint32_t)state->camera_lookat_step[i]);
        direction[i]=path_wrapped((uint32_t)state->camera_lookat[i]-(uint32_t)state->camera_follow_reference[i]);
    }
    memcpy(state->camera_follow_target,position,sizeof(position));
    int16_t pitch=ll_native_angle(direction[1],direction[2]);
    int yaw=ll_native_angle(direction[0],direction[2]);
    if (state->camera_side==2) pitch=(int16_t)(state->camera_side_yaw-pitch);
    if (yaw>1024) yaw-=4096;
    int32_t output[3];memcpy(output,state->camera_follow_reference,sizeof(output));
    output[0]=path_wrapped((uint32_t)output[0]+(uint32_t)state->camera_lead_offset);
    camera_publish(state,output,pitch,(int16_t)-yaw);
    if (--state->camera_transition_remaining==0) {
        memcpy(state->camera_follow_target,state->camera_lookat,sizeof(state->camera_lookat));
        state->camera_follow_yaw=state->camera_view_yaw;
        state->camera_transition_complete=1;
        state->camera_transition_active=0;
        if (state->camera_motion_mode<2 || state->camera_motion_mode>5) state->camera_motion_mode=0;
    }
}

static void camera_update(LL_LevelScript *script)
{
    LL_LevelNativeSetup *camera=&script->native;
    if (!camera->camera_callback_enabled || camera->camera_blocked) return;
    if (camera->camera_transition_active) camera_transition_update(script);
    else camera_follow_update(script);
}

static void player_blocked(LL_LevelScript *script, const char *message)
{
    LL_LevelPlayer *player=&script->player;
    if (player->blocked) return;
    player->blocked=1;
    unsigned instance=script->native.player_instance_plus_one;
    if (instance && instance<=260) script->objects[instance-1u].animation_active=0;
    snprintf(player->error,sizeof(player->error),"%s",message);
    fprintf(script->trace?script->trace:stderr,"BLOCKED: ABILENE player callback: %s\n",message);
}

static int player_sound(LL_LevelScript *script, uint16_t sample, int16_t pitch, uint16_t volume)
{
    if (script->audio.effects_enabled!=1) return 1;
    /* Controller callbacks address the decoded bank directly. Only the
     * SOOL99 wrapper subtracts the script's sample-ID base. */
    const uint16_t sound[6]={0,(uint16_t)(script->audio.base+sample),(uint16_t)pitch,volume,0x400,0};
    uint16_t voice;
    if (!sound_play(script,sound,&voice)) { player_blocked(script,script->error);return 0; }
    return 1;
}

static int player_damage(LL_LevelScript *script, uint16_t mode, int16_t amount, uint8_t *accepted)
{
    *accepted=0;
    LL_LevelPlayer *player=&script->player;
    unsigned instance=script->native.player_instance_plus_one;
    if (!player->present || !instance || instance>260 || !script->objects[instance-1u].present) {
        return fail(script,"native damage requires the registered player");
    }
    LL_LevelScriptObject *object=&script->objects[instance-1u];
    if (player->hurt_callback || (object->native_payload_flags&0x100u)) return 1;
    if (mode && !(object->native_payload_flags&0x20u)) mode=1;
    if (mode>1) return fail(script,"native grounded damage reaction mode is not ported");
    LL_LevelNativeSetup *state=&script->native;
    /* FUN_00468c20: three is the highest of four health tiers.
     * The fourth accepted hit resets health to3 and consumes one life. */
    if (!state->player_invincible) {
        state->native_word_44=(uint16_t)(state->native_word_44-(uint16_t)amount);state->player_health_dirty=1;
    }
    if ((int16_t)state->native_word_44<0) {
        state->native_word_44=3;state->player_lives=(int16_t)(uint16_t)(state->player_lives-1);
        state->native_flags|=1u;object->native_payload_flags|=0x100u;
    }
    player->hurt_callback=(uint8_t)(mode?1:3);*accepted=1;return 1;
}

static int player_hurt_update(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    LL_LevelPlayer *player=&script->player;
    if (player->hurt_callback==3) { /* FUN_00468e30: immunity without cry/blink. */
        uint32_t now=(uint32_t)((uint64_t)script->updates*60u/24u);
        if (!player->quiet_hurt_started) player->quiet_hurt_started=now;
        if (now-player->quiet_hurt_started>120u) { player->quiet_hurt_started=0;player->hurt_callback=0; }
        return 1;
    }
    if (player->hurt_callback==1) {
        /* FUN_00469020 schedules68d80; the blink starts on the next callback. */
        if (!player_sound(script,1,-100,0x1fff)) return 0;
        player->hurt_callback=2;return 1;
    }
    if (player->hurt_callback==2) {
        uint32_t now=(uint32_t)((uint64_t)script->updates*60u/24u);
        object->visible=1;object->native_payload_flags|=0x8000u;
        if (!player->hurt_started) player->hurt_started=now;
        if (now-player->hurt_started<121u) {
            if (!(now&8u)) object->visible=0;
        } else {
            player->hurt_started=0;player->hurt_callback=0;object->native_payload_flags&=~0x8000u;
        }
    }
    return 1;
}

static int player_event(LL_LevelScript *script, LL_LevelScriptObject *object, uint16_t event)
{
    unsigned selector=(unsigned)object->player_control_index+event;
    const LL_BibAnimationTable *table=ll_bib_get_animation_table(&script->bib,selector);
    if (!table || !table->record_count || !table->record_type ||
        table->loop_displacement[0] || table->loop_displacement[1] || table->loop_displacement[2]) {
        player_blocked(script,"controller animation needs a bounded table without root loop displacement");
        return 0;
    }
    script->player.event=event;script->player.animation_cycles=0;
    object->animation_selector=(uint16_t)selector;object->animation_first=0;
    object->animation_last=(uint16_t)(table->record_count-1u);
    object->animation_frame=0;object->animation_next_frame=table->record_count>1?1:0;
    object->animation_fraction=0;object->animation_started=animation_clock(script->updates);
    object->animation_active=1;object->animation_once=0;object->animation_pose_present=1;
    object->animation_reverse=0;
    object->animation_root_motion=0;
    object->animation_callback_owner=0;
    return 1;
}

static int player_initialize(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    const LL_Bib3dxModel *model=ll_bib_get_model(&script->bib,object->model_index);
    if (!model || model->vertex_count<5 || !object->bounds || !player_event(script,object,0)) return 0;
    LL_BibVertex *vertices=calloc(model->vertex_count,sizeof(*vertices));
    if (!vertices) return 0;
    int ok=ll_bib_build_neutral_vertices(&script->bib,object->model_index,vertices,model->vertex_count) &&
        ll_native_animation_vertices(&script->bib,object->model_index,object->animation_selector,
            0,0,0,vertices,model->vertex_count,NULL,0,NULL);
    if (ok) {
        for (unsigned axis=0;axis<3;axis++) {
            script->player.base_bounds[axis]=INT32_MAX;
            script->player.base_bounds[axis+3]=INT32_MIN;
        }
        for (unsigned v=2;v<model->vertex_count-2u;v++)
            for (unsigned axis=0;axis<3;axis++) {
                int value=vertices[v].position[axis];
                if (value<script->player.base_bounds[axis]) script->player.base_bounds[axis]=value;
                if (value>script->player.base_bounds[axis+3]) script->player.base_bounds[axis+3]=value;
            }
        memcpy(object->bounds,script->player.base_bounds,sizeof(script->player.base_bounds));
        script->player.initialized=1;script->player.mode=1;
        script->player.idle_started=(uint32_t)((uint64_t)script->updates*60u/24u);
        object->native_payload_flags&=~0x20040u;
    }
    free(vertices);return ok;
}

static int32_t player_multiply_shift12(int32_t a, int32_t b)
{
    int32_t value=path_wrapped((uint32_t)a*(uint32_t)b);
    return value>=0?value/4096:(int32_t)(-((-(int64_t)value+4095)/4096));
}

static void player_face_yaw(LL_LevelScript *script, LL_LevelScriptObject *object, int16_t yaw)
{
    script->player.yaw=yaw;
    int32_t angles[3]={0,yaw,0};int16_t matrix[3][3];
    ll_native_model_rotation(angles,matrix);memcpy(object->root_rotation,matrix,sizeof(matrix));
    memcpy(object->pose->angles,angles,sizeof(angles));
}

static int player_face_input(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    int16_t facing;
    int moving=ll_level_player_facing(&script->bib,object->path.selector,object->path.segment,
        object->path.distance,object->path.yaw,script->native.camera_view_yaw,script->player.actions,&facing);
    if (moving<0) { player_blocked(script,"controller direction query encountered invalid path links");return -1; }
    if (moving) player_face_yaw(script,object,facing);
    return moving;
}

static int player_ground_mode(LL_LevelScript *script, LL_LevelScriptObject *object,
                               unsigned mode, int restart)
{
    LL_LevelPlayer *player=&script->player;
    if (player->mode==mode && !restart) return 1;
    player->mode=(uint8_t)mode;
    memcpy(object->bounds,player->base_bounds,sizeof(player->base_bounds));
    if (mode==1) {
        player->fall_sound_ticks=0;
        object->native_payload_flags&=~0x20040u;
        player->idle_started=(uint32_t)((uint64_t)script->updates*60u/24u);
    }
    return player_event(script,object,(uint16_t)(mode==1?0:mode==2?4:5));
}

static int player_jump(LL_LevelScript *script, LL_LevelScriptObject *object, int moving_jump)
{
    /* FUN_00467830/004678c0 read signed WORD impulses at004bddf4/f8. */
    LL_LevelPlayer *player=&script->player;
    player->mode=4;player->vertical_speed=moving_jump?-155:-125;
    player->air_motion=(uint8_t)(moving_jump?1:0);
    object->native_payload_flags&=~0x40020u;
    return player_event(script,object,15);
}

static int player_fall(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    /* FUN_00467dd0: a walk-off starts at64, unlike a jump apex at0. */
    script->player.mode=5;script->player.vertical_speed=64;script->player.air_motion=1;
    object->native_payload_flags=(object->native_payload_flags&~0x20u)|0x40u;
    return player_event(script,object,18);
}

static int player_vertical_update(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    LL_LevelPlayer *player=&script->player;
    if (player->mode==4) {
        int apex=ll_level_player_accelerate(&player->vertical_speed,&player->vertical_displacement,
            0,6,script->native.projection_mode);
        if (!apex) {
            object->pose->position[1]=path_wrapped((uint32_t)object->pose->position[1]+(uint32_t)player->vertical_displacement);
            return 1;
        }
        /* FUN_00467e60 enters the fall callback immediately, preserving
         * horizontal control and the jump animation's completion callback. */
        player->mode=5;player->vertical_speed=0;object->native_payload_flags|=0x40u;
    }
    if (player->mode==5) {
        ll_level_player_accelerate(&player->vertical_speed,&player->vertical_displacement,
            145,5,script->native.projection_mode);
        object->pose->position[1]=path_wrapped((uint32_t)object->pose->position[1]+(uint32_t)player->vertical_displacement);
        if (script->audio.effects_enabled==1) {
            /* FUN_00467bd0: the long-fall cry occurs only at count40;
             * landing strength and pitch depend on the number of fall callbacks. */
            player->fall_sound_ticks++;
            if (!(object->native_payload_flags&0x100u) && player->fall_sound_ticks==40 &&
                !player_sound(script,2,-50,0x1fff)) return 0;
            if (object->native_payload_flags&0x20u) {
                int32_t product=path_wrapped(player->fall_sound_ticks*0xfffffe00u);
                int16_t pitch=(int16_t)(uint16_t)(product/256-400);
                if (pitch< -700) pitch=-700;
                if (pitch> -400) pitch=-400;
                uint16_t volume=(uint16_t)((uint32_t)wrapped_shift(player->fall_sound_ticks*1024u,8)+3500u);
                if ((int16_t)volume<3500) volume=3500;
                if ((int16_t)volume>4500) volume=4500;
                if (!player_sound(script,3,pitch,volume)) return 0;
            }
        }
        if (object->native_payload_flags&0x20u) {
            player->vertical_speed=0;player->mode=6;
            /* FUN_00467bd0 schedules466900 for the next callback; its
             * current horizontal control and pose still run this frame. */
        }
    }
    return 1;
}

static int player_air_animation_callback(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    if (script->player.event!=15 || !object->animation_active || object->animation_callback_owner ||
        (unsigned)object->animation_selector!=(unsigned)object->player_control_index+15u) return 1;
    const LL_BibAnimationTable *table=ll_bib_get_animation_table(&script->bib,object->animation_selector);
    if (!table || !table->record_count) { player_blocked(script,"jump completion has no animation table");return 0; }
    uint64_t duration=0;
    unsigned end=table->record_count>1 ? table->record_count-1u : 1u;
    for (unsigned i=0;i<end;i++) duration+=(uint64_t)table->records[i].sample_count*32u;
    if ((uint32_t)(animation_clock(script->updates)-object->animation_started)>=duration)
        return player_event(script,object,18); /* FUN_00467620 */
    return 1;
}

static int player_ground_control(LL_LevelScript *script, LL_LevelScriptObject *object);
static int player_shoot_control(LL_LevelScript *script, LL_LevelScriptObject *object);

static int player_dynamite_request(LL_LevelScript *script, const LL_LevelScriptObject *object)
{
    /* 466740/466b60/466d80/469870: a press, stock and suitable support are all required. */
    uint32_t flags=object->native_payload_flags;
    if (!(script->player.pressed_actions&0x1000u) || script->native.level_event_latch ||
        script->native.player_dynamite<=0 || ((flags&8u) && !(flags&0x10000u))) return 0;
    script->native.player_dynamite=(int16_t)(script->native.player_dynamite-1);
    script->native.level_event_latch=1;return 1;
}

static int player_crouch_entry(LL_LevelScript *script, LL_LevelScriptObject *object, int rising)
{
    LL_LevelPlayer *player=&script->player;
    player->crouch_motion=player->mode==17?1:player->mode;
    player->mode=(uint8_t)(rising?18:15);
    memcpy(object->bounds,player->base_bounds,sizeof(player->base_bounds));
    if (!rising) object->bounds[1]=path_wrapped((uint32_t)object->bounds[1]+800u);
    return player_event(script,object,(uint16_t)(rising?21:19));
}

static int player_crouch_control(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    LL_LevelPlayer *player=&script->player;
    if (!(object->native_payload_flags&0x20u)) return player_fall(script,object);
    if (player->mode==17) player_dynamite_request(script,object);
    int moving=player_face_input(script,object);
    if (moving<0) return 0;
    if (player->mode!=17 && moving)
        return player_ground_mode(script,object,2,1) && player_ground_control(script,object);
    if (player->mode==17) {
        if (player->pressed_actions&0x8000u)
            return player_ground_mode(script,object,1,1) && player_ground_control(script,object);
        if (!(player->actions&0x40u))
            return player_crouch_entry(script,object,1) && player_crouch_control(script,object);
    }
    if (player->actions&0x2000u) {
        if (!script->projectiles.initialized) { player_blocked(script,"crouched shooting requires the native projectile pool");return 0; }
        player->mode=7;player->aim_event=UINT16_MAX;player->shot_pending=0;
        return player_shoot_control(script,object);
    }
    if (player->mode!=17 && (player->pressed_actions&0x8000u))
        return player_ground_mode(script,object,1,1) && player_ground_control(script,object);
    return 1;
}

static int player_crouch_animation_callback(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    LL_LevelPlayer *player=&script->player;
    if ((player->event!=19 && player->event!=21) || !object->animation_active || object->animation_callback_owner ||
        (unsigned)object->animation_selector!=(unsigned)object->player_control_index+player->event) return 1;
    const LL_BibAnimationTable *table=ll_bib_get_animation_table(&script->bib,object->animation_selector);
    uint64_t completion=0;
    unsigned end=table && table->record_count>1?table->record_count-1u:1u;
    for (unsigned i=0;table && i<end;i++) completion+=(uint64_t)table->records[i].sample_count*32u;
    if ((uint32_t)(animation_clock(script->updates)-object->animation_started)>=completion)
        player->mode=(uint8_t)(player->event==19?16:19); /* 469a20/469b60 schedule next tick's entry. */
    return 1;
}

static int player_holster_control(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    LL_LevelPlayer *player=&script->player;
    if (!(object->native_payload_flags&0x20u)) return player_fall(script,object);
    int moving=player_face_input(script,object);
    if (moving<0) return 0;
    if (moving) return player_ground_mode(script,object,1,1) && player_ground_control(script,object);
    if (player->pressed_actions&0x8000u) return player_jump(script,object,(player->actions&0x4000u)!=0);
    if (player->actions&0x40u) return player_crouch_entry(script,object,0) && player_crouch_control(script,object);
    if (player->actions&0x2000u) {
        player->mode=7;player->aim_event=UINT16_MAX;player->shot_pending=0;
        return player_shoot_control(script,object);
    }
    return 1;
}

static int player_shoot_control(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    LL_LevelPlayer *player=&script->player;
    if (!(object->native_payload_flags&0x20u)) return player_fall(script,object);
    int16_t yaw;
    if (!ll_native_model_yaw(object->root_rotation,&yaw)) {
        player_blocked(script,"shooting root rotation has no native yaw");return 0;
    }
    if (player->shot_pending) {
        if (!player_sound(script,0,-200,0x1fff)) return 0;
        static const int16_t muzzle[6][3]={{0,-925,800},{0,-1200,600},{0,-1900,-50},
            {0,-1580,-720},{0,-470,-1070},{0,-570,1050}};
        const int16_t *offset=muzzle[player->aim_index];
        int32_t sine=ll_native_sine(yaw),cosine=ll_native_cosine(yaw);
        int32_t origin[3];
        origin[0]=path_wrapped((uint32_t)object->pose->position[0]+(uint32_t)wrapped_shift(
            (uint32_t)(offset[0]*cosine)+(uint32_t)(offset[2]*sine),12));
        origin[1]=path_wrapped((uint32_t)object->pose->position[1]+(uint32_t)(int32_t)offset[1]);
        origin[2]=path_wrapped((uint32_t)object->pose->position[2]+(uint32_t)wrapped_shift(
            (uint32_t)(-offset[2]*cosine)-(uint32_t)(offset[0]*sine),12));
        projectile_spawn(script,origin,player->aim_yaw,player->aim_angle,1,2);
    }
    player->shot_pending=0;
    static const uint8_t aim[2][9]={{0,1,2,3,4,4,5,5,0},{4,3,2,1,0,5,5,4,0}};
    static const int16_t angle[2][9]={{0,512,1024,1536,2048,2048,0,0,0},
        {2048,1536,1024,512,0,0,0,2048,0}};
    unsigned side=(uint16_t)yaw>=2048u,direction=ll_level_player_direction(player->actions);
    player->aim_index=aim[side][direction];player->aim_angle=angle[side][direction];player->aim_yaw=yaw;
    uint16_t event=(uint16_t)(7u+player->aim_index);
    if (event!=player->aim_event) {
        memcpy(object->bounds,player->base_bounds,sizeof(player->base_bounds));
        if (event==11 || event==12) object->bounds[1]=path_wrapped((uint32_t)object->bounds[1]+800u);
        player->aim_event=event;
        if (!player_event(script,object,event)) return 0;
        player->shot_pending=1;
    }
    if (!(player->actions&0x2000u)) {
        player->shot_pending=0;player->mode=8;
        return player_event(script,object,14) && player_holster_control(script,object);
    }
    if (player->pressed_actions&0x8000u) return player_jump(script,object,1);
    return 1;
}

static int player_obstacle_control(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    /* FUN_004690a0/004691e0: release when turning, stopping or jumping. */
    LL_LevelPlayer *player=&script->player;
    uint32_t mask=player->mode==9?4u:0x10u;
    int16_t before,after;
    if (!ll_native_model_yaw(object->root_rotation,&before)) {
        player_blocked(script,"obstacle response has no bounded root heading");return 0;
    }
    if (!(player->pressed_actions&0x8000u) && (object->native_payload_flags&mask)) {
        int moving=player_face_input(script,object);
        if (moving<0) return 0;
        if (!ll_native_model_yaw(object->root_rotation,&after)) {
            player_blocked(script,"obstacle response lost its root heading");return 0;
        }
        if (moving && before==after) {
            if (player->mode==9 && !(object->native_payload_flags&0x20u)) return player_fall(script,object);
            return 1;
        }
    }
    if (player->pressed_actions&0x8000u) player->speed=0;
    else object->native_payload_flags&=~mask;
    return player_ground_mode(script,object,1,1) && player_ground_control(script,object);
}

static int player_ground_control(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    LL_LevelPlayer *player=&script->player;
    uint32_t flags=object->native_payload_flags;
    if (!(flags&0x20u)) return player_fall(script,object);
    if (player->actions&0x2000u) {
        if (!script->projectiles.initialized) {
            player_blocked(script,"native shooting requires command0x40's projectile pool");return 0;
        }
        player->mode=7;player->aim_event=UINT16_MAX;player->shot_pending=0;
        return player_shoot_control(script,object);
    }
    int jump=player->mode==1 ? ((player->actions&0x8000u) && (flags&0x40000u)) :
        ((player->pressed_actions&0x8000u)!=0);
    if (jump) return player_jump(script,object,player->mode!=1 || (player->actions&0x4000u));
    int moving=player_face_input(script,object);
    if (moving<0) return 0;
    unsigned mode=moving ? ((player->actions&0x4000u)?3u:2u) : 1u;
    if (!moving && player->mode!=1 && !player_ground_mode(script,object,1,1)) return 0;
    if ((!moving && (player->actions&0x40u)) || player_dynamite_request(script,object))
        return player_crouch_entry(script,object,0) && player_crouch_control(script,object);
    if (!player_ground_mode(script,object,mode,0)) return 0;
    if (moving && (object->native_payload_flags&4u)) {
        player->mode=9;player->obstacle_motion=2;
        if (!player_event(script,object,22) || !player_obstacle_control(script,object)) return 0;
    }
    if (moving && (object->native_payload_flags&0x10u)) {
        if (player->mode<=3) player->obstacle_motion=(uint8_t)(player->mode==3);
        player->mode=10;
        if (!player_event(script,object,23) || !player_obstacle_control(script,object)) return 0;
    }
    return 1;
}

static int player_shoot_animation_callback(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    LL_LevelPlayer *player=&script->player;
    if ((player->mode!=7 && player->mode!=8) || !object->animation_active || object->animation_callback_owner ||
        (unsigned)object->animation_selector!=(unsigned)object->player_control_index+player->event) return 1;
    const LL_BibAnimationTable *table=ll_bib_get_animation_table(&script->bib,object->animation_selector);
    uint64_t total=0,completion=0;
    for (unsigned i=0;table && i<table->record_count;i++) {
        total+=(uint64_t)table->records[i].sample_count*32u;
        if (i+1u<table->record_count || table->record_count==1) completion=total;
    }
    uint32_t elapsed=(uint32_t)(animation_clock(script->updates)-object->animation_started);
    if (!total || elapsed<completion) return 1;
    uint32_t callbacks=(uint32_t)(1u+(elapsed-completion)/total);
    if (callbacks==player->animation_cycles) return 1;
    player->animation_cycles=callbacks;
    if (player->mode==7) player->shot_pending=1; /* FUN_00468130, consumed next callback. */
    else return player_ground_mode(script,object,1,1) && player_ground_control(script,object);
    return 1;
}

static int player_horizontal_update(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    LL_LevelPlayer *player=&script->player;
    unsigned mode=player->mode==14?player->suspended_motion:player->mode;
    if (mode==15 || mode==16 || mode==18 || mode==19) mode=player->crouch_motion;
    else if (mode==17) mode=1;
    int32_t target=0,acceleration=13;
    if (mode<=3) {
        target=mode==1?0:mode==2?23:66;
        acceleration=mode==1?13:10;
    } else if (mode==9 || mode==10) {
        unsigned motion=mode==9?2:player->obstacle_motion;
        target=motion==2?20:motion==1?66:23;acceleration=motion==2?6:10;
    } else if (mode==11 || mode==12 || mode==13) {
        target=mode==11?23:66;acceleration=10;
    } else if (mode==4 || mode==5 || mode==6) {
        unsigned motion=player->air_motion;
        int moving=player_face_input(script,object);
        if (moving<0) return 0;
        /* FUN_00465ba0/465df0/465ec0 select next frame's callback,
         * then accelerate using the callback that was entered this frame. */
        if (!motion) {
            if (moving) player->air_motion=(uint8_t)((player->actions&0x4000u)?2:1);
        } else if (motion==1) {
            if (!moving) player->air_motion=0;
            else if (player->actions&0x4000u) player->air_motion=2;
        } else {
            if (!moving) player->air_motion=0;
            else if (!(player->actions&0x4000u)) player->air_motion=1;
        }
        target=motion==0?0:motion==1?45:79;acceleration=motion==0?13:10;
    }
    ll_level_player_accelerate(&player->speed,&player->displacement,target,acceleration,script->native.projection_mode);
    return 1;
}

static int player_precontrol(LL_LevelScript *script, LL_LevelScriptObject *object,
                               const LL_BibPathSegment *segment, int *resume_idle)
{
    LL_LevelPlayer *player=&script->player;
    unsigned type=segment->flags&255u;
    player->actions=script->input_actions;player->pressed_actions=script->input_pressed;
    *resume_idle=player->mode==13;
    if (player->precontrol_mode==1) { /* Independent of the main callback changed by BA. */
        if (type==1) player_face_yaw(script,object,object->path.yaw);
        else {
            player->precontrol_mode=0;player->controller_entry=0;
            player->mode=13;*resume_idle=1;
            player->actions=player->pressed_actions=0;
        }
        return 1;
    }
    if (player->precontrol_mode==2) return 1; /* No pre-control callback during automatic running. */
    uint32_t flags=object->native_payload_flags;
    uint16_t masked=0;
    static const uint32_t restrictions[7]={1,0x200,0x400,0x800,0x1000,0x2000,0x4000};
    static const uint16_t actions[7]={0x8000,0x80,0x20,0x10,0x40,0x2000,0x1000};
    for (unsigned i=0;i<7;i++) if (flags&restrictions[i]) masked|=actions[i];
    player->actions&=(uint16_t)~masked;player->pressed_actions&=(uint16_t)~masked;
    /* FUN_00469ef0 accounts for path deaths once. Contexts15/16 own recovery. */
    if ((flags&0x100u) && !(script->native.native_flags&1u)) {
        const uint16_t sound[6]={0,(uint16_t)(script->audio.base+2u),(uint16_t)(int16_t)-450,8191,1024,0};
        uint16_t voice;
        if (!sound_play(script,sound,&voice)) { player_blocked(script,script->error);return 0; }
        script->native.native_word_44=3;
        script->native.player_lives=(int16_t)(uint16_t)(script->native.player_lives-1);
        script->native.native_flags|=1u;
    }
    if (!(player->actions&0x8000)) object->native_payload_flags|=0x40000u;
    if ((flags&0x20u) && (type==1 || type==2)) {
        *resume_idle=0;player->mode=(uint8_t)(type==1?11:12);
        player->precontrol_mode=(uint8_t)(type==1?1:2);player->controller_entry=0;
        if (type==1) {
            if (player->hurt_callback) player->hurt_callback=2;
            object->native_payload_flags&=~0x40u;
        }
        return player_event(script,object,(uint16_t)(type==1?4:5));
    }
    return 1;
}

static int player_scripted_entry(LL_LevelScript *script, LL_LevelScriptObject *object)
{
    LL_LevelPlayer *player=&script->player;
    unsigned entry=player->controller_entry-1u;
    player->controller_entry=0;
    if (entry<=2) return player_ground_mode(script,object,entry+1u,1);
    if (entry==8) {
        if (player->mode!=14) player->suspended_motion=player->mode;
        player->mode=14;return 1; /* 465a40 changes neither motion nor animation. */
    }
    /* 467b20 (BA15) and67830 (BA3) enter67660 immediately. Only BA3
     * clears jump release40000; BA15 resets the long-fall sound counter. */
    if (entry==15) player->fall_sound_ticks=0;
    else object->native_payload_flags&=~0x40000u;
    object->native_payload_flags&=~0x20u;
    /* WORD4bddf8=-125 (467b20), WORD4bddf4=-155 (467830). */
    player->mode=4;player->vertical_speed=entry==15?-125:-155;
    player->air_motion=entry==15?0:1;
    return player_event(script,object,15);
}

/* FUN_004662e0 -> 4669f0/466900/466cf0/466f10 -> 46a260.
 * Ground and air callbacks run after SOOL, then constrain their native path. */
static void player_update(LL_LevelScript *script)
{
    LL_LevelPlayer *player=&script->player;
    unsigned instance=script->native.player_instance_plus_one;
    if (!player->present || player->blocked || !instance || instance>260) return;
    LL_LevelScriptObject *object=&script->objects[instance-1u];
    if (!object->present || !object->update_enabled || !object->native_callback_enabled) return;
    if (!object->pose || !object->root_rotation || !object->path.attached) {
        player_blocked(script,"player movement requires its model root and attached native path");return;
    }
    if (!player->initialized && !player_initialize(script,object)) {
        player_blocked(script,"cannot initialize original controller pose and bounds");return;
    }
    LL_BibPathSegment segment;
    if (!ll_bib_get_path_segment(&script->bib,object->path.selector,object->path.segment,&segment)) {
        player_blocked(script,"controller path segment is invalid");return;
    }
    int resume_idle;
    if (!player_precontrol(script,object,&segment,&resume_idle)) return;
    if (!player_hurt_update(script,object)) return;
    if (player->controller_entry) {
        resume_idle=0;
        if (!player_scripted_entry(script,object)) return;
    }
    if (player->mode==16) { /* 4699b0: crouched idle is a separate entry and changes horizontal control. */
        player->mode=17;
        memcpy(object->bounds,player->base_bounds,sizeof(player->base_bounds));
        object->bounds[1]=path_wrapped((uint32_t)object->bounds[1]+800u);
        if (!player_event(script,object,20)) return;
    } else if (player->mode==19 && !player_ground_mode(script,object,1,1)) return;
    /* FUN_00469ea0 restores the ordinary control entry for the next tick;
     * this tick still uses the automatic run motion/animation. */
    if (player->mode==12 && (segment.flags&255u)!=2) {
        player->precontrol_mode=0;player->mode=13;
    }
    if (resume_idle && player->mode==13 && !player_ground_mode(script,object,1,1)) return;
    if (player->mode==6 && !player_ground_mode(script,object,1,1)) return;
    if (player->mode<=3) { if (!player_ground_control(script,object)) return; }
    else if (player->mode==7) { if (!player_shoot_control(script,object)) return; }
    else if (player->mode==8) { if (!player_holster_control(script,object)) return; }
    else if (player->mode==9 || player->mode==10) { if (!player_obstacle_control(script,object)) return; }
    else if (player->mode==15 || player->mode==17 || player->mode==18) { if (!player_crouch_control(script,object)) return; }
    if (!player_vertical_update(script,object)) return;
    if (!player_air_animation_callback(script,object)) return;
    if (!player_shoot_animation_callback(script,object)) return;
    if (!player_crouch_animation_callback(script,object)) return;
    /* Idle callback cycles after600 native60-Hz steps, at animation completion. */
    if (player->mode==1) {
        const LL_BibAnimationTable *table=ll_bib_get_animation_table(&script->bib,object->animation_selector);
        uint64_t duration=0;
        for (unsigned i=0;table && i<table->record_count;i++) duration+=(uint64_t)table->records[i].sample_count*32u;
        uint32_t cycles=duration ? (uint32_t)((uint32_t)(animation_clock(script->updates)-object->animation_started)/duration) : 0;
        uint32_t now=(uint32_t)((uint64_t)script->updates*60u/24u);
        if (cycles!=player->animation_cycles && now-player->idle_started>599u) {
            static const uint8_t variations[4]={1,2,3,2};
            static const uint8_t sounds[4]={7,4,5,6};
            player->idle_started=now;player->idle_variation++;
            unsigned variation=player->idle_variation&3u;
            int16_t pitch=(int16_t)(uint16_t)(script->audio.pitch_offset+(variation? -100:50));
            if (!player_sound(script,sounds[variation],pitch,5000)) return;
            if (!player_event(script,object,variations[player->idle_variation&3u])) return;
        } else player->animation_cycles=cycles;
    }
    if (!player_horizontal_update(script,object)) return;
    int32_t x=player_multiply_shift12(player->displacement,ll_native_sine(player->yaw));
    int32_t z=player_multiply_shift12(player->displacement,ll_native_cosine(player->yaw));
    x=player_multiply_shift12(x,ll_native_cosine(object->path.pitch));
    z=player_multiply_shift12(z,ll_native_cosine(object->path.pitch));
    object->pose->position[0]=path_wrapped((uint32_t)object->pose->position[0]+(uint32_t)x);
    object->pose->position[2]=path_wrapped((uint32_t)object->pose->position[2]-(uint32_t)z);
    unsigned direction=ll_level_player_direction(player->actions);
    if (object->native_payload_flags&0x20000u || direction==8) {
        int16_t yaw;
        if (!ll_native_model_yaw(object->root_rotation,&yaw)) {
            player_blocked(script,"controller root rotation has no native yaw");return;
        }
        object->path.heading=(uint16_t)yaw&4095u;
    } else {
        static const uint16_t parallel[8]={1024,1365,2048,2730,3072,3413,0,682};
        static const uint16_t transverse[8]={1024,1706,2048,2389,3072,3754,0,341};
        int yaw=object->path.yaw;
        int horizontal=(yaw>=513 && yaw<=1535) || (yaw>=2561 && yaw<=3583);
        object->path.heading=(uint16_t)((horizontal?transverse[direction]:parallel[direction])+
            script->native.camera_view_yaw)&4095u;
    }
    LL_LevelPathStep step;
    if (!ll_level_path_update(&script->bib,object->path.selector,object->path.segment,
            object->pose->position,object->path.previous_position,object->path.heading,
            object->native_payload_flags,object->path.flags,0,&step)) {
        player_blocked(script,"native player path constraint failed");return;
    }
    object->path.segment=step.segment;
    object->path.previous_distance=object->path.distance;
    object->path.distance=step.constraint.distance;object->path.flags=step.constraint.path_flags;
    if (step.orientation_reset) { object->path.yaw=step.yaw;object->path.pitch=step.pitch; }
    object->native_payload_flags=step.constraint.payload_flags;
    memcpy(object->pose->position,step.constraint.position,sizeof(step.constraint.position));
    memcpy(object->path.previous_position,step.constraint.position,sizeof(step.constraint.position));
}

static void object_paths_update(LL_LevelScript *script)
{
    for (unsigned instance=0;instance<260;instance++) {
        LL_LevelScriptObject *object=&script->objects[instance];
        LL_LevelObjectPath *path=&object->path;
        if (!object->present || !path->attached || !object->pose ||
            (script->player.present && script->native.player_instance_plus_one==instance+1u)) continue;
        LL_LevelPathStep step;
        if (!ll_level_path_update(&script->bib,path->selector,path->segment,
                object->pose->position,path->previous_position,path->heading,
                object->native_payload_flags,path->flags,0,&step)) {
            path->attached=0;
            snprintf(script->error,sizeof(script->error),
                "path callback instance%u selector%u segment%u has invalid geometry",
                instance,path->selector,path->segment);
            fprintf(script->trace?script->trace:stderr,"BLOCKED: ABILENE %s\n",script->error);
            if (path->owner_context<script->program.function_count &&
                !script->contexts[path->owner_context].blocked)
                blocked(script,path->owner_context,&script->contexts[path->owner_context].vm);
            script->error[0]=0;
            continue;
        }
        path->segment=step.segment;
        path->distance=step.constraint.distance;path->previous_distance=path->distance;
        path->flags=step.constraint.path_flags;
        if (step.orientation_reset) { path->yaw=step.yaw;path->pitch=step.pitch; }
        object->native_payload_flags=step.constraint.payload_flags;
        memcpy(object->pose->position,step.constraint.position,sizeof(step.constraint.position));
        memcpy(path->previous_position,step.constraint.position,sizeof(step.constraint.position));
    }
}

static void collision_callback_fail(LL_LevelScript *script, unsigned instance, const char *message)
{
    LL_LevelScriptObject *owner=&script->objects[instance];
    if (owner->collision_blocked) return;
    owner->collision_blocked=1;script->native.collision_blocked_count++;
    snprintf(owner->collision_error,sizeof(owner->collision_error),"%s",message);
    fprintf(script->trace?script->trace:stderr,"BLOCKED: ABILENE tick=%u collision callback instance=%u context=%u: %s\n",
        script->updates,instance,owner->collision_owner_context,message);
}

static void collision_body(const LL_LevelScriptObject *object, LL_NativeCollisionBody *body)
{
    memcpy(body->position,object->pose->position,sizeof(body->position));
    memcpy(body->previous,object->collision_previous_position,sizeof(body->previous));
    memcpy(body->bounds,object->bounds,sizeof(body->bounds));body->flags=object->native_payload_flags;
}

static void collision_callbacks_update(LL_LevelScript *script)
{
    /* Abilene's F5 owners are constructed after its player and projectile pool. */
    for (unsigned instance=0;instance<260;instance++) {
        LL_LevelScriptObject *owner=&script->objects[instance];
        if (!owner->present || !owner->collision_registered || owner->collision_blocked ||
            !owner->native_callback_enabled || owner->reduced) continue;
        for (unsigned slot=0;slot<3;slot++) {
            LL_LevelCollisionLink *link=&owner->collision_links[slot];
            if (!link->active) continue;
            LL_LevelScriptObject *target=link->target_instance<260?&script->objects[link->target_instance]:NULL;
            if (!target || !target->present || !owner->pose || !owner->bounds || !target->pose || !target->bounds) {
                collision_callback_fail(script,instance,"collision callback lost a bounded model root");break;
            }
            LL_NativeCollisionBody a,b;collision_body(owner,&a);collision_body(target,&b);
            LL_LevelCollisionLink prepared=*link;
            int moved=ll_native_collision_step(&prepared,&a,&b);
            if (moved<0) { collision_callback_fail(script,instance,"native collision callback mode is unsupported");break; }
            *link=prepared;owner->native_payload_flags=a.flags;target->native_payload_flags=b.flags;
            if (moved&1) model_position_set(script,owner,a.position);
            if (moved&2) model_position_set(script,target,b.position);
        }
    }
}

static int skeletal_attachment_update(LL_LevelScript *script, LL_LevelSkeletalAttachment *attachment,
                                        uint8_t visited[260])
{
    unsigned child=attachment->child_instance,parent=attachment->parent_instance;
    if (visited[child] || attachment->blocked) return visited[child]==2;
    visited[child]=1;
    LL_LevelSkeletalAttachment *upstream=skeletal_attachment(script,parent);
    if (upstream && !skeletal_attachment_update(script,upstream,visited)) return 0;
    LL_LevelScriptObject *a=&script->objects[parent],*b=&script->objects[child];
    /* Native child evaluation is reached through its parent's draw callback. */
    if (!a->update_enabled || !a->native_callback_enabled || !a->visible ||
        (a->draw_suppressed && !upstream)) return 0;
    int16_t parent_pivot[3],child_pivot[3]={0,0,0},rotation[9];int32_t position[3];
    if (!a->present || !b->present || !a->pose || !b->pose || !a->root_rotation || !b->root_rotation ||
        !attachment_pivot(script,a,attachment->parent_part,parent_pivot) ||
        ((int16_t)attachment->child_part>0 && !attachment_pivot(script,b,attachment->child_part,child_pivot))) {
        attachment->blocked=1;
        fail(script,"native skeletal attachment cannot evaluate its retained model roots and part pivots");
        unsigned owner=attachment->owner_context;
        if (owner<script->program.function_count && !script->contexts[owner].blocked)
            blocked(script,owner,&script->contexts[owner].vm);
        return 0;
    }
    /* Mode2, FUN_004872f0: descriptor+7c is separate from render matrix+5c.
     * Compose captured child matrix/offset, add the parent's transformed pivot,
     * evaluate the child's mesh with its own render matrix, subtract its pivot.
     * Detach later copies the resulting +7c rotation to +5c. */
    ll_native_camera_model_view(a->attachment_rotation,a->pose->position,
        attachment->root_rotation,attachment->root_offset,rotation,position);
    for (unsigned axis=0;axis<3;axis++) position[axis]=path_wrapped((uint32_t)position[axis]+
        (uint32_t)(int32_t)parent_pivot[axis]-(uint32_t)(int32_t)child_pivot[axis]);
    memcpy(b->pose->position,position,sizeof(position));
    memcpy(b->attachment_rotation,rotation,sizeof(rotation));visited[child]=2;return 1;
}

static void skeletal_attachments_update(LL_LevelScript *script)
{
    uint8_t visited[260]={0};
    for (unsigned i=0;i<script->skeletal_attachment_count;i++)
        skeletal_attachment_update(script,&script->skeletal_attachments[i],visited);
}

static void model_previous_roots_update(LL_LevelScript *script)
{
    /* Native47ac50 retains the last presented model root in its wrapper.
     * Cell-dependent draw eligibility remains outside the current renderer. */
    for (unsigned i=0;i<260;i++) {
        LL_LevelScriptObject *object=&script->objects[i];
        if (object->present && object->pose && !object->reduced && object->kind!=5 && object->kind!=7)
            memcpy(object->collision_previous_position,object->pose->position,sizeof(object->collision_previous_position));
    }
}

int ll_level_script_set_pause_archive(LL_LevelScript *script, const unsigned char *data, size_t size)
{
    if (!script || !script->loaded) return 0;
    if (!ll_native_pause_open(&script->pause,data,size)) return fail(script,script->pause.error);
    return 1;
}

void ll_level_script_set_system_input(LL_LevelScript *script, uint8_t keys)
{
    if (!script) return;
    script->system_keys=keys;
}

void ll_level_script_update(LL_LevelScript *script)
{
    if (!script || !script->loaded) return;
    /* Snapshot native input before any SOOL body/condition, including frames
     * without an enabled player callback. Queries do not consume this edge. */
    script->input_pressed=(uint16_t)(script->input_actions&(uint16_t)~script->previous_input_actions);
    script->previous_input_actions=script->input_actions;
    ll_native_audio_tick(&script->audio);
    uint8_t was_paused=script->pause.paused;
    ll_native_pause_update(&script->pause,script->native.pause_enabled,script->system_keys,
        script->input_pressed);
    if (was_paused!=script->pause.paused) {
        uint16_t mute=script->pause.paused;
        ll_native_audio_control(&script->audio,0xca,&mute,1);
        script->native.cd_paused=script->pause.paused;
    }
    if (script->pause.paused || script->pause.exit_requested || script->scene_requested) return;
    script->updates++;
    uint32_t clock=animation_clock(script->updates);
    sprite_groups_update(script);
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
        uint64_t elapsed=(uint32_t)((clock>>5)-object->sprite_animation_started);
        if (object->sprite_animation_once && elapsed>total) {
            object->sprite_frame=object->sprite_animation_last;
            object->sprite_primitives_present=0;
            object->sprite_animation_active=0;
            if (object->kind==5) object_visibility_set(object,0);
            unsigned owner=object->sprite_animation_owner;
            if (owner && owner<=script->program.function_count)
                script->contexts[owner-1u].vm.host_animation_wait=0;
            object->sprite_animation_owner=0;
            continue;
        }
        if (elapsed) elapsed=(elapsed-1u)%total+1u; /* 485430 advances only after elapsed>duration. */
        unsigned frame=object->sprite_animation_first;
        for (;frame<=object->sprite_animation_last;frame++) {
            LL_BibSpriteFrame record;
            if (!ll_bib_get_sprite_frame(&script->bib,object->sprite_selector,frame,&record)) break;
            if (elapsed<=record.duration) break;
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
        if (!table || object->animation_last>=table->record_count || object->animation_first>=table->record_count) continue;
        uint64_t total=0,elapsed=(uint32_t)(clock-object->animation_started);
        unsigned low=object->animation_reverse?object->animation_last:object->animation_first;
        unsigned high=object->animation_reverse?object->animation_first:object->animation_last;
        if (low>high) continue;
        for (unsigned frame=low;frame<=high;frame++)
            total+=(uint64_t)table->records[frame].sample_count*32u;
        if (!total) continue;
        object->animation_motion_cycles=object->animation_once?0:(uint32_t)(elapsed/total);
        if (object->animation_once) { if (elapsed>=total) elapsed=total-1u; }
        else elapsed%=total;
        unsigned frame=object->animation_first;
        while (frame!=object->animation_last) {
            uint64_t duration=(uint64_t)table->records[frame].sample_count*32u;
            if (elapsed<duration) break;
            elapsed-=duration;
            if (object->animation_reverse) frame--;else frame++;
        }
        object->animation_frame=(uint16_t)frame;
        object->animation_next_frame=frame!=object->animation_last ?
            (uint16_t)(object->animation_reverse?frame-1u:frame+1u) :
            (object->animation_once ? (uint16_t)frame : object->animation_first);
        uint64_t duration=(uint64_t)table->records[frame].sample_count*32u;
        object->animation_fraction=duration ? (uint32_t)(elapsed*65536u/duration) : 0;
        if (object->animation_once && frame==object->animation_last) object->animation_fraction=0;
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
        animation_motion_update(script,object);
    }
    object_paths_update(script);
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
    camera_update(script);
    if (script->native.background_enabled) for (unsigned i=0;i<script->program.function_count;i++)
        if (script->backgrounds[i]) ll_native_background_update(script->backgrounds[i],
            script->native.camera_render_reference,script->native.camera_view_pitch,
            script->native.camera_view_yaw,(uint16_t)script->native.projection);
    player_update(script);
    /* Abilene registers its player in context4, then the pool in context7. */
    projectiles_update(script);
    collision_callbacks_update(script);
    skeletal_attachments_update(script);
    model_previous_roots_update(script);
    /* FUN_00440fb0, after script queries and callbacks, before presentation. */
    LL_LevelNativeSetup *state=&script->native;
    if (state->fade_direction==1) {
        if (state->fade_alpha<=8) { state->fade_alpha=0;state->fade_direction=0; }
        else state->fade_alpha-=8;
    } else if (state->fade_direction==2) {
        if (state->fade_alpha>=247) { state->fade_alpha=255;state->fade_direction=0; }
        else state->fade_alpha+=8;
    }
}

void ll_level_script_report(const LL_LevelScript *script, FILE *out)
{
    if (!script || !out) return;
    fprintf(out,"ABILENE SOOL: loaded=%d functions=%u updates=%u calls=%u supported=%u blocked=%u objects=%u static_models=%u\n",
        script->loaded,script->program.function_count,script->updates,script->calls,
        script->supported_calls,script->blocked_count,script->object_count,script->static_model_count);
    if (script->scene_requested) fprintf(out,"SOOL scene transition: requested=%u reload=%u\n",script->requested_scene,script->scene_reload);
    unsigned managers=0,layers=0,primitives=0;
    for (unsigned i=0;i<260;i++) if (script->backgrounds[i]) {
        const LL_NativeBackground *background=script->backgrounds[i];managers++;layers+=background->layer_count;
        for (unsigned layer=0;layer<background->layer_count;layer++) primitives+=background->layers[layer].primitive_count;
    }
    if (managers) fprintf(out,"ABILENE backgrounds: managers=%u layers=%u primitives=%u enabled=%u\n",
        managers,layers,primitives,script->native.background_enabled);
    unsigned collision_owners=0,links=0,supports=0,sides=0;
    for (unsigned i=0;i<260;i++) if (script->objects[i].collision_registered) {
        collision_owners++;
        for (unsigned slot=0;slot<3;slot++) {
            const LL_LevelCollisionLink *link=&script->objects[i].collision_links[slot];
            if (link->active) { links++;supports+=(link->flags&0x80u)!=0;sides+=(link->flags&0x40u)!=0; }
        }
    }
    if (collision_owners) fprintf(out,"ABILENE collisions: owners=%u links=%u supports=%u side_contacts=%u blocked=%u\n",
        collision_owners,links,supports,sides,script->native.collision_blocked_count);
    if (script->skeletal_attachment_count) {
        unsigned blocked_attachments=0;
        for (unsigned i=0;i<script->skeletal_attachment_count;i++) blocked_attachments+=script->skeletal_attachments[i].blocked!=0;
        fprintf(out,"ABILENE attachments: links=%u blocked=%u\n",script->skeletal_attachment_count,blocked_attachments);
    }
    if (script->pause.ready) fprintf(out,"ABILENE pause: resources=%u registered=%u enabled=%u paused=%u exit=%u\n",
        LL_PAUSE_IMAGES,script->pause.registered,script->native.pause_enabled,script->pause.paused,script->pause.exit_requested);
    if (script->audio.ready) fprintf(out,"ABILENE audio: samples=%u enabled=%u plays=%u free_voices=%u/64\n",
        script->audio.sample_count,script->audio.enabled,script->audio.plays,ll_native_audio_free_voices(&script->audio));
    if (script->player.present) fprintf(out,"ABILENE player: health=%d lives=%d hurt_callback=%u\n",
        (int16_t)script->native.native_word_44,script->native.player_lives,script->player.hurt_callback);
    if (script->projectiles.initialized) {
        unsigned balls=0,flashes=0;
        for (unsigned i=0;i<10;i++) {
            balls+=script->projectiles.slots[i].flags!=0;
            flashes+=script->projectiles.slots[i].flash_active!=0;
        }
        fprintf(out,"ABILENE projectiles: balls=%u/10 flashes=%u/10 fired=%u enemy=%u dropped=%u\n",
            balls,flashes,script->projectiles.shots_fired,script->projectiles.enemy_shots_fired,script->projectiles.shots_dropped);
    }
    if (script->native.camera_blocked) fprintf(out,"  camera callback: %s\n",script->native.camera_error);
    for (unsigned i=0;i<260;i++) if (script->objects[i].collision_blocked)
        fprintf(out,"  collision callback instance%u: %s\n",i,script->objects[i].collision_error);
    if (script->player.blocked) fprintf(out,"  player callback: %s\n",script->player.error);
    for (unsigned i=0;script->contexts && i<script->program.function_count;i++)
        if (script->contexts[i].blocked) fprintf(out,"  context%u %s\n",i,script->contexts[i].error);
}
