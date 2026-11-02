#include "sool.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

static LL_SoolVM vm;

static int wait_command(uint8_t opcode, uint16_t *stack, size_t *size,
                        size_t capacity, void *userdata)
{
    (void)stack; (void)capacity;
    assert(opcode == 0x3c && *size == 1);
    (*size)--;
    ((LL_SoolVM *)userdata)->host_yield = 1;
    return 1;
}

int main(void)
{
    /* Store 0x1234 at byte 20, increment the overlapping word at 21,
     * then copy that word to another function's byte-addressed data. */
    static const unsigned char code[] = {
        0x05, 0x34, 0x12, 0x05, 20, 0, 0x28, 0x3b,
        0x05, 21, 0, 0x2a,
        0x07, 21, 0, 0x05, 1, 0, 0x05, 30, 0, 0x29, 0x3b, 0
    };
    uint16_t state = 0;
    LL_SoolFunction function = { .size = sizeof(code), .code_end = sizeof(code),
                                .state_count = 1, .state_offsets = &state };
    LL_SoolProgram program = { .data = code, .size = sizeof(code),
                              .function_count = 1, .functions = &function };
    assert(ll_sool_execute_state(&program, 0, 0, &vm, NULL, NULL));
    assert(vm.locals[19] == 0x3400);
    assert(vm.locals[20] == 0x1334);
    assert(vm.locals[21] == 0x0013);
    assert(vm.members[1][29] == 0x1300);
    assert(vm.members[1][30] == 0x0013);
    ll_sool_write_word(vm.locals, 0, 0xabcd);
    assert(vm.locals[1] == 0x00ab);
    ll_sool_write_word(vm.locals, 255, 0x5678);
    assert(vm.locals[254] == 0x7800);
    /* Member stores to self must be visible through local loads, and local
     * stores through member loads, without a scheduler synchronization. */
    static const unsigned char self_code[] = {
        0x05, 0x78, 0x56, 0x05, 0, 0, 0x05, 20, 0, 0x29, 0x3b,
        0x07, 20, 0,
        0x05, 21, 0, 0x2a,
        0x08, 0, 0, 20, 0, 0
    };
    memset(&vm, 0, sizeof(vm));
    function.size = function.code_end = sizeof(self_code);
    program.data = self_code;
    program.size = sizeof(self_code);
    assert(ll_sool_execute_state(&program, 0, 0, &vm, NULL, NULL));
    assert(vm.stack_size == 2);
    assert(vm.stack[0] == 0x5678);
    assert(vm.stack[1] == 0x5778);
    static const unsigned char wait_code[] = {
        0x05, 11, 0, 0x3c, 0x05, 42, 0, 0
    };
    memset(&vm, 0, sizeof(vm));
    function.size = function.code_end = sizeof(wait_code);
    program.data = wait_code;
    program.size = sizeof(wait_code);
    assert(ll_sool_execute_state(&program, 0, 0, &vm, wait_command, &vm));
    assert(vm.suspended && vm.resume_pc == 4 && vm.stack_size == 0);
    assert(!vm.host_yield);
    assert(ll_sool_execute_state(&program, 0, 0, &vm, wait_command, &vm));
    assert(!vm.suspended && vm.stack_size == 1 && vm.stack[0] == 42);
    static const unsigned char state_code[] = {
        0x05,0,0, 0x05,0,0, 0x38,
        0x05,0,0, 0x05,0,0, 0x13, 0
    };
    memset(&vm,0,sizeof(vm));
    vm.locals[255]=0x1234;
    vm.member_states[0]=UINT16_MAX;
    function.size=function.code_end=sizeof(state_code);
    program.data=state_code;
    program.size=sizeof(state_code);
    assert(ll_sool_execute_state(&program,0,0,&vm,NULL,NULL));
    assert(vm.member_state_requested[0] && vm.member_states[0]==0);
    assert(vm.stack_size==1 && vm.stack[0]==1);
    assert(vm.locals[255]==0x1234);
    static const unsigned char disable_code[] = {
        0x05,0,0, 0x36, 0x05,42,0, 0
    };
    memset(&vm,0,sizeof(vm));
    vm.members[0][255]=0x5678;
    function.size=function.code_end=sizeof(disable_code);
    program.data=disable_code;
    program.size=sizeof(disable_code);
    assert(ll_sool_execute_state(&program,0,0,&vm,NULL,NULL));
    assert(vm.suspended && vm.resume_pc==4 && vm.stack_size==0);
    assert((vm.state_flags&1u) && vm.member_disable_requested[0] && vm.member_disabled[0]);
    assert(vm.members[0][255]==0x5678);
    vm.state_flags &= (uint16_t)~1u; /* scheduler re-enables this context */
    assert(ll_sool_execute_state(&program,0,0,&vm,NULL,NULL));
    assert(!vm.suspended && vm.stack_size==1 && vm.stack[0]==42);
    static const unsigned char enable_code[]={0x05,0,0,0x35,0};
    memset(&vm,0,sizeof(vm));
    vm.state_flags=1;
    function.size=function.code_end=sizeof(enable_code);
    program.data=enable_code;
    program.size=sizeof(enable_code);
    assert(ll_sool_execute_state(&program,0,0,&vm,NULL,NULL));
    assert(!(vm.state_flags&1u) && vm.member_disable_requested[0] && !vm.member_disabled[0]);
    static const uint16_t values[]={0,1,0x1234,0x7fff,0x8000,0xfffd,0xffff};
    for (unsigned i=0;i<sizeof(values)/sizeof(values[0]);i++)
        for (unsigned count=0;count<64;count++)
            for (unsigned right=0;right<2;right++) {
                unsigned char code[]={0x05,(unsigned char)count,0,
                    0x05,(unsigned char)values[i],(unsigned char)(values[i]>>8),
                    (unsigned char)(right?0x26:0x25),0};
                memset(&vm,0,sizeof(vm));
                function.size=function.code_end=sizeof(code);
                program.data=code;program.size=sizeof(code);
                assert(ll_sool_execute_state(&program,0,0,&vm,NULL,NULL));
                unsigned shift=count%32u;
                uint16_t expected;
                if (!right) expected=shift>=16u?0:(uint16_t)(values[i]*(1u<<shift));
                else if (shift>=16u) expected=(int16_t)values[i]<0?UINT16_MAX:0;
                else {
                    int32_t value=(int16_t)values[i], divisor=(int32_t)(1u<<shift);
                    int32_t quotient=value/divisor;
                    if (value<0 && value%divisor) quotient--;
                    expected=(uint16_t)quotient;
                }
                assert(vm.stack_size==1 && vm.stack[0]==expected);
            }
    puts("SOOL data, states, waits and 896 x86 shift cases: OK");
    return 0;
}
