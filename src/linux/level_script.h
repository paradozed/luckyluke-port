#ifndef LL_LEVEL_SCRIPT_H
#define LL_LEVEL_SCRIPT_H

#include "sool.h"
#include "bib.h"
#include <stdio.h>

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
 * gameplay controller, camera-follow callback, audio device or 3D renderer. */
typedef struct {
    unsigned initialized, callback_capacity;
    uint8_t projection_mode, object_mode, camera_lock;
    uint32_t projection, reciprocal_projection, depth;
    int16_t world_cell, camera_mode, camera_speed;
    uint16_t camera_word, camera_limit, player_word;
    int32_t camera_bounds[4];
    unsigned path_capacity, pose_capacity, pose_count;
    uint16_t pose_groups[10];
} LL_LevelNativeSetup;

typedef struct {
    int present, cloned;
    uint32_t model_index;
    uint16_t wrapper_flags, motion_word;
    uint8_t visible, update_enabled, reduced, kind;
    int32_t motion[3];
    int32_t *bounds;
    int32_t private_bounds[6];
    LL_BibScenePose *pose; /* shared descriptor for0x65, private copy for0x68 */
    LL_BibScenePose private_pose;
} LL_LevelScriptObject;

typedef struct {
    LL_SoolProgram program;
    LL_BibFile bib;
    unsigned char *code_data, *bib_data;
    LL_LevelScriptContext *contexts;
    LL_SoolVM *condition_vm;
    LL_LevelNativeSetup native;
    LL_LevelScriptObject objects[260];
    LL_BibScenePose *model_poses;
    int32_t (*model_bounds)[6];
    uint8_t animation_preloaded[LL_BIB_MAX_SELECTORS];
    unsigned object_count, static_model_count;
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
void ll_level_script_close(LL_LevelScript *script);
/* One native engine iteration (24 Hz). Blocked contexts stay quarantined;
 * unrelated contexts continue, preserving explicit diagnostics and VM PCs. */
void ll_level_script_update(LL_LevelScript *script);
void ll_level_script_report(const LL_LevelScript *script, FILE *out);

#endif
