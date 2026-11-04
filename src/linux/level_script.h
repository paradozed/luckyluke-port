#ifndef LL_LEVEL_SCRIPT_H
#define LL_LEVEL_SCRIPT_H

#include "sool.h"
#include "bib.h"
#include "biz.h"
#include <stdio.h>

typedef struct {
    uint16_t target_context;
    uint16_t flags;
    uint8_t active, callback_mode;
} LL_LevelCollisionLink;

typedef struct {
    uint16_t child_instance, parent_instance;
    uint16_t animation_selector, attachment_mode;
    int32_t root_offset[3];
} LL_LevelSkeletalAttachment;

typedef struct {
    uint8_t present, callback_registered;
    uint16_t wrapper_instance, model_index, model_selector;
    uint16_t member_count, member_parameter, group_parameter, extra_parameter;
    int16_t scale, angle_step;
    int32_t center[3];
    uint32_t descriptor_offset;
    uint16_t native_words[4];
    uint8_t native_byte_2;
    uint8_t has_member_positions;
    int32_t member_positions[64][3];
    int32_t member_roots[64][3];
} LL_LevelOrbitalGroup;

typedef struct {
    LL_SoolVM vm;
    uint16_t state;
    uint16_t instance;
    uint16_t requested_state;
    int state_requested;
    int body_done, blocked;
    LL_LevelCollisionLink collision_links[3];
    char error[256];
} LL_LevelScriptContext;

/* Recovered setup state. Keeping these values does not yet implement the
 * gameplay controller, camera-follow callback, audio device or 3D renderer. */
typedef struct {
    unsigned initialized, callback_capacity;
    uint8_t projection_mode, object_mode, camera_lock;
    uint32_t native_flags;
    uint8_t level_event_latch;
    uint16_t collision_event_latch;
    uint32_t projection, reciprocal_projection, depth;
    int16_t world_cell, camera_mode, camera_speed;
    uint16_t camera_word, camera_limit, player_word;
    uint16_t native_word_44;
    uint16_t scene_sprite_capacity;
    uint16_t object_registry[256];
    uint16_t scene_sprite_slots[5];
    uint8_t scene_sprite_manager_registered;
    int32_t camera_bounds[4];
    int32_t camera_target[3];
    uint8_t camera_target_active;
    int16_t animation_transition[5];
    unsigned path_capacity, pose_capacity, pose_count;
    uint16_t pose_groups[10];
} LL_LevelNativeSetup;

typedef struct {
    int present, cloned;
    uint32_t model_index;
    uint16_t wrapper_flags, motion_word;
    uint8_t visible, update_enabled, reduced, kind, callback_kind;
    uint8_t native_callback_enabled;
    int32_t motion[3];
    int32_t *bounds;
    int32_t private_bounds[6];
    uint16_t sprite_selector, biz_object, biz_sprite, sprite_frame;
    int16_t sprite_scale, sprite_offset[2];
    uint16_t sprite_width, sprite_height;
    uint16_t native_wrapper_word;
    uint16_t player_control_index;
    uint16_t animation_selector, animation_first, animation_last, animation_frame;
    uint16_t animation_callback_owner;
    uint32_t animation_started;
    uint8_t animation_active, animation_once;
    uint8_t sprite_animation_active;
    uint16_t sprite_animation_first, sprite_animation_last;
    uint32_t sprite_animation_started_ms;
    LL_BibScenePose *pose; /* shared descriptor for0x65, private copy for0x68 */
    LL_BibScenePose private_pose;
} LL_LevelScriptObject;

typedef struct {
    LL_SoolProgram program;
    LL_BibFile bib;
    LL_BizFile biz;
    unsigned char *code_data, *bib_data, *biz_data;
    LL_LevelScriptContext *contexts;
    LL_SoolVM *condition_vm;
    LL_LevelNativeSetup native;
    LL_LevelScriptObject objects[260];
    LL_BibScenePose *model_poses;
    int32_t (*model_bounds)[6];
    uint8_t animation_preloaded[LL_BIB_MAX_SELECTORS];
    unsigned object_count, static_model_count;
    LL_LevelSkeletalAttachment skeletal_attachments[256];
    unsigned skeletal_attachment_count;
    LL_LevelOrbitalGroup orbital_groups[260];
    unsigned orbital_group_count;
    int grid_loaded;
    FILE *trace;
    uint32_t updates, calls, supported_calls, blocked_count;
    uint16_t dispatch_context;
    int in_conditions, loaded;
    char error[256];
} LL_LevelScript;

/* Zero-initialize before first open; close before reuse. Inputs are copied,
 * original asset buffers are never relocated or modified. No GL/SDL needed. */
int ll_level_script_open(LL_LevelScript *script,
                          const unsigned char *code, size_t code_size,
                          const unsigned char *bib, size_t bib_size, FILE *trace);
/* Attach an owned, bounds-checked level BIZ resource table before updates. */
int ll_level_script_set_biz(LL_LevelScript *script,
                            const unsigned char *biz, size_t biz_size);
void ll_level_script_close(LL_LevelScript *script);
/* One native engine iteration (24 Hz). Blocked contexts stay quarantined;
 * unrelated contexts continue, preserving explicit diagnostics and VM PCs. */
void ll_level_script_update(LL_LevelScript *script);
void ll_level_script_report(const LL_LevelScript *script, FILE *out);

#endif
