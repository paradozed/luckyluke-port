#include "renderer.h"

#include <SDL2/SDL_opengl.h>

#include <limits.h>
#include <stdlib.h>
#include <string.h>

static size_t bytes_per_pixel(LL_PixelFormat format)
{
    switch (format) {
    case LL_PIXEL_INDEX8:
        return 1;
    case LL_PIXEL_RGB555:
    case LL_PIXEL_RGB565:
        return 2;
    case LL_PIXEL_RGBA8888:
        return 4;
    default:
        return 0;
    }
}

int ll_renderer_init(LL_Renderer *renderer, int width, int height)
{
    GLint max_texture_size = 0;
    size_t pixel_count;

    if (renderer == NULL || width <= 0 || height <= 0 ||
        (size_t)width > SIZE_MAX / (size_t)height) {
        return 0;
    }

    memset(renderer, 0, sizeof(*renderer));
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_texture_size);
    if (width > max_texture_size || height > max_texture_size) {
        return 0;
    }

    pixel_count = (size_t)width * (size_t)height;
    if (pixel_count > SIZE_MAX / 4) {
        return 0;
    }

    renderer->rgba_pixels = (unsigned char *)malloc(pixel_count * 4);
    if (renderer->rgba_pixels == NULL) {
        return 0;
    }

    renderer->width = width;
    renderer->height = height;

    glGenTextures(1, &renderer->texture);
    if (renderer->texture == 0) {
        ll_renderer_destroy(renderer);
        return 0;
    }

    glBindTexture(GL_TEXTURE_2D, renderer->texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (glGetError() != GL_NO_ERROR) {
        ll_renderer_destroy(renderer);
        return 0;
    }
    return 1;
}

void ll_renderer_destroy(LL_Renderer *renderer)
{
    if (renderer == NULL) {
        return;
    }
    if (renderer->texture != 0) {
        glDeleteTextures(1, &renderer->texture);
    }
    free(renderer->rgba_pixels);
    memset(renderer, 0, sizeof(*renderer));
}

static void convert_row(unsigned char *destination,
                        const unsigned char *source,
                        int width,
                        LL_PixelFormat format,
                        const unsigned char palette_rgba[256][4])
{
    int x;

    if (format == LL_PIXEL_RGBA8888) {
        memcpy(destination, source, (size_t)width * 4);
        return;
    }

    for (x = 0; x < width; x++) {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha = 255;

        if (format == LL_PIXEL_INDEX8) {
            const unsigned char *color = palette_rgba[source[x]];
            red = color[0];
            green = color[1];
            blue = color[2];
            alpha = color[3];
        } else {
            unsigned int value = (unsigned int)source[x * 2] |
                                 ((unsigned int)source[x * 2 + 1] << 8);
            unsigned int red_bits;
            unsigned int green_bits;
            unsigned int blue_bits;

            if (format == LL_PIXEL_RGB555) {
                red_bits = (value >> 10) & 0x1f;
                green_bits = (value >> 5) & 0x1f;
                blue_bits = value & 0x1f;
            } else {
                red_bits = (value >> 11) & 0x1f;
                green_bits = (value >> 5) & 0x3f;
                blue_bits = value & 0x1f;
            }
            red = (unsigned char)((red_bits * 255 + 15) / 31);
            green = format == LL_PIXEL_RGB555
                ? (unsigned char)((green_bits * 255 + 15) / 31)
                : (unsigned char)((green_bits * 255 + 31) / 63);
            blue = (unsigned char)((blue_bits * 255 + 15) / 31);
        }

        destination[x * 4] = red;
        destination[x * 4 + 1] = green;
        destination[x * 4 + 2] = blue;
        destination[x * 4 + 3] = alpha;
    }
}

static int renderer_present(LL_Renderer *renderer,
                            const void *pixels,
                            size_t pixels_size,
                            size_t pitch,
                            LL_PixelFormat format,
                            const unsigned char palette_rgba[256][4],
                            int preserve_aspect)
{
    const unsigned char *source = (const unsigned char *)pixels;
    size_t pixel_size = bytes_per_pixel(format);
    size_t row_size;
    size_t required_size;
    int y;
    GLint viewport[4];
    float destination_width;
    float destination_height;
    float destination_x;
    float destination_y;

    if (renderer == NULL || renderer->texture == 0 || source == NULL ||
        pixel_size == 0 || (format == LL_PIXEL_INDEX8 && palette_rgba == NULL)) {
        return 0;
    }
    if ((size_t)renderer->width > SIZE_MAX / pixel_size) {
        return 0;
    }
    row_size = (size_t)renderer->width * pixel_size;
    if (pitch < row_size || (size_t)(renderer->height - 1) >
        (SIZE_MAX - row_size) / pitch) {
        return 0;
    }
    required_size = (size_t)(renderer->height - 1) * pitch + row_size;
    if (pixels_size < required_size) {
        return 0;
    }

    for (y = 0; y < renderer->height; y++) {
        convert_row(renderer->rgba_pixels + (size_t)y * (size_t)renderer->width * 4,
                    source + (size_t)y * pitch,
                    renderer->width,
                    format,
                    palette_rgba);
    }

    glGetIntegerv(GL_VIEWPORT, viewport);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, renderer->texture);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0,
                    renderer->width, renderer->height,
                    GL_RGBA, GL_UNSIGNED_BYTE, renderer->rgba_pixels);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, viewport[2], viewport[3], 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    destination_width = (float)viewport[2];
    destination_height = (float)viewport[3];
    if (preserve_aspect) {
        float scale_x = destination_width / (float)renderer->width;
        float scale_y = destination_height / (float)renderer->height;
        float scale = scale_x < scale_y ? scale_x : scale_y;

        destination_width = (float)renderer->width * scale;
        destination_height = (float)renderer->height * scale;
    }
    destination_x = ((float)viewport[2] - destination_width) * 0.5f;
    destination_y = ((float)viewport[3] - destination_height) * 0.5f;

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(destination_x, destination_y);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(destination_x + destination_width, destination_y);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(destination_x + destination_width,
                                           destination_y + destination_height);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(destination_x, destination_y + destination_height);
    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    return glGetError() == GL_NO_ERROR;
}

int ll_renderer_present(LL_Renderer *renderer,
                        const void *pixels,
                        size_t pixels_size,
                        size_t pitch,
                        LL_PixelFormat format,
                        const unsigned char palette_rgba[256][4])
{
    return renderer_present(renderer, pixels, pixels_size, pitch, format,
                            palette_rgba, 0);
}

int ll_renderer_present_fit(LL_Renderer *renderer,
                            const void *pixels,
                            size_t pixels_size,
                            size_t pitch,
                            LL_PixelFormat format,
                            const unsigned char palette_rgba[256][4])
{
    return renderer_present(renderer, pixels, pixels_size, pitch, format,
                            palette_rgba, 1);
}
