#ifndef LL_AUDIO_MIX_H
#define LL_AUDIO_MIX_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    const int16_t *pcm; /* borrowed for the complete playback lifetime */
    size_t count;
    uint64_t position;
    uint32_t step; /* source samples per output frame,24.8; zero holds the sample. */
    uint16_t gain[2];
    uint8_t active, reserved;
} LL_AudioVoice;

typedef struct {
    LL_AudioVoice voices[64];
    uint32_t gain_table[256];
    unsigned next_voice;
} LL_AudioMixer;

/* Caller serializes mixing and controls (e.g. through SDL_LockAudioDevice). */
void ll_audio_mix_init(LL_AudioMixer *mixer);
int ll_audio_mix_gains(const LL_AudioMixer *mixer, uint16_t volume,
                       uint16_t multiplier, uint16_t pan, int stereo,
                       uint16_t gains[2]);
/* Returns native one-based slot, or zero when invalid/exhausted. */
uint16_t ll_audio_mix_play(LL_AudioMixer *mixer, const int16_t *pcm,
                           size_t count, uint32_t step, const uint16_t gains[2]);
void ll_audio_mix_stop(LL_AudioMixer *mixer, uint16_t slot);
int ll_audio_mix_reserve(LL_AudioMixer *mixer, uint16_t slot, int reserved);
/* Writes interleaved stereo PCM, wrapping voice additions as the native mixer. */
void ll_audio_mix_render(LL_AudioMixer *mixer, int16_t *output, size_t frames);

#endif
