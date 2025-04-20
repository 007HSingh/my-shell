/**
 * @file shell.h
 * @brief Main header file for the custom shell implementation
 *
 * This file contains all declarations and constants used throughout
 * the shell implementation.
 */

#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * @def MAX_ARGS
 * @brief Maximum number of command arguments supported
 */
#define MAX_ARGS 64

/**
 * @def DELIM
 * @brief Delimiters used for tokenizing input
 */
#define DELIM " \t\r\n\a"

/**
 * @brief Read a line of input from the user using readline
 *
 * Uses GNU Readline to get user input with line editing capabilities
 * and adds the input to command history if non-empty.
 *
 * @return A dynamically allocated string containing the user input
 */
char *read_input();

/**
 * @brief Parse user input into an array of arguments
 *
 * Tokenizes the input string using the DELIM characters and
 * creates an array of strings terminated with NULL.
 *
 * @param input The string input from the user
 * @return A NULL-terminated array of arguments
 */
char **parse_input(char *input);

/**
 * @brief Execute a command with its arguments
 *
 * Handles both built-in commands and external programs.
 * For external programs, it forks a child process and uses execvp.
 * Also manages I/O redirection with < and > operators.
 *
 * @param args Array of command arguments
 */
void execute_command(char **args);

/**
 * @brief Check if a command is a built-in and execute it
 *
 * Handles the built-in commands: exit, cd, and history
 *
 * @param args Array of command arguments
 * @return 1 if the command was a built-in, 0 otherwise
 */
int handle_builtin(char **args);

#endif /* SHELL_H */
