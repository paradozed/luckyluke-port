#include "pcx.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PCX_MAX_PIXELS (64u * 1024u * 1024u)

static uint16_t read_u16le(const unsigned char *data)
{
    return (uint16_t)((unsigned int)data[0] | ((unsigned int)data[1] << 8));
}

static int pcx_error(char *out, size_t capacity, const char *message)
{
    if (out != NULL && capacity != 0) snprintf(out, capacity, "%s", message);
    return 0;
}

int ll_pcx_parse_header(const unsigned char *data, size_t data_size,
                        LL_PcxHeader *header, char *error, size_t error_size)
{
    LL_PcxHeader parsed;
    uint32_t minimum_line;
    if (error != NULL && error_size != 0) error[0] = '\0';
    if (header == NULL) return pcx_error(error, error_size, "PCX header output is null");
    memset(header, 0, sizeof(*header));
    if (data == NULL || data_size < 128)
        return pcx_error(error, error_size, "PCX file is shorter than its 128-byte header");
    memset(&parsed, 0, sizeof(parsed));
    parsed.manufacturer = data[0]; parsed.version = data[1];
    parsed.encoding = data[2]; parsed.bits_per_pixel = data[3];
    parsed.xmin = read_u16le(data + 4); parsed.ymin = read_u16le(data + 6);
    parsed.xmax = read_u16le(data + 8); parsed.ymax = read_u16le(data + 10);
    parsed.horizontal_resolution = read_u16le(data + 12);
    parsed.vertical_resolution = read_u16le(data + 14);
    memcpy(parsed.ega_palette, data + 16, sizeof(parsed.ega_palette));
    parsed.reserved = data[64]; parsed.plane_count = data[65];
    parsed.bytes_per_line = read_u16le(data + 66);
    parsed.palette_info = read_u16le(data + 68);
    parsed.screen_width = read_u16le(data + 70);
    parsed.screen_height = read_u16le(data + 72);
    if (parsed.manufacturer != 0x0a)
        return pcx_error(error, error_size, "PCX manufacturer signature is invalid");
    if (parsed.version > 5)
        return pcx_error(error, error_size, "PCX version is unsupported");
    if (parsed.encoding > 1)
        return pcx_error(error, error_size, "PCX encoding must be raw (0) or RLE (1)");
    if (parsed.bits_per_pixel == 0 || parsed.bits_per_pixel > 8 ||
        (parsed.bits_per_pixel & (parsed.bits_per_pixel - 1u)) != 0)
        return pcx_error(error, error_size, "PCX bits-per-pixel must be 1, 2, 4, or 8");
    if (parsed.xmax < parsed.xmin || parsed.ymax < parsed.ymin)
        return pcx_error(error, error_size, "PCX image bounds are reversed");
    if (parsed.plane_count == 0 || parsed.plane_count > 4 || parsed.bytes_per_line == 0)
        return pcx_error(error, error_size, "PCX plane count must be 1..4 and bytes-per-line nonzero");
    parsed.width = (uint32_t)parsed.xmax - parsed.xmin + 1u;
    parsed.height = (uint32_t)parsed.ymax - parsed.ymin + 1u;
    minimum_line = (parsed.width * parsed.bits_per_pixel + 7u) / 8u;
    if (parsed.bytes_per_line < minimum_line)
        return pcx_error(error, error_size, "PCX bytes-per-line is smaller than the visible row");
    *header = parsed;
    return 1;
}

void ll_pcx_destroy(LL_PcxImage *image)
{
    if (image == NULL) {
        return;
    }
    free(image->rgba_pixels);
    image->rgba_pixels = NULL;
    image->width = 0;
    image->height = 0;
    memset(&image->header, 0, sizeof(image->header));
}

int ll_pcx_decode(const unsigned char *data, size_t data_size, LL_PcxImage *image)
{
    size_t pixel_count;
    size_t decoded_size;
    size_t source_offset = 128;
    size_t source_limit = data_size;
    size_t destination_offset = 0;
    unsigned int bytes_per_plane;
    unsigned int plane_count;
    unsigned int x;
    unsigned int y;
    unsigned char *planes = NULL;
    unsigned char *rgba = NULL;
    unsigned char palette[768];
    size_t palette_offset = 0;
    LL_PcxHeader header;

    if (image == NULL) {
        return 0;
    }
    memset(image, 0, sizeof(*image));
    if (!ll_pcx_parse_header(data, data_size, &header, image->error,
                             sizeof(image->error))) {
        return 0;
    }
    if (!((header.bits_per_pixel == 8 &&
           (header.plane_count == 1 || header.plane_count == 3)) ||
          (header.bits_per_pixel <= 4 &&
           (uint32_t)header.bits_per_pixel * header.plane_count <= 4))) {
        pcx_error(image->error, sizeof(image->error), "PCX pixel format is unsupported");
        return 0;
    }
    image->header = header;
    image->width = (int)header.width;
    image->height = (int)header.height;
    plane_count = header.plane_count;
    bytes_per_plane = header.bytes_per_line;
    if (header.width > INT32_MAX || header.height > INT32_MAX ||
        (size_t)image->width > SIZE_MAX / (size_t)image->height) {
        pcx_error(image->error, sizeof(image->error), "PCX image dimensions overflow memory limits");
        return 0;
    }

    pixel_count = (size_t)image->width * (size_t)image->height;
    if (pixel_count > PCX_MAX_PIXELS) {
        image->width = image->height = 0;
        pcx_error(image->error, sizeof(image->error),
                  "PCX dimensions exceed the 64-megapixel decode limit");
        return 0;
    }
    if (header.bits_per_pixel == 8 && plane_count == 1) {
        if (data_size < 769 || data[data_size - 769] != 0x0c) {
            pcx_error(image->error, sizeof(image->error),
                      "8-bit indexed PCX is missing its 256-color palette marker");
            image->width = image->height = 0;
            return 0;
        }
        palette_offset = data_size - 768;
        source_limit = data_size - 769;
        memcpy(palette, data + palette_offset, sizeof(palette));
    } else if (header.bits_per_pixel * plane_count <= 4) {
        memcpy(palette, header.ega_palette, sizeof(header.ega_palette));
    }
    if ((size_t)bytes_per_plane > SIZE_MAX / plane_count ||
        (size_t)bytes_per_plane * plane_count > SIZE_MAX / (size_t)image->height) {
        image->width = image->height = 0;
        pcx_error(image->error, sizeof(image->error), "PCX decoded image size overflows memory limits");
        return 0;
    }
    decoded_size = (size_t)bytes_per_plane * plane_count * (size_t)image->height;
    planes = (unsigned char *)malloc(decoded_size);
    if (planes == NULL || pixel_count > SIZE_MAX / 4) {
        free(planes);
        image->width = image->height = 0;
        pcx_error(image->error, sizeof(image->error), "cannot allocate PCX scanline buffer");
        return 0;
    }

    while (destination_offset < decoded_size) {
        unsigned char value;
        size_t run_length = 1;

        if (source_offset >= source_limit) {
            free(planes);
            image->width = image->height = 0;
            pcx_error(image->error, sizeof(image->error), "PCX pixel stream is truncated");
            return 0;
        }
        value = data[source_offset++];
        if (header.encoding == 1 && (value & 0xc0) == 0xc0) {
            run_length = value & 0x3f;
            if (run_length == 0 || source_offset >= source_limit) {
                free(planes);
                image->width = image->height = 0;
                pcx_error(image->error, sizeof(image->error), "PCX RLE run is truncated or empty");
                return 0;
            }
            value = data[source_offset++];
        }
        if (run_length > decoded_size - destination_offset) {
            free(planes);
            image->width = image->height = 0;
            pcx_error(image->error, sizeof(image->error), "PCX RLE run exceeds decoded image size");
            return 0;
        }
        memset(planes + destination_offset, value, run_length);
        destination_offset += run_length;
    }

    /* Convert the decoded planar/indexed rows to RGBA pixels. */
    rgba = (unsigned char *)malloc(pixel_count * 4);
    if (rgba == NULL) {
        free(planes);
        image->width = image->height = 0;
        pcx_error(image->error, sizeof(image->error), "cannot allocate PCX RGBA output");
        return 0;
    }

    for (y = 0; y < (unsigned int)image->height; y++) {
        for (x = 0; x < (unsigned int)image->width; x++) {
            size_t pixel_offset = ((size_t)y * (size_t)image->width + x) * 4;
            size_t row_offset = (size_t)y * bytes_per_plane * plane_count;
            unsigned char red, green, blue;
            if (header.bits_per_pixel == 8 && plane_count == 3) {
                red = planes[row_offset + x];
                green = planes[row_offset + bytes_per_plane + x];
                blue = planes[row_offset + 2 * bytes_per_plane + x];
            } else {
                unsigned int color_index = 0;
                unsigned int bits = header.bits_per_pixel;
                unsigned int mask = (1u << bits) - 1u;
                unsigned int bit_index = x * bits;
                unsigned int byte_index = bit_index / 8u;
                unsigned int shift = 8u - bits - (bit_index & 7u);
                for (unsigned int plane = 0; plane < plane_count; plane++) {
                    unsigned int sample =
                        (planes[row_offset + (size_t)plane * bytes_per_plane + byte_index] >> shift) & mask;
                    color_index |= sample << (plane * bits);
                }
                red = palette[color_index * 3];
                green = palette[color_index * 3 + 1];
                blue = palette[color_index * 3 + 2];
            }
            /* FUN_00431fe0 quantizes decoded channels to five bits before
             * FUN_004318a0 packs them into the game's 16-bit surface. Expand
             * those five-bit values back to RGBA for the Linux texture so
             * colors match the original surface precision. */
            rgba[pixel_offset] = (unsigned char)(((red >> 3) * 255 + 15) / 31);
            rgba[pixel_offset + 1] = (unsigned char)(((green >> 3) * 255 + 15) / 31);
            rgba[pixel_offset + 2] = (unsigned char)(((blue >> 3) * 255 + 15) / 31);
            /* FUN_004318a0 sets the high bit only when RGB is nonzero. */
            rgba[pixel_offset + 3] = (red | green | blue) ? 255 : 0;
        }
    }

    free(planes);
    image->rgba_pixels = rgba;
    return 1;
}

int ll_pcx_extract_palette(const unsigned char *data, size_t data_size,
                           unsigned char *palette_out)
{
    LL_PcxHeader header;
    size_t palette_offset;
    if (palette_out == NULL || !ll_pcx_parse_header(data, data_size,
                                                     &header, NULL, 0) ||
        header.bits_per_pixel != 8 || header.plane_count != 1 ||
        data_size < 769 || data[data_size - 769] != 0x0c) return 0;
    palette_offset = data_size - 768;
    memcpy(palette_out, data + palette_offset, 768);
    return 256;
}
