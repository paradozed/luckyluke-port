#include "menu_art.h"
#include "pcx.h"

#include <SDL2/SDL_opengl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Read an entire file into a newly allocated buffer.  Returns the buffer and
 * sets *out_size to its byte count, or returns NULL on error.  The caller
 * owns the returned buffer and must free it. */
static unsigned char *read_file(const char *path, size_t *out_size)
{
    FILE *file;
    long file_size;
    unsigned char *data;

    if (path == NULL || out_size == NULL) {
        return NULL;
    }

    file = fopen(path, "rb");
    if (file == NULL) {
        return NULL;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return NULL;
    }
    file_size = ftell(file);
    if (file_size <= 0 || fseek(file, 0, SEEK_SET) != 0) {
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

/* Upload a decoded PCX image to an OpenGL texture.  Returns 1 on success. */
static int upload_pcx_texture(const LL_PcxImage *image, unsigned int *out_id,
                              int *out_width, int *out_height)
{
    unsigned int texture_id;

    if (image == NULL || image->rgba_pixels == NULL || out_id == NULL ||
        out_width == NULL || out_height == NULL) {
        return 0;
    }

    glGenTextures(1, &texture_id);
    if (texture_id == 0) {
        return 0;
    }

    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image->width, image->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image->rgba_pixels);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (glGetError() != GL_NO_ERROR) {
        glDeleteTextures(1, &texture_id);
        return 0;
    }

    *out_id = texture_id;
    *out_width = image->width;
    *out_height = image->height;
    return 1;
}

int ll_menu_art_load(const char *path, LL_MenuTexture *tex)
{
    unsigned char *file_data;
    size_t file_size;
    LL_PcxImage image;

    if (tex == NULL || path == NULL) {
        return 0;
    }

    memset(tex, 0, sizeof(*tex));

    file_data = read_file(path, &file_size);
    if (file_data == NULL) {
        return 0;
    }

    if (!ll_pcx_decode(file_data, file_size, &image)) {
        free(file_data);
        return 0;
    }
    free(file_data);

    if (!upload_pcx_texture(&image, &tex->texture, &tex->width, &tex->height)) {
        ll_pcx_destroy(&image);
        return 0;
    }

    ll_pcx_destroy(&image);
    tex->loaded = 1;
    return 1;
}

int ll_menu_art_load_from_memory(const unsigned char *pcx_data, size_t pcx_size,
                                 LL_MenuTexture *tex)
{
    LL_PcxImage image;

    if (tex == NULL || pcx_data == NULL) {
        return 0;
    }

    memset(tex, 0, sizeof(*tex));

    if (!ll_pcx_decode(pcx_data, pcx_size, &image)) {
        return 0;
    }

    if (!upload_pcx_texture(&image, &tex->texture, &tex->width, &tex->height)) {
        ll_pcx_destroy(&image);
        return 0;
    }

    ll_pcx_destroy(&image);
    tex->loaded = 1;
    return 1;
}

int ll_menu_art_load_from_rgba(const unsigned char *rgba_data,
                               int width, int height,
                               LL_MenuTexture *tex)
{
    unsigned int texture_id;

    if (tex == NULL || rgba_data == NULL || width <= 0 || height <= 0) {
        return 0;
    }

    memset(tex, 0, sizeof(*tex));

    glGenTextures(1, &texture_id);
    if (texture_id == 0) {
        return 0;
    }

    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, rgba_data);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (glGetError() != GL_NO_ERROR) {
        glDeleteTextures(1, &texture_id);
        return 0;
    }

    tex->texture = texture_id;
    tex->width = width;
    tex->height = height;
    tex->loaded = 1;
    return 1;
}

void ll_menu_art_draw(const LL_MenuTexture *tex, float x, float y,
                      float width, float height)
{
    if (tex == NULL || !tex->loaded || tex->texture == 0) {
        return;
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex->texture);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(x, y);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(x + width, y);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(x + width, y + height);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(x, y + height);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void ll_menu_art_destroy(LL_MenuTexture *tex)
{
    if (tex == NULL) {
        return;
    }
    if (tex->loaded && tex->texture != 0) {
        glDeleteTextures(1, &tex->texture);
    }
    memset(tex, 0, sizeof(*tex));
}
