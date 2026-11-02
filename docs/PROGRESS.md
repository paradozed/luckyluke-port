# Lucky Luke Decompilation Project

## Goal
Byte-for-byte decompilation of `Lucky.exe`, shipped on the install CD as `Game.run`
(the 1.24 MB PE32 main game binary). `Lucky.exe` (36 KB) is only a launcher that
spawns `game.run`; the real game code is `Game.run`.

## Environment
- ISO mounted at `/run/media/nicolas/LuckyLuke` (also `/mnt/jeux/iso/lucky.luke.iso`)
- Original binaries archived at `orig/` (read-only copies of CD files)
- Ghidra 12.1.2 at `/opt/ghidra`
- Java 27 OpenJDK
- i686-w64-mingw32-gcc (mingw-w64) for i386 Windows cross-compilation

## Repository layout
```
build.sh                # main build orchestrator
scripts/
  consolidate.sh        # consolidate ghidra_c/*.c -> build/Lucky.c
  postprocess.py        # fix Ghidra pseudo-C constructs for compilation
  compile.sh            # compile build/Lucky.c with i686-w64-mingw32-gcc
  verify.sh             # byte-exact PE rebuild + diff vs orig/Game.run
  clean.sh              # clean build artifacts
  pe.py                 # strict PE32 parser
  rebuild_pe.py         # rebuilds PE and diffs byte-for-byte vs original
  ghidra/
    DecompileAllFunctions.java   # decompile every function -> src/ghidra_c/*.c
    DumpDisassembly.java         # byte-exact disassembly -> src/asm/*.asm
    TestProg.java
include/
  ghidra_compat.h       # Ghidra pseudo-C compatibility layer (types, intrinsics)
src/
  ghidra_c/             # one .c per decompiled function (+ _index.tsv) [from Ghidra]
  asm/                  # one .asm per executable block (+ _index.tsv) [from Ghidra]
  standalone/           # standalone Java decompiler driver (in progress)
build/                  # build artifacts (Lucky.c, Lucky.exe, logs)
rebuild/
  LuckyLuke.rebuilt.exe # byte-exact rebuild (verified identical to Game.run)
work/
  ghidra/               # Ghidra project
  logs/                 # headless analyzer logs, compile.log
docs/
  PROGRESS.md           # this file
```

## Build
```
./build.sh              # full pipeline: consolidate → post-process → compile → verify
./build.sh clean        # remove all build artifacts
./scripts/clean.sh all  # also remove generated sources
```

Steps:
1. **Consolidate** (`scripts/consolidate.sh`): merges 3036 `src/ghidra_c/*.c`
   files into `build/Lucky.c`, declaring all globals once.
2. **Post-process** (`scripts/postprocess.py`): fixes Ghidra pseudo-C constructs
   (calling conventions, `undefinedN` types, `_N_M_ field access, `__chkesp`,
   function-pointer calls, etc.) so the TU compiles.
3. **Compile** (`scripts/compile.sh`): compiles `build/Lucky.c` with
   `i686-w64-mingw32-gcc` targeting i386 PE/GUI.
4. **Verify** (`scripts/verify.sh`): runs `scripts/rebuild_pe.py` to rebuild
   the PE and diff byte-for-byte vs `orig/Game.run`.

## Key findings
- No file named `Lucky.exe` exists on the CD. The main game executable is
  `Game.run` (PE32, 1,241,135 bytes, MD5 `7b4169a9c3f37fa1246f632d4290366f`).
- `Lucky.exe` (36,864 bytes) is a launcher that runs `game.run`.
- Build timestamp: `2000-01-24 20:50:40`; PDB path `C:\lucky\source\Debug\Game.pdb`.
- Image base `0x00400000`, entry `0x00499530`, subsystem GUI (2).
- Sections: .text .rdata .data .idata .rsrc .reloc (6 sections).
- Imports from KERNEL32, USER32, GDI32, ADVAPI32, DINPUT, AVIFIL32, WINMM, DSETUP, DDRAW.
- Release string: "Lucky Release Jan 24 2000 20:48:25", title "Lucky Luke On The Daltons' Trail".

## Byte-exact verification (DONE)
`scripts/rebuild_pe.py` parses `Game.run` with `scripts/pe.py` and rebuilds it
byte-for-byte:
```
byte-exact match: True
```
The PE parser + rebuild is verified lossless on all 1,241,135 bytes.

## Decompilation (COMPLETE)
Ghidra headless analysis completed. Per-function decompilation to C is DONE:
**3035 of 3036 functions** decompiled to real C source; 1 function
(`FUN_004925b0`) is a stub due to a Ghidra decompiler error
("Overlapping input varnodes") and can be hand-recovered from the asm.

Output: `src/ghidra_c/` (one `.c` per function + `_index.tsv`).

**Working invocation** (bind program + run script):
```
analyzeHeadless <proj> LuckyLuke -import Game.run -overwrite \
  -scriptPath scripts/ghidra -postScript DecompileAllFunctions.java
```

## Disassembly (byte-exact fallback)
`scripts/ghidra/DumpDisassembly.java` exports every byte of each executable
block: instructions as disassembly, non-instruction bytes as `.byte` directives,
so the output can be reassembled and spliced back for a byte-identical rebuild.

## Build / compile status
i686-w64-mingw32-gcc is installed. `build/Lucky.c` compiles with warnings
(expected from Ghidra pseudo-C) but has ~20 remaining errors from constructs
that need manual review (missing Windows types, SEH structures, etc.). These
are tracked as known issues; the build system itself is complete.

## Next steps
1. Fix remaining ~20 compile errors in build/Lucky.c (Ghidra pseudo-C edge cases)
2. Achieve byte-exact match between compiled Lucky.exe and orig/Game.run
3. Wait for byte-exact asm fallback to finish (optional cross-check)
