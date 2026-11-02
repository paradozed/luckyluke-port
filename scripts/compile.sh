#!/usr/bin/env bash
# Compile build/Lucky.c with i686-w64-mingw32-gcc (i386 Windows PE/GUI).
#
# Usage: scripts/compile.sh [CC]
#
# CC defaults to i686-w64-mingw32-gcc.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SRC="$ROOT/src"
BUILD="$ROOT/build"
CONSOLIDATED="$BUILD/Lucky.c"
EXE="$BUILD/Lucky.exe"
LOG="$ROOT/work/logs/compile.log"

CC="${1:-${CC:-i686-w64-mingw32-gcc}}"

if ! command -v "$CC" >/dev/null 2>&1; then
  echo "ERROR: i386 Windows cross-compiler not found ($CC)."
  echo "  Install mingw-w64 (provides i686-w64-mingw32-gcc)."
  exit 1
fi

if [ ! -f "$CONSOLIDATED" ]; then
  echo "ERROR: $CONSOLIDATED not found. Run scripts/consolidate.sh first."
  exit 1
fi

echo "Using: $CC ($($CC --version | head -1))"

mkdir -p "$BUILD" "$(dirname "$LOG")"

# -m32: i386 target
# -nostdlib: we link our own entry
# -e _start: entry point
# -s: strip
# -Wl,--subsystem,windows: GUI subsystem
# Warnings are expected from Ghidra pseudo-C; -fpermissive turns many
# constraint violations into warnings. Only hard errors stop the build.
set +e
"$CC" -m32 -O2 -std=gnu89 -fno-exceptions -fno-unwind-tables -fpermissive \
  -I"$ROOT/include" \
  -Wno-return-type -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast \
  -Wno-int-conversion -Wno-implicit-function-declaration \
  -Wno-incompatible-pointer-types -Wno-discarded-qualifiers \
  -Wno-return-type-mismatch -Wno-unused-but-set-variable \
  -Wno-unused-variable -Wno-unused-function -Wno-strict-prototypes \
  -nostdlib -e _start -s \
  -Wl,--subsystem,windows \
  -o "$EXE" \
  "$CONSOLIDATED" \
  -lkernel32 -luser32 -lgdi32 -ladvapi32 -lwinmm -ldinput -lddraw -lavifil32 -ldsetup \
  2>"$LOG"
compile_rc=$?
set -e

echo "Compile exit: $compile_rc (see work/logs/compile.log)"
if [ $compile_rc -ne 0 ]; then
  echo "First errors:"
  grep -E 'error:' "$LOG" | head -20
  exit "$compile_rc"
fi
echo "Built: $EXE ($(stat -c%s "$EXE") bytes)"
