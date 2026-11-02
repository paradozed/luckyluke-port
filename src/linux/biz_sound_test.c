#include "biz.h"

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
    /* Minimal graphics page followed by one two-block VAGp sound. */
    enum { BANK=8+28+0x8000, HEADER=BANK+8, FRAMES=HEADER+64, SIZE=FRAMES+48 };
    unsigned char *data=calloc(SIZE,1);
    assert(data);
    write32(data,8);write32(data+4,BANK);write32(data+8+12,1);
    write32(data+BANK,1);write32(data+BANK+4,8);
    memcpy(data+HEADER,"VAGp",4);memcpy(data+HEADER+32,"test",5);
    data[HEADER+18]=0x3e;data[HEADER+19]=0x80; /* big-endian 16000 */
    unsigned char *frames=data+FRAMES;
    frames[0]=12;memset(frames+2,0x8f,14);
    frames[16]=0x1c;frames[33]=7;
    LL_BizFile biz;
    LL_BizSound sound;
    int16_t pcm[56];
    uint32_t count;
    assert(ll_biz_open(&biz,data,SIZE));
    assert(ll_biz_get_sound_count(&biz,&count) && count==1);
    assert(ll_biz_decode_sound(&biz,0,pcm,56,&sound));
    assert(sound.sample_rate==16000 && sound.sample_count==56);
    assert(!strcmp(sound.name,"test"));
    for (unsigned n=0;n<28;n++) assert(pcm[n]==(n%2 ? -8 : -1));
    /* Fractional feedback: -7.5, -7.03125, -6.591796875. */
    assert(pcm[28]==-7 && pcm[29]==-7 && pcm[30]==-6);
    frames[0]=0;memset(frames+2,0x77,14);
    frames[16]=0x10;memset(frames+18,0x77,14);
    assert(ll_biz_decode_sound(&biz,0,pcm,56,NULL));
    assert(pcm[28]==-9984); /* 55552 wraps, rather than clipping to 32767 */
    pcm[0]=1234;
    assert(!ll_biz_decode_sound(&biz,0,pcm,55,NULL) && pcm[0]==1234);
    assert(!ll_biz_get_sound(&biz,1,&sound));
    frames[0]=0x50;assert(!ll_biz_get_sound(&biz,0,&sound));
    frames[0]=13;assert(!ll_biz_get_sound(&biz,0,&sound));
    frames[0]=0;frames[33]=0;assert(!ll_biz_get_sound(&biz,0,&sound));
    frames[33]=7;data[HEADER]=0;assert(!ll_biz_get_sound(&biz,0,&sound));
    data[HEADER]='V';
    biz.raw_size=FRAMES+33;assert(!ll_biz_get_sound(&biz,0,&sound));
    biz.raw_size=SIZE;write32(data+BANK,61);
    assert(!ll_biz_get_sound_count(&biz,&count));
    write32(data+BANK,1);write32(data+BANK+4,4);
    assert(!ll_biz_get_sound(&biz,0,&sound));
    ll_biz_close(&biz);free(data);
    puts("BIZ sound bounds, native predictor feedback and PCM conversion: OK");
    return 0;
}
