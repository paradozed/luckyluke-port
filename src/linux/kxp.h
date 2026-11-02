#ifndef LL_KXP_H
#define LL_KXP_H

#include <stddef.h>
#include <stdint.h>

/*
 * KXP archive reader for Lucky Luke game data archives.
 *
 * The original game stores graphics (PCX images) inside localized KXP
 * archives such as win/graphics/menu_e.kxp, abilene/abilene.kxp, etc.
 * This module reads a KXP archive at runtime and extracts individual
 * members, reproducing the game's conditional repeating-key XOR decode
 * (key "lucky") for encrypted archives.
 *
 * All functions validate signatures, lengths, offsets, and bounds before
 * parsing, and return actionable errors on malformed input.
 */

typedef struct {
    const unsigned char *data;
    size_t data_size;
    int encrypted;
} LL_KxpArchive;

/* Open a KXP archive from a memory buffer.  The buffer must remain valid
 * for the lifetime of the archive.  Returns 1 on success, 0 on error. */
int ll_kxp_open(LL_KxpArchive *arch, const unsigned char *data, size_t data_size,
                const char *key);

/* Find a member by name (case-insensitive, uppercased comparison).  Returns
 * 1 and fills in payload/payload_size if found, 0 if not found. */
int ll_kxp_find(const LL_KxpArchive *arch, const char *member_name,
                const unsigned char **payload, size_t *payload_size);

/* Number of entries in the archive index. */
int ll_kxp_entry_count(const LL_KxpArchive *arch);

/* Decrypt a payload buffer in place using the repeating-key XOR scheme
 * (key "lucky" by default).  Returns 1 on success, 0 if key is NULL. */
int ll_kxp_decrypt(unsigned char *payload, size_t payload_size,
                   const char *key);

/* Close/release an archive (currently a no-op, buffer owned by caller). */
void ll_kxp_close(LL_KxpArchive *arch);

#endif
