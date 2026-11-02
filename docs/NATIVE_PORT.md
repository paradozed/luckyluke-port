# Native Linux Port

## Runtime foundation

The first Linux target is a separate SDL2/OpenGL executable. Build it with:

```sh
./scripts/build-linux.sh
./build/linux/lucky-luke
```

The build requires a C compiler, `pkg-config`, SDL2 development files, and OpenGL development files. The runtime currently opens a resizable 640x480 window and renders a procedural OpenGL night-western menu: a moonlit town, a stylized Lucky Luke silhouette on the left, and a center signpost with localized GAME/JEU and OPTIONS boards. Up/Down or W/S selects, Enter opens the selected placeholder page, Escape returns or exits, and mouse hover/click also works. This recreates the observed composition; it is not the original BIB/BIZ 3D scene.

The existing `build.sh` remains the separate i386 Windows PE reconstruction and byte-exact verification pipeline. The native target does not modify `orig/Game.run`, `orig/Lucky.exe`, or original game assets.

## Original startup and game loop

Observed in the Ghidra output under `src/ghidra_c/`:

1. PE entrypoint `entry` at `0x00499530` performs CRT/runtime setup, captures the command line and startup information, runs `FUN_00496eb0` initializers, then calls `FUN_00445870` with the module handle.
2. `FUN_00445870` calls `FUN_00445630`, which registers the `Lucky Luke` Win32 window class and creates the initial window. It then enters `FUN_004067e0`, the main application routine.
3. `FUN_004067e0` initializes AVI support and game subsystems, checks/initializes the rendering backend, loads settings and input configuration through `FUN_00404f60`, updates the window/cursor, and optionally displays startup logos and localized screens.
4. The outer loop calls `FUN_004056d0` to prepare the current screen/state, then runs frames while `DAT_004f1e21 == 0`. The outer loop repeats until `DAT_004f1e20 != 0`.

The per-frame path in `FUN_004067e0` is approximately:

1. `FUN_004719e0` refreshes the high-resolution frame timer.
2. `FUN_00406560` polls input and window activity. It calls `FUN_004454d0`, which services the Win32 message queue through `FUN_00445740`; the latter calls `PeekMessageA`, `GetMessageA`, `TranslateMessage`, and `DispatchMessageA`.
3. `FUN_00406210` processes pause-related input and changes pause/input globals. The following conditional frame-update branch is not fully trustworthy in the decompiled C: its caller consumes a return value, but both the function source and Ghidra index declare it `void`.
4. Normal frames advance scheduled/game callbacks (`FUN_00422780`, `FUN_00471520`), update/draw registered screen objects (`FUN_00471620`, `FUN_00471750`), and run rendering/presentation callbacks including `FUN_0047de90`, `FUN_004437e0`, and function pointers in the `DAT_004e8a..` globals.
5. Frame bookkeeping and audio/update callbacks run before control returns to the inner-loop condition.

### State and exit transitions

- `DAT_004e8914` is the current screen/game-state selector. `FUN_00404f60` initializes it to `1`; `FUN_004056d0` uses it to select per-state data, callbacks, and rendering setup. The evidence supports treating it as a screen/state ID, but the individual meanings of all numeric IDs are not recovered yet.
- `FUN_00474a20`, called by `FUN_00474c70`, handles menu selection/navigation using the current selector and saved selection (`DAT_004e8916`). `FUN_004750b0` explicitly maps the level-intro title images `IMAGE_ABILENE_TIM`, `IMAGE_SALOON_TIM`, `IMAGE_WAGON_TIM`, and `IMAGE_DALTON_TIM` to state IDs `2`, `0x0f`, `0x12`, and `0x17`, respectively.
- Setting `DAT_004f1e21` exits the current inner run and returns to outer-loop state setup. Many state/input handlers write it; `FUN_004775f0` also sets it while processing pause/menu choices.
- Setting `DAT_004f1e20` terminates the outer loop. The Win32 close path runs through `FUN_00445570` to the registered callback `FUN_00404230`; its `WM_CLOSE` case sets both loop flags and marks shutdown state.
- `FUN_00406740` appears to be a timed state-advance/test helper, but the current decompiled call-site search found no caller, so it is not considered part of the confirmed main path.

This is a static trace of the decompiled output, not a runtime trace. Several functions retain Ghidra-generated names, so their roles above are described from their call sites and observable global/API effects rather than presumed original symbols.

## DirectDraw surfaces and presentation

Observed primarily in `FUN_004ae6a7` (`src/ghidra_c/4ae6a7__FUN_004ae6a7.c`), with descriptor decoding in `FUN_004b1045`, offscreen allocation in `FUN_004b1510`, and present selection in `FUN_004ae460`:

### Mode dimensions and depth

- The requested mode is packed in `DAT_004c7fb8`. `FUN_004b1045` decodes width as bits 0-10, height as bits 11-21, and requested depth as `8 * bits[22..23] + 8`, yielding 8, 16, 24, or 32 bits per pixel. Bit 24 is the fullscreen selector; other high bits control allocation/options.
- The selected width and height are configuration-derived; no single default resolution was established from the inspected call path. The window sizing handler in `FUN_00404230` clamps its reported rectangle to 50..640 by 50..480 pixels. That is a window constraint, not evidence that every render mode is 640x480.
- In windowed mode, initialization replaces the packed depth with the desktop depth reported by `GetDeviceCaps(BITSPIXEL) * GetDeviceCaps(PLANES)`. The selected width/height remain the values decoded from configuration.
- `FUN_004ae610`, registered as the DirectDraw display-mode enumeration callback, records width, height, and bit depth from each enumerated mode into a linked list. `FUN_004b0063` compares packed mode dimensions/depth against that list when deciding whether a mode is usable. The decompiled output does not identify a fixed shipped mode selection.

### Surface creation

- `FUN_004ae6a7` creates the DirectDraw object, enumerates display modes, then branches on windowed versus fullscreen mode. Cooperative-level and surface-creation failures are routed through `FUN_004b0969` with operation-specific error labels.
- Windowed: sets normal cooperative level (`0x8`), creates the primary surface with descriptor size `0x6c`, `DDSD_CAPS` (`dwFlags=0x1`), and primary-surface caps (`dwCaps=0x200`). It then creates a separate configured offscreen surface through `FUN_004b1510` and stores it in `DAT_004e8ecc`.
- Fullscreen: sets exclusive/fullscreen cooperative level (`0x15`), calls `SetDisplayMode` with decoded width, height, and depth, then creates the primary surface with descriptor flags `0x21` and caps `0x218` (primary + flip + complex), requesting one backbuffer. An option can add `0x2000` to the caps. It obtains the attached backbuffer with `GetAttachedSurface`, stored in `DAT_004e8ecc`.
- `FUN_004b1510` creates configured offscreen surfaces with descriptor flags initially `0x7` (caps, height, width), width/height from the packed mode, and caps initially `0x40` (offscreen plain). It adjusts caps/flags for option bits and for 8-bit/pixel-format-specific cases. Exact meanings of every option bit and descriptor-local field need confirmation against the original DirectDraw headers/disassembly before reimplementation.

### Pixel formats

- At 8 bpp, initialization constructs a 256-entry DirectDraw palette and attaches it to both the primary and secondary surfaces. Palette entries 10 through 245 are marked as reserved/static according to the final entry flag written by the initializer.
- At 16 bpp, initialization queries the primary surface pixel format and checks the green mask against `0x07e0`; equality selects the RGB565 path.
- Pixel conversion helpers explicitly support 8-bit indexed data and two 16-bit layouts: RGB555 masks `R=0x7c00, G=0x03e0, B=0x001f`, or RGB565 masks `R=0xf800, G=0x07e0, B=0x001f`. The 16-bit blit conversion preserves palette index zero as transparent.
- The mode decoder can represent 24- and 32-bit depths, but the inspected surface/pixel helpers have explicit branches only for 8 and 16 bpp. Do not infer full 24/32-bit game rendering support from the mode bitfield alone.

### Presentation and lifecycle

- `FUN_004ae460(source, primary)` is the present helper. In windowed mode it obtains the window client rectangle, converts it to screen coordinates, and calls primary-surface `Blt` to copy the source surface into that rectangle.
- In fullscreen mode, when the source is the attached backbuffer, it calls primary-surface `Flip`. Other fullscreen sources use the copy/blit helper (`FUN_004b0370`) with a full-surface destination rectangle.
- Startup `FUN_004b015a` clears the secondary surface and presents it three times. The clear helper `FUN_004b02fd` uses `Blt`; the presentation helper then takes the windowed blit or fullscreen flip branch above.
- Surface locks use `Lock`/`Unlock` wrappers (`FUN_004b0264`/`FUN_004b021a`) and retain the returned pixel pointer and pitch. Drawing code uses the pitch for row addressing. `FUN_004b0fef` wraps `Restore` for surfaces lost during display changes.

The exact native resolution at runtime remains dependent on configuration/display enumeration. The description above is a static reconstruction from Ghidra output, not a capture of a running Windows build.

## OpenGL mapping implemented

`src/linux/renderer.h` and `renderer.c` provide the first native counterpart to the recovered surface-to-primary flow:

| Original flow | Native presenter |
| --- | --- |
| DirectDraw offscreen/secondary surface | Caller-owned pixel buffer with explicit width, height, pitch, and format |
| 8-bit indexed surface plus DirectDraw palette | `LL_PIXEL_INDEX8` plus a 256-entry RGBA palette expanded to RGBA8 before upload |
| 16-bit RGB555/RGB565 pixel conversion | `LL_PIXEL_RGB555` / `LL_PIXEL_RGB565`, expanded on CPU to RGBA8 |
| Lock surface, draw using returned pitch, unlock | Pass pixels and pitch to `ll_renderer_present`; validates byte extent before reading |
| Windowed primary `Blt` to client area | Upload to a nearest-filtered OpenGL texture, draw it over the current drawable viewport |
| Fullscreen primary `Flip` from attached backbuffer | Same texture upload/draw operation followed by SDL's double-buffer swap |
| Surface loss/restore | Not implemented yet; SDL context/window loss recovery remains follow-up work |

The presenter retains the original configured surface dimensions and scales to the drawable. It intentionally does not claim to emulate DirectDraw's mode enumeration, palette reservation flags, color key/transparency behavior, exclusive fullscreen mode, or lost-surface semantics. RGB555/RGB565 conversion and indexed palette lookup are exercised by `src/linux/renderer_test.c`, which also checks RGBA framebuffer output and rejects truncated buffers/short pitches. The authentic startup logo exercises RGBA upload; recovered game frame callbacks are not connected yet.

## Original startup logos

Startup order in `FUN_004067e0` names `APLOGO.PCX` before the language-specific image. The logo pixels are not embedded in `Game.run`: both images are members of `win/graphics/FONT.KXP`. The Linux runtime reads this archive through `cd_mount`, validates the KXP index and member bounds, checks the original 32-byte encrypted-archive discriminator at offset `0x05`, applies the game's conditional repeating-key decode (`lucky`), and passes the resulting PCX bytes to the bounded PCX decoder. It displays `APLOGO.PCX`, then the configured language member (`LI_EN.PCX`, `LI_FR.PCX`, `LI_GE.PCX`, `LI_SP.PCX`, `LI_IT.PCX`, `LI_DU.PCX`, or `LI_BR.PCX`). In the original `FUN_00449bc0`, each image is presented for up to 600 iterations; skip input is only accepted when the loop counter is greater than 300. These are separate calls, so the localized logo gets a fresh timer and skip decision even if `APLOGO.PCX` was skipped. The SDL port follows that 60 Hz frame counter and those strict/inclusive boundary checks. `skip_intro=true` bypasses both.

`scripts/extract_kxp.py` remains available for offline inspection and validates KXP members before writing generated copies. `FUN_00449bc0` first checks the `.pcx` suffix (`FUN_00449b60`); that path opens `FONT.KXP`, retrieves the named member using the `lucky` key, and sends it to `FUN_00431fe0`. The game decoder accepts either 8-bit indexed PCX with a 256-color palette or 24-bit RGB PCX, then converts the result to the active 16-bit surface format. `src/linux/pcx.c` now handles both formats, validates dimensions and scanline stride, decodes bounded PCX RLE, and converts image pixels to RGBA. The runtime startup renderer centers and fits each decoded image without stretching.

Re-extract with:

```sh
python3 scripts/extract_kxp.py /path/to/LuckyLuke/win/graphics/font.kxp APLOGO.PCX assets/startup/aplogo.pcx
```

## Main-menu status

Startup sets state `DAT_004e8914 = 1`, whose SOOL script path resolves to `CINEMA/OPTION/option.cod` (`FUN_00405350`). The state setup separately loads localized `.BIZ` and `.BIB` resources: `FUN_0044baa0`/`FUN_0044b320` parse BIZ geometry, sprite, tile, and texture-page data; BIB is loaded into `DAT_004e8820` and indexed by animation/object handlers. `FUN_00404be0` is the AVI playback routine (it calls `AVIFileOpenA`, reads frames, and writes embedded audio); it does not load scene resources. The Linux parser derives the variable selector-table size from each aligned 3DX grid root, then decodes BIB geometry, transforms, animation-table offsets, and SOOL script boundaries. `src/linux/sool.c` decodes VM instruction boundaries and immediate words; `ll_bib_decode_packed_pose` exposes the sparse pose flags and signed channels consumed by the animation decoder. The original menu is a scripted 3D scene, not a single image; the Linux target does not yet implement its original scene interpreter or Win3DX renderer.

The Linux scene now reflects the observed composition: night-time western street, Lucky Luke on the left swinging a weapon, and exactly GAME and OPTIONS on arrow selectors. The city, character, moon, and menu presentation are procedural OpenGL geometry, not recovered original models or textures.

Original menu art can be dropped in as PCX files under `assets/menu/`:
- `background.pcx` — full-screen menu background
- `button_yes.pcx` — selected menu button
- `button_no.pcx` — unselected menu button

`src/linux/menu_art.c` loads these (decoded from localized `menu_e.kxp`/`menu_f.kxp`/`menu_d.kxp`/… archives via `scripts/extract_kxp.py`) into nearest-filtered OpenGL textures and draws them as quads, with graceful fallback to the procedural drawing when a file is missing or undecodable. The decompiled original loads `win\graphics\menu_<lang>.kxp` members such as `exity.pcx`/`exitn.pcx` (exit button yes/no) and `win\graphics\newmenu.kxp` members such as `woodtra.pcx`/`woodsal.pcx`/`woodtex.pcx`.

`MENU_E.KXP` contains pause/continue/exit controls and is not used as main-menu art. The original `win/drivers/software.w3x` exists, but Wine produced a black reference in this environment. Exact visual parity still requires recovering the OPTION BIB records and SOOL-driven scene objects.

Re-extract menu PCX members with:

```sh
python3 scripts/extract_kxp.py /path/to/LuckyLuke/win/graphics/menu_e.kxp EXITN.PCX assets/menu/button_no.pcx
python3 scripts/extract_kxp.py /path/to/LuckyLuke/win/graphics/menu_e.kxp EXITY.PCX assets/menu/button_yes.pcx
```

## First level: Abilene (state 2)

`FUN_00405350` maps state `DAT_004e8914 = 2` to `abilene\abilene.cod`, the first level. `FUN_00441560` loads the level's assets from `abilene\abilene.kxp` (`back.pcx` background, `coin1.pcx`…`coin11.pcx` animated coins) and `win\graphics\fixgfx.kxp` (`wood.pcx`, `moon.pcx`, `wanted.pcx`).

The Linux port mirrors this in `src/linux/level.c`/`level.h` and `src/linux/kxp.c`/`kxp.h`:

- `ll_kxp_open()` / `ll_kxp_find()` read a KXP archive from memory, validating the signature, version, index bounds, entry records, and payload ranges, with the conditional repeating-key XOR decode (key `"lucky"`) for encrypted archives.
- `ll_level_init()` / `ll_level_destroy()` manage the level renderer and decoded background surface.
- `ll_level_set_state()` switches game state (1 = menu, 2 = Abilene).
- `ll_level_load_background_from_archive()` decodes a PCX member from a KXP archive into RGBA pixels.
- `ll_level_render()` presents the background as a fitted OpenGL texture, or returns 0 so the caller can fall back to procedural rendering.

The native main loop transitions from menu (state 1) to Abilene (state 2) when GAME is selected, and returns to the menu on Escape. When the `abilene.kxp` archive and its `back.pcx` member are available, the level background is rendered from the original art; otherwise a procedural night-western scene is drawn as a fallback.

Re-extract level assets with:

```sh
python3 scripts/extract_kxp.py /path/to/LuckyLuke/abilene/abilene.kxp BACK.PCX /tmp/back.pcx
```

## First level gameplay: Abilene (state 2)

The native port now includes a playable first level. `src/linux/level.c`/`level.h`
manages the game state (1 = menu, 2 = Abilene) and loads the level background
from `abilene\abilene.kxp` via `src/linux/kxp.c`/`kxp.h`. When the archive and
its `back.pcx` member are available, the background is rendered from the
original art; otherwise a procedural night-western scene is drawn.

`src/linux/object.c`/`object.h` provides a generic game object list with
update/render/destroy callbacks and PCX sprite loading. `src/linux/gameplay.c`
`gameplay.h` implements the first-level gameplay:

- Player object (Lucky Luke): left/right movement, jumping, gravity, ground
  collision. Animated running frames (`RUN1.PCX`…`RUN4.PCX` from `fixgfx.kxp`)
  when moving, rendered as a colored rectangle in procedural fallback mode.
- Coin objects: animated bobbing and spinning through `coin1.pcx`…`coin11.pcx`
  from `abilene.kxp`, collected on contact with the player, then removed.
  Rendered as yellow procedural rectangles when archives are unavailable.
- Coins spawn periodically; player spawns at level start.
- Input: Left/A and Right/D move, Space/Up/W jumps, Escape returns to the menu.

The main loop transitions from menu (state 1) to Abilene (state 2) when GAME is
selected, and returns to the menu on Escape. Gameplay input is routed to
`ll_gameplay_key_down()`/`ll_gameplay_key_up()` when in state 2.

## Original COD, BIB, and BIZ resources

`FUN_00405350` selects `abilene\\abilene.cod` for state 2. Original `.cod`
files begin with the bytes `SOOL` and are submitted to the SOOL runtime; they
are not the object/sprite/tile/page container described in the existing native
`src/linux/cod.c` parser. That parser expects a CRC3 footer and an experimental
header schema, and does not parse the original `.cod` files.

The object/sprite/tile/page layout is instead evidenced in `.biz` resources.
For a scene stem, `FUN_004056d0` appends `.BIZ` and calls `FUN_0044baa0`;
`FUN_0044b320` reads the first DWORD as an offset to seven DWORD header fields,
then reads object entries (4 bytes each), sprite entries (20 bytes each), tile
records (16 bytes each), and packed texture pages (0x8000 bytes each). The
second BIZ DWORD points to a sound table after the texture pages. The French
menu file `option_f.biz` provides a consistency check: offset 8, counts
`0x132/0x117/0x95/14`, and sound-table offset `0x72408`, exactly the boundary
after its arrays and texture pages. `FUN_0041ebe0` loads the sound entries from
that table when digital sound is enabled. The 12 menu samples use `VAGp`
headers and report 16 kHz; `FUN_00492610` decodes their framed ADPCM payloads.

The paired `.bib` resource is loaded separately into `DAT_004e8820`. In the
French file, DWORD 0 is `0x25528`, the offset of an embedded `SOOL` marker;
71 selector DWORDs occupy offsets `0x04..0x11f`. Selector 12 resolves to a
grid section at `0x120`, with `3DX\0` at `0x130`. The catalogue contains 42
24-byte records beginning at `0x140`; their names include `OPFOND1`,
`PANCART2FR3DK`, and `LUCKY3DK`. Descriptor references are stored in
four-byte units relative to the grid section. The localized sign name changes
to `PANCART2AN3DK` in English and `PANCART2AL3DK` in German.

The native BIB reader derives the variable selector-table size from the
aligned 3DX grid root and parses the catalogue, parent-linked geometry groups,
vertices, transforms, bounds, animation tables, and SOOL script boundaries.
`ll_sool_decode_script` decodes instruction boundaries and immediate operands
while retaining per-instruction raw bytes. The packed-pose helper decodes the
three presence groups and nine optional signed 16-bit channels. Selector
payloads without a known schema remain bounded raw spans. The animation-table
to-pose pointer map is not established, so animation records remain raw until
individual pose payloads have been identified.

The current port's `ll_cod_*` interface is still an experimental reader, not
a faithful SOOL interpreter. `ll_sool_decode_script` provides structural
bytecode decoding, but not execution or semantic resolution of game-specific
commands and variables. KXP archive and PCX handling are separate; see the
asset-loading sections above.

The BIZ reader (`src/linux/biz.c`) validates the seven-DWORD header,
object/sprite/tile tables, and packed texture-page spans. Object entries bind
one sprite index to one tile index; sprite records contain dimensions, atlas
coordinates, and a palette-slot field. The renderer reads each 16-byte tile
entry's signed palette X/Y at `+0/+2` and masked texture-page index at `+0x0c`;
the remaining words are preserved as opaque fields. These records serve texture
and CLUT lookup, with no recovered evidence that they encode collision. The
inspected BIZ layout has no separate
timeline or animation-script directory. In the recovered executable, timed
scene-object changes are driven by registered SOOL/native callbacks (for
example, `FUN_004126d0` creates a two-lane controller and `FUN_00412790`
initializes its per-lane coordinates and counters). The callback arguments
have not yet been mapped to BIZ object IDs, so a complete scene timeline is
still open work.

The similarly named `src/linux/cod.c` parser accepts an experimental CRC3
schema and does not parse original COD assets. Original `.cod` files are SOOL
scripts; the TODO tracks finding the real level geometry/collision source
instead of treating those scripts or BIZ texture tiles as collision maps.

## Native BIB parser status

`src/linux/bib.c` derives the selector count from the aligned 3DX root (71 in
the French menu BIB), retains bounded selector spans, and parses the embedded
SOOL script-offset table. For 3DX catalogues it exposes model names, parent
references, vertices, typed groups and primitive fields, orientation bases,
anchors, and bounds. Animation sections expose record offsets, sample counts,
and bounded raw payloads; a separate helper decodes the engine's sparse pose
mask and channel words when given one packed pose. The native renderer still
does not construct the original scene.

## `Always3D.dll` responsibilities and interface

The bundled `orig/Always3D.dll` is a 32-bit PE DLL with image base `0x10000000` and a single imported module, `KERNEL32.dll`. Its export table contains 14 undecorated names:

| Export | Likely role from name |
| --- | --- |
| `A3D_Init` | Initialize the renderer/library |
| `A3D_Done` | Shut down the renderer/library |
| `A3D_BeginFrame`, `A3D_EndFrame` | Frame lifecycle |
| `A3D_DrawPolygon` | Submit/rasterize a polygon |
| `A3D_SetRaster`, `A3D_SetTexture` | Select raster target/state and texture |
| `A3D_SetParameters`, `A3D_SetFlags` | Configure rendering parameters and flags |
| `A3D_SetMipLevel` | Select texture mip level |
| `A3D_SetCycle` | Select a rendering/texture cycle; exact meaning unknown |
| `A3D_SetXlu` | Configure a likely translucency mode; exact meaning unknown |
| `A3D_Sync` | Synchronize renderer work |
| `view` | Exported view-related function; exact purpose unknown |

The API names, the DLL string `SBuffer_Rasterise: ... span ... uv ...`, and the absence of graphics-driver imports strongly suggest a CPU-side polygon/texture rasterizer with its own frame and raster state. This is an inference from names, strings, and imports; no argument types, calling conventions, structure layouts, or full function semantics have yet been recovered. `objdump` shows the exports are small jump stubs into internal code, so those stubs alone do not establish prototypes.

The game executable's decompiled plugin loader is a separate interface. `FUN_0047b0f0` loads a selected file from `drivers\\` and resolves `wx*` exports such as `InitWin3DX`, `wxBeginFrame`, `wxDrawPrim_PFT3`, `wxUploadTexturePage`, and `wxFlipScreen`. The main executable contains driver-selection strings (`windowed.w3x`, `3DFX.W3X`, `Win3DX Software`) but no `Always3D` or `A3D_*` strings, and the decompiled game sources contain no `A3D_*` callsites. Therefore, the bundled `Always3D.dll` is confirmed as a renderer-like companion library, but its direct use by this particular `Game.run` executable is not established; it is not the `wx*` driver loaded by that code path.

For the Linux port, treat DirectDraw presentation and the `wx*` Win3DX driver as confirmed game interfaces. Do not make `Always3D.dll` a runtime dependency or port its ABI until a caller, matching binary version, or recovered prototype proves it participates in the game's execution.

## CD mount configuration

The Linux runtime reads `config.ini` from its current working directory. Set
`cd_mount` to the directory where the original CD or ISO is mounted; the
provided config uses `/run/media/nicolas/LuckyLuke` as the local default. The
runtime joins that root with CD-relative paths when loading `FONT.KXP` startup
logos, the main-menu scene, Abilene's COD/KXP files, and `FIXGFX.KXP`. For
example:

```ini
cd_mount=/media/cdrom
skip_intro=false
language=e
```

`skip_intro` accepts `true`/`false` (also `1`/`0`, `yes`/`no`, and
`on`/`off`). When false, the port displays the Aqua Pacific logo and the
language-specific startup image from `FONT.KXP`, each for up to ten seconds.
Any key or mouse click skips the remaining startup images after the five-second
minimum, matching the original routine's 300/600 loop-iteration thresholds.
The default is `false`, so startup shows the logos unless the config opts out.
`language` selects the localized menu scene by its original resource code:
`e`, `f`, `d`, `s`, `i`, `u`, or `b`. The default is English (`e`).

If the config is missing, the mount path is invalid, or an asset cannot be
loaded, the runtime reports it on stderr and shows an asset error panel on the
main menu. Local, extracted menu PCX files under `assets/menu/` remain
relative to the launch working directory.

## Next porting work

- Recover the timing and transitions from the startup images into the original introductory video.
- Recover the game loop and state transitions from the decompiled functions before replacing platform APIs.
- Identify the original asset formats before implementing replacements; `Always3D.dll` exports are catalogued above, but its direct connection to `Game.run` is unproven.
- Port input and audio behind small platform interfaces after their original behavior is documented.

## Options menu

The original SOOL/BIB options screens now run in the Linux port:

- S.F.X: native sprite panel, mono/stereo, effects/music volume controls and
  CD-track state. Up/Down selects a row; Left/Right changes it. Backspace
  cancels and restores the values from entry. These values live for the session.
- Mot de passe: original wanted poster and four symbols, changed through the
  script. Password lookup uses the ten code/level pairs from the executable;
  unmatched codes select level 2, matching the original fallback. This does
  not implement loading every selected gameplay level.
- Manette: original configuration board. Left/Right selects A/B/C; Enter
  validates the configuration. Space is the script's help/handedness toggle,
  switching the movement/action maps and the original key textures.
- Backspace returns from submenus; select Retour and press Enter to return
  to the main menu. Enter opens/validates selections. The script handles
  symbol changing with Space in the password screen.

The UI uses original assets and script transitions. Menu digital effects now
use the BIZ sound bank through a 16000 Hz stereo SDL device. `sound=false`
skips audio initialization. The SFX volume controls a software master gain;
mono/stereo affects newly configured voices. Positional sound calls use their
owner object's projected horizontal position to gate playback. CD music, some additional
voice commands, saving options, and applying all profiles to gameplay remain
unfinished. `LL_TRACE_AUDIO=1` logs played sample names and voice slots.

The movement/action maps follow the native A/B/C permutations for SOOL input.
CD path lookup accepts the original mixed-case ISO filenames.
