# C From the Ground Up - A Project-Based Approach

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

An open-source curriculum for learning C programming by building a series of increasingly complex projects. This repository is designed to take you from writing `Hello, World!` to building a functional, line-based text editor from scratch.

> Learning to code is like building a house. You don't start with the roof. You start with a solid foundation. This course is designed to be that foundation, laid one brick—one concept, one project—at a time.

---

## ✨ Features

*   🎓 **Step-by-Step Progression**: 25 carefully ordered lessons guide you from core syntax to advanced memory management.
*   ✔️ **Heavily Commented Code**: Every program is meticulously documented to explain not just *what* the code does, but *why* it does it that way.
*   🚀 **Practical, Hands-On Projects**: Apply your knowledge immediately by building real tools like a command-line calculator and a text editor.
*   🧠 **Focus on Fundamentals**: Deep dives into the concepts that make C powerful: pointers, memory allocation, data structures, and file I/O.
*   📖 **Open Source & Community Driven**: Found a bug or have an idea for a better explanation? Contributions are welcome!

---

## 🚀 Getting Started

To get started, you only need a C compiler. The code is written to be compliant with the C11 standard and is tested with GCC.

### Prerequisites

*   A C compiler like [GCC](https://gcc.gnu.org/) or [Clang](https://clang.llvm.org/).
*   A text editor (like VS Code, Sublime Text, Vim, etc.).
*   A command-line terminal.

### How to Use This Repository

1.  **Clone the repository:**
    ```sh
    git clone https://github.com/dunamismax/C-From-the-Ground-Up---A-Project-Based-Approach.git
    cd C-From-the-Ground-Up---A-Project-Based-Approach
    ```

2.  **Navigate to a lesson:** Each program is a self-contained `.c` file.

3.  **Compile and Run:** Use your C compiler to compile the source code. The recommended flags enable extra warnings to help you write better code.

    ```sh
    # General compile command
    gcc -Wall -Wextra -std=c11 -o <output_name> <source_file.c>

    # Example for lesson 1
    gcc -Wall -Wextra -std=c11 -o hello_world 1_hello_world.c
    ```

4.  **Execute the program:**
    ```sh
    # On Linux/macOS
    ./hello_world

    # On Windows
    hello_world.exe
    ```

---

## 📚 The Curriculum

The course is divided into three distinct paths, taking you from core concepts to mastery.

### Part 1: The Beginner Path - Core Concepts

| File                                 | Key Concepts                                            | Description                                                                 |
| ------------------------------------ | ------------------------------------------------------- | --------------------------------------------------------------------------- |
| `1_hello_world.c`                    | `main()`, `<stdio.h>`, `printf()`                       | The essential first step: compiling and running a basic program.            |
| `2_variables_and_data_types.c`       | `int`, `double`, `char`, format specifiers              | Learn to store and display information.                                     |
| `3_user_input.c`                     | `scanf()`, `&` (address-of operator)                    | Make your programs interactive by reading user input.                       |
| `4_basic_operators.c`                | `+`, `/`, `%`, `==`, `&&`, `||`                         | Perform calculations and make logical comparisons.                          |
| `5_conditional_statements.c`         | `if`, `else if`, `else`                                 | Give your program a brain by letting it make decisions.                     |
| `6_loops.c`                          | `for`, `while`, `do-while`                              | Teach your program to perform repetitive tasks efficiently.                 |
| `7_functions.c`                      | Prototypes, definitions, calls, return values           | Organize code into clean, reusable, and modular blocks.                     |
| `8_arrays.c`                         | Declaration, initialization, iteration                  | Manage collections of same-typed data.                                      |
| `9_strings.c`                        | `char[]`, `\0` (null terminator), `<string.h>`          | Master text manipulation, a fundamental programming skill.                  |

### Part 2: The Intermediate Path - Deeper into C

| File                           | Key Concepts                                      | Description                                                                      |
| ------------------------------ | ------------------------------------------------- | -------------------------------------------------------------------------------- |
| `10_pointers.c`                | `&`, `*` (dereference), `NULL`                      | Unlock C's most famous and powerful feature: direct memory manipulation.         |
| `11_pointers_and_arrays.c`     | Pointer arithmetic, array-pointer equivalence     | Explore the deep, fundamental relationship between pointers and arrays.          |
| `12_structs.c`                 | `struct`, member access (`.`, `->`)                 | Create your own custom data types to model real-world objects.                   |
| `13_dynamic_memory_allocation.c` | `malloc()`, `free()`, the heap, memory leaks      | Gain full control over your program's memory at runtime.                         |
| `14_file_io.c`                 | `FILE*`, `fopen()`, `fclose()`, `fprintf()`         | Persist data by reading from and writing to files.                               |
| `15_command_line_arguments.c`  | `argc`, `argv`                                    | Make flexible tools that accept input directly from the command line.            |

### Part 3: The Advanced Path - Towards Mastery

| File                                 | Key Concepts                                                | Description                                                                             |
| ------------------------------------ | ----------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| `16_simple_calculator.c`             | **Project:** Combining `argv` and logic                     | Build your first complete, useful tool from the skills you've learned.                  |
| `17_student_record_system.c`         | **Project:** Structs, arrays, and file I/O                    | Create a menu-driven database application to manage a list of student records.          |
| `18_function_pointers.c`             | Callbacks, dispatch tables                                  | Learn to treat functions like data for highly flexible and dynamic code.                |
| `19_recursion.c`                     | Base cases, recursive steps                                 | Explore an elegant alternative to loops for solving complex problems.                   |
| `20_linked_lists.c`                  | `struct Node`, `head`/`tail`, traversal, `**` (double pointers) | Build a fundamental dynamic data structure from scratch.                                |
| `21_bit_manipulation.c`              | `&`, `|`, `^`, `~`, `<<`, `>>`                              | Go low-level by operating on the individual bits of data.                               |
| `22_preprocessor_directives.c`       | `#define`, `#include "..."`, `#ifdef`, include guards       | Understand what happens before compilation and how to manage multi-file projects.       |
| `23_unions_and_enums.c`              | `union`, `enum`, tagged unions                              | Learn specialized types for efficient memory use and creating readable constants.       |
| `24_static_and_extern_variables.c`   | `static`, `extern`, scope, linkage                          | Master variable lifetime and visibility across a multi-file project.                  |
| `25_simple_text_editor.c`            | **Final Capstone Project**                                  | Build a complete, line-based text editor using a doubly-linked list. A true test of your C skills. |

---

## 🏆 Capstone Project: Simple Text Editor

The final project (`25_simple_text_editor.c`) is a culmination of everything learned in this course. It's a fully functional, line-based text editor that can:
*   Append, insert, and delete lines of text.
*   Use a doubly-linked list to store the document in memory.
*   Load a document from a file when it starts.
*   Save the current text buffer back to the file.

![GIF of the text editor in action](https://i.imgur.com/example.gif)  <!-- Placeholder: Replace with an actual GIF of your editor! -->

**To run the editor:**
```sh
# Compile it
gcc -Wall -Wextra -std=c11 -o editor 25_simple_text_editor.c

# Run it on a new or existing file
./editor my_document.txt
content_copy
download
Use code with caution.
Markdown
🤝 Contributing
Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

Reporting Bugs: If you find a bug in the code or a typo in the comments, please open an issue.
Suggesting Enhancements: Have an idea for a new lesson or a better way to explain a concept? Feel free to open an issue to discuss it.
Pull Requests: If you want to contribute directly, please fork the repo and create a pull request.
📜 License
This project is licensed under the MIT License. See the LICENSE file for more details.
