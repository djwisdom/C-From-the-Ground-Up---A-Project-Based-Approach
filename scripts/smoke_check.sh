#!/bin/sh

set -eu

CC=${CC:-cc}
CFLAGS=${CFLAGS:--Wall -Wextra -std=c11}

ROOT_DIR=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
BUILD_DIR=$(mktemp -d "${TMPDIR:-/tmp}/cftgu-smoke.XXXXXX")
SOURCE_LIST="$BUILD_DIR/sources.txt"
LESSON31_DIR="$ROOT_DIR/Part 5 - Expert Systems & Application Development/31_make_files_for_multi_file_projects"

cleanup() {
    rm -rf "$BUILD_DIR"
    make -C "$LESSON31_DIR" clean >/dev/null 2>&1 || true
}

trap cleanup EXIT INT TERM HUP

detect_ncurses_flag() {
    cat > "$BUILD_DIR/ncurses_probe.c" <<'EOF'
#include <ncurses.h>

int main(void)
{
    return 0;
}
EOF

    for flag in -lncursesw -lncurses; do
        if "$CC" $CFLAGS "$BUILD_DIR/ncurses_probe.c" -o "$BUILD_DIR/ncurses_probe" "$flag" >/dev/null 2>&1; then
            printf '%s\n' "$flag"
            return 0
        fi
    done

    return 1
}

compile_lesson() {
    lesson_path=$1
    output_path=$2
    extra_flags=

    case "$lesson_path" in
        *30_multithreaded_file_analyzer.c)
            extra_flags="-pthread"
            ;;
        *32_linking_external_libraries.c)
            extra_flags="-lm"
            ;;
        *33_advanced_terminal_ui.c|*35_capstone_awesome_text_adventure.c)
            extra_flags=$NCURSES_FLAG
            ;;
    esac

    printf 'Compiling %s\n' "$lesson_path"
    "$CC" $CFLAGS "$ROOT_DIR/$lesson_path" -o "$output_path" $extra_flags
}

run_analyzer_check() {
    sample_file=$BUILD_DIR/analyzer_sample.txt
    analyzer_bin=$BUILD_DIR/30_multithreaded_file_analyzer

    awk 'BEGIN {
        for (i = 0; i < 40; i++) printf "a";
        printf " ";
        for (i = 0; i < 40; i++) printf "b";
        printf "\n";
    }' > "$sample_file"

    set -- $(wc "$sample_file")
    expected_lines=$1
    expected_words=$2
    expected_chars=$3

    analyzer_output=$("$analyzer_bin" "$sample_file")
    actual_chars=$(printf '%s\n' "$analyzer_output" | awk '/Total Characters:/ { print $3 }')
    actual_words=$(printf '%s\n' "$analyzer_output" | awk '/Total Words:/ { print $3 }')
    actual_lines=$(printf '%s\n' "$analyzer_output" | awk '/Total Lines:/ { print $3 }')

    if [ "$actual_lines" != "$expected_lines" ] || [ "$actual_words" != "$expected_words" ] || [ "$actual_chars" != "$expected_chars" ]; then
        echo "Analyzer verification failed." >&2
        echo "Expected: lines=$expected_lines words=$expected_words chars=$expected_chars" >&2
        echo "Actual:   lines=$actual_lines words=$actual_words chars=$actual_chars" >&2
        exit 1
    fi
}

NCURSES_FLAG=$(detect_ncurses_flag) || {
    echo "Could not find a usable ncurses library (-lncursesw or -lncurses)." >&2
    exit 1
}

(cd "$ROOT_DIR" && find . -type f -name '*.c' | sort > "$SOURCE_LIST")

compiled_count=0

while IFS= read -r lesson_path; do
    case "$lesson_path" in
        ./Part\ 5\ -\ Expert\ Systems\ \&\ Application\ Development/31_make_files_for_multi_file_projects/*)
            continue
            ;;
    esac

    lesson_path=${lesson_path#./}
    lesson_name=$(basename "${lesson_path%.c}")
    compile_lesson "$lesson_path" "$BUILD_DIR/$lesson_name"
    compiled_count=$((compiled_count + 1))
done < "$SOURCE_LIST"

printf 'Building %s\n' "$LESSON31_DIR"
make -C "$LESSON31_DIR" clean >/dev/null
make -C "$LESSON31_DIR" CC="$CC" CFLAGS="$CFLAGS" >/dev/null
test -x "$LESSON31_DIR/31_project_main"
make -C "$LESSON31_DIR" clean >/dev/null

run_analyzer_check

printf 'Smoke check passed. Compiled %d single-file lessons plus lesson 31.\n' "$compiled_count"
