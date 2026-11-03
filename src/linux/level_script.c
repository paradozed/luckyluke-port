#include "level_script.h"
#include <stdlib.h>
#include <string.h>

static int fail(LL_LevelScript *script, const char *message)
{
    snprintf(script->error,sizeof(script->error),"%s",message);
    return 0;
}

void ll_level_script_close(LL_LevelScript *script)
{
    if (!script) return;
    ll_sool_program_close(&script->program);
    ll_bib_close(&script->bib);
    free(script->contexts);free(script->condition_vm);
    free(script->code_data);free(script->bib_data);
    free(script->model_poses);
    memset(script,0,sizeof(*script));
}

int ll_level_script_open(LL_LevelScript *script,
                          const unsigned char *code, size_t code_size,
                          const unsigned char *bib, size_t bib_size, FILE *trace)
{
    if (!script) return 0;
    memset(script,0,sizeof(*script));
    script->trace=trace;
    if (!code || !code_size || code_size>64u*1024u*1024u)
        return fail(script,"Abilene SOOL input is missing or too large");
    script->code_data=malloc(code_size);
    if (!script->code_data) return fail(script,"cannot allocate Abilene SOOL input");
    memcpy(script->code_data,code,code_size);
    if (!ll_sool_program_open(&script->program,script->code_data,code_size))
        return fail(script,ll_sool_program_error(&script->program));
    if (script->program.function_count>256)
        return fail(script,"level runtime supports at most256 SOOL function banks");
    if (bib) {
        if (!bib_size || bib_size>64u*1024u*1024u) return fail(script,"Abilene BIB input size is invalid (limit64 MiB)");
        script->bib_data=malloc(bib_size);
        if (!script->bib_data) return fail(script,"cannot allocate Abilene BIB input");
        memcpy(script->bib_data,bib,bib_size);
        if (!ll_bib_open(&script->bib,script->bib_data,bib_size))
            return fail(script,ll_bib_error(&script->bib));
        script->model_poses=calloc(script->bib.model_count,sizeof(*script->model_poses));
        if (script->bib.model_count && !script->model_poses)
            return fail(script,"cannot allocate mutable scene-root poses");
        for (unsigned i=0;i<script->bib.model_count;i++)
            memcpy(script->model_poses[i].position,script->bib.models[i].anchor,
                sizeof(script->model_poses[i].position));
    }
    script->contexts=calloc(script->program.function_count,sizeof(*script->contexts));
    script->condition_vm=calloc(1,sizeof(*script->condition_vm));
    if (!script->contexts || !script->condition_vm)
        return fail(script,"cannot allocate persistent Abilene SOOL contexts");
    for (unsigned i=0;i<script->program.function_count;i++) {
        const LL_SoolFunction *fn=&script->program.functions[i];
        LL_LevelScriptContext *context=&script->contexts[i];
        context->state=fn->initial_state;
        context->instance=UINT16_MAX;
        if (fn->initial_state==UINT16_MAX) {
            context->body_done=1;context->vm.state_flags|=2u;
        }
        /* Local words use byte offsets and alias the function's header/data. */
        for (unsigned local=0;local<256 && local+1u<fn->code_start;local++) {
            const unsigned char *p=script->program.data+fn->offset+local;
            context->vm.locals[local]=(uint16_t)(p[0]|((uint16_t)p[1]<<8));
        }
    }
    script->loaded=1;
    return 1;
}

static int command(LL_LevelScript *script, uint16_t id, const uint16_t *args, size_t argc)
{
    LL_LevelNativeSetup *state=&script->native;
#define ARITY(n) do { if (argc!=(n)) return fail(script,"wrong native command arity"); } while (0)
    switch (id) {
    case 0x64: /* FUN_0041a680: retain validated catalogue/grid as scene data.
                * Rendering, relocation into world cells and collisions remain separate. */
        ARITY(2);
        if (!script->bib.valid || args[0]!=script->bib.grid_selector)
            return fail(script,"static scene selector does not match BIB grid");
        script->grid_loaded=1;script->static_model_count=0;
        for (unsigned i=0;i<script->bib.model_count;i++)
            script->static_model_count+=script->bib.models[i].type==0;
        return 1;
    case 0x65: case 0x68: { /* FUN_00418030/00418160: shared vs copied root. */
        ARITY(2);uint32_t offset;
        if (!script->grid_loaded || args[1]>=260 ||
            !ll_bib_get_selector_offset(&script->bib,args[0],&offset))
            return fail(script,"model constructor needs a loaded grid and valid selector/instance");
        unsigned model=0;
        while (model<script->bib.model_count && script->bib.models[model].descriptor_offset!=offset) model++;
        if (model==script->bib.model_count || script->objects[args[1]].present)
            return fail(script,"model descriptor missing or instance already registered");
        LL_LevelScriptObject *object=&script->objects[args[1]];
        object->present=1;object->cloned=id==0x68;object->model_index=model;
        object->private_pose=script->model_poses[model];
        object->pose=object->cloned ? &object->private_pose : &script->model_poses[model];
        script->contexts[script->dispatch_context].instance=args[1];
        script->object_count++;return 1;
    }
    case 0x2e: { /* FUN_00411400 ->00473140 ->00411c90/00411680. */
        ARITY(2);int found=0;
        for (unsigned i=0;i<state->pose_count;i++) if (state->pose_groups[i]==args[0]) found=1;
        uint16_t instance=script->contexts[script->dispatch_context].instance;
        LL_BibScenePose pose;
        if (!found || instance>=260 || !script->objects[instance].present ||
            !ll_bib_get_scene_pose(&script->bib,args[0],args[1],&pose))
            return fail(script,"model pose requires registered group, instance and bounded pose index");
        *script->objects[instance].pose=pose;return 1;
    }
    case 0xb9: /* FUN_00416120/00416040: scheduler/cleanup and camera defaults. */
        ARITY(0);
        memset(state,0,sizeof(*state));
        state->initialized=1;state->callback_capacity=250;
        state->world_cell=0x137;state->depth=6000;
        state->camera_speed=512;state->camera_word=80;
        state->camera_limit=100;
        return 1;
    case 0x36: /* FUN_00411d90: arg4 is consumed but not read. */
        ARITY(3);
        if (!args[1]) return fail(script,"SOOL projection is zero (native division by zero)");
        state->projection_mode=(uint8_t)args[0];
        state->projection=(uint32_t)(int32_t)(int16_t)args[1]&0xffffffu;
        state->reciprocal_projection=0x100000u/state->projection;
        return 1;
    case 0x70: /* FUN_004188d0, spatial cell selector. */
        ARITY(1);state->world_cell=(int16_t)args[0];return 1;
    case 0xe6: /* FUN_00416190: empty path registries, capacities10/10. */
        ARITY(0);state->path_capacity=10;return 1;
    case 0xf0: /* FUN_00416550: empty ten-entry pose-group registry. */
        ARITY(0);state->pose_capacity=10;state->pose_count=0;return 1;
    case 0xf1: { /* FUN_00416590/004730a0: bounded BIB pose registration. */
        ARITY(1);LL_BibSelector selector;
        if (!state->pose_capacity || state->pose_count>=state->pose_capacity ||
            !ll_bib_get_selector(&script->bib,args[0],&selector) || !selector.is_section)
            return fail(script,"pose registry is full/uninitialized or BIB selector is invalid");
        state->pose_groups[state->pose_count++]=args[0];return 1;
    }
    case 0x132: /* FUN_0041c230: configure callback, not camera movement. */
        ARITY(2);
        if (state->camera_lock==1 && args[0]!=10) return 1;
        if (args[0]==10) { state->camera_lock=(uint8_t)args[1];return 1; }
        if (args[0]<=5 || args[0]==6 || args[0]==9) state->camera_mode=(int16_t)args[0];
        if (args[0]<=5) {
            int speed=(int16_t)args[1];
            state->camera_speed=(int16_t)(speed<128?128:speed>1023?1023:speed);
        } else if (args[0]==9) state->camera_speed=(int16_t)args[1];
        return 1;
    case 0x13c: /* FUN_0041cbe0 */
        ARITY(4);
        if (state->camera_lock!=1)
            for (unsigned i=0;i<4;i++) state->camera_bounds[i]=(int16_t)args[i]*100;
        return 1;
    case 0x138: /* FUN_0041ca10 */
        ARITY(1);if (state->camera_lock!=1) state->camera_word=args[0];return 1;
    case 0x13e: { /* FUN_0041cd50 sign extends, then clamps UNSIGNED. */
        ARITY(1);uint32_t limit=(uint32_t)(int32_t)(int16_t)args[0];
        if (state->camera_lock!=1) state->camera_limit=(uint16_t)(limit>200?200:limit<10?10:limit);
        return 1;
    }
    case 0xa1: ARITY(1);state->object_mode=(uint8_t)args[0];return 1; /* FUN_004186f0 */
    case 0x58: ARITY(1);state->player_word=args[0];return 1; /* FUN_004141c0 */
    default:
        return fail(script,"native handler not ported");
    }
#undef ARITY
}

static int dispatch(uint8_t opcode, uint16_t *stack, size_t *size,
                     size_t capacity, void *userdata)
{
    LL_LevelScript *script=userdata;
    LL_SoolVM *vm=script->in_conditions ? script->condition_vm :
        &script->contexts[script->dispatch_context].vm;
    int variable=opcode>=0x50;
    size_t count=opcode-(variable ? 0x4fu : 0x3bu);
    if (!count || count>*size) return fail(script,"native call stack underflow");
    uint16_t id=stack[*size-1u], args[14];
    for (size_t i=0;i+1<count;i++) args[i]=stack[*size-2u-i];
    script->calls++;
    /* Every executed call records its real stack arguments, not guessed IDs
     * from linear disassembly. Unsupported calls leave the stack untouched. */
    int ok=variable ? fail(script,"native variable not ported") : command(script,id,args,count-1);
    if (script->trace || !ok) {
        FILE *out=script->trace ? script->trace : stderr;
        fprintf(out,"%s: ABILENE tick=%u context=%u function=%u state=%u %s pc=+0x%x opcode=0x%02x %s=0x%x args=[",
            ok?"TRACE":"BLOCKED",script->updates,script->dispatch_context,vm->last_function,
            script->contexts[script->dispatch_context].state,
            script->in_conditions?"conditions":"body",vm->last_instruction_offset,opcode,
            variable?"variable":"command",id);
        for (size_t i=0;i+1<count;i++) fprintf(out,"%s%d",i?",":"",(int16_t)args[i]);
        fprintf(out,"] %s%s\n",ok?"supported":"",ok?"":script->error);
    }
    if (!ok) return 0;
    script->supported_calls++;
    *size-=count;
    (void)capacity;
    return 1;
}

static void shared_in(LL_LevelScript *script, LL_SoolVM *vm)
{
    for (unsigned i=0;i<script->program.function_count;i++) {
        memcpy(vm->members[i],script->contexts[i].vm.locals,sizeof(vm->locals));
        vm->member_states[i]=script->contexts[i].state;
        vm->member_disabled[i]=(uint8_t)(script->contexts[i].vm.state_flags&1u);
    }
    memset(vm->member_state_requested,0,sizeof(vm->member_state_requested));
    memset(vm->member_disable_requested,0,sizeof(vm->member_disable_requested));
    vm->has_pending_transition=0;
}

static void set_state(LL_LevelScriptContext *context, uint16_t state)
{
    context->state=state;context->body_done=0;
    context->vm.suspended=0;context->vm.return_depth=0;
    context->vm.stack_size=0;
    context->vm.state_flags&=(uint16_t)~2u;
    if (state==UINT16_MAX) { context->body_done=1;context->vm.state_flags|=2u; }
}

static void shared_out(LL_LevelScript *script, LL_SoolVM *vm, unsigned owner)
{
    for (unsigned i=0;i<script->program.function_count;i++) {
        LL_LevelScriptContext *context=&script->contexts[i];
        if (i!=owner) memcpy(context->vm.locals,vm->members[i],sizeof(vm->locals));
        if (vm->member_disable_requested[i])
            context->vm.state_flags=(uint16_t)((context->vm.state_flags&~1u)|vm->member_disabled[i]);
        if (vm->member_state_requested[i]) {
            context->requested_state=vm->member_states[i];context->state_requested=1;
        }
    }
}

static void blocked(LL_LevelScript *script, unsigned index, LL_SoolVM *vm)
{
    LL_LevelScriptContext *context=&script->contexts[index];
    context->blocked=1;script->blocked_count++;
    snprintf(context->error,sizeof(context->error),"function%u state%u +0x%x opcode0x%02x: %.160s",
        vm->last_function,context->state,vm->last_instruction_offset,vm->last_opcode,
        script->error[0]?script->error:"unsupported/malformed VM instruction");
    if (!script->error[0]) fprintf(script->trace?script->trace:stderr,
        "BLOCKED: ABILENE context%u %s\n",index,context->error);
}

void ll_level_script_update(LL_LevelScript *script)
{
    if (!script || !script->loaded) return;
    script->updates++;
    /* FUN_004219b0: pending states are applied at the next engine iteration,
     * then bodies, then separate conditions. No unbounded startup chaining. */
    for (unsigned i=0;i<script->program.function_count;i++) {
        LL_SoolVM *vm=&script->contexts[i].vm;
        if (vm->has_pending_transition) {
            uint16_t target=vm->pending_function,state=vm->pending_state;
            vm->has_pending_transition=0;
            if (target<script->program.function_count &&
                (state==UINT16_MAX || state<script->program.functions[target].state_count)) {
                script->contexts[target].requested_state=state;
                script->contexts[target].state_requested=1;
            }
            else { script->error[0]=0;blocked(script,i,vm); }
        }
    }
    for (unsigned i=0;i<script->program.function_count;i++)
        if (script->contexts[i].state_requested) {
            set_state(&script->contexts[i],script->contexts[i].requested_state);
            script->contexts[i].state_requested=0;
        }
    for (unsigned phase=0;phase<2;phase++)
        for (unsigned i=0;i<script->program.function_count;i++) {
            LL_LevelScriptContext *context=&script->contexts[i];
            const LL_SoolFunction *fn=&script->program.functions[i];
            if (context->blocked || (context->vm.state_flags&1u)) continue;
            if ((!phase && context->body_done) || (phase && fn->conditions_start==UINT16_MAX)) continue;
            script->in_conditions=(int)phase;script->dispatch_context=(uint16_t)i;
            LL_SoolVM *vm=&context->vm;
            if (phase) {
                memcpy(script->condition_vm,vm,sizeof(*vm));vm=script->condition_vm;
                vm->stack_size=0;vm->suspended=0;vm->return_depth=0;
            }
            shared_in(script,vm);vm->current_state=(int16_t)context->state;
            script->error[0]=0;
            int ok=phase ? ll_sool_execute_conditions(&script->program,(uint16_t)i,vm,dispatch,script) :
                ll_sool_execute_state(&script->program,(uint16_t)i,context->state,vm,dispatch,script);
            if (phase) {
                memcpy(context->vm.locals,vm->locals,sizeof(vm->locals));
                if (vm->has_pending_transition) {
                    context->vm.has_pending_transition=1;
                    context->vm.pending_function=vm->pending_function;
                    context->vm.pending_state=vm->pending_state;
                }
            }
            shared_out(script,vm,i);
            if (!ok) { blocked(script,i,vm);continue; }
            if (!phase) {
                context->body_done=!vm->suspended;
                if (context->body_done) context->vm.state_flags|=2u;
            }
        }
}

void ll_level_script_report(const LL_LevelScript *script, FILE *out)
{
    if (!script || !out) return;
    fprintf(out,"ABILENE SOOL: loaded=%d functions=%u updates=%u calls=%u supported=%u blocked=%u objects=%u static_models=%u\n",
        script->loaded,script->program.function_count,script->updates,script->calls,
        script->supported_calls,script->blocked_count,script->object_count,script->static_model_count);
    for (unsigned i=0;script->contexts && i<script->program.function_count;i++)
        if (script->contexts[i].blocked) fprintf(out,"  context%u %s\n",i,script->contexts[i].error);
}
