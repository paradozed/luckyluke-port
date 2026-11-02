#include "pcx.h"
#include "renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *file;
    long file_size;
    unsigned char *data;
    LL_PcxImage image;
    LL_Renderer renderer = {0};
    SDL_Window *window;
    SDL_GLContext context;
    unsigned char sample[4];
    static const unsigned int samples[][2] = {
        {4, 4}, {127, 63}, {255, 127}, {507, 251}
    };
    size_t index;

    if (argc != 2) {
        fprintf(stderr, "usage: pcx-test image.pcx\n");
        return 2;
    }

    file = fopen(argv[1], "rb");
    if (file == NULL || fseek(file, 0, SEEK_END) != 0 ||
        (file_size = ftell(file)) <= 0 || fseek(file, 0, SEEK_SET) != 0) {
        fprintf(stderr, "could not read PCX file\n");
        if (file != NULL) {
            fclose(file);
        }
        return 1;
    }

    data = (unsigned char *)malloc((size_t)file_size);
    if (data == NULL || fread(data, 1, (size_t)file_size, file) != (size_t)file_size) {
        fprintf(stderr, "could not load PCX data\n");
        free(data);
        fclose(file);
        return 1;
    }
    fclose(file);

    if (!ll_pcx_decode(data, (size_t)file_size, &image)) {
        fprintf(stderr, "PCX decode failed\n");
        free(data);
        return 1;
    }
    free(data);

    if (image.width != 512 || image.height != 256) {
        fprintf(stderr, "unexpected splash dimensions: %dx%d\n", image.width, image.height);
        ll_pcx_destroy(&image);
        return 1;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL init failed: %s\n", SDL_GetError());
        ll_pcx_destroy(&image);
        return 1;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 0);
    window = SDL_CreateWindow("PCX splash test", 0, 0, 640, 480,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN);
    if (window == NULL) {
        fprintf(stderr, "SDL window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        ll_pcx_destroy(&image);
        return 1;
    }
    context = SDL_GL_CreateContext(window);
    if (context == NULL) {
        fprintf(stderr, "OpenGL context creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        ll_pcx_destroy(&image);
        return 1;
    }
    glViewport(0, 0, 640, 480);
    if (!ll_renderer_init(&renderer, image.width, image.height) ||
        !ll_renderer_present_fit(&renderer, image.rgba_pixels,
                                 (size_t)image.width * (size_t)image.height * 4,
                                 (size_t)image.width * 4, LL_PIXEL_RGBA8888, NULL)) {
        fprintf(stderr, "OpenGL splash presentation failed\n");
        ll_renderer_destroy(&renderer);
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        ll_pcx_destroy(&image);
        return 1;
    }

    glReadBuffer(GL_BACK);
    for (index = 0; index < sizeof(samples) / sizeof(samples[0]); index++) {
        size_t source_offset = ((size_t)samples[index][1] * (size_t)image.width +
                                samples[index][0]) * 4;
        GLint window_x = (GLint)(((float)samples[index][0] + 0.5f) * 1.25f);
        GLint image_y = (GLint)(((float)samples[index][1] + 0.5f) * 1.25f);
        GLint window_y = 480 - (80 + image_y) - 1;
        glReadPixels(window_x, window_y,
                     1, 1, GL_RGBA, GL_UNSIGNED_BYTE, sample);
        if (glGetError() != GL_NO_ERROR ||
            abs((int)sample[0] - image.rgba_pixels[source_offset]) > 2 ||
            abs((int)sample[1] - image.rgba_pixels[source_offset + 1]) > 2 ||
            abs((int)sample[2] - image.rgba_pixels[source_offset + 2]) > 2 || sample[3] != 255) {
                    fprintf(stderr, "splash framebuffer mismatch at source %u,%u: got %u,%u,%u expected %u,%u,%u\n",
                        samples[index][0], samples[index][1], sample[0], sample[1], sample[2],
                        image.rgba_pixels[source_offset], image.rgba_pixels[source_offset + 1],
                        image.rgba_pixels[source_offset + 2]);
            ll_renderer_destroy(&renderer);
            SDL_GL_DeleteContext(context);
            SDL_DestroyWindow(window);
            SDL_Quit();
            ll_pcx_destroy(&image);
            return 1;
        }
    }

    ll_renderer_destroy(&renderer);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("PCX decode passed: %dx%d RGB image\n", image.width, image.height);
    ll_pcx_destroy(&image);
    return 0;
}
