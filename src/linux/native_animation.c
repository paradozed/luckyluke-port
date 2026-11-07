#include "native_animation.h"
#include "native_camera.h"
#include <stdlib.h>
#include <string.h>

static int frame_poses(const LL_BibFile *bib, const LL_BibAnimationTable *table,
                        uint32_t frame, uint32_t next_frame, uint32_t fraction,
                        int loop_direction, LL_BibPackedPose *poses)
{
    if (fraction>65535u || loop_direction< -1 || loop_direction>1 ||
        !ll_bib_decode_animation_frame(bib,table->selector,frame,poses,table->record_type,NULL)) return 0;
    if (!fraction) return 1;
    LL_BibPackedPose *next=calloc(table->record_type,sizeof(*next));
    if (!next) return 0;
    if (!ll_bib_decode_animation_frame(bib,table->selector,next_frame,next,table->record_type,NULL)) {
        free(next);return 0;
    }
    LL_BibPackedPose root={0};
    if (table->record_type>1) root=poses[1];
    for (unsigned p=0;p<table->record_type;p++) ll_bib_interpolate_pose(&poses[p],&next[p],fraction,&poses[p]);
    if (loop_direction && table->record_type>1 && (poses[1].present_groups&2u)) {
        /* Native4845e0 adds the loop offset before subtracting the source,
         * without narrowing the target to16 bits before multiplication. */
        for (unsigned axis=0;axis<3;axis++) {
            int32_t difference=(int32_t)next[1].channels[3u+axis]+
                loop_direction*table->loop_displacement[axis]-root.channels[3u+axis];
            uint32_t product=(uint32_t)difference*fraction;
            int32_t signed_product;memcpy(&signed_product,&product,sizeof(product));
            int32_t shifted=signed_product>=0?signed_product/65536:
                (int32_t)(-((-(int64_t)signed_product+65535)/65536));
            poses[1].channels[3u+axis]=(int16_t)(uint16_t)(root.channels[3u+axis]+shifted);
        }
    }
    free(next);return 1;
}

int ll_native_animation_root_translation(const LL_BibFile *bib, uint16_t selector,
                                          uint32_t frame, uint32_t next_frame, uint32_t fraction,
                                          int loop_direction, int16_t translation[3])
{
    const LL_BibAnimationTable *table=ll_bib_get_animation_table(bib,selector);
    if (!table || table->record_type<2 || !translation) return 0;
    LL_BibPackedPose *poses=calloc(table->record_type,sizeof(*poses));if (!poses) return 0;
    int ok=frame_poses(bib,table,frame,next_frame,fraction,loop_direction,poses);
    if (ok) for (unsigned axis=0;axis<3;axis++) translation[axis]=poses[1].channels[3u+axis];
    free(poses);return ok;
}

/* Model rotation uses FUN_0047c630, distinct from the camera builder. */
int ll_native_animation_vertices_motion(const LL_BibFile *bib, uint32_t model_index,
                                 uint16_t selector, uint32_t frame, uint32_t next_frame,
                                 uint32_t fraction, LL_BibVertex *vertices, size_t capacity,
                                 const LL_BibPackedPose *initial,
                                 uint32_t initial_fraction, LL_BibPackedPose *evaluated,
                                 int root_axis, int loop_direction)
{
    const LL_Bib3dxModel *model = ll_bib_get_model(bib, model_index);
    const LL_BibAnimationTable *table = ll_bib_get_animation_table(bib, selector);
    if (model == NULL || table == NULL || vertices == NULL || capacity < model->vertex_count ||
        fraction > 65535u || initial_fraction > 65535u || root_axis< -1 || root_axis>2) return 0;
    LL_BibPackedPose *poses = calloc(table->record_type, sizeof(*poses));
    if (poses == NULL) return 0;
    if (!frame_poses(bib,table,frame,next_frame,fraction,loop_direction,poses)) { free(poses);return 0; }
    if (initial) for (unsigned part=0;part<table->record_type;part++)
        ll_bib_interpolate_pose(&initial[part],&poses[part],initial_fraction,&poses[part]);
    if (root_axis>=0 && table->record_type>1) poses[1].channels[3u+(unsigned)root_axis]=0;
    int ok=ll_native_model_pose_vertices(bib,model_index,poses,table->record_type,vertices,capacity);
    if (ok && evaluated) memcpy(evaluated,poses,(size_t)table->record_type*sizeof(*poses));
    free(poses);
    return ok;
}

int ll_native_animation_vertices(const LL_BibFile *bib, uint32_t model_index,
                                  uint16_t selector, uint32_t frame, uint32_t next_frame,
                                  uint32_t fraction, LL_BibVertex *vertices, size_t capacity,
                                  const LL_BibPackedPose *initial, uint32_t initial_fraction,
                                  LL_BibPackedPose *evaluated)
{
    return ll_native_animation_vertices_motion(bib,model_index,selector,frame,next_frame,fraction,
        vertices,capacity,initial,initial_fraction,evaluated,-1,0);
}

int ll_native_model_pose_vertices(const LL_BibFile *bib, uint32_t model_index,
                                   const LL_BibPackedPose *poses, size_t part_count,
                                   LL_BibVertex *vertices, size_t capacity)
{
    return ll_native_model_pose_vertices_rooted(bib,model_index,poses,part_count,vertices,capacity,NULL);
}

int ll_native_model_pose_vertices_rooted(const LL_BibFile *bib, uint32_t model_index,
                                   const LL_BibPackedPose *poses, size_t part_count,
                                   LL_BibVertex *vertices, size_t capacity, const int16_t root[9])
{
    const LL_Bib3dxModel *model=ll_bib_get_model(bib,model_index);
    if (!model || !vertices || capacity<model->vertex_count || (part_count && !poses)) return 0;
    int16_t current[9] = {4096,0,0,0,4096,0,0,0,4096};
    if (root) memcpy(current,root,sizeof(current));
    int16_t saved[64][9];
    size_t depth = 0;
    int ok = 1;
    for (uint32_t i = 0;; i++) {
        int32_t entry;
        if (!ll_bib_get_model_hierarchy_entry(bib, model_index, i, &entry)) break;
        if (entry < 0) {
            if (entry == -2 || entry == -3) {
                if (depth == 0) { ok = 0; break; }
                memcpy(current, saved[--depth], sizeof(current));
            }
            if (entry == -1 || entry == -3) {
                if (depth == 64) { ok = 0; break; }
                memcpy(saved[depth++], current, sizeof(current));
            }
            continue;
        }
        LL_BibModelPart part;
        if (!ll_bib_get_model_part(bib, model_index, (uint32_t)entry, &part)) { ok = 0; break; }
        /* FUN_00483e30 copies min(animation parts, model parts). Remaining
         * expanded records retain their initial zero channels. */
        const LL_BibPackedPose zero={0};
        const LL_BibPackedPose *pose = (uint32_t)entry<part_count ? &poses[entry] : &zero;
        int32_t pivot[3] = {0,0,0};
        if (i != 0) for (unsigned a = 0; a < 3; a++) pivot[a] = vertices[part.pivot_vertex].position[a];
        int16_t basis[9];
        memcpy(basis,current,sizeof(basis));
        if (pose->present_groups & 2u) {
            int16_t offset[3]={pose->channels[3],pose->channels[4],pose->channels[5]}, translated[3];
            ll_native_vertex_transform(basis,offset,pivot,NULL,translated);
            for (unsigned axis=0;axis<3;axis++) pivot[axis]=translated[axis];
        }
        /* FUN_004824a0 installs each pivot as the current translation.
         * Explicit translation channels are offsets from that pivot, rotated
         * through the current parent basis. */
        if (pose->present_groups & 1u) {
            int32_t angles[3] = {pose->channels[0],pose->channels[1],pose->channels[2]};
            int16_t local[3][3], composed[9];
            ll_native_model_rotation(angles,local);
            ll_native_rotation_multiply(basis,&local[0][0],composed);
            memcpy(basis,composed,sizeof(basis));
            memcpy(current,composed,sizeof(current));
        }
        int32_t scale[3]={4096+pose->channels[6],4096+pose->channels[7],4096+pose->channels[8]};
        int has_scale=(pose->present_groups & 4u)!=0;
        int32_t next_entry=0;
        if (has_scale && (pose->present_groups & 2u) &&
            ll_bib_get_model_hierarchy_entry(bib,model_index,i+1u,&next_entry) &&
            (next_entry==-2 || next_entry==-3)) {
            /* FUN_004823e0 branch: quantize the scaled basis, rather
             * than prescaling each source vertex (FUN_0047f830). */
            ll_native_rotation_scale(basis,scale);
            memcpy(current,basis,sizeof(current));
            has_scale=0;
        }
        for (uint32_t v = part.first_vertex; v < (uint32_t)part.first_vertex + part.vertex_count; v++) {
            ll_native_vertex_transform(basis,model->vertices[v].position,pivot,
                has_scale ? scale : NULL,vertices[v].position);
        }
    }
    return ok;
}
