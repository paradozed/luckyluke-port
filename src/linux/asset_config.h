#ifndef LL_ASSET_CONFIG_H
#define LL_ASSET_CONFIG_H

#include <stddef.h>

#define LL_ASSET_PATH_CAP 1024
#define LL_ASSET_ERROR_CAP 192

typedef struct {
    char cd_mount[LL_ASSET_PATH_CAP];
    char error[LL_ASSET_ERROR_CAP];
    int configured;
    int mount_valid;
    int mount_error;
    int skip_intro;
    int sound_enabled;
    int video_width;
    int video_height;
    char language_code;
} LL_AssetConfig;

/* Load cd_mount from an INI-style config file and validate that it is a
 * readable directory.  On failure, cd_mount falls back to "." so the
 * program can still run its local visual fallback. */
int ll_asset_config_load(LL_AssetConfig *config, const char *config_path);

/* Join a CD-relative asset path to the configured mount point. */
int ll_asset_config_path(const LL_AssetConfig *config, const char *relative_path,
                         char *out_path, size_t out_capacity);

#endif
