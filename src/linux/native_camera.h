#ifndef LL_NATIVE_CAMERA_H
#define LL_NATIVE_CAMERA_H
#include <stdint.h>

/* Native signed-angle lookup; angles use 4096 units per revolution. */
int16_t ll_native_sine(int16_t angle);
int16_t ll_native_cosine(int16_t angle);
/* FUN_004836a0 atan2 conversion, original constants and truncation to16 bits. */
int16_t ll_native_angle(int32_t a, int32_t b);
typedef struct {
    int16_t delta[3], length, distance, yaw, pitch;
    int32_t origin[3];
} LL_NativePathSegmentState;
/* FUN_004562f0 segment reset; narrows differences/length before angle math. */
void ll_native_path_segment_reset(const int32_t start[3], const int32_t end[3],
                                   uint32_t length, LL_NativePathSegmentState *out);
/* FUN_0047c470: recover yaw from matrix coefficients0 and2. Reject scaled
 * coefficients outside the inverse-trigonometric domain; output unchanged. */
int ll_native_model_yaw(const int16_t *matrix, int16_t *yaw);
/* FUN_00408440/FUN_00407700 decision. changed/converged are booleans;
 * next_yaw is meaningful when changed. Invalid matrix leaves outputs intact. */
int ll_native_turn_towards(const int16_t *matrix, const int32_t source[3],
                           const int32_t target[3], uint16_t cone, int16_t step,
                           int16_t *next_yaw, int *changed, int *converged);
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
/* FUN_00482640/00480e20: compose the view and scene-root transform before
 * transforming vertices. Translation and matrix products round separately. */
void ll_native_camera_model_view(const int16_t *view, const int32_t view_translation[3],
                                 const int16_t *model, const int32_t position[3],
                                 int16_t *rows, int32_t translation[3]);
void ll_native_camera_vertex(const int16_t *rows, const int32_t translation[3],
                             const int16_t point[3], int32_t camera[3]);
/* Positive-Z, Y-down perspective for the reference 640x480 scene. Native
 * FUN_004830a0 focal scales; homogeneous coordinates retain near-plane clipping.
 * This is distinct from the fixed (256,128) sound/background queries below. */
void ll_native_camera_projection(uint16_t projection, double matrix[16]);
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
