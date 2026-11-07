#include "native_background.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    LL_NativeBackground background;ll_native_background_init(&background,3,140);
    assert(background.wrapper_word==3 && background.reference_y==-74);
    const uint16_t sky[]={0,(uint16_t)(int16_t)-256,512,768,0};uint16_t index=99;
    assert(ll_native_background_layer(&background,sky,&index) && index==0);
    const uint16_t sky_motion[]={0,0,0,0,128};
    assert(ll_native_background_command(&background,0x126,sky_motion,5,NULL,NULL));
    const int32_t zero[3]={0,0,0};
    ll_native_background_update(&background,zero,0,0,804);
    assert(background.layers[0].factor[1]==68 && background.layers[0].origin[1]==-242);

    ll_native_background_init(&background,3,0);
    const uint16_t bounds[]={0,0,100,100,65535};
    assert(ll_native_background_layer(&background,bounds,&index) && index==0);
    assert(background.layers[0].order==4094 && background.layers[0].enabled);
    const uint16_t color[]={0,10,20,30,40,255,128,1};
    assert(ll_native_background_command(&background,0x124,color,8,NULL,NULL));
    LL_BackgroundQuad quad;
    assert(ll_native_background_quad(&background,0,0,&quad));
    assert(!quad.textured && quad.position[0][0]==12 && quad.position[0][1]==37);
    assert(quad.position[3][0]==50 && quad.position[3][1]==112);
    background.layers[0].tint[0]=255;background.layers[0].tint[2]=64;
    assert(ll_native_background_quad(&background,0,0,&quad));
    assert(quad.color[0][0]==252 && quad.color[0][1]==128 && !quad.color[0][2]);
    const uint16_t motion[]={0,(uint16_t)(int16_t)-4,(uint16_t)(int16_t)-4,128,240};
    assert(ll_native_background_command(&background,0x126,motion,5,NULL,NULL));
    const int32_t reference[3]={160,640,0};
    ll_native_background_update(&background,reference,0,0,804);
    assert(background.camera[0]==-10 && background.camera[1]==-10);
    assert(background.layers[0].phase[0]==1596 && background.layers[0].phase[1]==1598);
    assert(background.layers[0].origin[0]==94 && background.layers[0].origin[1]==94);
    assert(ll_native_background_quad(&background,0,0,&quad));
    assert(quad.position[0][0]==5 && quad.position[0][1]==26 && quad.position[3][1]==101);
    for (unsigned i=0;i<15;i++) ll_native_background_update(&background,reference,0,0,804);
    assert(background.layers[0].origin[0]==91 && background.layers[0].origin[1]==93);
    uint16_t enable[]={0,0};
    assert(ll_native_background_command(&background,0x12c,enable,2,NULL,NULL));
    LL_BackgroundLayer frozen=background.layers[0];
    ll_native_background_update(&background,zero,800,700,804);
    assert(!memcmp(&frozen,&background.layers[0],sizeof(frozen)));
    assert(!ll_native_background_quad(&background,0,0,&quad));
    enable[1]=1;assert(ll_native_background_command(&background,0x12c,enable,2,NULL,NULL));
    uint16_t flags[]={0,0,1};
    assert(ll_native_background_command(&background,0x128,flags,3,NULL,NULL));
    assert(background.layers[0].flags==4 && !ll_native_background_quad(&background,0,0,&quad));

    ll_native_background_init(&background,3,0);
    assert(ll_native_background_layer(&background,bounds,&index));
    const uint16_t gradient[]={0,0,0,10,20,10,20,30,40,50,60};
    assert(ll_native_background_command(&background,0x125,gradient,11,NULL,NULL));
    assert(ll_native_background_quad(&background,0,0,&quad));
    assert(quad.color[0][0]==10 && quad.color[1][2]==30 && quad.color[2][0]==40 && quad.color[3][2]==60);

    LL_BibSelector selector={0};LL_BibFile bib={0};
    bib.valid=1;bib.selector_count=1;bib.sections=&selector;
    unsigned char raw[24]={0};raw[8]=64;raw[10]=65;raw[21]=81;
    bib.raw_data=raw;bib.raw_size=sizeof(raw);
    LL_BizFile biz={0};biz.valid=1;biz.raw_data=raw;biz.raw_size=sizeof(raw);
    biz.counts[0]=biz.counts[1]=biz.counts[2]=1;biz.sprite_offset=4;
    uint16_t sprite[]={256,256,0,0,384,65,999,888,256,65};
    assert(ll_native_background_command(&background,0x123,sprite,10,&bib,&biz));
    assert(ll_native_background_quad(&background,0,1,&quad));
    assert(quad.textured && !quad.object && quad.uv[0][0]==0 && quad.uv[0][1]==1);
    assert(quad.uv[3][0]==255 && quad.uv[3][1]==63 && quad.color[0][0]==128);
    sprite[8]=257;
    assert(!ll_native_background_command(&background,0x123,sprite,10,&bib,&biz));
    assert(background.layers[0].primitive_count==2);
    sprite[8]=256;sprite[4]=256;
    assert(!ll_native_background_command(&background,0x123,sprite,10,&bib,&biz));
    assert(strstr(background.error,"unscaled") && background.layers[0].primitive_count==2);
    const uint16_t invalid[]={0,0,0,100,0};
    assert(!ll_native_background_layer(&background,invalid,&index) && background.layer_count==1);
    assert(!ll_native_background_command(&background,0x124,color,7,NULL,NULL));
    assert(!ll_native_background_quad(&background,16,0,&quad));
    puts("Native background layers, signed parallax, pixel quantization, colors and BIZ source bounds: OK");
    return 0;
}
