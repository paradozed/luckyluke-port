#include "asset_config.h"
#include <dirent.h>

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

static char *trim(char *text)
{
    char *end;
    while (isspace((unsigned char)*text)) text++;
    end = text + strlen(text);
    while (end > text && isspace((unsigned char)end[-1])) *--end = '\0';
    return text;
}

static int string_equal_ci(const char *left, const char *right)
{
    while (*left != '\0' && *right != '\0') {
        if (tolower((unsigned char)*left) != tolower((unsigned char)*right)) {
            return 0;
        }
        left++;
        right++;
    }
    return *left == '\0' && *right == '\0';
}

int ll_asset_config_load(LL_AssetConfig *config, const char *config_path)
{
    FILE *file;
    char line[LL_ASSET_PATH_CAP + 32];
    int found_mount = 0;
    struct stat info;

    if (config == NULL || config_path == NULL) return 0;
    memset(config, 0, sizeof(*config));
    memcpy(config->cd_mount, ".", 2);
    /* Match Game.run's startup path unless the user opts out explicitly. */
    config->skip_intro = 0;
    config->sound_enabled = 1;
    config->video_width = 640;
    config->video_height = 480;
    config->language_code = 'e';

    file = fopen(config_path, "r");
    if (file == NULL) {
        snprintf(config->error, sizeof(config->error),
                 "cannot open config file '%s'", config_path);
        return 0;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *entry = trim(line);
        char *equals;
        char *value;
        size_t length;

        if (*entry == '\0' || *entry == '#' || *entry == ';' || *entry == '[') {
            continue;
        }
        equals = strchr(entry, '=');
        if (equals == NULL) continue;
        *equals = '\0';
        entry = trim(entry);
        value = trim(equals + 1);
        length = strlen(value);
        if (length >= 2 && ((value[0] == '"' && value[length - 1] == '"') ||
                            (value[0] == '\'' && value[length - 1] == '\''))) {
            value[length - 1] = '\0';
            value++;
        }
        value = trim(value);
        if (strcmp(entry, "cd_mount") == 0) {
            if (*value == '\0' || strlen(value) >= sizeof(config->cd_mount)) {
                fclose(file);
                snprintf(config->error, sizeof(config->error),
                         "cd_mount is empty or too long in '%s'", config_path);
                return 0;
            }
            strcpy(config->cd_mount, value);
            found_mount = 1;
        } else if (strcmp(entry, "skip_intro") == 0) {
            if (string_equal_ci(value, "true") || string_equal_ci(value, "yes") ||
                string_equal_ci(value, "on") || strcmp(value, "1") == 0) {
                config->skip_intro = 1;
            } else if (string_equal_ci(value, "false") || string_equal_ci(value, "no") ||
                       string_equal_ci(value, "off") || strcmp(value, "0") == 0) {
                config->skip_intro = 0;
            } else {
                fclose(file);
                config->configured = found_mount;
                snprintf(config->error, sizeof(config->error),
                         "skip_intro must be true or false in '%s'", config_path);
                return 0;
            }
        } else if (strcmp(entry, "sound") == 0) {
            if (string_equal_ci(value, "true") || string_equal_ci(value, "yes") ||
                string_equal_ci(value, "on") || strcmp(value, "1") == 0) {
                config->sound_enabled = 1;
            } else if (string_equal_ci(value, "false") || string_equal_ci(value, "no") ||
                       string_equal_ci(value, "off") || strcmp(value, "0") == 0) {
                config->sound_enabled = 0;
            } else {
                fclose(file);
                config->configured = found_mount;
                snprintf(config->error, sizeof(config->error),
                         "sound must be true or false in '%s'", config_path);
                return 0;
            }
        } else if (strcmp(entry, "resolution") == 0) {
            char *separator = strchr(value, 'x');
            char *end;
            long width, height;
            if (separator == NULL) separator = strchr(value, 'X');
            if (separator == NULL || separator == value || separator[1] == '\0') {
                fclose(file);
                config->configured = found_mount;
                snprintf(config->error, sizeof(config->error),
                         "resolution must be WIDTHxHEIGHT (4:3) in '%s'", config_path);
                return 0;
            }
            *separator = '\0';
            width = strtol(value, &end, 10);
            if (*end != '\0' || width < 640 || width > 3840) width = 0;
            height = strtol(separator + 1, &end, 10);
            if (*end != '\0' || height < 480 || height > 2880) height = 0;
            if (width == 0 || height == 0 || width * 3 != height * 4) {
                fclose(file);
                config->configured = found_mount;
                snprintf(config->error, sizeof(config->error),
                         "resolution must be a valid 4:3 size from 640x480 to 3840x2880 in '%s'",
                         config_path);
                return 0;
            }
            config->video_width = (int)width;
            config->video_height = (int)height;
        } else if (strcmp(entry, "language") == 0) {
            char language = (char)tolower((unsigned char)value[0]);
            if (strlen(value) != 1 ||
                strchr("efdsiub", language) == NULL) {
                fclose(file);
                config->configured = found_mount;
                snprintf(config->error, sizeof(config->error),
                         "language must be one of e, f, d, s, i, u, or b in '%s'",
                         config_path);
                return 0;
            }
            config->language_code = language;
        }
    }
    fclose(file);

    if (!found_mount) {
        snprintf(config->error, sizeof(config->error),
                 "cd_mount is missing from '%s'", config_path);
        return 0;
    }
    config->configured = 1;
    if (stat(config->cd_mount, &info) != 0 || !S_ISDIR(info.st_mode)) {
        config->mount_error = 1;
        snprintf(config->error, sizeof(config->error),
                 "CD mount '%.120s' is not an accessible directory",
                 config->cd_mount);
        return 0;
    }
    config->mount_valid = 1;
    return 1;
}

int ll_asset_config_path(const LL_AssetConfig *config, const char *relative_path,
                         char *out_path, size_t out_capacity)
{
    size_t root_length;
    int written;

    if (config == NULL || relative_path == NULL || out_path == NULL ||
        out_capacity == 0 || relative_path[0] == '/') return 0;
    root_length = strlen(config->cd_mount);
    written = snprintf(out_path, out_capacity, "%s%s%s", config->cd_mount,
                       root_length > 0 && config->cd_mount[root_length - 1] == '/' ? "" : "/",
                       relative_path);
    if (written < 0 || (size_t)written >= out_capacity) return 0;
    struct stat info;
    if (stat(out_path,&info)==0) return 1;
    /* CD/Windows names are case-insensitive; ISO extraction preserves their
     * original mixed case. Resolve each component without changing assets. */
    char requested[LL_ASSET_PATH_CAP * 2];
    if (strlen(relative_path)>=sizeof(requested)) return 0;
    strcpy(requested,relative_path);
    if (root_length>=out_capacity) return 0;
    memcpy(out_path,config->cd_mount,root_length+1u);
    char *component=requested;
    while (*component) {
        char *separator=strchr(component,'/');
        if (separator) *separator='\0';
        if (*component=='\0' || strcmp(component,".")==0 || strcmp(component,"..")==0) return 0;
        DIR *directory=opendir(out_path);
        if (directory==NULL) return 0;
        char matched[512]={0};
        int matches=0;
        struct dirent *entry;
        while ((entry=readdir(directory))!=NULL) {
            if (!string_equal_ci(component,entry->d_name)) continue;
            if (strlen(entry->d_name)>=sizeof(matched)) { closedir(directory); return 0; }
            strcpy(matched,entry->d_name);
            matches++;
            if (strcmp(component,entry->d_name)==0) { matches=1; break; }
        }
        closedir(directory);
        if (matches!=1) return 0;
        size_t length=strlen(out_path), name_length=strlen(matched);
        int slash=length>0 && out_path[length-1]!='/';
        if (length+(size_t)slash+name_length>=out_capacity) return 0;
        if (slash) out_path[length++]='/';
        memcpy(out_path+length,matched,name_length+1u);
        if (!separator) break;
        component=separator+1;
    }
    return 1;
}
