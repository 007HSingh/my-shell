/**
 * @file executor.c
 * @brief Command execution functionality for custom shell
 *
 * This file contains functions to execute commands, handling both
 * built-in commands and external programs. It also supports
 * I/O redirection using < and > operators.
 */
#include "shell.h"

/**
 * @brief Execute a command with its arguments
 *
 * First checks if the command is a built-in. If not, forks a child process
 * to execute the external command. Handles I/O redirection if present.
 *
 * @param args Array of command arguments (NULL-terminated)
 */
void execute_command(char **args) {
  /* Check for empty command */
  if (args[0] == NULL)
    return;

  /* Check and handle built-in commands */
  if (handle_builtin(args))
    return;

  /* Variables for I/O redirection */
  int in_fd = -1, out_fd = -1;
  char *in_file = NULL, *out_file = NULL;

  /* Look for redirection operators in arguments */
  for (int i = 0; args[i]; i++) {
    /* Input redirection: command < file */
    if (strcmp(args[i], "<") == 0) {
      in_file = args[i + 1]; /* Save input filename */
      args[i] = NULL;        /* Remove redirection from arguments */
    }
    /* Output redirection: command > file */
    else if (strcmp(args[i], ">") == 0) {
      out_file = args[i + 1]; /* Save output filename */
      args[i] = NULL;         /* Remove redirection from arguments */
    }
  }

  /* Create child process */
  pid_t pid = fork();

  if (pid == 0) {
    /* Child process */

    /* Handle input redirection if specified */
    if (in_file) {
      /* Open input file for reading */
      in_fd = open(in_file, O_RDONLY);
      if (in_fd < 0) {
        perror("input open");
        exit(1); /* Exit child on error */
      }
      /* Redirect stdin to file */
      dup2(in_fd, STDIN_FILENO);
      close(in_fd);
    }

    /* Handle output redirection if specified */
    if (out_file) {
      /* Open output file for writing (create if not exists, truncate if exists)
       */
      out_fd = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
      if (out_fd < 0) {
        perror("output open");
        exit(1); /* Exit child on error */
      }
      /* Redirect stdout to file */
      dup2(out_fd, STDOUT_FILENO);
      close(out_fd);
    }

    /* Execute the command */
    if (execvp(args[0], args) == -1) {
      perror("exec");
      exit(EXIT_FAILURE); /* Exit child on error */
    }
  } else if (pid < 0) {
    /* Fork failed */
    perror("fork");
  } else {
    /* Parent process - wait for child to complete */
    waitpid(pid, NULL, 0);
  }
}
