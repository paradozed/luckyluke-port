#include "native_audio.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int audio_fail(LL_NativeAudio *audio, const char *message)
{
    snprintf(audio->error,sizeof(audio->error),"%s",message);return 0;
}

void ll_native_audio_init(LL_NativeAudio *audio)
{
    memset(audio,0,sizeof(*audio));ll_audio_mix_init(&audio->mixer);
    audio->effects_enabled=1;audio->stereo=1;audio->master_volume=100;
}

void ll_native_audio_close(LL_NativeAudio *audio)
{
    if (!audio) return;
    for (unsigned i=0;i<60;i++) free(audio->pcm[i]);
    memset(audio,0,sizeof(*audio));
}

int ll_native_audio_open(LL_NativeAudio *audio, LL_BizFile *biz)
{
    LL_NativeAudio prepared;ll_native_audio_init(&prepared);
    if (!ll_biz_get_sound_count(biz,&prepared.sample_count)) return audio_fail(audio,ll_biz_error(biz));
    for (unsigned i=0;i<prepared.sample_count;i++) {
        LL_BizSound *sample=&prepared.samples[i];
        if (!ll_biz_get_sound(biz,i,sample)) goto invalid;
        if (!sample->sample_count || sample->sample_count>16u*1024u*1024u) {
            audio_fail(audio,"native audio sample length is empty or exceeds16M samples");goto failed;
        }
        prepared.pcm[i]=malloc(sample->sample_count*sizeof(*prepared.pcm[i]));
        if (!prepared.pcm[i]) { audio_fail(audio,"cannot allocate native audio PCM");goto failed; }
        if (!ll_biz_decode_sound(biz,i,prepared.pcm[i],sample->sample_count,NULL)) goto invalid;
    }
    prepared.ready=1;prepared.enabled=1;
    ll_native_audio_close(audio);*audio=prepared;return 1;
invalid:
    audio_fail(audio,ll_biz_error(biz));
failed:
    ll_native_audio_close(&prepared);return 0;
}

int ll_native_audio_play(LL_NativeAudio *audio, uint16_t sample, int16_t pitch,
                          uint16_t volume, uint16_t pan, uint16_t *slot)
{
    if (!audio || !slot) return 0;
    *slot=0;
    if (!audio->enabled || !volume) return 1;
    /* FUN_00420490 finds a free physical voice before the sample/pan are
     * dereferenced. Exhaustion therefore also silences an invalid selector. */
    if (!ll_native_audio_free_voices(audio)) return 1;
    if (!audio->ready) return audio_fail(audio,"native effects bank is not initialized");
    sample=(uint16_t)(sample-audio->base);
    if (sample>=audio->sample_count || !audio->pcm[sample])
        return audio_fail(audio,"native sound selector is outside the decoded BIZ bank");
    uint16_t rate=(uint16_t)(audio->samples[sample].sample_rate+pitch),gains[2];
    if (!ll_audio_mix_gains(&audio->mixer,volume,audio->multiplier,pan,audio->stereo,gains))
        return audio_fail(audio,"native sound pan exceeds0..2048");
    unsigned candidate=64;
    for (unsigned offset=0;offset<64;offset++) {
        unsigned index=(audio->mixer.next_voice+offset)%64;
        if (!audio->mixer.voices[index].active && !audio->mixer.voices[index].reserved) { candidate=index;break; }
    }
    if (audio->muted && (candidate>=64 || audio->group[candidate]!=4)) gains[0]=gains[1]=0;
    *slot=ll_audio_mix_play(&audio->mixer,audio->pcm[sample],audio->samples[sample].sample_count,
        ((uint32_t)rate*256u+8000u)/16000u,gains);
    if (*slot) {
        audio->volume[*slot-1u]=volume;audio->pan[*slot-1u]=pan;audio->rate[*slot-1u]=rate;
        audio->group[*slot-1u]=0; /* Native resets it after calculating the initial gains. */
        audio->plays++;
    }
    return 1;
}

int ll_native_audio_control(LL_NativeAudio *audio, uint16_t command,
                             const uint16_t *args, size_t argc)
{
    if (!audio) return 0;
    switch (command) {
    case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xce: case 0xcf: case 0xd0: case 0xda: break;
    default:return audio_fail(audio,"native sound control is not implemented");
    }
    size_t expected=command==0xcc?3u:(command==0xcb || command==0xda)?2u:1u;
    if (!args || argc!=expected) return audio_fail(audio,"wrong native sound command arity");
    /* FUN_0041eff0/0041fdd0 also run when the physical driver is disabled. */
    if (command==0xc8) { audio->base=args[0];return 1; }
    if (command==0xd0) { audio->multiplier=args[0];return 1; }
    if (command==0xda) {
        uint16_t slot=(uint8_t)args[0];
        if (!slot) return 1;
        if (slot>64) return audio_fail(audio,"native voice group exceeds64 slots");
        audio->group[slot-1u]=(uint8_t)args[1];return 1;
    }
    if (command==0xce || command==0xcf) {
        uint16_t slot=(uint8_t)args[0];
        if (!slot) return 1;
        if (slot>64) return audio_fail(audio,"native voice reservation exceeds64 slots");
        return ll_audio_mix_reserve(&audio->mixer,slot,command==0xce);
    }
    if (!audio->enabled) return 1;
    if (command==0xca) {
        audio->muted=(uint8_t)args[0]==1;
        for (unsigned i=0;i<64;i++) {
            if (audio->group[i]==4) continue;
            if (audio->muted) audio->mixer.voices[i].gain[0]=audio->mixer.voices[i].gain[1]=0;
            else if (audio->mixer.voices[i].active || audio->mixer.voices[i].reserved)
                ll_audio_mix_gains(&audio->mixer,audio->volume[i],audio->multiplier,
                    audio->pan[i],audio->stereo,audio->mixer.voices[i].gain);
        }
        return 1;
    }
    uint16_t slot=(uint8_t)args[0];
    if (!slot) return 1;
    if (slot>64) return audio_fail(audio,"native voice control exceeds64 slots");
    if (command==0xc9) ll_audio_mix_stop(&audio->mixer,slot);
    else if (command==0xcc) {
        uint16_t gains[2];
        if (!ll_audio_mix_gains(&audio->mixer,args[1],audio->multiplier,args[2],audio->stereo,gains))
            return audio_fail(audio,"native sound pan exceeds0..2048");
        audio->volume[slot-1u]=args[1];audio->pan[slot-1u]=args[2];
        if (audio->muted && audio->group[slot-1u]!=4) gains[0]=gains[1]=0;
        memcpy(audio->mixer.voices[slot-1u].gain,gains,sizeof(gains));
    } else if (command==0xcb) {
        /* FUN_0041f9f0 adds to the remembered initial rate, not the last edit. */
        uint32_t rate=(uint32_t)audio->rate[slot-1u]+(uint32_t)(int32_t)(int16_t)args[1];
        audio->mixer.voices[slot-1u].step=(uint32_t)(((uint64_t)rate*256u+8000u)/16000u);
    } else return audio_fail(audio,"native sound control is not implemented");
    return 1;
}

uint16_t ll_native_audio_active(const LL_NativeAudio *audio, uint16_t slot)
{
    slot=(uint8_t)slot;
    return audio && audio->enabled && slot && slot<=64 ? audio->mixer.voices[slot-1u].active : 0;
}

uint16_t ll_native_audio_free_voices(const LL_NativeAudio *audio)
{
    if (!audio || !audio->enabled) return 0;
    uint16_t count=0;
    for (unsigned i=0;i<64;i++) count+=!audio->mixer.voices[i].active && !audio->mixer.voices[i].reserved;
    return count;
}

void ll_native_audio_render(LL_NativeAudio *audio, int16_t *output, size_t frames)
{
    if (!audio || !output || frames>SIZE_MAX/(2u*sizeof(*output))) return;
    ll_audio_mix_render(&audio->mixer,output,frames);
    /* waveOutSetVolume's master setting, using the native655.3499755859375. */
    unsigned master=(unsigned)(audio->master_volume*655.3499755859375);
    if (master>65535u) master=65535;
    if (!audio->enabled) master=0;
    for (size_t i=0;i<frames*2u;i++) output[i]=(int16_t)((int64_t)output[i]*master/65535);
}

void ll_native_audio_tick(LL_NativeAudio *audio)
{
    if (!audio || !audio->enabled || audio->device_active) return;
    unsigned numerator=16000u+audio->frame_remainder;
    unsigned frames=numerator/24u;audio->frame_remainder=(uint8_t)(numerator%24u);
    int16_t discard[667*2];ll_native_audio_render(audio,discard,frames);
}
