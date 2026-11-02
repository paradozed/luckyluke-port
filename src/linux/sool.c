#include "sool.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static uint16_t read_u16le(const unsigned char *p)
{
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

static const char *const names[0x5f] = {
    [0x00] = "state_end", [0x01] = "branch",
    [0x02] = "indirect_frame_jump", [0x03] = "branch_if_zero",
    [0x04] = "jump", [0x05] = "push_immediate",
    [0x06] = "push_immediate_alt", [0x07] = "push_local",
    [0x08] = "push_member", [0x09] = "push_immediate_alt2",
    [0x0a] = "push_two_immediates", [0x0b] = "lookup_indexed",
    [0x0c] = "lookup_stack_indexed", [0x0d] = "lookup_nested",
    [0x0e] = "compare_state_branch", [0x0f] = "conditional_state",
    [0x10] = "set_state_flag", [0x11] = "clear_state_flag",
    [0x12] = "compare_state_value", [0x13] = "compare_member_value",
    [0x14] = "logical_not", [0x15] = "equal", [0x16] = "not_equal",
    [0x17] = "logical_and", [0x18] = "logical_or", [0x19] = "subtract",
    [0x1a] = "add", [0x1b] = "divide", [0x1c] = "multiply",
    [0x1d] = "modulo", [0x1e] = "less_than", [0x1f] = "greater_than",
    [0x20] = "less_equal", [0x21] = "greater_equal", [0x22] = "negate",
    [0x23] = "bit_and", [0x24] = "bit_or", [0x25] = "shift_left",
    [0x26] = "shift_right", [0x28] = "store_local",
    [0x29] = "store_member", [0x2a] = "increment_local",
    [0x2b] = "increment_member", [0x2c] = "decrement_local",
    [0x2d] = "decrement_member", [0x2e] = "add_local",
    [0x2f] = "add_member", [0x30] = "subtract_local",
    [0x31] = "subtract_member", [0x32] = "clear_state",
    [0x34] = "set_local_state", [0x35] = "clear_member_state",
    [0x36] = "set_member_state", [0x37] = "set_state_value",
    [0x38] = "set_member_state_value", [0x39] = "next_state",
    [0x3a] = "switch_function_state", [0x3b] = "pop",
    [0x3c] = "command_00", [0x50] = "variable_00"
};

static unsigned operand_count(uint8_t op)
{
    switch (op) {
    case 0x08: case 0x0a: return 2;
    case 0x03: case 0x04: case 0x05: case 0x06: case 0x07: case 0x09:
        return 1;
    case 0x0e: return 2;
    default: return 0;
    }
}

int ll_sool_decode_instruction(const unsigned char *script, size_t script_size,
                               uint32_t offset, LL_SoolInstruction *out)
{
    uint8_t op;
    unsigned count;
    size_t size;
    if (script == NULL || out == NULL || offset >= script_size) return 0;
    memset(out, 0, sizeof(*out));
    op = script[offset];
    count = operand_count(op);
    size = 1u + 2u * count;
    if (size > script_size - offset) return 0;
    out->offset = offset;
    out->opcode = op;
    out->size = (uint8_t)size;
    out->operand_count = (uint8_t)count;
    out->mnemonic = op < sizeof(names) / sizeof(names[0]) ? names[op] : NULL;
    out->known = out->mnemonic != NULL || (op >= 0x3c && op <= 0x4a) ||
                 (op >= 0x50 && op <= 0x5e);
    if (op >= 0x3c && op <= 0x4a) out->mnemonic = "command";
    if (op >= 0x50 && op <= 0x5e) out->mnemonic = "variable";
    out->raw_bytes = script + offset;
    for (unsigned i = 0; i < count; i++)
        out->operands[i] = read_u16le(script + offset + 1u + i * 2u);
    return 1;
}

int ll_sool_decode_script(const unsigned char *script, size_t script_size,
                          LL_SoolInstruction **out_instructions,
                          size_t *out_count)
{
    LL_SoolInstruction *items;
    size_t count = 0, offset = 0;
    if (script == NULL || out_instructions == NULL || out_count == NULL ||
        script_size > UINT32_MAX) return 0;
    *out_instructions = NULL;
    *out_count = 0;
    if (script_size == 0) return 1;
    items = (LL_SoolInstruction *)calloc(script_size, sizeof(*items));
    if (items == NULL) return 0;
    while (offset < script_size) {
        LL_SoolInstruction instruction;
        if (!ll_sool_decode_instruction(script, script_size, (uint32_t)offset,
                                        &instruction)) {
            free(items);
            return 0;
        }
        items[count++] = instruction;
        offset += instruction.size;
    }
    *out_instructions = items;
    *out_count = count;
    return 1;
}

static uint32_t read_u32le(const unsigned char *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static int vm_error(LL_SoolProgram *program, const char *message)
{
    snprintf(program->error, sizeof(program->error), "%s", message);
    return 0;
}

int ll_sool_program_open(LL_SoolProgram *program,
                         const unsigned char *data, size_t size)
{
    uint16_t count;
    uint64_t table_end;
    if (program == NULL) return 0;
    memset(program, 0, sizeof(*program));
    if (data == NULL || size < 10 || memcmp(data, "SOOL", 4) != 0)
        return vm_error(program, "SOOL signature/header is missing or truncated");
    if (read_u32le(data + 4) != size)
        return vm_error(program, "SOOL declared size does not match the file length");
    count = read_u16le(data + 8);
    table_end = 10u + (uint64_t)count * 8u;
    if (count == 0 || count > 4096 || table_end > size)
        return vm_error(program, "SOOL function directory is outside supported bounds");
    program->functions = (LL_SoolFunction *)calloc(count, sizeof(*program->functions));
    if (program->functions == NULL)
        return vm_error(program, "cannot allocate SOOL function directory");
    program->data = data;
    program->size = size;
    program->function_count = count;
    for (uint32_t i = 0; i < count; i++) {
        LL_SoolFunction *fn = &program->functions[i];
        uint32_t offset = read_u32le(data + 10u + i * 4u);
        uint32_t block_size;
        if (offset < table_end || offset > size || size - offset < 16u ||
            (i != 0 && offset <= program->functions[i - 1u].offset)) {
            ll_sool_program_close(program);
            return vm_error(program, "SOOL function offset is invalid or unordered");
        }
        fn->offset = offset;
        fn->data_start = read_u16le(data + offset);
        fn->code_start = read_u16le(data + offset + 2u);
        fn->virtual_start = read_u16le(data + offset + 4u);
        fn->virtual_count = read_u16le(data + offset + 6u);
        fn->conditions_start = read_u16le(data + offset + 8u);
        fn->initial_state = read_u16le(data + offset + 10u);
        block_size = read_u16le(data + offset + 12u);
        fn->state_count = read_u16le(data + offset + 14u);
        if (block_size < 16u || block_size > size - offset ||
            fn->state_count == 0 || fn->state_count > 4096 ||
            (fn->initial_state != UINT16_MAX && fn->initial_state >= fn->state_count) ||
            16u + (uint64_t)fn->state_count * 2u > block_size ||
            fn->code_start < 16u + fn->state_count * 2u || fn->code_start >= block_size) {
            ll_sool_program_close(program);
            return vm_error(program, "SOOL function header/state table is malformed");
        }
        fn->size = block_size;
        if ((fn->conditions_start != UINT16_MAX && fn->conditions_start >= block_size) ||
            (fn->data_start != UINT16_MAX && fn->data_start >= block_size) ||
            (fn->virtual_start != UINT16_MAX && fn->virtual_start >= block_size)) {
            ll_sool_program_close(program);
            return vm_error(program, "SOOL data/condition directory exceeds its function block");
        }
        fn->code_end = (uint16_t)block_size;
        fn->state_offsets = (uint16_t *)calloc(fn->state_count, sizeof(uint16_t));
        if (fn->state_offsets == NULL) {
            ll_sool_program_close(program);
            return vm_error(program, "cannot allocate SOOL state offset table");
        }
        for (uint32_t j = 0; j < fn->state_count; j++) {
            uint16_t state = read_u16le(data + offset + 16u + j * 2u);
            if (state < fn->code_start || state >= block_size ||
                (j != 0 && state <= fn->state_offsets[j - 1u])) {
                ll_sool_program_close(program);
                return vm_error(program, "SOOL state offset is invalid or unordered");
            }
            fn->state_offsets[j] = state;
        }
    }
    return 1;
}

void ll_sool_program_close(LL_SoolProgram *program)
{
    if (program == NULL) return;
    if (program->functions != NULL) {
        for (uint32_t i = 0; i < program->function_count; i++)
            free(program->functions[i].state_offsets);
    }
    free(program->functions);
    memset(program, 0, sizeof(*program));
}

const char *ll_sool_program_error(const LL_SoolProgram *program)
{
    return program != NULL ? program->error : "SOOL program handle is null";
}

/* Native locals are little-endian words addressed by byte offset
 * (FUN_00421fc0). Keep overlapping word views coherent. */
void ll_sool_write_word(uint16_t words[256], uint8_t offset, uint16_t value)
{
    words[offset] = value;
    if (offset != 0)
        words[offset - 1u] = (uint16_t)((words[offset - 1u] & 0xffu) |
                                      ((value & 0xffu) << 8));
    if (offset != 255)
        words[offset + 1u] = (uint16_t)((words[offset + 1u] & 0xff00u) |
                                      (value >> 8));
}

/* A member reference to the executing function aliases its live locals. */
static uint16_t *vm_data_bank(LL_SoolVM *vm, uint16_t current, uint16_t target)
{
    return (target & 0xffu) == current ? vm->locals : vm->members[target & 0xffu];
}

static int vm_push(LL_SoolVM *vm, uint16_t value)
{
    if (vm->stack_size >= sizeof(vm->stack) / sizeof(vm->stack[0])) return 0;
    vm->stack[vm->stack_size++] = value;
    return 1;
}

static int vm_pop(LL_SoolVM *vm, uint16_t *value)
{
    if (vm->stack_size == 0) return 0;
    *value = vm->stack[--vm->stack_size];
    return 1;
}

int ll_sool_execute_state(const LL_SoolProgram *program, uint16_t function_index,
                          uint16_t state_index, LL_SoolVM *vm,
                          LL_SoolDispatch dispatch, void *userdata)
{
    const LL_SoolFunction *fn;
    uint32_t pc, end;
    uint32_t *return_ends;
    size_t return_depth;
    if (program == NULL || vm == NULL || function_index >= program->function_count)
        return 0;
    fn = &program->functions[function_index];
    if (state_index >= fn->state_count) return 0;
    return_ends = vm->return_ends;
    return_depth = 0;
    pc = (uint32_t)fn->offset + fn->state_offsets[state_index];
    /* Sequential fall-through belongs to this state only. State transitions
     * are returned to the caller so the runtime can schedule the target state
     * independently instead of running adjacent state bodies as one stream. */
    end = (uint32_t)fn->offset +
          (state_index + 1u < fn->state_count ? fn->state_offsets[state_index + 1u]
                                             : fn->code_end);
    if (vm->suspended && vm->resume_root_function == function_index &&
        vm->resume_root_state == state_index) {
        if (vm->resume_function >= program->function_count || vm->return_depth > 64) return 0;
        function_index = vm->resume_function;
        fn = &program->functions[function_index];
        pc = vm->resume_pc;
        end = vm->resume_end;
        return_depth = vm->return_depth;
        if (pc < fn->offset + fn->code_start || end > fn->offset + fn->code_end || pc > end) return 0;
    } else {
        vm->resume_root_function = function_index;
        vm->resume_root_state = state_index;
    }
    vm->suspended = 0;
    vm->steps = 0;
    /* FUN_004219b0 executes at most 30 ordinary instructions per update;
     * mask 4 requests synchronous execution, still bounded here. */
    while (pc < end && vm->steps < ((vm->state_flags & 4u) ? 100000u : 30u)) {
        vm->steps++;
        LL_SoolInstruction ins;
        uint16_t a, b;
        if (!ll_sool_decode_instruction(program->data, program->size, pc, &ins) ||
            pc + ins.size > end) return 0;
        vm->last_instruction_offset = pc - fn->offset;
        vm->last_opcode = ins.opcode;
        switch (ins.opcode) {
        case 0x00: case 0x01: return 1;
        case 0x02:
            if (!vm_pop(vm, &a) || !vm_pop(vm, &b)) return 0;
            if (return_depth != 0) {
                if (b >= program->function_count || b >= 256) return 0;
                const LL_SoolFunction *caller = &program->functions[b];
                if (a < caller->code_start || a >= caller->code_end) return 0;
                if (b != function_index) {
                    memcpy(vm->members[function_index], vm->locals, sizeof(vm->locals));
                    memcpy(vm->locals, vm->members[b], sizeof(vm->locals));
                }
                function_index = b;
                fn = caller;
                pc = fn->offset + a;
                end = return_ends[--return_depth];
                break;
            }
            vm->pending_state = a;
            vm->pending_function = b;
            vm->has_pending_transition = 1;
            return 1;
        case 0x03:
            if (!vm_pop(vm, &a)) return 0;
            if (a == 0) {
                if (ins.operands[0] < fn->code_start || ins.operands[0] >= fn->code_end) return 0;
                pc = (uint32_t)fn->offset + ins.operands[0];
            } else pc += ins.size;
            break;
        case 0x04:
            if (ins.operands[0] < fn->code_start || ins.operands[0] >= fn->code_end) return 0;
            pc = (uint32_t)fn->offset + ins.operands[0]; break;
        case 0x05: case 0x06: case 0x09:
            if (!vm_push(vm, ins.operands[0])) return 0;
            pc += ins.size; break;
        case 0x07:
            if (!vm_push(vm, vm->locals[ins.operands[0] & 0xffu])) return 0;
            pc += ins.size; break;
        case 0x08:
            if (!vm_push(vm, vm_data_bank(vm, function_index, ins.operands[0])[ins.operands[1] & 0xffu])) return 0;
            pc += ins.size; break;
        case 0x0a:
            if (!vm_push(vm, ins.operands[0]) || !vm_push(vm, ins.operands[1])) return 0;
            pc += ins.size; break;
        case 0x0b:
            if (!vm_pop(vm, &a) || !vm_pop(vm, &b) ||
                !vm_push(vm, vm_data_bank(vm, function_index, b)[a & 0xffu])) return 0;
            pc++; break;
        case 0x0c:
            if (!vm_pop(vm, &a) || vm->stack_size == 0) return 0;
            b = vm->stack[vm->stack_size - 1u];
            if (!vm_push(vm, vm_data_bank(vm, function_index, b)[a & 0xffu])) return 0;
            pc++; break;
        case 0x0d:
            if (!vm_pop(vm, &a) || !vm_pop(vm, &b)) return 0;
            a = vm_data_bank(vm, function_index, b)[a & 0xffu];
            if (!vm_push(vm, vm_data_bank(vm, function_index, b)[a & 0xffu])) return 0;
            pc++; break;
        case 0x0f:
            if (!vm_pop(vm, &a)) return 0;
            if (a != 0) {
                if (!vm_pop(vm, &a)) return 0;
                if (a != UINT16_MAX && a >= fn->state_count) return 0;
                if ((int16_t)a != vm->current_state) {
                    vm->pending_function = function_index;
                    vm->pending_state = a;
                    vm->has_pending_transition = 1;
                }
            } else if (!vm_pop(vm, &a)) return 0;
            pc++; break;
        case 0x0e:
            if (vm->current_state == (int16_t)ins.operands[0]) {
                if (ins.operands[1] < fn->code_start || ins.operands[1] >= fn->code_end) return 0;
                pc = (uint32_t)fn->offset + ins.operands[1];
            } else if (!vm_push(vm, ins.operands[0])) return 0;
            else pc += ins.size;
            break;
        case 0x10: vm->state_flags |= 4u; pc++; break;
        case 0x11: vm->state_flags &= (uint16_t)~4u; pc++; break;
        case 0x12:
            if (!vm_pop(vm, &a) || !vm_push(vm, (uint16_t)(vm->current_state == (int16_t)a))) return 0;
            pc++; break;
        case 0x13:
            if (!vm_pop(vm, &a) || !vm_pop(vm, &b) ||
                !vm_push(vm, (uint16_t)(vm->member_states[a & 0xffu] == b))) return 0;
            pc++; break;
        case 0x14:
            if (!vm_pop(vm, &a) || !vm_push(vm, (uint16_t)(a == 0))) return 0;
            pc++; break;
        case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
        case 0x1b: case 0x1c: case 0x1d: case 0x1e: case 0x1f: case 0x20:
        case 0x21: case 0x23: case 0x24: case 0x25: case 0x26:
            if (!vm_pop(vm, &a) || !vm_pop(vm, &b)) return 0;
            switch (ins.opcode) {
            case 0x15: a = a == b; break; case 0x16: a = a != b; break;
            case 0x17: a = a != 0 && b != 0; break; case 0x18: a = a != 0 || b != 0; break;
            case 0x19: a = (uint16_t)((int16_t)a - (int16_t)b); break;
            case 0x1a: a = (uint16_t)((int16_t)a + (int16_t)b); break;
            case 0x1b: if ((int16_t)b == 0) return 0; a = (uint16_t)((int16_t)a / (int16_t)b); break;
            case 0x1c: a = (uint16_t)((int16_t)a * (int16_t)b); break;
            case 0x1d: if ((int16_t)b == 0) return 0; a = (uint16_t)((int16_t)a % (int16_t)b); break;
            case 0x1e: a = (int16_t)a < (int16_t)b; break; case 0x1f: a = (int16_t)a > (int16_t)b; break;
            case 0x20: a = (int16_t)a <= (int16_t)b; break; case 0x21: a = (int16_t)a >= (int16_t)b; break;
            case 0x23: a &= b; break; case 0x24: a |= b; break;
            /* Native uses 16-bit SHL/SAR with the x86 five-bit count.
             * Spell out sign fill without signed-shift UB/implementation dependence. */
            case 0x25: a = (uint16_t)((uint32_t)a << (b & 31u)); break;
            case 0x26: {
                unsigned shift=b & 31u;
                if (shift>=16u) a=(a & 0x8000u)?UINT16_MAX:0;
                else if (shift!=0) {
                    uint32_t fill=(a & 0x8000u)?((uint32_t)UINT16_MAX << (16u-shift)):0;
                    a=(uint16_t)(((uint32_t)a >> shift) | fill);
                }
                break;
            }
            }
            if (!vm_push(vm, a)) return 0;
            pc++; break;
        case 0x22:
            if (!vm_pop(vm, &a) || !vm_push(vm, (uint16_t)-(int16_t)a)) return 0;
            pc++; break;
        case 0x28: case 0x2a: case 0x2c:
            if (!vm_pop(vm, &a)) return 0;
            if (ins.opcode == 0x28) {
                if (vm->stack_size == 0) return 0;
                ll_sool_write_word(vm->locals, (uint8_t)a, vm->stack[vm->stack_size - 1u]);
            } else if (ins.opcode == 0x2a) ll_sool_write_word(vm->locals, (uint8_t)a, (uint16_t)(vm->locals[a & 0xffu] + 1u));
            else ll_sool_write_word(vm->locals, (uint8_t)a, (uint16_t)(vm->locals[a & 0xffu] - 1u));
            pc++; break;
        case 0x29:
            if (vm->stack_size < 3) return 0;
            ll_sool_write_word(vm_data_bank(vm, function_index, vm->stack[vm->stack_size - 2u]),
                               (uint8_t)vm->stack[vm->stack_size - 1u],
                               vm->stack[vm->stack_size - 3u]);
            vm->stack_size -= 2u;
            pc++; break;
        case 0x2b: case 0x2d:
            if (!vm_pop(vm, &a) || !vm_pop(vm, &b)) return 0;
            if (ins.opcode == 0x2b) ll_sool_write_word(vm_data_bank(vm, function_index, b), (uint8_t)a, (uint16_t)(vm_data_bank(vm, function_index, b)[a & 0xffu] + 1u));
            else ll_sool_write_word(vm_data_bank(vm, function_index, b), (uint8_t)a, (uint16_t)(vm_data_bank(vm, function_index, b)[a & 0xffu] - 1u));
            pc++; break;
        case 0x2e: case 0x30:
            if (!vm_pop(vm, &a) || !vm_pop(vm, &b)) return 0;
            ll_sool_write_word(vm->locals, (uint8_t)a, ins.opcode == 0x2e
                ? (uint16_t)(vm->locals[a & 0xffu] + (int16_t)b)
                : (uint16_t)(vm->locals[a & 0xffu] - (int16_t)b));
            pc++; break;
        case 0x2f: case 0x31: {
            uint16_t amount, old;
            if (!vm_pop(vm, &a) || !vm_pop(vm, &b) || !vm_pop(vm, &amount)) return 0;
            old = vm_data_bank(vm, function_index, b)[a & 0xffu];
            ll_sool_write_word(vm_data_bank(vm, function_index, b), (uint8_t)a, ins.opcode == 0x2f
                ? (uint16_t)(old + (int16_t)amount)
                : (uint16_t)(old - (int16_t)amount));
            pc++; break;
        }
        case 0x32:
            vm->state_flags &= (uint16_t)~8u;
            pc++;
            goto suspend_execution;
        case 0x34:
            vm->state_flags = (uint16_t)((vm->state_flags | 1u) & ~8u);
            pc++;
            goto suspend_execution;
        case 0x35: case 0x36:
            if (!vm_pop(vm, &a)) return 0;
            if (a >= program->function_count || a >= 256u) return 0;
            vm->member_disabled[a] = ins.opcode == 0x36;
            vm->member_disable_requested[a] = 1;
            if (a == function_index) {
                vm->state_flags = (uint16_t)((vm->state_flags & ~1u) | vm->member_disabled[a]);
                if (vm->member_disabled[a]) { pc++; goto suspend_execution; }
            }
            pc++; break;
        case 0x37:
            if (!vm_pop(vm, &a)) return 0;
            if (a != UINT16_MAX && a >= fn->state_count) return 0;
            if ((int16_t)a != vm->current_state) {
                vm->pending_function = function_index;
                vm->pending_state = a;
                vm->has_pending_transition = 1;
            }
            pc++; break;
        case 0x38:
            if (!vm_pop(vm, &a) || !vm_pop(vm, &b)) return 0;
            if (a >= program->function_count || a >= 256u ||
                (b != UINT16_MAX && b >= program->functions[a].state_count)) return 0;
            vm->member_states[a] = b;
            vm->member_state_requested[a] = 1;
            pc++; break;
        case 0x39:
            if (!vm_pop(vm, &a) || a >= fn->state_count) return 0;
            /* Native opcode 0x39 calls a state body, saving function and
             * return PC on the operand stack; 0x02 restores that frame. */
            if (return_depth >= 64 || !vm_push(vm, function_index) ||
                !vm_push(vm, (uint16_t)(pc + 1u - fn->offset))) return 0;
            return_ends[return_depth++] = end;
            pc = fn->offset + fn->state_offsets[a];
            end = fn->offset + (a + 1u < fn->state_count ? fn->state_offsets[a + 1u] : fn->code_end);
            break;
        case 0x3a:
            if (!vm_pop(vm, &a) || !vm_pop(vm, &b) ||
                a >= program->function_count || a >= 256 || function_index >= 256 ||
                b >= program->functions[a].state_count || return_depth >= 64) return 0;
            if (!vm_push(vm, function_index) ||
                !vm_push(vm, (uint16_t)(pc + 1u - fn->offset))) return 0;
            return_ends[return_depth++] = end;
            if (a != function_index) {
                memcpy(vm->members[function_index], vm->locals, sizeof(vm->locals));
                memcpy(vm->locals, vm->members[a], sizeof(vm->locals));
            }
            function_index = a;
            fn = &program->functions[a];
            pc = fn->offset + fn->state_offsets[b];
            end = fn->offset + (b + 1u < fn->state_count ? fn->state_offsets[b + 1u] : fn->code_end);
            break;
        case 0x3b:
            if (!vm_pop(vm, &a)) return 0;
            pc++; break;
        default:
            if ((ins.opcode >= 0x3c && ins.opcode <= 0x4a) ||
                (ins.opcode >= 0x50 && ins.opcode <= 0x5e)) {
                if (dispatch == NULL || !dispatch(ins.opcode, vm->stack,
                        &vm->stack_size, sizeof(vm->stack) / sizeof(vm->stack[0]),
                        userdata)) return 0;
                pc++;
                if (vm->host_yield) {
                    vm->host_yield = 0;
                    goto suspend_execution;
                }
            } else {
                /* Member/nested array and state operations need the original
                 * runtime object context; fail closed rather than desync. */
                return 0;
            }
        }
    }
    /* Reaching the budget is a cooperative yield for polling states (several
     * menu states intentionally loop while waiting for a native callback). */
    if (pc < end) goto suspend_execution;
    return pc == end;
suspend_execution:
    vm->resume_pc = pc;
    vm->resume_end = end;
    vm->resume_function = function_index;
    vm->return_depth = return_depth;
    vm->suspended = 1;
    return 1;
}
