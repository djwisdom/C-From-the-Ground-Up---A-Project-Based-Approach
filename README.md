# C From The Ground Up

<p align="left">
  <b>A complete, open-source curriculum that teaches you C by building a portfolio of real-world tools and applications from scratch.</b>
</p>
<p align="left">
  This course uses a unique, hands-on teaching method: <b>the lesson is in the code</b>. You'll learn every concept from structured comments inside a single, runnable C file for each topic.
</p>
<p align="center">
  <a href="https://en.wikipedia.org/wiki/C11_(C_standard_revision)"><img src="https://img.shields.io/badge/Language-C11-blue.svg" alt="C11"></a>
  <a href="https://www.gnu.org/software/make/"><img src="https://img.shields.io/badge/Build-Make-green.svg" alt="Make"></a>
  <a href="https://en.wikipedia.org/wiki/Ncurses"><img src="https://img.shields.io/badge/UI-ncurses-9cf" alt="ncurses"></a>
  <a href="https://github.com/dunamismax/C-From-The-Ground-Up-A-Project-Based-Approach/blob/main/LICENSE"><img src="https://img.shields.io/badge/License-MIT-yellow.svg" alt="License: MIT"></a>
  <a href="https://github.com/dunamismax/C-From-The-Ground-Up-A-Project-Based-Approach/pulls"><img src="https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square" alt="PRs Welcome"></a>
  <a href="https://github.com/dunamismax/C-From-The-Ground-Up-A-Project-Based-Approach/stargazers"><img src="https://img.shields.io/github/stars/dunamismax/C-From-The-Ground-Up-A-Project-Based-Approach?style=social" alt="GitHub Stars"></a>
</p>

---

Welcome to the ultimate approach for learning the C programming language! This is not just a tutorial; it's a complete, foundational computer science education designed to build deep, practical knowledge. We start with the absolute basics—assuming you've never written a line of code—and end with a portfolio of impressive systems projects, including a multithreaded application and an advanced text-based RPG.

> Learning C is learning the fundamentals of how computers truly work. This course is your foundation, laid one brick—one concept, one project—at a time. Mastering C will make you a fundamentally better developer, no matter what language you use in the future.

## ✨ Why This Approach?

*   📖 **Learn Directly In The Code**: Forget switching between theory and practice. Every lesson is taught directly within the comments of a single, runnable C file. The code *is* the textbook.
*   👨‍💻 **True Beginners Welcome**: This course has zero prerequisites. We'll guide you through installing a compiler and writing `printf("Hello, World!");` before we even think about pointers.
*   🚀 **From Console to Systems Mastery**: The curriculum is carefully designed to build your skills layer by layer. You'll master C fundamentals, build a portfolio of classic command-line tools, and finally develop complex, multi-file applications.
*   🛠️ **Build an Impressive Portfolio**: The entire course is oriented around practical projects. Every concept, from `malloc` to `pthreads`, is a building block for tools like your own `grep`, a tiny shell, and a final text adventure game.
*   💪 **Master the Hard Parts**: We embrace C's most powerful (and feared) features. You will gain true confidence with pointers, dynamic memory allocation, low-level bit manipulation, process management, and multithreading.
*   🌍 **Open Source & Community Driven**: This curriculum is for the community. Contributions, suggestions, bug fixes, and project ideas are highly encouraged!

---

## 💻 Tech Stack & Prerequisites

You don't need any programming knowledge to start, but you will need to install a few standard development tools.

*   A C Compiler like **GCC** (recommended) or **Clang**.
*   **Make** for automating the build process in later projects.
*   **Git** for cloning the repository.
*   An IDE or Text Editor (Visual Studio Code, CLion, Vim, or Sublime Text are great choices).

---

## 🚀 How to Use This Course

Each lesson folder contains one or more source files. For most of the course, a single `.c` file is both the complete, runnable program and the full lesson text.

1.  **Read the Lesson:** Navigate to a lesson folder (e.g., `Part1_Core_Concepts/01_HelloWorld/`) and open the `1_hello_world.c` file. Read the comments from top to bottom to understand the concepts.

2.  **Compile and Run the Code:** To see the lesson's concepts in action, you'll need to compile and run the program.

    First, clone the repository (you only need to do this once):
    ```sh
    git clone https://github.com/dunamismax/C-From-The-Ground-Up-A-Project-Based-Approach.git
    cd C-From-The-Ground-Up-A-Project-Based-Approach
    ```

    Then, for each lesson, navigate to its folder and use the C compiler. We highly recommend using these flags to catch common errors.
    ```sh
    # Example for the first lesson
    cd Part1_Core_Concepts/01_HelloWorld

    # Compile the code using GCC
    # Note: the output file (-o) matches the source file name
    gcc -Wall -Wextra -std=c11 -o 1_hello_world 1_hello_world.c

    # Run the compiled program
    # On Linux/macOS
    ./1_hello_world

    # On Windows
    1_hello_world.exe
    ```
    *Note: Later projects will use `Make`. In those cases, you will simply run the `make` command in the lesson directory.*

---

## 📚 The Curriculum

The curriculum is divided into five parts, taking you from a blank text file to a C master capable of building complex systems applications.

<details>
<summary><strong>Part 1: The Beginner Path - Core Concepts</strong></summary>
<br>
<i>(Focus: Core language syntax and logic, taught entirely within single-file console applications.)</i>

| Lesson                               | Key Concepts                                     | Description                                                              |
| ------------------------------------ | ------------------------------------------------ | ------------------------------------------------------------------------ |
| `1_hello_world.c`                    | `main()`, `<stdio.h>`, `printf()`                | The essential first step: compiling and running a basic program.         |
| `2_variables_and_data_types.c`       | `int`, `double`, `char`, format specifiers       | Learn to store, manage, and display information.                         |
| `3_user_input.c`                     | `scanf()`, `&` (address-of)                      | Make your programs interactive by reading user input from the keyboard.  |
| `4_basic_operators.c`                | `+`, `/`, `%`, `==`, `&&`, `||`                  | Perform calculations and make logical comparisons.                       |
| `5_conditional_statements.c`         | `if`, `else if`, `else`                          | Give your program a brain by letting it make decisions and follow logic. |
| `6_loops.c`                          | `for`, `while`, `do-while`                       | Teach your program to perform repetitive tasks efficiently.              |
| `7_functions.c`                      | Prototypes, definitions, calls                   | Organize code into clean, reusable, and modular blocks—a core concept.   |
| `8_arrays.c`                         | Declaration, initialization, iteration         | Manage collections of data of the same type.                             |
| `9_strings.c`                        | `char[]`, `\0` (null terminator), `<string.h>`   | Master text manipulation, a fundamental programming skill.               |

</details>

<details>
<summary><strong>Part 2: The Intermediate Path - Deeper into C</strong></summary>
<br>
<i>(Focus: Mastering memory, custom data types, and file persistence.)</i>

| Lesson                           | Key Concepts                                 | Description                                                              |
| -------------------------------- | -------------------------------------------- | ------------------------------------------------------------------------ |
| `10_pointers.c`                    | `&`, `*` (dereference), `NULL`               | Unlock C's most famous and powerful feature: direct memory manipulation. |
| `11_pointers_and_arrays.c`         | Pointer arithmetic                           | Explore the deep, fundamental relationship between pointers and arrays.  |
| `12_structs.c`                     | `struct`, member access (`.`, `->`)          | Create your own custom, complex data types to model real-world objects.  |
| `13_dynamic_memory_allocation.c` | `malloc()`, `free()`, the heap, memory leaks | Gain full control over your program's memory at runtime—a crucial C skill. |
| `14_file_io.c`                     | `FILE*`, `fopen()`, `fclose()`, `fprintf()`  | Persist data beyond program execution by reading from and writing to files.|
| `15_command_line_arguments.c`      | `argc`, `argv`                               | Make flexible tools that accept input directly from the command line.    |

</details>

<details>
<summary><strong>Part 3: The Advanced Path - Towards Mastery</strong></summary>
<br>
<i>(Focus: Building complete projects and learning advanced language features.)</i>

| Lesson                           | Key Concepts                                   | Description                                                                    |
| -------------------------------- | ---------------------------------------------- | ------------------------------------------------------------------------------ |
| `16_simple_calculator.c`         | **Project:** Combining `argv` and logic        | Build your first complete, useful tool from the skills you've learned.         |
| `17_student_record_system.c`     | **Project:** Structs, arrays, and file I/O   | Create a menu-driven database application to manage student records.           |
| `18_function_pointers.c`         | Callbacks, dispatch tables                     | Learn to treat functions like data for highly flexible and dynamic code.       |
| `19_recursion.c`                 | Base cases, recursive steps                    | Explore an elegant, powerful alternative to loops for solving complex problems.|
| `20_linked_lists.c`              | `struct Node`, traversal                       | Build one of the most fundamental dynamic data structures from scratch.        |
| `21_bit_manipulation.c`          | `&`, `|`, `^`, `~`, `<<`, `>>`                 | Go low-level by directly manipulating the individual bits of data.             |
| `22_preprocessor_directives.c`   | `#define`, `#include "..."`, `#ifdef`          | Understand the C preprocessor and how to manage large, multi-file projects.    |
| `23_unions_and_enums.c`          | `union`, `enum`                                | Learn specialized types for efficient memory use and creating readable constants.|
| `24_static_and_extern_variables.c` | `static`, `extern`, scope, linkage             | Master variable lifetime and visibility across an entire project.              |
| `25_simple_text_editor.c`        | **Capstone:** Doubly-linked list, File I/O     | Build a functional, line-based text editor. A true test of your C skills.      |

</details>

<details>
<summary><strong>Part 4: The Expert Path - Systems & Concurrency</strong></summary>
<br>
<i>(Focus: Interacting with the operating system, the network, and multiple CPU cores.)</i>

| Lesson                               | Key Concepts                                 | Description                                                                  |
| ------------------------------------ | -------------------------------------------- | ---------------------------------------------------------------------------- |
| `26_simple_socket_server.c`          | Sockets (`bind`, `listen`, `accept`)         | **Your Gateway to the Internet:** Build a basic client-server application.     |
| `27_build_your_own_grep.c`           | **Project:** Advanced File I/O, `strstr`     | **Build a Famous CLI Tool:** Create your own version of the `grep` utility.  |
| `28_hash_table_implementation.c`     | Hashing, collision resolution                | **The Engine of Modern Languages:** Implement a hash table from scratch.     |
| `29_tiny_shell.c`                      | **Project:** `fork`, `execvp`, `waitpid`     | **Build Your Own `bash`:** Create a working shell to execute other programs. |
| `30_multithreaded_file_analyzer.c`   | **Project:** `pthreads`, mutexes             | **Harness Multi-Core Power:** Use threads to analyze a large file in parallel. |

</details>

<details>
<summary><strong>Part 5: Expert Systems & Application Development</strong></summary>
<br>
<i>(Focus: Building large, multi-file applications with external libraries and advanced user interfaces.)</i>

| Lesson                                     | Key Concepts                                 | Description                                                                                             |
| ------------------------------------------ | -------------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| `31_make_files_for_multi_file_projects`    | **Project:** `make`, targets, rules          | Learn to automate the build process for complex, multi-file projects.                                   |
| `32_linking_external_libraries.c`          | `-L`, `-l` flags, library paths              | Understand how to find, link, and use third-party libraries like `ncurses`.                           |
| `33_advanced_terminal_ui.c`                | **Project:** `ncurses`, windows, color       | Move beyond `printf` to build rich, interactive user interfaces in the terminal.                        |
| `34_parsing_data_files.c`                  | `strtok`, `sscanf`, state machines           | Create programs that can be configured by reading and parsing structured text files.                  |
| `35_capstone_awesome_text_adventure.c`     | **Final Capstone Project**                   | A large, multi-file text RPG using `make`, `ncurses`, and a file-based world map. Integrates all course concepts into one epic final project. |

</details>

---

## ⭐ Show Your Support

If this approach helps you become a better developer, please **give this repository a star!** It helps the project reach more aspiring programmers and encourages us to keep creating great, free content.

## 🤝 Connect & Contribute

This project is for the community. Have an idea for a new feature, a better way to explain a concept, or find a bug? Feel free to [open an issue](https://github.com/dunamismax/C-From-The-Ground-Up-A-Project-Based-Approach/issues) or submit a pull request!

Connect with the author, **dunamismax**, on:

*   **Twitter:** [@dunamismax](https://twitter.com/dunamismax)
*   **Bluesky:** [@dunamismax.bsky.social](https://bsky.app/profile/dunamismax.bsky.social)
*   **Reddit:** [u/dunamismax](https://www.reddit.com/user/dunamismax)
*   **Discord:** `dunamismax`
*   **Signal:** `dunamismax.66`

## 📜 License

This project is licensed under the **MIT License**. See the `LICENSE` file for details.