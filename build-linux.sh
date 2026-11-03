#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SOURCES=("$ROOT/src/linux/main.c" "$ROOT/src/linux/audio_mix.c" "$ROOT/src/linux/native_camera.c" "$ROOT/src/linux/asset_config.c" "$ROOT/src/linux/menu_art.c" "$ROOT/src/linux/pcx.c" "$ROOT/src/linux/kxp.c" "$ROOT/src/linux/level.c" "$ROOT/src/linux/renderer.c" "$ROOT/src/linux/object.c" "$ROOT/src/linux/gameplay.c" "$ROOT/src/linux/cod.c" "$ROOT/src/linux/bib.c" "$ROOT/src/linux/biz.c" "$ROOT/src/linux/sool.c")
OUTPUT="$ROOT/build/linux/lucky-luke"
TEST_OUTPUT="$ROOT/build/linux/renderer-test"
PCX_TEST_OUTPUT="$ROOT/build/linux/pcx-test"
SOOL_TEST_OUTPUT="$ROOT/build/linux/sool-test"
BIZ_SOUND_TEST_OUTPUT="$ROOT/build/linux/biz-sound-test"
AUDIO_MIX_TEST_OUTPUT="$ROOT/build/linux/audio-mix-test"
NATIVE_CAMERA_TEST_OUTPUT="$ROOT/build/linux/native-camera-test"
BIB_POSE_TEST_OUTPUT="$ROOT/build/linux/bib-pose-test"
CC="${CC:-cc}"

if ! command -v "$CC" >/dev/null 2>&1; then
  echo "ERROR: C compiler not found ($CC)." >&2
  exit 1
fi

if ! command -v pkg-config >/dev/null 2>&1; then
  echo "ERROR: pkg-config is required to locate SDL2 and OpenGL." >&2
  exit 1
fi

if ! pkg-config --exists sdl2 gl; then
  echo "ERROR: SDL2 and OpenGL development packages are required." >&2
  echo "  Install the SDL2 and OpenGL development packages for your Linux distribution." >&2
  exit 1
fi

mkdir -p "$(dirname "$OUTPUT")"
"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror \
  $(pkg-config --cflags sdl2 gl) \
  "${SOURCES[@]}" -o "$OUTPUT" \
  $(pkg-config --libs sdl2 gl) -lm

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror \
  $(pkg-config --cflags sdl2 gl) -I"$ROOT/src/linux" \
  "$ROOT/src/linux/renderer_test.c" "$ROOT/src/linux/renderer.c" "$ROOT/src/linux/native_camera.c" \
  -o "$TEST_OUTPUT" $(pkg-config --libs sdl2 gl) -lm

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  $(pkg-config --cflags sdl2 gl) \
  "$ROOT/src/linux/pcx_test.c" "$ROOT/src/linux/pcx.c" "$ROOT/src/linux/renderer.c" \
  -o "$PCX_TEST_OUTPUT" $(pkg-config --libs sdl2 gl) -lm

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/sool_test.c" "$ROOT/src/linux/sool.c" -o "$SOOL_TEST_OUTPUT"
"$SOOL_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/biz_sound_test.c" "$ROOT/src/linux/biz.c" -o "$BIZ_SOUND_TEST_OUTPUT"
"$BIZ_SOUND_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/audio_mix_test.c" "$ROOT/src/linux/audio_mix.c" -o "$AUDIO_MIX_TEST_OUTPUT"
"$AUDIO_MIX_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/native_camera_test.c" "$ROOT/src/linux/native_camera.c" -o "$NATIVE_CAMERA_TEST_OUTPUT" -lm
"$NATIVE_CAMERA_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/bib_pose_test.c" "$ROOT/src/linux/bib.c" -o "$BIB_POSE_TEST_OUTPUT"
"$BIB_POSE_TEST_OUTPUT"

echo "Built native runtime: $OUTPUT"
echo "Built renderer test: $TEST_OUTPUT"
echo "Built PCX test: $PCX_TEST_OUTPUT"
echo "Built SOOL test: $SOOL_TEST_OUTPUT"
echo "Built BIZ sound test: $BIZ_SOUND_TEST_OUTPUT"
echo "Built audio mixer test: $AUDIO_MIX_TEST_OUTPUT"
echo "Built native camera test: $NATIVE_CAMERA_TEST_OUTPUT"
echo "Built BIB pose test: $BIB_POSE_TEST_OUTPUT"
