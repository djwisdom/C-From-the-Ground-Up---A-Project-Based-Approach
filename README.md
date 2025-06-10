# C From the Ground Up - A Project-Based Journey

[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![Stars](https://img.shields.io/github/stars/dunamismax/C-From-the-Ground-Up---A-Project-Based-Approach?style=social)](https://github.com/dunamismax/C-From-the-Ground-Up---A-Project-Based-Approach/stargazers)

Your ultimate journey to mastering the C programming language, designed for everyone from absolute beginners to experienced developers looking to deepen their systems knowledge. This open-source curriculum guides you from `printf("Hello, World!");` to building a multithreaded application, one practical project at a time.

> Learning to code is like building a house. You don't start with the roof. You start with a solid foundation. This course is designed to be that foundation, laid one brick—one concept, one project—at a time.

---

## ✨ Why C From the Ground Up?

This isn't just another collection of code snippets. It's a structured learning path designed for deep understanding.

*   🧠 **Learn the 'Why', Not Just the 'What'**: Every line of code in every project is meticulously commented to explain the underlying concepts, design decisions, and best practices.
*   🚀 **Zero to Hero Progression**: 30 carefully ordered lessons guide you from core syntax and memory fundamentals all the way to advanced topics like network programming, process management, and concurrency.
*   🛠️ **Build a Portfolio of Real-World Tools**: You won't just learn concepts; you'll apply them immediately by building practical tools like a command-line `grep`, a shell, a hash table, and a text editor.
*   💪 **Master the Hard Parts**: We embrace C's most powerful (and feared) features. You will gain true confidence with pointers, dynamic memory, low-level bit manipulation, and multithreading.
*   🌍 **Open Source & Community Driven**: This curriculum is for the community, by the community. Contributions, suggestions, and corrections are always welcome.

---

## 🚀 Getting Started

All you need to begin your journey is a C compiler and a passion to learn. The code is written to be C11 compliant and is tested with GCC.

### Prerequisites

*   A C compiler like [GCC](https://gcc.gnu.org/) (recommended) or [Clang](https://clang.llvm.org/).
*   A text editor (like VS Code, Sublime Text, Vim, etc.).
*   A command-line terminal.

### How to Use This Repository

1.  **Clone the repository:**
    ```sh
    git clone https://github.com/dunamismax/C-From-the-Ground-Up---A-Project-Based-Approach.git
    cd C-From-the-Ground-Up---A-Project-Based-Approach
    ```

2.  **Start with Lesson 1:** Each program is a self-contained `.c` file. Open `1_hello_world.c` and read the comments to understand the goal.

3.  **Compile and Run:** Use your C compiler to create an executable. We recommend these flags to catch potential errors and enforce modern standards.
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
5.  **Proceed to the next lesson!**

---

## 📚 The Journey

The curriculum is divided into four distinct paths, each building on the last to take you from core concepts to C mastery.

### Part 1: The Beginner Path - Core Concepts

| File | Key Concepts | Description |
| :--- | :--- | :--- |
| `1_hello_world.c` | `main()`, `<stdio.h>`, `printf()` | The essential first step: compiling and running a basic program. |
| `2_variables_and_data_types.c` | `int`, `double`, `char`, format specifiers | Learn to store, manage, and display information. |
| `3_user_input.c` | `scanf()`, `&` (address-of operator) | Make your programs interactive by reading user input from the keyboard. |
| `4_basic_operators.c` | `+`, `/`, `%`, `==`, `&&`, `||` | Perform calculations and make logical comparisons. |
| `5_conditional_statements.c` | `if`, `else if`, `else` | Give your program a brain by letting it make decisions and follow logic. |
| `6_loops.c` | `for`, `while`, `do-while` | Teach your program to perform repetitive tasks efficiently. |
| `7_functions.c` | Prototypes, definitions, calls, return values | Organize code into clean, reusable, and modular blocks—a core concept. |
| `8_arrays.c` | Declaration, initialization, iteration | Manage collections of data of the same type. |
| `9_strings.c` | `char[]`, `\0` (null terminator), `<string.h>` | Master text manipulation, a fundamental programming skill. |

### Part 2: The Intermediate Path - Deeper into C

| File | Key Concepts | Description |
| :--- | :--- | :--- |
| `10_pointers.c` | `&`, `*` (dereference), `NULL` | Unlock C's most famous and powerful feature: direct memory manipulation. |
| `11_pointers_and_arrays.c` | Pointer arithmetic, array-pointer equivalence | Explore the deep, fundamental relationship between pointers and arrays. |
| `12_structs.c` | `struct`, member access (`.`, `->`) | Create your own custom, complex data types to model real-world objects. |
| `13_dynamic_memory_allocation.c`| `malloc()`, `free()`, the heap, memory leaks | Gain full control over your program's memory at runtime—a crucial C skill. |
| `14_file_io.c` | `FILE*`, `fopen()`, `fclose()`, `fprintf()` | Persist data beyond program execution by reading from and writing to files. |
| `15_command_line_arguments.c` | `argc`, `argv` | Make flexible tools that accept input directly from the command line. |

### Part 3: The Advanced Path - Towards Mastery

| File | Key Concepts | Description |
| :--- | :--- | :--- |
| `16_simple_calculator.c` | **Project:** Combining `argv` and logic | Build your first complete, useful tool from the skills you've learned. |
| `17_student_record_system.c` | **Project:** Structs, arrays, and file I/O | Create a menu-driven database application to manage a list of student records. |
| `18_function_pointers.c` | Callbacks, dispatch tables | Learn to treat functions like data for highly flexible and dynamic code. |
| `19_recursion.c` | Base cases, recursive steps | Explore an elegant, powerful alternative to loops for solving complex problems. |
| `20_linked_lists.c` | `struct Node`, `head`/`tail`, traversal | Build one of the most fundamental dynamic data structures from scratch. |
| `21_bit_manipulation.c` | `&`, `|`, `^`, `~`, `<<`, `>>` | Go low-level by directly manipulating the individual bits of data. |
| `22_preprocessor_directives.c` | `#define`, `#include "..."`, `#ifdef` | Understand the C preprocessor and how to manage large, multi-file projects. |
| `23_unions_and_enums.c` | `union`, `enum`, tagged unions | Learn specialized types for efficient memory use and creating readable constants. |
| `24_static_and_extern_variables.c`| `static`, `extern`, scope, linkage | Master variable lifetime and visibility across an entire project. |
| `25_simple_text_editor.c` | **Project:** Doubly-linked list, `FILE` I/O | **Capstone:** Build a complete text editor. A true test of your C skills. |

### Part 4: The Expert Path - Systems & Concurrency

This is where theory ends and systems mastery begins. These projects challenge you to integrate everything you've learned to build programs that interact with the network, the operating system, and multiple CPU cores.

| File | Key Concepts | Description |
| :--- | :--- | :--- |
| `26_simple_socket_client_server.c`| Sockets (`socket`, `bind`, `listen`, `accept`, `connect`) | **Your Gateway to the Internet:** Build a client-server chat application. |
| `27_build_your_own_grep.c` | Advanced File I/O, `strstr`, CLI tools | **Build a Famous CLI Tool:** Create your own version of the `grep` utility. |
| `28_hash_table_implementation.c`| Hashing, collision resolution (chaining) | **The Engine of Modern Languages:** Implement a hash table from scratch. |
| `29_tiny_shell.c` | Process management (`fork`, `execvp`, `waitpid`) | **Build Your Own `bash`:** Create a working shell to execute other programs. |
| `30_multithreaded_file_analyzer.c`| `pthreads`, concurrency, mutexes, race conditions | **Harness Multi-Core Power:** Use threads to analyze a large file in parallel. |

---

## ⭐ Show Your Support

If you find this curriculum helpful on your journey to mastering C, please **give it a star!** It helps the project be seen by more people and encourages further development.

## 🤝 Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

*   **Reporting Bugs**: Find a bug in the code or a typo in the comments? Please [open an issue](https://github.com/dunamismax/C-From-the-Ground-Up---A-Project-Based-Approach/issues).
*   **Suggesting Enhancements**: Have an idea for a new lesson or a better way to explain a concept? Feel free to open an issue to discuss it.
*   **Pull Requests**: If you want to contribute directly, please fork the repo and create a pull request. (See `CONTRIBUTING.md` for more details).

## 📜 License

This project is licensed under the MIT License. See the `LICENSE` file for more details.