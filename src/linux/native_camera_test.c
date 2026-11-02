#include "native_camera.h"
#include <assert.h>
#include <stdio.h>

int main(void)
{
    assert(ll_native_sine(0)==0 && ll_native_cosine(0)==4096);
    int16_t rotation[3][3];
    int16_t fractional[9]={-1,0,0,0,-4095,0,0,0,4096};
    const int16_t near_identity[9]={4095,0,0,0,4095,0,0,0,4095};
    ll_native_rotation_multiply(fractional,near_identity,fractional);
    assert(fractional[0]==0 && fractional[4]==-4094 && fractional[8]==4095);
    int16_t point_to_transform[3]={-1,-1,-1};
    const int32_t pivot[3]={10,20,30}, scale[3]={2048,4096,8192};
    ll_native_vertex_transform(near_identity,point_to_transform,pivot,scale,point_to_transform);
    assert(point_to_transform[0]==9 && point_to_transform[1]==19 && point_to_transform[2]==28);
    const int32_t no_angles[3]={0,0,0};
    ll_native_model_rotation(no_angles,rotation);
    assert(rotation[0][0]==4094 && rotation[1][1]==4094 && rotation[2][2]==4094);
    const int32_t negative_small[3]={-3,0,0}, negative_step[3]={-4,0,0}, positive_step[3]={4,0,0};
    ll_native_model_rotation(negative_small,rotation);assert(rotation[2][1]==0);
    ll_native_model_rotation(negative_step,rotation);assert(rotation[2][1]==-26);
    ll_native_model_rotation(positive_step,rotation);assert(rotation[2][1]==25);
    ll_native_camera_rotation(0,0,rotation);
    assert(rotation[0][0]==4096 && rotation[1][1]==2944 && rotation[2][2]==4096);
    assert(!rotation[0][1] && !rotation[0][2] && !rotation[1][0] &&
           !rotation[1][2] && !rotation[2][0] && !rotation[2][1]);
    ll_native_camera_rotation(0,1024,rotation);
    assert(rotation[0][0]==0 && rotation[0][2]==4096 && rotation[2][0]==-4096);
    for (int yaw=-1600;yaw<=1600;yaw++)
        assert(ll_native_camera_horizon(0,(int16_t)yaw,768)==128);
    assert(ll_native_camera_horizon(71,-549,768)==8);
    assert(ll_native_camera_horizon(39,-1024,768)==63);
    assert(ll_native_camera_horizon(39,-144,768)==63);
    const int32_t origin[3]={0,0,0};
    const int32_t center[2]={0,0};
    const int32_t directions[7][2]={{0,0},{0,1},{1,0},{-1,0},{1,1},{-1,1},{1,-1}};
    const uint16_t pans[7]={1024,1024,0,2048,512,1536,512};
    for (unsigned i=0;i<7;i++) assert(ll_native_screen_pan(center,directions[i])==pans[i]);
    const int32_t vertical[3]={0,1000,0};int32_t screen[2];
    ll_native_camera_screen(vertical,origin,0,0,1000,100,screen);
    assert(screen[0]==256 && screen[1]==199);
    int32_t point[3]={1000,0,0};
    assert(ll_native_camera_screen_x(point,origin,0,0,1000,100)==355);
    point[0]=-1000;
    assert(ll_native_camera_screen_x(point,origin,0,0,1000,100)==156);
    const int positions[5]={3840,3850,3860,-2560,-2570};
    const int expected[5]={639,640,641,0,-1};
    for (unsigned i=0;i<5;i++) {
        point[0]=positions[i];
        assert(ll_native_camera_screen_x(point,origin,0,0,1000,100)==expected[i]);
    }
    point[0]=1000;point[2]=-2000;
    assert(ll_native_camera_screen_x(point,origin,0,0,1000,100)==1256); /* depth clamp */
    const int32_t reference[3]={83400,-3100,-1000};
    int32_t translation[3];
    ll_native_camera_view(0,0,reference,6000,rotation,translation);
    assert(translation[0]==-83400 && translation[1]==2229 && translation[2]==7000);
    assert(ll_native_distance100(origin,origin)==0);
    for (unsigned axis=0;axis<3;axis++) {
        int32_t other[3]={0,0,0};other[axis]=1000;
        assert(ll_native_distance100(origin,other)==10);
        other[axis]=65536;assert(ll_native_distance100(origin,other)==655);
    }
    assert(ll_native_camera_screen_x(reference,reference,71,-549,6000,768)==256);
    /* Every native signed-angle input, including normalization endpoints. */
    for (int angle=-32768;angle<=32767;angle++) {
        int sine=ll_native_sine((int16_t)angle), cosine=ll_native_cosine((int16_t)angle);
        assert(sine>=-4096 && sine<=4096 && cosine>=-4096 && cosine<=4096);
    }
    puts("Native camera lookup bounds, fixed-point projection and screen edges: OK");
    return 0;
}
