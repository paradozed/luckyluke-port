#include "native_collision.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static LL_NativeCollisionBody owner(void)
{
    LL_NativeCollisionBody body={0};
    const int32_t bounds[6]={-100,-1000,-100,100,0,100};
    memcpy(body.bounds,bounds,sizeof(bounds));return body;
}

static LL_NativeCollisionBody target(int32_t x, int32_t y, uint32_t flags)
{
    LL_NativeCollisionBody body={0};
    const int32_t bounds[6]={-20,-200,-20,20,0,20};
    memcpy(body.bounds,bounds,sizeof(bounds));body.position[0]=x;body.position[1]=y;
    memcpy(body.previous,body.position,sizeof(body.previous));body.flags=flags;return body;
}

int main(void)
{
    LL_NativeCollisionBody a=owner(),b=target(80,-100,0x20020);
    LL_NativeCollisionLink link={4,0,1,0};
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==121);
    assert(link.flags==0x40 && b.flags==0x20030);
    assert(ll_native_collision_step(&link,&a,&b)==0 && !link.flags && b.flags==0x20020);
    b=target(-80,-100,0x20);assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==-121);
    a=owner();a.flags=2;b=target(80,-100,0x20);link.flags=0;
    assert(ll_native_collision_step(&link,&a,&b)==1 && a.position[0]==-41 && b.position[0]==80 && b.flags==0x24);
    a=owner();a.flags=2;b=target(80,-100,0);link.flags=0;
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==121 && !b.flags);
    a=owner();b=target(80,-100,0x20);link.flags=0x20;
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==121 && b.flags==0x20 && link.flags==0x60);

    /* Mode0's penetration displacement is a signed word; mode1 keeps32 bits. */
    a=owner();a.bounds[0]=-60000;a.bounds[3]=60000;b=target(10000,-100,0);link.flags=0;
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==-5515);
    b=target(10000,-100,0);link.callback_mode=1;
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==60021);

    a=owner();b=target(0,100,0);b.previous[1]=300;link=(LL_NativeCollisionLink){4,0,1,0};
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[1]==200 && !link.flags);
    a=owner();b=target(0,-800,0);b.previous[1]=-1100;
    assert(ll_native_collision_step(&link,&a,&b)==0 && link.callback_mode==4 && link.flags==0x80);
    assert(b.position[1]==-800 && b.flags==0x28); /* No setter at458018. */
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[1]==-1000);
    a.position[0]=10;a.position[1]=-20;a.position[2]=5;link.flags|=0x100;
    assert(ll_native_collision_step(&link,&a,&b)==2);
    assert(b.position[0]==10 && b.position[1]==-1020 && b.position[2]==5 && (b.flags&0x10000));
    b.flags&=~0x20u;
    assert(ll_native_collision_step(&link,&a,&b)==0 && link.callback_mode==0 && !(link.flags&0x80) && !(b.flags&0x10028));
    a=owner();b=target(0,-1200,0x20);link=(LL_NativeCollisionLink){4,0x80,1,4};
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[1]==-1000); /* Cropped target maximumY. */

    a=owner();b=target(0,-701,0x20);link=(LL_NativeCollisionLink){4,0,1,0};
    assert(ll_native_collision_step(&link,&a,&b)==0 && link.callback_mode==4);
    b=target(0,-700,0x20);link=(LL_NativeCollisionLink){4,0,1,0};
    assert(ll_native_collision_step(&link,&a,&b)==2 && link.callback_mode==0 && (link.flags&0x40));
    b=target(0,-900,0);b.previous[1]=-800;a.previous[1]=500;link=(LL_NativeCollisionLink){4,0,1,0};
    assert(ll_native_collision_step(&link,&a,&b)==0 && link.callback_mode==4); /* Moving support's previousY. */

    a=owner();b=target(0,-901,0x20);link=(LL_NativeCollisionLink){4,0,1,1};
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[1]==-1000 && b.flags==0x28 && link.callback_mode==5);
    a.position[0]=50;a.position[1]=-30;
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==50 && b.position[1]==-1030);
    b.position[0]=1000;
    assert(ll_native_collision_step(&link,&a,&b)==0 && link.callback_mode==1 && !(b.flags&0x28));
    a=owner();b=target(0,-900,0x20);link=(LL_NativeCollisionLink){4,0,1,1};
    assert(ll_native_collision_step(&link,&a,&b)==2 && link.callback_mode==1); /*100 is excluded. */

    a=owner();b=target(0,-1000,0);b.previous[1]=-1001;link=(LL_NativeCollisionLink){4,0,1,2};
    assert(ll_native_collision_step(&link,&a,&b)==2 && link.callback_mode==6 && b.flags==0x28);
    b.flags&=~0x20u;
    assert(ll_native_collision_step(&link,&a,&b)==0 && link.callback_mode==2 && !(b.flags&0x28));
    b=target(0,-1000,0);b.previous[1]=-1001;link=(LL_NativeCollisionLink){4,0,1,3};
    assert(ll_native_collision_step(&link,&a,&b)==2 && link.callback_mode==3 && !link.flags);
    b=target(0,-999,0);b.previous[1]=-1001;
    assert(ll_native_collision_step(&link,&a,&b)==2 && link.callback_mode==7 && b.position[1]==-1000);
    a.position[0]=7;a.position[1]=-40;a.position[2]=2;
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==7 && b.position[1]==-1040 && b.position[2]==2);
    b.position[2]=1000;assert(ll_native_collision_step(&link,&a,&b)==0 && link.callback_mode==3);

    a=owner();b=target(0,-500,0);link=(LL_NativeCollisionLink){4,8,1,1};
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[1]==201);
    b=target(0,-100,0);b.position[2]=80;link.flags=16;
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[2]==121 && !b.position[0]);
    b=target(80,-100,0);link.flags=24;
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==121);
    a=owner();a.bounds[0]=-102;a.bounds[3]=99;b=target(-2,-100,0);
    link=(LL_NativeCollisionLink){4,0,1,1};
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==-123); /* -3/2 truncates toward0. */
    a=owner();a.bounds[0]=INT32_MAX-100;a.bounds[3]=INT32_MAX;b=target(INT32_MAX-50,-100,0);
    assert(ll_native_collision_step(&link,&a,&b)==2 && b.position[0]==INT32_MIN+20);
    link.callback_mode=8;LL_NativeCollisionBody original=b;
    assert(ll_native_collision_step(&link,&a,&b)==-1 && !memcmp(&b,&original,sizeof(b)));
    link.callback_mode=0;link.active=0;
    assert(!ll_native_collision_step(&link,&a,&b) && !memcmp(&b,&original,sizeof(b)));
    puts("Native collision sides, head contact, signed penetration, support acquisition/carry/release and four callback modes: OK");
    return 0;
}
