#!/usr/bin/env bash
# Clean build artifacts.
#
# Usage: scripts/clean.sh [all]
#
# Without 'all', only build/ output is removed. With 'all', also removes
# the generated build/Lucky.c and rebuild output.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD="$ROOT/build"
REBUILD="$ROOT/rebuild"

echo "Cleaning build artifacts..."
rm -rf "$BUILD"/*
rm -f "$REBUILD"/*.exe

if [ "${1:-}" = "all" ]; then
  echo "Also removing generated sources..."
  rm -f "$BUILD/Lucky.c"
fi

echo "Done."
