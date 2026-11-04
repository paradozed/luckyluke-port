# Abilene SOOL: native execution progress

## Scope and observed result

The native runtime loads the original `ABILENE/abilene.cod`, retains its
contexts and executes its bytecode through `sool.c`. It owns copies of the
original BIB and BIZ resources; it neither mutates game files nor reuses the
experimental CRC3 `ll_cod_*` parser. Static/model and sprite constructors now
retain bounded scene records, and skeletal animation schedules frames and
completion waits. They do not yet deform model vertices or draw level objects.
Player control, collision callbacks, projectile logic and level audio remain
incomplete. Unsupported calls stop the affected context; they are never
treated as successful no-ops or variables returning zero.

Against the installed original COD/BIB/BIZ assets, the bounded tracer produces:

```text
24 updates:  calls=1437 supported=1394 blocked_contexts=43 objects=88 static_models=169
240 updates: calls=8913 supported=8862 blocked_contexts=51 objects=88 static_models=169
directory: functions=118 condition_streams=13 virtual_tables=40 models=213
projection=804 cell=311 camera_mode=1 speed=128
bounds=[8200,202200,-20000,-3000] word=0 limit=200
```

The 24-update run recognizes 1264 more host calls than the initial stage (130)
and registers 26 additional objects. At 240 updates, animation callbacks let
more bodies resume, so later failures become reachable and the blocked-context
count rises to51. These counts are not full-file handler
coverage or proof of gameplay equivalence.

## Reproduction

```sh
./build-linux.sh
./build/linux/abilene-trace /path/ABILENE/abilene.cod /path/ABILENE/abilene.bib /path/ABILENE/abilene.biz 24
```

The tool needs a C compiler at build time, but no display or SDL at runtime.
Each executed host call records engine iteration, owning context, current
function/state, body versus conditions, instruction offset/opcode, command or
variable ID, and real arguments from the operand stack. IDs are not inferred
from filenames or a linear scan. The summary preserves the first failure per
context. Exit3 means missing handlers, exit2 invalid input/arguments, exit0 no
reported blocker during the requested updates. Updates are bounded1..10000;
inputs are limited to64 MiB each. BIZ is optional; supply it after the update
count or before the count to enable checked sprite constructors. Callers must
not equate exit0 with complete gameplay or completion of a script that can
intentionally keep running.

In the game, `LL_TRACE_LEVEL_SOOL=1` includes supported calls on stderr;
blocking calls always appear. Select JEU/GAME with Enter. The original menu
issues `0x12(2)` (`FUN_00410250`), which previously had no host effect.
The host now defers that request until the menu VM returns, stops menu audio,
and opens Abilene. Escape destroys the level contexts and reinitializes the
menu; entering again starts from fresh script data. The procedural platformer
is not used as a substitute. If no genuine level background can be loaded,
the diagnostic screen has a plain background, not an invented level scene.

## Format and execution fixes

Function header+12 marks the end of state code, not the complete function
allocation. For example, Abilene function5 has code_end216, conditions at216
and a full directory span227. Function4 has code_end552 and a virtual table
at552, ending556. The parser now bounds the complete span by the next function
offset (or EOF), validates state code separately, and checks conditions and
four-byte virtual pairs without crossing function boundaries. Virtual tables
are retained and validated; their full dispatch semantics are not added here.

`FUN_004219b0` schedules pending states, bounded body bursts and a separate
conditions phase. The level runtime follows that order, sharing byte-addressed
local/member data between contexts. Conditions use a scratch VM so their
operand stack and PC cannot overwrite a suspended body. State changes replace
continuations on the next engine iteration. A context with initial_stateFFFF
has a finished body (native flag2), not a disabled context (flag1); its
conditions can request its first state. A missing handler quarantines the
context without retrying it each frame, while other contexts still execute.

`FUN_00422dc0` clears the target's burst flag for effective state requests
(opcodes37/38). Self-state requests now yield immediately instead of executing
the old body's following instructions. Remote requests are deferred to the
next engine iteration by the level scheduler. Conditions are bounded rather
than permitted to loop indefinitely. Wider virtual/cross-function ownership
semantics are not claimed as completely recovered.

## Implemented setup contracts

Verified from the existing Ghidra exports and focused `objdump` reads of
unchanged `orig/Game.run`; REA MCP was unavailable. No original Windows
execution was observed in this stage.

| ID | Original handler | Contract represented in the port |
|---|---|---|
| b9 | 416120,452fa0,416040 | Owned level lifecycle, scheduler capacity250 and initial camera/setup values; not all native engine callbacks |
| 36 | 411d90 | Consume3 args `(1,804,384)`, projection804 from arg3, low-byte mode, reciprocal; reject zero |
| 70 | 4188d0 | Retain signed world-cell selector311; world-cell relocation/render dispatch remains absent |
| e6 | 416190 | Empty path-registry capacity10; attaching/running paths remains unsupported |
| f0/f1 | 416550,416590,4730a0 | Ten-entry pose-group registry, validated BIB selectors91/92 |
| 132 | 41c230 | Camera callback mode, lock, signed speed clamp128..1023; no camera-follow update yet |
| 13c/138/13e | 41cbe0,41ca10,41cd50 | Signed bounds times100, camera word, unsigned clamp10..200 after sign extension (`-1 ->200`) |
| a1/58 | 4186f0,4141c0 | Low-byte object mode / player word |
| 64 | 41a680 | Validate grid selector54 and retain static catalogue; no spatial rebasing, collision or draw callbacks |
| 65/68 | 418030,418160 | Validate model/instance binding; shared descriptor-root pose versus independent cloned root pose |
| 2e | 411400,473140 | Resolve registered pose group/index and assign position/angles to the bound root |

Static geometry stays immutable. Cloned instances share immutable geometry
but own their mutable root poses, so moving a clone cannot overwrite its source.
Further descriptor fields are not accepted until their handlers are ported.

Follow-on handlers now cover `0x6e/0x71` sprite wrapper setup from BIB frame
zero and validated BIZ records; `0x45` wrapper registry slots; `0x5b` and
variable `0x38` shared event flags; command/variable `0x2a`; variables `0x0b`
(shared subtractive RNG), `0x44`, and `0x26` signed inclusive AABB overlap.
Command `0x66` registers Abilene's bounded `LUCKY3DK` player model root at
instance4; movement and player update callbacks are still absent. Command
`0x15` releases the current model's active animation data. Variable `0x00`
returns its input word; variable `0x36` compares and consumes the collision
event latch, matching the boolean behavior of the related native handler.
Command `0x7a` records the native skeletal child/parent attachment and blend
parameters for Abilene's zero-root-offset calls. Vertex blending and the native
attachment update callback are still absent.
`0x72` accepts the observed idempotent callback-enable requests for already
registered model wrappers (instances28 and29); callback state transitions
remain blocked because they register/reset native engine dispatch. Command
`0xf5` now stores the native three-slot collision links per SOOL context,
including target context, callback mode and recognized flags. Its collision
callbacks are not dispatched yet, so contact response and gameplay effects
remain absent.
Variable `0x64` compares two wrapper bounds with inclusive AABB semantics;
mode0 uses descriptor bounds and mode1 scans the original BIB geometry vertex
range used by the native handler, then translates by each wrapper root.
World-sprite wrappers retain the clipped BIZ texture rectangle with the native
scale and Abilene's 640/512 horizontal projection factor. Variable `0x66`
compares these sprite bounds against a target wrapper using the same inclusive
AABB test; unsupported sprite-wrapper modes still stop their context.
`0x11e` resolves a bounded BIB pose and retains its three position coordinates
as the native camera target; a failed native lookup preserves the previous
target. The camera-follow callback that consumes this target is still absent.
Command `0x32` retains the scene-sprite manager's capacity16 and clears its five
native sprite slots; registration is modeled, while the manager's update/draw
callback has not been ported.
`0x6b` advances bounded BIB sprite-frame/BIZ object metadata. Commands
`0x0b/0x14/0x1b` schedule bounded model animation ranges on the native 60 Hz
clock, yield waiting contexts, advance frame metadata and resume owners
through completion callbacks. Nonzero loop root displacement is rejected.
Pose interpolation, transition blending,
skeletal vertex application and sprite rendering remain unimplemented;
bounded BIB sprite sequences update metadata but are not drawn.

## Next native work, from actual blocking calls

| Blocking call | Contexts in this run | Native entry / next dependency |
|---|---:|---|
| command39 | 11 | 4121d0: orbital sprite group and native update/draw callbacks |
| variable17 / command96 | 7 / 5 | 409500 position comparison / 41b970 pose-driven sprite groups |
| variable8e | 3 | Event and collision/projectile state |
| variable39/99, command e8 | 2 / 2 / 1 | Model callback state and projectile trajectory setup |
| variable7 / variablec | 2 / 2 | Native controller state and event query |
| other calls | 8 | Level audio, camera/player callbacks and object setup |

The ordering is a practical dependency guide, not a claim that implementing
only these calls will complete the level. Later calls remain unreachable until
their earlier blockers are implemented. In particular, don't reuse menu
fallbacks for gameplay variables or confuse BIZ texture tiles with collision.

## Validation

The strict build runs `level-script-test` in addition to the existing suites.
Synthetic tests cover owned inputs, next-function/trailing-table bounds,
condition branches outside state code, separate body continuation/stack,
condition-only startup, cross-context writes, next-tick state requests,
immediate self-transition yields, exact negative clamp behavior and one-time
quarantine with the unsupported call's stack preserved, plus native variable
return-stack behavior and shared-flag side effects. The real asset tracer also
verifies the observed startup values and registrations above. A 240-update
original COD/BIB/BIZ run passed ASan/UBSan (LSan disabled because ptrace
supervision prevents LSan in this environment). These tests do not establish
native visual, physics or audio equivalence.

Xvfb checks also cover JEU -> Abilene -> Escape -> menu -> Abilene, including
closing/reopening the menu's SDL audio device with the dummy audio driver.
The genuine `image/Abilene.pcx` is a title card, not playable level geometry.
Its presenter is now initialized to the source dimensions (512x256 rather
than640x480); letterbox bands are cleared each frame. The synthetic OpenGL
test `level-background-test` checks a2x1 PCX loaded into an initially64x48
presenter. Run it with `xvfb-run -a env SDL_VIDEODRIVER=x11
build/linux/level-background-test`.
