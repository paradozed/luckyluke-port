#include "kxp.h"

#include <string.h>

/*
 * KXP archive format (reverse-engineered from the game's archives):
 *
 *   Offset  Size  Field
 *   0       3     Signature "KXP"
 *   3       1     Version (must be 1)
 *   4       1     Header byte (not used by the reader)
 *   5       0x20  Encrypted-archive discriminator; nonzero first byte means encrypted
 *   0x25    4     Index offset (little-endian u32)
 *
 *   Index block (at index_offset):
 *   0       1     Signature 'I'
 *   1       2     Entry count (little-endian u16)
 *   3       ...   Entry records, each 17 bytes:
 *       0       13  Member name (null-padded, uppercase ASCII)
 *       13      4   Payload offset (little-endian u32)
 *
 *   Member payload (at payload_offset):
 *   0       1     Member marker
 *   1       4     Opaque member metadata
 *   5       4     Payload size (little-endian u32)
 *   9       ...   Payload data (payload_size bytes)
 *
 *   Encrypted payloads use the discriminator above, then XOR-decode payloads
 *   with a repeating key ("lucky"):
 *   for each byte: if byte != 0 and byte != key_byte, byte ^= key_byte.
 */

#define KXP_SIGNATURE "KXP"
#define KXP_VERSION 1
#define KXP_INDEX_OFFSET_FIELD 0x25
#define KXP_INDEX_SIGNATURE 'I'
#define KXP_ENTRY_SIZE 17
#define KXP_NAME_SIZE 13
#define KXP_MEMBER_HEADER_SIZE 9
#define KXP_DEFAULT_KEY "lucky"

/* FUN_00435000 compares this 32-byte discriminator at file offset 5 when
 * byte 5 is non-zero. It is an archive-format check, separate from the
 * repeating XOR key passed to FUN_00435670 (normally "lucky"). */
static const unsigned char KXP_ENCRYPTED_HEADER[32] = {
    0x4d, 0x46, 0x53, 0x54, 0x52, 0x46, 0x4b, 0x4a,
    0x48, 0x50, 0x28, 0x25, 0x5e, 0x25, 0x31, 0x32,
    0x37, 0x36, 0x23, 0x7d, 0x2b, 0xbd, 0x9d, 0x61,
    0x6f, 0x69, 0x62, 0x6e, 0x32, 0x34, 0x3c, 0x3e
};

static uint32_t read_u32le(const unsigned char *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static uint16_t read_u16le(const unsigned char *p)
{
    return (uint16_t)((uint32_t)p[0] | ((uint32_t)p[1] << 8));
}

static int to_upper(int c)
{
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int ll_kxp_open(LL_KxpArchive *arch, const unsigned char *data, size_t data_size,
                const char *key)
{
    size_t key_len = 0;
    size_t key_index;
    unsigned char decoded_header[sizeof(KXP_ENCRYPTED_HEADER)];
    size_t index_offset;
    uint16_t entry_count;
    size_t entries_size;
    size_t entries_offset;

    if (arch == NULL || data == NULL) {
        return 0;
    }

    memset(arch, 0, sizeof(*arch));

    if (data_size < 0x29) {
        return 0;
    }
    if (data[0] != 'K' || data[1] != 'X' || data[2] != 'P' || data[3] != KXP_VERSION) {
        return 0;
    }

    arch->encrypted = (data[5] != 0) ? 1 : 0;
    if (arch->encrypted) {
        if (key == NULL || (key_len = strlen(key)) == 0) {
            return 0;
        }
        /* FUN_00435000 reads bytes 0x05..0x24 and passes them through
         * FUN_00435e10 with the caller's key before comparing the fixed
         * discriminator. Header bytes use unconditional XOR, unlike the
         * payload decoder's zero/key-byte exceptions. */
        memcpy(decoded_header, data + 5, sizeof(decoded_header));
        for (key_index = 0; key_index < sizeof(decoded_header); key_index++) {
            decoded_header[key_index] ^=
                (unsigned char)key[key_index % key_len];
        }
        if (memcmp(decoded_header, KXP_ENCRYPTED_HEADER,
                   sizeof(KXP_ENCRYPTED_HEADER)) != 0) {
            return 0;
        }
    }
    index_offset = read_u32le(data + KXP_INDEX_OFFSET_FIELD);

    if (index_offset > data_size - 3 || data[index_offset] != KXP_INDEX_SIGNATURE) {
        return 0;
    }

    entry_count = read_u16le(data + index_offset + 1);
    entries_offset = index_offset + 3;
    entries_size = (size_t)entry_count * KXP_ENTRY_SIZE;
    if (entries_size > data_size - entries_offset) {
        return 0;
    }

    arch->data = data;
    arch->data_size = data_size;
    return 1;
}

int ll_kxp_find(const LL_KxpArchive *arch, const char *member_name,
                const unsigned char **payload, size_t *payload_size)
{
    size_t index_offset;
    uint16_t entry_count;
    size_t entries_offset;
    size_t index;
    unsigned char expected_name[KXP_NAME_SIZE + 1];
    size_t name_len;
    size_t i;

    if (arch == NULL || arch->data == NULL || member_name == NULL ||
        payload == NULL || payload_size == NULL) {
        return 0;
    }

    *payload = NULL;
    *payload_size = 0;

    index_offset = read_u32le(arch->data + KXP_INDEX_OFFSET_FIELD);
    entries_offset = index_offset + 3;
    entry_count = read_u16le(arch->data + index_offset + 1);

    /* Build expected name: uppercase, null-padded to 13 bytes. */
    memset(expected_name, 0, sizeof(expected_name));
    name_len = 0;
    while (member_name[name_len] != '\0' && name_len < KXP_NAME_SIZE) {
        expected_name[name_len] = (unsigned char)to_upper(member_name[name_len]);
        name_len++;
    }

    for (index = 0; index < entry_count; index++) {
        size_t entry_offset = entries_offset + index * KXP_ENTRY_SIZE;
        const unsigned char *raw_name = arch->data + entry_offset;
        unsigned char name[KXP_NAME_SIZE + 1];
        uint32_t member_offset;
        size_t payload_start;
        uint32_t member_payload_size;

        memcpy(name, raw_name, KXP_NAME_SIZE);
        name[KXP_NAME_SIZE] = '\0';

        /* Case-insensitive compare over the 13-byte field. */
        for (i = 0; i < KXP_NAME_SIZE; i++) {
            if (to_upper(name[i]) != expected_name[i]) {
                goto next_entry;
            }
        }

        member_offset = read_u32le(arch->data + entry_offset + KXP_NAME_SIZE);
        if (member_offset > arch->data_size - KXP_MEMBER_HEADER_SIZE) {
            return 0;
        }

        payload_start = member_offset + KXP_MEMBER_HEADER_SIZE;
        /* The member header is 9 bytes: one marker byte, four opaque bytes,
         * then the little-endian payload length at offset +5. */
        member_payload_size = read_u32le(arch->data + member_offset + 5);
        if (member_payload_size == 0 ||
            member_payload_size > arch->data_size - payload_start) {
            return 0;
        }

        if (payload != NULL) {
            *payload = arch->data + payload_start;
        }
        if (payload_size != NULL) {
            *payload_size = (size_t)member_payload_size;
        }
        return 1;

    next_entry:
        continue;
    }

    return 0;
}

int ll_kxp_entry_count(const LL_KxpArchive *arch)
{
    size_t index_offset;
    if (arch == NULL || arch->data == NULL) {
        return 0;
    }
    index_offset = read_u32le(arch->data + KXP_INDEX_OFFSET_FIELD);
    if (index_offset > arch->data_size - 3) {
        return 0;
    }
    return (int)read_u16le(arch->data + index_offset + 1);
}

void ll_kxp_close(LL_KxpArchive *arch)
{
    if (arch != NULL) {
        memset(arch, 0, sizeof(*arch));
    }
}

/* Decrypt a payload buffer in place using the game's repeating-key XOR
 * scheme: for each byte, if byte != 0 and byte != key_byte, byte ^= key_byte.
 * Returns 1 on success, 0 if key is NULL. */
int ll_kxp_decrypt(unsigned char *payload, size_t payload_size,
                   const char *key)
{
    size_t offset;
    size_t key_len;

    if (payload == NULL || key == NULL) {
        return 0;
    }

    key_len = strlen(key);
    if (key_len == 0) {
        return 0;
    }

    for (offset = 0; offset < payload_size; offset++) {
        unsigned char key_byte = (unsigned char)key[offset % key_len];
        if (payload[offset] != 0 && payload[offset] != key_byte) {
            payload[offset] = (unsigned char)(payload[offset] ^ key_byte);
        }
    }
    return 1;
}
