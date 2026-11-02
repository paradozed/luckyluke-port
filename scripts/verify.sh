#!/usr/bin/env bash
# Byte-exact PE verification: rebuild Game.run and diff vs original.
#
# Usage: scripts/verify.sh [src_pe] [out_rebuilt]
#
# Defaults: src_pe=orig/Game.run, out_rebuilt=rebuild/LuckyLuke.rebuilt.exe
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ORIG="$ROOT/orig"
REBUILD="$ROOT/rebuild"

SRC="${1:-$ORIG/Game.run}"
OUT="${2:-$REBUILD/LuckyLuke.rebuilt.exe}"

if [ ! -f "$SRC" ]; then
  echo "ERROR: $SRC not found."
  echo "  Copy it from the mounted CD:"
  echo "    cp /run/media/nicolas/LuckyLuke/Game.run $ORIG/"
  exit 1
fi

echo "=== BYTE-EXACT VERIFICATION ==="
python3 "$ROOT/scripts/rebuild_pe.py" "$SRC" "$OUT"
