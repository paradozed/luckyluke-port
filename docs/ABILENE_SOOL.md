# Abilene SOOL: native execution progress

## Current dependencies

The runtime retains sprite-group member positions, local bounds and contact
state. Variable `0x28` now tests those members against the registered player;
no-hit and hide-on-hit behavior are supported, while configured hit animations
still fail explicitly. Commands `0x74` and `0x6b` schedule bounded sprite
sequences; completion of `0x74` releases primitive state and resumes its owner.

Path selector90 is decoded without relocating asset bytes. Its segment and
link tables validate, and native integer projection selects segment37,
distance3500, anchor[14874,0,7326], yaw1024 and pitch0 at startup. Command
`0xe8` now attaches the model and registers its per-tick positional constraint.
The callback applies obstacle tests, linked junction/floor selection, projection
and vertical response. The controller now supplies native ground and air motion
and logical input. Initial camera placement/transition and normal follow execute;
Ordinary model collision, support and push/block responses now execute;
Automatic walk/run path segments and BA spring-box launches also execute;
other controller entries and advanced camera recovery remain unported.

Screen sprites, static type0 models and registered visible type1 model instances
are connected to OpenGL using original BIZ textures. The scene renderer uses
the native fixed-point view/root transforms, original triangle/quad indices,
UV coordinates and packed colors. Skeletal meshes use the same native part
matrix evaluator as the menu, now factored into `native_animation.c`.
Per-instance caches keep cloned meshes independent and are freed on level exit.
Animation frames include their 16-bit interpolation fraction and explicit next
frame, keeping bounded loops inside their selected range. Animation release
preserves the last pose and clears part1 translation as in
`FUN_004851b0/00485230`.

`FUN_00483e30` copies only min(animation part count, model part count) expanded
records. Remaining model parts start with zero channels. This fixes the shorter
animations of `DYNAMI013DK` and `GOUTIERE3DK`; they must not be rejected just
because their mesh has more parts. The source evidence is the local original
executable's exported functions `483e30__FUN_00483e30.c`,
`4851b0__FUN_004851b0.c` and `485230__FUN_00485230.c`. These are static reverse
engineering observations, not an original Windows runtime comparison.

An X11 capture at `build/abilene-skeletal-scene.jpg` shows Lucky Luke and Jolly
Jumper alongside the original ground, fences, wagon, tower and buildings.
The ground controller starts Lucky's idle animation193, walk197 and run198.
Jolly Jumper and several other instances also change skeletal vertices across
native animation frames. The graphical probe covers menu Enter ->
Abilene -> Escape -> menu -> Enter -> Abilene, with four seconds allowed for
menu startup on re-entry and no skeleton/material errors in the log.
Sprite78 starts entirely above the viewport; its coordinates are preserved.

Sprite groups, other skeletal attachment modes, transition blending between different
level animations and native cell selection/rebasing remain incomplete.
Parts omitted by a later shorter animation currently use zero channels rather
than retaining a previous longer animation's part channels. No original Windows
capture was obtained for comparison; this demonstrates original asset rendering,
not visual parity or playable control.

## Reverse animations, frame queries and extracted movement

Command05 now follows `FUN_00419930 ->004850b0`: it starts at the table's last
frame, runs backwards toward0 with native mode bytes[1,1], and does not yield
the calling context. Command1B forces its initial cursor to0 before850b0,
so repeating that call restarts the animation even when its selector is unchanged.
Waiting commands0B/14 keep their completion owner and bounded range behavior.
Transitions blending the previous expanded pose into a new animation are still
unported; a new animation currently starts directly at its requested first pose.

Variables73/74 inspect the animation buffer's next-frame cursor at+32, rather
than the currently displayed frame. Original x86 in0040e450 confirms73 returns
that word. Original0040e4c0 confirms74 compares it with the configured terminal
frame for forward playback, or0 for reverse playback, and returns1 when the
animation buffer is absent. Thus74 can become true during the interval blending
into the terminal pose. An invalid73 query with no buffer is explicitly rejected.
Abilene context23 now starts reversed animation124 at update15, polls74, releases
it at update18 and continues to state3, instead of stopping on command05.

Ordinary script-driven skeletal wrappers now extract part1 movement into their
world root as in00480a40/00480c10. `00484db0` chooses X when the loop's X offset
is nonzero, otherwise Z when its Z offset is nonzero, otherwise Y. The selected
local delta is narrowed to signed16, rotated through the model's native matrix,
then added to the world position. The consumed translation channel is zeroed
in the rendered skeleton; the other part1 axes remain local to the mesh.
These deltas run before ordinary path constraints. Player kinematics keep their
separate controller path; the inspected ordinary player trajectories have zero
part1 movement. Attached models use487070 instead: the same selected delta is
rotated through the captured attachment matrix and added to its deferred local
offset. The ordinary world-root extraction is skipped, matching the native C8 guard.

`004845e0` corrects part1 translation while interpolating the wrap interval:
forward playback adds the three loop offsets to the destination pose; reverse
playback subtracts them. Runtime references include complete loop displacements
so the next first-frame pose does not pull the object back to its initial root.
Bounds, signed shifts and16/32-bit wrapping are retained. Animation153 has loop
offset[0,0,-2582]; the `ABHERB013DK` decor models in contexts36/37 now roll through
their original scripts rather than stopping on that offset. Their following
variable96 call is also ported from0041f020: signed distance gain and scale,
including the original unscaled peak return outside the radius. Its sign and
boundary behavior differ from variable97's unsigned linear attenuation.

Synthetic tests cover forward/reverse seams, extracted mesh channels, rotated
world deltas, multiple complete cycles, callback disable/re-enable, reverse
cursor queries, absent buffers and positive/negative variable96 ramps. A real
960-update ASan/UBSan probe performs56002 skeletal evaluations with no failures,
including the hidden enemy's reverse poses. It observes four reverse-update
intervals and1763 animation153 intervals across the two decor contexts; all
three contexts23/36/37 remain unblocked. The real240-update run now has6 blocked
contexts, compared with9 at the preceding audio stage. X11 checks cover left
running, firing, jumping and Escape with no model/material errors; captures are
`build/abilene-motion-scene.jpg` and `build/abilene-motion-jump.jpg`.
This establishes the port's data flow and observed behavior; original Windows
runtime comparison and full callback-registration-order parity remain unverified.

## Native ground controller

SOOL command66 registers the ordinary variant0 controller from its original
wrapper callback `FUN_004662e0`. `LL_LevelPlayer` now retains its ground state,
heading, speed, accumulated displacement, input words and idle-animation state.
The main loop polls the same configured keyboard profile used by the menu,
converts it to native held/pressed action masks and supplies it through
`ll_level_script_set_input`; no SDL dependency is added to the script runtime.
Opposing directions cancel and the original controller restriction flags mask
both held and pressed inputs.

The callback runs after SOOL for the registered player, and applies the path
constraint itself instead of constraining that player twice. Source evidence:

- `4662e0`, `4669f0`, `466900`: callback dispatch, startup and idle bounds.
- `466cf0`, `466f10`: walking event4 and running event5, relative to BIB base193.
- `4696b0`, `469410`, `46c310`: path-facing and endpoint junction decisions;
  original x86 confirms the return values omitted by Ghidra.
- `46a6e0`, constants at `004bdf00/08/10`: target speeds0/23/66 and acceleration
  13/10/10, using `projection_mode+1` substeps. With mode1, the first walking
  displacement is30, then46 at steady speed; running reaches132 per callback.
- `46a260`: separately rounded sine/cosine products and path-pitch compression,
  followed by the existing native path update and its heading tables.
- `466570`: idle variations after600 native60-Hz steps, at animation completion.
  Their associated original bank samples and pitch offsets are now played.

A real-asset ASan/UBSan probe starts at[14874,0,7326], walks to[15962,0,7326]
over24 updates, runs to[19058,0,7326] over another24, decelerates on release,
and reverses toward the left using the same event4 animation. A longer run
crosses native segments37 ->49 ->74 ->75 ->77 ->50 ->51 without a path failure.
The X11 keyboard probe observes right walking, left running, release and return
to the menu. Captures: `build/abilene-player-walk.jpg` and
`build/abilene-player-run.jpg`.

Default keyboard profileA uses the arrow keys for direction, C for speed and
G for jump, B for fire, Down for crouch and V for planting dynamite; menu keyboard
preferences remain effective. Unsupported controller branches explicitly quarantine
the player callback once and freeze its last pose. Escape and re-entering the
level creates a fresh controller. This is partial native movement, not complete
playable-level parity: other skeletal attachment interactions, combat and the remaining
controller states still need porting. The tracer exits3 if that callback is
quarantined, even if no SOOL context itself is blocked.

## Native ground shooting and projectile pool

The native command registry in `FUN_004145c0` binds command40 to00412c80.
Abilene context7 calls it with[105,104]: selector105 is the single-frame ball
(BIZ520), selector104 the13-frame effect (BIZ507..519). Command122 instead
maps to00415a60 and constructs the background manager described below.
The pool owns ten private ball descriptors
and ten independent effect descriptors, outside the script wrapper table.
Every referenced frame/BIZ sprite is checked before publishing the pool.

The ground controller now enters467f60 ->4682f0 ->468160 from idle/walk/run.
It consumes a pending shot before choosing the next aim; an event change sets
the pending flag for the next controller callback. Callback468130 rearms that
flag on animation completion, rather than using an arbitrary firing timer.
The six events7..12 select Abilene animations200..205. Releasing fire enters
event14/animation207, whose completion returns to idle. Directional movement
can interrupt that holstering, and a new jump press while aiming enters the
native moving jump with impulse-155.

Tables at004bdf9c/004bdfb0 and004bdfd8/004be000 choose the animation and Z angle
for all eight directions plus no direction, separately for each half of the
native matrix-derived yaw. Aiming preserves Lucky's root heading. Events11/12
use the original shortened bounds (base minimumY+800). `0046c610` rotates the
six muzzle offsets at004be0c0 by the current root yaw, then calls00476b40 with
the previously selected aim yaw/angle. Velocities retain native signed shifts:
X=cos(yaw-1024)*cos(angle)>>16, Z=sin(yaw-1024)*cos(angle)>>16,
Y=-sin(angle)>>4. A full ball pool does not evict a shot; a free effect can
still be allocated independently.

`00476680` moves each ball once per engine update, with fixed local bounds
[-30,-30,-60,30,30,60]. Its type2 branch scans wrapper slots0..249 in order,
checks flag4 and inclusive translated AABBs, retires the first contacting ball,
sets the wrapper's hit bit1 and publishes its instance in collision_event_latch
(consumed by variable36). The hit slot is retained. The controlled player-shot
replay below now verifies enemy24's script reaction; broader enemy combat
remains incomplete. The enemy-projectile/player branch is described below.
After the first movement, balls retire outside the previous projected vertex0's
640x480 viewport or worldZ[-3000,20000]. Abilene registers the player in context4
before the pool in context7, so a new ball moves in its creation update.

Sprite sequences use animation_clock>>5 and advance only when elapsed exceeds
the frame duration, including the last frame. An effect's completion clears
activity once, while its current draw still presents the last frame. Balls
keep looping. The world renderer uses the native scale4, frame offsets,
one-pixel texture margins, 16-bit rectangle quantization, 640/512 horizontal
scale and camera-facing basis diag[4096,2944,4096] from004810e0. The root is
transformed by the scene camera before applying that billboard basis. The same
geometry feeds headless clipping and the OpenGL renderer.

Regressions cover delayed fire, callback cadence, all18 aim choices, muzzle
origin/velocity, holstering, shooting-to-jump, independent pool exhaustion,
inclusive impact/latch, first-frame clipping, quad vertices and strict final
frame timing. A real COD/BIB/BIZ ASan/UBSan probe evaluates every player pose
while exercising all18 choices, recycles34 balls without player/camera quarantine,
then verifies holstering207, jumping208 and returning193. X11 captures show
right/diagonal/left firing, a jump and Escape back to the menu:
`build/abilene-shooting-right.jpg`, `build/abilene-shooting-diagonal.jpg`,
`build/abilene-shooting-left.jpg`, `build/abilene-shooting-jump.jpg`.
The revolver now plays its original `GunShoo3` sample through the native audio
bank below. Original Windows runtime comparison and full combat parity remain
unverified/unported; no replacement health or damage rules are invented.

## Enemy projectiles and player impact

Variables33/34/35 now follow `0040b760/0040b980/0040b9e0` and the type1 branch
of `004761e0`. Variable33 consumes[shooter,part,unused,target_count], reads the
part's animated pivot, adds its root and allocates a type1 ball and independent
flash from the existing pools. The third argument is genuinely unread by the
original handler. `0047ec50` maps expanded part+10 to the BIB pivot vertex.
Rendering and muzzle lookup share `ll_level_script_model_vertices`, including
retained/released poses and extracted root channels. The local pivot is rotated
through the root before world translation. Full equivalence to the original
combined root/part matrix rounding remains unverified.

Variable34 sets one of five target IDs, without requiring the target to exist
yet, and returns1. Target entries persist when a slot is reused. Variable35
compares and consumes a separate enemy-ball contact latch, distinct from36's
player-shot latch. The enemy branch scans configured targets in order, accepts
wrapper flags4 or2 and uses inclusive translated bounds. Ordinary targets gain
hit bit1 and decrement the ball's target count. A player target invokes the
native damage mode1/amount1. Ball exhaustion returns0, as the original does,
even though0 also names the first valid slot; no active ball is evicted.

Variable39 (`0040be10`) tests a selected pool ball against a BIB world box.
A hit decrements its target-count word, clears its active flags and returns1;
a missing box or separated bounds returns0. The original does not test whether
the ball is active before reading its retained root. This includes the unsigned
count wrap when querying an inactive ball with count0. No impact latch is set.
Contexts18/20 now poll their original boxes instead of stopping on this query.
Focused x86 reads confirm the word returns of34/35/39 that Ghidra omitted.

`00468c20(1,1)` accepts a hit only when no hurt callback is pending and the
player's death flag is clear. Health starts at3 and progresses through2,1,0;
the fourth accepted hit resets health to3, decrements the initial five lives
and sets global death bit1 and player payload bit100. Variable44 returns the
raw health word, including0. Level cleanup resets health while retaining lives,
the health dirty byte and the invincibility preference. Invincibility suppresses
the health decrement but still schedules the hurt response, as in the binary.

On the following player callback, `00469020` plays bank sample1 at pitch-100,
volume8191, pan1024 and schedules `00468d80`. Blinking starts one callback later,
using bit8 of the original60 Hz clock. It expires when elapsed time reaches121;
queued and blinking responses both reject further damage. Normal movement,
jumping and shooting continue; no invented recoil is applied. The fourth-hit
counters feed the original death/recovery sequence described below.
Script damage variable23 now shares this native entry, as described below.
Other grounded reaction modes, pickups, HUD drawing and broader enemy combat
remain unported/unverified.

Synthetic regressions cover animated/rotated muzzle placement, target setup and
separate latches, inclusive box edges, inactive queries, count wrap, delayed
audio/blink, immunity expiry, health0, four hits/life loss and cleanup preservation.
An optional real-asset test replays context23/state5 with the player relocated
and its controller/camera disabled. The unchanged script runs animation126,
creates a targeted ball at tick55 and produces a player impact with health2,
lives5 and the pending hurt callback. ASan/UBSan pass this replay. It verifies
the original COD/BIB/BIZ data flow in the port, not a natural playthrough or
execution of the original Windows game. X11 checks also cover movement, firing,
jumping and returning to the menu with the shared pose evaluator.

## Script damage and enemy reactions

Variable23 (`0040ac50 ->00468c20`) now reaches the same native damage entry as
enemy balls. A bounded scan of the installed Abilene COD finds11 sites, in
contexts6,29,30,31(twice),32(twice),63,65,67(twice). Every site passes[1,1]
(reaction mode1, signed damage amount1) and immediately discards the result.
Previously these contact and hazard branches stopped at an unported variable.

The shared entry first rejects damage while a hurt callback is pending/active
or payload bit100 marks death. Otherwise it subtracts the signed amount with
word wrapping, marks health dirty unless invincible, and applies the original
negative-health reset/life debit/death flags. Zero and negative amounts retain
the binary's behavior; no new clamp or damage rule is substituted. A nonzero
reaction requested in the air becomes mode1. Grounded modes2..4 still stop
explicitly before mutation because their alternate controller sequences are
unported. Mode0 uses00468e30's quiet immunity until elapsed60-Hz ticks exceed120:
it preserves visibility and does not queue a cry or set the blink flag.
Mode1 keeps the existing69020 ->68d80 cry/blink and121-tick protection.

Original x86 defines only AL on return from468c20; AH can retain health or
allocator-address bits. The SOOL wrapper returns AX without normalizing it.
The port therefore accepts variable23 only when its next instruction in the
same execution stream is POP. It does not publish an invented observable
full-word result. A consumer or a POP across a state/body-condition boundary
stops explicitly before changing health. This covers all11 Abilene sites;
broader byte-return ABI emulation remains unported.

The real-asset replay now checks both directions of combat. Lucky is placed
on a valid native path anchor2000 units before enemy24; a normal rightward
movement input establishes his heading, then the ordinary fire input creates
one revolver ball. That ball contacts at update125, its latch is consumed by
the unchanged enemy script, animation122 runs and context24 reaches state4.
No hit latch, enemy health counter or replacement defeat rule is injected.
The player relocation and disabled camera/clipping isolate this controlled
test; it does not demonstrate traversal from level startup.

A second replay holds enemy31's original bounds at Lucky's root, disables its
F5 physical separation to isolate repeated damage requests, and requests
its original attack state3. At update123 the script's variable23 call reduces
health3 ->2 and the ordinary player callback starts the hurt cry. During40
updates,27 script damage calls leave health2/lives5 while the native blink
runs. Neither its context nor the player/camera callback is quarantined.
Synthetic tests additionally cover signed/zero amounts, invincibility, pending
and dead-player rejection, airborne reaction coercion, unsupported grounded
reactions without partial mutation, the AX guard and quiet immunity expiry.
Strict builds and ASan/UBSan pass these tests plus camera, pause and the
existing death/checkpoint recovery replay.

A temporary graphical harness at the script-damage stage, using original resources,
performs the controlled enemy31 placement, then removes that contact. Its log
records one health loss at tick123; Lucky blinks and normal movement/firing
remain available afterward. Captures are `build/abilene-contact-hurt.png`,
`build/abilene-contact-blink.png`, `build/abilene-contact-recovered.png` and
`build/abilene-contact-menu.png`. No replay injection is added to production
code or asset files. Original Windows runtime comparison, remaining enemy
attack branches, skeletal attachment interactions and full combat parity remain
unverified/unported.

## Death scene and checkpoint recovery

The ordinary player controller no longer quarantines solely on payload bit100.
`00469ef0` continues its ordinary callbacks while SOOL contexts15/16 own the
death sequence. A path death, unlike a lethal bullet already accounted by68c20,
resets health to3, consumes one life and sets global bit1 once. Its sample2,
pitch-450, volume8191 and center pan are called directly even when the effects
preference is off, matching the native driver call. The global bit prevents a
second debit on later callbacks.

Context15 observes variable38 and requests context16/state1. That unchanged
state disables pause availability (command4D), restricts player actions, fades
out, stages a clone of Lucky at instance16, plays original animations113/195,
then fades out again and executes command48(0). No death timer or replacement
animation is added outside the script. Command10E and variable4C now implement
`00415080 ->00440f30/70/00440fb0/004411c0`: reveal starts at255, darken at0,
alpha advances by8 and clamps on the32nd update. The query returns a full word
0/1, confirmed in0040c8b0's x86. OpenGL composites the resulting black fade
after the scene. The port currently drives this callback on its24 Hz level
clock; original presentation-cadence parity remains unverified.

Command48 follows `00413580 ->00457740/00452f50` for normal remaining lives:
clear death/dynamite event flags, project the stored command11E checkpoint onto
the native path, preserve its incomingY, set the selected segment/distance and
orientation, restore ground state and the camera's vertical mode/dead lock,
then restore visibility for registered HUD slots0/3/4/1. It preserves unrelated
player flags, movement callbacks and the existing health/life values. The
script restores its camera, input masks, pause availability and effects gains.
No resource reload, artificial health refill or fresh player is substituted.
Command12D controls the original background-manager enable byte; both its
animation callback and drawing stop while disabled. D5 records CD pause state; CD track playback
remains unported and its startup commandD3 still stops explicitly.

Death-scene audio uses commandDA (`00417530/0041fcd0`) to mark its voice as
group4. Global effects muteCA and later volume/pan edits preserve that group's
audible gains, while ordinary voices keep advancing silently. DA only changes
the group byte. Native playback calculates initial gains using the selected
circular pool slot's previous group, then resets that byte to0; the port
retains this ordering, including reuse of a stopped group4 slot.

Variable27 (`0040adb0`) now removes the first occupied scene-sprite slot. The
argument's root is dereferenced but never compared with that list, and the
original x86 returns AX=0 even on successful removal. This allows context78's
death-scene cleanup to run. Registration/drawing of the broader HUD manager
remains incomplete. Command4C, still blocked at startup in context14, actually
initializes pause/quit interface PCX resources in00413780; its five arguments
are unused by that Windows handler. It is distinct from the fade variable4C.

Synthetic tests cover32-step fades, query timing, group4 mute/edit/reuse,
ordinary path-death accounting, checkpoint flag preservation, HUD visibility,
missing anchors, zero remaining lives and first-slot removal. The optional
real COD/BIB/BIZ test replays a fatal bullet, observes both clone animations,
101 dark-frame intervals,197 clone intervals and51 audible muted-scene voice
intervals, and reaches recovery at update298. It verifies checkpoint segment,
distance/root, completed fade-in and resumed movement. ASan/UBSan pass this
controlled replay. X11 captures from a temporary fatal-projectile harness show
the darkening, clone scene and restored level, followed by movement/fire and
Escape: `build/abilene-death-darkening.jpg`, `build/abilene-death-clone.jpg`,
`build/abilene-death-recovered.jpg`, `build/abilene-death-resumed-input.jpg`.
The harness leaves production inputs and original assets unchanged.

The last-life branch of48 still reports the missing original game-over scene
instead of granting more lives. Context13 now executes its camera calls as
described below. The death scene sets the dead-camera lock before requesting
context13/state9, so that state's absolute camera setters are ignored by the
original guards while its script body continues. HUD, animation transition
blending, CD playback and original Windows runtime comparison remain open;
this is recovery data-flow coverage, not full death-scene equivalence.

## Native effects bank and audio calls

`native_audio.c` decodes Abilene's54 VAGp samples from the original BIZ bank,
using the existing bounds-checked predictor/PCM decoder and the64-voice native
software mixer. Loading is atomic: a malformed replacement preserves the live
bank and its voices. Voice/sample memory is released before the BIZ buffers.
The SDL output requests16000Hz signed16 stereo; updates and the audio callback
share the SDL device lock. The device is closed before releasing a level and
reopened with the next level/menu bank. Config `sound` and the menu's SFX volume
and stereo preferences are applied on entry.

Command registration in00417810 and variable registration in0040d6c0 establish:

| Call | Native function | Ported behavior |
|---|---|---|
| commandC8 / D0 | 4172b0 / 417580 | Set the script sample-ID base / volume multiplier |
| variable98 | 40d390 ->41f460 | Project two wrapper roots with451d70, derive sound pan |
| variable99 | 40d3e0 ->41f5e0 | Play an original sample with signed pitch, volume, pan and optional X culling |
| variable9A /9B | 41fbb0 /41fd20 | Query voice activity / unreserved free voices |
| commandC9 /CA | 41f7b0 /41f830 | Stop/unreserve a voice / mute or restore voice gains |
| commandCB /CC | 41f9f0 /41fa80 | Change rate relative to the original rate / replace volume and pan |
| commandCE /CF | 41fc30 /41fc80 | Reserve / release a voice |
| commandDA | 417530 /41fcd0 | Set the voice group byte; group4 is exempt from global effects mute |
| variableA2 | 41ff20 | Return the separate effects preference |

Sound projection retains the native center[256,128] and near-depth clamp100,
separately from the640x480 scene renderer. Pan uses the original absolute-Y
angle and left/right branches, including1024 for zero X separation. Positional
mode is narrowed to a byte and only value1 enables the X[0,640] test. Driver-off,
zero-volume, offscreen and exhausted-pool outcomes return voice0. The native
free-voice scan precedes sample lookup; invalid audible/in-range resources
still stop their context. SOOL sample IDs subtract commandC8's base, while
internal controller sounds address the decoded bank directly.

The rate/gain path preserves signed pitch, the initial16-bit sample-rate
narrowing, unsigned32-bit commandCB edits, zero-rate held samples,600/256 level
volume scaling and the existing native gain curve and wrapping PCM mix.
Mute and master-volume zero keep advancing voice phase. Without an SDL output,
a virtual device mixes/discards exactly16000 frames per24 updates; this makes
voice completion and SOOL waits observable in the headless tracer. Headless
completion is quantized to engine updates, unlike the live SDL callback.

Lucky's468160 firing callback plays bank sample0 (`GunShoo3`) at pitch-200,
volume8191 and pan1024. Callback467bd0 increments the native fall counter only
when effects preference equals1, plays sample2 at count40, and plays sample3
when the grounded flag is observed. Landing pitch clamps to[-700,-400] and
volume to[3500,4500], using the original fall-count arithmetic. Ground idle
entry resets that counter. Callback466570 maps its idle variations2,3,2,1 to
samples4,5,6,7, with the native pitch offset and volume5000.

Synthetic regressions cover bank replacement, selector base, audible PCM,
pan/mono/master volume, zero rate, unsigned rate edits, mute phase, reservation,
full-pool silent behavior, virtual/live device ownership, SOOL play/query/stop,
positional culling, long-fall/landing timing and all four idle voices.
At the audio-port stage, the real240-update trace performed78 voice starts with
9 blocked contexts, compared with20 before that port. An ASan/UBSan8-second real-asset
capture produces `build/abilene-effects.wav` (stereo16000Hz, six player shots,
51 total voice starts, nonzero PCM in both channels). A1076-update real-asset
probe evaluates Lucky's original poses and observes `LuckyL2/L3/L4/L5` with
animations195/196/195/194 at updates242/512/806/1076. X11 checks with SDL's
dummy output exercise repeated menu -> Abilene -> menu transitions and trace
the original shot and landing sample names. These checks establish decoded
playback and integration, not equivalence to the original Windows audio output.
CD track playback/fades and the unported combat/controller audio paths remain.

## Native jump and fall callbacks

The ordinary controller now executes jump, apex, fall and landing callbacks.
Nativex86 confirms that `FUN_00467830/004678c0` read signed WORD impulses at
004bddf4 and004bddf8: -155 for a moving/speed jump and -125 for a normal standing
jump. Reading those as DWORDs would incorrectly include adjacent constants.
No nonzero part1 translation occurs in the inspected jump208 or fall211 frames;
they do not require an extra animated root displacement for these trajectories.

`FUN_0046a6e0` returnsAL=1 only when velocity already equals its target on entry.
The port now retains that return condition separately from the updated velocity.
Ascent (`00467660`) targets0 with acceleration6; one apex callback then enters
`00467e60/00467bd0`, starting a jump's downward velocity at0. A walk-off enters
`00467dd0` at velocity64 instead. Descent targets145 with acceleration5.
Each callback sums `projection_mode+1` substeps, with native32-bit wrapping.
For Abilene mode1, the first standing jump step is-232 and the first walk-off
fall step is143. Flat-ground trajectories reach minima-1240/-1925.

Horizontal airborne callbacks are retained separately from the vertical state.
`00465ba0/00465df0/00465ec0` choose the following callback before applying their
own acceleration for the current iteration: stop uses0/13, walk45/10 and
run79/10. Release and reversal therefore preserve the original one-callback
control delay. Native root yaw and the existing path constraint still determine
the final position; no separate platformer physics path is used.

Controller event15 selects BIB208, and its animation completion callback
`00467620` selects event18/BIB211 independently of the physical apex. Animation
release or a SOOL-owned replacement cancels that player completion callback.
The path sets payload flag20 when a falling root crosses the surface. The next
fall callback schedules landing, then the following controller callback enters
idle and restores the original bounds; the final airborne horizontal step and
pose are retained during that pending phase. Holding jump leaves flag40000
unarmed; releasing it rearms the native latch. Moving jumps use the pressed
edge as in the original state callback. Camera vertical mode2 now remains set
while jump/fall callbacks are active and resets after they finish.

Synthetic tests cover both impulses, apex timing, held/released input, air-control
callback changes, animation completion, terminal velocity, ground flags and the
landing phase. A real-asset ASan/UBSan probe executes standing, walking and
running jumps using BIB208, followed by a4000-unit fall using211 and return to
193. Every intermediate player pose decodes and assembles successfully, with
no player/camera quarantine. X11 keyboard probes observe G jumping from rest,
C+Right+G jumping while running, both landings and Escape back to the menu.
Captures: `build/abilene-standing-jump.jpg`, `build/abilene-running-jump.jpg`.
Original Windows runtime comparison, remaining airborne interactions, combat,
other controller entries, special hurt modes and the final game-over scene remain incomplete.

## Native follow camera

`FUN_00453590` now runs after SOOL and before the player callback, matching
`FUN_00471520`'s ordering. The entry transition also advances in that phase:
a transition created by the script moves immediately that iteration, and
conditions see its completion on the following iteration. Conditions and the
native camera therefore do not observe the same phase of a frame.

The retained follow reference (`004f2b6c`), look-at point (`004f2b7c`), last
tracked target (`004f2b8c`) and published display reference (`004bd6a0`) are
separate. Mode1 setup enables gradual horizontal look-ahead (up to2000 native
units) using command13e's step, while its argument128 is a yaw threshold,
not a translational speed. The callback ports horizontal modes0,2,3,4,5,7,8:
normal framing, fixed-axis follow, pitch/yaw clamps, reversal and idle recenter.
Player heading uses the original matrix-to-yaw conversion. Ordinary ground
shooting uses468160; the special shooting/climbing callbacks that suppress
look-ahead remain unported.

`FUN_00453190` clamps the published copy after adding look-ahead; it does not
clamp the retained reference. The renderer now uses that published reference.
Normal follow retains the script's native pitch, so command139's small pitch
variations are visible after the entry transition. Command132(6) retains the
published manual view. Recovery from player position changes over5000 units, vertical
terrain modes0/3, editor/debug controls, animated bounds and depth transitions
still require porting; an unsupported callback quarantines camera updates with
an explicit error instead of substituting a different motion.

Additional native setters13a/13b/13d/13f now update horizontal lead range,
vertical follow offset, projection depth and camera side. Their signed/unsigned
clamps and lock handling match `FUN_0041cae0/41cb60/41ccd0/41cdd0`.
`FUN_00454d50` keeps the existing look-ahead during a transition; its completion
restores normal follow while preserving fixed modes2..5.

Synthetic tests cover lead ramping, mode7 yaw threshold and reversal, separate
render/reference clamps, idle recentering, fixed-axis modes, pitch clamps,
camera locks, side switching, native setter clamps and callback/condition phase.
An ASan/UBSan real-asset run across882 updates and six path changes reports no
camera quarantine and keeps Lucky's projected root X within160..471 on the
640-pixel surface. X11 captures show scene scrolling while running right and
reversal while running left: `build/abilene-camera-follow.jpg` and
`build/abilene-camera-reverse.jpg`. This verifies the port's published framing,
not exact parity against an original Windows capture.

## Absolute camera transitions and script input

Command160 now implements `0041d680 ->0041d430/004547b0`. Its six arguments
are absoluteXYZ in units100, pitch, yaw and speed. It clamps the destination
against all three current world bounds, clamps pitch to[-800,800] and yaw to
[-1600,1600], then applies the side2 yaw offset. Speed is sign-extended before
its unsigned10..200 clamp; duration is205-speed. The current horizontal lead
is folded into the startX once and cleared, and the followed wrapper is removed.

Original0041e410 performs32-bit SHL12, signed IDIV and SAR12 to derive integer
world steps. Angles use0041e480's Q12 quotient without the final shift; each
callback adds that quotient to a Q12 accumulator, then shifts/narrows to16-bit.
There is no shortest-arc interpolation or final snap to the requested pose.
The final callback reconstructs a virtual look-at root using the reached angles
and the retained follow distance, then returns to ordinary camera dispatch.
The native-1024 tangent guard is preserved. The normal followed-root transition
15E keeps its separate callback behavior and completion ownership.

`004547b0` publishes the retained reference directly through00453190, so its
world clamp changes the position used by the next transition step. Ordinary
follow callbacks publish a temporary copy and retain their unclamped reference.
The port now preserves that distinction, including rootless ordinary dispatch.
Variable46 reports absolute-transition completion for target0 and the shared
countdown for-1, with script queries preceding that frame's camera callback.

Command15F (`0041d370`) schedules projection-depth easing: unsigned target
clamp1500..10000 and step50..500. Command161 (`0041d190`) schedules four signed
world-bound targets and an unclamped signed step. Negative steps can move a
bound away from its target, as in the original; they are not silently corrected.
00453190 advances these values before publishing/clamping, even while the
dead-camera lock disables the clamp. Immediate setters13C/13D replace their
corresponding easing targets. Commands160/15F/161 honor the native lock guard.

Focused x86 inspection also corrected variable00: Ghidra's export omitted its
final indexed read and the earlier port incorrectly returned the argument.
00407650 reads held input at004f2744+index*24;00407690 (variable01) reads new
presses at004f2750+index*24. The port supports controller index0 explicitly.
Edges are snapshotted once before all SOOL bodies/conditions and remain readable
by multiple contexts without consumption, including frames with no player
callback. Other controller indices remain unsupported. This lets context13's
original input check shorten its wait without replacing the scripted transition.

Synthetic regressions cover positive/negative Q12 steps and endpoint undershoot,
32-bit shift/add wrapping, side2 angles, persistent versus temporary clamps,
locked setters, signed bound divergence, unsigned depth clamps, completion-query
ordering and repeated held/pressed queries across contexts. The optional real
COD/BIB/BIZ test executes the initial context13 sequence twice: its first return
to settled player follow occurs at update103 with no input and54 with a new
Return press. Both runs observe25 active absolute-transition intervals and25
follow-transition intervals, including the interrupted first panorama. Context13
remains unblocked; the death/checkpoint replay still succeeds afterward.

ASan/UBSan pass these synthetic and real-asset tests. Production X11 captures
show the panorama, return to Lucky, then running/firing/jumping and Escape:
`build/abilene-camera-script-start.jpg`, `build/abilene-camera-script-pan.jpg`,
`build/abilene-camera-script-follow.jpg`, `build/abilene-camera-script-input.jpg`.
These verify the port's original-script camera flow and rendering; original
Windows capture comparison, terrain-anchored modes and teleport recovery remain
unverified/unported. This does not establish full camera or level parity.

## Native background, sky and parallax

Context3 now executes its original body instead of stopping on command122.
The local executable's `00415a60 ->00446390` creates a background manager:
its arguments[3,140] are a wrapper word and a reference height. The140 is
**not a BIB selector**. Its signed conversion gives referenceY=-74. The manager
belongs to the SOOL context, independently of the current model instance, and
is freed on reset/level exit. Repeated construction and capacity overflow fail
explicitly rather than replacing an existing callback silently.

Variable50 (`0040ca80 ->004471b0`) registers[x,y,width,height,order] and returns
the previous layer-count word. The return is confirmed by the original x86;
the decompiler loses it. Negative order adds4095 with word wrapping. Abilene
creates these three layers, containing seven primitives:

| Layer | Bounds | Order | Contents |
| --- | --- | --- | --- |
| 0 | [0,-256,512,768] | 0 | Two vertical color gradients and a flat orange rectangle |
| 1 | [-384,-128,1280,512] | 2 | One cloud strip, BIB selector89 / BIZ353 |
| 2 | [-512,-128,1536,512] | 3 | Three repeated distant-relief strips, selector87 / BIZ351 |

Commands124/125 (`00446d40/00446f50`) retain their byte RGB values and flat or
Gouraud corner colors. Command123 (`00415b90 ->00446b90`) resolves the low-byte
selector directly to its BIZ object, including selectors whose BIB section
marker is set. Native sourceX/Y arguments are ignored: UV starts at the
sprite's texture origin with V+1, source height loses two rows and the far UV
endpoints are inclusive. The cloud uses destination384x65/source256x65;
each relief uses destination512x80/source256x80. Decoded BIZ palettes and
transparent texels are reused through the scene's texture cache.

Command126 (`00447350`) sets signed-byte drift and signed-word camera factors.
Y drift is narrowed to a byte before multiplication by256/480, while Y factor
is converted as a signed word. Original `004490f0/00448e30` supplies the camera
contribution: -referenceX/16 plus sin(yaw)/2, and -referenceY/64 plus
sin(pitch)/96, with wrapped32-bit negation and truncating division. A nonzero
manager referenceY adds that offset and the camera's native128-centered
horizon to the vertical contribution. Each enabled layer advances its Q4
phase once per level callback, applies the native single wrap and signed
remainder, and combines it with camera factor/256. The cloud's X speed is-4;
its script-selected Y consumes the original shared RNG stream. This additional
RNG call changes later stationary trace counts compared with the preceding
camera-only stage.

Commands128/12C retain the native flags and per-layer enable byte. Global12D
gates both update and rendering, so cloud drift freezes while the death scene
is isolated and resumes afterward. Rendering never advances the simulation.
`00448a40` supplies the strict single-wrap rectangle origin; each corner is
narrowed to signed16 before conversion from512x256 to640x480. Flat/Gouraud
colors use native (primitiveRGB*tint)>>7 with byte wrapping. OpenGL draws
ordered background layers before the world geometry, using nearest texture
sampling and the original transparent palette entries.

`native-background-test` covers signed parallax, phase wrapping, Y conversion,
pixel quantization, flat/Gouraud colors, UV insets, byte-index aliases,
per-layer disabling and invalid resources. Real-asset tests execute context3,
check its three layers/seven primitives, resolve all four textured quads and
verify exactly120 cloud steps, independent of quad queries. The existing
fatal-projectile replay additionally checks that cloud phase stays unchanged
through consecutive globally disabled callbacks and is enabled on recovery.
Strict builds and ASan/UBSan pass. Production X11 captures show the sky during
the camera panorama and player follow; a controlled fatal-projectile harness
shows the isolated clone followed by restored sky, world and player input:
`build/abilene-background-follow.jpg`,
`build/abilene-background-death-clone.jpg`,
`build/abilene-background-death-recovered.jpg`.

The native unscaled type3 sprite branch of446b90 is explicitly unsupported;
all observed Abilene calls use scaled textured quads. Detailed native viewport
edge clipping with color/UV interpolation is not reproduced; OpenGL clips
the quantized quads. Background tint editing commands129/12A and broader
multi-manager callback-order parity remain unported/unverified. No original
Windows runtime comparison has established visual or timing parity.

## Native pause and confirmed exit

Command4C (`00413780`) now registers the ordinary Windows pause interface in
context14. Its five arguments[106,107,108,109,110] are unused by this native
constructor; they must not be resolved as HUD BIB selectors. The host supplies
the selected `win/graphics/MENU_*.KXP` archive before execution. Ten original
PCX members are decoded and retained: exity/exitn, contc/contq, backy/backn,
pause, quit and rety/retn. Missing or malformed resources keep the constructor
explicitly blocked. Replacement is atomic before registration; repeated
registration/replacement after registration fails explicitly. Level exit frees
the owned decoded images and OpenGL texture cache.

`0045e600` binds Pause to DIK_P=0x19 and Exit game to DIK_ESCAPE=1. The
`00406210` and `004775f0` x86 supplies the following behavior:

- P enters a simple pause on release. Another P release resumes it; unrelated
  keys leave it paused. `004f58d9` is release[0x19] in the keyboard table at
  `004f58c0`, written by0043f590, **not an any-key flag**.
- Escape enters the Continue/Quit page on release, with Continue selected.
  Right selects Quit and left selects Continue. Enter or a new speed-action
  press confirms. Entering Quit consumes that confirmation once; it does not
  immediately confirm the next page.
- The exit confirmation defaults to No. Left selects Yes, right selects No.
  No returns to Continue/Quit. Yes requests the native level2-to-menu1 flow;
  the app destroys Abilene and initializes a fresh menu. Escape while paused
  opens/returns to the Continue/Quit page rather than bypassing confirmation.
- Command4D's low-byte gate prevents pause processing during the death scene
  and other script-controlled intervals. Pause temporarily uses the arrow-key
  hand layout, matching00406210's call to0045e280; the selected gameplay layout
  remains available after resuming.

Original477260 positions the title at[288,104,64,32], the Continue/Quit or
Yes/No choice at[256,224,128,32], and the quit hint at[256,352,128,16] on the
640x480 surface. The quit hint's153x16 source is resized to the native128x16
quad. Original transparent/5-bit palette decoding and nearest sampling are
used. The constructor also creates a gray background layer with flags6;
the observed Windows448a40 entry guard skips nonzero flags, so the port does
not invent a darkening rectangle for it. Original Windows runtime comparison
remains necessary to establish final overlay parity.

Pause input runs before the SOOL update, as in4067e0's call to406210. While
paused, script update counters and waits, model animation, player/projectile
callbacks, camera, background drift and fades freeze together. Input edges
continue to be sampled, preventing a held action from becoming a new press
on resume. Audio playback keeps advancing independently. The pause transition
calls the native global effects mute/unmute (41f830, existing CA behavior,
including the group4 exception) and records CD pause/unpause; CD playback is
still absent. On resume the retained simulation clock advances one ordinary
step, without catching up the elapsed wall time.

`native-pause-test` checks key release, unrelated keys, both selections,
confirmation/cancellation and registration guards. Its optional archive input
checks actual localized PCX resources and preserves an existing bank after
invalid replacement. Real-asset `level-script-test` with a fourth MENU_F.KXP
path executes context14, compares every SOOL context and the retained player,
camera and background state across12 paused updates, verifies audio still
advances, then exercises movement after resume and a confirmed exit. The
existing combat/death/checkpoint tests still pass with the interface enabled.
The keyboard state and menu decisions are tested headlessly; graphical checks
use the production executable, not a replacement pause harness.
X11 captures show the title, both confirmation choices, the restored menu and
a fresh level entry: `build/abilene-pause-p.png`,
`build/abilene-pause-confirm-no.png`, `build/abilene-pause-confirm-yes.png`,
`build/abilene-pause-menu.png`, `build/abilene-pause-reentry.png`.
The paused frame and a frame taken0.9s later have zero differing pixels;
an unrelated Space press also leaves the captured frame identical. Strict
builds and ASan/UBSan pass the headless scenarios and resource decoding.

## Physical model collision, support and crate pushing

Command F5 (`4165e0`) now registers collision links on the owning **model
wrapper**, rather than on its SOOL context. The bounded three-slot selection,
target identity, detach mode7 and native constructor flag filtering follow
`457bb0/47ab10`. Registration modes0..3 are supported; modes4..6 have no native
constructor branch and stop explicitly. The support query8E follows the
context's currently bound wrapper and returns `0x80`, rather than boolean1.
Changing a context binding leaves the old object's physical links intact.

`native_collision.c` ports the four contact callbacks and their four riding
callbacks from the original executable. The Ghidra exports were checked against
x86 assembly, including local-array aliases and position-setter branches:

| Contact / riding functions | Behavior |
| --- | --- |
| `457eb0 / 457d20` | Solid contact, movable-owner pushing, head contact and support; grounded landing tolerance strictly below300; support acquisition defers the Y setter until the next callback |
| `4584d0 / 4582f0` | Axis separation or immediate support below100 units; riding follows the owner's XYZ displacement |
| `458890 / 458720` | Downward crossing onto the top, with immediate support; riding follows X/Z and snaps feet to the top |
| `458c40 / 458a60` | Strict downward top crossing, otherwise axis separation below the top; riding follows XYZ |

Inclusive AABBs, signed division toward zero, wrapped32-bit coordinates and
the first callback's signed16-bit penetration are retained. Link bits40/80
record side contact/support; model payload bits4/10 request pushing/blocking.
A movable owner (payload bit2) is displaced when the target is grounded;
airborne targets are separated instead. Link20 suppresses the controller's
side flags while retaining physical separation. Link100 grants the rider's
native10000 permission flag. Axis8/10 select Y/Z; the native constructor drops
the unsupported combined axis bits18 and falls back to X.

The ordinary player ground controller now enters event22/animation215 when
pushing and event23/animation216 when blocked. This follows
`4692d0/469170/4691e0/4690a0`: pushing uses speed20/acceleration6; blocking retains
the previous walk/run/push motion callback. Release or a change of facing exits
that state. Jump restarts speed from zero and uses the normal jump path; with
native two-step projection, its first moving update has speed20/displacement30.
No substitute animation, crate movement rule or collision mesh is generated.

Callbacks run after player/projectile movement and respect the wrapper's
native callback-enable byte. Missing roots and unsupported modes stop only that physical callback with
an explicit diagnostic. Attached setters now write the deferred local offset
through457b70. Their failure count appears in the report, debug overlay and
tracer exit3. B9 clears links and their effects. Native47ac50 snapshots roots
only for eligible presented cells; the current port snapshots all retained
model roots after callbacks because native cell selection/rebasing remains
unported. Full engine callback ordering and cell-dependent parity remain
unverified.

Pure tests cover all eight callbacks, thresholds, side/head contacts, movable
and airborne targets, carrying/release, axis selection and native arithmetic
overflow. Synthetic SOOL tests cover F5/8E, rebinding, disable/re-enable,
detaching and independent callback diagnostics. Real-asset tests cover:

- From the normal startup anchor: running stops against fixed obstacle48 at
  X21478, uses animation216, permits jumping, and permits retreat.
- From a controlled valid path anchor beside unchanged crate45: ordinary input
  pushes the crate with animation215 and script sound21, stops, resumes and
  jumps onto its top at Y-1600. A controlled support displacement carries Lucky;
  pause freezes both rider and link, and walking off releases support.

The second test relocates the player and disables camera/clipping to isolate
the physical scenario; it does not prove traversal to that crate from startup.
Strict builds and ASan/UBSan pass these scenarios together with the existing
combat, death/checkpoint, camera and pause replays.

A production X11 keyboard replay confirms blocking at the first obstacle,
jumping, retreat and a confirmed return to the menu
(`build/abilene-collision-blocked.png`, `build/abilene-collision-jump.png`,
`build/abilene-collision-menu.png`). A separate temporary graphical harness
places Lucky at the crate45 path anchor and offsets the retained camera by
the same delta; it uses the production controller, collision and renderer.
`build/abilene-crate-push.png` and `build/abilene-crate-support.png` show the
original push pose and Lucky standing on the crate. The same run checks pause
and confirmed menu exit. These controlled inputs and relocation remain outside
production code and do not alter asset files.

A controlled traversal near crate46 reaches context66's attachment and detach
of child67. The previous missing7B diagnostic is now resolved as described below;
the script-driven ballistic variable0F now executes as described below. Original Windows
runtime comparison and complete level/combat parity remain unverified.

## Skeletal part attachments and retained detach

The native command7A handler419fc0 calls419a50 with a child wrapper from the
global instance table and the current context's bound parent. Its arguments
are **parent part, child instance, child part, mode**. The previous record-only
implementation incorrectly named the part indices as blend/animation parameters
and looked up the child through a SOOL context binding. Both are corrected.
The observed Abilene calls use mode12: mode2 with a zero local root offset.
Mode2 without the+10 flag also retains the original419a50 offset calculation.
Other native attachment modes remain explicit unsupported branches.

Parenting follows486b50 and4872f0. Pivots are evaluated using the animated
original part hierarchy in the render-root basis, preserving native matrix
rounding before signed16 vertex storage. A mode2 child composes its captured
matrix/local offset with the parent's descriptor+7c matrix, adds the parent's
posed part pivot, then subtracts its own posed part pivot when that selector is
positive. Descriptor+7c and render matrix+5c remain distinct; no invented
bone-angle inheritance is applied. Children are resolved after their parents.
Position setters write the deferred attachment offset rather than overwriting
the currently presented root. Attached animation root motion uses487070's
captured basis and updates that offset. Command7B (41a050/486d00) removes the
link and copies the last descriptor+7c rotation to+5c, preserving the last world
position. It does not recompute the hand pose halfway through the SOOL body.

Command72 (418620) is also corrected: nonzero sets wrapper byte+13 to suppress
presentation; zero clears it. This is separate from callback-active byte+10.
The previous implementation had interpreted it as an idempotent callback-enable
request. Instances28/29 are therefore hidden as requested by the startup script;
collisions remain independent. Attached presentation inherits the root parent's
gate. Re-enabling an actually reduced descriptor remains unsupported because
native cell-dependent reduction/expansion is not ported.

The ordinary startup script creates three live links: parent54/part2 to
crate41/part2, parent55/part2 to hay57, and parent56/part2 to hay58. These loads
now follow the animated ropes. Controlled tests relocate Lucky to valid native
path anchors inside the original encounter trigger boxes, with camera/clipping
disabled for isolation. No enemy state, attachment or hit event is injected:

- Context62 attaches child63 using parts10/3 at update240 and detaches it at259.
- Context66 attaches child67 using parts10/3 at138 and detaches it at152.

Both replays observe changing held-object roots, pause with the link and child
unchanged, retain position/rotation at detach and add no blocker through that
point. Synthetic SOOL tests exercise direct instance lookup beyond the function
count, context rebinding, deferred root writes, independently retained matrices,
parent presentation gating, detach continuity and atomic unsupported-mode failure.
The rooted pose evaluator also has a fixed quarter-turn geometry test. Strict
builds and real-asset ASan/UBSan pass, including existing combat/death/pause tests.

A temporary graphical harness places Lucky inside context66's real trigger and
centers the camera on the unchanged enemy. Captures
`build/abilene-attachment-held.png`, `build/abilene-attachment-raised.png` and
`build/abilene-attachment-detached.png` show the tonneau following the hands;
`build/abilene-attachment-menu.png` shows confirmed menu exit. The harness and
camera override remain outside production code. The former update153 blocker,
ballistic variable0F[1,67,10,30] (409650), is now ported together with the full
scripted throw/impact cycle described below. Original Windows runtime timing/visual
comparison, other attachment modes, native cell eligibility, retained omitted
animation channels and transition blending remain unverified/unported.

## Scripted ballistic movement and barrel impacts

`native_ballistic.c` ports variable0F (`409650`, with position helper4095d0 and
attached/ordinary setters408d40/408db0/408e00). Its four arguments are signed
floor Y times100, model instance, signed horizontal drag and signed gravity.
The bytecode contains16 sites across contexts28/29/41/57/58/63/65/67/68/80..83;
dynamic coverage below concerns barrels63/67, rather than every such branch.
Assembly4099ae/409a69/409a8c establishes full-word AX0 while moving/bouncing
and AX1 after stopping; the Ghidra export incorrectly declares a void result.

Command18 (410410) sets the three signed32 motion components from signed16
arguments and retains its fourth word as the bounce counter. Command19
(4104a0) retains only the low direction byte. Each query:

- Computes displacement from the frame's elapsed60-Hz ticks with native wrapped
  32-bit products and signed division toward zero. The deterministic24-Hz port
  supplies differences of floor(updates*60/24), hence alternating2/3 ticks.
- Uses the native drag/gravity integral terms and the old velocity, then applies
  horizontal friction to the retained velocity. The strict versus inclusive
  threshold tests differ: equality can produce zero horizontal displacement
  while the retained velocity crosses zero. The displacement drag term keeps
  the native sign, including its asymmetry for leftward movement.
- Publishes movement, clamping Y only when it exceeds floor Y, to floor+1.
  Attached setters write the deferred attachment offset. No automatic second
  physics callback is added to a script-driven object.
- Tests the **incoming** Y against the floor. Crossing the floor therefore
  returns0 on that query; the next grounded query can return1. Above the floor,
  gravity updates retained vertical velocity with its native maximum300.
- At the floor, a signed nonpositive bounce counter clears velocity and returns1.
  A positive counter assigns the original counter-based bounce velocities,
  decrements the word and returns0; the direction byte controls their sign.
  These rules are retained even when the just-published move went above the floor.

The existing SOOL30-instruction cooperative limit remains effective. For the
observed context67 throw, the first ballistic query runs at update153; its
remaining collision checks consume the next update before the next query at155.
No continuous projectile simulator replaces those scheduling decisions.

The original scripts then own rolling, contact checks, health changes, sounds,
breaking animation168, visibility changes and reset poses. Controlled tests
continue both attachment replays through a complete first cycle, without
injecting a hit event or a replacement enemy state:

| Barrel | First floor clamp | Lucky loses one health tier | Breaking animation | Reset state1 |
| --- | --- | --- | --- | --- |
|63, thrown by context62 |276 |279 |281 |292 |
|67, thrown by context66 |173 |176 |179 |199 |

These replays relocate Lucky to valid path anchors inside the original trigger
boxes and disable camera/clipping to isolate the encounters. They verify the
flight/rolling/break/reset states, health3 ->2 with lives unchanged, blink immunity,
the original breaking sound26, a frozen object/velocity during mid-flight pause
and a changed reset root. They do not demonstrate
traversal from level startup. The ordinary first-obstacle, crate, revolver,
enemy-shot, death/checkpoint and pause replays remain enabled.

A further replay uses ordinary controls at a valid path anchor beside unchanged
crate46: Lucky pushes it, jumps onto it and stays on top for200 updates. Original
barrel67 repeatedly rolls into that crate, runs breaking animation168 and resets;
original rolling/breaking sounds25/26 play while Lucky's health and support
height remain unchanged. The test then resumes walking off the crate. No barrel
position or enemy state is injected.

The graphical harness uses the same valid encounter anchor and a fixed overview
camera, keeping production controller, scripts and object updates. Captures
`build/abilene-ballistic-falling.png`, `build/abilene-ballistic-impact.png`,
`build/abilene-ballistic-explosion.png` and `build/abilene-ballistic-reset.png`
show the falling/rolling barrel, its breaking geometry and the resumed enemy
sequence. `build/abilene-ballistic-menu.png` shows confirmed menu exit. The
temporary relocation/camera harness remains outside production code and does
not establish the original Windows camera framing.

Pure tests cover the2/3-tick trajectory, drag thresholds, delayed floor decision,
both bounce directions including byte255, signed bounce exhaustion, coordinate
and product overflow, vertical velocity cap and negative elapsed arithmetic.
Synthetic SOOL tests cover commands18/19, direct instance lookup, AX0/1, signed
floor scaling, no movement without a query and absent-instance failure before
mutation. Scripted movement remains independent of presentation suppression,
callback enable and a reduced model's retained root. Strict builds, real-asset
tests and ASan/UBSan pass these scenarios. Original Windows runtime comparison and full level/combat parity
remain unverified.

## Automatic path control and scripted model intensity

The old "climbing not implemented" guard on path types1/2 was misleading:
`469ef0`, `469dd0` and `469ea0`, checked against the shipped x86, select automatic
walk/run motion with ordinary events4/5 (Lucky BIB197/198). They do not use a
new climbing animation. Abilene has two segments of each type among89 segments.

Grounded type1 selects walk acceleration10/target23, clears payload40 and
switches an existing hurt callback to blink without a new cry. Entry preserves
speed, facing, bounds and the falling counter. Later ticks force the retained
path yaw. The exit tick clears the player's private input and enters ordinary
idle control immediately. Grounded type2 selects acceleration10/target66 and
retains incoming facing. Its exit tick keeps automatic running; ordinary idle
entry runs the following tick. Automatic ticks bypass the ordinary input mask,
jump-release and path-death pre-controller. Losing the ground flag alone does
not select a fall callback. Normal root motion and linked path projection still
execute, including slopes. The two hurt timers at4e8850/4e8854 are independent,
including when type1 changes quiet immunity into blinking.

Permanent real-asset tests start on projected quarter-points of the unchanged
segments, with the controller, scripts and physics active and camera disabled.
No SOOL state, path flag or path link is forced. After120 ordinary startup
updates, no directional input is needed:

| Start segment | Mode | Exit segment | Idle entry tick | Resting root |
| --- | --- | --- | --- | --- |
|39|Automatic walk|14|141|[123047,-332,9744]|
|42|Automatic walk|38|160|[123550,-3716,7647]|
|55|Automatic run|24|132|[159100,-4204,8552]|
|26|Automatic run|18|134|[202550,-4798,11202]|

Type1 traverses the original39/42 link whose endpoints do not coincide. The
existing native fallback projection reanchors on that linked segment; the port
does not add interpolated geometry. The tests also pause each automatic mode,
check both exit schedules, and retain only the preexisting CD-music blocker.
These controlled replays do not establish a natural full-level traversal or
an original Windows runtime comparison.

The type1 route activates context101's original shadow volume92. Command30
(`4116d0` -> `47d700`) now retains descriptor+54 as a signed16 multiplier and
updates the displayed material. The script sets128 and restricts actions with
DD(4,2001,1); leaving the volume sets256 and clears those restrictions. Shared
model wrappers share material state, while constructor68 resets its copied
descriptor multiplier to256. Type1 resource expansion converts initial zero to
256 (`47ec50`); static descriptors preserve their initial field without applying
a tint until explicitly commanded.

For primitive types0/1, `48efc0`/`48e5e0` multiply packed source RGB by the
coefficient then shift8 and retain the low byte, preserving native wrap rather
than clamping or accumulating previous tints. For types2/3, `48dcc0`/`48c510`
combine the logical half-coefficient into RGB without byte masks. Lucky uses
only these four primitive types. The OpenGL texture combine uses128 as neutral
and scales by2 before final pixel clamping, then restores texture state for
sprites and menus. Tests cover half/neutral/overflow/negative coefficients,
shared and private material state, and context101's entry/exit using original
assets. Pixel-rounding parity with the original hardware driver is unverified.

Xvfb replays through the production renderer capture automatic running on the
ladder (`build/abilene-auto-run.png`), its exit, and a confirmed fresh menu
(`build/abilene-auto-menu.png`). In the saloon, the original geometry occludes
Lucky from the front. A temporary rear-camera replay freezes the pose and
compares the native128 tint with a render-only256 override: the changed pixels
are confined to the visible part of Lucky, with approximately half the RGB sum.
The replay camera, freeze and material override exist only in `/tmp` harnesses;
the production port contains none of those controls. At that stage the
stationary960-update trace retained103533 calls,103532 supported and the one
existing CD context blocker; current counts after sprite fixes are listed below.

Command30 on nonempty Gouraud groups4..7 remains explicit unsupported behavior:
the native hardware dispatch passes four arguments, while those helpers read
their third argument as the coefficient. Reproducing that address-dependent
behavior requires runtime evidence; no speculative Gouraud tint is applied.

## Script-selected controller entries and spring boxes

CommandBA (`416a20`, confirmed against x86) reads only its second SOOL word
and replaces the global player's main controller. Its first argument is unused,
even when it names an absent wrapper. Entries0/1/2 (idle/walk/run),3,8 and15
are ported. Case4 and values outside0..15 leave the current callback unchanged,
including an already pending entry. Other switch cases remain explicit
unsupported entries; they are not mapped to an idle fallback.

Entry execution occurs in the native main-controller phase, after pre-control
and hurt callbacks. It does not run during the SOOL command itself. The
ordinary pre-controller can replace a queued entry when entering an automatic
path. Pre-control is retained separately from the main mode: replacing the
main callback during type1/type2 does not silently restore ordinary input
filtering. The type1 exit can itself replace the queued entry with idle.

BA8 installs `465a40`, an empty main callback. It preserves the current
horizontal callback, animation, bounds and fall counter: walking/running can
continue despite a new opposite input, whereas an air horizontal callback can
still react to direction. It does not freeze the model or the whole engine.
Context4 uses this before the level-exit sequence. Synthetic SOOL tests exercise
this behavior and its repeated selection. The original obstacle/exit replay
below now reaches the final fade and loads the original Abi_Boss scene.

BA15 selects `467b20`: reset the long-fall sound counter, use vertical impulse
-125, select decelerating air motion, clear only ground20 and start event15
(BIB208), calling the ordinary rising callback immediately. It preserves the
jump-release40000 bit, bounds and horizontal speed. With two motion substeps,
the first vertical speed is-113 and displacement-232. BA3 (`467830`) instead
uses-155, clears40000, preserves the fall counter and selects the walking air
callback: its first displacement is-292 and initial horizontal acceleration
still runs even with no direction. These differences are tested explicitly.
The earlier implementation had those two values reversed. The shipped `.data`
words establish `4bddf4=ff65` (-155) and `4bddf8=ff83` (-125); both the controller
and its tests now use those values.

Variables24/25 (`408e40`/`408ec0`) complete the existing X query0C: Y/Z divided
by100 with signed truncation toward zero and a low16-bit result. The assembly
retains the return that Ghidra omitted. These queries allow contexts42/43/44 to
pass the actual box location to bonus contexts73/71/72, respectively.

Permanent tests drop Lucky onto each unchanged box from an anchor on its native
path, without changing any SOOL state or collision registration. Ordinary
falling produces physical contact126, the script requests BA15 at127, the box
reaches state3 at141, and Lucky is idle on the floor at153. The rising/falling
apex in this replay is Y=-1976. Each box plays its original sound44, runs
animations158/159/160, detaches the contact link and places its animated bonus
at the box's truncated X/Z and Y-400. The flight can be paused/resumed without
changing SOOL, controller, box or player state. Tests finish before the nearby
barrel67 encounter, which is covered separately.

A fourth replay keeps the original startup position and live follow camera.
After120 startup updates it uses only Left, then Left+Jump below X7900, and
releases direction below X7100. It contacts box42 at295, launches at296, opens
the box at310 and returns to ordinary idle at323, with apexY=-2115. There is
no relocation, forced controller entry, edited path or forced SOOL state in
this replay. This proves that interaction from the beginning of the port;
it does not prove a full-level playthrough or Windows runtime parity.

Card73 is collected at149 in the controlled replay and319 in the input-only
replay. Its native card counter and context77's separate mission counter both
increase once; sound52 and effect102 execute to completion. The health bonuses
from boxes43/44 require health below3 in their original script; the full-health
replays correctly leave them available. Their healing primitive is covered by
command35 tests, rather than evidence of a complete healing-box playthrough.

## Bonus bounds, inventory and sprite groups

`486410` constructs a world-sprite rectangle at0,0 with its clipped BIZ size.
`4862e0`, confirmed in x86, later replaces its origin with the BIB frame offsets
and its size with the clipped dimensions minus2. The old bounds helper used
atlas UV coordinates as the origin; this placed collision volumes thousands
of units away from their visible bonus. Bounds now use the geometry offsets,
signed16 scale arithmetic and the native640/512 X projection. X/Y extents are
replaced per frame; Z retains the minimum/maximum reached by the descriptor
(`485e70`), including the initial constructor extent. The original card96
constructor bounds are[0,0,0;480,744,744]; its frame0 bounds are
[-210,-384,-384;210,312,744], both checked in permanent real-asset tests.

Command35 (`411930`) now updates the five signed-word inventory fields: dynamite,
health, lives, money and cards. It preserves word wrapping, health's asymmetric
positive/negative guards and upper cap3, money's lower cap0, the HUD dirty flags
and the money timer reset. These are direct inventory updates, so a negative
health update does not invent a damage/death reaction. Unknown selectors leave
the fields unchanged, as in the native switch. Setup preserves money and cards;
the native cleanup resets dynamite and health (`474970`). Inventory effects are
ported; the full native HUD callbacks and presentation remain incomplete.

Sprite sequence start/release now mirrors wrapper byte14:6B/74 reveal sprites,
6A (`41b930`/`41b880`/`485d00`) removes the current sprite sequence and clears
that byte for world kind5, retaining it for screen kind7. Releasing a sequence
does not synthesize its completion callback. The first implementation retained
the flag separately but omitted visibility activation, making bonuses invisible
despite an active animation. Native model variants of6A remain unsupported.

Ordinary sprite animations now use `animation_clock>>5`, the same native time
base as projectile sprites, instead of milliseconds. `485430` advances only
after elapsed time exceeds the frame duration; exact boundaries retain the
current frame. Completion waits and pause/resume use this clock as well.

The corrected bounds also activate the original coin group contacts. Command96
now owns a separate sprite descriptor for each member, outside the global
wrapper array, with its BIB/BIZ frame, position, bounds and animation clock.
Translation97 retains the saved origins and updates their current roots.
Variable28 (`40ae50`) consumes at most the first overlapping active member.
With selector58 set, it starts that member's original hit sequence at scale32
and leaves it visible until its final frame is queued (`473450`). With selector0
it hides the member immediately. Invalid effect resources preserve the member
and still report unsupported behavior. Group callback/byte2 gates both contact
and animation, and pause freezes these descriptors. The renderer now draws
visible ordinary coin members and their collection effects using the shared
world-sprite path. Model-derived orbital groups remain a separate unfinished
feature; no procedural coin substitute is added.

The existing input-only run to obstacle48 now collects all three members of
group88, adds money3 and runs effect102, without quarantining its context.
The spring-box replay shows the card, its pickup effect and the confirmed fresh
menu through the production renderer in Xvfb. Captures include
`build/abilene-spring-bounce.png`, `build/abilene-spring-landing.png` and
`build/abilene-spring-menu.png`. All replay input hooks remain in `/tmp`, outside
the production sources. These tests do not establish original Windows pixel,
frame-phase or complete level equivalence.

## Crouching and the original dynamite scripts

The controller distinguishes Down (`40`) from a dynamite press (`1000`, V in
profile A). `469b00` enters event19/BIB212 with the original lower Y bound
raised by800. Its completion callback schedules `4699b0` for the following
update, selecting crouched event20/BIB213. Releasing Down starts event21/BIB214
and restores the full bounds; its completion likewise defers the ordinary idle
entry. Horizontal motion is retained through descent/rise, then changes to
idle deceleration while crouched. Turning, walking, shooting, jumping and
ground loss use the corresponding original cancellation branches. Down with
Left/Right from ordinary standing still walks; it does not enter crouch.

`466740`/`466b60`/`466d80`/`469870` accept dynamite only on a pressed edge, with
positive signed stock, no active dynamite latch and permitted support: flag8
requires flag10000. An accepted press consumes one stick and sets the latch;
holding V does not consume more. Empty or temporarily forbidden requests are
ignored without quarantining the player. This starts the original crouch
entry, rather than introducing a separate throw animation or projectile.

Unchanged SOOL context5 reads the latch, queries Lucky's truncated X/Y/Z and
positions its fuse sprite100 at Y-100. Sprite completion releases context6,
whose explosion98 is another1000 units higher. Context6 plays sound20 through
the native distance/pan variables, waits for the animation, runs the scripted
shake and tests Lucky's bounds for damage. Its final wait asks context5 to
clear the latch. Stock snapshots also let the script re-arm pack76 when empty.
The port now supplies the remaining native dependencies:

- Command69 (`41b530`) uses the same bounded sprite/completion behavior as74
  (`41b650`), including visibility and the original animation clock.
- Variable2B (`40b400`) stores its low byte in the latch and returns zero;
  the x86 explicitly clears AX, despite the missing decompiler return.
- Command14A (`41d020`) ignores camera lock1; otherwise it adds a signed word
  to retained camera Y in modes0/3 or without a follow target, or adjusts the
  follow height with the native -6000..6000 clamp.
- Command33 (`411ac0`) snapshots lives, health, money, dynamite and cards into
  five `(byte offset, context)` destinations. It writes cards first and lives
  last, preserving aliased destinations. All destinations are validated before
  mutation; unaligned word writes use the VM's byte-addressed banks.

Command33 has a real stack-ABI quirk. The shipped opcode41 declares five
arguments, but `411ac0` reads ten destination words. Opcode0A pushes a pair,
and `422dc0`/`420a40`/`425990` still consume only six words including the command
ID: the handler never adjusts the extra-consumption count. The port reads the
ten words but retains the native five-word stack remainder. Synthetic tests
check that remainder, cross-context writes, alias order and malformed banks;
cleaning up all eleven words would change execution of the shipped script.

Real-resource tests exercise crouch/hold/rise, cancellation, stock/support
gates and pause. A controlled-stock replay at the original spawn plants at121,
starts the explosion at186, applies one health loss at215 and clears the latch
at273. Holding V through reset does not restart it; release/repress completes
a second cycle, refreshing the inventory snapshot. Running away with ordinary
Right+Run input keeps health3. Remaining nearby leaves health2 after the first
cycle and health1 after the second. Another replay anchors Lucky on his valid
original path beside the actual pack76, without granting stock or forcing SOOL
states: the pack's script awards three sticks and a complete cycle leaves two.
That controlled anchor does not prove a traversal from the level entrance.
Pause freezes the player, fuse, explosion and all contexts without advancing
their waits. Net shake restores the retained camera value.

The production renderer was also exercised in Xvfb. Normal-camera captures at
the original spawn use two granted sticks solely in a temporary harness;
`build/abilene-dynamite-start-crouch.png`,
`build/abilene-dynamite-start-explosion.png` and
`build/abilene-dynamite-start-menu.png` show the crouch, explosion and confirmed
return to the menu. A separate controlled-pack overview is partly occluded by
the jail facade. All harness hooks stay in `/tmp`. Other enemy/destructible
explosion interactions and Windows runtime/pixel parity have not been established.

## Dynamite obstacle and level exit

Context6 tests its explosion against the crate barricade's unchanged BIB box91/70,
[204000,-2000,7097;206500,0,9630]. A match requests context52's state1 until that
context reaches state2. The obstacle at [205300,0,8375], model208, removes its
F5 collision link, runs animation156 and requests context4's exit-wait state2.
At animation completion it selects resting animation157 and stays open. A
later explosion cannot restart that opened obstacle. These behaviors execute
through the existing native handlers and the original script; no special
destruction rule is added to the host.

Two newly ported variables let context4 continue:

- Variable83 (`40cd40`) reads the target model's payload low word and returns
  its bitwise intersection with the supplied mask. This is the raw mask result,
  not a normalized boolean. The decompiler omits the return; x86 explicitly
  ANDs the sign-extended words and returns SI in AX. Context4 waits for ground20.
- Variable8 (`408a00` -> `408630`) approaches a scripted X target, expressed in
  hundreds, at a signed speed scaled by the native engine tick delta and divided
  by projection_mode+1. The quotient narrows to an unsigned word before movement.
  It selects direction from the signed low word of target-current, then compares
  signed DWORD coordinates. Even the surprising long-distance/negative-speed
  outcomes are retained. It reports completion within one step, including the
  boundary, without snapping to the target. Position writes use `408d40`'s
  ordinary root or deferred skeletal-attachment offset path.

After the player overlaps box91/90, context4 applies its original input masks,
waits for grounded status, selects BA8 and animation198, and repeatedly calls
variable8 with target2117/speed128. It then starts command10E's darkening fade,
waits for its completion and calls command12 with target3. The native scene-name
table at4bce50 maps state3 to `Abi_Boss` (pointer4b7688), not directly to another
ordinary level or the menu. Command12 now requests that scene from the outer
loop. The validated loader replaces the SOOL/BIB/BIZ resources after the update
returns, so this final black frame proceeds to the original duel scene.

Three real-resource replays use a controlled valid path anchor and two granted
sticks. The camera callback/output are disabled to isolate the still-unported
teleport-recovery branch. F5 pushes Lucky out of the closed obstacle to X204447;
an ordinary V press starts the fuse. The obstacle enters its opening state at221
and resting state at253. A second complete fuse/explosion leaves that resting
animation unchanged. An explosion8000 units farther left never opens the
obstacle and retains its collision link. In the passage replay, Right+Run input
crosses the opening and triggers the original exit script. Lucky stops at
X211642, short of211700, before the full fade and command12's deferred request
at355 (357 with the two resumed updates from the opening-pause check).
Pause freezes the obstacle descriptor and all contexts during its opening and
can still be entered after the final fade. These are controlled interaction
replays, not evidence of a complete traversal from the entrance or Windows
runtime equivalence.

An Xvfb replay uses the same controlled anchor/stock with a fixed temporary
overview camera. `build/abilene-gate-closed.png` and
`build/abilene-gate-open.png` show the original stacked crates and their broken
resting pose. `build/abilene-gate-exit.png`, `build/abilene-gate-fade.png` and
`build/abilene-gate-boss-request.png` record the exit and the earlier black-frame
boundary before the scene loader was ported. The confirmed quit flow returns to the freshly initialized
menu (`build/abilene-gate-menu.png`). Replay hooks and camera overrides remain
in `/tmp`, outside production sources.

## Deferred scene loading and Abi_Boss

Command12 (`410250`, confirmed in x86) stores the requested native scene word
and sets the outer-loop change flag. It does not free resources during SOOL
dispatch. The port currently accepts scenes1/2/3 (menu/Abilene/Abi_Boss); other
destinations stop the requesting context explicitly. The rest of the current
update finishes, then further engine updates freeze until the host loads the
scene. Pause/quit remains available if loading fails. A synthetic test checks
that instructions after the request still run and the next update does not
advance the old VMs.

`ll_level_script_replace` prepares owned copies of the new SOOL/BIB/BIZ and
optional localized pause archive before releasing the old scene. Malformed
code, BIB, BIZ or supplied pause data leaves the old scene, request, contexts
and inventory owned and intact. SDL audio is closed before replacement, and
the host clears model/material/sprite/pause texture caches before presenting
the new resources. The original script selects the new camera and background.
The native global lives, money, cards and sound/control preferences carry into
the duel. B9 still resets health to3 and dynamite to0 (`474970`). `4056d0`
explicitly retains mission cards for scene3; the host clears them for ordinary
scene2. A replacement test carries lives2/money37/cards4 and exercises each
malformed-resource path before loading the valid original assets.

The original `ABI_BOSS/abi_boss.cod` has24 contexts,15 retained scene objects,
16 static models,25 original effects samples and a background with3 layers/
10 primitives. Its startup needs these additional native handlers:

- Command1E (`410740` -> `477aa0`) registers the initially empty50-entry timer
  manager; B9 removes it. Timer insertion/control calls remain unported and
  cannot silently acquire invented timers. Abi_Boss does not insert any.
- Variable3E (`40c1c0`) zero-extends the global keyboard-profile byte. Command51
  (`413f70`) saves the previous profile byte, then assigns the low argument byte
  to the active/current profile. B9 retains these globals. Unsupported keyboard
  tables stop explicitly. The duel saves the user's profile and selects A;
  the host input reader now follows this script-selected profile.
- Command8 (`419810`) starts a nonblocking one-shot skeletal sequence using an
  existing animation buffer. Its completion callback releases the owner's wait
  flag, but the command itself neither waits nor yields. This differs from0B's
  blocking sequence and1B's loop. Existing limitations on transition blending
  still apply; a missing source animation buffer stops explicitly.

The duel also queries a particular model part through variable66. Native
`40da10` caches one nonzero-mode world AABB per wrapper, mode and
`animation_clock>>5`. Mode1 scans expanded vertices[2,count-2); another positive
mode selects that exact part's vertex range via `47fec0`. `47ec50` connects those
ranges to the model's +BC buffer, and `4821d0`/`47f6d0` writes rooted skeletal
vertices into it. The earlier port incorrectly scanned packed source geometry
for mode1 and rejected part modes. Queries now use the existing rooted skeletal
evaluation, the original vertex ranges and the native single-entry cache.
Mode0 always reads live descriptor bounds; kind5 sprites retain descriptor
bounds for every mode. Invalid part indices and unsupported screen-sprite
modes stop their context. A burst test verifies stale world coordinates after
a same-clock root move, then refresh on a mode change, all within one native
burst. These checks do not establish
Windows draw/query frame-phase or transition-blend parity.

The controlled barricade/exit replay now loads the real duel, validates profile
C->A, walks both ways with animations50/51, starts the original fire/action
sequence53, exercises part bounds and freezes Lucky's descriptor during pause.
Four hundred duel updates retain only the known CD-music blocker (plus the
missing pause resource context9 when the optional archive is omitted). A
separate1600-update held-action probe also leaves only CD context0 blocked.
The stationary960-update boss trace records14227 calls,14226 supported, with
only context0/D3 quarantined; the Abilene trace remains106783/106782 with that
same sole CD blocker.
These are interaction checks; a complete victory/defeat, subsequent scene
loading and Windows runtime comparison remain unverified.

The Xvfb harness takes the controlled path anchor/stock through Abilene's exit,
then leaves the new scene's camera and keyboard polling live. Real Right/Left/B
key events exercise the duel. Captures are `build/abilene-boss-intro.png`,
`build/abilene-boss-right.png`, `build/abilene-boss-left.png`,
`build/abilene-boss-fire.png`, `build/abilene-boss-pause.png` and
`build/abilene-boss-menu.png`. The last capture follows the confirmed quit flow
back to a fresh main menu. All replay hooks remain in `/tmp`.

## Scope and observed result

The native runtime loads the original `ABILENE/abilene.cod`, retains its
contexts and executes its bytecode through `sool.c`. It owns copies of the
original BIB and BIZ resources; it neither mutates game files nor reuses the
experimental CRC3 `ll_cod_*` parser. Static/model and sprite constructors now
retain bounded scene records. Skeletal animation schedules frames, interpolates
part poses, deforms visible model vertices and handles completion waits.
Player control supports native idle/walk/run/jump/fall, ground landing and
ground shooting with its projectile pool, enemy targeted balls and nonfatal
player impact responses and the script's ordinary death/checkpoint recovery.
Ordinary F5 model collision, movable crate pushing and support also execute.
Barrel throws, rolling impacts, breaking and scripted reset also execute.
Automatic path walking/running and context101's shadow entry/exit also execute.
The three spring boxes launch Lucky, open and place their original bonuses.
Crouching, dynamite pickup, planting, fuse/explosion, Lucky damage and scripted
camera shake also execute, including release/repress and pause/resume.
The explosion opens the final obstacle, and the player's exit animation/movement
and darkening fade load the original Abi_Boss scene. Its24 contexts support
the initial lateral movement/action interactions, skeletal-part bounds and pause.
Broader enemy combat, other skeletal attachment modes, the game-over scene,
other BA entries, native HUD presentation and CD music remain incomplete. Effects-bank audio
and native script voice controls now run. Unsupported calls stop the affected context; they are never
treated as successful no-ops or variables returning zero.

Against the installed original COD/BIB/BIZ assets and MENU_F.KXP pause archive,
the bounded tracer produces:

```text
24 updates:  calls=2764 supported=2763 blocked_contexts=1 objects=88 static_models=169
240 updates: calls=26581 supported=26580 blocked_contexts=1 objects=88 static_models=169
960 updates: calls=106783 supported=106782 blocked_contexts=1 objects=88 static_models=169
backgrounds: managers=1 layers=3 primitives=7 enabled=1
collisions: owners=19 links=19 supports=0 side_contacts=0 blocked=0
attachments: links=3 blocked=0
pause: resources=10 registered=1 enabled=1 paused=0 exit=0
directory: functions=118 condition_streams=13 virtual_tables=40 models=213
projection=804 cell=311 camera_mode=1 speed=128
bounds=[8200,202200,-20000,0] word=0 limit=200
```

The 24-update run recognizes 2633 more host calls than the initial stage (130)
and registers 26 additional objects. The240-update run reaches more bodies
through animation callbacks while retaining the same blocked context0/CD music D3.
Without the optional pause archive, context14 also stops on its missing
localized PCX dependency; this is no longer an unimplemented native constructor.
A stationary player does not trigger
the enemy firing states; their coverage comes from the controlled replay above.
These counts are not full-file handler
coverage or proof of gameplay equivalence.

## Reproduction

```sh
./build-linux.sh
./build/linux/abilene-trace /path/ABILENE/abilene.cod /path/ABILENE/abilene.bib /path/ABILENE/abilene.biz 24 --pause-archive /path/win/graphics/MENU_F.KXP
./build/linux/level-script-test /path/ABILENE/abilene.cod /path/ABILENE/abilene.bib /path/ABILENE/abilene.biz /path/win/graphics/MENU_F.KXP
./build/linux/native-pause-test /path/win/graphics/MENU_F.KXP
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
and opens Abilene. A confirmed Escape -> Quit -> Yes destroys the level contexts and reinitializes the
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
| e6 | 416190 | Empty path-registry capacity10; command e8 attaches and runs ordinary native path constraints |
| f0/f1 | 416550,416590,4730a0 | Ten-entry pose-group registry, validated BIB selectors91/92 |
| 132 | 41c230 | Camera callback selection, lock, signed yaw threshold128..1023; normal follow now executes |
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
instance4; its ground, air, shooting and nonfatal hurt callbacks run as described above. Command
`0x15` releases the current model's active animation data. Variables `0x00/01`
read held/newly pressed input for controller0; variable `0x36` compares and consumes the collision
event latch, matching the boolean behavior of the related native handler.
Command `0x7a` executes Abilene's mode2 skeletal part attachments, and `0x7b`
detaches while retaining the last root. Other modes and transition blending
remain incomplete; see the attachment section above.
Command `0x39` validates its BIB selector and records Abilene's bounded orbital
group setup (member count, scale, angular step, center, parameters and wrapper
instance). The following per-member construction command and the group's native
update/draw callbacks remain unimplemented, so no orbital sprites are built or
rendered.
Command `0x53` stores the four observed setup words in the matching orbital
group, with context and arity checks. The group-specific variable `0x0e` and
command `0x4e` are also ported: the variable tests a strict signed X interval
using a checked wrapper root, while the command stores the native group byte
at+2. Variable `0x28` uses retained member bounds and positions for contact;
configured hit animations remain unsupported.
`0x72` controls the native presentation suppression byte independently of the
ordinary callback-enable byte; reduced descriptor expansion remains unported. Command
`0xf5` stores and dispatches the native three-slot collision links per model
wrapper, including target instance, callback mode and recognized flags.
Variable `0x8e` queries the bound wrapper and returns the native support mask
`0x80` or zero. Rebinding a SOOL context does not transfer an old wrapper's links.
See the physical collision section for supported callbacks and limitations.
Variable `0x64` compares two wrapper bounds with inclusive AABB semantics;
mode0 uses descriptor bounds, mode1 scans the expanded rooted skeletal vertex
range and other positive modes scan a particular part, with native cache timing
as described in the Abi_Boss section.
World-sprite wrappers retain their frame geometry bounds with the native
scale and Abilene's 640/512 horizontal projection factor; atlas UVs do not define
the bounds' origin. Variable `0x66`
compares these sprite bounds against a target wrapper using the same inclusive
AABB test; unsupported sprite-wrapper modes still stop their context.
`0x11e` resolves a bounded BIB pose and retains its three position coordinates
at native004f2e10. Inspection of `FUN_00413580` confirms this is the player reset
destination for command48, not the normal camera's follow target. The fields
are now named `player_reset_position`; a failed lookup preserves the previous
position. Normal command48 checkpoint recovery now executes as described above;
its final game-over and explicit level-exit branches remain unported.
Command `0x32` retains the scene-sprite manager's capacity16 and clears its five
native sprite slots; registration is modeled, while the manager's update/draw
callback has not been ported.
`0x6b` advances bounded BIB sprite-frame/BIZ object metadata. Commands
`0x05/0x08/0x0b/0x14/0x1b` schedule bounded model animation ranges on the native 60 Hz
clock, yield waiting contexts (08 stays nonblocking), advance frame metadata and resume owners
through completion callbacks. Reverse cursor queries and per-axis root movement,
including nonzero loop offsets, are now handled as described above.
Pose interpolation and skeletal vertex application now feed the scene renderer.
Level transition blending between animations remains incomplete. Individual
world sprites, the projectile pool and screen sprites
feed the OpenGL path; sprite groups still lack their draw callback.

## Historical blocker list (before the current dependencies above)

| Blocking call | Contexts in this run | Native entry / next dependency |
|---|---:|---|
| variable28 | 8 | 40ae50: orbital member collision scan; needs generated meshes and bounds |
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

The earlier skeletal evaluation probe applies every visible type1 instance pose
for240 original-script updates:13962 evaluations, zero failures under ASan/UBSan
(LSan disabled). It observes44 vertex-buffer changes for Jolly Jumper, while
At that earlier presentation-only stage, Lucky's assembled pose was unchanged;
the ground controller now starts his original animation193. Synthetic regressions cover
short animation tables, parent pivots, explicit next frames, interpolation,
retained expanded poses, capacity/truncation checks and bounded loop/final-frame
metadata. This does not establish native gameplay or animation-transition parity.

Xvfb checks also cover JEU -> Abilene -> Escape -> menu -> Abilene, including
closing/reopening the menu's SDL audio device with the dummy audio driver.
The genuine `image/Abilene.pcx` is a title card, not playable level geometry.
Its presenter is now initialized to the source dimensions (512x256 rather
than640x480); letterbox bands are cleared each frame. The synthetic OpenGL
test `level-background-test` checks a2x1 PCX loaded into an initially64x48
presenter. Run it with `xvfb-run -a env SDL_VIDEODRIVER=x11
build/linux/level-background-test`.
