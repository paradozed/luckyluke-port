#include "level_script.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void word(unsigned char *p, unsigned value)
{
    p[0]=(unsigned char)value;p[1]=(unsigned char)(value>>8);
}

static void dword(unsigned char *p, unsigned value)
{
    word(p,value);word(p+2,value>>16);
}

/* Two functions with real headers, byte-addressed locals, optional conditions
 * and a virtual pair after code_end (the layout rejected before Abilene). */
static size_t fixture(unsigned char data[1024], const unsigned char *a, size_t as,
                        const unsigned char *b, size_t bs,
                        const unsigned char *conditions, size_t cs)
{
    memset(data,0,1024);memcpy(data,"SOOL",4);word(data+8,2);
    size_t offset=26;
    for (unsigned i=0;i<2;i++) {
        const unsigned char *code=i?b:a;size_t size=i?bs:as;
        size_t cond=i?0:cs;
        dword(data+10+i*4,(unsigned)offset);
        unsigned char *fn=data+offset;
        word(fn,18);word(fn+2,24);word(fn+4,(unsigned)(24+size+cond));
        word(fn+6,1);word(fn+8,cond?(unsigned)(24+size):UINT16_MAX);
        word(fn+10,0);word(fn+12,(unsigned)(24+size));word(fn+14,1);word(fn+16,24);
        memcpy(fn+24,code,size);
        if (cond) memcpy(fn+24+size,conditions,cond);
        word(fn+24+size+cond,0);word(fn+26+size+cond,0);
        offset+=24+size+cond+4;
    }
    dword(data+4,(unsigned)offset);return offset;
}

static void run_tests(void)
{
    unsigned char data[1024];
    const unsigned char end[]={0};
    /* Store member1 byte20 before its first execution. Then suspend with a
     * live operand. A condition stream must not consume that operand or PC. */
    const unsigned char body[]={5,0x34,0x12,5,1,0,5,20,0,0x29,0x3b,
        5,0x78,0x56,0x32,0x3b,5,7,0,5,0x58,0,0x3d,0};
    const unsigned char other[]={7,20,0,5,0x58,0,0x3d,0};
    const unsigned char conditions[]={5,9,0,5,0xa1,0,0x3d,1};
    size_t size=fixture(data,body,sizeof(body),other,sizeof(other),conditions,sizeof(conditions));
    FILE *trace=tmpfile();assert(trace);
    LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    assert(script.program.functions[0].code_end==24+sizeof(body));
    assert(script.program.functions[0].size==24+sizeof(body)+sizeof(conditions)+4);
    /* Runtime owns copies, including parser data. */
    data[0]='X';assert(script.program.data[0]=='S');
    ll_level_script_update(&script);
    assert(script.contexts[0].vm.suspended && script.contexts[0].vm.stack_size==1);
    assert(script.contexts[0].vm.stack[0]==0x5678);
    assert(script.contexts[1].vm.locals[20]==0x1234);
    assert(script.native.player_word==0x1234 && script.native.object_mode==9);
    ll_level_script_update(&script);
    assert(script.contexts[0].body_done && script.contexts[0].vm.stack_size==0);
    assert(script.native.player_word==7 && script.blocked_count==0);
    ll_level_script_close(&script);

    /* Variable host calls replace their identifier/arguments with the native
     * return word. FUN_0040bdc0 observes the command-controlled global flag. */
    const unsigned char variable_flags[]={
        5,0x38,0,0x50,5,0x58,0,0x3d,
        5,0,0,5,0x5b,0,0x3d,
        5,0x38,0,0x50,5,0x58,0,0x3d,0
    };
    size=fixture(data,variable_flags,sizeof(variable_flags),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);
    assert(script.native.player_word==1 && script.supported_calls==5 && !script.blocked_count);
    assert(script.native.native_flags==5);
    ll_level_script_close(&script);

    /* Quarantine unknown command, preserving stack and exact fault offset;
     * do not execute the following setter, retry, or stop unrelated contexts. */
    const unsigned char unknown[]={5,0x34,0x12,0x3c,5,2,0,5,0x58,0,0x3d,0};
    const unsigned char setter[]={5,42,0,5,0x58,0,0x3d,0};
    size=fixture(data,unknown,sizeof(unknown),setter,sizeof(setter),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);
    assert(script.blocked_count==1 && script.contexts[0].blocked);
    assert(script.contexts[0].vm.stack_size==1 && script.contexts[0].vm.stack[0]==0x1234);
    assert(script.contexts[0].vm.last_instruction_offset==27);
    assert(script.native.player_word==42);
    uint32_t calls=script.calls;
    for (unsigned i=0;i<100;i++) ll_level_script_update(&script);
    assert(script.calls==calls && script.blocked_count==1);
    ll_level_script_close(&script);

    /* Native unsigned clamp after sign extension: -1 ->200, 0 ->10. */
    const unsigned char clamp[]={5,0xff,0xff,5,0x3e,1,0x3d,0};
    size=fixture(data,clamp,sizeof(clamp),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);assert(script.native.camera_limit==200);
    ll_level_script_close(&script);
    data[26+25]=data[26+26]=0;
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);assert(script.native.camera_limit==10);
    ll_level_script_close(&script);

    /* A remote state request must not restart another body in the same tick.
     * It becomes visible before bodies on the next update. */
    const unsigned char remote[]={5,1,0,5,1,0,0x38,0};
    const unsigned char two_states[]={0,5,42,0,5,0x58,0,0x3d,0};
    size=fixture(data,remote,sizeof(remote),two_states,sizeof(two_states),NULL,0);
    size_t second=data[14]|((size_t)data[15]<<8);
    word(data+second,20);word(data+second+14,2);word(data+second+18,25);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.contexts[1].body_done=1;
    ll_level_script_update(&script);assert(script.native.player_word==0);
    ll_level_script_update(&script);assert(script.native.player_word==42);
    ll_level_script_close(&script);

    const unsigned char self_transition[]={5,1,0,0x37,5,99,0,5,0x58,0,0x3d,0,
        5,42,0,5,0x58,0,0x3d,0};
    size=fixture(data,self_transition,sizeof(self_transition),end,sizeof(end),NULL,0);
    word(data+26,20);word(data+26+14,2);word(data+26+18,36);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);assert(script.native.player_word==0);
    assert(script.contexts[0].vm.suspended && script.contexts[0].vm.resume_pc==26+28);
    ll_level_script_update(&script);assert(script.native.player_word==42);
    ll_level_script_close(&script);

    /* Separate condition branches may jump beyond state code_end. Compare
     * the current state, skip the disabled arm, terminate at opcode1. */
    const unsigned char branch[]={0x0e,0,0,0,0,5,1,0,5,1,0,0x0f,1};
    size=fixture(data,end,sizeof(end),end,sizeof(end),branch,sizeof(branch));
    word(data+26+24+sizeof(end)+3,24+sizeof(end)+sizeof(branch)-1);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);assert(!script.blocked_count);
    assert(!script.contexts[0].vm.has_pending_transition);
    ll_level_script_close(&script);

    /* initial_state ffff finishes the body (native flag2), not the whole
     * context (flag1). Its conditions can request the first ordinary state. */
    const unsigned char activate[]={5,0,0,5,1,0,0x0f,1};
    size=fixture(data,setter,sizeof(setter),end,sizeof(end),activate,sizeof(activate));
    word(data+26+10,UINT16_MAX);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    assert(!(script.contexts[0].vm.state_flags&1u));
    ll_level_script_update(&script);assert(script.native.player_word==0);
    assert(script.contexts[0].vm.has_pending_transition);
    ll_level_script_update(&script);assert(script.native.player_word==42);
    ll_level_script_close(&script);

    /* Cross-function and trailing-table bounds: valid code does not justify
     * reading into the next function or accepting a truncated virtual pair. */
    LL_SoolProgram program={0};
    assert(ll_sool_program_open(&program,data,size));ll_sool_program_close(&program);
    word(data+26+4,1023);
    assert(!ll_sool_program_open(&program,data,size));ll_sool_program_close(&program);
    size=fixture(data,end,sizeof(end),end,sizeof(end),branch,sizeof(branch));
    word(data+26+8,24); /* conditions cannot overlap state code */
    assert(!ll_sool_program_open(&program,data,size));ll_sool_program_close(&program);
    size=fixture(data,end,sizeof(end),end,sizeof(end),NULL,0);
    word(data+26+12,1023); /* state code cannot cross into next function */
    assert(!ll_sool_program_open(&program,data,size));ll_sool_program_close(&program);
    size=fixture(data,end,sizeof(end),end,sizeof(end),NULL,0);
    dword(data+4,(unsigned)size-1);
    assert(!ll_sool_program_open(&program,data,size-1));ll_sool_program_close(&program);
    fclose(trace);
}

int main(void)
{
    run_tests();
    puts("Level SOOL ownership, conditions, continuations, requests, quarantine and bounds: OK");
    return 0;
}
