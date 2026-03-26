# C From The Ground Up

A progressive C learning workbook from basics to systems programming.

Each lesson is a small, readable program with the explanation in the comments
and the code inline. The workbook is meant to stay close to the code that is
actually here. This is not a polished application suite or portfolio showcase.
It is a progression of lessons, exercises, and a few larger workbook-style projects.

## How This Book Works

Every chapter follows the same pattern:

1. A prose explanation of the concepts being taught
2. The full, runnable C source file with detailed comments
3. Compile-and-run instructions

The original `.c` files in the repository are the single source of truth. The
comments *are* the lesson content. Read the chapter prose for the overview, then
study the source to see it in action.

## Structure

The book is organized into five progressive parts:

- **Part 1: The Beginner Path** -- Core language fundamentals from Hello World
  through strings
- **Part 2: The Intermediate Path** -- Pointers, structs, dynamic memory, file
  I/O, and command-line arguments
- **Part 3: The Advanced Path** -- Projects and deeper topics including
  function pointers, recursion, linked lists, bit manipulation, and a
  line-based text editor
- **Part 4: The Expert Path** -- Systems programming with sockets, process
  management, hash tables, and multithreading
- **Part 5: Expert Systems** -- Multi-file projects, external libraries,
  terminal UI with ncurses, data parsing, and a capstone text adventure

## Quick Start

Most lessons are single-file programs. Pick one `.c` file, compile it, and run it:

```sh
cc -Wall -Wextra -std=c11 \
  "Part 1 - The Beginner Path_ Core Concepts/1_hello_world.c" \
  -o /tmp/1_hello_world

/tmp/1_hello_world
```

## Build Notes

- Most lessons compile with `cc -Wall -Wextra -std=c11 lesson.c -o lesson_name`.
- Lessons 26 through 30 use POSIX APIs (sockets, `fork`, `waitpid`, `pthread`).
- Lesson 30 needs `-pthread`.
- Lesson 32 needs `-lm`.
- Lessons 33 and 35 need `-lncurses`.

## Verification

A repo-level smoke check is included:

```sh
sh scripts/smoke_check.sh
```

## License

This project is licensed under the MIT License.
