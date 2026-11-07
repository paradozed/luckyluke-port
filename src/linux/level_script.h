#ifndef LL_LEVEL_SCRIPT_H
#define LL_LEVEL_SCRIPT_H

#include "sool.h"
#include "bib.h"
#include "biz.h"
#include "native_audio.h"
#include "native_background.h"
#include "native_pause.h"
#include "native_collision.h"
#include "native_ballistic.h"
#include "native_material.h"
#include <stdio.h>

typedef LL_NativeCollisionLink LL_LevelCollisionLink;
typedef struct LL_LevelScriptObject LL_LevelScriptObject;

typedef struct {
    uint16_t child_instance, parent_instance;
    uint16_t parent_part, child_part, attachment_mode;
    uint16_t owner_context;
    uint8_t blocked;
    int16_t root_rotation[9]; /* Captured child matrix at native attachment+14. */
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
    uint8_t has_sprite_bounds;
    uint16_t biz_object, biz_sprite;
    int32_t sprite_bounds[6];
    uint8_t member_active[64], member_visible[64];
    LL_LevelScriptObject *sprites; /* Owned per-member descriptors for command96. */
    uint32_t member_started[64];
    uint8_t member_effect[64]; /* 0 ordinary loop,1 collecting,2 final frame queued. */
} LL_LevelOrbitalGroup;

typedef struct {
    LL_SoolVM vm;
    uint16_t state;
    uint16_t instance;
    uint16_t requested_state;
    int state_requested;
    int body_done, blocked;
    char error[256];
} LL_LevelScriptContext;

/* Recovered setup state. Keeping these values does not yet implement the
 * complete gameplay controller, advanced camera modes or level audio device. */
typedef struct {
    unsigned initialized, callback_capacity;
    uint8_t projection_mode, object_mode, camera_lock;
    uint32_t native_flags;
    uint8_t level_event_latch;
    uint8_t force_full_display; /* 004d1db5, variableBF and outer viewport selection. */
    uint8_t control_profile, saved_control_profile, previous_control_profile; /* 4f2800/4f2c6c/4f2c7b. */
    uint8_t timer_manager_registered; /* 410740: empty native50-entry manager; timer commands remain unported. */
    uint8_t pause_enabled, background_enabled, cd_paused;
    uint8_t fade_direction, fade_alpha; /* 1 reveal,2 darken; native step8 per presentation. */
    uint16_t collision_event_latch;
    unsigned collision_blocked_count;
    uint32_t projection, reciprocal_projection, depth;
    int16_t world_cell, camera_mode, camera_speed;
    uint16_t camera_word, camera_limit, player_word;
    uint16_t native_word_44; /* Signed health at004f1782; zero is a valid remaining health tier. */
    int16_t player_lives;
    int16_t player_dynamite, player_money, player_cards; /* 004f1786/1784/1788. */
    uint8_t dynamite_dirty, money_dirty, cards_dirty;
    uint32_t money_timer; /* 004e89b4, reset by command35's money update. */
    uint8_t player_health_dirty, player_invincible;
    uint16_t player_instance_plus_one;
    uint16_t selected_model_instance_plus_one; /* DAT_004e8474, retained by ID. */
    uint16_t scene_sprite_capacity;
    uint16_t object_registry[256];
    uint16_t scene_sprite_slots[5];
    uint8_t scene_sprite_manager_registered;
    int32_t camera_bounds[4];
    int32_t camera_bounds_target[4], camera_bounds_step;
    uint32_t camera_depth_target, camera_depth_step;
    uint8_t camera_bounds_transition, camera_depth_transition;
    int32_t player_reset_position[3]; /* DAT_004f2e10, command0x48 reset destination. */
    uint8_t player_reset_position_active;
    uint16_t camera_follow_instance_plus_one;
    uint32_t camera_follow_distance;
    int16_t camera_follow_pitch, camera_follow_yaw, camera_follow_height;
    uint16_t camera_side;
    int16_t camera_side_yaw;
    int32_t camera_follow_target[3], camera_follow_reference[3];
    uint8_t camera_reference_active;
    uint8_t camera_callback_enabled, camera_blocked, camera_output_active;
    uint8_t camera_vertical_mode, camera_lead_enabled, camera_clamp_active;
    uint16_t camera_motion_mode, camera_idle_counter;
    int32_t camera_lead_offset, camera_lead_range, camera_last_dx;
    int32_t camera_render_reference[3], camera_z_bounds[2], camera_clamp_target_x;
    int16_t camera_side_direction;
    char camera_error[160];
    int32_t camera_lookat[3]; /* DAT_004f2b7c, separate from last tracked target. */
    int32_t camera_reference_step[3], camera_lookat_step[3];
    int32_t camera_angle_fixed[2], camera_angle_step[2];
    uint16_t camera_transition_remaining;
    uint16_t camera_transition_target;
    uint8_t camera_transition_active;
    uint8_t camera_transition_absolute;
    uint8_t camera_transition_complete;
    int16_t camera_view_pitch, camera_view_yaw;
    int16_t animation_transition[5];
    unsigned path_capacity, path_count, pose_capacity, pose_count;
    uint16_t pose_groups[10];
} LL_LevelNativeSetup;

typedef struct {
    uint8_t attached;
    uint16_t selector, owner_context, heading;
    unsigned segment;
    int16_t distance, previous_distance, yaw, pitch;
    uint32_t flags;
    int32_t previous_position[3];
} LL_LevelObjectPath;

struct LL_LevelScriptObject {
    int present, cloned;
    LL_LevelCollisionLink collision_links[3];
    int32_t collision_previous_position[3];
    uint16_t collision_owner_context;
    uint8_t collision_registered, collision_blocked;
    char collision_error[160];
    uint32_t model_index;
    uint16_t wrapper_flags, motion_word;
    uint8_t motion_positive_bounce;
    uint32_t native_payload_flags; /* Model payload+0x10, separate from wrapper flags. */
    uint8_t visible, update_enabled, reduced, kind, callback_kind;
    uint8_t native_callback_enabled;
    uint8_t draw_suppressed; /* Wrapper+13, command72; separate from callback byte+10. */
    int32_t motion[3];
    int32_t *bounds;
    int32_t private_bounds[6];
    int32_t query_bounds[6]; /* 40da10: world-space part/whole-model cache. */
    uint32_t query_bounds_clock;
    uint16_t query_bounds_mode;
    uint8_t query_bounds_valid;
    uint16_t sprite_selector, biz_object, biz_sprite, sprite_frame;
    int16_t sprite_scale, sprite_offset[2];
    uint16_t sprite_width, sprite_height;
    uint16_t native_wrapper_word;
    uint16_t player_control_index;
    uint16_t animation_selector, animation_first, animation_last, animation_frame;
    uint16_t animation_next_frame;
    uint32_t animation_fraction; /* Native 16-bit interpolation fraction. */
    uint16_t animation_callback_owner;
    uint32_t animation_started;
    uint8_t animation_active, animation_once, animation_pose_present, animation_reverse;
    uint8_t animation_root_motion, animation_root_axis;
    uint16_t animation_motion_owner;
    int32_t animation_motion_reference;
    uint32_t animation_motion_cycles;
    uint8_t sprite_animation_active;
    uint8_t sprite_animation_once;
    uint8_t sprite_primitives_present; /* FUN_00485d00 clears sequence resources. */
    uint8_t sprite_frame_applied; /* Constructor quad differs from4862e0's offset/border-adjusted frame. */
    uint16_t sprite_animation_owner;
    uint16_t sprite_animation_first, sprite_animation_last;
    uint32_t sprite_animation_started; /* Native animation_clock>>5, not milliseconds. */
    LL_BibScenePose *pose; /* shared descriptor for0x65, private copy for0x68 */
    LL_BibScenePose private_pose;
    int16_t *root_rotation;
    int16_t private_root_rotation[9];
    LL_NativeMaterial *material;
    LL_NativeMaterial private_material;
    int16_t attachment_rotation[9]; /* Descriptor+7c, distinct from render root+5c. */
    LL_LevelObjectPath path;
};

typedef struct {
    uint8_t present, initialized, blocked;
    uint16_t owner_context, event;
    uint8_t mode; /* 0 startup,1 idle,2 walk,3 run,4 jump,5 fall,6 landing,7 aim,8 holster,
                  * 9 push,10 blocked,11 automatic walk,12 automatic run,13 deferred idle,14 no-op control,
                  * 15 crouching,16 crouch-idle entry,17 crouched,18 rising,19 deferred standing. */
    uint8_t crouch_motion; /* Horizontal callback retained by469b00/469c40. */
    uint8_t precontrol_mode; /* 0 ordinary469ef0,1 automatic-walk469dd0,2 null. */
    uint8_t controller_entry; /* Native BA selector+1; zero means no pending entry. */
    uint8_t suspended_motion; /* Mode retaining the horizontal callback while control is465a40. */
    uint8_t obstacle_motion; /* Retained horizontal callback:0 walk,1 run,2 push. */
    uint8_t air_motion; /* 0 deceleration,1 walking air control,2 running air control. */
    int16_t yaw;
    int32_t speed, displacement, vertical_speed, vertical_displacement;
    int32_t base_bounds[6];
    uint32_t idle_started, idle_variation, animation_cycles;
    uint32_t fall_sound_ticks; /* DAT_004f240c, increments in467bd0 when effects are enabled. */
    uint16_t actions, pressed_actions;
    uint8_t shot_pending, aim_index;
    uint16_t aim_event;
    int16_t aim_yaw, aim_angle;
    uint8_t hurt_callback; /* 0 none,1 pending69020,2 blinking68d80,3 quiet68e30. */
    uint32_t hurt_started, quiet_hurt_started; /* Native004e8850/004e8854 are independent. */
    char error[160];
} LL_LevelPlayer;

typedef struct {
    LL_LevelScriptObject ball, flash; /* Private descriptors, outside the wrapper table. */
    uint16_t flags;
    uint8_t first_frame, flash_active, flash_visible;
    int32_t velocity[3];
    int16_t screen[2]; /* Previous projection, read by FUN_00476680 before drawing. */
    uint32_t ball_started, flash_started;
    uint16_t target_count, targets[5];
} LL_LevelProjectile;

typedef struct {
    uint8_t initialized;
    uint16_t owner_context, hit_slot;
    uint32_t shots_fired, shots_dropped;
    uint32_t enemy_shots_fired;
    uint16_t enemy_hit_instance, enemy_hit_slot;
    LL_LevelProjectile slots[10];
} LL_LevelProjectiles;

typedef struct {
    LL_SoolProgram program;
    LL_BibFile bib;
    LL_BizFile biz;
    unsigned char *code_data, *bib_data, *biz_data;
    LL_LevelScriptContext *contexts;
    LL_SoolVM *condition_vm;
    LL_LevelNativeSetup native;
    LL_LevelPlayer player;
    LL_LevelProjectiles projectiles;
    LL_NativeAudio audio;
    LL_NativeBackground *backgrounds[260]; /* Owned managers indexed by their SOOL context. */
    LL_NativePause pause;
    uint8_t system_keys;
    uint16_t input_actions, previous_input_actions, input_pressed;
    LL_LevelScriptObject objects[260];
    LL_BibScenePose *model_poses;
    int16_t (*model_rotations)[9];
    int32_t (*model_bounds)[6];
    LL_NativeMaterial *model_materials;
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
    uint16_t requested_scene;
    uint8_t scene_requested; /* 410250: handled by the outer loop after SOOL returns. */
    uint8_t scene_reload; /* 413580(nonzero): restart the current scene, not a numeric scene0. */
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
/* Validate the next scene before releasing the current one. The caller must
 * stop its audio device first. Carries native global inventory/preferences;
 * B9 still resets health/dynamite in the new scene. Failure retains the scene. */
int ll_level_script_replace(LL_LevelScript *script,
    const unsigned char *code, size_t code_size, const unsigned char *bib, size_t bib_size,
    const unsigned char *biz, size_t biz_size, const unsigned char *pause, size_t pause_size);
void ll_level_script_close(LL_LevelScript *script);
/* One native engine iteration (24 Hz). Blocked contexts stay quarantined;
 * unrelated contexts continue, preserving explicit diagnostics and VM PCs. */
void ll_level_script_update(LL_LevelScript *script);
/* Attach localized pause PCX resources before the constructor executes. */
int ll_level_script_set_pause_archive(LL_LevelScript *script, const unsigned char *data, size_t size);
void ll_level_script_set_system_input(LL_LevelScript *script, uint8_t keys);
/* Logical native actions, independent of SDL. Opposing directions cancel. */
void ll_level_script_set_input(LL_LevelScript *script, uint16_t actions);
/* FUN_00456150 eight-way index;8 means no usable direction. */
unsigned ll_level_player_direction(uint16_t actions);
/* FUN_0046a6e0: projection_mode+1 acceleration substeps and their sum.
 * Returns1 only when speed already equals target on entry (native AL). */
int ll_level_player_accelerate(int32_t *speed, int32_t *displacement,
                                int32_t target, int32_t acceleration, uint8_t projection_mode);
/* FUN_004696b0/00469410 ground-facing query. Returns1 on a direction,
 * 0 for none/admissible junction absent,-1 for invalid path data. */
int ll_level_player_facing(const LL_BibFile *bib, uint16_t selector, unsigned segment,
                            int16_t distance, int16_t path_yaw, int16_t camera_yaw,
                            uint16_t actions, int16_t *yaw);
/* FUN_00485e70/004810e0: scaled frame rectangle, then a camera-facing quad.
 * Vertex order is top-left, top-right, bottom-left, bottom-right. */
int ll_level_script_world_sprite_vertices(const LL_LevelScript *script,
                                           const LL_LevelScriptObject *sprite,
                                           const int16_t *view, const int32_t translation[3],
                                           int32_t vertices[4][3]);
/* Shared posed model geometry for rendering and native part-pivot queries. */
/* Presentation eligibility inherited from an attachment's top-level wrapper. */
int ll_level_script_model_presented(const LL_LevelScript *script, unsigned instance);
int ll_level_script_model_vertices(const LL_LevelScript *script,
                                    const LL_LevelScriptObject *object,
                                    LL_BibVertex *vertices, size_t capacity);
/* Translate retained local sprite bounds by a decoded member root. Returns0
 * for absent groups/resources or an out-of-range member; output is untouched. */
int ll_level_script_group_member_bounds(const LL_LevelScript *script,
                                        unsigned instance, unsigned member,
                                        int32_t bounds[6]);
/* Geometric query only: first overlapping member index, -1 for no overlap,
 * -2 for invalid/incomplete group data or reversed query bounds. */
int ll_level_script_group_overlap(const LL_LevelScript *script, unsigned instance,
                                  const int32_t bounds[6]);
/* Consume the first active contact. -3 means the configured hit animation
 * is not implemented; no member is changed in that case. Other negatives
 * match group_overlap. A zero animation selector hides the contacted member. */
int ll_level_script_group_contact(LL_LevelScript *script, unsigned instance,
                                  const int32_t bounds[6]);
void ll_level_script_report(const LL_LevelScript *script, FILE *out);
/* FUN_00456410 branch decision: -1 invalid,0 dead end,1 inside current
 * segment,2 connected branch,3 type1 fallback. Does not mutate model state. */
int ll_level_path_next_segment(const LL_BibFile *bib, uint32_t selector,
                               unsigned current, const int32_t position[3],
                               uint16_t heading, unsigned *next);
/* FUN_004566a0: linked floor transfer, -1 invalid,0 no candidate,1 selected.
 * Only writes next when a candidate is found. */
int ll_level_path_floor_segment(const LL_BibFile *bib, uint32_t selector,
                                unsigned current, const int32_t position[3],
                                unsigned *next);
typedef struct {
    int32_t position[3];
    int16_t distance;
    uint32_t payload_flags, path_flags;
} LL_LevelPathConstraint;
/* Projection/vertical-response portion of FUN_00457180, after link decisions. */
int ll_level_path_constrain(const LL_BibPathSegment *segment, const int32_t position[3],
                            uint32_t payload_flags, uint32_t path_flags,
                            int type4_override, LL_LevelPathConstraint *out);
typedef struct {
    unsigned segment;
    int16_t yaw, pitch;
    int orientation_reset; /* Apply yaw/pitch only when the native segment reset runs. */
    LL_LevelPathConstraint constraint;
} LL_LevelPathStep;
/* FUN_00457180 after its preliminary collision adjustment. No model mutation. */
int ll_level_path_step(const LL_BibFile *bib, uint32_t selector, unsigned current,
                       const int32_t position[3], uint16_t heading,
                       uint32_t payload_flags, uint32_t path_flags,
                       int type4_override, LL_LevelPathStep *out);
/* Candidate decision from FUN_004568c0: -1 invalid,0 none,1 transfer to
 * candidate,2 corrected position. Output position only changes for result2. */
int ll_level_path_obstacle(const LL_BibPathSegment *current,
                           const LL_BibPathSegment *candidate,
                           const int32_t position[3], const int32_t previous[3],
                           int32_t corrected[3]);
/* Complete positional constraint callback, including preliminary obstacles. */
int ll_level_path_update(const LL_BibFile *bib, uint32_t selector, unsigned current,
                         const int32_t position[3], const int32_t previous[3],
                         uint16_t heading, uint32_t payload_flags, uint32_t path_flags,
                         int type4_override, LL_LevelPathStep *out);

#endif
