#!/usr/bin/env bash
# Build harness for the Lucky Luke byte-for-byte decompilation project.
#
# Pipeline:
#   1. Verify the original Game.run is present
#   2. Consolidate decompiled C sources (src/ghidra_c/*.c) into build/Lucky.c
#   3. Post-process Ghidra pseudo-C constructs so the TU compiles
#   4. Compile build/Lucky.c with i686-w64-mingw32-gcc (i386 PE/GUI)
#   5. Rebuild the PE and diff byte-for-byte vs orig/Game.run (verification)
#
# Decompilation via Ghidra is already complete (src/ghidra_c/ contains one .c
# per function). Re-running Ghidra is intentionally out of this script: its
# script paths are machine-specific. Re-run scripts/ghidra/DecompileAllFunctions.java
# manually if you need fresh decompilation.
#
# Usage: build.sh [clean|all]
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS="$ROOT/scripts"
TARGET="$ROOT/orig/Game.run"

echo "== Lucky Luke byte-for-byte decompilation =="
echo "Root:  $ROOT"
echo "Target: $TARGET"

# --- Step 0: optional clean ---------------------------------------------------
if [ "${1:-}" = "clean" ]; then
  "$SCRIPTS/clean.sh" all
  exit 0
fi

# --- Step 1: verify the original binary --------------------------------------
if [ ! -f "$TARGET" ]; then
  echo "ERROR: $TARGET not found."
  echo "  Copy it from the mounted CD:"
  echo "    cp /run/media/nicolas/LuckyLuke/Game.run $ROOT/orig/"
  exit 1
fi
echo "Target: $TARGET ($(stat -c%s "$TARGET") bytes, MD5 $(md5sum "$TARGET" | cut -d' ' -f1))"

# --- Step 2: consolidate decompiled C into build/Lucky.c ---------------------
echo ""
echo "=== CONSOLIDATE ==="
"$SCRIPTS/consolidate.sh"

# --- Step 3: post-process Ghidra pseudo-C constructs -------------------------
echo ""
echo "=== POST-PROCESS ==="
python3 "$SCRIPTS/postprocess.py" "$ROOT/src/ghidra_c" "$ROOT/build/Lucky.c"

# --- Step 4: compile ---------------------------------------------------------
echo ""
"$SCRIPTS/compile.sh"

# --- Step 5: byte-exact PE verification --------------------------------------
echo ""
"$SCRIPTS/verify.sh" "$TARGET" "$ROOT/rebuild/LuckyLuke.rebuilt.exe"

echo ""
echo "== Build complete =="
