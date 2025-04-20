/**
 * @file builtins.c
 * @brief Implementation of built-in shell commands
 *
 * This file contains functions to handle shell built-in commands
 * that don't require process creation (exit, cd, history).
 */
#include "shell.h"

/**
 * @brief Handle built-in shell commands
 *
 * Checks if the command is a built-in and executes it if so.
 * Currently supports: exit, cd, history
 *
 * @param args Array of command arguments (NULL-terminated)
 * @return 1 if command was a built-in and handled, 0 otherwise
 */
int handle_builtin(char **args) {
  /* Check for exit command */
  if (strcmp(args[0], "exit") == 0) {
    /* Save command history before exiting */
    write_history(".my_shell_history");
    exit(0); /* Exit shell with success status */
  }

  /* Check for cd (change directory) command */
  if (strcmp(args[0], "cd") == 0) {
    /* If no directory specified, use HOME environment variable */
    const char *dir = args[1] ? args[1] : getenv("HOME");

    /* Attempt to change directory */
    if (chdir(dir) != 0)
      perror("cd"); /* Print error if chdir fails */

    return 1; /* Indicate command was handled */
  }

  /* Check for history command */
  if (strcmp(args[0], "history") == 0) {
    /* Get history entries from readline library */
    HIST_ENTRY **hist = history_list();

    /* Print each history entry with line number if history exists */
    if (hist) {
      for (int i = 0; hist[i]; i++) {
        printf("%d: %s\n", i + 1, hist[i]->line);
      }
    }

    return 1; /* Indicate command was handled */
  }

  /* Not a built-in command */
  return 0;
}
