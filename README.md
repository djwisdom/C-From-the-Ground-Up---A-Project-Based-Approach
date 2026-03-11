# C From The Ground Up

`c-from-the-ground-up` is a C learning workbook. Each lesson is a small, readable program with the explanation in the comments, and the repo is meant to stay close to the code that is actually here.

This is not a polished application suite or portfolio showcase. It is a progression of lessons, exercises, and a few larger workbook-style projects.

## Repo Layout

```text
.
├── Part 1 - The Beginner Path_ Core Concepts/
│   ├── 1_hello_world.c
│   ├── 2_variables_and_data_types.c
│   ├── 3_user_input.c
│   ├── 4_basic_operators.c
│   ├── 5_conditional_statements.c
│   ├── 6_loops.c
│   ├── 7_functions.c
│   ├── 8_arrays.c
│   └── 9_strings.c
├── Part 2 - The Intermediate Path_ Deeper into C/
│   ├── 10_pointers.c
│   ├── 11_pointers_and_arrays.c
│   ├── 12_structs.c
│   ├── 13_dynamic_memory_allocation.c
│   ├── 14_file_io.c
│   └── 15_command_line_arguments.c
├── Part 3 - The Advanced Path_ Towards Mastery/
│   ├── 16_simple_calculator.c
│   ├── 17_student_record_system.c
│   ├── 18_function_pointers.c
│   ├── 19_recursion.c
│   ├── 20_linked_lists.c
│   ├── 21_bit_manipulation.c
│   ├── 22_preprocessor_directives.c
│   ├── 23_unions_and_enums.c
│   ├── 24_static_and_extern_variables.c
│   └── 25_simple_text_editor.c
├── Part 4 - The Expert Path_ Systems and Concurrency/
│   ├── 26_simple_socket_client.c
│   ├── 26_simple_socket_server.c
│   ├── 27_build_your_own_grep.c
│   ├── 28_hash_table_implementation.c
│   ├── 29_tiny_shell.c
│   └── 30_multithreaded_file_analyzer.c
├── Part 5 - Expert Systems & Application Development/
│   ├── 31_make_files_for_multi_file_projects/
│   │   ├── Makefile
│   │   ├── helper.c
│   │   ├── helper.h
│   │   └── main.c
│   ├── 32_linking_external_libraries.c
│   ├── 33_advanced_terminal_ui.c
│   ├── 34_parsing_data_files.c
│   └── 35_capstone_awesome_text_adventure.c
├── assets/images/
├── scripts/
│   └── smoke_check.sh
├── .gitignore
├── LICENSE
└── README.md
```

## Quick Start

Most lessons are single-file programs. Pick one `.c` file, compile it, and run it.

```sh
cc -Wall -Wextra -std=c11 \
  "Part 1 - The Beginner Path_ Core Concepts/1_hello_world.c" \
  -o /tmp/1_hello_world

/tmp/1_hello_world
```

Lesson 31 is the exception: it is intentionally split across multiple files and built with its local `Makefile`.

```sh
make -C "Part 5 - Expert Systems & Application Development/31_make_files_for_multi_file_projects"
"Part 5 - Expert Systems & Application Development/31_make_files_for_multi_file_projects/31_project_main"
```

## Build Notes

- Most lessons compile cleanly with `cc -Wall -Wextra -Wpedantic -Wstrict-prototypes -std=c11 lesson.c -o lesson_name`.
- Lessons 26 through 30 use POSIX or Unix-style APIs such as sockets, `fork`, `waitpid`, `unistd.h`, and `pthread`.
- Lesson 30 needs `-pthread`.
- Lesson 32 needs `-lm`.
- Lessons 33 and 35 need `-lncurses` or `-lncursesw`, depending on your system, so they are easiest to run on Unix-like systems or inside WSL on Windows.
- Several lessons expect runtime input or data files. Read the lesson comments before running them.

## Verification

A repo-level smoke check is included:

```sh
sh scripts/smoke_check.sh
```

The smoke check:

- Compiles every lesson into a temporary build directory.
- Builds lesson 31 through its `Makefile`.
- Verifies the socket lesson with a real local client/server exchange.
- Exercises the student record system's invalid-input and save/load paths.
- Confirms TinyShell rejects overlong commands instead of splitting them.
- Verifies the multithreaded file analyzer against `wc` on a boundary-sensitive sample file.
- Runs optional AddressSanitizer/UndefinedBehaviorSanitizer regressions when the compiler supports them.
- Cleans up generated binaries and lesson 31 build products before exiting.

## Capstone Note

Lesson 35 is a single-file `ncurses` exercise that loads a user-supplied map file at runtime. The repo does not present it as a standalone shipped game with bundled assets; it is a workbook capstone that ties together parsing, data structures, and terminal UI work.

## License

This project is licensed under the MIT License. See [LICENSE](/Users/sawyer/github/c-from-the-ground-up/LICENSE).
