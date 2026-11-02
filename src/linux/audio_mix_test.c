#include "audio_mix.h"

#include <assert.h>
#include <stdio.h>

int main(void)
{
    LL_AudioMixer mixer;
    ll_audio_mix_init(&mixer);
    uint16_t gains[2];
    assert(ll_audio_mix_gains(&mixer,16383,0,2048,1,gains));
    assert(gains[0]==95 && gains[1]==0);
    assert(ll_audio_mix_gains(&mixer,16383,0,0,0,gains));
    assert(gains[0]==95 && gains[1]==95);
    assert(ll_audio_mix_gains(&mixer,0,600,1024,1,gains));
    assert(!gains[0] && !gains[1]);
    assert(!ll_audio_mix_gains(&mixer,100,600,2049,1,gains));
    assert(mixer.gain_table[140]==23028);
    assert(mixer.gain_table[142]==268458460); /* native unsigned underflow */
    const int16_t pcm[2]={1000,-1000};
    const uint16_t unity[2]={256,128};
    uint16_t slot=ll_audio_mix_play(&mixer,pcm,2,256,unity);
    assert(slot==1);
    int16_t output[4];
    ll_audio_mix_render(&mixer,output,1);
    assert(output[0]==1000 && output[1]==500 && mixer.voices[0].active);
    ll_audio_mix_render(&mixer,output,1);
    assert(output[0]==-1000 && output[1]==-500 && !mixer.voices[0].active);
    ll_audio_mix_init(&mixer);
    for (unsigned i=0;i<64;i++) assert(ll_audio_mix_play(&mixer,pcm,2,256,unity)==i+1u);
    assert(!ll_audio_mix_play(&mixer,pcm,2,256,unity));
    assert(ll_audio_mix_reserve(&mixer,1,1));
    ll_audio_mix_render(&mixer,output,2);
    assert(output[0]==-1536 && output[1]==32000); /* wrapping sum of64 voices */
    assert(ll_audio_mix_play(&mixer,pcm,2,256,unity)==2);
    ll_audio_mix_stop(&mixer,1);assert(!mixer.voices[0].reserved);
    assert(!ll_audio_mix_reserve(&mixer,65,1));
    ll_audio_mix_init(&mixer);
    const int16_t negative[2]={-1,-3};
    assert(ll_audio_mix_play(&mixer,negative,2,128,unity));
    ll_audio_mix_render(&mixer,output,2);
    assert(output[0]==-1 && output[1]==-1 && output[2]==-1 && output[3]==-1);
    ll_audio_mix_render(&mixer,output,1);
    assert(output[0]==-3 && output[1]==-2);
    puts("Audio gain curve, 64 voices, reservations, phase and wrapping mix: OK");
    return 0;
}
