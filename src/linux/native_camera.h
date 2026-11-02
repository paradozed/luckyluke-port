#ifndef LL_NATIVE_CAMERA_H
#define LL_NATIVE_CAMERA_H
#include <stdint.h>

/* Native signed-angle lookup; angles use 4096 units per revolution. */
int16_t ll_native_sine(int16_t angle);
int16_t ll_native_cosine(int16_t angle);
/* FUN_0047c630: distinct post-initialization model/part rotation table. */
void ll_native_model_rotation(const int32_t angles[3], int16_t rows[3][3]);
/* Row-major 3x3 composition, aliases allowed; native 32-bit sums and
 * division toward zero followed by 16-bit coefficient narrowing. */
void ll_native_rotation_multiply(const int16_t *left, const int16_t *right, int16_t *out);
void ll_native_rotation_scale(int16_t *matrix, const int32_t scale[3]);
/* Native prescale/SAR12, rotation/SAR12, translation, then signed16 storage. */
void ll_native_vertex_transform(const int16_t *matrix, const int16_t point[3],
                                 const int32_t translation[3], const int32_t *scale,
                                 int16_t out[3]);
/* Row-major zero-roll view rotation, including native vertical compression. */
void ll_native_camera_rotation(int16_t pitch, int16_t yaw, int16_t rows[3][3]);
void ll_native_camera_view(int16_t pitch, int16_t yaw, const int32_t reference[3],
                           uint32_t depth, int16_t rows[3][3], int32_t translation[3]);
/* FUN_00420320/0041f260: native approximate distance, divided by100. */
uint16_t ll_native_distance100(const int32_t a[3], const int32_t b[3]);
uint16_t ll_native_screen_pan(const int32_t a[2], const int32_t b[2]);
/* FUN_00450d80, reference 640x480 projection, zero roll. */
int32_t ll_native_camera_horizon(int16_t pitch, int16_t yaw, uint16_t projection);
void ll_native_camera_screen(const int32_t point[3], const int32_t reference[3],
                             int16_t pitch, int16_t yaw, uint32_t depth,
                             uint16_t projection, int32_t screen[2]);
/* FUN_00451d70's screen-X projection for a zero-roll menu camera.
 * Its center is 256 even when the output surface is 640 pixels wide. */
int32_t ll_native_camera_screen_x(const int32_t point[3], const int32_t reference[3],
                                  int16_t pitch, int16_t yaw, uint32_t depth,
                                  uint16_t projection);
#endif
