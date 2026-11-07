#ifndef LL_NATIVE_ANIMATION_H
#define LL_NATIVE_ANIMATION_H
#include "bib.h"

/* Assemble decoded BIB poses using the native 12-bit part matrices. The
 * caller initializes vertices with ll_bib_build_neutral_vertices, and supplies
 * an explicit next frame so bounded loops never blend outside their range.
 * Optional initial/evaluated arrays contain animation.record_type poses.
 * Transition fractions are 0..65535. Failure may partially update vertices. */
int ll_native_animation_vertices(const LL_BibFile *bib, uint32_t model_index,
                                  uint16_t selector, uint32_t frame, uint32_t next_frame,
                                  uint32_t fraction, LL_BibVertex *vertices, size_t capacity,
                                  const LL_BibPackedPose *initial, uint32_t initial_fraction,
                                  LL_BibPackedPose *evaluated);
/* FUN_004845e0/00480a40: adjust part1 across a loop seam, then extract one
 * translation axis into the model root. loop_direction is -1,0,+1; root_axis
 * is0..2, or-1 to keep every channel in the skeleton. */
int ll_native_animation_vertices_motion(const LL_BibFile *bib, uint32_t model_index,
                                         uint16_t selector, uint32_t frame, uint32_t next_frame,
                                         uint32_t fraction, LL_BibVertex *vertices, size_t capacity,
                                         const LL_BibPackedPose *initial, uint32_t initial_fraction,
                                         LL_BibPackedPose *evaluated, int root_axis, int loop_direction);
int ll_native_animation_root_translation(const LL_BibFile *bib, uint16_t selector,
                                          uint32_t frame, uint32_t next_frame, uint32_t fraction,
                                          int loop_direction, int16_t translation[3]);
/* Apply expanded part records, including a retained pose after animation
 * release. Parts beyond part_count use their initial zero channels. */
int ll_native_model_pose_vertices(const LL_BibFile *bib, uint32_t model_index,
                                   const LL_BibPackedPose *poses, size_t part_count,
                                   LL_BibVertex *vertices, size_t capacity);
/* Evaluate in a supplied native root basis, before part-matrix rounding.
 * Used by attachments: rotating an already quantized local pivot differs. */
int ll_native_model_pose_vertices_rooted(const LL_BibFile *bib, uint32_t model_index,
                                   const LL_BibPackedPose *poses, size_t part_count,
                                   LL_BibVertex *vertices, size_t capacity, const int16_t root[9]);
#endif
