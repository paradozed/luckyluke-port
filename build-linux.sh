#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SOURCES=("$ROOT/src/linux/main.c" "$ROOT/src/linux/audio_mix.c" "$ROOT/src/linux/native_camera.c" "$ROOT/src/linux/asset_config.c" "$ROOT/src/linux/menu_art.c" "$ROOT/src/linux/pcx.c" "$ROOT/src/linux/kxp.c" "$ROOT/src/linux/level.c" "$ROOT/src/linux/renderer.c" "$ROOT/src/linux/object.c" "$ROOT/src/linux/gameplay.c" "$ROOT/src/linux/cod.c" "$ROOT/src/linux/bib.c" "$ROOT/src/linux/biz.c" "$ROOT/src/linux/sool.c")
SOURCES+=("$ROOT/src/linux/level_script.c" "$ROOT/src/linux/native_rng.c" "$ROOT/src/linux/native_animation.c" "$ROOT/src/linux/native_audio.c" "$ROOT/src/linux/native_background.c" "$ROOT/src/linux/native_pause.c" "$ROOT/src/linux/native_collision.c")
SOURCES+=("$ROOT/src/linux/native_ballistic.c")
OUTPUT="$ROOT/build/linux/lucky-luke"
TEST_OUTPUT="$ROOT/build/linux/renderer-test"
PCX_TEST_OUTPUT="$ROOT/build/linux/pcx-test"
SOOL_TEST_OUTPUT="$ROOT/build/linux/sool-test"
BIZ_SOUND_TEST_OUTPUT="$ROOT/build/linux/biz-sound-test"
AUDIO_MIX_TEST_OUTPUT="$ROOT/build/linux/audio-mix-test"
NATIVE_AUDIO_TEST_OUTPUT="$ROOT/build/linux/native-audio-test"
NATIVE_CAMERA_TEST_OUTPUT="$ROOT/build/linux/native-camera-test"
NATIVE_BACKGROUND_TEST_OUTPUT="$ROOT/build/linux/native-background-test"
NATIVE_PAUSE_TEST_OUTPUT="$ROOT/build/linux/native-pause-test"
NATIVE_COLLISION_TEST_OUTPUT="$ROOT/build/linux/native-collision-test"
NATIVE_BALLISTIC_TEST_OUTPUT="$ROOT/build/linux/native-ballistic-test"
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
  "$ROOT/src/linux/native_audio_test.c" "$ROOT/src/linux/native_audio.c" \
  "$ROOT/src/linux/audio_mix.c" "$ROOT/src/linux/biz.c" -o "$NATIVE_AUDIO_TEST_OUTPUT"
"$NATIVE_AUDIO_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/native_camera_test.c" "$ROOT/src/linux/native_camera.c" -o "$NATIVE_CAMERA_TEST_OUTPUT" -lm
"$NATIVE_CAMERA_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/native_background_test.c" "$ROOT/src/linux/native_background.c" \
  "$ROOT/src/linux/native_camera.c" "$ROOT/src/linux/bib.c" "$ROOT/src/linux/biz.c" \
  -o "$NATIVE_BACKGROUND_TEST_OUTPUT" -lm
"$NATIVE_BACKGROUND_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/native_pause_test.c" "$ROOT/src/linux/native_pause.c" \
  "$ROOT/src/linux/pcx.c" "$ROOT/src/linux/kxp.c" -o "$NATIVE_PAUSE_TEST_OUTPUT"
"$NATIVE_PAUSE_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/native_collision_test.c" "$ROOT/src/linux/native_collision.c" -o "$NATIVE_COLLISION_TEST_OUTPUT"
"$NATIVE_COLLISION_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/native_ballistic_test.c" "$ROOT/src/linux/native_ballistic.c" -o "$NATIVE_BALLISTIC_TEST_OUTPUT"
"$NATIVE_BALLISTIC_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/bib_pose_test.c" "$ROOT/src/linux/bib.c" \
  "$ROOT/src/linux/native_animation.c" "$ROOT/src/linux/native_camera.c" -o "$BIB_POSE_TEST_OUTPUT" -lm
"$BIB_POSE_TEST_OUTPUT"

echo "Built native runtime: $OUTPUT"
echo "Built renderer test: $TEST_OUTPUT"
echo "Built PCX test: $PCX_TEST_OUTPUT"
echo "Built SOOL test: $SOOL_TEST_OUTPUT"
echo "Built BIZ sound test: $BIZ_SOUND_TEST_OUTPUT"
echo "Built audio mixer test: $AUDIO_MIX_TEST_OUTPUT"
echo "Built native audio test: $NATIVE_AUDIO_TEST_OUTPUT"
echo "Built native camera test: $NATIVE_CAMERA_TEST_OUTPUT"
echo "Built native background test: $NATIVE_BACKGROUND_TEST_OUTPUT"
echo "Built native pause test: $NATIVE_PAUSE_TEST_OUTPUT"
echo "Built native collision test: $NATIVE_COLLISION_TEST_OUTPUT"
echo "Built native ballistic test: $NATIVE_BALLISTIC_TEST_OUTPUT"
echo "Built BIB pose test: $BIB_POSE_TEST_OUTPUT"

"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/abilene_trace.c" "$ROOT/src/linux/level_script.c" \
  "$ROOT/src/linux/sool.c" "$ROOT/src/linux/bib.c" "$ROOT/src/linux/biz.c" "$ROOT/src/linux/native_camera.c" "$ROOT/src/linux/native_rng.c" "$ROOT/src/linux/native_animation.c" \
  "$ROOT/src/linux/native_audio.c" "$ROOT/src/linux/native_background.c" "$ROOT/src/linux/native_pause.c" "$ROOT/src/linux/native_collision.c" "$ROOT/src/linux/native_ballistic.c" \
  "$ROOT/src/linux/pcx.c" "$ROOT/src/linux/kxp.c" "$ROOT/src/linux/audio_mix.c" -o "$ROOT/build/linux/abilene-trace" -lm
echo "Built original-script tracer: $ROOT/build/linux/abilene-trace"
"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -I"$ROOT/src/linux" \
  "$ROOT/src/linux/level_script_test.c" "$ROOT/src/linux/level_script.c" \
  "$ROOT/src/linux/sool.c" "$ROOT/src/linux/bib.c" "$ROOT/src/linux/biz.c" "$ROOT/src/linux/native_camera.c" "$ROOT/src/linux/native_rng.c" "$ROOT/src/linux/native_animation.c" \
  "$ROOT/src/linux/native_audio.c" "$ROOT/src/linux/native_background.c" "$ROOT/src/linux/native_pause.c" "$ROOT/src/linux/native_collision.c" "$ROOT/src/linux/native_ballistic.c" \
  "$ROOT/src/linux/pcx.c" "$ROOT/src/linux/kxp.c" "$ROOT/src/linux/audio_mix.c" -o "$ROOT/build/linux/level-script-test" -lm
"$ROOT/build/linux/level-script-test"
"$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror \
  $(pkg-config --cflags sdl2 gl) -I"$ROOT/src/linux" \
  "$ROOT/src/linux/level_background_test.c" "${SOURCES[@]:1}" \
  -o "$ROOT/build/linux/level-background-test" $(pkg-config --libs sdl2 gl) -lm
echo "Built level background test: $ROOT/build/linux/level-background-test"
