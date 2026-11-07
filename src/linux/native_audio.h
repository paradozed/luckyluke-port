#ifndef LL_NATIVE_AUDIO_H
#define LL_NATIVE_AUDIO_H

#include "audio_mix.h"
#include "biz.h"

/* Native BIZ effects bank and64 wave voices. No SDL dependency. The caller
 * serializes controls/rendering and closes its audio device before close. */
typedef struct {
    LL_AudioMixer mixer;
    LL_BizSound samples[60];
    int16_t *pcm[60];
    uint16_t volume[64], pan[64], rate[64];
    uint8_t group[64]; /* DAT_004d239c: group4 survives the global effects mute. */
    uint16_t base, multiplier;
    int16_t pitch_offset; /* DAT_004d1eb2, read by the idle voice callbacks. */
    uint8_t ready, enabled, effects_enabled, stereo, master_volume, muted;
    uint8_t device_active, frame_remainder;
    uint32_t sample_count, plays;
    char error[192];
} LL_NativeAudio;

void ll_native_audio_init(LL_NativeAudio *audio);
int ll_native_audio_open(LL_NativeAudio *audio, LL_BizFile *biz);
void ll_native_audio_close(LL_NativeAudio *audio);
/* Success includes native silent outcomes (disabled, zero volume, full pool).
 * A malformed resource or unsupported pan returns0, without allocating a voice. */
int ll_native_audio_play(LL_NativeAudio *audio, uint16_t sample, int16_t pitch,
                          uint16_t volume, uint16_t pan, uint16_t *slot);
int ll_native_audio_control(LL_NativeAudio *audio, uint16_t command,
                             const uint16_t *args, size_t argc);
uint16_t ll_native_audio_active(const LL_NativeAudio *audio, uint16_t slot);
uint16_t ll_native_audio_free_voices(const LL_NativeAudio *audio);
void ll_native_audio_render(LL_NativeAudio *audio, int16_t *output, size_t frames);
/* Advance a virtual output device by1/24s when SDL is not driving rendering. */
void ll_native_audio_tick(LL_NativeAudio *audio);

#endif
