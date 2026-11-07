#include "native_audio.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void write32(unsigned char *p, uint32_t value)
{
    for (unsigned i=0;i<4;i++) p[i]=(unsigned char)(value>>(8u*i));
}

int main(void)
{
    /* One real-layout VAGp sample,56 PCM samples at16000Hz, with a constant
     * nonzero signal. Geometry and palette data are irrelevant to this bank. */
    enum { BANK=8+28+0x8000, HEADER=BANK+8, FRAMES=HEADER+64, SIZE=FRAMES+48 };
    unsigned char *data=calloc(SIZE,1);assert(data);
    write32(data,8);write32(data+4,BANK);write32(data+20,1);
    write32(data+BANK,1);write32(data+BANK+4,8);
    memcpy(data+HEADER,"VAGp",4);memcpy(data+HEADER+32,"effect",7);
    data[HEADER+18]=0x3e;data[HEADER+19]=0x80;
    data[FRAMES]=data[FRAMES+16]=8;
    memset(data+FRAMES+2,0x77,14);memset(data+FRAMES+18,0x77,14);data[FRAMES+33]=7;
    LL_BizFile biz={0};assert(ll_biz_open(&biz,data,SIZE));
    LL_NativeAudio audio;ll_native_audio_init(&audio);
    assert(ll_native_audio_open(&audio,&biz));
    assert(audio.ready && audio.enabled && audio.sample_count==1 && audio.effects_enabled);
    assert(ll_native_audio_free_voices(&audio)==64);
    uint16_t base[]={200},multiplier[]={600};
    assert(ll_native_audio_control(&audio,0xc8,base,1));
    assert(ll_native_audio_control(&audio,0xd0,multiplier,1));
    uint16_t voice=0;
    assert(!ll_native_audio_play(&audio,199,0,8191,1024,&voice) && !voice);
    assert(!ll_native_audio_play(&audio,200,0,8191,2049,&voice) && !voice);
    assert(audio.plays==0 && ll_native_audio_free_voices(&audio)==64);
    assert(ll_native_audio_play(&audio,200,-100,8191,2048,&voice) && voice==1);
    assert(audio.rate[0]==15900 && audio.mixer.voices[0].step==254 && audio.plays==1);
    int16_t output[16];ll_native_audio_render(&audio,output,8);
    assert(output[0]>0 && output[1]==0 && ll_native_audio_active(&audio,257)==1);
    uint16_t pitch[]={voice,100};
    assert(ll_native_audio_control(&audio,0xcb,pitch,2) && audio.mixer.voices[0].step==256);
    pitch[1]=200;
    assert(ll_native_audio_control(&audio,0xcb,pitch,2) && audio.mixer.voices[0].step==258);
    assert(audio.rate[0]==15900); /* Edits are relative to the original rate. */
    pitch[1]=0x8000;
    assert(ll_native_audio_control(&audio,0xcb,pitch,2) && audio.mixer.voices[0].step==68719207);
    pitch[1]=(uint16_t)(int16_t)-15900;
    assert(ll_native_audio_control(&audio,0xcb,pitch,2) && !audio.mixer.voices[0].step);
    uint64_t held_phase=audio.mixer.voices[0].position;
    ll_native_audio_render(&audio,output,8);
    assert(audio.mixer.voices[0].position==held_phase && audio.mixer.voices[0].active);
    pitch[1]=200;assert(ll_native_audio_control(&audio,0xcb,pitch,2));
    uint16_t gain[]={voice,16383,0};
    assert(ll_native_audio_control(&audio,0xcc,gain,3));
    ll_native_audio_render(&audio,output,8);assert(output[0]==0 && output[1]>0);
    uint64_t phase=audio.mixer.voices[0].position;
    uint16_t mute[]={1};assert(ll_native_audio_control(&audio,0xca,mute,1));
    ll_native_audio_render(&audio,output,8);
    for (unsigned i=0;i<16;i++) assert(!output[i]);
    assert(audio.mixer.voices[0].position>phase); /* Muting does not pause. */
    mute[0]=0;assert(ll_native_audio_control(&audio,0xca,mute,1));
    ll_native_audio_render(&audio,output,8);assert(output[1]>0);
    uint16_t stop[]={257};assert(ll_native_audio_control(&audio,0xc9,stop,1));
    assert(!ll_native_audio_active(&audio,1) && ll_native_audio_free_voices(&audio)==64);
    uint16_t reserve[]={2};assert(ll_native_audio_control(&audio,0xce,reserve,1));
    assert(ll_native_audio_free_voices(&audio)==63);
    assert(ll_native_audio_play(&audio,200,0,8191,1024,&voice) && voice==3);
    audio.device_active=1;phase=audio.mixer.voices[voice-1u].position;
    ll_native_audio_tick(&audio);assert(audio.mixer.voices[voice-1u].position==phase);
    audio.device_active=0;ll_native_audio_tick(&audio);
    assert(!ll_native_audio_active(&audio,voice) && ll_native_audio_free_voices(&audio)==63);
    assert(ll_native_audio_control(&audio,0xcf,reserve,1) && ll_native_audio_free_voices(&audio)==64);
    for (unsigned i=1;i<24;i++) ll_native_audio_tick(&audio);
    assert(audio.frame_remainder==0); /* Exactly16000 output frames per24 ticks. */
    audio.stereo=0;
    assert(ll_native_audio_play(&audio,200,0,8191,0,&voice));
    audio.master_volume=0;ll_native_audio_render(&audio,output,8);
    for (unsigned i=0;i<16;i++) assert(!output[i]);
    audio.master_volume=100;ll_native_audio_render(&audio,output,8);
    assert(output[0]>0 && output[0]==output[1]);
    /* Death-scene voice group4 remains audible while CA mutes ordinary
     * effects. DA only writes the byte; it does not recalculate gains. */
    uint16_t group[]={voice,4};assert(ll_native_audio_control(&audio,0xda,group,2));
    uint16_t ordinary;
    assert(ll_native_audio_play(&audio,200,0,8191,1024,&ordinary) && ordinary!=voice);
    mute[0]=1;assert(ll_native_audio_control(&audio,0xca,mute,1));
    assert(audio.mixer.voices[voice-1u].gain[0]>0 && !audio.mixer.voices[ordinary-1u].gain[0]);
    uint16_t edit[]={voice,6000,1024};assert(ll_native_audio_control(&audio,0xcc,edit,3));
    assert(audio.mixer.voices[voice-1u].gain[0]>0);
    group[1]=0;assert(ll_native_audio_control(&audio,0xda,group,2));
    assert(audio.mixer.voices[voice-1u].gain[0]>0);
    assert(ll_native_audio_control(&audio,0xcc,edit,3) && !audio.mixer.voices[voice-1u].gain[0]);
    mute[0]=0;assert(ll_native_audio_control(&audio,0xca,mute,1));
    assert(audio.mixer.voices[voice-1u].gain[0]>0 && audio.mixer.voices[ordinary-1u].gain[0]>0);
    group[1]=4;assert(ll_native_audio_control(&audio,0xda,group,2));
    mute[0]=1;assert(ll_native_audio_control(&audio,0xca,mute,1));
    stop[0]=voice;assert(ll_native_audio_control(&audio,0xc9,stop,1));
    audio.mixer.next_voice=voice-1u; /* Exercise reuse when the circular cursor returns. */
    assert(ll_native_audio_play(&audio,200,0,8191,1024,&voice));
    assert(audio.mixer.voices[voice-1u].gain[0]>0 && !audio.group[voice-1u]);
    /* 41f5e0 calculates gains with the reused slot's old group, then clears it. */
    mute[0]=0;assert(ll_native_audio_control(&audio,0xca,mute,1));
    /* A failed replacement preserves the live bank and its existing voices. */
    int16_t *pcm=audio.pcm[0];data[HEADER]='X';
    assert(!ll_native_audio_open(&audio,&biz) && audio.pcm[0]==pcm && audio.ready);
    assert(ll_native_audio_active(&audio,voice));data[HEADER]='V';
    for (unsigned i=0;i<64;i++) {
        uint16_t held[]={(uint16_t)(i+1u)};
        assert(ll_native_audio_control(&audio,0xce,held,1));
    }
    assert(!ll_native_audio_free_voices(&audio));
    assert(ll_native_audio_play(&audio,65535,0,8191,65535,&voice) && !voice);
    audio.enabled=0;
    assert(ll_native_audio_play(&audio,65535,0,8191,1024,&voice) && voice==0);
    assert(!ll_native_audio_free_voices(&audio));
    ll_native_audio_close(&audio);ll_biz_close(&biz);free(data);
    puts("Native effects bank, pitch, voice groups, mute, voice lifetime and virtual device: OK");
    return 0;
}
