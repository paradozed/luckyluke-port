#include "native_background.h"
#include "native_camera.h"

#include <stdio.h>
#include <string.h>

static int background_fail(LL_NativeBackground *background, const char *message)
{
    snprintf(background->error,sizeof(background->error),"%s",message);return 0;
}

static int32_t signed32(uint32_t bits)
{
    int32_t value;memcpy(&value,&bits,sizeof(value));return value;
}

void ll_native_background_init(LL_NativeBackground *background, uint16_t word, int16_t height)
{
    memset(background,0,sizeof(*background));background->wrapper_word=word;
    background->reference_y=(int16_t)(uint16_t)(-((int32_t)height*256/480));
}

int ll_native_background_layer(LL_NativeBackground *background, const uint16_t args[5], uint16_t *index)
{
    if (background->layer_count>=LL_BACKGROUND_LAYERS)
        return background_fail(background,"native background exceeds16 bounded layers");
    if ((int16_t)args[2]<=0 || (int16_t)args[3]<=0)
        return background_fail(background,"native background layer has a zero or negative modulo extent");
    LL_BackgroundLayer *layer=&background->layers[background->layer_count];
    for (unsigned i=0;i<4;i++) layer->rectangle[i]=(int16_t)args[i];
    int16_t order=(int16_t)args[4];
    if (order<0) order=(int16_t)(uint16_t)(order+4095);
    layer->order=order;layer->enabled=1;memset(layer->tint,128,sizeof(layer->tint));
    *index=(uint16_t)background->layer_count++;return 1;
}

int ll_native_background_command(LL_NativeBackground *background, uint16_t command,
    const uint16_t *args, size_t argc, const LL_BibFile *bib, const LL_BizFile *biz)
{
    size_t expected=command==0x123?10:command==0x124?8:command==0x125?11:
        command==0x126?5:command==0x128?3:command==0x12c?2:0;
    if (!expected || argc!=expected) return background_fail(background,"wrong native background command or arity");
    unsigned index=(uint8_t)args[0];
    if (index>=background->layer_count) return background_fail(background,"native background layer is not registered");
    LL_BackgroundLayer *layer=&background->layers[index];
    if (command==0x126) {
        layer->speed[0]=(int8_t)(uint8_t)args[1];
        layer->speed[1]=(int8_t)(uint8_t)((int32_t)(int8_t)(uint8_t)args[2]*256/480);
        layer->factor[0]=(int16_t)args[3];layer->factor[1]=(int16_t)((int32_t)(int16_t)args[4]*256/480);
        return 1;
    }
    if (command==0x128) { layer->flags=(uint8_t)args[1];if ((uint8_t)args[2]) layer->flags|=4;return 1; }
    if (command==0x12c) { layer->enabled=(uint8_t)args[1];return 1; }
    if (layer->primitive_count>=LL_BACKGROUND_PRIMITIVES)
        return background_fail(background,"native background exceeds32 primitives per layer");
    LL_BackgroundPrimitive primitive={0};
    unsigned rectangle=command==0x123?2:1;
    for (unsigned i=0;i<4;i++) primitive.rectangle[i]=(int16_t)args[rectangle+i];
    if (primitive.rectangle[2]<=0 || primitive.rectangle[3]<=0)
        return background_fail(background,"native background primitive needs positive dimensions");
    if (command==0x123) {
        LL_BibSelector selector;LL_BizObject object;LL_BizSprite sprite;
        if (!ll_bib_get_selector(bib,(uint8_t)args[1],&selector) || selector.value>65535 ||
            !ll_biz_get_object(biz,selector.value,&object) || !ll_biz_get_sprite(biz,object.sprite_index,&sprite))
            return background_fail(background,"native background texture selector has no BIZ sprite");
        int width=(int16_t)args[8],height=(int16_t)args[9];
        if (width<=0 || width>256 || height<=2 || height>256 ||
            width>sprite.width_units*4 || height>sprite.height)
            return background_fail(background,"native background source rectangle exceeds its decoded BIZ sprite");
        if (primitive.rectangle[2]==width && primitive.rectangle[3]==height)
            return background_fail(background,"native unscaled background sprite branch is not ported");
        /* 446b90 ignores sourceX/Y arguments. The page's sprite origin is
         * used, with V+1 and source height-2. Quad UV endpoints are inclusive. */
        primitive.type=0;primitive.object=(uint16_t)selector.value;
        primitive.source[0]=0;primitive.source[1]=1;
        primitive.source[2]=(int16_t)width;primitive.source[3]=(int16_t)(height-2);
    } else {
        primitive.type=(uint8_t)(command==0x124?1:2);
        for (unsigned corner=0;corner<4;corner++) for (unsigned channel=0;channel<3;channel++)
            primitive.color[corner][channel]=(uint8_t)args[5+channel+(command==0x125 && corner>=2?3:0)];
    }
    layer->primitives[layer->primitive_count++]=primitive;return 1;
}

void ll_native_background_update(LL_NativeBackground *background, const int32_t reference[3],
    int16_t pitch, int16_t yaw, uint16_t projection)
{
    background->camera[0]=signed32(0u-(uint32_t)reference[0])/16+ll_native_sine(yaw)/2;
    background->camera[1]=signed32(0u-(uint32_t)reference[1])/64+ll_native_sine(pitch)/96;
    int32_t horizon=ll_native_camera_horizon(pitch,yaw,projection);
    for (unsigned index=0;index<background->layer_count;index++) {
        LL_BackgroundLayer *layer=&background->layers[index];
        if (!layer->enabled) continue;
        for (unsigned axis=0;axis<2;axis++) {
            int extent=layer->rectangle[axis+2];
            int16_t phase=(int16_t)(uint16_t)(layer->phase[axis]+layer->speed[axis]);
            int16_t limit=(int16_t)(uint16_t)(extent*16);
            if (phase>limit) phase=(int16_t)(uint16_t)(phase-extent*16);
            else if (phase<0) phase=(int16_t)(uint16_t)(phase+limit);
            layer->phase[axis]=phase;
            int32_t position=background->camera[axis];
            if (axis==1 && background->reference_y)
                position=signed32((uint32_t)position+(uint32_t)(int32_t)background->reference_y+(uint32_t)horizon);
            int32_t product=signed32((uint32_t)position*(uint32_t)(int32_t)layer->factor[axis]);
            int16_t offset=(int16_t)(uint16_t)(phase/16+product/256);
            layer->origin[axis]=(int16_t)(uint16_t)(offset%extent+layer->rectangle[axis]);
        }
    }
}

int ll_native_background_quad(const LL_NativeBackground *background, unsigned index,
    unsigned primitive_index, LL_BackgroundQuad *quad)
{
    if (!background || !quad || index>=background->layer_count) return 0;
    const LL_BackgroundLayer *layer=&background->layers[index];
    if (!layer->enabled || layer->flags || primitive_index>=layer->primitive_count) return 0;
    const LL_BackgroundPrimitive *primitive=&layer->primitives[primitive_index];
    int16_t origin[2];
    for (unsigned axis=0;axis<2;axis++) {
        int value=(int16_t)(uint16_t)(layer->origin[axis]+primitive->rectangle[axis]);
        int extent=layer->rectangle[axis+2];
        if (value>layer->rectangle[axis]+extent) value=(int16_t)(uint16_t)(value-extent);
        else if (value<layer->rectangle[axis]) value=(int16_t)(uint16_t)(value+extent);
        origin[axis]=(int16_t)value;
    }
    memset(quad,0,sizeof(*quad));quad->textured=primitive->type==0;quad->object=primitive->object;
    for (unsigned corner=0;corner<4;corner++) for (unsigned axis=0;axis<2;axis++) {
        int far=axis==0?(corner&1u)!=0:corner>=2;
        int16_t value=(int16_t)(uint16_t)(origin[axis]+(far?primitive->rectangle[axis+2]:0));
        quad->position[corner][axis]=(int16_t)(uint16_t)((int32_t)value*(axis?480:640)/(axis?256:512));
        quad->uv[corner][axis]=(int16_t)(primitive->source[axis]+(far?primitive->source[axis+2]-1:0));
        for (unsigned channel=0;channel<3;channel++) quad->color[corner][channel]=quad->textured?layer->tint[channel]:
            (uint8_t)((unsigned)primitive->color[corner][channel]*layer->tint[channel]>>7);
    }
    return 1;
}
