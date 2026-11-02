#include "audio_mix.h"

#include <string.h>

void ll_audio_mix_init(LL_AudioMixer *mixer)
{
    /* Game.run 004c6e04: preserve unsigned interpolation, including the
     * original nonmonotonic entries. FUN_00493f60 expands this to 256 gains. */
    static const uint16_t curve[65]={
        0,5376,37632,43264,46080,48128,49536,50560,51584,52608,53056,
        53824,54336,54848,55360,55872,56384,56896,57072,57248,57760,
        58016,58272,58528,58784,59040,59296,59552,59808,60064,60320,
        60576,60832,61088,61168,61408,61280,61920,61792,61920,62048,
        62176,62304,62432,62560,62688,62816,62944,63072,63200,63328,
        63456,63584,63712,63840,63968,64096,64240,64368,64496,64624,
        64752,64880,64912,64944
    };
    memset(mixer,0,sizeof(*mixer));
    for (unsigned i=0;i<64;i++) {
        uint32_t base=curve[i], delta=(uint32_t)curve[i+1]-base;
        uint32_t values[4]={base,base+(delta>>2),base+(delta>>1),base+(delta>>2)*3u};
        for (unsigned j=0;j<4;j++) mixer->gain_table[i*4+j]=(values[j]*3u)>>3;
    }
}

int ll_audio_mix_gains(const LL_AudioMixer *mixer, uint16_t volume,
                       uint16_t multiplier, uint16_t pan, int stereo,
                       uint16_t gains[2])
{
    if (!mixer || !gains || pan>2048) return 0;
    /* FUN_00420580 narrows the scaled result before its 0x3fff clamp. */
    if (multiplier) volume=(uint16_t)(((uint32_t)volume*multiplier)>>8);
    if (volume>16383) volume=16383;
    uint16_t left=volume, right=volume;
    if (stereo) { left=(uint16_t)(((uint32_t)pan*volume)>>11);right=volume-left; }
    gains[0]=(uint16_t)(mixer->gain_table[(uint32_t)left*255u/16383u]>>8);
    gains[1]=(uint16_t)(mixer->gain_table[(uint32_t)right*255u/16383u]>>8);
    return 1;
}

uint16_t ll_audio_mix_play(LL_AudioMixer *mixer, const int16_t *pcm,
                           size_t count, uint32_t step, const uint16_t gains[2])
{
    if (!mixer || !pcm || !count || !step || !gains) return 0;
    for (unsigned offset=0;offset<64;offset++) {
        unsigned slot=(mixer->next_voice+offset)%64;
        LL_AudioVoice *voice=&mixer->voices[slot];
        if (voice->active || voice->reserved) continue;
        *voice=(LL_AudioVoice){pcm,count,0,step,{gains[0],gains[1]},1,0};
        /* Native cursor advances once from its previous scan origin. */
        mixer->next_voice=(mixer->next_voice+1u)%64;
        return (uint16_t)(slot+1u);
    }
    return 0;
}

void ll_audio_mix_stop(LL_AudioMixer *mixer, uint16_t slot)
{
    if (mixer && slot && slot<=64) {
        mixer->voices[slot-1u].active=0;
        mixer->voices[slot-1u].reserved=0;
    }
}

int ll_audio_mix_reserve(LL_AudioMixer *mixer, uint16_t slot, int reserved)
{
    if (!mixer || !slot || slot>64) return 0;
    mixer->voices[slot-1u].reserved=(uint8_t)(reserved!=0);
    return 1;
}

static int16_t wrap16(int32_t value)
{
    uint16_t bits=(uint16_t)value;
    return (int16_t)(bits>=32768u ? (int32_t)bits-65536 : bits);
}

void ll_audio_mix_render(LL_AudioMixer *mixer, int16_t *output, size_t frames)
{
    if (!mixer || !output || frames>SIZE_MAX/(2u*sizeof(*output))) return;
    memset(output,0,frames*2u*sizeof(*output));
    for (unsigned slot=0;slot<64;slot++) {
        LL_AudioVoice *voice=&mixer->voices[slot];
        if (!voice->active) continue;
        for (size_t frame=0;frame<frames;frame++) {
            uint64_t source=(voice->position+127u)>>8;
            if (source>=voice->count) { voice->active=0;break; }
            int32_t sample=voice->pcm[(size_t)source];
            for (unsigned channel=0;channel<2;channel++) {
                int32_t product=sample*voice->gain[channel];
                /* Explicit arithmetic shift: native SAR rounds downward. */
                int32_t scaled=product>=0 ? product/256 : -((-(int64_t)product+255)/256);
                output[frame*2u+channel]=wrap16(output[frame*2u+channel]+scaled);
            }
            voice->position+=voice->step;
            if ((voice->position>>8)>=voice->count) voice->active=0;
            if (!voice->active) break;
        }
    }
}
