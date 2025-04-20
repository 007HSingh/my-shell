/**
 * @file main.c
 * @brief Entry point for custom shell implementation
 *
 * This file contains the main function that initializes the shell,
 * reads and processes user input in a continuous loop, and handles cleanup.
 */
#include "shell.h"

/**
 * @def HISTORY_FILE
 * @brief File where command history is saved
 */
#define HISTORY_FILE ".my_shell_history"

/**
 * @brief Main function - entry point for the shell
 *
 * Initializes readline history, loads previous history from file,
 * enters the main command processing loop until exit, and
 * saves history before exiting.
 *
 * @return Exit status code
 */
int main() {
  /* Initialize the readline history functionality */
  using_history();

  /* Load command history from previous sessions */
  read_history(HISTORY_FILE);

  /* Main shell loop - continues until exit command or signal */
  while (1) {
    /* Get input from user using readline library */
    char *input = read_input();

    /* Parse the input into an array of arguments */
    char **args = parse_input(input);

    /* Execute the command with its arguments */
    execute_command(args);

    /* Free allocated memory to prevent leaks */
    free(input);
    free(args);
  }

  /* Save command history to file (note: this code is unreachable
     in the current implementation because exit is handled in builtins.c) */
  write_history(HISTORY_FILE);

  return 0;
}
