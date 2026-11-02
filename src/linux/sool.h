#ifndef LL_SOOL_H
#define LL_SOOL_H

#include <stddef.h>
#include <stdint.h>

/* One instruction in the SOOL VM byte stream. Operands are retained as
 * little-endian words; raw_size/raw_bytes always point inside the supplied
 * script buffer. Unknown/reserved opcodes are reported and consume one byte. */
typedef struct {
    uint32_t offset;
    uint8_t opcode;
    uint8_t size;
    uint8_t operand_count;
    uint16_t operands[2];
    const char *mnemonic;
    const unsigned char *raw_bytes;
    int known;
} LL_SoolInstruction;

typedef struct {
    uint32_t offset;       /* offset from the start of the SOOL file */
    uint32_t size;
    uint16_t code_start;
    uint16_t data_start;
    uint16_t virtual_start;
    uint16_t virtual_count;
    uint16_t conditions_start; /* 0xffff when no condition bytecode */
    uint16_t code_end;
    uint16_t initial_state; /* state index; 0xffff disables initial execution */
    uint16_t state_count;
    uint16_t *state_offsets;
} LL_SoolFunction;

typedef struct {
    const unsigned char *data;
    size_t size;
    uint16_t function_count;
    LL_SoolFunction *functions;
    char error[192];
} LL_SoolProgram;

/* A VM callback handles a command or variable instruction. It receives the
 * live operand stack and must consume its arguments and push any return value.
 * Return 1 on success, 0 on an unsupported command or malformed stack use. */
typedef int (*LL_SoolDispatch)(uint8_t opcode, uint16_t *stack,
                              size_t *stack_size, size_t stack_capacity,
                              void *userdata);

typedef struct {
    uint16_t stack[256];
    uint16_t locals[256];
    uint16_t members[256][256];
    uint16_t member_states[256];
    uint8_t member_state_requested[256];
    uint8_t member_disabled[256], member_disable_requested[256];
    size_t stack_size;
    uint32_t steps;
    uint32_t last_instruction_offset;
    uint8_t last_opcode;
    int16_t current_state;
    uint16_t state_flags;
    uint16_t pending_function;
    uint16_t pending_state;
    int has_pending_transition;
    uint32_t resume_pc, resume_end;
    uint16_t resume_function, resume_root_function, resume_root_state;
    uint32_t return_ends[64];
    size_t return_depth;
    int suspended;
    int host_yield; /* dispatch requests suspension after its instruction */
    uint16_t host_color_wait; /* host child token, zero when not waiting */
    uint8_t host_animation_wait; /* cleared by the object's completion callback */
    uint32_t host_wait_until; /* host scheduler deadline, in milliseconds */
} LL_SoolVM;

/* Update the overlapping little-endian word views of byte-addressed data. */
void ll_sool_write_word(uint16_t words[256], uint8_t offset, uint16_t value);

int ll_sool_program_open(LL_SoolProgram *program,
                         const unsigned char *data, size_t size);
void ll_sool_program_close(LL_SoolProgram *program);
const char *ll_sool_program_error(const LL_SoolProgram *program);
/* Execute one bounded function state. `state_index` selects the block's state
 * offset; execution stops at state_end/branch-return or its code boundary. */
int ll_sool_execute_state(const LL_SoolProgram *program, uint16_t function_index,
                          uint16_t state_index, LL_SoolVM *vm,
                          LL_SoolDispatch dispatch, void *userdata);

/* Decode a single VM instruction. Returns 1 on success and 0 when offset is
 * outside the script or a known instruction is truncated. */
int ll_sool_decode_instruction(const unsigned char *script, size_t script_size,
                               uint32_t offset, LL_SoolInstruction *out);

/* Decode a bounded byte stream into instructions. Unknown bytes are preserved
 * as one-byte instructions. The caller owns *out_instructions. */
int ll_sool_decode_script(const unsigned char *script, size_t script_size,
                          LL_SoolInstruction **out_instructions,
                          size_t *out_count);

#endif
