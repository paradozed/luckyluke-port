#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu_art.h"
#include "pcx.h"
#include "kxp.h"
#include "level.h"
#include "gameplay.h"
#include "asset_config.h"
#include "biz.h"
#include "sool.h"
#include "audio_mix.h"
#include "native_camera.h"

/* All scene/UI math uses the original 640x480 display-list surface.
 * The configured window size is applied once through the GL viewport. */
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define MENU_GAME 0
#define MENU_OPTIONS 1
#define MENU_ASSET_BIB_MISSING (1u << 0)
#define MENU_ASSET_BIB_INVALID (1u << 1)
#define MENU_ASSET_CONFIG_ERROR (1u << 2)
#define MENU_ASSET_CD_MOUNT_ERROR (1u << 3)
#define MENU_ASSET_INTRO_MISSING (1u << 4)
#define MENU_ASSET_BIZ_MISSING (1u << 5)
#define MENU_ASSET_BIZ_INVALID (1u << 6)

static const unsigned char font[36][7] = {
    {14, 17, 17, 31, 17, 17, 17}, {30, 17, 17, 30, 17, 17, 30},
    {14, 17, 16, 16, 16, 17, 14}, {30, 17, 17, 17, 17, 17, 30},
    {31, 16, 16, 30, 16, 16, 31}, {31, 16, 16, 30, 16, 16, 16},
    {14, 17, 16, 23, 17, 17, 15}, {17, 17, 17, 31, 17, 17, 17},
    {14, 4, 4, 4, 4, 4, 14}, {7, 2, 2, 2, 18, 18, 12},
    {17, 18, 20, 24, 20, 18, 17}, {16, 16, 16, 16, 16, 16, 31},
    {17, 27, 21, 21, 17, 17, 17}, {17, 25, 21, 19, 17, 17, 17},
    {14, 17, 17, 17, 17, 17, 14}, {30, 17, 17, 30, 16, 16, 16},
    {14, 17, 17, 17, 21, 18, 13}, {30, 17, 17, 30, 20, 18, 17},
    {15, 16, 16, 14, 1, 1, 30}, {31, 4, 4, 4, 4, 4, 4},
    {17, 17, 17, 17, 17, 17, 14}, {17, 17, 17, 17, 17, 10, 4},
    {17, 17, 17, 21, 21, 21, 10}, {17, 17, 10, 4, 10, 17, 17},
    {17, 17, 10, 4, 4, 4, 4}, {31, 1, 2, 4, 8, 16, 31},
    {14, 17, 19, 21, 25, 17, 14}, {4, 12, 4, 4, 4, 4, 14},
    {14, 17, 1, 2, 4, 8, 31}, {30, 1, 1, 14, 1, 1, 30},
    {2, 6, 10, 18, 31, 2, 2}, {31, 16, 16, 30, 1, 1, 30},
    {14, 16, 16, 30, 17, 17, 14}, {31, 1, 2, 4, 8, 8, 8},
    {14, 17, 17, 14, 17, 17, 14}, {14, 17, 17, 15, 1, 1, 14}
};

static LL_AssetConfig asset_config;

/* Native menu scene resources retain their source buffers for parser lifetime. */
static unsigned char *menu_bib_data;
static unsigned char *menu_biz_data;
static LL_BizFile menu_biz;
static unsigned char *menu_biz_updates[32], *menu_biz_update_masks[32];
static int menu_copy_biz_pixels(uint16_t destination, uint16_t source);
static uint32_t menu_biz_revision;
static int menu_biz_loaded;
static unsigned char *menu_script_data;
static LL_SoolProgram menu_program;
static int menu_program_loaded;
typedef struct {
    LL_SoolVM vm;
    uint16_t function, state, instance;
    int active;
} LL_MenuScriptContext;
static LL_MenuScriptContext *menu_script_contexts;
static LL_SoolVM *menu_dispatch_vm;
static uint16_t menu_dispatch_context;
static uint16_t menu_dispatch_function;
static Uint8 menu_previous_keys[SDL_NUM_SCANCODES];
static Uint8 menu_released_keys[SDL_NUM_SCANCODES];
static uint16_t menu_actions, menu_pressed_actions;
typedef struct {
    uint16_t instance_id;
    uint16_t selector;
    uint16_t biz_object;
    uint16_t scale;
    uint32_t model_index;
    int is_biz_sprite;
    int visible; /* original wrapper render flag at +0x14 */
} LL_MenuSceneObject;
static LL_MenuSceneObject menu_scene_objects[128];
static size_t menu_scene_object_count;
static unsigned char menu_pose_groups[LL_BIB_MAX_SELECTORS];
static LL_BibScenePose menu_object_poses[128];
static LL_BibVertex *menu_neutral_vertices[128];
static unsigned char menu_neutral_attempted[128];
static unsigned char menu_object_has_pose[128];
static int16_t menu_sprite_screen[128][3];
static int16_t menu_sprite_offset[128][2];
static unsigned char menu_sprite_has_screen[128];
static uint16_t menu_animation_selector[128];
static unsigned char menu_animation_once[128];
static uint16_t menu_animation_first[128], menu_animation_last[128];
static uint16_t menu_animation_frame[128];
static uint32_t menu_animation_fraction[128];
static uint32_t menu_animation_object_start[128];
static uint32_t menu_animation_started;
static uint16_t menu_animation_callback_owner[128]; /* context index + 1 */

/* BIZ sprite animation state: time-based frame progression driven by
 * SOOL command 0x42. Each sprite frame carries a duration; the engine
 * advances to the next frame when that duration elapses. */
static uint16_t menu_sprite_animation_selector[128];
static unsigned char menu_sprite_animation_once[128];
static uint16_t menu_sprite_animation_first[128], menu_sprite_animation_last[128];
static uint16_t menu_sprite_animation_frame[128];
static uint32_t menu_sprite_animation_start[128];
static LL_BibPackedPose *menu_animation_evaluated[128], *menu_animation_initial[128];
static uint16_t menu_animation_pose_count[128];
static unsigned char menu_animation_pose_valid[128];
static uint32_t menu_animation_duration[128], menu_animation_blend_ticks[128];

/* FUN_00478360 subtracts samples of a global 60 Hz clock. Keep its
 * fractional phase when an animation starts between two clock boundaries. */
static uint64_t menu_animation_elapsed(uint32_t start, uint32_t now)
{
    uint64_t phase=((uint64_t)start*60u)%1000u;
    return (((uint64_t)(uint32_t)(now-start)*60u+phase)/1000u)*31u;
}

static uint32_t menu_camera_depth = 6000; /* FUN_00452fa0 */
static uint16_t menu_camera_motion_id;
static int menu_camera_motion_complete = 1; /* FUN_00452fa0 */
static struct {
    int32_t position_step[3], angle_fixed[2], angle_step[2];
    unsigned remaining;
} menu_camera_transition;
static struct {
    int32_t reference[3];
    int32_t bounds[4]; /* X minimum/maximum, Y minimum/maximum */
    int has_bounds;
    int16_t pitch, yaw;
    uint16_t projection;
    int has_reference;
} menu_camera;
static unsigned int menu_asset_errors;
static unsigned char *abilene_cod_data;
static unsigned char *abilene_archive_data;
static unsigned char *fixgfx_archive_data;

static unsigned char *read_cd_file(const char *relative_path, size_t *out_size)
{
    char path[LL_ASSET_PATH_CAP * 2];
    unsigned char *data;
    long file_size;
    FILE *file;

    if (out_size == NULL ||
        !ll_asset_config_path(&asset_config, relative_path, path, sizeof(path))) {
        return NULL;
    }
    file = fopen(path, "rb");
    if (file == NULL) return NULL;
    if (fseek(file, 0, SEEK_END) != 0 || (file_size = ftell(file)) <= 0 ||
        fseek(file, 0, SEEK_SET) != 0) {
        fclose(file);
        return NULL;
    }
    data = (unsigned char *)malloc((size_t)file_size);
    if (data == NULL) {
        fclose(file);
        return NULL;
    }
    if (fread(data, 1, (size_t)file_size, file) != (size_t)file_size) {
        free(data);
        fclose(file);
        return NULL;
    }
    fclose(file);
    *out_size = (size_t)file_size;
    return data;
}

/* Game state (mirrors the original DAT_004e8914 selector).  State 1 is the
 * main menu; state 2 is the first level, Abilene. */
static int game_state = 1;
static LL_Level game_level;

static int load_abilene_assets(void)
{
    size_t size;

    if (abilene_archive_data == NULL) {
        abilene_archive_data = read_cd_file("ABILENE/abilene.kxp", &size);
        if (abilene_archive_data != NULL &&
            !ll_level_set_archive(&game_level, abilene_archive_data, size)) {
            fprintf(stderr, "WARNING: ABILENE/abilene.kxp exists but is not a valid KXP archive\n");
            free(abilene_archive_data);
            abilene_archive_data = NULL;
        } else if (abilene_archive_data != NULL) {
            if (!ll_level_load_background_from_archive(
                    &game_level, abilene_archive_data, size, "BACK.PCX")) {
                fprintf(stderr, "ERROR: missing or invalid CD asset ABILENE/BACK.PCX in abilene.kxp\n");
            }
        }
    }
    if (!ll_level_has_assets(&game_level)) {
        unsigned char *pcx = read_cd_file("image/Abilene.pcx", &size);
        if (pcx == NULL || !ll_level_load_background_from_pcx(&game_level, pcx, size)) {
            fprintf(stderr, "ERROR: cannot load CD background image/Abilene.pcx\n");
        }
        free(pcx);
    }

    if (abilene_cod_data == NULL) {
        abilene_cod_data = read_cd_file("ABILENE/abilene.cod", &size);
        if (abilene_cod_data == NULL) {
            fprintf(stderr, "ERROR: cannot read CD script ABILENE/abilene.cod\n");
        } else if (size >= 4 && memcmp(abilene_cod_data, "SOOL", 4) == 0) {
            fprintf(stderr, "INFO: found ABILENE/abilene.cod (SOOL); native SOOL level-script execution is not implemented yet\n");
        } else if (!ll_level_load_cod_from_memory(&game_level, abilene_cod_data, size)) {
            fprintf(stderr, "WARNING: ABILENE/abilene.cod uses an unsupported script format\n");
            free(abilene_cod_data);
            abilene_cod_data = NULL;
        }
    }

    if (fixgfx_archive_data == NULL) {
        fixgfx_archive_data = read_cd_file("win/graphics/FIXGFX.KXP", &size);
        if (fixgfx_archive_data == NULL ||
            !ll_level_set_fixgfx_archive(&game_level, fixgfx_archive_data, size)) {
            fprintf(stderr, "WARNING: cannot load optional CD asset win/graphics/FIXGFX.KXP\n");
            free(fixgfx_archive_data);
            fixgfx_archive_data = NULL;
        }
    }
    return ll_level_has_assets(&game_level);
}

static int load_menu_bib(void)
{
    char localized_upper[64];
    char localized_lower[64];
    const char *candidates[4];
    size_t index;
    int found_file = 0;

    snprintf(localized_upper, sizeof(localized_upper),
             "CINEMA/OPTION/option_%c.bib", asset_config.language_code);
    snprintf(localized_lower, sizeof(localized_lower),
             "cinema/option/option_%c.bib", asset_config.language_code);
    candidates[0] = localized_upper;
    candidates[1] = "CINEMA/OPTION/option.bib";
    candidates[2] = localized_lower;
    candidates[3] = "cinema/option/option.bib";

    if (ll_level_has_bib(&game_level)) {
        return 1;
    }

    /* The parsed BIB retains a pointer into this buffer, so preserve the
     * successful allocation for the lifetime of the parsed catalogue. */
    for (index = 0; index < sizeof(candidates) / sizeof(candidates[0]); index++) {
        size_t file_size = 0;
        unsigned char *data = read_cd_file(candidates[index], &file_size);

        if (data == NULL) continue;
        found_file = 1;
        if (ll_level_load_bib_from_memory(&game_level, data, file_size)) {
            free(menu_bib_data);
            menu_bib_data = data;
            return 1;
        }
        fprintf(stderr, "WARNING: cannot parse menu BIB '%s': %s\n",
                candidates[index], ll_bib_error(&game_level.bib));
        menu_asset_errors |= MENU_ASSET_BIB_INVALID;
        free(data);
    }
    free(menu_bib_data);
    menu_bib_data = NULL;
    if (!found_file) {
        menu_asset_errors |= MENU_ASSET_BIB_MISSING;
    } else {
        menu_asset_errors |= MENU_ASSET_BIB_INVALID;
    }
    return 0;
}

static int load_menu_biz(void)
{
    char path[64];
    size_t size = 0;

    if (menu_biz_loaded) return 1;
    snprintf(path, sizeof(path), "CINEMA/OPTION/option_%c.biz",
             asset_config.language_code);
    menu_biz_data = read_cd_file(path, &size);
    if (menu_biz_data == NULL) {
        menu_asset_errors |= MENU_ASSET_BIZ_MISSING;
        fprintf(stderr, "ERROR: cannot read localized menu BIZ '%s'\n", path);
        return 0;
    }
    if (!ll_biz_open(&menu_biz, menu_biz_data, size)) {
        menu_asset_errors |= MENU_ASSET_BIZ_INVALID;
        fprintf(stderr, "ERROR: cannot load menu BIZ '%s'%s%s\n", path,
                ": ", ll_biz_error(&menu_biz));
        free(menu_biz_data);
        menu_biz_data = NULL;
        return 0;
    }
    menu_biz_loaded = 1;
    fprintf(stderr, "INFO: loaded localized menu BIB catalogue and BIZ resources (%u objects, %u sprites)\n",
            menu_biz.counts[0], menu_biz.counts[1]);
    return 1;
}

static void menu_scene_register_model(uint16_t instance, uint16_t selector)
{
    uint32_t descriptor_offset;
    const LL_Bib3dxModel *model = NULL;
    if (!ll_bib_get_selector_offset(&game_level.bib, selector, &descriptor_offset)) {
        fprintf(stderr, "ERROR: option.cod model selector %u is missing in BIB\n", selector);
        return;
    }
    for (uint32_t i = 0; i < game_level.bib.model_count; i++) {
        const LL_Bib3dxModel *candidate = ll_bib_get_model(&game_level.bib, i);
        if (candidate != NULL && candidate->descriptor_offset == descriptor_offset) {
            model = candidate;
            if (menu_scene_object_count >= sizeof(menu_scene_objects) / sizeof(menu_scene_objects[0])) {
                fprintf(stderr, "ERROR: SOOL menu scene object capacity exceeded\n");
                return;
            }
            menu_scene_objects[menu_scene_object_count++] = (LL_MenuSceneObject){
                instance, selector, 0, 0, i, 0, 1
            };
            break;
        }
    }
    if (model == NULL) {
        fprintf(stderr, "ERROR: BIB selector %u resolves outside the parsed 3DX catalogue\n",
                selector);
    } else {
        fprintf(stderr, "INFO: SOOL created menu model %s at instance %u\n",
                model->name, instance);
    }
}

static void menu_scene_register_biz(uint16_t instance, uint16_t selector,
                                    uint16_t scale)
{
    LL_BibSelector section;
    uint32_t object_index;
    LL_BizObject object;
    if (!ll_bib_get_selector(&game_level.bib, selector, &section) ||
        !section.is_section || section.size < 4) {
        fprintf(stderr, "ERROR: option.cod BIZ selector %u is missing or truncated\n",
                selector);
        return;
    }
    LL_BibSpriteFrame frame;
    if (!ll_bib_get_sprite_frame(&game_level.bib, selector, 0, &frame)) {
        fprintf(stderr, "ERROR: BIB sprite selector %u has no valid frame zero\n", selector);
        return;
    }
    object_index = frame.object_index;
    if (object_index > UINT16_MAX || !ll_biz_get_object(&menu_biz, object_index, &object)) {
        fprintf(stderr, "ERROR: BIB selector %u refers to invalid BIZ object %u\n",
                selector, object_index);
        return;
    }
    if (menu_scene_object_count >= sizeof(menu_scene_objects) / sizeof(menu_scene_objects[0])) {
        fprintf(stderr, "ERROR: SOOL menu scene object capacity exceeded\n");
        return;
    }
    menu_sprite_offset[menu_scene_object_count][0] = frame.offset_x;
    menu_sprite_offset[menu_scene_object_count][1] = frame.offset_y;
    menu_scene_objects[menu_scene_object_count++] = (LL_MenuSceneObject){
        instance, selector, (uint16_t)object_index, scale, UINT32_MAX, 1, 1
    };
    fprintf(stderr, "INFO: SOOL created menu BIZ sprite %u/tile %u at instance %u\n",
            object.sprite_index, object.tile_index, instance);
}

/* Native subtractive generator: FUN_0046d7b0 / FUN_0046d700.
 * Unsigned arithmetic explicitly preserves the original 32-bit wraparound. */
static uint16_t menu_random_word(void)
{
    static uint32_t words[55];
    static unsigned first, second;
    static int initialized;
    if (!initialized) {
        uint32_t seed = 0x09a4ec86u, next = 1;
        words[54] = seed;
        for (unsigned i = 0; i < 54; i++) {
            unsigned index = (i * 21u) % 55u;
            words[index] = next;
            next = seed - next;
            seed = words[index];
        }
        for (unsigned pass = 0; pass < 4; pass++)
            for (unsigned i = 0; i < 55; i++)
                words[i] -= words[(i + 31u) % 55u];
        first = 0;
        second = 31;
        initialized = 1;
    }
    first = (first + 1u) % 55u;
    second = (second + 1u) % 55u;
    words[first] -= words[second];
    return (uint16_t)(words[first] % 0x7fffu);
}

typedef struct {
    int16_t rectangle[4];
    uint8_t top[3], bottom[3];
    uint16_t sprite_object;
    int16_t source[4];
    int is_sprite;
} LL_MenuBackgroundPrimitive;

typedef struct {
    int16_t rectangle[4], order;
    uint16_t transform[4];
    int16_t phase[2], origin[2];
    uint8_t draw_flags;
    uint8_t enabled;
    uint8_t tint[3], tint_start[3];
    int16_t tint_delta[3], tint_phase;
    LL_MenuBackgroundPrimitive primitives[32];
    unsigned primitive_count;
} LL_MenuPrimitiveChild;
static LL_MenuPrimitiveChild menu_primitive_children[256][16];
static uint8_t menu_primitive_child_count[256];
static int16_t menu_primitive_parent_y[256];

typedef struct {
    uint16_t selector, scale, frame;
    int16_t position[3];
    int present;
} LL_MenuGroupSprite;
typedef struct {
    uint16_t count;
    uint8_t enabled;
    LL_MenuGroupSprite children[32];
} LL_MenuSpriteGroup;
static LL_MenuSpriteGroup menu_sprite_groups[256];
static uint8_t menu_marker_enabled, menu_marker_index;
/* Original password table at Lucky.exe 0x4be1ac (code, level). */
static const struct { uint16_t code, level; } menu_passwords[] = {
    {0x1320,4},{0x3031,6},{0x0310,8},{0x2033,10},{0x3223,12},
    {0x3301,14},{0x0230,17},{0x1223,18},{0x0102,19},{0x2130,23}
};
static uint16_t menu_password_level=2;
static uint16_t menu_control_profile;
static uint8_t menu_keyboard_hand;
static uint8_t menu_sound_stereo=1, menu_sfx_volume=100, menu_music_volume=70, menu_cd_track=4;
static LL_AudioMixer menu_audio_mixer;
static SDL_AudioDeviceID menu_audio_device;
static int16_t *menu_audio_pcm[60];
static LL_BizSound menu_audio_samples[60];
static uint16_t menu_audio_base, menu_audio_multiplier;
static uint16_t menu_audio_volume[64], menu_audio_pan[64], menu_audio_rate[64];
static int menu_audio_muted;

static int menu_scene_position(uint16_t instance, int32_t point[3])
{
    for (size_t i=0;i<menu_scene_object_count;i++) {
        if (menu_scene_objects[i].instance_id!=instance) continue;
        if (menu_object_has_pose[i]) memcpy(point,menu_object_poses[i].position,3u*sizeof(*point));
        else {
            const LL_Bib3dxModel *model=ll_bib_get_model(&game_level.bib,menu_scene_objects[i].model_index);
            if (!model) return 0;
            memcpy(point,model->anchor,3u*sizeof(*point));
        }
        return 1;
    }
    fprintf(stderr,"ERROR: SOOL position query references unavailable owner %u\n",instance);
    return 0;
}

static void menu_audio_callback(void *userdata, Uint8 *stream, int length)
{
    (void)userdata;
    memset(stream,0,(size_t)length);
    int16_t *output=(int16_t *)stream;
    ll_audio_mix_render(&menu_audio_mixer,output,(size_t)length/4u);
    /* waveOutSetVolume is represented here as a software master gain. */
    unsigned master=menu_audio_muted ? 0u : (unsigned)(menu_sfx_volume*655.3499755859375);
    if (master>65535u) master=65535u;
    for (size_t sample=0;sample<(size_t)length/2u;sample++)
        output[sample]=(int16_t)((int64_t)output[sample]*master/65535);
}

static void menu_audio_shutdown(void)
{
    if (menu_audio_device) SDL_CloseAudioDevice(menu_audio_device);
    menu_audio_device=0;
    for (unsigned i=0;i<60;i++) { free(menu_audio_pcm[i]);menu_audio_pcm[i]=NULL; }
}

static void menu_audio_init(void)
{
    if (!asset_config.sound_enabled || !menu_biz_loaded) return;
    ll_audio_mix_init(&menu_audio_mixer);
    uint32_t count;
    if (!ll_biz_get_sound_count(&menu_biz,&count)) goto invalid_bank;
    for (uint32_t i=0;i<count;i++) {
        LL_BizSound *sample=&menu_audio_samples[i];
        if (!ll_biz_get_sound(&menu_biz,i,sample)) goto invalid_bank;
        if (!sample->sample_count || sample->sample_count>16u*1024u*1024u) {
            fprintf(stderr,"ERROR: menu sound %u has an unsupported PCM length\n",i);
            menu_audio_shutdown();return;
        }
        menu_audio_pcm[i]=malloc(sample->sample_count*sizeof(int16_t));
        if (!menu_audio_pcm[i]) {
            fprintf(stderr,"ERROR: cannot allocate PCM for menu sound %u\n",i);
            menu_audio_shutdown();return;
        }
        if (!ll_biz_decode_sound(&menu_biz,i,menu_audio_pcm[i],sample->sample_count,NULL)) goto invalid_bank;
    }
    if (SDL_InitSubSystem(SDL_INIT_AUDIO)!=0) {
        fprintf(stderr,"ERROR: cannot initialize menu audio: %s\n",SDL_GetError());
        menu_audio_shutdown();return;
    }
    SDL_AudioSpec wanted={0};
    wanted.freq=16000;wanted.format=AUDIO_S16SYS;wanted.channels=2;
    wanted.samples=512;wanted.callback=menu_audio_callback;
    menu_audio_device=SDL_OpenAudioDevice(NULL,0,&wanted,NULL,0);
    if (!menu_audio_device) {
        fprintf(stderr,"ERROR: cannot open 16000 Hz stereo menu audio: %s\n",SDL_GetError());
        menu_audio_shutdown();return;
    }
    SDL_PauseAudioDevice(menu_audio_device,0);
    fprintf(stderr,"INFO: menu audio enabled (%u decoded samples, 64 voices)\n",count);
    return;
invalid_bank:
    fprintf(stderr,"ERROR: cannot decode menu sound bank: %s\n",ll_biz_error(&menu_biz));
    menu_audio_shutdown();
}

static uint16_t menu_audio_play(uint16_t owner, uint16_t sample, int16_t pitch, uint16_t volume,
                                 uint16_t pan, uint16_t positional)
{
    if (!menu_audio_device || !volume) return 0;
    if (positional==1) {
        int found=0;
        for (size_t i=0;i<menu_scene_object_count;i++) {
            if (menu_scene_objects[i].instance_id!=owner) continue;
            int32_t point[3];
            if (menu_object_has_pose[i]) memcpy(point,menu_object_poses[i].position,sizeof(point));
            else {
                const LL_Bib3dxModel *model=ll_bib_get_model(&game_level.bib,menu_scene_objects[i].model_index);
                if (!model) break;
                memcpy(point,model->anchor,sizeof(point));
            }
            int32_t x=ll_native_camera_screen_x(point,menu_camera.reference,menu_camera.pitch,
                menu_camera.yaw,menu_camera_depth,menu_camera.projection);
            if (x<0 || x>WINDOW_WIDTH) return 0;
            found=1;break;
        }
        if (!found) {
            fprintf(stderr,"ERROR: positional menu sound references unavailable owner %u\n",owner);return 0;
        }
    }
    sample=(uint16_t)(sample-menu_audio_base);
    if (sample>=60 || !menu_audio_pcm[sample]) {
        fprintf(stderr,"ERROR: SOOL references unavailable menu sound %u\n",sample);return 0;
    }
    uint16_t rate=(uint16_t)(menu_audio_samples[sample].sample_rate+pitch);
    if (!rate) return 0;
    SDL_LockAudioDevice(menu_audio_device);
    uint16_t gains[2], slot=0;
    if (ll_audio_mix_gains(&menu_audio_mixer,volume,menu_audio_multiplier,pan,menu_sound_stereo,gains))
        slot=ll_audio_mix_play(&menu_audio_mixer,menu_audio_pcm[sample],
            menu_audio_samples[sample].sample_count,((uint32_t)rate*256u+8000u)/16000u,gains);
    if (slot) {
        menu_audio_volume[slot-1]=volume;menu_audio_pan[slot-1]=pan;menu_audio_rate[slot-1]=rate;
    }
    SDL_UnlockAudioDevice(menu_audio_device);
    if (getenv("LL_TRACE_AUDIO")) fprintf(stderr,"TRACE: menu sound %s voice %u\n",menu_audio_samples[sample].name,slot);
    return slot;
}

static int menu_sool_dispatch(uint8_t opcode, uint16_t *stack, size_t *stack_size,
                              size_t stack_capacity, void *userdata)
{
    size_t count;
    uint16_t *current_instance = userdata;
    if (opcode >= 0x50 && opcode <= 0x5e) {
        uint16_t value = 0;
        count = opcode - 0x4fu;
        if (count > *stack_size || *stack_size - count >= stack_capacity) return 0;
        if (stack[*stack_size-1u]==0x98 && count==3u) {
            int32_t a[3], b[3], screen_a[2], screen_b[2];
            if (!menu_scene_position(stack[*stack_size-2u],a) ||
                !menu_scene_position(stack[*stack_size-3u],b)) return 0;
            ll_native_camera_screen(a,menu_camera.reference,menu_camera.pitch,menu_camera.yaw,
                menu_camera_depth,menu_camera.projection,screen_a);
            ll_native_camera_screen(b,menu_camera.reference,menu_camera.pitch,menu_camera.yaw,
                menu_camera_depth,menu_camera.projection,screen_b);
            value=ll_native_screen_pan(screen_a,screen_b);
        } else if ((stack[*stack_size-1u]==0x96 && count==6u) ||
            (stack[*stack_size-1u]==0x97 && count==5u)) {
            int32_t a[3], b[3];
            if (!menu_scene_position(stack[*stack_size-2u],a) ||
                !menu_scene_position(stack[*stack_size-3u],b)) return 0;
            value=ll_native_distance100(a,b);
            if (stack[*stack_size-1u]==0x96) {
                uint16_t radius=stack[*stack_size-4u];
                int16_t peak=(int16_t)stack[*stack_size-5u];
                int16_t scale=(int16_t)stack[*stack_size-6u];
                if (value>radius) value=(uint16_t)peak;
                else {
                    if (!radius) { fprintf(stderr,"ERROR: SOOL attenuation radius is zero\n");return 0; }
                    int16_t level=(int16_t)((int32_t)(int16_t)value*peak/(int16_t)radius);
                    if (peak>=0) level=(int16_t)(peak-level);
                    level=(int16_t)((int32_t)level*scale/256);
                    int magnitude=level<0 ? -(int)level : level;
                    int limit=peak<0 ? -(int)peak : peak;
                    value=(uint16_t)(magnitude>limit ? peak : level);
                }
            }
        } else if (stack[*stack_size-1u]==0x99 && count==7u) {
            value=menu_audio_play(stack[*stack_size-2u],stack[*stack_size-3u],(int16_t)stack[*stack_size-4u],
                stack[*stack_size-5u],stack[*stack_size-6u],stack[*stack_size-7u]);
        } else if (stack[*stack_size-1u]==0x9a && count==2u) {
            uint16_t slot=(uint8_t)stack[*stack_size-2u];
            if (menu_audio_device && slot && slot<=64) {
                SDL_LockAudioDevice(menu_audio_device);
                value=menu_audio_mixer.voices[slot-1].active;
                SDL_UnlockAudioDevice(menu_audio_device);
            }
        } else if (stack[*stack_size-1u]==0x9b && count==1u) {
            if (menu_audio_device) {
                SDL_LockAudioDevice(menu_audio_device);
                for (unsigned i=0;i<64;i++)
                    if (!menu_audio_mixer.voices[i].active && !menu_audio_mixer.voices[i].reserved) value++;
                SDL_UnlockAudioDevice(menu_audio_device);
            }
        } else if ((stack[*stack_size - 1u] == 0 || stack[*stack_size - 1u] == 1) && count >= 2u) {
            if (stack[*stack_size - 2u] == 0)
                value = stack[*stack_size - 1u] == 0 ? menu_actions : menu_pressed_actions;
        } else if (stack[*stack_size - 1u] == 0x5b && count == 2u) {
            /* FUN_0040e970 returns the primitive's U-right minus U-left,
             * before screen scaling; FUN_004862e0 insets each edge by 1. */
            uint16_t instance=stack[*stack_size - 2u];
            int found=0;
            for (size_t i=0; i<menu_scene_object_count; i++) {
                const LL_MenuSceneObject *object=&menu_scene_objects[i];
                if (object->instance_id!=instance || !object->is_biz_sprite) continue;
                LL_BizObject entry;
                LL_BizSprite sprite;
                if (!ll_biz_get_object(&menu_biz,object->biz_object,&entry) ||
                    !ll_biz_get_sprite(&menu_biz,entry.sprite_index,&sprite) || sprite.width_units<=0) return 0;
                unsigned width=(unsigned)sprite.width_units*4u;
                if (width>256u-sprite.texture_x) width=256u-sprite.texture_x;
                if (width<=2u) return 0;
                value=(uint16_t)(width-2u);
                found=1;
                break;
            }
            if (!found) {
                fprintf(stderr,"ERROR: SOOL sprite width query references unavailable instance %u\n",instance);
                return 0;
            }
        } else if (stack[*stack_size - 1u] == 0x3e && count == 1u) {
            value=menu_control_profile;
        } else if (stack[*stack_size - 1u] == 0x3d && count == 5u) {
            uint16_t code=0;
            for (unsigned digit=0; digit<4; digit++)
                code |= (uint16_t)(stack[*stack_size - 2u - digit] << (12u-digit*4u));
            value=2; /* Native fallback: first level. */
            for (size_t i=0; i<sizeof(menu_passwords)/sizeof(menu_passwords[0]); i++)
                if (menu_passwords[i].code==code) value=menu_passwords[i].level;
            menu_password_level=value;
            fprintf(stderr,"INFO: SOOL password %04x selects level %u\n",code,value);
        } else if (count == 1u && stack[*stack_size - 1u] >= 0x9c && stack[*stack_size - 1u] <= 0x9f) {
            switch (stack[*stack_size - 1u]) {
            case 0x9c: value=menu_sound_stereo; break;
            case 0x9d: value=menu_sfx_volume; break;
            case 0x9e: value=menu_music_volume; break;
            case 0x9f: value=menu_cd_track; break;
            }
        } else if (count==1u && stack[*stack_size-1u]>=0xa0 && stack[*stack_size-1u]<=0xa3) {
            /* 0xa0: CD track count (no CD backend yet); 0xa1 is an
             * explicit zero-return native stub. Successful waveOut setup
             * initializes the 0xa2 flag to1 and the 0xa3 word to0. */
            value=stack[*stack_size-1u]==0xa2 && menu_audio_device!=0 ? 1u : 0u;
        } else if (stack[*stack_size - 1u] == 0x3f && count == 1u) {
            /* FUN_0040c1f0: auxiliary languages use English script layout. */
            switch (asset_config.language_code) {
            case 'f': value = 1; break;
            case 'd': value = 2; break;
            case 's': value = 3; break;
            default: value = 0; break;
            }
        } else if (stack[*stack_size - 1u] == 0x50 && count == 6u) {
            if (menu_dispatch_function >= 256) return 0;
            uint8_t *children = &menu_primitive_child_count[menu_dispatch_function];
            if (*children >= 16) {
                fprintf(stderr, "ERROR: SOOL primitive child capacity exceeded\n");
                return 0;
            }
            value = (*children)++;
            LL_MenuPrimitiveChild *child = &menu_primitive_children[menu_dispatch_function][value];
            for (unsigned axis = 0; axis < 4; axis++)
                child->rectangle[axis] = (int16_t)stack[*stack_size - 2u - axis];
            child->order = (int16_t)stack[*stack_size - 6u];
            child->enabled = 1; /* FUN_004471b0: byte +0x1a */
            memset(child->tint,128,sizeof(child->tint));
            child->tint_phase=-1;
        } else if (stack[*stack_size - 1u] == 0x0b && count >= 2u) {
            int16_t bound = (int16_t)stack[*stack_size - 2u];
            if (bound == 0) {
                fprintf(stderr, "ERROR: SOOL random variable requires a nonzero bound\n");
                return 0;
            }
            value = (uint16_t)((int)menu_random_word() % bound);
        } else if ((stack[*stack_size - 1u] == 0xaa || stack[*stack_size - 1u] == 0xab) && count >= 2u) {
            int release_query = stack[*stack_size - 1u] == 0xab;
            SDL_Scancode key = SDL_SCANCODE_UNKNOWN;
            switch (stack[*stack_size - 2u]) {
            case 1: key = SDL_SCANCODE_ESCAPE; break;
            case 14: key = SDL_SCANCODE_BACKSPACE; break;
            case 28: key = SDL_SCANCODE_RETURN; break;
            case 29: key = SDL_SCANCODE_LCTRL; break;
            case 30: key = SDL_SCANCODE_A; break;
            case 31: key = SDL_SCANCODE_S; break;
            case 57: key = SDL_SCANCODE_SPACE; break;
            case 200: key = SDL_SCANCODE_UP; break;
            case 203: key = SDL_SCANCODE_LEFT; break;
            case 205: key = SDL_SCANCODE_RIGHT; break;
            case 208: key = SDL_SCANCODE_DOWN; break;
            }
            if (key != SDL_SCANCODE_UNKNOWN &&
                (release_query ? menu_released_keys[key] : SDL_GetKeyboardState(NULL)[key])) value = 0x80;
        } else if (stack[*stack_size - 1u] == 0x46 && count >= 2u) {
            if (stack[*stack_size - 2u] == menu_camera_motion_id)
                value = (uint16_t)menu_camera_motion_complete;
        } else if (stack[*stack_size - 1u] == 0x47 && count == 1u) {
            value = 1; /* Depth changes currently reach their target immediately. */
        } else if (stack[*stack_size - 1u] == 0x26 && count >= 4u) {
            uint16_t instance = stack[*stack_size - 2u];
            uint16_t group = stack[*stack_size - 3u];
            uint16_t index = stack[*stack_size - 4u];
            LL_BibScenePose box;
            if (ll_bib_get_scene_pose(&game_level.bib, group, index, &box)) {
                for (size_t i = 0; i < menu_scene_object_count; i++) {
                    const LL_MenuSceneObject *object = &menu_scene_objects[i];
                    if (object->instance_id != instance || object->is_biz_sprite) continue;
                    const LL_Bib3dxModel *model = ll_bib_get_model(&game_level.bib, object->model_index);
                    if (model == NULL) continue;
                    value = 1;
                    for (unsigned axis = 0; axis < 3; axis++) {
                        int64_t position = menu_object_has_pose[i]
                            ? menu_object_poses[i].position[axis] : model->anchor[axis];
                        if (position + model->bounds_max[axis] < box.position[axis] ||
                            box.angles[axis] < position + model->bounds_min[axis]) value = 0;
                    }
                }
            }
        }
        if (getenv("LL_TRACE_SOOL") != NULL) {
            fprintf(stderr, "TRACE: SOOL variable 0x%x args", stack[*stack_size - 1u]);
            for (size_t arg = 1; arg < count; arg++)
                fprintf(stderr, " %d", (int16_t)stack[*stack_size - 1u - arg]);
            fprintf(stderr, " => 0x%x\n", value);
        }
        *stack_size -= count;
        stack[(*stack_size)++] = value;
        return 1;
    }
    count = opcode - 0x3bu; /* includes the command ID */
    if (count > *stack_size) return 0;
    {
        size_t first = *stack_size - count;
        uint16_t command = stack[*stack_size - 1u];
        if (getenv("LL_TRACE_SOOL") != NULL) {
            fprintf(stderr, "TRACE: SOOL command 0x%x instance %u args", command,
                    current_instance != NULL ? *current_instance : UINT16_MAX);
            for (size_t arg = 1; arg < count; arg++)
                fprintf(stderr, " %d", (int16_t)stack[*stack_size - 1u - arg]);
            fputc('\n', stderr);
        }
        if ((command==0xc8 || command==0xd0) && count==2u) {
            if (command==0xc8) menu_audio_base=stack[*stack_size-2u];
            else menu_audio_multiplier=stack[*stack_size-2u];
        } else if ((command==0xc9 || command==0xce || command==0xcf) && count==2u) {
            uint16_t slot=(uint8_t)stack[*stack_size-2u];
            if (menu_audio_device) {
                SDL_LockAudioDevice(menu_audio_device);
                if (command==0xc9) ll_audio_mix_stop(&menu_audio_mixer,slot);
                else ll_audio_mix_reserve(&menu_audio_mixer,slot,command==0xce);
                SDL_UnlockAudioDevice(menu_audio_device);
            }
        } else if ((command==0xcc && count==4u) || (command==0xcb && count==3u)) {
            uint16_t slot=(uint8_t)stack[*stack_size-2u];
            if (menu_audio_device && slot && slot<=64) {
                SDL_LockAudioDevice(menu_audio_device);
                if (command==0xcc) {
                    menu_audio_volume[slot-1]=stack[*stack_size-3u];
                    menu_audio_pan[slot-1]=stack[*stack_size-4u];
                    ll_audio_mix_gains(&menu_audio_mixer,menu_audio_volume[slot-1],menu_audio_multiplier,
                        menu_audio_pan[slot-1],menu_sound_stereo,menu_audio_mixer.voices[slot-1].gain);
                } else {
                    uint16_t rate=(uint16_t)(menu_audio_rate[slot-1]+(int16_t)stack[*stack_size-3u]);
                    menu_audio_mixer.voices[slot-1].step=((uint32_t)rate*256u+8000u)/16000u;
                }
                SDL_UnlockAudioDevice(menu_audio_device);
            }
        } else if (command==0xca && count==2u) {
            if (menu_audio_device) SDL_LockAudioDevice(menu_audio_device);
            menu_audio_muted=stack[*stack_size-2u]!=0;
            if (menu_audio_device) SDL_UnlockAudioDevice(menu_audio_device);
        } else if (command == 0x18e && count == 1u) {
            menu_keyboard_hand ^= 1u;
            menu_biz_revision++;
            fprintf(stderr,"INFO: SOOL keyboard hand %u\n",menu_keyboard_hand);
        } else if (command == 0x51 && count == 2u) {
            uint16_t profile=stack[*stack_size - 2u];
            if (profile>2u) return 0;
            menu_control_profile=profile;
            fprintf(stderr,"INFO: SOOL control configuration %c\n",'A'+profile);
        } else if (count == 2u && (command == 0xd1 || command == 0xd2 || command == 0xd3 || command == 0xd6)) {
            uint8_t value=(uint8_t)stack[*stack_size - 2u];
            if (menu_audio_device) SDL_LockAudioDevice(menu_audio_device);
            if (command == 0xd1) menu_sound_stereo=value;
            else if (command == 0xd2) menu_sfx_volume=value;
            else if (command == 0xd6) menu_music_volume=value;
            else menu_cd_track=value;
            if (menu_audio_device) SDL_UnlockAudioDevice(menu_audio_device);
            fprintf(stderr,"INFO: SOOL sound setting 0x%x = %u\n",command,value);
        } else if (command >= 0x17c && command <= 0x180) {
            if (count < 3u) return 0;
            uint16_t id = stack[*stack_size - 2u];
            if (id >= 256u) return 0;
            LL_MenuSpriteGroup *group = &menu_sprite_groups[id];
            uint16_t index = stack[*stack_size - 3u];
            if (command == 0x17c) {
                if (count != 3u || index == 0 || index > 32u) return 0;
                memset(group,0,sizeof(*group));
                group->count = index;
            } else if (command == 0x17e) {
                if (count != 3u || group->count == 0) return 0;
                group->enabled = (uint8_t)index;
            } else {
                if (index >= group->count) return 0;
                LL_MenuGroupSprite *sprite = &group->children[index];
                if (command == 0x17d) {
                    if (count != 8u) return 0;
                    if (!sprite->present) {
                        sprite->selector = stack[*stack_size - 4u];
                        sprite->scale = stack[*stack_size - 5u];
                        LL_BibSpriteFrame frame;
                        if (!ll_bib_get_sprite_frame(&game_level.bib,sprite->selector,0,&frame)) return 0;
                        for (unsigned axis = 0; axis < 3; axis++)
                            sprite->position[axis] = (int16_t)stack[*stack_size - 6u - axis];
                        sprite->present = 1;
                    }
                } else if (command == 0x17f) {
                    if (count != 4u || !sprite->present) return 0;
                    sprite->frame = stack[*stack_size - 4u];
                    LL_BibSpriteFrame frame;
                    if (!ll_bib_get_sprite_frame(&game_level.bib,sprite->selector,sprite->frame,&frame)) return 0;
                } else {
                    if (count != 6u || !sprite->present) return 0;
                    for (unsigned axis = 0; axis < 3; axis++)
                        sprite->position[axis] = (int16_t)stack[*stack_size - 4u - axis];
                }
            }
        } else if (command == 0x181 && count == 3u) {
            menu_marker_enabled = (uint8_t)stack[*stack_size - 2u];
            menu_marker_index = (uint8_t)stack[*stack_size - 3u];
        } else if (command == 0x100 && count == 4u) {
            uint16_t destination_selector = stack[*stack_size - 2u];
            uint16_t source_selector = stack[*stack_size - 3u];
            uint16_t frame_index = stack[*stack_size - 4u];
            LL_BibSelector destination;
            LL_BibSpriteFrame frame;
            LL_BizObject object;
            if (!ll_bib_get_selector(&game_level.bib, destination_selector, &destination) ||
                destination.value >= 512u ||
                !ll_biz_get_object(&menu_biz,destination.value,&object) ||
                !ll_bib_get_sprite_frame(&game_level.bib,source_selector,frame_index,&frame) ||
                frame.object_index == UINT16_MAX || !ll_biz_get_object(&menu_biz,frame.object_index,&object)) {
                fprintf(stderr,"ERROR: SOOL texture copy %u <- %u:%u is invalid\n",
                        destination_selector,source_selector,frame_index);
                return 0;
            }
            if (!menu_copy_biz_pixels((uint16_t)destination.value,frame.object_index)) {
                fprintf(stderr,"ERROR: SOOL BIZ page copy %u <- %u exceeds bounds or allocation failed\n",
                        (unsigned)destination.value,frame.object_index);
                return 0;
            }
        } else if (command == 0x122 && count == 3u) {
            if (menu_dispatch_function >= 256 || WINDOW_HEIGHT <= 0) return 0;
            menu_primitive_parent_y[menu_dispatch_function] = (int16_t)
                (-((int16_t)stack[*stack_size - 3u] * 256 / WINDOW_HEIGHT));
        } else if ((command == 0x123 && count == 11u) || (command == 0x126 && count == 6u) || (command == 0x128 && count == 4u) ||
                   (command == 0x124 && count == 9u) || (command == 0x125 && count == 12u) || (command == 0x12c && count == 3u) || (command == 0x12a && count == 6u) || (command == 0x129 && count == 5u)) {
            uint16_t index = stack[*stack_size - 2u];
            if (menu_dispatch_function >= 256 || index >= menu_primitive_child_count[menu_dispatch_function]) {
                fprintf(stderr, "ERROR: SOOL primitive child %u is unavailable in function %u\n", index, menu_dispatch_function);
                return 0;
            }
            LL_MenuPrimitiveChild *child = &menu_primitive_children[menu_dispatch_function][index];
            if (command == 0x129) {
                /* FUN_004473e0 replaces both current and start RGB without
                 * cancelling an existing interpolation phase/delta. */
                for (unsigned channel=0; channel<3; channel++) {
                    child->tint[channel]=(uint8_t)stack[*stack_size-3u-channel];
                    child->tint_start[channel]=child->tint[channel];
                }
            } else if (command == 0x12a) {
                int changed=0;
                for (unsigned channel=0; channel<3; channel++) {
                    child->tint_start[channel]=child->tint[channel];
                    child->tint_delta[channel]=(int16_t)((uint8_t)stack[*stack_size-3u-channel]-child->tint[channel]);
                    changed |= child->tint_delta[channel]!=0;
                }
                child->tint_phase=changed?0:-1;
                if (changed && stack[*stack_size-6u]!=0 && menu_dispatch_vm!=NULL) {
                    menu_dispatch_vm->host_color_wait=(uint16_t)(menu_dispatch_function*16u+index+1u);
                    menu_dispatch_vm->host_yield=1;
                }
            } else if (command == 0x12c) {
                child->enabled = (uint8_t)stack[*stack_size - 3u];
            } else if (command == 0x124 || command == 0x125) {
                if (child->primitive_count >= 32) {
                    fprintf(stderr, "ERROR: SOOL child color primitive capacity exceeded\n");
                    return 0;
                }
                LL_MenuBackgroundPrimitive *color = &child->primitives[child->primitive_count++];
                for (unsigned axis = 0; axis < 4; axis++)
                    color->rectangle[axis] = (int16_t)stack[*stack_size - 3u - axis];
                for (unsigned channel = 0; channel < 3; channel++) {
                    color->top[channel] = (uint8_t)stack[*stack_size - 7u - channel];
                    color->bottom[channel] = command == 0x124 ? color->top[channel]
                        : (uint8_t)stack[*stack_size - 10u - channel];
                }
            } else if (command == 0x128) {
                child->draw_flags = (uint8_t)stack[*stack_size - 3u];
                if (stack[*stack_size - 4u] != 0) child->draw_flags |= 4u;
            } else if (command == 0x126) {
                for (unsigned arg = 0; arg < 4; arg++)
                    child->transform[arg] = stack[*stack_size - 3u - arg];
                /* FUN_00447350: vertical values use the output height. */
                int height = WINDOW_HEIGHT;
                if (height <= 0) return 0;
                child->transform[1] = (uint16_t)(int16_t)(int8_t)
                    ((int8_t)child->transform[1] * 256 / height);
                child->transform[3] = (uint16_t)(int16_t)
                    ((int16_t)child->transform[3] * 256 / height);
            } else {
                uint16_t selector = stack[*stack_size - 3u];
                LL_BibSelector entry;
                LL_BizObject object;
                if (!ll_bib_get_selector(&game_level.bib, selector, &entry) ||
                    entry.value > UINT16_MAX ||
                    !ll_biz_get_object(&menu_biz, entry.value, &object)) {
                    fprintf(stderr, "ERROR: SOOL sprite selector %u is not a direct BIZ object\n", selector);
                    return 0;
                }
                if (child->primitive_count >= 32) return 0;
                LL_MenuBackgroundPrimitive *sprite = &child->primitives[child->primitive_count++];
                sprite->is_sprite = 1;
                sprite->sprite_object = (uint16_t)entry.value;
                for (unsigned axis = 0; axis < 4; axis++) {
                    sprite->rectangle[axis] = (int16_t)stack[*stack_size - 4u - axis];
                    sprite->source[axis] = (int16_t)stack[*stack_size - 8u - axis];
                }
                fprintf(stderr, "INFO: SOOL function %u child %u sprite object %u at (%d,%d) size (%d,%d)\n",
                        menu_dispatch_function, index, sprite->sprite_object,
                        sprite->rectangle[0], sprite->rectangle[1],
                        sprite->rectangle[2], sprite->rectangle[3]);
            }
        } else if (command == 0x5c && count >= 5 && menu_dispatch_vm != NULL) {
            /* FUN_004142a0 fills password symbols for the selected level.
             * Four by-reference arguments occupy eight words; the native
             * dispatcher reports four additional consumed stack words. */
            if (*stack_size < 9u) return 0;
            count += 4u;
            uint16_t code=0x0123;
            for (size_t i=0; i<sizeof(menu_passwords)/sizeof(menu_passwords[0]); i++)
                if (menu_passwords[i].level==menu_password_level) code=menu_passwords[i].code;
            for (unsigned binding = 0; binding < 4; binding++) {
                uint16_t symbol=(uint16_t)((code >> (12u-binding*4u)) & 15u);
                uint16_t offset = stack[*stack_size - 2u - binding * 2u];
                uint16_t target = stack[*stack_size - 3u - binding * 2u];
                if (offset >= 256u || target >= menu_program.function_count) return 0;
                if (target == menu_dispatch_function) ll_sool_write_word(menu_dispatch_vm->locals, (uint8_t)offset, symbol);
                else ll_sool_write_word(menu_script_contexts[target].vm.locals, (uint8_t)offset, symbol);
                if (target < 256u) ll_sool_write_word(menu_dispatch_vm->members[target], (uint8_t)offset, symbol);
            }
        } else if (command == 0x64 && count >= 3) {
            /* FUN_0041a680 loads static catalogue geometry; type-1
             * animated descriptors are instantiated separately by 0x65. */
            for (uint32_t m = 0; m < game_level.bib.model_count; m++) {
                const LL_Bib3dxModel *model = ll_bib_get_model(&game_level.bib, m);
                if (model == NULL || model->type != 0) continue;
                int in_grid = 1;
                for (unsigned axis = 0; axis < 3; axis++) {
                    int32_t step = game_level.bib.grid_steps[axis];
                    if (step > 0 && game_level.bib.grid_dimensions[axis] != 0) {
                        /* Native signed cell division truncates toward zero:
                         * small negative heights still belong to cell zero. */
                        int32_t coordinate = model->anchor[axis];
                        if (axis == 0) coordinate += 300; /* FUN_0047a660 */
                        if (axis == 1) coordinate -= 300; /* FUN_0047a6a0 */
                        int32_t cell = coordinate / step;
                        if (cell < 0 || cell >= game_level.bib.grid_dimensions[axis]) in_grid = 0;
                    }
                }
                if (!in_grid) continue;
                if (menu_scene_object_count >= 128) return 0;
                menu_scene_objects[menu_scene_object_count++] = (LL_MenuSceneObject){
                    UINT16_MAX, 0, 0, 0, m, 0, 1
                };
            }
        } else if (command == 0xf1 && count >= 2) {
            uint16_t selector = stack[*stack_size - 2u];
            if (selector >= LL_BIB_MAX_SELECTORS) return 0;
            menu_pose_groups[selector] = 1;
        } else if (command == 0x2e && count >= 3 && current_instance != NULL) {
            uint16_t group = stack[*stack_size - 2u];
            uint16_t pose_index = stack[*stack_size - 3u];
            LL_BibScenePose pose;
            if (group >= LL_BIB_MAX_SELECTORS || !menu_pose_groups[group] ||
                !ll_bib_get_scene_pose(&game_level.bib, group, pose_index, &pose)) {
                fprintf(stderr, "ERROR: SOOL pose group %u index %u is unavailable\n", group, pose_index);
                return 0;
            }
            for (size_t i = 0; i < menu_scene_object_count; i++) {
                if (menu_scene_objects[i].instance_id != *current_instance) continue;
                menu_object_poses[i] = pose;
                menu_object_has_pose[i] = 1;
                fprintf(stderr, "INFO: SOOL instance %u pose %u:%u at (%d,%d,%d)\n",
                        *current_instance, group, pose_index,
                        pose.position[0], pose.position[1], pose.position[2]);
            }
        } else if (command == 0x1a && count >= 4 && current_instance != NULL) {
            /* FUN_00410530 -> FUN_00411bd0 updates the current object's
             * orientation independently of its selected world-position pose. */
            for (size_t i = 0; i < menu_scene_object_count; i++) {
                if (menu_scene_objects[i].instance_id != *current_instance || !menu_object_has_pose[i]) continue;
                for (size_t axis = 0; axis < 3; axis++)
                    menu_object_poses[i].angles[axis] = (int16_t)stack[*stack_size - 2u - axis];
            }
        } else if ((command == 0x1b || command == 0x0b || command == 0x14) && count >= 2 && current_instance != NULL) {
            /* 0x0b is FUN_00418e60: play the selected BIB animation,
             * install the completion callback and request script wait.
             * Completion belongs to the object context, so replacement
             * retains its callback until another waiting command replaces it. */
            uint16_t selector = stack[*stack_size - 2u];
            const LL_BibAnimationTable *animation = ll_bib_get_animation_table(&game_level.bib, selector);
            if (animation == NULL) {
                fprintf(stderr, "ERROR: SOOL animation selector %u has no decoded frame directory\n", selector);
                return 0;
            }
            uint16_t first_frame = 0, last_frame = (uint16_t)(animation->record_count - 1u);
            if (command == 0x14) {
                if (count != 4u) return 0;
                first_frame = stack[*stack_size - 3u];
                last_frame = stack[*stack_size - 4u];
                if (last_frame == UINT16_MAX) last_frame = (uint16_t)(animation->record_count - 1u);
                if (first_frame > last_frame || last_frame >= animation->record_count) {
                    fprintf(stderr, "ERROR: SOOL animation %u range %u..%u is invalid\n", selector, first_frame, last_frame);
                    return 0;
                }
            }
            for (size_t i = 0; i < menu_scene_object_count; i++) {
                if (menu_scene_objects[i].instance_id != *current_instance) continue;
                if (command != 0x1b || menu_animation_selector[i] != selector) {
                    LL_BibPackedPose *snapshot=NULL;
                    uint32_t blend_ticks=0;
                    if (menu_animation_pose_valid[i] && menu_animation_evaluated[i] && menu_animation_pose_count[i]==animation->record_type &&
                        menu_animation_duration[i]) {
                        snapshot=malloc((size_t)animation->record_type*sizeof(*snapshot));
                        if (!snapshot) { fprintf(stderr,"ERROR: cannot retain animation transition pose\n");return 0; }
                        memcpy(snapshot,menu_animation_evaluated[i],(size_t)animation->record_type*sizeof(*snapshot));
                        LL_BibPackedPose root;
                        const LL_BibAnimationRecord *record=&animation->records[first_frame];
                        if (!record->data || record->size<2u ||
                            !ll_bib_decode_packed_pose(record->data+2u,record->size-2u,&root) ||
                            !ll_bib_prepare_transition_pose(snapshot,animation->record_type,&root)) {
                            free(snapshot);
                            fprintf(stderr,"ERROR: cannot prepare bounded animation transition root\n");return 0;
                        }
                        blend_ticks=menu_animation_duration[i];
                    }
                    free(menu_animation_initial[i]);menu_animation_initial[i]=snapshot;
                    menu_animation_blend_ticks[i]=blend_ticks;
                    menu_animation_object_start[i] = SDL_GetTicks();
                    menu_animation_frame[i] = UINT16_MAX;
                    menu_animation_fraction[i] = UINT32_MAX;
                }
                menu_animation_selector[i] = selector;
                menu_animation_once[i] = command != 0x1b;
                menu_animation_first[i] = first_frame;
                menu_animation_last[i] = last_frame;
                if (command != 0x1b && menu_dispatch_vm != NULL) {
                    menu_animation_callback_owner[i]=(uint16_t)(menu_dispatch_context+1u);
                    menu_dispatch_vm->host_animation_wait=1;
                    menu_dispatch_vm->host_yield = 1;
                } else if (command==0x1b && menu_dispatch_vm!=NULL)
                    menu_dispatch_vm->host_animation_wait=0;
                fprintf(stderr, "INFO: SOOL instance %u selects animation %u (%u frames, %u parts)\n",
                        *current_instance, selector, animation->record_count, animation->record_type);
            }
        } else if (command == 0x41 && count == 4u && current_instance != NULL) {
            for (size_t i = 0; i < menu_scene_object_count; i++) {
                if (menu_scene_objects[i].instance_id != *current_instance) continue;
                for (unsigned axis = 0; axis < 3; axis++)
                    menu_sprite_screen[i][axis] = (int16_t)stack[*stack_size - 2u - axis];
                menu_sprite_has_screen[i] = 1;
            }
        } else if (command == 0x42 && count == 3u && current_instance != NULL) {
            uint16_t selector = stack[*stack_size - 2u];
            uint16_t frame_index = stack[*stack_size - 3u];
            uint16_t play_once = stack[*stack_size - 1u] != 0 ? 1u : 0u;
            LL_BibSpriteFrame frame;
            LL_BizObject object;
            if (!ll_bib_get_sprite_frame(&game_level.bib, selector, frame_index, &frame) ||
                !ll_biz_get_object(&menu_biz, frame.object_index, &object)) {
                fprintf(stderr, "ERROR: BIB sprite selector %u frame %u is unavailable\n", selector, frame_index);
                return 0;
            }
            /* Determine the animation's last frame from the section header. */
            LL_BibSelector section;
            uint16_t frame_count = 0;
            if (ll_bib_get_selector(&game_level.bib, selector, &section) &&
                section.is_section && section.size >= 12u) {
                frame_count = (uint16_t)((uint16_t)game_level.bib.raw_data[section.offset + 2] |
                                         ((uint16_t)game_level.bib.raw_data[section.offset + 3] << 8));
            }
            if (frame_count == 0 || frame_index >= frame_count) {
                fprintf(stderr, "ERROR: BIZ animation selector %u has no valid frames\n", selector);
                return 0;
            }
            uint16_t last_frame = (uint16_t)(frame_count - 1u);
            for (size_t i = 0; i < menu_scene_object_count; i++) {
                if (menu_scene_objects[i].instance_id != *current_instance || !menu_scene_objects[i].is_biz_sprite) continue;
                menu_sprite_animation_selector[i] = selector;
                menu_sprite_animation_once[i] = (unsigned char)play_once;
                menu_sprite_animation_first[i] = frame_index;
                menu_sprite_animation_last[i] = last_frame;
                menu_sprite_animation_frame[i] = frame_index;
                menu_sprite_animation_start[i] = SDL_GetTicks();
                menu_scene_objects[i].biz_object = frame.object_index;
                menu_sprite_offset[i][0] = frame.offset_x;
                menu_sprite_offset[i][1] = frame.offset_y;
            }
            if (play_once && menu_dispatch_vm != NULL) {
                menu_dispatch_vm->host_animation_wait = 1;
                menu_dispatch_vm->host_yield = 1;
            }
            fprintf(stderr, "INFO: SOOL instance %u starts BIZ sprite animation %u from frame %u (%u frames, once=%u)\n",
                    *current_instance, selector, frame_index, frame_count, play_once);
        } else if (command == 0x10 && count >= 3) {
            uint16_t instance = stack[*stack_size - 2u];
            int visible = stack[*stack_size - 3u] != 0;
            for (size_t i = 0; i < menu_scene_object_count; i++)
                if (menu_scene_objects[i].instance_id == instance)
                    menu_scene_objects[i].visible = visible;
        } else if (command == 0x160 && count >= 7) {
            int speed = (int16_t)stack[*stack_size - 7u];
            if (speed < 10) speed = 10;
            if (speed > 200) speed = 200;
            unsigned updates = (unsigned)(205 - speed);
            for (unsigned axis = 0; axis < 3; axis++) {
                int32_t target = (int16_t)stack[*stack_size - 2u - axis] * 100;
                if (axis < 2 && menu_camera.has_bounds) {
                    if (target > menu_camera.bounds[axis*2u+1u]) target = menu_camera.bounds[axis*2u+1u];
                    if (target < menu_camera.bounds[axis*2u]) target = menu_camera.bounds[axis*2u];
                }
                int64_t fixed = ((int64_t)target - menu_camera.reference[axis]) * 4096 / updates;
                menu_camera_transition.position_step[axis] = (int32_t)(fixed >= 0 ? fixed/4096 : -((-fixed+4095)/4096));
            }
            for (unsigned axis = 0; axis < 2; axis++) {
                int current = axis == 0 ? menu_camera.pitch : menu_camera.yaw;
                int target = (int16_t)stack[*stack_size - 5u - axis];
                int limit = axis == 0 ? 800 : 1600;
                if (target < -limit) target = -limit;
                if (target > limit) target = limit;
                menu_camera_transition.angle_fixed[axis] = current * 4096;
                menu_camera_transition.angle_step[axis] = (target-current)*4096/(int)updates;
            }
            menu_camera_transition.remaining = updates;
            menu_camera_motion_id = 0;
            menu_camera_motion_complete = 0;
            fprintf(stderr, "INFO: SOOL camera transition over %u updates\n", updates);
        } else if (command == 0x15e && count >= 2) {
            menu_camera_motion_id = stack[*stack_size - 2u];
            menu_camera_motion_complete = 0;
        } else if (command == 0x13c && count >= 5) {
            for (size_t bound = 0; bound < 4; bound++)
                menu_camera.bounds[bound] = (int16_t)stack[*stack_size - 2u - bound] * 100;
            menu_camera.has_bounds = 1;
        } else if (command == 0x13d && count >= 2) {
            uint32_t depth = (uint32_t)(int32_t)(int16_t)stack[*stack_size - 2u];
            menu_camera_depth = depth > 20000u ? 20000u : depth == 0 ? 1u : depth;
        } else if (command == 0x36 && count >= 3) {
            /* FUN_00411d90 reads projection from argument 3. */
            menu_camera.projection = stack[*stack_size - 3u];
        } else if (command == 0x136 && count >= 6) {
            /* FUN_0041c3e0 clears the active motion (DAT_004f2b68).
             * A direct placement must not inherit a previous transition's
             * position/angle steps on the next scheduler update. */
            menu_camera_transition.remaining = 0;
            menu_camera_motion_id = 0;
            menu_camera_motion_complete = 1;
            /* FUN_0041c670: arguments 2..4 are signed XYZ, scaled by
             * 100; FUN_0041c3e0 clamps pitch and yaw independently. */
            for (size_t axis = 0; axis < 3; axis++)
                menu_camera.reference[axis] = (int16_t)stack[*stack_size - 2u - axis] * 100;
            if (menu_camera.has_bounds) {
                for (size_t axis = 0; axis < 2; axis++) {
                    if (menu_camera.reference[axis] > menu_camera.bounds[axis * 2u + 1u])
                        menu_camera.reference[axis] = menu_camera.bounds[axis * 2u + 1u];
                    if (menu_camera.reference[axis] < menu_camera.bounds[axis * 2u])
                        menu_camera.reference[axis] = menu_camera.bounds[axis * 2u];
                }
            }
            int pitch = (int16_t)stack[*stack_size - 5u];
            int yaw = (int16_t)stack[*stack_size - 6u];
            menu_camera.pitch = (int16_t)(pitch < -800 ? -800 : pitch > 800 ? 800 : pitch);
            menu_camera.yaw = (int16_t)(yaw < -1600 ? -1600 : yaw > 1600 ? 1600 : yaw);
            menu_camera.has_reference = 1;
            fprintf(stderr, "INFO: SOOL camera reference (%d,%d,%d), pitch %d yaw %d projection %u\n",
                    menu_camera.reference[0], menu_camera.reference[1], menu_camera.reference[2],
                    menu_camera.pitch, menu_camera.yaw, menu_camera.projection);
        } else if (command == 0x65 && count >= 3)
            menu_scene_register_model(stack[first + count - 3u],
                                      stack[first + count - 2u]);
        else if (command == 0x71 && count >= 4)
            menu_scene_register_biz(stack[first + count - 2u],
                                    stack[first + count - 3u],
                                    stack[first + count - 4u]);
        if (current_instance != NULL) {
            if (command == 0x65 && count >= 3) *current_instance = stack[*stack_size - 3u];
            if (command == 0x71 && count >= 4) *current_instance = stack[*stack_size - 2u];
        }
    }
    *stack_size -= count;
    return 1; /* Non-rendering engine commands have no Linux host effect yet. */
}

static int load_and_execute_menu_script(void)
{
    size_t size = 0;
    LL_SoolVM vm;
    menu_script_data = read_cd_file("CINEMA/OPTION/option.cod", &size);
    if (menu_script_data == NULL) {
        fprintf(stderr, "ERROR: cannot read CINEMA/OPTION/option.cod\n");
        return 0;
    }
    if (!ll_sool_program_open(&menu_program, menu_script_data, size)) {
        fprintf(stderr, "ERROR: cannot parse CINEMA/OPTION/option.cod: %s\n",
                ll_sool_program_error(&menu_program));
        return 0;
    }
    menu_program_loaded = 1;
    menu_script_contexts = calloc(menu_program.function_count, sizeof(*menu_script_contexts));
    if (menu_script_contexts == NULL) {
        fprintf(stderr, "ERROR: cannot allocate persistent menu script contexts\n");
        return 0;
    }
    /* Native function data is shared from creation, including startup reads
     * of a previously initialized function (e.g. function14's language). */
    for (uint16_t function = 0; function < menu_program.function_count; function++) {
        const LL_SoolFunction *fn = &menu_program.functions[function];
        menu_script_contexts[function].function=function;
        menu_script_contexts[function].state=fn->initial_state;
        menu_script_contexts[function].instance=UINT16_MAX;
        menu_script_contexts[function].active=fn->initial_state != UINT16_MAX;
        for (uint32_t local = 0; local < 256u && local + 1u < fn->code_start; local++) {
            const unsigned char *p = menu_program.data + fn->offset + local;
            menu_script_contexts[function].vm.locals[local] =
                (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
        }
    }
    for (uint16_t function = 0; function < menu_program.function_count; function++) {
        /* FUN_00421930 copies header +10 into the pending state; the
         * scheduler selects that single state, not a range of states. */
        if (!menu_script_contexts[function].active ||
            (menu_script_contexts[function].vm.state_flags & 1u)) continue;
        {
            uint16_t state = menu_script_contexts[function].state;
            uint16_t current_instance = UINT16_MAX;
            uint16_t active_function = function;
            uint16_t active_state = state;
            memset(&vm, 0, sizeof(vm));
            vm.state_flags=menu_script_contexts[function].vm.state_flags;
            memcpy(vm.locals, menu_script_contexts[function].vm.locals, sizeof(vm.locals));
            size_t shared_count = menu_program.function_count < 256u ? menu_program.function_count : 256u;
            for (size_t target = 0; target < shared_count; target++) {
                memcpy(vm.members[target], menu_script_contexts[target].vm.locals, sizeof(vm.locals));
                vm.member_states[target]=menu_script_contexts[target].state;
                vm.member_disabled[target]=(uint8_t)(menu_script_contexts[target].vm.state_flags & 1u);
            }
            vm.current_state = (int16_t)state;
            for (unsigned transition = 0; transition < 256; transition++) {
                vm.has_pending_transition = 0;
                vm.current_state = (int16_t)active_state;
                menu_dispatch_vm = &vm;
                menu_dispatch_context = function;
                menu_dispatch_function = active_function;
                if (!ll_sool_execute_state(&menu_program, active_function,
                                           active_state, &vm,
                                           menu_sool_dispatch, &current_instance)) {
                    fprintf(stderr, "WARNING: SOOL function %u state %u stopped at +0x%x (opcode 0x%02x)\n",
                            active_function, active_state,
                            vm.last_instruction_offset, vm.last_opcode);
                    break;
                }
                if (!vm.has_pending_transition) break;
                if (vm.pending_state == UINT16_MAX) break;
                if (vm.pending_function >= menu_program.function_count ||
                    vm.pending_state >= menu_program.functions[vm.pending_function].state_count) {
                    fprintf(stderr, "WARNING: SOOL transition from %u:%u targets invalid %u:%u\n",
                            active_function, active_state,
                            vm.pending_function, vm.pending_state);
                    break;
                }
                active_function = vm.pending_function;
                active_state = vm.pending_state;
            }
            for (size_t target = 0; target < shared_count; target++) {
                if (target == function) continue;
                memcpy(menu_script_contexts[target].vm.locals, vm.members[target], sizeof(vm.locals));
            }
            menu_script_contexts[function] = (LL_MenuScriptContext){
                vm, active_function, active_state, current_instance, vm.suspended
            };
            for (size_t target=0; target<shared_count; target++) {
                LL_MenuScriptContext *affected=&menu_script_contexts[target];
                if (vm.member_disable_requested[target]) {
                    affected->vm.state_flags=(uint16_t)((affected->vm.state_flags & ~1u) | vm.member_disabled[target]);
                    if (!vm.member_disabled[target]) affected->active=1;
                }
                if (vm.member_state_requested[target]) {
                    affected->function=(uint16_t)target;
                    affected->state=vm.member_states[target];
                    affected->active=affected->state != UINT16_MAX;
                    affected->vm.suspended=0;
                    affected->vm.host_wait_until=0;
                    affected->vm.host_color_wait=0;
                    affected->vm.host_animation_wait=0;
                }
            }
        }
    }
    fprintf(stderr, "INFO: option.cod initialized %zu BIB/BIZ scene objects\n",
            menu_scene_object_count);
    menu_animation_started = SDL_GetTicks();
    return 1;
}

/* FUN_004490f0 / FUN_00448e30: signed division truncates toward zero. */
static void menu_update_primitive_origins(void)
{
    /* FUN_00482cb0 indexes a 4096-amplitude sine table. */
    int yaw_sine = ll_native_sine(menu_camera.yaw);
    int pitch_sine = ll_native_sine(menu_camera.pitch);
    int32_t camera[2] = {
        -menu_camera.reference[0] / 16 + yaw_sine / 2,
        -menu_camera.reference[1] / 64 + pitch_sine / 96
    };
    int horizon=ll_native_camera_horizon(menu_camera.pitch,menu_camera.yaw,menu_camera.projection);
    for (unsigned owner = 0; owner < 256; owner++)
        for (unsigned index = 0; index < menu_primitive_child_count[owner]; index++) {
            LL_MenuPrimitiveChild *child = &menu_primitive_children[owner][index];
            if (!child->enabled) continue;
            if (child->tint_phase>=0) {
                if (child->tint_phase<=8) {
                    for (unsigned channel=0; channel<3; channel++)
                        child->tint[channel]=(uint8_t)(child->tint_start[channel]+
                            child->tint_delta[channel]*child->tint_phase/8);
                    child->tint_phase++;
                } else child->tint_phase=-1;
            }
            for (unsigned axis = 0; axis < 2; axis++) {
                int extent = child->rectangle[axis + 2u];
                if (extent <= 0) continue;
                int phase = (int16_t)(child->phase[axis] + (int8_t)child->transform[axis]);
                int limit = (int16_t)(extent * 16);
                if (phase > limit) phase -= extent * 16;
                else if (phase < 0) phase += limit;
                child->phase[axis] = (int16_t)phase;
                int position = camera[axis];
                if (axis == 1 && menu_primitive_parent_y[owner] != 0)
                    position += menu_primitive_parent_y[owner] + horizon;
                int offset = phase / 16 +
                    (int)((int64_t)(int16_t)child->transform[axis + 2u] * position / 256);
                child->origin[axis] = (int16_t)(offset % extent + child->rectangle[axis]);
            }
        }
}

static void menu_update_animation_callbacks(uint32_t tick)
{
    if (menu_script_contexts==NULL) return;
    for (size_t object=0;object<menu_scene_object_count;object++) {
        uint16_t owner=menu_animation_callback_owner[object];
        if (!owner || owner>menu_program.function_count || !menu_animation_once[object]) continue;
        const LL_BibAnimationTable *animation=ll_bib_get_animation_table(
            &game_level.bib,menu_animation_selector[object]);
        if (!animation || menu_animation_last[object]>=animation->record_count) continue;
        unsigned first=menu_animation_first[object], last=menu_animation_last[object];
        unsigned end=last>first ? last-1u : last;
        uint64_t duration=menu_animation_blend_ticks[object];
        for (unsigned frame=first;frame<=end;frame++)
            duration+=(uint64_t)animation->records[frame].sample_count*32u;
        if (menu_animation_elapsed(menu_animation_object_start[object],tick)>=duration)
            menu_script_contexts[owner-1u].vm.host_animation_wait=0;
    }
}

static void update_menu_scripts(uint32_t tick)
{
    static uint32_t previous_step;
    /* FUN_004056d0 sets FUN_004718e0(0x18): scripts, camera steps and
     * primitive phases run once per 24 Hz engine loop. Skeletal animation
     * separately follows FUN_00478360's 60-unit wall clock. Do not replay
     * missed script iterations after a slow frame. */
    uint32_t step = (uint32_t)((uint64_t)tick * 24u / 1000u);
    if (step == previous_step || menu_script_contexts == NULL) return;
    previous_step = step;
    if (menu_camera_transition.remaining != 0) {
        for (unsigned axis = 0; axis < 3; axis++)
            menu_camera.reference[axis] += menu_camera_transition.position_step[axis];
        for (unsigned axis = 0; axis < 2; axis++)
            menu_camera_transition.angle_fixed[axis] += menu_camera_transition.angle_step[axis];
        menu_camera.pitch = (int16_t)(menu_camera_transition.angle_fixed[0] >> 12);
        menu_camera.yaw = (int16_t)(menu_camera_transition.angle_fixed[1] >> 12);
        if (--menu_camera_transition.remaining == 0) menu_camera_motion_complete = 1;
    }
    menu_update_primitive_origins();
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    static const SDL_Scancode direction_keys[2][4] = {
        {SDL_SCANCODE_UP,SDL_SCANCODE_DOWN,SDL_SCANCODE_LEFT,SDL_SCANCODE_RIGHT},
        {SDL_SCANCODE_G,SDL_SCANCODE_V,SDL_SCANCODE_C,SDL_SCANCODE_B}
    };
    static const uint16_t direction_masks[4]={0x10,0x40,0x80,0x20};
    static const SDL_Scancode action_keys[2][4] = {
        {SDL_SCANCODE_C,SDL_SCANCODE_G,SDL_SCANCODE_B,SDL_SCANCODE_V},
        {SDL_SCANCODE_LEFT,SDL_SCANCODE_UP,SDL_SCANCODE_RIGHT,SDL_SCANCODE_DOWN}
    };
    /* FUN_0045e280: speed, jump, fire, dynamite indices per profile. */
    static const uint8_t profiles[3][4]={{0,1,2,3},{2,1,0,3},{3,2,0,1}};
    static const uint16_t action_masks[4]={0x4000,0x8000,0x2000,0x1000};
    uint16_t actions=0;
    for (unsigned action=0; action<4; action++) {
        if (keys[direction_keys[menu_keyboard_hand][action]]) actions |= direction_masks[action];
        if (keys[action_keys[menu_keyboard_hand][profiles[menu_control_profile][action]]]) actions |= action_masks[action];
    }
    if (keys[SDL_SCANCODE_RETURN]) actions |= 8;
    if (keys[SDL_SCANCODE_S]) actions |= 1;
    if (keys[SDL_SCANCODE_F]) actions |= 0x100;
    if ((actions & 0xa0u) == 0xa0u) actions &= (uint16_t)~0xa0u;
    if ((actions & 0x50u) == 0x50u) actions &= (uint16_t)~0x50u;
    menu_pressed_actions = (uint16_t)((menu_actions ^ actions) & (uint16_t)~menu_actions);
    menu_actions = actions;
    for (size_t key = 0; key < SDL_NUM_SCANCODES; key++) {
        /* FUN_0043f590: (previous XOR current) AND previous, i.e. release. */
        menu_released_keys[key] = menu_previous_keys[key] && !keys[key];
        menu_previous_keys[key] = keys[key];
    }
    for (uint16_t i = 0; i < menu_program.function_count; i++) {
        LL_MenuScriptContext *context = &menu_script_contexts[i];
        if (!context->active || (context->vm.state_flags & 1u)) continue;
        LL_SoolVM *vm = &context->vm;
        if (vm->host_animation_wait) continue;
        if (vm->host_color_wait) {
            unsigned token=vm->host_color_wait-1u;
            if (menu_primitive_children[token/16u][token%16u].tint_phase>=0) continue;
            vm->host_color_wait=0;
        }
        if (vm->host_wait_until != 0) {
            if ((int32_t)(SDL_GetTicks() - vm->host_wait_until) < 0) continue;
            vm->host_wait_until = 0;
        }
        /* Opcodes 0x08/0x29 address another function's local data. Supply
         * the live contexts instead of leaving each VM's bank private. */
        size_t shared_count = menu_program.function_count < 256u ? menu_program.function_count : 256u;
        for (size_t target = 0; target < shared_count; target++)
            memcpy(vm->members[target], menu_script_contexts[target].vm.locals,
                   sizeof(vm->locals));
        for (size_t target = 0; target < shared_count; target++)
            vm->member_states[target] = menu_script_contexts[target].state;
        memset(vm->member_state_requested,0,sizeof(vm->member_state_requested));
        memset(vm->member_disable_requested,0,sizeof(vm->member_disable_requested));
        for (size_t target = 0; target < shared_count; target++)
            vm->member_disabled[target] = (uint8_t)(menu_script_contexts[target].vm.state_flags & 1u);
        vm->has_pending_transition = 0;
        vm->current_state = (int16_t)context->state;
        menu_dispatch_vm = vm;
        menu_dispatch_context = i;
        menu_dispatch_function = context->function;
        if (!ll_sool_execute_state(&menu_program, context->function, context->state,
                                   vm, menu_sool_dispatch, &context->instance)) {
            fprintf(stderr, "ERROR: SOOL update %u:%u stopped at +0x%x opcode 0x%02x\n",
                    context->function, context->state, vm->last_instruction_offset, vm->last_opcode);
            context->active = 0;
            continue;
        }
        for (size_t target = 0; target < shared_count; target++) {
            if (target == i) continue;
            memcpy(menu_script_contexts[target].vm.locals, vm->members[target],
                   sizeof(vm->locals));
        }
        for (size_t target = 0; target < shared_count; target++) {
            if (vm->member_disable_requested[target]) {
                LL_MenuScriptContext *affected = &menu_script_contexts[target];
                affected->vm.state_flags = (uint16_t)((affected->vm.state_flags & ~1u) | vm->member_disabled[target]);
                if (!vm->member_disabled[target]) affected->active = 1;
            }
            if (!vm->member_state_requested[target]) continue;
            uint16_t state = vm->member_states[target];
            LL_MenuScriptContext *requested = &menu_script_contexts[target];
            if (target == i) {
                vm->pending_function = (uint16_t)target;
                vm->pending_state = state;
                vm->has_pending_transition = 1;
            } else {
                requested->function = (uint16_t)target;
                requested->state = state;
                requested->active = state != UINT16_MAX;
                requested->vm.suspended = 0;
                requested->vm.host_wait_until = 0;
                requested->vm.host_color_wait = 0;
                requested->vm.host_animation_wait = 0;
            }
        }
        if (getenv("LL_TRACE_SOOL") != NULL && (i == 5 || i == 10 || i == 14))
            fprintf(stderr, "TRACE: SOOL context %u state %u pc +0x%x suspended %d pending %d:%u locals20=%u locals26=%u selector=%u focus=%u dispatch=%u\n",
                    i, context->state, vm->last_instruction_offset, vm->suspended,
                    vm->has_pending_transition, vm->pending_state, vm->locals[20], vm->locals[26],
                    vm->locals[0x20], vm->locals[0x22], vm->locals[0x4a]);
        if (vm->has_pending_transition) {
            if (vm->pending_function >= menu_program.function_count || vm->pending_state == UINT16_MAX ||
                vm->pending_state >= menu_program.functions[vm->pending_function].state_count) {
                context->active = 0;
                continue;
            }
            context->function = vm->pending_function;
            context->state = vm->pending_state;
            vm->suspended = 0;
        } else context->active = vm->suspended;
    }
}

static void update_viewport(int width, int height)
{
    glViewport(0, 0, width, height);
}

static int mouse_to_logical_x(SDL_Window *window, int x)
{
    int width;
    SDL_GetWindowSize(window, &width, NULL);
    return width > 0 ? x * WINDOW_WIDTH / width : x;
}

static int mouse_to_logical_y(SDL_Window *window, int y)
{
    int height;
    SDL_GetWindowSize(window, NULL, &height);
    return height > 0 ? y * WINDOW_HEIGHT / height : y;
}

static const char *startup_language_member(void)
{
    switch (asset_config.language_code) {
    case 'f': return "LI_FR.PCX";
    case 'd': return "LI_GE.PCX";
    case 's': return "LI_SP.PCX";
    case 'i': return "LI_IT.PCX";
    case 'u': return "LI_DU.PCX";
    case 'b': return "LI_BR.PCX";
    default: return "LI_EN.PCX";
    }
}

static int load_kxp_texture(const unsigned char *archive_data,
                            size_t archive_size, const char *member_name,
                            LL_MenuTexture *texture)
{
    LL_KxpArchive archive;
    const unsigned char *payload;
    size_t payload_size;
    unsigned char *decoded;
    int result;

    if (!ll_kxp_open(&archive, archive_data, archive_size, "lucky")) {
        fprintf(stderr, "ERROR: invalid KXP archive win/graphics/FONT.KXP\n");
        return 0;
    }
    if (!ll_kxp_find(&archive, member_name, &payload, &payload_size)) {
        fprintf(stderr, "ERROR: missing or invalid FONT.KXP member %s\n",
                member_name);
        ll_kxp_close(&archive);
        return 0;
    }
    decoded = (unsigned char *)malloc(payload_size);
    if (decoded == NULL) {
        fprintf(stderr, "ERROR: cannot allocate %zu bytes for %s\n",
                payload_size, member_name);
        ll_kxp_close(&archive);
        return 0;
    }
    memcpy(decoded, payload, payload_size);
    if (archive.encrypted &&
        !ll_kxp_decrypt(decoded, payload_size, "lucky")) {
        fprintf(stderr, "ERROR: cannot decode FONT.KXP member %s\n",
                member_name);
        free(decoded);
        ll_kxp_close(&archive);
        return 0;
    }
    ll_kxp_close(&archive);
    result = ll_menu_art_load_from_memory(decoded, payload_size, texture);
    free(decoded);
    if (!result) {
        fprintf(stderr, "ERROR: member %s is not a supported PCX image\n",
                member_name);
    }
    return result;
}

static int show_intro_image(SDL_Window *window, int *running,
                            const LL_MenuTexture *image, int *skip)
{
    unsigned int start_time = SDL_GetTicks();

    while (*running && !*skip) {
        SDL_Event event;
        int drawable_width;
        int drawable_height;
        unsigned int elapsed_ms = SDL_GetTicks() - start_time;
        unsigned int frame = (elapsed_ms * 60u) / 1000u;

        /* The original tests max_frames * 60 inclusively and only accepts
         * skip input once min_frames * 60 is strictly below its loop count. */
        if (frame >= 10u * 60u) break;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                *running = 0;
            } else if (event.type == SDL_KEYDOWN ||
                       event.type == SDL_MOUSEBUTTONDOWN) {
                if (frame > 5u * 60u) {
                    *skip = 1;
                }
            } else if (event.type == SDL_WINDOWEVENT &&
                       event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                SDL_GL_GetDrawableSize(window, &drawable_width, &drawable_height);
                update_viewport(drawable_width, drawable_height);
            }
        }
        if (!*running) break;
        if (*skip) break;

        SDL_GL_GetDrawableSize(window, &drawable_width, &drawable_height);
        /* FUN_0043ff20 allocates a screen-sized surface and FUN_004408d0
         * copies the decoded PCX into it starting at (0, 0), without
         * centering or scaling the source. */
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, drawable_width, drawable_height, 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glDisable(GL_DEPTH_TEST);
        ll_menu_art_draw(image, 0.0f, 0.0f,
                         (float)image->width, (float)image->height);
        SDL_GL_SwapWindow(window);
        /* Keep the original loop cadence at 60 iterations per second. */
        {
            unsigned int next_frame_ms = ((frame + 1u) * 1000u) / 60u;
            unsigned int now_ms = SDL_GetTicks() - start_time;
            if (next_frame_ms > now_ms) SDL_Delay(next_frame_ms - now_ms);
        }
    }
    return *running;
}

static void run_intro(SDL_Window *window, int *running)
{
    LL_MenuTexture logo = {0};
    const char *members[2] = {"APLOGO.PCX", NULL};
    unsigned char *archive_data;
    size_t archive_size = 0;
    size_t index;

    if (running == NULL || !*running || asset_config.skip_intro) return;

    archive_data = read_cd_file("win/graphics/FONT.KXP", &archive_size);
    if (archive_data == NULL) {
        fprintf(stderr, "ERROR: cannot read CD asset win/graphics/FONT.KXP\n");
        menu_asset_errors |= MENU_ASSET_INTRO_MISSING;
        return;
    }
    members[1] = startup_language_member();

    /* Game.run calls the PCX loader and presents APLOGO before it chooses
     * and loads the localized image. Keep that order so a bad second member
     * does not prevent the first logo from being shown. */
    for (index = 0; index < sizeof(members) / sizeof(members[0]); index++) {
        int skip = 0;

        if (!*running) break;
        if (!load_kxp_texture(archive_data, archive_size, members[index], &logo)) {
            menu_asset_errors |= MENU_ASSET_INTRO_MISSING;
            continue;
        }
        show_intro_image(window, running, &logo, &skip);
        ll_menu_art_destroy(&logo);
    }
    ll_menu_art_destroy(&logo);
    free(archive_data);
}

static void draw_rect(float x, float y, float width, float height,
                      float red, float green, float blue)
{
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

static int glyph_index(char character)
{
    character = (char)toupper((unsigned char)character);
    if (character >= 'A' && character <= 'Z') {
        return character - 'A';
    }
    if (character >= '0' && character <= '9') {
        return character - '0' + 26;
    }
    return -1;
}

static void draw_text(const char *text, int x, int y, int scale,
                      float red, float green, float blue)
{
    glColor3f(red, green, blue);
    while (*text != '\0') {
        int index = glyph_index(*text++);
        int row;
        if (index >= 0) {
            for (row = 0; row < 7; row++) {
                int column;
                for (column = 0; column < 5; column++) {
                    if ((font[index][row] & (1u << (4 - column))) != 0) {
                        float left = (float)(x + column * scale);
                        float top = (float)(y + row * scale);
                        glBegin(GL_QUADS);
                        glVertex2f(left, top);
                        glVertex2f(left + scale, top);
                        glVertex2f(left + scale, top + scale);
                        glVertex2f(left, top + scale);
                        glEnd();
                    }
                }
            }
        } else if (* (text - 1) == '-') {
            draw_rect((float)x, (float)(y + 3 * scale), (float)(4 * scale),
                      (float)scale, red, green, blue);
        } else if (*(text - 1) == ':') {
            draw_rect((float)(x + 2 * scale), (float)(y + scale),
                      (float)scale, (float)scale, red, green, blue);
            draw_rect((float)(x + 2 * scale), (float)(y + 5 * scale),
                      (float)scale, (float)scale, red, green, blue);
        }
        x += 6 * scale;
    }
}

static void draw_menu_asset_errors(void)
{
    int line_count = 0;
    int y;
    float panel_height;

    if (menu_asset_errors == 0) {
        return;
    }
    line_count += (menu_asset_errors & MENU_ASSET_BIB_MISSING) != 0;
    line_count += (menu_asset_errors & MENU_ASSET_BIB_INVALID) != 0;
    line_count += (menu_asset_errors & MENU_ASSET_CONFIG_ERROR) != 0;
    line_count += (menu_asset_errors & MENU_ASSET_CD_MOUNT_ERROR) != 0;
    line_count += (menu_asset_errors & MENU_ASSET_INTRO_MISSING) != 0;
    line_count += (menu_asset_errors & MENU_ASSET_BIZ_MISSING) != 0;
    line_count += (menu_asset_errors & MENU_ASSET_BIZ_INVALID) != 0;
    panel_height = 27.0f + (float)line_count * 12.0f;

    draw_rect(6.0f, 6.0f, 286.0f, panel_height, 0.12f, 0.025f, 0.025f);
    draw_rect(6.0f, 6.0f, 286.0f, 2.0f, 0.95f, 0.22f, 0.14f);
    draw_rect(6.0f, 6.0f, 2.0f, panel_height, 0.95f, 0.22f, 0.14f);
    draw_text("MENU RESOURCE ERROR", 14, 12, 1,
              1.0f, 0.72f, 0.65f);
    y = 25;
    if (menu_asset_errors & MENU_ASSET_BIB_MISSING) {
        draw_text("OPTION BIB MISSING", 14, y, 1, 1.0f, 0.9f, 0.84f);
        y += 12;
    }
    if (menu_asset_errors & MENU_ASSET_BIB_INVALID) {
        draw_text("OPTION BIB UNSUPPORTED OR INVALID", 14, y, 1,
                  1.0f, 0.9f, 0.84f);
        y += 12;
    }
    if (menu_asset_errors & MENU_ASSET_CONFIG_ERROR) {
        draw_text("CONFIG INI MISSING OR INVALID", 14, y, 1,
                  1.0f, 0.9f, 0.84f);
        y += 12;
    }
    if (menu_asset_errors & MENU_ASSET_CD_MOUNT_ERROR) {
        draw_text("CD MOUNT DIRECTORY INVALID", 14, y, 1,
                  1.0f, 0.9f, 0.84f);
        y += 12;
    }
    if (menu_asset_errors & MENU_ASSET_INTRO_MISSING) {
        draw_text("STARTUP KXP OR LOGO MISSING/INVALID", 14, y, 1,
                  1.0f, 0.9f, 0.84f);
        y += 12;
    }
    if (menu_asset_errors & MENU_ASSET_BIZ_MISSING) {
        draw_text("OPTION BIZ MISSING", 14, y, 1, 1.0f, 0.9f, 0.84f);
        y += 12;
    }
    if (menu_asset_errors & MENU_ASSET_BIZ_INVALID) {
        draw_text("OPTION BIZ INVALID", 14, y, 1, 1.0f, 0.9f, 0.84f);
    }
}

static void draw_box(float center_x, float bottom_y, float center_z,
                     float width, float height, float depth,
                     float red, float green, float blue)
{
    float left = center_x - width * 0.5f;
    float right = center_x + width * 0.5f;
    float top = bottom_y + height;
    float front = center_z + depth * 0.5f;
    float back = center_z - depth * 0.5f;

    glBegin(GL_QUADS);
    glColor3f(red, green, blue);
    glVertex3f(left, bottom_y, front); glVertex3f(right, bottom_y, front);
    glVertex3f(right, top, front); glVertex3f(left, top, front);
    glColor3f(red * 0.62f, green * 0.62f, blue * 0.68f);
    glVertex3f(left, bottom_y, back); glVertex3f(left, bottom_y, front);
    glVertex3f(left, top, front); glVertex3f(left, top, back);
    glColor3f(red * 0.43f, green * 0.43f, blue * 0.52f);
    glVertex3f(right, bottom_y, back); glVertex3f(left, bottom_y, back);
    glVertex3f(left, top, back); glVertex3f(right, top, back);
    glColor3f(red * 0.76f, green * 0.76f, blue * 0.82f);
    glVertex3f(right, bottom_y, front); glVertex3f(right, bottom_y, back);
    glVertex3f(right, top, back); glVertex3f(right, top, front);
    glColor3f(red * 0.72f, green * 0.72f, blue * 0.78f);
    glVertex3f(left, top, front); glVertex3f(right, top, front);
    glVertex3f(right, top, back); glVertex3f(left, top, back);
    glColor3f(red * 0.34f, green * 0.34f, blue * 0.42f);
    glVertex3f(left, bottom_y, back); glVertex3f(right, bottom_y, back);
    glVertex3f(right, bottom_y, front); glVertex3f(left, bottom_y, front);
    glEnd();
}

static void draw_window(float x, float y, float z, float width, float height,
                        float glow)
{
    glColor3f(glow, glow * 0.67f, glow * 0.33f);
    glBegin(GL_QUADS);
    glVertex3f(x, y, z); glVertex3f(x + width, y, z);
    glVertex3f(x + width, y + height, z); glVertex3f(x, y + height, z);
    glEnd();
}

static void draw_building(float x, float z, float width, float height,
                          float red, float green, float blue, int columns)
{
    int row;
    int column;
    float bottom = -2.55f;

    draw_box(x, bottom, z, width, height, 1.0f, red, green, blue);
    draw_box(x, bottom + height, z + 0.04f, width + 0.22f, 0.14f, 1.25f,
             red * 0.58f, green * 0.50f, blue * 0.50f);
    for (row = 0; row < 2; row++) {
        for (column = 0; column < columns; column++) {
            float window_x = x - width * 0.34f +
                width * 0.68f * (float)column / (float)(columns > 1 ? columns - 1 : 1);
            float window_y = bottom + 0.92f + (float)row * 1.18f;
            float glow = (row == 0 && column % 2 == 0) ? 0.72f : 0.24f;
            draw_window(window_x, window_y, z + 0.51f, 0.26f, 0.46f, glow);
        }
    }
    draw_box(x, bottom + 0.48f, z + 0.54f, 0.78f, 0.96f, 0.12f,
             0.09f, 0.055f, 0.04f);
}

static void draw_stars_and_moon(void)
{
    static const float stars[][3] = {
        {-8.0f, 5.2f, -23.0f}, {-6.0f, 6.1f, -24.0f}, {-3.0f, 4.8f, -22.0f},
        {0.0f, 6.5f, -26.0f}, {2.1f, 5.3f, -24.0f}, {4.0f, 6.2f, -25.0f},
        {7.0f, 4.8f, -24.0f}, {8.3f, 6.0f, -27.0f}, {-7.1f, 3.8f, -26.0f},
        {-1.0f, 5.8f, -24.0f}, {5.8f, 3.9f, -22.0f}, {1.0f, 4.3f, -27.0f}
    };
    static const float moon[][2] = {
        {0.0f, -0.82f}, {0.41f, -0.71f}, {0.71f, -0.41f}, {0.82f, 0.0f},
        {0.71f, 0.41f}, {0.41f, 0.71f}, {0.0f, 0.82f}, {-0.41f, 0.71f},
        {-0.71f, 0.41f}, {-0.82f, 0.0f}, {-0.71f, -0.41f}, {-0.41f, -0.71f}
    };
    size_t index;

    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3f(0.82f, 0.82f, 0.72f);
    for (index = 0; index < sizeof(stars) / sizeof(stars[0]); index++) {
        glVertex3f(stars[index][0], stars[index][1], stars[index][2]);
    }
    glEnd();

    glColor3f(0.94f, 0.85f, 0.63f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(5.4f, 4.0f, -11.0f);
    for (index = 0; index < sizeof(moon) / sizeof(moon[0]); index++) {
        glVertex3f(5.4f + moon[index][0], 4.0f + moon[index][1], -11.0f);
    }
    glVertex3f(5.4f, 3.18f, -11.0f);
    glEnd();
}

static void draw_western_scene(float swing_angle)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.72, 0.72, -0.54, 0.54, 1.0, 90.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -18.0f);
    glDisable(GL_DEPTH_TEST);

    glBegin(GL_QUADS);
    glColor3f(0.025f, 0.055f, 0.13f);
    glVertex3f(-100.0f, 60.0f, -34.0f);
    glVertex3f(100.0f, 60.0f, -34.0f);
    glColor3f(0.17f, 0.11f, 0.15f);
    glVertex3f(100.0f, -12.0f, -34.0f);
    glVertex3f(-100.0f, -12.0f, -34.0f);
    glEnd();

    draw_stars_and_moon();
    glEnable(GL_DEPTH_TEST);
    draw_box(0.0f, -2.72f, -12.0f, 44.0f, 0.10f, 50.0f,
             0.13f, 0.105f, 0.095f);
    draw_building(-12.0f, -15.0f, 4.3f, 3.4f, 0.20f, 0.13f, 0.12f, 3);
    draw_building(-7.3f, -16.0f, 4.8f, 4.2f, 0.24f, 0.16f, 0.13f, 3);
    draw_building(1.0f, -17.0f, 5.0f, 3.8f, 0.20f, 0.14f, 0.13f, 3);
    draw_building(6.7f, -15.0f, 4.5f, 4.6f, 0.22f, 0.15f, 0.14f, 3);
    draw_building(12.1f, -16.0f, 4.2f, 3.4f, 0.18f, 0.12f, 0.12f, 2);

    draw_box(-11.0f, -2.62f, -7.0f, 6.0f, 4.2f, 2.0f, 0.25f, 0.15f, 0.105f);
    draw_box(-11.0f, 1.58f, -7.0f, 6.4f, 0.20f, 2.3f, 0.13f, 0.09f, 0.075f);
    draw_box(10.6f, -2.62f, -7.0f, 5.4f, 5.0f, 2.0f, 0.20f, 0.13f, 0.11f);
    draw_box(10.6f, 2.38f, -7.0f, 5.8f, 0.20f, 2.3f, 0.12f, 0.085f, 0.07f);

    /* Scale around the boots to keep Lucky grounded while making the silhouette readable. */
    glPushMatrix();
    glTranslatef(-3.2f, -2.55f, -2.6f);
    glScalef(1.55f, 1.55f, 1.55f);
    glTranslatef(3.2f, 2.55f, 2.6f);
    draw_box(-3.2f, -2.55f, -2.6f, 0.40f, 1.15f, 0.48f, 0.15f, 0.11f, 0.085f);
    draw_box(-2.35f, -2.55f, -2.6f, 0.40f, 1.15f, 0.48f, 0.15f, 0.11f, 0.085f);
    draw_box(-3.2f, -1.42f, -2.6f, 1.50f, 1.40f, 0.75f, 0.76f, 0.61f, 0.38f);
    draw_box(-3.2f, -1.20f, -2.17f, 1.15f, 0.22f, 0.12f, 0.70f, 0.12f, 0.10f);
    draw_box(-3.2f, 0.02f, -2.6f, 0.62f, 0.70f, 0.58f, 0.79f, 0.63f, 0.43f);
    draw_box(-3.2f, 0.67f, -2.6f, 1.34f, 0.13f, 0.78f, 0.13f, 0.09f, 0.06f);
    draw_box(-3.2f, 0.80f, -2.6f, 0.88f, 0.36f, 0.60f, 0.12f, 0.08f, 0.055f);
    draw_box(-2.36f, -1.18f, -2.6f, 0.38f, 0.92f, 0.36f, 0.70f, 0.51f, 0.30f);
    draw_box(-4.00f, -1.15f, -2.6f, 0.34f, 0.78f, 0.34f, 0.68f, 0.49f, 0.28f);

    glPushMatrix();
    glTranslatef(-2.20f, -0.46f, -2.48f);
    glRotatef(swing_angle, 0.0f, 0.0f, 1.0f);
    draw_box(0.32f, -0.08f, 0.0f, 0.90f, 0.17f, 0.18f, 0.55f, 0.38f, 0.22f);
    draw_box(0.78f, 0.02f, 0.0f, 0.46f, 0.13f, 0.16f, 0.27f, 0.28f, 0.28f);
    draw_box(0.02f, -0.36f, 0.0f, 0.15f, 0.40f, 0.17f, 0.31f, 0.21f, 0.12f);
    glPopMatrix();
    glPopMatrix();
    glDisable(GL_DEPTH_TEST);
}

static void draw_procedural_background(unsigned int tick)
{
    float phase = (float)(tick % 1600u) / 800.0f;
    float swing_angle = phase <= 1.0f ? 45.0f + phase * 85.0f
                                      : 130.0f - (phase - 1.0f) * 85.0f;

    glClearColor(0.035f, 0.045f, 0.075f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_western_scene(swing_angle);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
}

typedef struct {
    uint16_t object;
    GLuint texture;
    uint32_t width, height;
    LL_BizSprite sprite;
} LL_MenuMaterial;
static LL_MenuMaterial menu_materials[512];
static size_t menu_material_count;

/* Mutable expanded-page deltas preserve all aliasing crops and copy order,
 * without modifying the original packed BIZ buffer. */
static int menu_write_biz_page(unsigned page, unsigned x, unsigned y,
                                unsigned width, unsigned height, const unsigned char *rgba)
{
    if (page>=32u || x>=256u || y>=256u ||
        width==0 || height==0 || width>256u-x || height>256u-y || rgba==NULL) return 0;
    if (menu_biz_updates[page]==NULL) {
        unsigned char *pixels=calloc(256u*256u,4u), *mask=calloc(256u*256u,1u);
        if (pixels==NULL || mask==NULL) { free(pixels);free(mask);return 0; }
        menu_biz_updates[page]=pixels;
        menu_biz_update_masks[page]=mask;
    }
    for (unsigned row=0;row<height;row++) {
        size_t target=(size_t)(y+row)*256u+x;
        memcpy(menu_biz_updates[page]+target*4u,rgba+(size_t)row*width*4u,(size_t)width*4u);
        memset(menu_biz_update_masks[page]+target,1,width);
    }
    menu_biz_revision++;
    return 1;
}

static void menu_apply_biz_page(const LL_BizSprite *sprite, unsigned char *pixels,
                                 uint32_t width, uint32_t height)
{
    unsigned page=sprite->field_0e;
    if (page>=32u || menu_biz_updates[page]==NULL) return;
    for (uint32_t y=0;y<height;y++) for (uint32_t x=0;x<width;x++) {
        size_t source=(size_t)(sprite->texture_y+y)*256u+sprite->texture_x+x;
        if (menu_biz_update_masks[page][source])
            memcpy(pixels+((size_t)y*width+x)*4u,menu_biz_updates[page]+source*4u,4u);
    }
}

typedef struct {
    LL_PcxImage image;
    unsigned page, x, y;
    int attempted;
} LL_MenuPagePatch;
static LL_MenuPagePatch menu_page_patches[12] = {
    {.page=6,.x=79,.y=0}, {.page=14,.x=0,.y=0},
    {.page=14,.x=0,.y=100}, {.page=14,.x=0,.y=202}
};

static void menu_load_page_patch(LL_MenuPagePatch *patch,
                                  const char *archive_path, const char *member)
{
    if (patch->attempted) return;
    patch->attempted = 1;
    size_t archive_size = 0, payload_size = 0;
    unsigned char *data = read_cd_file(archive_path, &archive_size);
    LL_KxpArchive archive;
    const unsigned char *payload = NULL;
    unsigned char *decoded = NULL;
    int opened = data != NULL && ll_kxp_open(&archive, data, archive_size, "lucky");
    int ok = opened && ll_kxp_find(&archive, member, &payload, &payload_size);
    if (ok) {
        decoded = malloc(payload_size);
        ok = decoded != NULL;
    }
    if (ok) {
        memcpy(decoded, payload, payload_size);
        ok = (!archive.encrypted || ll_kxp_decrypt(decoded, payload_size, "lucky")) &&
             ll_pcx_decode(decoded, payload_size, &patch->image);
        if (ok && (patch->image.width > 256 - (int)patch->x || patch->image.height > 256 - (int)patch->y)) {
            ll_pcx_destroy(&patch->image);
            ok = 0;
        }
    }
    if (ok) {
        for (size_t pixel=0; pixel<(size_t)patch->image.width*patch->image.height; pixel++) {
            unsigned char *rgba=patch->image.rgba_pixels+pixel*4u;
            /* FUN_00432510 truncates PCX channels to five bits before
             * FUN_004318a0 packs the shared texture page. Expand using
             * the same convention as ll_biz_decode_sprite. */
            unsigned rgb_or=0;
            for (unsigned channel=0; channel<3; channel++) {
                unsigned value=rgba[channel]>>3;
                rgb_or|=value;
                rgba[channel]=(unsigned char)((value*255u+15u)/31u);
            }
            rgba[3]=rgb_or ? 255 : 0;
        }
        ok=menu_write_biz_page(patch->page,patch->x,patch->y,
                              (unsigned)patch->image.width,(unsigned)patch->image.height,patch->image.rgba_pixels);
    }
    if (!ok) fprintf(stderr, "ERROR: cannot load bounded %s patch from %s\n", member, archive_path);
    else fprintf(stderr, "INFO: loaded %s %dx%d for BIZ page %u at (%u,%u)\n",
                 member, patch->image.width, patch->image.height, patch->page, patch->x, patch->y);
    free(decoded);
    if (opened) ll_kxp_close(&archive);
    free(data);
}

static void menu_load_material_patches(unsigned page)
{
    if (page == 6) menu_load_page_patch(&menu_page_patches[0], "win/graphics/fixgfx.kxp", "moon.pcx");
    if (page != 14) return;
    const char *language = "en";
    switch (asset_config.language_code) {
    case 'f': language="fr"; break; case 'd': language="ge"; break;
    case 's': language="sp"; break; case 'i': language="it"; break;
    case 'u': language="du"; break; case 'b': language="br"; break;
    }
    char member[32];
    snprintf(member,sizeof(member),"rh_%s.pcx",language);
    menu_load_page_patch(&menu_page_patches[1], "win/graphics/handed.kxp", member);
    snprintf(member,sizeof(member),"lh_%s.pcx",language);
    menu_load_page_patch(&menu_page_patches[2], "win/graphics/handed.kxp", member);
    menu_load_page_patch(&menu_page_patches[3], "win/graphics/handed.kxp", "cross.pcx");
}

static void menu_load_key_patches(void)
{
    static int hand=-1;
    static const uint16_t targets[8]={0x6d,0x120,0x6b,0x71,0x11e,0x11f,0x6f,0x69};
    static const char *const members[2][8]={
        {"key_v.pcx","key_v.pcx","key_b.pcx","key_g.pcx","key_g.pcx","key_c.pcx","key_c.pcx","key_f.pcx"},
        {"key_down.pcx","key_down.pcx","key_rite.pcx","key_up.pcx","key_up.pcx","key_left.pcx","key_left.pcx","key_f.pcx"}
    };
    if (hand==menu_keyboard_hand) return;
    hand=menu_keyboard_hand;
    for (unsigned i=0;i<8;i++) {
        LL_MenuPagePatch *patch=&menu_page_patches[4u+i];
        ll_pcx_destroy(&patch->image);
        memset(patch,0,sizeof(*patch));
        LL_BizObject object;
        LL_BizSprite sprite;
        if (!ll_biz_get_object(&menu_biz,targets[i],&object) ||
            !ll_biz_get_sprite(&menu_biz,object.sprite_index,&sprite)) {
            fprintf(stderr,"ERROR: keyboard patch target BIZ %u is unavailable\n",targets[i]);
            continue;
        }
        patch->page=sprite.field_0e;
        patch->x=sprite.texture_x;
        patch->y=sprite.texture_y;
        if (patch->x>=256 || patch->y>=256) {
            fprintf(stderr,"ERROR: keyboard patch target BIZ %u exceeds texture page\n",targets[i]);
            continue;
        }
        menu_load_page_patch(patch,"win/graphics/keys.kxp",members[hand][i]);
    }
}

static void menu_prepare_biz_pages(void)
{
    menu_load_key_patches();
    menu_load_material_patches(6);
    menu_load_material_patches(14);
}

static int menu_copy_biz_pixels(uint16_t destination, uint16_t source)
{
    menu_prepare_biz_pages();
    LL_BizObject src,dst;
    LL_BizSprite source_sprite,destination_sprite;
    unsigned char pixels[256u*256u*4u];
    uint32_t width,height;
    if (!ll_biz_get_object(&menu_biz,source,&src) || !ll_biz_get_object(&menu_biz,destination,&dst) ||
        !ll_biz_get_sprite(&menu_biz,src.sprite_index,&source_sprite) ||
        !ll_biz_get_sprite(&menu_biz,dst.sprite_index,&destination_sprite) ||
        !ll_biz_decode_sprite(&menu_biz,src.sprite_index,src.tile_index,pixels,sizeof(pixels),&width,&height)) return 0;
    menu_apply_biz_page(&source_sprite,pixels,width,height);
    return menu_write_biz_page(destination_sprite.field_0e,destination_sprite.texture_x,
                               destination_sprite.texture_y,width,height,pixels);
}

static const LL_MenuMaterial *menu_material(uint16_t object_index)
{
    LL_BizObject object;
    unsigned char pixels[256 * 256 * 4];
    LL_MenuMaterial *material;
    static uint32_t revision;
    menu_prepare_biz_pages();
    if (revision != menu_biz_revision) {
        for (size_t i = 0; i < menu_material_count; i++)
            if (menu_materials[i].texture != 0) glDeleteTextures(1,&menu_materials[i].texture);
        memset(menu_materials,0,sizeof(menu_materials));
        menu_material_count = 0;
        revision = menu_biz_revision;
    }
    for (size_t i = 0; i < menu_material_count; i++)
        if (menu_materials[i].object == object_index) return &menu_materials[i];
    if (menu_material_count == sizeof(menu_materials) / sizeof(menu_materials[0])) return NULL;
    material = &menu_materials[menu_material_count++];
    material->object = object_index;
    if (!ll_biz_get_object(&menu_biz, object_index, &object) ||
        !ll_biz_get_sprite(&menu_biz, object.sprite_index, &material->sprite) ||
        !ll_biz_decode_sprite(&menu_biz, object.sprite_index, object.tile_index,
                              pixels, sizeof(pixels), &material->width, &material->height)) {
        fprintf(stderr, "ERROR: cannot decode BIB face BIZ material object %u\n", object_index);
        return material;
    }
    menu_apply_biz_page(&material->sprite,pixels,material->width,material->height);
    glGenTextures(1, &material->texture);
    glBindTexture(GL_TEXTURE_2D, material->texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)material->width,
                 (GLsizei)material->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    return material;
}

/* Model rotation uses FUN_0047c630, distinct from the camera builder. */
static void menu_apply_model_rotation(const int32_t angles[3])
{
    int16_t rows[3][3];
    ll_native_model_rotation(angles,rows);
    GLdouble matrix[16] = {0};
    for (unsigned r = 0; r < 3; r++)
        for (unsigned col = 0; col < 3; col++) matrix[col * 4u + r] = rows[r][col]/4096.0;
    matrix[15] = 1;
    glMultMatrixd(matrix);
}

static int menu_build_animation_pose(uint32_t model_index, uint16_t selector, uint32_t frame, uint32_t fraction,
                                 int play_once, LL_BibVertex *vertices, const LL_BibPackedPose *initial,
                                 uint32_t initial_fraction, LL_BibPackedPose *evaluated)
{
    const LL_Bib3dxModel *model = ll_bib_get_model(&game_level.bib, model_index);
    const LL_BibAnimationTable *table = ll_bib_get_animation_table(&game_level.bib, selector);
    if (model == NULL || table == NULL) return 0;
    LL_BibPackedPose *poses = calloc(table->record_type, sizeof(*poses));
    if (poses == NULL) return 0;
    if (!ll_bib_decode_animation_frame(&game_level.bib, selector, frame, poses,
                                        table->record_type, NULL)) { free(poses); return 0; }
    if (fraction != 0) {
        LL_BibPackedPose *next = calloc(table->record_type, sizeof(*next));
        if (next == NULL) { free(poses); return 0; }
        if (!ll_bib_decode_animation_frame(&game_level.bib, selector,
                (play_once && frame + 1u == table->record_count ? frame : (frame + 1u) % table->record_count), next, table->record_type, NULL)) {
            free(next); free(poses); return 0;
        }
        for (unsigned p = 0; p < table->record_type; p++)
            ll_bib_interpolate_pose(&poses[p], &next[p], fraction, &poses[p]);
        free(next);
    }
    if (initial) for (unsigned part=0;part<table->record_type;part++)
        ll_bib_interpolate_pose(&initial[part],&poses[part],initial_fraction,&poses[part]);
    GLdouble current[16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
    GLdouble saved[64][16];
    size_t depth = 0;
    int ok = 1;
    for (uint32_t i = 0;; i++) {
        int32_t entry;
        if (!ll_bib_get_model_hierarchy_entry(&game_level.bib, model_index, i, &entry)) break;
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
        if ((uint32_t)entry >= table->record_type ||
            !ll_bib_get_model_part(&game_level.bib, model_index, (uint32_t)entry, &part)) { ok = 0; break; }
        const LL_BibPackedPose *pose = &poses[entry];
        int32_t pivot[3] = {0,0,0};
        if (i != 0) for (unsigned a = 0; a < 3; a++) pivot[a] = vertices[part.pivot_vertex].position[a];
        int16_t basis[9];
        for (unsigned r=0;r<3;r++)
            for (unsigned c=0;c<3;c++) basis[r*3u+c]=(int16_t)(current[c*4u+r]*4096.0);
        if (pose->present_groups & 2u) {
            int16_t offset[3]={pose->channels[3],pose->channels[4],pose->channels[5]}, translated[3];
            ll_native_vertex_transform(basis,offset,pivot,NULL,translated);
            for (unsigned axis=0;axis<3;axis++) pivot[axis]=translated[axis];
        }
        /* FUN_004824a0 installs each pivot as the current translation.
         * Explicit translation channels are offsets from that pivot, rotated
         * through the current parent basis. */
        for (unsigned axis = 0; axis < 3; axis++) current[12u + axis] = pivot[axis];
        if (pose->present_groups & 1u) {
            int32_t angles[3] = {pose->channels[0],pose->channels[1],pose->channels[2]};
            int16_t local[3][3], composed[9];
            ll_native_model_rotation(angles,local);
            ll_native_rotation_multiply(basis,&local[0][0],composed);
            memcpy(basis,composed,sizeof(basis));
            for (unsigned r=0;r<3;r++)
                for (unsigned c=0;c<3;c++) current[c*4u+r]=composed[r*3u+c]/4096.0;
        }
        int32_t scale[3]={4096+pose->channels[6],4096+pose->channels[7],4096+pose->channels[8]};
        int has_scale=(pose->present_groups & 4u)!=0;
        int32_t next_entry=0;
        if (has_scale && (pose->present_groups & 2u) &&
            ll_bib_get_model_hierarchy_entry(&game_level.bib,model_index,i+1u,&next_entry) &&
            (next_entry==-2 || next_entry==-3)) {
            /* FUN_004823e0 branch: quantize the scaled basis, rather
             * than prescaling each source vertex (FUN_0047f830). */
            ll_native_rotation_scale(basis,scale);
            for (unsigned r=0;r<3;r++)
                for (unsigned c=0;c<3;c++) current[c*4u+r]=basis[r*3u+c]/4096.0;
            has_scale=0;
        }
        for (uint32_t v = part.first_vertex; v < (uint32_t)part.first_vertex + part.vertex_count; v++) {
            ll_native_vertex_transform(basis,model->vertices[v].position,pivot,
                has_scale ? scale : NULL,vertices[v].position);
        }
        if (!ok) break;
    }
    if (ok && evaluated) memcpy(evaluated,poses,(size_t)table->record_type*sizeof(*poses));
    free(poses);
    return ok;
}

static int menu_build_first_pose(uint32_t model_index, uint16_t selector, uint32_t frame, uint32_t fraction,
                                 int play_once, LL_BibVertex *vertices)
{
    return menu_build_animation_pose(model_index,selector,frame,fraction,play_once,vertices,NULL,0,NULL);
}

static void menu_render_background_sprites(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 512, 256, 0, -1, 1); /* FUN_004478b0 */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.0f);
    glColor4ub(255, 255, 255, 255);
    for (unsigned owner = 0; owner < 256; owner++)
        for (unsigned index = 0; index < menu_primitive_child_count[owner]; index++) {
            const LL_MenuPrimitiveChild *child = &menu_primitive_children[owner][index];
            if (!child->enabled || child->draw_flags != 0) continue;
            for (unsigned primitive = 0; primitive < child->primitive_count; primitive++) {
                const LL_MenuBackgroundPrimitive *item = &child->primitives[primitive];
                int x = child->origin[0] + item->rectangle[0];
                int y = child->origin[1] + item->rectangle[1];
                if (x > child->rectangle[0] + child->rectangle[2]) x -= child->rectangle[2];
                else if (x < child->rectangle[0]) x += child->rectangle[2];
                if (y > child->rectangle[1] + child->rectangle[3]) y -= child->rectangle[3];
                else if (y < child->rectangle[1]) y += child->rectangle[3];
                int width = item->rectangle[2], height = item->rectangle[3];
                if (width <= 0 || height <= 0) continue;
                if (!item->is_sprite) {
                    glDisable(GL_TEXTURE_2D);
                    glDisable(GL_ALPHA_TEST);
                    glBegin(GL_QUADS);
                    glColor3f(item->top[0]*child->tint[0]/32640.0f,item->top[1]*child->tint[1]/32640.0f,item->top[2]*child->tint[2]/32640.0f);
                    glVertex2i(x,y); glVertex2i(x+width,y);
                    glColor3f(item->bottom[0]*child->tint[0]/32640.0f,item->bottom[1]*child->tint[1]/32640.0f,item->bottom[2]*child->tint[2]/32640.0f);
                    glVertex2i(x+width,y+height); glVertex2i(x,y+height);
                    glEnd();
                    continue;
                }
                const LL_MenuMaterial *material = menu_material(item->sprite_object);
                if (material == NULL || material->texture == 0) continue;
                double u0 = (double)item->source[0] / material->width;
                double v0 = (double)item->source[1] / material->height;
                double u1 = u0 + (double)item->source[2] / material->width;
                double v1 = v0 + (double)item->source[3] / material->height;
                glColor4f(child->tint[0]/128.0f,child->tint[1]/128.0f,child->tint[2]/128.0f,1);
                glEnable(GL_TEXTURE_2D);
                glEnable(GL_ALPHA_TEST);
                glBindTexture(GL_TEXTURE_2D, material->texture);
                glBegin(GL_QUADS);
                glTexCoord2d(u0,v0); glVertex2i(x,y);
                glTexCoord2d(u1,v0); glVertex2i(x+width,y);
                glTexCoord2d(u1,v1); glVertex2i(x+width,y+height);
                glTexCoord2d(u0,v1); glVertex2i(x,y+height);
                glEnd();
            }
        }
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_ALPHA_TEST);
}

static void menu_render_screen_sprites(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /* FUN_00412f20 leaves menu positions in output pixels (level 1).
     * Only background primitives use the 512x256 coordinate conversion. */
    glOrtho(0,WINDOW_WIDTH,WINDOW_HEIGHT,0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER,0);
    glColor4ub(255,255,255,255);
    for (size_t i = 0; i < menu_scene_object_count; i++) {
        const LL_MenuSceneObject *object = &menu_scene_objects[i];
        if (!object->is_biz_sprite || !object->visible || !menu_sprite_has_screen[i]) continue;
        const LL_MenuMaterial *material = menu_material(object->biz_object);
        if (material == NULL || material->texture == 0 || material->width <= 2u || material->height <= 2u) continue;
        double x = menu_sprite_screen[i][0] + menu_sprite_offset[i][0] * object->scale / 16.0 * WINDOW_WIDTH / 512.0;
        double y = menu_sprite_screen[i][1] + menu_sprite_offset[i][1] * object->scale / 16.0 * WINDOW_HEIGHT / 256.0;
        double width = (material->width - 2u) * object->scale / 16.0 * WINDOW_WIDTH / 512.0;
        double height = (material->height - 2u) * object->scale / 16.0 * WINDOW_HEIGHT / 256.0;
        glBindTexture(GL_TEXTURE_2D,material->texture);
        double u0 = 1.0 / material->width, v0 = 1.0 / material->height;
        double u1 = 1.0 - u0, v1 = 1.0 - v0;
        glBegin(GL_QUADS);
        glTexCoord2d(u0,v0); glVertex2d(x,y);
        glTexCoord2d(u1,v0); glVertex2d(x+width,y);
        glTexCoord2d(u1,v1); glVertex2d(x+width,y+height);
        glTexCoord2d(u0,v1); glVertex2d(x,y+height);
        glEnd();
    }
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_ALPHA_TEST);
}

static void menu_render_sprite_groups(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,WINDOW_WIDTH,WINDOW_HEIGHT,0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER,0);
    glColor4ub(255,255,255,255);
    for (unsigned id=0; id<256; id++) {
        const LL_MenuSpriteGroup *group=&menu_sprite_groups[id];
        if (group->enabled != 1) continue;
        for (unsigned index=0; index<group->count; index++) {
            const LL_MenuGroupSprite *sprite=&group->children[index];
            if (!sprite->present) continue;
            LL_BibSpriteFrame frame;
            if (!ll_bib_get_sprite_frame(&game_level.bib,sprite->selector,sprite->frame,&frame)) continue;
            const LL_MenuMaterial *material=menu_material(frame.object_index);
            if (material==NULL || material->texture==0 || material->width<=2 || material->height<=2) continue;
            double sx=sprite->scale/16.0*WINDOW_WIDTH/512.0;
            double sy=sprite->scale/16.0*WINDOW_HEIGHT/256.0;
            double x=sprite->position[0]+frame.offset_x*sx;
            double y=sprite->position[1]+frame.offset_y*sy;
            double w=(material->width-2u)*sx, h=(material->height-2u)*sy;
            double u=1.0/material->width, v=1.0/material->height;
            glBindTexture(GL_TEXTURE_2D,material->texture);
            glBegin(GL_QUADS);
            glTexCoord2d(u,v);glVertex2d(x,y);
            glTexCoord2d(1-u,v);glVertex2d(x+w,y);
            glTexCoord2d(1-u,1-v);glVertex2d(x+w,y+h);
            glTexCoord2d(u,1-v);glVertex2d(x,y+h);
            glEnd();
        }
    }
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_ALPHA_TEST);
    if (menu_marker_enabled && menu_marker_index<4) {
        double sx=WINDOW_WIDTH/512.0, sy=WINDOW_HEIGHT/256.0;
        double x=(menu_marker_index==3?231:194)*sx;
        double y=(menu_marker_index==3?170:34+menu_marker_index*45)*sy;
        double w=(menu_marker_index==3?46:121)*sx, h=29*sy;
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(255,255,64,90);
        glBegin(GL_QUADS);
        glVertex2d(x,y);glVertex2d(x+w,y);glVertex2d(x+w,y+h);glVertex2d(x,y+h);
        glEnd();
        glDisable(GL_BLEND);
    }
}

static void render_menu(int selection, int page, unsigned int tick)
{
    (void)page;
    /* Render the BIB/BIZ scene as background, then draw the menu overlay
     * (title, buttons, selection) on top. */
    glClearColor(0.012f, 0.018f, 0.045f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    menu_render_background_sprites();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    /* ---- Advance BIZ sprite animations (time-based frame progression) ---- */
    for (size_t object_index = 0; object_index < menu_scene_object_count; object_index++) {
        if (!menu_scene_objects[object_index].is_biz_sprite ||
            !menu_scene_objects[object_index].visible ||
            menu_sprite_animation_selector[object_index] == 0)
            continue;
        uint32_t now = tick;
        uint32_t elapsed = now - menu_sprite_animation_start[object_index];
        uint16_t frame = menu_sprite_animation_frame[object_index];
        for (;;) {
            LL_BibSpriteFrame current;
            if (!ll_bib_get_sprite_frame(&game_level.bib,
                    menu_sprite_animation_selector[object_index], frame, &current))
                break;
            if (elapsed < current.duration) break;
            elapsed -= current.duration;
            if (frame >= menu_sprite_animation_last[object_index]) {
                if (menu_sprite_animation_once[object_index]) {
                    frame = menu_sprite_animation_last[object_index];
                    break;
                }
                frame = menu_sprite_animation_first[object_index];
            } else {
                frame++;
            }
        }
        if (frame != menu_sprite_animation_frame[object_index]) {
            LL_BibSpriteFrame next_frame;
            if (ll_bib_get_sprite_frame(&game_level.bib,
                    menu_sprite_animation_selector[object_index], frame, &next_frame)) {
                menu_sprite_animation_frame[object_index] = frame;
                menu_sprite_animation_start[object_index] = now - elapsed;
                menu_scene_objects[object_index].biz_object = next_frame.object_index;
                menu_sprite_offset[object_index][0] = next_frame.offset_x;
                menu_sprite_offset[object_index][1] = next_frame.offset_y;
            }
        }
    }
    for (size_t object_index = 0; object_index < menu_scene_object_count; object_index++) {
        const LL_MenuSceneObject *object = &menu_scene_objects[object_index];
        const LL_Bib3dxModel *model;
        if (!object->visible || object->is_biz_sprite ||
            object->model_index >= game_level.bib.model_count)
            continue;
        model = ll_bib_get_model(&game_level.bib, object->model_index);
        if (model == NULL || model->vertices == NULL) continue;
        if (model->type == 1 && !menu_neutral_attempted[object_index]) {
            menu_neutral_attempted[object_index] = 1;
            LL_BibVertex *neutral = calloc(model->vertex_count, sizeof(*neutral));
            if (neutral != NULL && ll_bib_build_neutral_vertices(&game_level.bib,
                    object->model_index, neutral, model->vertex_count)) {
                menu_neutral_vertices[object_index] = neutral;
                if (menu_animation_selector[object_index] != 0 &&
                    !menu_build_first_pose(object->model_index,
                        menu_animation_selector[object_index], 0, 0, menu_animation_once[object_index], neutral)) {
                    fprintf(stderr, "ERROR: cannot apply first animation pose to %s\n", model->name);
                    ll_bib_build_neutral_vertices(&game_level.bib, object->model_index,
                                                  neutral, model->vertex_count);
                }
            } else {
                free(neutral);
                fprintf(stderr, "ERROR: cannot assemble neutral parts for menu model %s\n", model->name);
            }
        }
        if (menu_animation_selector[object_index] != 0 && menu_neutral_vertices[object_index] != NULL) {
            const LL_BibAnimationTable *animation = ll_bib_get_animation_table(
                &game_level.bib, menu_animation_selector[object_index]);
            uint64_t total = 0;
            if (animation != NULL) {
                for (uint32_t f = menu_animation_first[object_index]; f <= menu_animation_last[object_index]; f++)
                    total += (uint64_t)animation->records[f].sample_count * 32u;
                if (total != 0) {
                    /* FUN_00478360: milliseconds -> 60 Hz steps. Startup
                     * FUN_00404f60 adjusts the stored 38 multiplier to 31. */
                    uint64_t elapsed = menu_animation_elapsed(menu_animation_object_start[object_index],tick);
                    uint32_t blend_ticks=menu_animation_blend_ticks[object_index];
                    int blending=menu_animation_initial[object_index]!=NULL && elapsed<blend_ticks;
                    uint32_t blend_fraction=blending ? (uint32_t)(elapsed*65536u/blend_ticks) : 0;
                    if (!blending && elapsed>=blend_ticks) elapsed-=blend_ticks;
                    if (blending) elapsed=0;
                    if (menu_animation_once[object_index]) {
                        if (elapsed >= total) elapsed = total - 1u;
                    } else elapsed %= total;
                    uint32_t frame = menu_animation_first[object_index];
                    while (frame < menu_animation_last[object_index] &&
                           elapsed >= (uint64_t)animation->records[frame].sample_count * 32u) {
                        elapsed -= (uint64_t)animation->records[frame].sample_count * 32u;
                        frame++;
                    }
                    uint64_t duration = (uint64_t)animation->records[frame].sample_count * 32u;
                    uint32_t fraction = duration != 0 ? (uint32_t)(elapsed * 65536u / duration) : 0;
                    if (menu_animation_once[object_index] && frame == menu_animation_last[object_index]) fraction = 0;
                    uint32_t fraction_key=blending ? blend_fraction|0x80000000u : fraction;
                    if (frame != menu_animation_frame[object_index] || fraction_key != menu_animation_fraction[object_index]) {
                        if (menu_animation_pose_count[object_index]!=animation->record_type) {
                            LL_BibPackedPose *cache=realloc(menu_animation_evaluated[object_index],
                                (size_t)animation->record_type*sizeof(*cache));
                            if (!cache) { fprintf(stderr,"ERROR: cannot allocate evaluated animation pose\n");continue; }
                            menu_animation_evaluated[object_index]=cache;
                            menu_animation_pose_count[object_index]=animation->record_type;
                            menu_animation_pose_valid[object_index]=0;
                        }
                        menu_animation_frame[object_index] = (uint16_t)frame;
                        menu_animation_fraction[object_index] = fraction_key;
                        menu_animation_duration[object_index]=blending ? blend_ticks : (uint32_t)duration;
                        ll_bib_build_neutral_vertices(&game_level.bib, object->model_index,
                            menu_neutral_vertices[object_index], model->vertex_count);
                        menu_animation_pose_valid[object_index]=0;
                        if (!menu_build_animation_pose(object->model_index,
                                menu_animation_selector[object_index], frame, fraction, menu_animation_once[object_index],
                                menu_neutral_vertices[object_index],blending ? menu_animation_initial[object_index] : NULL,
                                blend_fraction,menu_animation_evaluated[object_index]))
                            fprintf(stderr, "ERROR: cannot apply animation frame %u to %s\n", frame, model->name);
                        else menu_animation_pose_valid[object_index]=1;
                    }
                }
            }
        }
        glPushMatrix();
        if (menu_camera.has_reference && menu_object_has_pose[object_index]) {
            const LL_BibScenePose *pose = &menu_object_poses[object_index];
            glTranslated(pose->position[0], pose->position[1], pose->position[2]);
            menu_apply_model_rotation(pose->angles);
        } else {
            glTranslated(model->anchor[0], model->anchor[1], model->anchor[2]);
            GLdouble basis[16] = {0};
            for (unsigned r = 0; r < 3; r++)
                for (unsigned col = 0; col < 3; col++)
                    basis[col * 4u + r] = model->orientation[r * 3u + col] / 4096.0;
            basis[15] = 1;
            glMultMatrixd(basis);
        }
        for (uint32_t group_index = 0; group_index < model->group_count; group_index++) {
            const LL_BibGeometryGroup *group = &model->groups[group_index];
            int quad = (group->type & 1u) != 0;
            if (group->elements == NULL || group->type > 7u) continue;
            for (uint32_t element_index = 0; element_index < group->element_count;
                 element_index++) {
                const LL_BibGeometryElement *element = &group->elements[element_index];
                const LL_MenuMaterial *texture = element->has_material
                    ? menu_material(element->biz_object) : NULL;
                if (texture != NULL && texture->texture != 0) {
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D, texture->texture);
                    glEnable(GL_ALPHA_TEST);
                    glAlphaFunc(GL_GREATER, 0.0f);
                } else glDisable(GL_TEXTURE_2D);
                /* Flat primitive constructors preserve the packed source
                 * color at +8 (FUN_0048edd0/FUN_0048e3d0). */
                uint32_t flat_color = element->attributes;
                glColor3ub((GLubyte)(flat_color & 255u),
                           (GLubyte)((flat_color >> 8) & 255u),
                           (GLubyte)((flat_color >> 16) & 255u));
                if (texture != NULL && texture->texture != 0) glColor3f(1, 1, 1);
                /* FUN_0048c5b0 submits geometry 0,1,3,2 against attributes
                 * in strip order. Keep source geometry on its perimeter. */
                static const uint8_t quad_corners[6] = {0, 1, 3, 3, 1, 2};
                glBegin(GL_TRIANGLES);
                for (uint32_t submitted = 0; submitted < (quad ? 6u : 3u); submitted++) {
                    uint32_t corner = quad ? quad_corners[submitted] : submitted;
                    uint32_t attribute_corner = quad && corner >= 2u ? 5u - corner : corner;
                    uint16_t vertex_index = element->vertex_indices[corner];
                    const LL_BibVertex *vertex;
                    if (vertex_index >= model->vertex_count) continue;
                    vertex = menu_neutral_vertices[object_index] != NULL
                        ? &menu_neutral_vertices[object_index][vertex_index] : &model->vertices[vertex_index];
                    if (group->type >= 4u) {
                        uint32_t color = element->corner_colors[attribute_corner];
                        glColor3ub((GLubyte)(color & 255u),
                                   (GLubyte)((color >> 8) & 255u),
                                   (GLubyte)((color >> 16) & 255u));
                    }
                    if (texture != NULL && texture->texture != 0)
                        glTexCoord2f((float)(element->corner_data[attribute_corner][0] - texture->sprite.texture_x) / texture->width,
                                     (float)(element->corner_data[attribute_corner][1] - texture->sprite.texture_y) / texture->height);
                    glVertex3d(vertex->position[0], vertex->position[1], vertex->position[2]);
                }
                glEnd();
                glDisable(GL_ALPHA_TEST);
            }
        }
        glPopMatrix();
    }
    glDisable(GL_CULL_FACE);
    menu_render_sprite_groups();
    menu_render_screen_sprites();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* Draw menu title and selection overlay */
    glColor3f(1.0f, 0.8f, 0.2f);
    draw_text("LUCKY LUKE", WINDOW_WIDTH / 2 - 120, 120, 3, 1.0f, 0.8f, 0.2f);

    /* Draw menu buttons */
    int button_w = 200;
    int button_h = 48;
    int button_x = WINDOW_WIDTH / 2 - button_w / 2;
    int button_y_start = 260;
    int button_spacing = 72;
    const char *button_labels[2] = {"GAME", "OPTIONS"};

    for (int i = 0; i < 2; i++) {
        int button_y = button_y_start + i * button_spacing;
        int is_selected = (selection == i);

        glColor4f(0.15f, 0.18f, 0.25f, 0.85f);
        if (is_selected) {
            glColor4f(0.25f, 0.35f, 0.55f, 0.95f);
        }
        glBegin(GL_QUADS);
        glVertex2i(button_x, button_y);
        glVertex2i(button_x + button_w, button_y);
        glVertex2i(button_x + button_w, button_y + button_h);
        glVertex2i(button_x, button_y + button_h);
        glEnd();

        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_LINE_LOOP);
        glVertex2i(button_x, button_y);
        glVertex2i(button_x + button_w, button_y);
        glVertex2i(button_x + button_w, button_y + button_h);
        glVertex2i(button_x, button_y + button_h);
        glEnd();

        draw_text(button_labels[i],
                  WINDOW_WIDTH / 2 - (int)strlen(button_labels[i]) * 4 * 2,
                  button_y + button_h / 2 - 8,
                  2, 1.0f, 1.0f, 1.0f);

        if (is_selected) {
            glColor3f(1.0f, 0.8f, 0.0f);
            glBegin(GL_TRIANGLES);
            glVertex2i(button_x - 40, button_y + button_h / 2);
            glVertex2i(button_x - 20, button_y + button_h / 2 - 10);
            glVertex2i(button_x - 20, button_y + button_h / 2 + 10);
            glEnd();
        }
    }

    draw_text("ESC TO QUIT", WINDOW_WIDTH / 2 - 70, 420, 1, 0.6f, 0.6f, 0.6f);
    draw_menu_asset_errors();
}

int main(void)
{
    SDL_Window *window;
    SDL_GLContext context;
    int selection = 0;
    int page = 0;
    int running = 1;

    if (!ll_asset_config_load(&asset_config, "config.ini")) {
        fprintf(stderr, "ERROR: %s\n", asset_config.error);
        menu_asset_errors |= asset_config.mount_error
                                 ? MENU_ASSET_CD_MOUNT_ERROR
                                 : MENU_ASSET_CONFIG_ERROR;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "ERROR: SDL video initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2) != 0 ||
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1) != 0 ||
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1) != 0) {
        fprintf(stderr, "ERROR: cannot configure the OpenGL context: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    window = SDL_CreateWindow(
        "Lucky Luke - Linux port",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        asset_config.video_width,
        asset_config.video_height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == NULL) {
        fprintf(stderr, "ERROR: cannot create the game window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    if (!asset_config.sound_enabled) {
        fprintf(stderr, "INFO: sound disabled by config.ini\n");
    }

    context = SDL_GL_CreateContext(window);
    if (context == NULL) {
        fprintf(stderr, "ERROR: cannot create an OpenGL context: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (SDL_GL_MakeCurrent(window, context) != 0) {
        fprintf(stderr, "ERROR: cannot activate the OpenGL context: %s\n", SDL_GetError());
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (!ll_level_init(&game_level, WINDOW_WIDTH, WINDOW_HEIGHT)) {
        fprintf(stderr, "ERROR: cannot initialize the level module\n");
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    run_intro(window, &running);
    load_menu_bib();
    load_menu_biz();
    menu_audio_init();
    if (ll_level_has_bib(&game_level) && menu_biz_loaded)
        load_and_execute_menu_script();

    SDL_GL_SetSwapInterval(1);
    {
        int width;
        int height;

        SDL_GL_GetDrawableSize(window, &width, &height);
        update_viewport(width, height);
    }
    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_KEYDOWN:
                if (game_state == 2 && event.key.keysym.sym == SDLK_ESCAPE) {
                    game_state = 1;
                    selection = 0;
                    page = 0;
                    ll_gameplay_shutdown();
                    ll_level_set_state(&game_level, 1);
                    load_menu_bib();
                } else if (game_state == 2) {
                    ll_gameplay_key_down(event.key.keysym.sym);
                } else if (game_state == 1 && menu_program_loaded) {
                    /* Original menu input is consumed by SOOL's native
                     * keyboard/action queries during the script update. */
                    break;
                } else if (page != 0 && event.key.keysym.sym == SDLK_ESCAPE) {
                    page = 0;
                } else if (page == 0 && event.key.keysym.sym == SDLK_ESCAPE) {
                    running = 0;
                } else if (page == 0 &&
                           (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w ||
                            event.key.keysym.sym == SDLK_LEFT)) {
                    selection = (selection + 1) % 2;
                } else if (page == 0 &&
                           (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s ||
                            event.key.keysym.sym == SDLK_RIGHT)) {
                    selection = (selection + 1) % 2;
                } else if (page == 0 && (event.key.keysym.sym == SDLK_RETURN ||
                                         event.key.keysym.sym == SDLK_SPACE)) {
                    if (selection == 0) {
                        game_state = 2;
                        if (ll_level_set_state(&game_level, 2)) {
                            load_abilene_assets();
                            if (ll_level_has_cod(&game_level)) {
                                ll_level_spawn_cod_objects(&game_level);
                            }
                        }
                        ll_gameplay_set_level(&game_level);
                        ll_gameplay_init();
                        page = 0;
                        selection = 0;
                    } else if (selection == 1) {
                        page = 2;
                    }
                }
                break;
            case SDL_KEYUP:
                if (game_state == 2) {
                    ll_gameplay_key_up(event.key.keysym.sym);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
            {
                int mouse_x = mouse_to_logical_x(window, event.button.x);
                int mouse_y = mouse_to_logical_y(window, event.button.y);
                if (!menu_program_loaded && page == 0 && game_state == 1 && event.button.button == SDL_BUTTON_LEFT &&
                    mouse_x >= 390 && mouse_x < 620 &&
                    mouse_y >= 200 && mouse_y < 330) {
                    selection = mouse_y >= 264 ? MENU_OPTIONS : MENU_GAME;
                    if (mouse_y < 252 || mouse_y >= 264) {
                        if (selection == 0) {
                            game_state = 2;
                            if (ll_level_set_state(&game_level, 2)) {
                                load_abilene_assets();
                                if (ll_level_has_cod(&game_level)) {
                                    ll_level_spawn_cod_objects(&game_level);
                                }
                            }
                            ll_gameplay_set_level(&game_level);
                            ll_gameplay_init();
                            page = 0;
                            selection = 0;
                        } else if (selection == 1) {
                            page = 2;
                        }
                    }
                }
            }
                break;
            case SDL_MOUSEMOTION:
            {
                int mouse_x = mouse_to_logical_x(window, event.motion.x);
                int mouse_y = mouse_to_logical_y(window, event.motion.y);
                if (!menu_program_loaded && page == 0 && game_state == 1 && mouse_x >= 390 && mouse_x < 620) {
                    if (mouse_y >= 200 && mouse_y < 252) {
                        selection = MENU_GAME;
                    } else if (mouse_y >= 264 && mouse_y < 316) {
                        selection = MENU_OPTIONS;
                    }
                }
            }
                break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                    int width;
                    int height;

                    SDL_GL_GetDrawableSize(window, &width, &height);
                    update_viewport(width, height);
                }
                break;
            default:
                break;
            }
        }

        if (game_state == 2) {
            ll_gameplay_update(1.0f / 60.0f);
            if (!ll_level_render(&game_level)) {
                /* No level assets available: fall back to procedural scene. */
                draw_procedural_background(SDL_GetTicks());
            }
            ll_gameplay_render();
        } else {
            update_menu_scripts(SDL_GetTicks());
            render_menu(selection, page, SDL_GetTicks());
            menu_update_animation_callbacks(SDL_GetTicks());
        }
        SDL_GL_SwapWindow(window);
    }

    for (size_t i = 0; i < menu_material_count; i++)
        if (menu_materials[i].texture != 0) glDeleteTextures(1, &menu_materials[i].texture);
    for (size_t i = 0; i < 128; i++) {
        free(menu_neutral_vertices[i]);free(menu_animation_evaluated[i]);free(menu_animation_initial[i]);
    }
    ll_level_destroy(&game_level);
    free(menu_bib_data);
    for (unsigned patch = 0; patch < 12; patch++)
        ll_pcx_destroy(&menu_page_patches[patch].image);
    for (unsigned page=0;page<32;page++) {
        free(menu_biz_updates[page]);
        free(menu_biz_update_masks[page]);
    }
    menu_audio_shutdown();
    ll_biz_close(&menu_biz);
    free(menu_biz_data);
    ll_sool_program_close(&menu_program);
    free(menu_script_contexts);
    free(menu_script_data);
    free(abilene_cod_data);
    free(abilene_archive_data);
    free(fixgfx_archive_data);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
