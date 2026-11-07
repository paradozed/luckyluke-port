#include "native_camera.h"
#include <math.h>
#include <string.h>
#include "native_trig.inc"

static unsigned angle_index(int16_t angle)
{
    int index=(int)angle+4096;
    while (index<0) index+=4096;
    while (index>8192) index-=4096;
    return (unsigned)index;
}

int16_t ll_native_sine(int16_t angle) { return native_sine[angle_index(angle)]; }
int16_t ll_native_cosine(int16_t angle) { return native_cosine[angle_index(angle)]; }

int16_t ll_native_angle(int32_t a, int32_t b)
{
    /* FUN_004836a0: CRT atan2 descriptor at004c76b0; constants at
     * 004b8e40/004b8e38. Conversion truncates toward zero. */
    return (int16_t)(atan2(a,b)*57.29694043887547*11.378);
}

void ll_native_path_segment_reset(const int32_t start[3], const int32_t end[3],
                                   uint32_t length, LL_NativePathSegmentState *out)
{
    LL_NativePathSegmentState state={0};
    for (unsigned i=0;i<3;i++) {
        uint16_t word=(uint16_t)((uint32_t)end[i]-(uint32_t)start[i]);
        state.delta[i]=(int16_t)(word<32768?(int32_t)word:(int32_t)word-65536);
        state.origin[i]=start[i];
    }
    uint16_t word=(uint16_t)length;
    state.length=(int16_t)(word<32768?(int32_t)word:(int32_t)word-65536);
    state.yaw=(int16_t)((ll_native_angle(state.delta[2],state.delta[0])+1024)&4095);
    state.pitch=ll_native_angle(state.delta[1],state.length);
    *out=state;
}

int ll_native_model_yaw(const int16_t *matrix, int16_t *yaw)
{
    if (!matrix || !yaw || matrix[0]<-4096 || matrix[0]>4096 ||
        matrix[2]<-4096 || matrix[2]>4096) return 0;
    /* Original constants at004b8e10..004b8e30 differ from atan2's. */
    int angle=(int)(acos(matrix[0]/4096.0)*57.29577950560105*11.3777777778);
    double sine_angle=asin(matrix[2]/4096.0)*57.29577950560105*11.37777777778;
    if (sine_angle<0) sine_angle=4096.0-sine_angle;
    if ((int)sine_angle<2048) angle=(-angle)&4095;
    *yaw=(int16_t)angle;
    return 1;
}

int ll_native_turn_towards(const int16_t *matrix, const int32_t source[3],
                           const int32_t target[3], uint16_t cone, int16_t step,
                           int16_t *next_yaw, int *changed, int *converged)
{
    int16_t yaw;
    if (!source || !target || !next_yaw || !changed || !converged ||
        !ll_native_model_yaw(matrix,&yaw)) return 0;
    uint32_t word=(uint32_t)target[0]-(uint32_t)source[0];
    int32_t dx,dz;memcpy(&dx,&word,sizeof(word));
    word=(uint32_t)target[2]-(uint32_t)source[2];memcpy(&dz,&word,sizeof(word));
    *changed=0;*converged=0;*next_yaw=yaw;
    if (!dx && !dz) return 1;
    int32_t negative_z;word=0u-(uint32_t)dz;memcpy(&negative_z,&word,sizeof(word));
    unsigned relative=(unsigned)(ll_native_angle(negative_z,dx)-1024+yaw)&4095u;
    unsigned tolerance=cone&4095u;
    int64_t absolute_x=dx<0?-(int64_t)dx:dx;
    if (!(relative<tolerance || relative>4096u-tolerance) || absolute_x>=10000) return 1;
    int32_t negative_x;word=0u-(uint32_t)dx;memcpy(&negative_x,&word,sizeof(word));
    unsigned desired=(unsigned)ll_native_angle(negative_z,negative_x)&4095u;
    unsigned current=(unsigned)(yaw+1024)&4095u;
    int difference=(int)desired-(int)current;
    if (difference<0) difference=-difference;
    *changed=1;
    if (difference<100) {
        *next_yaw=(int16_t)(desired-1024u);*converged=1;
    } else {
        int value=(int)current+(desired<current?-(int)step:(int)step)-1024;
        *next_yaw=(int16_t)value;
    }
    return 1;
}

uint16_t ll_native_distance100(const int32_t a[3], const int32_t b[3])
{
    uint16_t delta[3];
    for (unsigned i=0;i<3;i++) {
        int64_t difference=(int64_t)a[i]-b[i];
        uint64_t absolute=(uint64_t)(difference<0 ? -difference : difference);
        if (absolute>65535u) return 65535u/100u;
        delta[i]=(uint16_t)absolute;
    }
    uint16_t length=delta[0];
    if (delta[2]) {
        uint16_t cosine=(uint16_t)ll_native_cosine(ll_native_angle(delta[0],delta[2]));
        if (cosine>=499) length=(uint16_t)(((uint32_t)delta[2]*4096u)/cosine);
    }
    if (length) {
        uint16_t cosine=(uint16_t)ll_native_cosine(ll_native_angle(delta[1],length));
        length=cosine>=499 ? (uint16_t)(((uint32_t)length*4096u)/cosine) : delta[1];
    } else length=delta[1];
    if (length<delta[0] || length<delta[1] || length<delta[2]) length=65535;
    return length/100u;
}

static int32_t signed32(uint32_t value)
{
    return value>INT32_MAX ? (int32_t)((int64_t)value-4294967296LL) : (int32_t)value;
}

uint16_t ll_native_screen_pan(const int32_t a[2], const int32_t b[2])
{
    int32_t dx=signed32((uint32_t)b[0]-(uint32_t)a[0]);
    int32_t dy=signed32((uint32_t)b[1]-(uint32_t)a[1]);
    if (!dx) return 1024;
    if (!dy) return dx>0 ? 0 : 2048;
    int32_t abs_y=dy<0 ? signed32(0u-(uint32_t)dy) : dy;
    int32_t abs_x=dx<0 ? signed32(0u-(uint32_t)dx) : dx;
    int16_t angle=ll_native_angle(abs_y,abs_x);
    return (uint16_t)(dx>0 ? angle : 2048-angle);
}

static int32_t sar12(uint32_t value)
{
    int32_t number=signed32(value);
    return number>=0 ? number/4096 : (int32_t)(-((-(int64_t)number+4095)/4096));
}

static int16_t narrow16(int32_t value)
{
    uint16_t bits=(uint16_t)value;
    return (int16_t)(bits>INT16_MAX ? (int32_t)bits-65536 : bits);
}

void ll_native_rotation_scale(int16_t *matrix, const int32_t scale[3])
{
    for (unsigned i=0;i<9;i++)
        matrix[i]=narrow16(sar12((uint32_t)(int32_t)matrix[i]*(uint32_t)scale[i%3u]));
}

void ll_native_vertex_transform(const int16_t *matrix, const int16_t point[3],
                                 const int32_t translation[3], const int32_t *scale,
                                 int16_t out[3])
{
    int16_t scaled[3];
    for (unsigned axis=0;axis<3;axis++) scaled[axis]=scale
        ? narrow16(sar12((uint32_t)(int32_t)point[axis]*(uint32_t)scale[axis])) : point[axis];
    int16_t result[3];
    for (unsigned row=0;row<3;row++) {
        uint32_t sum=0;
        for (unsigned axis=0;axis<3;axis++)
            sum+=(uint32_t)((int32_t)matrix[row*3u+axis]*scaled[axis]);
        result[row]=narrow16(signed32((uint32_t)sar12(sum)+(uint32_t)translation[row]));
    }
    memcpy(out,result,sizeof(result));
}

void ll_native_rotation_multiply(const int16_t *left, const int16_t *right, int16_t *out)
{
    int16_t result[9];
    for (unsigned row=0;row<3;row++)
        for (unsigned column=0;column<3;column++) {
            uint32_t sum=0;
            for (unsigned axis=0;axis<3;axis++)
                sum+=(uint32_t)((int32_t)left[row*3u+axis]*right[axis*3u+column]);
            int32_t quotient=signed32(sum)/4096;
            uint16_t bits=(uint16_t)quotient;
            result[row*3u+column]=(int16_t)(bits>INT16_MAX ? (int32_t)bits-65536 : bits);
        }
    memcpy(out,result,sizeof(result));
}

void ll_native_model_rotation(const int32_t angles[3], int16_t rows[3][3])
{
    int32_t s[3],c[3];
    for (unsigned axis=0;axis<3;axis++) {
        int angle=(int16_t)angles[axis];
        unsigned index=(unsigned)(angle/4)&1023u;
        s[axis]=native_model_sine[index];
        c[axis]=native_model_sine[(index+256u)&1023u];
    }
    int32_t sxsy=sar12((uint32_t)(s[0]*s[1]));
    int32_t sxcy=sar12((uint32_t)(s[0]*c[1]));
    rows[0][0]=(int16_t)sar12((uint32_t)(c[1]*c[2]+sxsy*s[2]));
    rows[0][1]=(int16_t)sar12((uint32_t)(-s[2]*c[0]));
    rows[0][2]=(int16_t)sar12((uint32_t)(sxcy*s[2]-s[1]*c[2]));
    rows[1][0]=(int16_t)sar12((uint32_t)(s[2]*c[1]-sxsy*c[2]));
    rows[1][1]=(int16_t)sar12((uint32_t)(c[0]*c[2]));
    rows[1][2]=(int16_t)sar12((uint32_t)(-sxcy*c[2]-s[1]*s[2]));
    rows[2][0]=(int16_t)sar12((uint32_t)(c[0]*s[1]));
    rows[2][1]=(int16_t)s[0];
    rows[2][2]=(int16_t)sar12((uint32_t)(c[0]*c[1]));
}

static int32_t transform(const int16_t row[3], const int32_t point[3])
{
    uint32_t sum=0;
    for (unsigned i=0;i<3;i++) sum+=(uint32_t)(int32_t)row[i]*(uint32_t)point[i];
    return sar12(sum);
}

void ll_native_camera_rotation(int16_t pitch, int16_t yaw, int16_t rows[3][3])
{
    int16_t sp=ll_native_sine(pitch), cp=ll_native_cosine(pitch);
    int16_t sy=ll_native_sine(yaw), cy=ll_native_cosine(yaw);
    /* FUN_00482a90: Rx*Ry, matrix products divide toward zero.
     * FUN_0047ca90 then compresses only the Y row. */
    rows[0][0]=cy;rows[0][1]=0;rows[0][2]=sy;
    rows[1][0]=(int16_t)((int32_t)sp*sy/4096);rows[1][1]=cp;
    rows[1][2]=(int16_t)(-(int32_t)sp*cy/4096);
    for (unsigned i=0;i<3;i++) rows[1][i]=(int16_t)((int32_t)rows[1][i]*368/512);
    rows[2][0]=(int16_t)(-(int32_t)cp*sy/4096);rows[2][1]=sp;
    rows[2][2]=(int16_t)((int32_t)cp*cy/4096);
}

int32_t ll_native_camera_horizon(int16_t pitch, int16_t yaw, uint16_t projection)
{
    int16_t rows[3][3];ll_native_camera_rotation(pitch,yaw,rows);
    /* Transpose view rotation, transform (0,0,32000), then flatten Y.
     * Reproject using the original rotation and zero translation. */
    int32_t direction[3]={sar12((uint32_t)(int32_t)rows[2][0]*32000u),0,
                          sar12((uint32_t)(int32_t)rows[2][2]*32000u)};
    int32_t y=transform(rows[1],direction), z=transform(rows[2],direction);
    int32_t product=signed32((uint32_t)y*((uint32_t)projection*2u));
    int32_t projected=z ? (int32_t)((int64_t)product/z) : product;
    uint16_t bits=(uint16_t)((uint32_t)projected+128u);
    return bits>INT16_MAX ? (int32_t)bits-65536 : bits;
}

void ll_native_camera_view(int16_t pitch, int16_t yaw, const int32_t reference[3],
                           uint32_t depth, int16_t rows[3][3], int32_t translation[3])
{
    ll_native_camera_rotation(pitch,yaw,rows);
    for (unsigned axis=0;axis<3;axis++)
        translation[axis]=signed32((axis==2 ? depth : 0u)-(uint32_t)transform(rows[axis],reference));
}

void ll_native_camera_model_view(const int16_t *view, const int32_t view_translation[3],
                                 const int16_t *model, const int32_t position[3],
                                 int16_t *rows, int32_t translation[3])
{
    int32_t result[3];
    for (unsigned axis=0;axis<3;axis++)
        result[axis]=signed32((uint32_t)transform(view+axis*3u,position)+
                             (uint32_t)view_translation[axis]);
    ll_native_rotation_multiply(view,model,rows);
    memcpy(translation,result,sizeof(result));
}

void ll_native_camera_vertex(const int16_t *rows, const int32_t translation[3],
                             const int16_t point[3], int32_t camera[3])
{
    int32_t input[3]={point[0],point[1],point[2]}, result[3];
    for (unsigned axis=0;axis<3;axis++)
        result[axis]=signed32((uint32_t)transform(rows+axis*3u,input)+
                             (uint32_t)translation[axis]);
    memcpy(camera,result,sizeof(result));
}

void ll_native_camera_projection(uint16_t projection, double matrix[16])
{
    /* FUN_004830a0 stores float ratios, multiplies, then truncates to int.
     * The original scene uses the output center, not the sound query center.
     * Near/far clipping are OpenGL presentation policy, not native constants. */
    int32_t focal_x=(int32_t)(projection*(640.0f/448.0f));
    int32_t focal_y=(int32_t)(projection*(480.0f/240.0f));
    const double near=1.0, far=200000.0;
    memset(matrix,0,16*sizeof(*matrix));
    matrix[0]=2.0*focal_x/640.0;
    matrix[5]=-2.0*focal_y/480.0;
    matrix[10]=(far+near)/(far-near);
    matrix[11]=1.0;
    matrix[14]=-2.0*far*near/(far-near);
}

void ll_native_camera_screen(const int32_t point[3], const int32_t reference[3],
                                  int16_t pitch, int16_t yaw, uint32_t depth,
                                  uint16_t projection, int32_t screen[2])
{
    int16_t rows[3][3];ll_native_camera_rotation(pitch,yaw,rows);
    int32_t x=signed32((uint32_t)transform(rows[0],point)-(uint32_t)transform(rows[0],reference));
    int32_t y=signed32((uint32_t)transform(rows[1],point)-(uint32_t)transform(rows[1],reference));
    int32_t z=signed32((uint32_t)transform(rows[2],point)-(uint32_t)transform(rows[2],reference)+depth);
    if (z<100) z=100;
    uint32_t factor=((uint32_t)projection*4096u)/(uint32_t)z;
    screen[0]=signed32((uint32_t)sar12((uint32_t)x*factor)+256u);
    screen[1]=signed32((uint32_t)sar12((uint32_t)y*factor)+128u);
}

int32_t ll_native_camera_screen_x(const int32_t point[3], const int32_t reference[3],
                                  int16_t pitch, int16_t yaw, uint32_t depth,
                                  uint16_t projection)
{
    int32_t screen[2];
    ll_native_camera_screen(point,reference,pitch,yaw,depth,projection,screen);
    return screen[0];
}
