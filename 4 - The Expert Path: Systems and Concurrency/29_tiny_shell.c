/**
 * @file 29_tiny_shell.c
 * @author dunamismax 
 * @date 2025-06-10
 *
 * @brief An expert-level project: A tiny command-line shell.
 *
 * ---
 *
 * The Heart of the Operating System Interface
 *
 * A shell is the fundamental program that allows a user to interact with the
 * operating system's kernel. It reads your commands, interprets them, and asks
 * the OS to execute other programs. This project builds a simple version of `bash`.
 *
 * This is the most complex project so far, combining many concepts and introducing
 * the powerful process management system calls from POSIX.
 *
 * Core Concepts:
 * 1.  **Process Management:** This is the key. When you type `ls -l`, the shell
 *     doesn't have the code for `ls` inside it. Instead, it asks the OS to create
 *     a new process and run the `ls` program inside that new process.
 *
 * 2.  **`fork()`:** The magical system call that creates a new process. It clones
 *     the currently running process (our shell). The original is the "parent,"
 *     and the new one is the "child."
 *
 * 3.  **`exec()` family:** After forking, the child process uses a function from
 *     the `exec()` family (we use `execvp`) to *replace its own code* with the
 *     code of the program it's supposed to run (e.g., `ls`). If `execvp` succeeds,
 *     it never returns; the child process is now the `ls` program.
 *
 * 4.  **`wait()`:** The parent process (the shell) must wait for the child process
 *     (the command) to finish before printing the next prompt. The `waitpid()`
 *     system call accomplishes this.
 *
 * 5.  **Built-in Commands:** Some commands, like `cd` (change directory) and `exit`,
 *     *must* be handled directly by the shell itself. If `cd` were run in a forked
 *     child, only the child's directory would change, and then it would exit,
 *     leaving the parent shell's directory untouched.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * **This program is for POSIX systems (Linux, macOS) only.**
 *
 * 1.  **Compile the code:**
 *     `gcc -Wall -Wextra -std=c11 -o tiny_shell 29_tiny_shell.c`
 *
 * 2.  **Run the executable:**
 *     `./tiny_shell`
 *
 * 3.  **Interact with your shell!**
 *     > ls -a
 *     .  ..  tiny_shell  tiny_shell.c
 *     > echo Hello, Shell!
 *     Hello, Shell!
 *     > cd ..
 *     > pwd
 *     /path/to/your/parent/directory
 *     > exit
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   // For fork(), chdir(), execvp(), getcwd()
#include <sys/wait.h> // For waitpid()

#define MAX_LINE_LEN 256
#define MAX_ARGS 32

// --- Function Prototypes ---
void shell_loop(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);

// --- Built-in Command Prototypes ---
int shell_cd(char **args);
int shell_exit(char **args);
int shell_pwd(char **args);

// List of built-in command names and their corresponding functions
const char *builtin_str[] = {
    "cd",
    "exit",
    "pwd"};

int (*builtin_func[])(char **) = {
    &shell_cd,
    &shell_exit,
    &shell_pwd};

int num_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}

/**
 * @brief Main entry point.
 */
int main(void)
{
    // Run the main command loop.
    shell_loop();

    // The shell_loop only exits on an "exit" command or EOF.
    return EXIT_SUCCESS;
}

/**
 * @brief The main loop of the shell: gets input and executes it.
 */
void shell_loop(void)
{
    char *line;
    char **args;
    int status;

    do
    {
        printf("> ");
        line = read_line();
        // If line is NULL (EOF, e.g., Ctrl+D), exit gracefully.
        if (line == NULL)
        {
            printf("\n"); // Print a newline for clean exit
            break;
        }

        args = parse_line(line);
        status = execute_command(args);

        // Free the memory allocated by read_line and parse_line
        free(line);
        free(args);
    } while (status); // Loop continues as long as execute_command returns 1
}

/**
 * @brief Reads a single line of input from stdin.
 * @return The line from stdin as a dynamically allocated string.
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0; // getline will allocate a buffer for us

    // getline is a POSIX function that handles allocation, a safer alternative to gets().
    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            free(line);  // Must free even on EOF
            return NULL; // Handle End-Of-File (Ctrl+D)
        }
        else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}

/**
 * @brief Parses a line into a NULL-terminated array of arguments.
 * @param line The line to parse.
 * @return An array of string tokens (arguments).
 */
char **parse_line(char *line)
{
    char **tokens = malloc(MAX_ARGS * sizeof(char *));
    char *token;
    int position = 0;
    const char *delimiters = " \t\r\n\a"; // Space, tab, newline, etc.

    if (!tokens)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    // `strtok` splits the string into tokens.
    token = strtok(line, delimiters);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= MAX_ARGS)
        {
            fprintf(stderr, "Too many arguments.\n");
            // In a real shell, you might reallocate here. We'll just stop.
            break;
        }

        // Subsequent calls to strtok with NULL continue tokenizing the same string.
        token = strtok(NULL, delimiters);
    }
    tokens[position] = NULL; // The array must be NULL-terminated for execvp.
    return tokens;
}

/**
 * @brief Executes the command. Checks for built-ins first, then forks.
 * @param args The command and its arguments.
 * @return 1 to continue the loop, 0 to terminate.
 */
int execute_command(char **args)
{
    // An empty command was entered.
    if (args[0] == NULL)
    {
        return 1;
    }

    // Check if the command is a built-in.
    for (int i = 0; i < num_builtins(); i++)
    {
        if (strcmp(args[0], builtin_str[i]) == 0)
        {
            return (*builtin_func[i])(args);
        }
    }

    // If not a built-in, fork and execute.
    pid_t pid = fork();
    if (pid == 0)
    {
        // --- This is the Child Process ---
        // `execvp` searches the system's PATH for the program.
        // If it finds it, it replaces this entire process with the new program.
        if (execvp(args[0], args) == -1)
        {
            // `execvp` only returns if an error occurred.
            perror("tiny_shell");
        }
        exit(EXIT_FAILURE); // Exit the child process on exec error.
    }
    else if (pid < 0)
    {
        // --- Forking Error ---
        perror("fork");
    }
    else
    {
        // --- This is the Parent Process ---
        int status;
        // Wait for the child process to terminate.
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1; // Signal to continue the main loop.
}

// --- Built-in Function Implementations ---

/**
 * @brief Built-in 'cd' command: change directory.
 * @return Always 1 to continue the loop.
 */
int shell_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "tiny_shell: expected argument to \"cd\"\n");
    }
    else
    {
        // `chdir` is the system call to change the current directory.
        if (chdir(args[1]) != 0)
        {
            perror("tiny_shell");
        }
    }
    return 1;
}

/**
 * @brief Built-in 'exit' command: terminate the shell.
 * @return Always 0 to signal the main loop to terminate.
 */
int shell_exit(char **args)
{
    return 0;
}

/**
 * @brief Built-in 'pwd' command: print working directory.
 * @return Always 1 to continue the loop.
 */
int shell_pwd(char **args)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        perror("pwd");
    }
    return 1;
}