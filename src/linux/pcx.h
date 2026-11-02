#ifndef LL_PCX_H
#define LL_PCX_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t manufacturer;
    uint8_t version;
    uint8_t encoding;
    uint8_t bits_per_pixel;
    uint16_t xmin, ymin, xmax, ymax;
    uint16_t horizontal_resolution, vertical_resolution;
    unsigned char ega_palette[48];
    uint8_t reserved;
    uint8_t plane_count;
    uint16_t bytes_per_line;
    uint16_t palette_info;
    uint16_t screen_width, screen_height;
    uint32_t width, height;
} LL_PcxHeader;

typedef struct {
    int width;
    int height;
    unsigned char *rgba_pixels;
    LL_PcxHeader header;
    char error[160];
} LL_PcxImage;

/* Parse and validate the fixed 128-byte PCX header, including image bounds,
 * encoding mode, plane layout, row stride, and palette metadata. */
int ll_pcx_parse_header(const unsigned char *data, size_t data_size,
                        LL_PcxHeader *header, char *error, size_t error_size);
/* Decode raw or RLE PCX data. Supports indexed 1/2/4/8-bit images and planar
 * 24-bit RGB; unsupported formats and malformed streams set image->error. */
int ll_pcx_decode(const unsigned char *data, size_t data_size, LL_PcxImage *image);
void ll_pcx_destroy(LL_PcxImage *image);

/* Extract the 256-entry RGB palette from a PCX file.
 *
 * For 8-bit indexed PCX files, the palette is stored at the end of the file
 * as a 0x0C marker byte followed by 768 bytes of RGB palette data.
 * palette_out must point to a buffer of at least 768 bytes.
 * Returns the number of palette entries (0-256) on success, 0 on error. */
int ll_pcx_extract_palette(const unsigned char *data, size_t data_size,
                           unsigned char *palette_out);

#endif
