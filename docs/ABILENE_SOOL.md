# Abilene SOOL: first native execution stage

## Scope and observed result

The native runtime now loads the original `ABILENE/abilene.cod`, retains its
contexts and executes its bytecode through `sool.c`. It uses a separate,
owned copy of `abilene.bib`; it neither mutates original files nor reuses the
experimental CRC3 `ll_cod_*` parser. The scene's BIZ renderer, player,
collision, animation/movement callbacks and audio are not implemented here.
Model registration is scene **data**, not proof that those objects update or
render like the original game. Unsupported calls stop the affected context;
they are never treated as successful no-ops or variables returning zero.

Against the installed original assets, 24 engine updates produce:

```text
functions=118 condition_streams=13 virtual_tables=40 models=213
calls=246 supported=130 blocked=116 objects=62 static_models=169
projection=804 cell=311 camera_mode=1 speed=128
bounds=[8200,202200,-20000,-3000] word=0 limit=200
```

These numbers describe this bounded startup run, not coverage of every command
in the file. Two contexts finish their supported setup; 116 encounter missing
native commands/variables. No complete gameplay simulation is claimed.

## Reproduction

```sh
./build-linux.sh
./build/linux/abilene-trace /path/ABILENE/abilene.cod /path/ABILENE/abilene.bib 24
```

The tool needs a C compiler at build time, but no display or SDL at runtime.
Each executed host call records engine iteration, owning context, current
function/state, body versus conditions, instruction offset/opcode, command or
variable ID, and real arguments from the operand stack. IDs are not inferred
from filenames or a linear scan. The summary preserves the first failure per
context. Exit3 means missing handlers, exit2 invalid input/arguments, exit0 no
reported blocker during the requested updates. Updates are bounded1..10000;
inputs are limited to64 MiB each. Callers must not equate exit0 with complete
gameplay or completion of a script that can intentionally keep running.

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

## Next native work, from actual blocking calls

| Blocking call | Contexts in this run | Native entry / next dependency |
|---|---:|---|
| command0a | 31 | 418e00/418da0: animation-table preload and expanded frame context |
| command6e | 20 | 418350: sprite/wrapper constructor, distinct from a model |
| command16 | 12 | 410310: per-object behavior flags |
| command39 | 11 | 4121d0: two-lane scene controller |
| command71 | 5 | BIZ sprite construction and rendering |
| command96 | 5 | 41b970: gameplay behavior construction |
| command32 | 1 | 411800: native player/input/HUD controller |
| command66 | 1 | 418920: main player constructor |
| commandc8 | 1 | 4172b0/41eff0: level audio initialization path |
| other commands/variables | 29 | Exact first call, arguments and offsets retained in the trace |

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
quarantine with the unsupported call's stack preserved. The real asset tracer
also verifies the observed startup values and registrations above. Sanitizer
checks use ASan/UBSan; LSan is disabled because ptrace supervision prevents it
from running in this environment. These tests do not establish native visual,
physics or audio equivalence.

Xvfb checks also cover JEU -> Abilene -> Escape -> menu -> Abilene, including
closing/reopening the menu's SDL audio device with the dummy audio driver.
The genuine `image/Abilene.pcx` is a title card, not playable level geometry.
Its presenter is now initialized to the source dimensions (512x256 rather
than640x480); letterbox bands are cleared each frame. The synthetic OpenGL
test `level-background-test` checks a2x1 PCX loaded into an initially64x48
presenter. Run it with `xvfb-run -a env SDL_VIDEODRIVER=x11
build/linux/level-background-test`.
