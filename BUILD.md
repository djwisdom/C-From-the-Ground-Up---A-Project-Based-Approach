# BUILD

Build plan and tech stack alignment tracker for `c-from-the-ground-up`.

---

## Phase 1: Beginner Path -- Core Concepts

- [x] 1_hello_world.c
- [x] 2_variables_and_data_types.c
- [x] 3_user_input.c
- [x] 4_basic_operators.c
- [x] 5_conditional_statements.c
- [x] 6_loops.c
- [x] 7_functions.c
- [x] 8_arrays.c
- [x] 9_strings.c

---

## Phase 2: Intermediate Path -- Deeper into C

- [x] 10_pointers.c
- [x] 11_pointers_and_arrays.c
- [x] 12_structs.c
- [x] 13_dynamic_memory_allocation.c
- [x] 14_file_io.c
- [x] 15_command_line_arguments.c

---

## Phase 3: Advanced Path -- Towards Mastery

- [x] 16_simple_calculator.c
- [x] 17_student_record_system.c
- [x] 18_function_pointers.c
- [x] 19_recursion.c
- [x] 20_linked_lists.c
- [x] 21_bit_manipulation.c
- [x] 22_preprocessor_directives.c
- [x] 23_unions_and_enums.c
- [x] 24_static_and_extern_variables.c
- [x] 25_simple_text_editor.c

---

## Phase 4: Expert Path -- Systems and Concurrency

- [x] 26_simple_socket_server.c and 26_simple_socket_client.c
- [x] 27_build_your_own_grep.c
- [x] 28_hash_table_implementation.c
- [x] 29_tiny_shell.c
- [x] 30_multithreaded_file_analyzer.c

---

## Phase 5: Expert Systems and Application Development

- [x] 31_make_files_for_multi_file_projects (Makefile + helper.c + helper.h + main.c)
- [x] 32_linking_external_libraries.c
- [x] 33_advanced_terminal_ui.c
- [x] 34_parsing_data_files.c
- [x] 35_capstone_awesome_text_adventure.c

---

## Phase 6: Tech Stack Alignment

Gaps identified against the C tech stack reference. Each item below is a concrete
change or addition needed to bring this workbook into alignment with the documented
defaults for compiler configuration, build tooling, static analysis, sanitizers,
Valgrind, a formal test harness, libsodium crypto, deeper POSIX networking, and
fuzzing.

### Compiler and flags

- [ ] Migrate the smoke_check.sh CFLAGS default from `-std=c11` to `-std=c23` (keep a
      `-std=c17` fallback note for compilers that do not yet ship full C23 support)
- [ ] Add `-Wconversion`, `-Wshadow`, and `-Wmissing-prototypes` to the CFLAGS baseline
      and fix any new warnings that surface across the existing lessons
- [ ] Add a secondary GCC compile pass to smoke_check.sh as a portability cross-check
      (the tech stack requires both Clang and GCC to pass in CI)
- [ ] Verify all 35 lessons compile cleanly under both Clang and GCC with the updated
      flag set

### Build system

- [ ] Add a `CMakeLists.txt` at the repo root that builds all single-file lessons as
      individually named targets using `add_executable`
- [ ] Wire CMake to Ninja as the default generator and document the invocation in
      README.md Build Notes (`cmake -G Ninja -B build && ninja -C build`)
- [ ] Register all lesson binaries with CTest using `add_test` so `ctest` can serve
      as the primary test runner
- [ ] Add a `clang-format` config (`.clang-format`) at the repo root based on a clean
      baseline (e.g., LLVM or Google style, with any project-specific overrides noted)
- [ ] Verify all existing lesson files format cleanly under `clang-format --dry-run`

### Static analysis

- [ ] Add a `.clang-tidy` config at the repo root with a sensible starting rule set
      (cert-*, bugprone-*, clang-analyzer-*, modernize-* restricted to C23 idioms)
- [ ] Run `clang-tidy` against the full source tree and fix or suppress findings with
      explanatory `// NOLINT` comments where suppression is warranted
- [ ] Document how to run `scan-build` on the full source tree in README.md
- [ ] Document how to run GCC `-fanalyzer` on the source tree in README.md
- [ ] Add a `.clangd` config at the repo root (or generate `compile_commands.json`
      via `cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON`) so clangd LSP works out of the box

### Sanitizers (systematic)

- [ ] Promote sanitizer coverage from optional to required: make the ASan/UBSan
      regression block in smoke_check.sh fail the check rather than printing a skip
      message when the compiler supports sanitizers
- [ ] Add a dedicated `asan_ubsan_check.sh` script (or CMake/CTest variant) that
      compiles every lesson under `-fsanitize=address,undefined` and runs each binary
      through its expected input path
- [ ] Add a `tsan_check.sh` script that compiles and runs lesson 30
      (30_multithreaded_file_analyzer.c) under `-fsanitize=thread` to catch data races

### Valgrind

- [ ] Add a `valgrind_check.sh` script that runs `valgrind --leak-check=full
      --error-exitcode=1` over the heap-intensive lessons: 13, 17, 20, 28, and 35
- [ ] Confirm lesson 13 (dynamic memory allocation) passes Valgrind memcheck with zero
      errors and zero leaks
- [ ] Confirm lesson 20 (linked lists) passes Valgrind memcheck with zero errors and
      zero leaks
- [ ] Confirm lesson 28 (hash table) passes Valgrind memcheck with zero errors and zero
      leaks
- [ ] Confirm lesson 17 (student record system) passes Valgrind memcheck under its
      full save/load path

### Formal test harness

- [ ] Create a `tests/` directory with plain C test executables (no external framework,
      just `assert` or manual exit-code checks) for the core data structure lessons
- [ ] Add `tests/test_linked_list.c` covering insert, delete, search, and free for
      the lesson 20 list implementation
- [ ] Add `tests/test_hash_table.c` covering insert, lookup, collision handling, and
      cleanup for the lesson 28 table implementation
- [ ] Register the test executables with CTest and document the `ctest -V` invocation

### libsodium crypto exercises

- [ ] Add lesson 36: symmetric encryption and decryption using
      `crypto_secretbox_easy` / `crypto_secretbox_open_easy` with a randomly generated
      key and nonce; include `sodium_memzero` to wipe key material after use
- [ ] Add lesson 37: password hashing and key derivation using `crypto_pwhash`
      (Argon2id) with a stored salt, demonstrating a safe credential storage pattern
- [ ] Add lesson 38: authenticated public-key message exchange using `crypto_box_easy`
      between a simulated sender and receiver, with explicit key and message wiping
- [ ] Update README.md Build Notes with the libsodium dependency and its `pkg-config`
      usage (`pkg-config --cflags --libs libsodium`)

### POSIX networking (deeper coverage)

- [ ] Add lesson 39: a concurrent TCP echo server that uses `select()` or `poll()` to
      multiplex multiple client connections without spawning threads; demonstrate
      clean fd lifecycle management
- [ ] Add lesson 40: a Unix domain socket example showing local IPC between a server
      and client process using `AF_UNIX` / `SOCK_STREAM`; demonstrate abstract and
      path-based socket names
- [ ] Update README.md Build Notes with the headers and link flags for lessons 39-40
      (`sys/socket.h`, `sys/select.h`, `sys/un.h`)

### Fuzzing

- [ ] Create a `fuzz/` directory with a libFuzzer target for the data file parser used
      in lesson 34 (`fuzz/fuzz_data_parser.c`); build with
      `-fsanitize=fuzzer,address`
- [ ] Add a libFuzzer target for the map file parser in the text adventure capstone
      (lesson 35) (`fuzz/fuzz_map_parser.c`)
- [ ] Add a `fuzz/corpus/` subdirectory with a small seed corpus for each target
- [ ] Document the fuzz build and run workflow in README.md, including minimum run
      time and crash reproduction steps (`-runs=10000` for CI, reproduce with the
      crashing input artifact)

### Cross-compilation note

- [ ] Add a documented example of cross-compiling lesson 1 via `zig cc` to a different
      target triple (e.g., `x86_64-linux-musl`) to validate the cross-build path
      described in the tech stack
