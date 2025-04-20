/**
 * @file input.c
 * @brief Input handling functions for custom shell
 *
 * This file contains functions for reading user input and
 * parsing it into command arguments.
 */
#include "shell.h"

/**
 * @brief Read a line of input from the user
 *
 * Uses GNU Readline library to read input with editing capabilities.
 * Handles EOF (Ctrl+D) by exiting the shell.
 * Adds non-empty input to command history.
 *
 * @return A dynamically allocated string containing the user input
 */
char *read_input() {
  /* Prompt user and get input using readline */
  char *input = readline("$ ");

  /* Handle EOF (Ctrl+D) or error condition */
  if (!input) {
    printf("\n"); /* Print newline for clean exit */
    exit(0);      /* Exit shell gracefully */
  }

  /* Add non-empty input to history */
  if (*input)
    add_history(input);

  return input;
}

/**
 * @brief Parse user input into command arguments
 *
 * Splits the input string into tokens based on delimiters
 * defined in DELIM macro (spaces, tabs, etc.)
 *
 * @param input The string input from the user
 * @return A NULL-terminated array of argument strings
 */
char **parse_input(char *input) {
  /* Allocate memory for array of argument pointers */
  char **args = malloc(MAX_ARGS * sizeof(char *));

  /* Index counter for argument array */
  int i = 0;

  /* Get first token from input string */
  char *token = strtok(input, DELIM);

  /* Continue tokenizing until end of string or max args reached */
  while (token && i < MAX_ARGS - 1) {
    /* Store token pointer in argument array */
    args[i++] = token;

    /* Get next token */
    token = strtok(NULL, DELIM);
  }

  /* Null-terminate the argument array */
  args[i] = NULL;

  return args;
}
