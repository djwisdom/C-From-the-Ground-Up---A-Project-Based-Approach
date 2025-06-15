<div align="center">
<img src="https://i.imgur.com/e82iG3A.png" alt="C From The Ground Up Banner" width="800" height="250"/>
<h1>C From The Ground Up - A Project-Based Journey</h1>
<p>
<b>A complete, open-source curriculum that teaches you C by building a portfolio of real-world tools and applications from scratch.</b>
</p>
<p>
This course uses a unique, hands-on teaching method: <b>the lesson is in the code</b>. You'll learn every concept from structured comments inside a single, runnable C file for each topic.
</p>
<p>
<a href="https://en.wikipedia.org/wiki/C11_(C_standard_revision)"><img src="https://img.shields.io/badge/Language-C11-blue.svg" alt="C11"></a>
<a href="https://www.gnu.org/software/make/"><img src="https://img.shields.io/badge/Build-Make-green.svg" alt="Make"></a>
<a href="https://en.wikipedia.org/wiki/Ncurses"><img src="https://img.shields.io/badge/UI-ncurses-9cf" alt="ncurses"></a>
<a href="https://github.com/dunamismax/C-From-the-Ground-Up---A-Project-Based-Journey/blob/main/LICENSE"><img src="https://img.shields.io/badge/License-MIT-yellow.svg" alt="License: MIT"></a>
<a href="https://github.com/dunamismax/C-From-the-Ground-Up---A-Project-Based-Journey/pulls"><img src="https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square" alt="PRs Welcome"></a>
</p>
</div>
Welcome to the ultimate journey into the C programming language! This is not just a tutorial; it's a complete, foundational computer science education designed to build deep, practical knowledge. We start with the absolute basics—assuming you've never written a line of code—and end with a portfolio of impressive systems projects, including a multithreaded application and an advanced text-based RPG.

Learning C is learning the fundamentals of how computers truly work. This course is your foundation, laid one brick—one concept, one project—at a time. Mastering C will make you a fundamentally better developer, no matter what language you use in the future.
✨ Why This Journey?
📖 Learn Directly In The Code: Forget switching between theory and practice. Every lesson is taught directly within the comments of a single, runnable C file. The code is the textbook.
👨‍💻 True Beginners Welcome: This course has zero prerequisites. We'll guide you through installing a compiler and writing printf("Hello, World!"); before we even think about pointers.
🚀 From Console to Systems Mastery: The curriculum is carefully designed to build your skills layer by layer. You'll master C fundamentals, build a portfolio of classic command-line tools, and finally develop complex, multi-file applications.
🛠️ Build an Impressive Portfolio: The entire course is oriented around practical projects. Every concept, from malloc to pthreads, is a building block for tools like your own grep, a tiny shell, and a final text adventure game.
💪 Master the Hard Parts: We embrace C's most powerful (and feared) features. You will gain true confidence with pointers, dynamic memory allocation, low-level bit manipulation, process management, and multithreading.
🌍 Open Source & Community Driven: This curriculum is for the community. Contributions, suggestions, bug fixes, and project ideas are highly encouraged!
💻 Tech Stack & Prerequisites
You don't need any programming knowledge to start, but you will need to install a few standard development tools.

A C Compiler like GCC (recommended) or Clang.
Make for automating the build process in later projects.
Git for cloning the repository.
An IDE or Text Editor (Visual Studio Code, CLion, Vim, or Sublime Text are great choices).
🚀 How to Use This Course
Each lesson folder contains one or more source files. For most of the course, a single .c file is both the complete, runnable program and the full lesson text.

Read the Lesson: Navigate to a lesson folder (e.g., Part1_Core_Concepts/01_HelloWorld/) and open the .c file. Read the comments from top to bottom to understand the concepts.
Compile and Run the Code: To see the lesson's concepts in action, you'll need to compile and run the program.
First, clone the repository (you only need to do this once):
git clone https://github.com/dunamismax/C-From-the-Ground-Up---A-Project-Based-Journey.git
cd C-From-the-Ground-Up---A-Project-Based-Journey
content_copy
download
Use code with caution.
Sh
Then, for each lesson, navigate to its folder and use the C compiler. We highly recommend using these flags to catch common errors.
# Example for the first lesson
cd Part1_Core_Concepts/01_HelloWorld

# Compile the code using GCC
gcc -Wall -Wextra -std=c11 -o HelloWorld HelloWorld.c

# Run the compiled program
# On Linux/macOS
./HelloWorld

# On Windows
HelloWorld.exe
content_copy
download
Use code with caution.
Sh
Note: Later projects will use Make. In those cases, you will simply run the make command in the lesson directory.
📚 The Journey
The curriculum is divided into five parts, taking you from a blank text file to a C master capable of building complex systems applications.

<details>
<summary><strong>Part 1: The Beginner Path - Core Concepts</strong></summary>
<br>
<i>(Focus: Core language syntax and logic, taught entirely within single-file console applications.)</i>
<table>
<thead>
<tr>
<th>Lesson</th>
<th>Key Concepts</th>
<th>Description</th>
</tr>
</thead>
<tbody>
<tr>
<td><code>01_HelloWorld.c</code></td>
<td><code>main()</code>, <code>&lt;stdio.h&gt;</code>, <code>printf()</code></td>
<td>The essential first step: compiling and running a basic program.</td>
</tr>
<tr>
<td><code>02_VariablesAndDataTypes.c</code></td>
<td><code>int</code>, <code>double</code>, <code>char</code>, format specifiers</td>
<td>Learn to store, manage, and display information.</td>
</tr>
<tr>
<td><code>03_UserInput.c</code></td>
<td><code>scanf()</code>, <code>&</code> (address-of)</td>
<td>Make your programs interactive by reading user input from the keyboard.</td>
</tr>
<tr>
<td><code>04_BasicOperators.c</code></td>
<td><code>+</code>, <code>/</code>, <code>%</code>, <code>==</code>, <code>&&</code>, <code>||</code></td>
<td>Perform calculations and make logical comparisons.</td>
</tr>
<tr>
<td><code>05_ConditionalStatements.c</code></td>
<td><code>if</code>, <code>else if</code>, <code>else</code></td>
<td>Give your program a brain by letting it make decisions and follow logic.</td>
</tr>
<tr>
<td><code>06_Loops.c</code></td>
<td><code>for</code>, <code>while</code>, <code>do-while</code></td>
<td>Teach your program to perform repetitive tasks efficiently.</td>
</tr>
<tr>
<td><code>07_Functions.c</code></td>
<td>Prototypes, definitions, calls</td>
<td>Organize code into clean, reusable, and modular blocks—a core concept.</td>
</tr>
<tr>
<td><code>08_Arrays.c</code></td>
<td>Declaration, initialization, iteration</td>
<td>Manage collections of data of the same type.</td>
</tr>
<tr>
<td><code>09_Strings.c</code></td>
<td><code>char[]</code>, <code>\0</code> (null terminator), <code>&lt;string.h&gt;</code></td>
<td>Master text manipulation, a fundamental programming skill.</td>
</tr>
</tbody>
</table>
</details>
<details>
<summary><strong>Part 2: The Intermediate Path - Deeper into C</strong></summary>
<br>
<i>(Focus: Mastering memory, custom data types, and file persistence.)</i>
<table>
<thead>
<tr>
<th>Lesson</th>
<th>Key Concepts</th>
<th>Description</th>
</tr>
</thead>
<tbody>
<tr>
<td><code>10_Pointers.c</code></td>
<td><code>&amp;</code>, <code>*</code> (dereference), <code>NULL</code></td>
<td>Unlock C's most famous and powerful feature: direct memory manipulation.</td>
</tr>
<tr>
<td><code>11_PointersAndArrays.c</code></td>
<td>Pointer arithmetic</td>
<td>Explore the deep, fundamental relationship between pointers and arrays.</td>
</tr>
<tr>
<td><code>12_Structs.c</code></td>
<td><code>struct</code>, member access (<code>.</code>, <code>-&gt;</code>)</td>
<td>Create your own custom, complex data types to model real-world objects.</td>
</tr>
<tr>
<td><code>13_DynamicMemory.c</code></td>
<td><code>malloc()</code>, <code>free()</code>, the heap, memory leaks</td>
<td>Gain full control over your program's memory at runtime—a crucial C skill.</td>
</tr>
<tr>
<td><code>14_FileIO.c</code></td>
<td><code>FILE*</code>, <code>fopen()</code>, <code>fclose()</code>, <code>fprintf()</code></td>
<td>Persist data beyond program execution by reading from and writing to files.</td>
</tr>
<tr>
<td><code>15_CommandLineArgs.c</code></td>
<td><code>argc</code>, <code>argv</code></td>
<td>Make flexible tools that accept input directly from the command line.</td>
</tr>
</tbody>
</table>
</details>
<details>
<summary><strong>Part 3: The Advanced Path - Towards Mastery</strong></summary>
<br>
<i>(Focus: Building complete projects and learning advanced language features.)</i>
<table>
<thead>
<tr>
<th>Lesson</th>
<th>Key Concepts</th>
<th>Description</th>
</tr>
</thead>
<tbody>
<tr>
<td><code>16_SimpleCalculator.c</code></td>
<td><strong>Project:</strong> Combining `argv` and logic</td>
<td>Build your first complete, useful tool from the skills you've learned.</td>
</tr>
<tr>
<td><code>17_StudentRecordSystem.c</code></td>
<td><strong>Project:</strong> Structs, arrays, and file I/O</td>
<td>Create a menu-driven database application to manage student records.</td>
</tr>
<tr>
<td><code>18_FunctionPointers.c</code></td>
<td>Callbacks, dispatch tables</td>
<td>Learn to treat functions like data for highly flexible and dynamic code.</td>
</tr>
<tr>
<td><code>19_Recursion.c</code></td>
<td>Base cases, recursive steps</td>
<td>Explore an elegant, powerful alternative to loops for solving complex problems.</td>
</tr>
<tr>
<td><code>20_LinkedLists.c</code></td>
<td><code>struct Node</code>, traversal</td>
<td>Build one of the most fundamental dynamic data structures from scratch.</td>
</tr>
<tr>
<td><code>21_BitManipulation.c</code></td>
<td><code>&amp;</code>, <code>|</code>, <code>^</code>, <code>~</code>, <code>&lt;&lt;</code>, <code>&gt;&gt;</code></td>
<td>Go low-level by directly manipulating the individual bits of data.</td>
</tr>
<tr>
<td><code>22_Preprocessor.c</code></td>
<td><code>#define</code>, <code>#include "..."</code>, <code>#ifdef</code></td>
<td>Understand the C preprocessor and how to manage large, multi-file projects.</td>
</tr>
<tr>
<td><code>23_UnionsAndEnums.c</code></td>
<td><code>union</code>, <code>enum</code></td>
<td>Learn specialized types for efficient memory use and creating readable constants.</td>
</tr>
<tr>
<td><code>24_StaticAndExtern.c</code></td>
<td><code>static</code>, <code>extern</code>, scope, linkage</td>
<td>Master variable lifetime and visibility across an entire project.</td>
</tr>
<tr>
<td><code>25_SimpleTextEditor.c</code></td>
<td><strong>Capstone:</strong> Doubly-linked list, File I/O</td>
<td>Build a functional, line-based text editor. A true test of your C skills.</td>
</tr>
</tbody>
</table>
</details>
<details>
<summary><strong>Part 4: The Expert Path - Systems & Concurrency</strong></summary>
<br>
<i>(Focus: Interacting with the operating system, the network, and multiple CPU cores.)</i>
<table>
<thead>
<tr>
<th>Lesson</th>
<th>Key Concepts</th>
<th>Description</th>
</tr>
</thead>
<tbody>
<tr>
<td><code>26_SimpleSocketServer.c</code></td>
<td>Sockets (`bind`, `listen`, `accept`)</td>
<td><strong>Your Gateway to the Internet:</strong> Build a basic client-server application.</td>
</tr>
<tr>
<td><code>27_BuildYourOwnGrep.c</code></td>
<td><strong>Project:</strong> Advanced File I/O, `strstr`</td>
<td><strong>Build a Famous CLI Tool:</strong> Create your own version of the `grep` utility.</td>
</tr>
<tr>
<td><code>28_HashTable.c</code></td>
<td>Hashing, collision resolution</td>
<td><strong>The Engine of Modern Languages:</strong> Implement a hash table from scratch.</td>
</tr>
<tr>
<td><code>29_TinyShell.c</code></td>
<td><strong>Project:</strong> `fork`, `execvp`, `waitpid`</td>
<td><strong>Build Your Own `bash`:</strong> Create a working shell to execute other programs.</td>
</tr>
<tr>
<td><code>30_MultithreadedFileAnalyzer.c</code></td>
<td><strong>Project:</strong> `pthreads`, mutexes</td>
<td><strong>Harness Multi-Core Power:</strong> Use threads to analyze a large file in parallel.</td>
</tr>
</tbody>
</table>
</details>
<details>
<summary><strong>Part 5: Expert Systems & Application Development</strong></summary>
<br>
<i>(Focus: Building large, multi-file applications with external libraries and advanced user interfaces.)</i>
<table>
<thead>
<tr>
<th>Lesson</th>
<th>Key Concepts</th>
<th>Description</th>
</tr>
</thead>
<tbody>
<tr>
<td><code>31_MakefilesForMultiFileProjects</code></td>
<td><strong>Project:</strong> `make`, targets, rules</td>
<td>Learn to automate the build process for complex, multi-file projects.</td>
</tr>
<tr>
<td><code>32_LinkingExternalLibraries</code></td>
<td><code>-L</code>, <code>-l</code> flags, library paths</td>
<td>Understand how to find, link, and use third-party libraries like `ncurses`.</td>
</tr>
<tr>
<td><code>33_AdvancedTerminalUI</code></td>
<td><strong>Project:</strong> `ncurses`, windows, color</td>
<td>Move beyond `printf` to build rich, interactive user interfaces in the terminal.</td>
</tr>
<tr>
<td><code>34_ParsingDataFiles</code></td>
<td>`strtok`, `sscanf`, state machines</td>
<td>Create programs that can be configured by reading and parsing structured text files.</td>
</tr>
<tr>
<td><code>35_Capstone_AwesomeTextAdventure</code></td>
<td><strong>Final Capstone Project</strong></td>
<td>A large, multi-file text RPG using `make`, `ncurses`, and a file-based world map. Integrates all course concepts into one epic final project.</td>
</tr>
</tbody>
</table>
</details>
⭐ Show Your Support
If this journey helps you become a better developer, please give this repository a star! It helps the project reach more aspiring programmers and encourages us to keep creating great, free content.

🤝 Connect & Contribute
This project is for the community. Have an idea for a new feature, a better way to explain a concept, or find a bug? Feel free to open an issue or submit a pull request!

Connect with the author, dunamismax, on:

Twitter: @dunamismax
Bluesky: @dunamismax.bsky.social
Reddit: u/dunamismax
Discord: dunamismax
Signal: dunamismax.66
📜 License
This project is licensed under the MIT License. See the LICENSE file for details.
