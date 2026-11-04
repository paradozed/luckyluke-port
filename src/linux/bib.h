#ifndef LL_BIB_H
#define LL_BIB_H

#include <stddef.h>
#include <stdint.h>

/* 71 is the menu BIB's selector count; other files use a variable-length table.
 * Selector values are offsets relative to the BIB base. */
#define LL_BIB_SELECTOR_COUNT 71u
#define LL_BIB_MAX_SELECTORS 4096u
#define LL_BIB_3DX_NAME_SIZE 16u
#define LL_BIB_SOOL_MAX_SCRIPTS 4096u

typedef struct {
    int32_t position[3];
    int32_t angles[3]; /* stored DWORDs, narrowed by the native handler */
} LL_BibScenePose;

typedef struct {
    uint16_t vertex_indices[4];
    uint16_t material;
    uint16_t biz_object; /* first word of descriptor +0x3c material entry */
    uint16_t material_field_02;
    uint8_t vertex_index_count;
    int has_material;
    uint32_t attributes;
    uint32_t corner_colors[4]; /* Gouraud groups 4..7, raw packed colors */
    uint8_t corner_data[4][2];
} LL_BibGeometryElement;

typedef struct {
    uint16_t type;
    uint16_t element_count;
    uint32_t source_stride;       /* packed record bytes per element */
    uint32_t decoded_stride;      /* staging bytes per element (header +4) */
    uint32_t source_size;         /* packed stream advance (header +8) */
    uint32_t output_size;         /* renderer work-list advance (header +12) */
    uint32_t header_offset;
    uint32_t data_offset;         /* packed source stream */
    uint32_t data_size;
    uint32_t staging_offset;      /* expanded index-pointer records */
    LL_BibGeometryElement *elements; /* decoded for primitive types 0..3 */
} LL_BibGeometryGroup;

typedef struct {
    int16_t position[3];
    uint16_t attribute;
} LL_BibVertex;

typedef struct {
    uint16_t vertex_count;
    uint16_t field_02;
    uint16_t first_vertex;
    uint16_t pivot_vertex;
    uint8_t flags; /* source +8, expanded +0x15; not animation pose flags */
} LL_BibModelPart;

typedef struct {
    uint32_t offset;
    uint32_t size;
    uint16_t sample_count;
    const unsigned char *data;
} LL_BibAnimationRecord;

/* Sparse pose decoded by FUN_00483700. The three groups each carry three
 * signed 16-bit channels; group/field mask bits are kept for exact fidelity. */
typedef struct {
    uint16_t flags;
    uint8_t present_groups;
    uint16_t present_channels[3];
    int16_t channels[9];
    uint32_t encoded_size;
} LL_BibPackedPose;
/* Native 16-bit interpolation fraction; angles wrap at 4096 units. */
int ll_bib_interpolate_pose(const LL_BibPackedPose *from,
                            const LL_BibPackedPose *to, uint32_t fraction,
                            LL_BibPackedPose *out_pose);

typedef struct {
    uint32_t selector;
    uint32_t offset;
    uint32_t size;
    uint16_t record_count;
    uint16_t record_type;
    uint32_t opaque_header;
    int16_t loop_displacement[3]; /* header +4/+6/+8, FUN_00483b60 */
    LL_BibAnimationRecord *records;
} LL_BibAnimationTable;

typedef struct {
    uint16_t table_index;
    uint32_t offset;
    uint32_t size;
    uint16_t flags;
    int valid;
    const unsigned char *data;
} LL_BibSoolScript;

typedef struct {
    char name[LL_BIB_3DX_NAME_SIZE + 1];
    uint32_t descriptor_reference; /* grid-section-relative DWORD offset */
    uint32_t catalogue_field_20;    /* on-disk DWORD at record +20; unknown */
    uint32_t descriptor_offset;    /* absolute file offset */
    uint32_t parent_model_index;   /* UINT32_MAX when geometry is local */
    uint32_t geometry_model_index;
    uint32_t geometry_descriptor_offset;
    uint8_t type;                  /* descriptor byte at +1 */
    uint32_t element_count;         /* descriptor DWORD at +0x2c */
    uint32_t model_directory_offset;
    uint32_t data_offsets[3];      /* absolute offsets in the geometry owner */
    uint32_t data_sizes[3];
    uint32_t vertex_count;
    LL_BibVertex *vertices;
    uint32_t group_header_offset;
    uint32_t group_count;
    LL_BibGeometryGroup *groups;
    int16_t orientation[9];         /* 12-bit fixed point basis at +0x7c */
    int32_t anchor[3];              /* descriptor XYZ at +0x90..+0x98 */
    int32_t bounds_min[3];          /* descriptor +0xa4..+0xac */
    int32_t bounds_max[3];          /* descriptor +0xb0..+0xb8 */
} LL_Bib3dxModel;

typedef struct {
    uint32_t value;             /* raw DWORD from the selector table */
    uint32_t offset;            /* file offset when is_section is nonzero */
    uint32_t size;              /* extent to the next indexed section */
    int is_section;             /* false when value is not a direct file offset */
} LL_BibSelector;

typedef struct {
    const unsigned char *raw_data;
    size_t raw_size;
    uint32_t sool_offset;
    uint32_t sool_size;
    uint16_t sool_script_count;
    uint16_t sool_header_field;
    LL_BibSoolScript *sool_scripts;
    uint32_t selector_count;
    uint32_t *selectors;
    LL_BibSelector *sections;
    int valid;
    uint32_t grid_section_offset;
    uint32_t grid_selector;
    uint16_t grid_dimensions[3];
    int16_t grid_steps[3];
    uint32_t model_root_offset;
    uint32_t model_count;
    uint32_t model_stride;
    uint32_t model_data_base;
    LL_Bib3dxModel *models;
    LL_BibAnimationTable *animations;
    char error[192];
} LL_BibFile;

/* Parse the SOOL-rooted BIB container, variable selector index, recognized
 * animation/SOOL tables, and optional 3DX geometry. Input must remain valid
 * until ll_bib_close. */
int ll_bib_open(LL_BibFile *bib, const unsigned char *data, size_t data_size);
void ll_bib_close(LL_BibFile *bib);
int ll_bib_is_valid(const LL_BibFile *bib);
const char *ll_bib_error(const LL_BibFile *bib);

/* Resolve an on-disk selector, including its raw value and bounded section
 * extent when the table value is an in-file offset. */
int ll_bib_get_selector_offset(const LL_BibFile *bib, uint32_t selector,
                               uint32_t *out_offset);
int ll_bib_get_selector(const LL_BibFile *bib, uint32_t selector,
                        LL_BibSelector *out_selector);
/* Borrow a directory-indexed record, bounded by the next distinct offset or
 * section end. Outputs are cleared on failure; lifetime matches the BIB. */
int ll_bib_get_indexed_record(const LL_BibFile *bib, uint32_t selector,
                              uint32_t index, const unsigned char **data,
                              size_t *size);
/* Pose groups registered by SOOL command 0xf1 and indexed by 0x2e. */
int ll_bib_get_scene_pose(const LL_BibFile *bib, uint32_t selector,
                          uint32_t index, LL_BibScenePose *out_pose);
uint32_t ll_bib_selector_count(const LL_BibFile *bib);
const LL_BibAnimationTable *ll_bib_get_animation_table(const LL_BibFile *bib,
                                                       uint32_t selector);
/* Decode one sparse pose payload as consumed by FUN_00483700. The first word
 * is the presence mask and each set channel bit consumes one following word.
 * Returns 0 for a truncated payload or invalid arguments. */
int ll_bib_decode_packed_pose(const unsigned char *data, size_t size,
                              LL_BibPackedPose *out_pose);
/* FUN_00483700 skips the frame's leading word and then walks one sparse
 * pose per animated part. The leading word is retained without timing assumptions. */
int ll_bib_decode_animation_frame(const LL_BibFile *bib, uint32_t selector,
                                  uint32_t frame, LL_BibPackedPose *parts,
                                  size_t capacity, uint16_t *out_frame_word);
/* FUN_00484ba0's edits to the retained expanded pose buffer. Preserves
 * flags/masks and allows target_root to alias an entry in snapshot. */
int ll_bib_prepare_transition_pose(LL_BibPackedPose *snapshot, size_t part_count,
                                   const LL_BibPackedPose *target_root);
const LL_BibSoolScript *ll_bib_get_sool_script(const LL_BibFile *bib,
                                               uint32_t index);
uint32_t ll_bib_model_count(const LL_BibFile *bib);
const LL_Bib3dxModel *ll_bib_get_model(const LL_BibFile *bib, uint32_t index);
/* Twelve-byte part records expanded into 40-byte animation records by
 * FUN_0047ec50; offsets reference the geometry owner's vertex stream. */
int ll_bib_get_model_part(const LL_BibFile *bib, uint32_t model_index,
                          uint32_t part_index, LL_BibModelPart *out_part);
/* Hierarchy entries are part indices or native matrix-stack commands -3..-1.
 * The caller can iterate until index reaches the descriptor's +0x24 count. */
int ll_bib_get_model_hierarchy_entry(const LL_BibFile *bib, uint32_t model_index,
                                     uint32_t index, int32_t *out_entry);
/* Assemble identity part transforms, without animation channels. */
int ll_bib_build_neutral_vertices(const LL_BibFile *bib, uint32_t model_index,
                                  LL_BibVertex *vertices, size_t capacity);
const LL_Bib3dxModel *ll_bib_find_model(const LL_BibFile *bib,
                                       const char *name);

typedef struct {
    uint32_t duration;
    uint16_t object_index, flags;
    int16_t offset_x, offset_y;
} LL_BibSpriteFrame;
/* Sprite animation: 12-byte header followed by bounded 12-byte frames.
 * The serialized pointer at header+8 is ignored (native relocates it). */
int ll_bib_get_sprite_frame(const LL_BibFile *bib, uint32_t selector,
                            uint32_t frame, LL_BibSpriteFrame *out);

#endif
