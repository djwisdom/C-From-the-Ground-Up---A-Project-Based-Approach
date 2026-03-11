#!/bin/sh

set -eu

CC=${CC:-cc}
CFLAGS=${CFLAGS:--Wall -Wextra -Wpedantic -Wstrict-prototypes -Werror -std=c11}

ROOT_DIR=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
BUILD_DIR=$(mktemp -d "${TMPDIR:-/tmp}/cftgu-smoke.XXXXXX")
SOURCE_LIST="$BUILD_DIR/sources.txt"
LESSON31_DIR="$ROOT_DIR/Part 5 - Expert Systems & Application Development/31_make_files_for_multi_file_projects"
SOCKET_SERVER_PID=

cleanup() {
    if [ -n "${SOCKET_SERVER_PID}" ]; then
        kill "$SOCKET_SERVER_PID" >/dev/null 2>&1 || true
        wait "$SOCKET_SERVER_PID" >/dev/null 2>&1 || true
    fi
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

detect_sanitizer_flags() {
    cat > "$BUILD_DIR/sanitizer_probe.c" <<'EOF'
int main(void)
{
    return 0;
}
EOF

    if "$CC" $CFLAGS "$BUILD_DIR/sanitizer_probe.c" -o "$BUILD_DIR/sanitizer_probe" -fsanitize=address,undefined >/dev/null 2>&1; then
        printf '%s\n' "-fsanitize=address,undefined"
        return 0
    fi

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

fail_with_output() {
    message=$1
    output=$2

    echo "$message" >&2
    printf '%s\n' "$output" >&2
    exit 1
}

expect_contains() {
    output=$1
    expected=$2
    message=$3

    case "$output" in
        *"$expected"*)
            ;;
        *)
            fail_with_output "$message" "$output"
            ;;
    esac
}

expect_not_contains() {
    output=$1
    unexpected=$2
    message=$3

    case "$output" in
        *"$unexpected"*)
            fail_with_output "$message" "$output"
            ;;
    esac
}

run_analyzer_check() {
    sample_file=$BUILD_DIR/analyzer_sample.txt
    analyzer_bin=$BUILD_DIR/30_multithreaded_file_analyzer
    empty_file=$BUILD_DIR/analyzer_empty.txt

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

    : > "$empty_file"
    empty_output=$("$analyzer_bin" "$empty_file")
    expect_contains "$empty_output" "File is empty. Nothing to analyze." "Analyzer did not report empty-file handling."
    expect_contains "$empty_output" "Total Characters: 0" "Analyzer empty-file character count is incorrect."
    expect_contains "$empty_output" "Total Words:      0" "Analyzer empty-file word count is incorrect."
    expect_contains "$empty_output" "Total Lines:      0" "Analyzer empty-file line count is incorrect."
}

run_socket_check() {
    server_bin=$BUILD_DIR/26_simple_socket_server
    client_bin=$BUILD_DIR/26_simple_socket_client
    server_log=$BUILD_DIR/socket_server.log

    for attempt in 1 2 3 4 5; do
        port=$((35000 + ($$ + attempt) % 20000))
        : > "$server_log"
        "$server_bin" "$port" > "$server_log" 2>&1 &
        SOCKET_SERVER_PID=$!

        for _ in 1 2 3 4 5 6 7 8 9 10; do
            if ! kill -0 "$SOCKET_SERVER_PID" >/dev/null 2>&1; then
                break
            fi

            sleep 0.2
        done

        if kill -0 "$SOCKET_SERVER_PID" >/dev/null 2>&1; then
            client_output=$("$client_bin" 127.0.0.1 "$port" "Smoke test message" 2>&1)
            wait "$SOCKET_SERVER_PID"
            SOCKET_SERVER_PID=

            expect_contains "$client_output" "Server reply: Message received. Thank you!" "Socket client/server exchange did not complete successfully."
            expect_contains "$(cat "$server_log")" "Connection accepted from" "Socket server did not accept the smoke-test client."
            return 0
        fi

        wait "$SOCKET_SERVER_PID" >/dev/null 2>&1 || true
        SOCKET_SERVER_PID=
    done

    fail_with_output "Socket server/client regression test could not start successfully." "$(cat "$server_log")"
}

run_student_record_checks() {
    student_bin=$BUILD_DIR/17_student_record_system
    invalid_dir=$BUILD_DIR/student_invalid
    comma_dir=$BUILD_DIR/student_comma
    save_dir=$BUILD_DIR/student_save

    mkdir -p "$invalid_dir" "$comma_dir" "$save_dir"

    invalid_output=$(cd "$invalid_dir" && printf '1\nabc\n2\n4\n' | "$student_bin")
    expect_contains "$invalid_output" "Invalid student ID. Record was not added." "Student system accepted a non-numeric ID."
    expect_contains "$invalid_output" "No records to display." "Student system added a record after invalid numeric input."

    comma_output=$(cd "$comma_dir" && printf '1\n42\nDoe, Jane\n4\n' | "$student_bin")
    expect_contains "$comma_output" "Names cannot contain commas" "Student system did not protect the on-disk format from comma-containing names."

    save_output=$(cd "$save_dir" && printf '1\n42\nJane Doe\n3.50\n3\n4\n' | "$student_bin")
    expect_contains "$save_output" "Student added successfully." "Student system failed to add a valid record."
    expect_contains "$save_output" "Successfully saved 1 record(s) to students.db." "Student system failed to save the valid record."

    load_output=$(cd "$save_dir" && printf '2\n4\n' | "$student_bin")
    expect_contains "$load_output" "Successfully loaded 1 record(s) from students.db." "Student system failed to reload a saved record."
    expect_contains "$load_output" "Jane Doe" "Student system did not print the reloaded student name."
    expect_contains "$load_output" "3.50" "Student system did not print the reloaded GPA."
}

run_tiny_shell_check() {
    shell_bin=$BUILD_DIR/29_tiny_shell

    shell_output=$(awk 'BEGIN {
        printf "echo ";
        for (i = 0; i < 120; i++) printf "a";
        printf "\nexit\n";
    }' | "$shell_bin" 2>&1)

    expect_contains "$shell_output" "Command too long. Maximum length is 78 characters." "TinyShell did not reject an overlong command line."
    expect_not_contains "$shell_output" "execvp failed" "TinyShell split an overlong command into a second command."
}

run_sanitizer_regressions() {
    if [ -z "${SANITIZER_FLAGS:-}" ]; then
        printf 'Skipping sanitizer regressions (compiler does not support -fsanitize=address,undefined).\n'
        return 0
    fi

    analyzer_san_bin=$BUILD_DIR/30_multithreaded_file_analyzer_san
    empty_file=$BUILD_DIR/analyzer_empty_san.txt
    capstone_harness=$BUILD_DIR/capstone_parse_harness.c
    capstone_harness_bin=$BUILD_DIR/capstone_parse_harness

    "$CC" $CFLAGS "$ROOT_DIR/Part 4 - The Expert Path_ Systems and Concurrency/30_multithreaded_file_analyzer.c" \
        -o "$analyzer_san_bin" -pthread $SANITIZER_FLAGS
    : > "$empty_file"
    ASAN_OPTIONS=detect_leaks=0 UBSAN_OPTIONS=halt_on_error=1 "$analyzer_san_bin" "$empty_file" >/dev/null 2>&1

    cat > "$capstone_harness" <<EOF
#include <stdlib.h>
#include <string.h>

#define main capstone_lesson_main
#include "$ROOT_DIR/Part 5 - Expert Systems & Application Development/35_capstone_awesome_text_adventure.c"
#undef main

int main(void)
{
    GameState game;
    char room_line[700];
    char link_line[64];
    int i;

    memset(&game, 0, sizeof(game));

    memcpy(room_line, "room 0 \\"", 8);
    for (i = 0; i < 600; i++)
    {
        room_line[8 + i] = 'A';
    }
    room_line[608] = '"';
    room_line[609] = '\0';

    if (parse_room(room_line, &game) != 0)
    {
        return 1;
    }

    game.all_rooms[0] = calloc(1, sizeof(Room));
    game.all_rooms[1] = calloc(1, sizeof(Room));
    if (!game.all_rooms[0] || !game.all_rooms[1])
    {
        free(game.all_rooms[0]);
        free(game.all_rooms[1]);
        return 1;
    }

    game.all_rooms[0]->id = 0;
    game.all_rooms[1]->id = 1;
    game.num_rooms = 2;

    strcpy(link_line, "link 0 abcdefghijk 1");
    if (parse_link(link_line, &game) != 0)
    {
        free(game.all_rooms[0]);
        free(game.all_rooms[1]);
        return 1;
    }

    free(game.all_rooms[0]);
    free(game.all_rooms[1]);
    return 0;
}
EOF

    "$CC" $CFLAGS "$capstone_harness" -o "$capstone_harness_bin" "$NCURSES_FLAG" $SANITIZER_FLAGS
    ASAN_OPTIONS=detect_leaks=0 UBSAN_OPTIONS=halt_on_error=1 "$capstone_harness_bin" >/dev/null 2>&1
}

NCURSES_FLAG=$(detect_ncurses_flag) || {
    echo "Could not find a usable ncurses library (-lncursesw or -lncurses)." >&2
    exit 1
}
SANITIZER_FLAGS=$(detect_sanitizer_flags || true)

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
run_socket_check
run_student_record_checks
run_tiny_shell_check
run_sanitizer_regressions

printf 'Smoke check passed. Compiled %d single-file lessons plus lesson 31.\n' "$compiled_count"
