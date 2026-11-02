#include "bib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIB_SOOL_SIGNATURE "SOOL"
#define BIB_3DX_SIGNATURE "3DX\0"
#define BIB_OFFSET_TABLE 4u
#define BIB_GRID_3DX_DELTA 0x10u
#define BIB_3DX_HEADER_SIZE 0x10u
#define BIB_3DX_RECORD_HEADER_SIZE 0x10u
#define BIB_3DX_RECORD_SIZE 24u
#define BIB_DESCRIPTOR_MIN_SIZE 0xbcu
#define BIB_SOOL_HEADER_SIZE 12u
#define BIB_ANIMATION_HEADER_SIZE 12u
#define BIB_MAX_RECORDS 65535u
#define BIB_MAX_GROUPS 4096u

static uint16_t read_u16le(const unsigned char *p)
{
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

static int16_t read_i16le(const unsigned char *p)
{
    return (int16_t)read_u16le(p);
}

static uint32_t read_u32le(const unsigned char *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static int32_t read_i32le(const unsigned char *p)
{
    return (int32_t)read_u32le(p);
}

int ll_bib_decode_packed_pose(const unsigned char *data, size_t size,
                              LL_BibPackedPose *out_pose)
{
    static const uint16_t group_bits[3] = {0x8000u, 0x4000u, 0x2000u};
    uint32_t cursor = 2;
    if (data == NULL || out_pose == NULL || size < 2) return 0;
    memset(out_pose, 0, sizeof(*out_pose));
    out_pose->flags = read_u16le(data);
    for (uint32_t group = 0; group < 3; group++) {
        if ((out_pose->flags & group_bits[group]) == 0) continue;
        out_pose->present_groups |= (uint8_t)(1u << group);
        for (uint32_t channel = 0; channel < 3; channel++) {
            uint32_t flag = 1u << (group * 3u + channel);
            if ((out_pose->flags & flag) == 0) continue;
            if (size - cursor < 2) return 0;
            out_pose->present_channels[group] |= (uint16_t)(1u << channel);
            out_pose->channels[group * 3u + channel] = read_i16le(data + cursor);
            cursor += 2;
        }
    }
    out_pose->encoded_size = cursor;
    return 1;
}

int ll_bib_prepare_transition_pose(LL_BibPackedPose *snapshot, size_t part_count,
                                   const LL_BibPackedPose *target_root)
{
    if (!snapshot || part_count<2 || !target_root) return 0;
    int16_t translation[3];
    memcpy(translation,target_root->channels+3,sizeof(translation));
    memset(snapshot[0].channels,0,3u*sizeof(snapshot[0].channels[0]));
    memcpy(snapshot[1].channels+3,translation,sizeof(translation));
    return 1;
}

int ll_bib_interpolate_pose(const LL_BibPackedPose *from,
                            const LL_BibPackedPose *to, uint32_t fraction,
                            LL_BibPackedPose *out_pose)
{
    if (from == NULL || to == NULL || out_pose == NULL || fraction > 65536u) return 0;
    LL_BibPackedPose result = {0};
    result.flags = from->flags | to->flags;
    result.present_groups = from->present_groups | to->present_groups;
    for (unsigned group = 0; group < 3; group++) {
        result.present_channels[group] = from->present_channels[group] | to->present_channels[group];
        for (unsigned axis = 0; axis < 3; axis++) {
            unsigned c = group * 3u + axis;
            int32_t delta = (int32_t)to->channels[c] - from->channels[c];
            if (group == 0) {
                if (delta > 2048) delta -= 4096;
                else if (delta < -2048) delta += 4096;
            }
            int64_t product = (int64_t)delta * fraction;
            int64_t step = product >= 0 ? product / 65536 : -((-product + 65535) / 65536);
            result.channels[c] = (int16_t)(from->channels[c] + step);
        }
    }
    *out_pose = result;
    return 1;
}

int ll_bib_decode_animation_frame(const LL_BibFile *bib, uint32_t selector,
                                  uint32_t frame, LL_BibPackedPose *parts,
                                  size_t capacity, uint16_t *out_frame_word)
{
    const LL_BibAnimationTable *table = ll_bib_get_animation_table(bib, selector);
    if (table == NULL || parts == NULL || frame >= table->record_count ||
        table->record_type == 0 || capacity < table->record_type) return 0;
    const LL_BibAnimationRecord *record = &table->records[frame];
    if (record->data == NULL || record->size < 2u) return 0;
    size_t cursor = 2u;
    for (uint32_t part = 0; part < table->record_type; part++) {
        if (cursor > record->size || !ll_bib_decode_packed_pose(record->data + cursor,
                record->size - cursor, &parts[part])) return 0;
        cursor += parts[part].encoded_size;
    }
    if (out_frame_word != NULL) *out_frame_word = read_u16le(record->data);
    return 1;
}

static int range_is_valid(size_t total, uint64_t offset, uint64_t length)
{
    return offset <= total && length <= (uint64_t)total - offset;
}

static uint32_t selector_section_end(const LL_BibFile *bib, uint32_t start)
{
    uint32_t end = (uint32_t)bib->raw_size;
    uint32_t i;
    if (bib->sool_offset > start && bib->sool_offset < end) end = bib->sool_offset;
    for (i = 0; i < bib->selector_count; i++) {
        uint32_t candidate = bib->selectors[i];
        if (candidate > start && candidate < end) end = candidate;
    }
    return end;
}

static void release_parsed_data(LL_BibFile *bib)
{
    uint32_t i;
    if (bib->models != NULL) {
        for (i = 0; i < bib->model_count; i++) {
            for (uint32_t j = 0; j < bib->models[i].group_count; j++)
                free(bib->models[i].groups[j].elements);
            free(bib->models[i].groups);
            free(bib->models[i].vertices);
        }
        free(bib->models);
    }
    for (i = 0; i < bib->selector_count; i++) free(bib->animations[i].records);
    free(bib->animations);
    free(bib->selectors);
    free(bib->sections);
    free(bib->sool_scripts);
    bib->models = NULL;
    bib->sool_scripts = NULL;
    bib->animations = NULL;
    bib->selectors = NULL;
    bib->sections = NULL;
    bib->model_count = 0;
    bib->sool_script_count = 0;
    bib->selector_count = 0;
}

static void free_group_array(LL_BibGeometryGroup *groups, uint32_t count)
{
    for (uint32_t i = 0; i < count; i++) free(groups[i].elements);
    free(groups);
}

static int fail(LL_BibFile *bib, const char *message)
{
    snprintf(bib->error, sizeof(bib->error), "%s", message);
    release_parsed_data(bib);
    bib->valid = 0;
    bib->raw_data = NULL;
    bib->raw_size = 0;
    return 0;
}

static int parse_sool_directory(LL_BibFile *bib)
{
    const unsigned char *data = bib->raw_data;
    const unsigned char *header;
    uint32_t *offsets, *sorted;
    uint32_t i, script_count, valid_count = 0;
    uint32_t table_end;

    if (!range_is_valid(bib->raw_size, bib->sool_offset, BIB_SOOL_HEADER_SIZE))
        return 1; /* Some legacy BIBs use SOOL as an opaque embedded marker. */

    header = data + bib->sool_offset;
    bib->sool_size = read_u32le(header + 4);
    bib->sool_script_count = read_u16le(header + 8);
    bib->sool_header_field = read_u16le(header + 10);
    if (bib->sool_script_count == 0 ||
        bib->sool_script_count > LL_BIB_SOOL_MAX_SCRIPTS ||
        bib->sool_size < BIB_SOOL_HEADER_SIZE ||
        !range_is_valid(bib->raw_size, bib->sool_offset, bib->sool_size)) {
        /* A signature alone is enough for non-SOOL BIB variants. */
        bib->sool_size = 0;
        bib->sool_script_count = 0;
        return 1;
    }
    table_end = BIB_SOOL_HEADER_SIZE + (uint32_t)bib->sool_script_count * 4u;
    if (table_end > bib->sool_size) {
        bib->sool_size = 0;
        bib->sool_script_count = 0;
        return 1;
    }

    offsets = (uint32_t *)calloc(bib->sool_script_count, sizeof(*offsets));
    sorted = (uint32_t *)calloc(bib->sool_script_count, sizeof(*sorted));
    bib->sool_scripts = (LL_BibSoolScript *)calloc(bib->sool_script_count,
                                                    sizeof(*bib->sool_scripts));
    if (offsets == NULL || sorted == NULL || bib->sool_scripts == NULL) {
        free(offsets);
        free(sorted);
        return 0;
    }
    script_count = bib->sool_script_count;
    for (i = 0; i < bib->sool_script_count; i++) {
        uint32_t raw = read_u32le(header + BIB_SOOL_HEADER_SIZE + (size_t)i * 4u);
        offsets[i] = raw >> 16;
        if (offsets[i] == 0 && i + 1u == bib->sool_script_count) {
            script_count--;
            break;
        }
        bib->sool_scripts[i].table_index = (uint16_t)i;
        bib->sool_scripts[i].flags = (uint16_t)raw;
        if (offsets[i] >= table_end && offsets[i] < bib->sool_size) {
            bib->sool_scripts[i].valid = 1;
            sorted[valid_count++] = offsets[i];
        }
    }
    /* The executable indexes scripts by their table ordinal, but their
     * extents are delimited by the next physical offset, not table order. */
    for (i = 1; i < valid_count; i++) {
        uint32_t value = sorted[i], j = i;
        while (j != 0 && sorted[j - 1u] > value) {
            sorted[j] = sorted[j - 1u];
            j--;
        }
        sorted[j] = value;
    }
    bib->sool_script_count = (uint16_t)script_count;
    for (i = 0; i < script_count; i++) {
        LL_BibSoolScript *script = &bib->sool_scripts[i];
        uint32_t offset = offsets[i];
        uint32_t j;
        if (!script->valid) continue;
        uint32_t end = bib->sool_size;
        for (j = 0; j < valid_count; j++)
            if (sorted[j] > offset && sorted[j] < end) end = sorted[j];
        script->offset = bib->sool_offset + offset;
        script->size = end - offset;
        script->data = data + script->offset;
    }
    free(offsets);
    free(sorted);
    return 1;
}

static int parse_animation_table(LL_BibFile *bib, uint32_t selector)
{
    LL_BibSelector *section = &bib->sections[selector];
    LL_BibAnimationTable *table = &bib->animations[selector];
    const unsigned char *bytes;
    uint32_t count, header_end, i;
    uint32_t *offsets;

    if (!section->is_section || section->size < BIB_ANIMATION_HEADER_SIZE) return 1;
    bytes = bib->raw_data + section->offset;
    count = read_u16le(bytes);
    if (count == 0 || count > BIB_MAX_RECORDS) return 1;
    header_end = BIB_ANIMATION_HEADER_SIZE + count * 4u;
    if (header_end > section->size) return 1;

    offsets = (uint32_t *)calloc(count, sizeof(*offsets));
    if (offsets == NULL) return 0;
    for (i = 0; i < count; i++) {
        offsets[i] = read_u32le(bytes + BIB_ANIMATION_HEADER_SIZE + (size_t)i * 4u);
        if (offsets[i] < header_end || offsets[i] >= section->size ||
            (i != 0 && offsets[i] <= offsets[i - 1])) {
            free(offsets);
            return 1; /* This selector is a different section type. */
        }
    }

    table->records = (LL_BibAnimationRecord *)calloc(count, sizeof(*table->records));
    if (table->records == NULL) {
        free(offsets);
        return 0;
    }
    table->selector = selector;
    table->offset = section->offset;
    table->size = section->size;
    table->record_count = (uint16_t)count;
    table->record_type = read_u16le(bytes + 2);
    table->opaque_header = read_u32le(bytes + 4);
    for (uint32_t axis = 0; axis < 3; axis++)
        table->loop_displacement[axis] = read_i16le(bytes + 4u + axis * 2u);
    for (i = 0; i < count; i++) {
        uint32_t end = i + 1u < count ? offsets[i + 1u] : section->size;
        LL_BibAnimationRecord *record = &table->records[i];
        record->offset = section->offset + offsets[i];
        record->size = end - offsets[i];
        record->data = bib->raw_data + record->offset;
        if (record->size >= 2) record->sample_count = read_u16le(record->data);
    }
    free(offsets);
    return 1;
}

static int parse_model_groups(LL_BibFile *bib, LL_Bib3dxModel *model,
                              uint32_t geometry_index)
{
    const unsigned char *data = bib->raw_data;
    LL_Bib3dxModel *geometry = &bib->models[geometry_index];
    uint32_t base = geometry->descriptor_offset;
    uint32_t directory_rel = read_u32le(data + base + 0x44);
    uint64_t directory = (uint64_t)base + directory_rel;
    uint32_t directory_words[5];
    uint32_t group_offset, source_cursor, total = 0, count = 0, capacity = 0;
    LL_BibGeometryGroup *groups = NULL;

    if (!range_is_valid(bib->raw_size, directory, 20))
        return fail(bib, "BIB 3DX model directory is out of bounds");
    for (uint32_t i = 0; i < 5; i++) directory_words[i] = read_u32le(data + directory + i * 4u);
    for (uint32_t i = 0; i < 3; i++) {
        uint64_t absolute = (uint64_t)base + directory_words[i];
        if (absolute > bib->raw_size)
            return fail(bib, "BIB 3DX data region starts beyond end of file");
        model->data_offsets[i] = (uint32_t)absolute;
    }
    if (!range_is_valid(bib->raw_size, (uint64_t)base + directory_words[3], 20))
        return fail(bib, "BIB 3DX group headers are out of bounds");
    group_offset = base + directory_words[3];
    source_cursor = (uint32_t)directory + 20u;
    model->model_directory_offset = (uint32_t)directory;
    model->group_header_offset = group_offset;
    for (uint32_t i = 0; i < 3; i++) {
        uint32_t end = i < 2 ? model->data_offsets[i + 1u] : group_offset;
        if (end < model->data_offsets[i])
            return fail(bib, "BIB 3DX model data regions are not ordered");
        model->data_sizes[i] = end - model->data_offsets[i];
    }
    if ((model->data_sizes[0] % 8u) != 0)
        return fail(bib, "BIB 3DX vertex stream is not an array of 8-byte records");
    model->vertex_count = model->data_sizes[0] / 8u;
    if (model->vertex_count != 0) {
        model->vertices = (LL_BibVertex *)calloc(model->vertex_count,
                                                  sizeof(*model->vertices));
        if (model->vertices == NULL)
            return fail(bib, "cannot allocate BIB 3DX vertex array");
        for (uint32_t i = 0; i < model->vertex_count; i++) {
            const unsigned char *v = data + model->data_offsets[0] + (size_t)i * 8u;
            model->vertices[i].position[0] = read_i16le(v);
            model->vertices[i].position[1] = read_i16le(v + 2);
            model->vertices[i].position[2] = read_i16le(v + 4);
            model->vertices[i].attribute = read_u16le(v + 6);
        }
    }

    while (total < model->element_count) {
        LL_BibGeometryGroup group;
        uint64_t source_size, staging_size, next;
        const unsigned char *header;
        memset(&group, 0, sizeof(group));
        if (count >= BIB_MAX_GROUPS || !range_is_valid(bib->raw_size, group_offset, 20)) {
            free_group_array(groups, count);
            return fail(bib, "BIB 3DX group chain is truncated or too long");
        }
        header = data + group_offset;
        group.type = read_u16le(header);
        group.element_count = read_u16le(header + 2);
        group.decoded_stride = read_u32le(header + 4);
        group.source_size = read_u32le(header + 8);
        group.output_size = read_u32le(header + 12);
        group.header_offset = group_offset;
        group.staging_offset = group_offset + 20u;
        group.data_offset = source_cursor;
        if (group.element_count == 0 || group.decoded_stride == 0 ||
            group.decoded_stride > 4096u || group.source_size == 0 ||
            group.source_size % group.element_count != 0 ||
            total + group.element_count > model->element_count) {
            free_group_array(groups, count);
            return fail(bib, "BIB 3DX group has invalid type/count/stride totals");
        }
        group.source_stride = group.source_size / group.element_count;
        source_size = group.source_size;
        staging_size = (uint64_t)group.element_count * group.decoded_stride;
        if (group.source_stride > 4096u ||
            !range_is_valid(bib->raw_size, group.data_offset, source_size)) {
            free_group_array(groups, count);
            return fail(bib, "BIB 3DX packed primitive stream exceeds file bounds");
        }
        group.data_size = (uint32_t)source_size;
        if (!range_is_valid(bib->raw_size, group.staging_offset, staging_size)) {
            free_group_array(groups, count);
            return fail(bib, "BIB 3DX decoded group staging area exceeds file bounds");
        }
        next = (uint64_t)group.staging_offset + staging_size;
        if (next > UINT32_MAX) {
            free_group_array(groups, count);
            return fail(bib, "BIB 3DX group chain exceeds 32-bit offsets");
        }
        if (count == capacity) {
            uint32_t new_capacity = capacity == 0 ? 4u : capacity * 2u;
            LL_BibGeometryGroup *grown = (LL_BibGeometryGroup *)realloc(
                groups, (size_t)new_capacity * sizeof(*groups));
            if (grown == NULL) {
                free_group_array(groups, count);
                return fail(bib, "cannot allocate BIB 3DX group table");
            }
            groups = grown;
            capacity = new_capacity;
        }
        if (group.type <= 7u) {
            uint32_t indices = (group.type & 1u) == 0 ? 3u : 4u;
            uint32_t attribute_offset = group.type == 3u ? 12u : 8u;
            uint32_t minimum_stride = group.type == 0u || group.type == 1u ? 12u
                                    : (group.type & 1u) == 0 ? 20u : 24u;
            if (group.type >= 6u) minimum_stride = group.type == 6u ? 28u : 36u;
            uint32_t expected_decoded_stride = indices * 4u;
            if (group.source_stride < minimum_stride ||
                group.decoded_stride != expected_decoded_stride) {
                free_group_array(groups, count);
                return fail(bib, "BIB 3DX packed primitive or decoded staging stride is invalid");
            }
            group.elements = (LL_BibGeometryElement *)calloc(group.element_count,
                                                              sizeof(*group.elements));
            if (group.elements == NULL) {
                free_group_array(groups, count);
                return fail(bib, "cannot allocate BIB 3DX primitive records");
            }
            for (uint32_t e = 0; e < group.element_count; e++) {
                const unsigned char *record = data + group.data_offset +
                                              (size_t)e * group.source_stride;
                LL_BibGeometryElement *element = &group.elements[e];
                element->vertex_index_count = (uint8_t)indices;
                for (uint32_t j = 0; j < indices; j++) {
                    element->vertex_indices[j] = read_u16le(record + j * 2u);
                    if (element->vertex_indices[j] >= model->vertex_count) {
                        free(group.elements);
                        free_group_array(groups, count);
                        return fail(bib, "BIB 3DX primitive references a vertex outside its model");
                    }
                }
                if (group.type == 2u || group.type == 3u || group.type >= 6u) {
                    element->has_material = 1;
                    uint32_t material_position = group.type == 2u ? 6u : 8u;
                    if (group.type >= 6u) material_position = group.type == 6u ? 20u : 24u;
                    element->material = read_u16le(record + material_position);
                    /* FUN_0047ea50 relocates this table relative to the
                     * geometry owner; inherited meshes share its materials. */
                    uint64_t material_offset = (uint64_t)base +
                        read_u32le(data + base + 0x3c) +
                        (uint64_t)element->material * 4u;
                    if (!range_is_valid(bib->raw_size, material_offset, 4u)) {
                        free(group.elements);
                        free_group_array(groups, count);
                        return fail(bib, "BIB 3DX material entry exceeds file bounds");
                    }
                    element->biz_object = read_u16le(data + material_offset);
                    element->material_field_02 = read_u16le(data + material_offset + 2u);
                    uint32_t corner_offset = group.type == 2u ? 12u : 16u;
                    if (group.type >= 6u) corner_offset = group.type == 6u ? 22u : 28u;
                    for (uint32_t corner = 0; corner < indices; corner++) {
                        element->corner_data[corner][0] = record[corner_offset + corner * 2u];
                        element->corner_data[corner][1] = record[corner_offset + corner * 2u + 1u];
                    }
                }
                element->attributes = read_u32le(record + attribute_offset);
                if (group.type >= 4u)
                    for (uint32_t corner = 0; corner < indices; corner++)
                        element->corner_colors[corner] = read_u32le(record + 8u + corner * 4u);
            }
        }
        groups[count++] = group;
        total += group.element_count;
        if ((uint64_t)source_cursor + source_size > UINT32_MAX) {
            free_group_array(groups, count);
            return fail(bib, "BIB 3DX packed primitive stream exceeds 32-bit offsets");
        }
        source_cursor += (uint32_t)source_size;
        group_offset = (uint32_t)next;
    }
    model->groups = groups;
    model->group_count = count;
    return 1;
}

static int parse_3dx_catalogue(LL_BibFile *bib)
{
    const unsigned char *data = bib->raw_data;
    uint32_t selector;
    uint32_t model_table_offset;

    for (selector = 0; selector < bib->selector_count; selector++) {
        LL_BibSelector *section = &bib->sections[selector];
        uint64_t root;
        if (!section->is_section || section->size < BIB_GRID_3DX_DELTA + BIB_3DX_HEADER_SIZE)
            continue;
        root = (uint64_t)section->offset + BIB_GRID_3DX_DELTA;
        if (!range_is_valid(bib->raw_size, root, BIB_3DX_HEADER_SIZE) ||
            memcmp(data + root, BIB_3DX_SIGNATURE, 4) != 0) continue;
        bib->grid_section_offset = section->offset;
        bib->grid_selector = selector;
        bib->model_root_offset = (uint32_t)root;
        break;
    }
    if (selector == bib->selector_count) return 1;

    if (range_is_valid(bib->raw_size, bib->grid_section_offset, 16)) {
        const unsigned char *grid = data + bib->grid_section_offset;
        bib->grid_dimensions[0] = read_u16le(grid + 4);
        bib->grid_dimensions[1] = read_u16le(grid + 6);
        bib->grid_dimensions[2] = read_u16le(grid + 8);
        bib->grid_steps[0] = read_i16le(grid + 10);
        bib->grid_steps[1] = read_i16le(grid + 12);
        bib->grid_steps[2] = read_i16le(grid + 14);
    }

    bib->model_count = read_u32le(data + bib->model_root_offset + 4);
    bib->model_stride = read_u32le(data + bib->model_root_offset + 8);
    bib->model_data_base = read_u32le(data + bib->model_root_offset + 12);
    if (bib->model_count == 0 || bib->model_count > 4096 ||
        bib->model_stride < BIB_3DX_RECORD_SIZE || bib->model_stride > 4096 ||
        bib->model_data_base >= bib->raw_size) {
        return fail(bib, "BIB 3DX header has invalid count, stride, or data base");
    }
    model_table_offset = bib->model_root_offset + BIB_3DX_RECORD_HEADER_SIZE;
    if (!range_is_valid(bib->raw_size, model_table_offset,
                        (uint64_t)bib->model_count * bib->model_stride))
        return fail(bib, "BIB 3DX catalogue exceeds the file bounds");
    bib->models = (LL_Bib3dxModel *)calloc(bib->model_count, sizeof(*bib->models));
    if (bib->models == NULL) return fail(bib, "cannot allocate BIB 3DX catalogue");

    for (uint32_t i = 0; i < bib->model_count; i++) {
        const unsigned char *record = data + model_table_offset + (size_t)i * bib->model_stride;
        LL_Bib3dxModel *model = &bib->models[i];
        uint64_t descriptor;
        memcpy(model->name, record, LL_BIB_3DX_NAME_SIZE);
        model->name[LL_BIB_3DX_NAME_SIZE] = '\0';
        model->descriptor_reference = read_u32le(record + 16);
        model->catalogue_field_20 = read_u32le(record + 20);
        descriptor = (uint64_t)bib->grid_section_offset +
                     (uint64_t)model->descriptor_reference * 4u;
        if (!range_is_valid(bib->raw_size, descriptor, BIB_DESCRIPTOR_MIN_SIZE))
            return fail(bib, "BIB 3DX descriptor reference is invalid or truncated");
        model->descriptor_offset = (uint32_t)descriptor;
        model->parent_model_index = UINT32_MAX;
        model->type = data[model->descriptor_offset + 1];
        model->element_count = read_u32le(data + model->descriptor_offset + 0x2c);
        for (uint32_t axis = 0; axis < 3; axis++) {
            model->orientation[axis * 3] = read_i16le(data + model->descriptor_offset + 0x7c + axis * 6u);
            model->orientation[axis * 3 + 1] = read_i16le(data + model->descriptor_offset + 0x7e + axis * 6u);
            model->orientation[axis * 3 + 2] = read_i16le(data + model->descriptor_offset + 0x80 + axis * 6u);
            model->anchor[axis] = read_i32le(data + model->descriptor_offset + 0x90 + axis * 4u);
            model->bounds_min[axis] = read_i32le(data + model->descriptor_offset + 0xa4 + axis * 4u);
            model->bounds_max[axis] = read_i32le(data + model->descriptor_offset + 0xb0 + axis * 4u);
        }
        if (model->element_count > 1000000u)
            return fail(bib, "BIB 3DX descriptor has an unsupported element count");
        {
            uint32_t parent = read_u32le(data + model->descriptor_offset + 8);
            if (parent != 0) {
                if (parent > bib->model_count || parent == i + 1u)
                    return fail(bib, "BIB 3DX descriptor has an invalid parent reference");
                model->parent_model_index = parent - 1u;
            }
        }
    }

    /* A descriptor may inherit its directory and mesh data from a prior
     * catalogue entry. Resolve the 1-based parent chain before reading groups. */
    for (uint32_t i = 0; i < bib->model_count; i++) {
        uint32_t current = i;
        uint32_t depth = 0;
        while (bib->models[current].parent_model_index != UINT32_MAX) {
            current = bib->models[current].parent_model_index;
            if (++depth >= bib->model_count)
                return fail(bib, "BIB 3DX descriptor parent chain contains a cycle");
        }
        bib->models[i].geometry_model_index = current;
        bib->models[i].geometry_descriptor_offset = bib->models[current].descriptor_offset;
    }
    for (uint32_t i = 0; i < bib->model_count; i++) {
        if (!parse_model_groups(bib, &bib->models[i], bib->models[i].geometry_model_index))
            return 0;
    }
    return 1;
}

int ll_bib_open(LL_BibFile *bib, const unsigned char *data, size_t data_size)
{
    if (bib == NULL) return 0;
    memset(bib, 0, sizeof(*bib));
    if (data == NULL) {
        snprintf(bib->error, sizeof(bib->error), "BIB data buffer is null");
        return 0;
    }
    bib->raw_data = data;
    bib->raw_size = data_size;
    if (data_size > UINT32_MAX) return fail(bib, "BIB exceeds the 32-bit offset range");
    if (data_size < BIB_OFFSET_TABLE + 4u)
        return fail(bib, "BIB is truncated before its selector table");

    bib->sool_offset = read_u32le(data);
    if (!range_is_valid(data_size, bib->sool_offset, 4) ||
        memcmp(data + bib->sool_offset, BIB_SOOL_SIGNATURE, 4) != 0)
        return fail(bib, "BIB SOOL offset is out of bounds or has the wrong signature");

    /* The 3DX grid root follows the selector table in every indexed BIB
     * variant examined. Its aligned position determines the table length;
     * the menu happens to have 71 entries, while level BIBs have more. */
    {
        uint32_t pos;
        uint32_t grid = UINT32_MAX;
        for (pos = BIB_SOOL_HEADER_SIZE; pos + 4u <= data_size; pos++) {
            uint32_t candidate;
            if (memcmp(data + pos, BIB_3DX_SIGNATURE, 4) != 0 || pos < 16u) continue;
            candidate = pos - BIB_GRID_3DX_DELTA;
            if (candidate < BIB_OFFSET_TABLE ||
                (candidate - BIB_OFFSET_TABLE) % 4u != 0) continue;
            bib->grid_section_offset = candidate;
            bib->model_root_offset = pos;
            grid = candidate;
            break;
        }
        if (grid != UINT32_MAX) {
            bib->selector_count = (grid - BIB_OFFSET_TABLE) / 4u;
        } else {
            bib->selector_count = LL_BIB_SELECTOR_COUNT;
        }
    }
    if (bib->selector_count == 0 || bib->selector_count > LL_BIB_MAX_SELECTORS ||
        BIB_OFFSET_TABLE + (uint64_t)bib->selector_count * 4u > data_size)
        return fail(bib, "BIB selector table has an invalid entry count");
    bib->selectors = (uint32_t *)calloc(bib->selector_count, sizeof(*bib->selectors));
    bib->sections = (LL_BibSelector *)calloc(bib->selector_count, sizeof(*bib->sections));
    bib->animations = (LL_BibAnimationTable *)calloc(bib->selector_count,
                                                      sizeof(*bib->animations));
    if (bib->selectors == NULL || bib->sections == NULL || bib->animations == NULL)
        return fail(bib, "cannot allocate BIB selector tables");

    for (uint32_t i = 0; i < bib->selector_count; i++) {
        uint32_t offset = read_u32le(data + BIB_OFFSET_TABLE + (size_t)i * 4u);
        if (offset >= data_size)
            return fail(bib, "BIB selector offset points beyond end of file");
        bib->selectors[i] = offset;
        bib->sections[i].value = offset;
        bib->sections[i].offset = offset;
        bib->sections[i].is_section = 1;
        bib->sections[i].size = selector_section_end(bib, offset) - offset;
    }

    if (!parse_sool_directory(bib)) return fail(bib, "cannot allocate BIB SOOL script index");
    for (uint32_t i = 0; i < bib->selector_count; i++) {
        if (!parse_animation_table(bib, i))
            return fail(bib, "cannot allocate BIB animation record index");
    }
    if (!parse_3dx_catalogue(bib)) return 0;
    bib->valid = 1;
    return 1;
}

void ll_bib_close(LL_BibFile *bib)
{
    if (bib == NULL) return;
    release_parsed_data(bib);
    memset(bib, 0, sizeof(*bib));
}

int ll_bib_is_valid(const LL_BibFile *bib)
{
    return bib != NULL && bib->valid && bib->raw_data != NULL;
}

const char *ll_bib_error(const LL_BibFile *bib)
{
    return bib != NULL ? bib->error : "BIB handle is null";
}

int ll_bib_get_selector_offset(const LL_BibFile *bib, uint32_t selector,
                               uint32_t *out_offset)
{
    if (!ll_bib_is_valid(bib) || selector >= bib->selector_count || out_offset == NULL)
        return 0;
    if (!bib->sections[selector].is_section) return 0;
    *out_offset = bib->sections[selector].offset;
    return 1;
}

int ll_bib_get_selector(const LL_BibFile *bib, uint32_t selector,
                        LL_BibSelector *out_selector)
{
    if (!ll_bib_is_valid(bib) || selector >= bib->selector_count || out_selector == NULL)
        return 0;
    *out_selector = bib->sections[selector];
    return 1;
}

int ll_bib_get_scene_pose(const LL_BibFile *bib, uint32_t selector,
                          uint32_t index, LL_BibScenePose *out_pose)
{
    LL_BibSelector section;
    uint32_t directory_size, relative;
    if (out_pose == NULL || !ll_bib_get_selector(bib, selector, &section) ||
        !section.is_section || section.size < 4u) return 0;
    const unsigned char *group = bib->raw_data + section.offset;
    directory_size = read_u32le(group);
    if (directory_size < 4u || directory_size % 4u != 0 ||
        directory_size > section.size || index >= directory_size / 4u) return 0;
    relative = read_u32le(group + (size_t)index * 4u);
    if (relative < directory_size || relative > section.size ||
        section.size - relative < 24u) return 0;
    for (uint32_t axis = 0; axis < 3; axis++) {
        out_pose->position[axis] = read_i32le(group + relative + axis * 4u);
        out_pose->angles[axis] = read_i32le(group + relative + 12u + axis * 4u);
    }
    return 1;
}

const LL_BibAnimationTable *ll_bib_get_animation_table(const LL_BibFile *bib,
                                                       uint32_t selector)
{
    if (!ll_bib_is_valid(bib) || selector >= bib->selector_count ||
        bib->animations[selector].records == NULL) return NULL;
    return &bib->animations[selector];
}

const LL_BibSoolScript *ll_bib_get_sool_script(const LL_BibFile *bib,
                                               uint32_t index)
{
    if (!ll_bib_is_valid(bib) || index >= bib->sool_script_count ||
        bib->sool_scripts == NULL) return NULL;
    return &bib->sool_scripts[index];
}

uint32_t ll_bib_model_count(const LL_BibFile *bib)
{
    return ll_bib_is_valid(bib) ? bib->model_count : 0;
}

uint32_t ll_bib_selector_count(const LL_BibFile *bib)
{
    return ll_bib_is_valid(bib) ? bib->selector_count : 0;
}

const LL_Bib3dxModel *ll_bib_get_model(const LL_BibFile *bib, uint32_t index)
{
    if (!ll_bib_is_valid(bib) || bib->models == NULL || index >= bib->model_count)
        return NULL;
    return &bib->models[index];
}

int ll_bib_get_model_hierarchy_entry(const LL_BibFile *bib, uint32_t model_index,
                                     uint32_t index, int32_t *out_entry)
{
    const LL_Bib3dxModel *model = ll_bib_get_model(bib, model_index);
    uint64_t offset;
    if (model == NULL || out_entry == NULL) return 0;
    uint32_t count = read_u32le(bib->raw_data + model->descriptor_offset + 0x24);
    uint32_t parts = read_u32le(bib->raw_data + model->descriptor_offset + 0x1c);
    if (index >= count || (uint64_t)count * 4u > model->data_sizes[1]) return 0;
    offset = (uint64_t)model->data_offsets[1] + (uint64_t)index * 4u;
    if (!range_is_valid(bib->raw_size, offset, 4u)) return 0;
    int32_t entry = read_i32le(bib->raw_data + offset);
    if (entry < -3 || (entry >= 0 && (uint32_t)entry >= parts)) return 0;
    *out_entry = entry;
    return 1;
}

int ll_bib_build_neutral_vertices(const LL_BibFile *bib, uint32_t model_index,
                                  LL_BibVertex *vertices, size_t capacity)
{
    const LL_Bib3dxModel *model = ll_bib_get_model(bib, model_index);
    if (model == NULL || vertices == NULL || capacity < model->vertex_count) return 0;
    unsigned char *written = calloc(model->vertex_count, 1);
    if (written == NULL) return 0;
    uint32_t count = read_u32le(bib->raw_data + model->descriptor_offset + 0x24);
    memcpy(vertices, model->vertices, model->vertex_count * sizeof(*vertices));
    for (uint32_t i = 0; i < count; i++) {
        int32_t entry;
        LL_BibModelPart part;
        if (!ll_bib_get_model_hierarchy_entry(bib, model_index, i, &entry)) goto invalid;
        /* Matrix-stack operations preserve identity in the neutral pose. */
        if (entry < 0) continue;
        if (!ll_bib_get_model_part(bib, model_index, (uint32_t)entry, &part)) goto invalid;
        int32_t pivot[3] = {0, 0, 0};
        if (i != 0) {
            if (!written[part.pivot_vertex]) goto invalid;
            for (unsigned axis = 0; axis < 3; axis++)
                pivot[axis] = vertices[part.pivot_vertex].position[axis];
        }
        for (uint32_t v = part.first_vertex; v < (uint32_t)part.first_vertex + part.vertex_count; v++) {
            for (unsigned axis = 0; axis < 3; axis++) {
                int32_t value = model->vertices[v].position[axis] + pivot[axis];
                if (value < INT16_MIN || value > INT16_MAX) goto invalid;
                vertices[v].position[axis] = (int16_t)value;
            }
            written[v] = 1;
        }
    }
    for (uint32_t v = 0; v < model->vertex_count; v++) if (!written[v]) goto invalid;
    free(written);
    return 1;
invalid:
    free(written);
    return 0;
}

int ll_bib_get_model_part(const LL_BibFile *bib, uint32_t model_index,
                          uint32_t part_index, LL_BibModelPart *out_part)
{
    const LL_Bib3dxModel *model = ll_bib_get_model(bib, model_index);
    uint64_t offset;
    if (model == NULL || out_part == NULL) return 0;
    uint32_t count = read_u32le(bib->raw_data + model->descriptor_offset + 0x1c);
    if (part_index >= count || (uint64_t)(part_index + 1u) * 12u > model->data_sizes[2]) return 0;
    offset = (uint64_t)model->data_offsets[2] + (uint64_t)part_index * 12u;
    if (!range_is_valid(bib->raw_size, offset, 12u)) return 0;
    const unsigned char *record = bib->raw_data + offset;
    LL_BibModelPart part = {read_u16le(record), read_u16le(record + 2),
        read_u16le(record + 4), read_u16le(record + 6), record[8]};
    if ((uint32_t)part.first_vertex + part.vertex_count > model->vertex_count ||
        part.pivot_vertex >= model->vertex_count) return 0;
    *out_part = part;
    return 1;
}

const LL_Bib3dxModel *ll_bib_find_model(const LL_BibFile *bib, const char *name)
{
    if (!ll_bib_is_valid(bib) || bib->models == NULL || name == NULL) return NULL;
    for (uint32_t i = 0; i < bib->model_count; i++) {
        if (strcmp(bib->models[i].name, name) == 0) return &bib->models[i];
    }
    return NULL;
}

int ll_bib_get_sprite_frame(const LL_BibFile *bib, uint32_t selector,
                            uint32_t frame, LL_BibSpriteFrame *out)
{
    LL_BibSelector section;
    if (out == NULL || !ll_bib_get_selector(bib, selector, &section) ||
        !section.is_section || section.size < 12u ||
        !range_is_valid(bib->raw_size, section.offset, section.size)) return 0;
    const unsigned char *header = bib->raw_data + section.offset;
    uint16_t count = read_u16le(header + 2);
    if (header[4] > 1 || count == 0 || frame >= count ||
        (uint64_t)count * 12u > section.size - 12u) return 0;
    const unsigned char *record = header + 12u + frame * 12u;
    LL_BibSpriteFrame result = {read_u32le(record), read_u16le(record + 4),
        read_u16le(record + 6), read_i16le(record + 8), read_i16le(record + 10)};
    if (result.duration == 0) return 0;
    *out = result;
    return 1;
}
