#!/usr/bin/env bash
# Consolidate decompiled C sources (src/ghidra_c/*.c) into build/Lucky.c,
# injecting the Ghidra pseudo-C compatibility header and definitions for all
# DAT_/PTR_/s_/uRam_/piRam_ globals.
#
# Usage: scripts/consolidate.sh
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SRC="$ROOT/src"
GHIDRA_C="$SRC/ghidra_c"
COMPAT_H="$ROOT/include/ghidra_compat.h"
BUILD="$ROOT/build"
CONSOLIDATED="$BUILD/Lucky.c"

if [ ! -d "$GHIDRA_C" ]; then
  echo "ERROR: $GHIDRA_C missing. Decompile with Ghidra first."
  exit 1
fi

shopt -s nullglob
c_files=("$GHIDRA_C"/*.c)
shopt -u nullglob

if [ "${#c_files[@]}" -eq 0 ]; then
  echo "ERROR: no .c files in $GHIDRA_C. Decompile with Ghidra first."
  exit 1
fi

echo "Consolidating ${#c_files[@]} functions -> $CONSOLIDATED"

# Collect every global identifier referenced anywhere in the decompiled sources
globals=$(grep -hoE '(_DAT_|DAT_|PTR_|s_|uRam|piRam|stack0x)[0-9A-Za-z_]*' "$GHIDRA_C"/*.c \
  | sort -u)

mkdir -p "$BUILD"
{
  echo "/* ====================================================================="
  echo " * Lucky Luke On The Daltons' Trail"
  echo " * Decompiled from Game.run (Lucky.exe), PE32, imageBase 0x00400000"
  echo " * Auto-generated from src/ghidra_c/ by scripts/consolidate.sh"
  echo " * DO NOT EDIT BY HAND - regenerate from src/ghidra_c/"
  echo " * ===================================================================== */"
  echo ""
  echo "/* Target imports: KERNEL32 USER32 GDI32 ADVAPI32 DINPUT AVIFIL32 WINMM DSETUP DDRAW */"
  echo "#include <windows.h>"
  echo "#include <stdio.h>"
  echo "#include <stdbool.h>"
  echo "#include <mmsystem.h>"
  echo "#include <dinput.h>"
  echo "#include <ddraw.h>"
  echo "#include <commdlg.h>"
  echo "#include \"ghidra_compat.h\""
  echo ""
  echo "/* --- Global data (DAT_ / _DAT_ / PTR_ / s_ / uRam_ / piRam_) defined once --- */"
  echo "/* DAT_/PTR_ as unsigned int; s_ as char arrays; piRam_ as unsigned int *; */"
  echo "/* uRam_ as unsigned int. Warnings are expected.                       */"
  while IFS= read -r g; do
    [ -n "$g" ] || continue
    if [[ "$g" == s_* ]]; then
      echo "char $g[256] = {0};"
    elif [[ "$g" == piRam* ]]; then
      echo "unsigned int *$g = (unsigned int *)0;"
    else
      echo "unsigned int $g = 0;"
    fi
  done <<< "$globals"
  echo ""
  echo "/* ExceptionList (SEH) */"
  echo "void *ExceptionList = (void *)0;"
  echo ""
} > "$CONSOLIDATED"

n=0
for f in "${c_files[@]}"; do
  echo "" >> "$CONSOLIDATED"
  echo "/* ---------- $(basename "$f") ---------- */" >> "$CONSOLIDATED"
  cat "$f" >> "$CONSOLIDATED"
  echo ";" >> "$CONSOLIDATED"
  echo "" >> "$CONSOLIDATED"
  n=$((n + 1))
done
echo "Consolidated $n functions, $(stat -c%s "$CONSOLIDATED") bytes"