#include "native_ballistic.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    LL_NativeBallistic body={{-230,-50,60},0,0};int32_t position[3]={1000,-1000,200};
    assert(ll_native_ballistic_step(&body,position,100,10,30,2)==0);
    assert(position[0]==775 && position[1]==-1035 && position[2]==265);
    assert(body.velocity[0]==-220 && body.velocity[1]==-20 && body.velocity[2]==50);
    assert(ll_native_ballistic_step(&body,position,100,10,30,3)==0);
    assert(position[0]==455 && position[1]==-1035 && position[2]==350);
    assert(body.velocity[0]==-205 && body.velocity[1]==25 && body.velocity[2]==35);
    body=(LL_NativeBallistic){{10,0,-10},0,0};position[1]=-1000;
    int32_t x=position[0],z=position[2];
    assert(!ll_native_ballistic_step(&body,position,100,10,0,3));
    assert(position[0]==x && position[2]==z && body.velocity[0]==-5 && body.velocity[2]==5);
    body=(LL_NativeBallistic){{9,0,-9},0,0};
    assert(!ll_native_ballistic_step(&body,position,100,10,0,3));
    assert(position[0]==x && position[2]==z && !body.velocity[0] && !body.velocity[2]);
    body=(LL_NativeBallistic){{100,20,0},0,0};position[0]=0;position[1]=90;
    assert(!ll_native_ballistic_step(&body,position,100,10,30,2));
    assert(position[0]==105 && position[1]==101 && body.velocity[0]==90 && body.velocity[1]==50);
    assert(ll_native_ballistic_step(&body,position,100,10,30,2)==1);
    assert(position[0]==200 && position[1]==101 && !body.velocity[0] && !body.velocity[1]);
    /* The incoming Y controls stopping even when this move goes above the floor. */
    body=(LL_NativeBallistic){{0,-50,0},0,0};position[1]=100;
    assert(ll_native_ballistic_step(&body,position,100,10,30,2)==1 && position[1]==65);
    for (unsigned direction=0;direction<3;direction++) {
        body=(LL_NativeBallistic){{100,20,-30},3,(uint8_t)(direction?direction==1?1:255:0)};
        position[1]=101;
        assert(!ll_native_ballistic_step(&body,position,100,10,30,2));
        assert(body.bounce_count==2 && body.velocity[1]==-7);
        assert(body.velocity[0]==(direction?17:-23) && body.velocity[2]==body.velocity[0]);
    }
    body=(LL_NativeBallistic){{5,20,30},1,0};position[1]=101;
    assert(!ll_native_ballistic_step(&body,position,100,10,0,2));
    assert(!body.bounce_count && !body.velocity[0] && body.velocity[2]==-21 && body.velocity[1]==-9);
    assert(ll_native_ballistic_step(&body,position,100,10,0,2)==1 && position[1]==92);
    body=(LL_NativeBallistic){{1,1,1},0x8000,1};position[1]=101;
    assert(ll_native_ballistic_step(&body,position,100,0,30,2)==1 && body.bounce_count==0x8000);
    body=(LL_NativeBallistic){{INT32_MAX,INT32_MAX,INT32_MIN},0,0};
    position[0]=INT32_MIN;position[1]=-1;position[2]=7;
    assert(!ll_native_ballistic_step(&body,position,100,0,0,2));
    assert(position[0]==INT32_MAX && position[1]==-2 && position[2]==7);
    assert(body.velocity[0]==INT32_MAX && body.velocity[1]==300 && !body.velocity[2]);
    body=(LL_NativeBallistic){{100,-50,0},0,0};position[0]=0;position[1]=-1000;
    assert(!ll_native_ballistic_step(&body,position,100,10,30,-3));
    assert(position[0]==-140 && position[1]==-895 && body.velocity[0]==115 && body.velocity[1]==-95);
    LL_NativeBallistic retained=body;int32_t before[3];memcpy(before,position,sizeof(before));
    assert(ll_native_ballistic_step(NULL,position,100,10,30,2)==-1 && !memcmp(before,position,sizeof(before)));
    assert(ll_native_ballistic_step(&body,NULL,100,10,30,2)==-1 && !memcmp(&retained,&body,sizeof(body)));
    puts("Native ballistic displacement, delayed floor decision, signed drag, bounce flags and wrapped arithmetic: OK");
    return 0;
}
