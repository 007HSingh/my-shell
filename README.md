# My Custom Shell

A lightweight shell implementation in C featuring command history, built-in commands, and I/O redirection.

## Features

- Command execution with arguments
- Command history (saved between sessions)
- Built-in commands: `cd`, `exit`, `history`
- I/O redirection with `<` and `>` operators
- GNU Readline integration for input handling

## Project Structure

- `main.c` - Entry point with main shell loop
- `shell.h` - Header file with declarations
- `input.c` - Handles user input and parsing
- `executor.c` - Command execution with forking and redirection
- `builtins.c` - Implementation of built-in shell commands

## Dependencies

- GNU Readline library

## Building

To build the shell, run:

```
make
```

## Usage

After building, run the shell:

```
./myshell
```

A prompt `$` will appear, waiting for your commands.

### Built-in Commands

- `cd [directory]` - Change current directory (defaults to HOME if no directory specified)
- `exit` - Exit the shell
- `history` - Display command history

### I/O Redirection

The shell supports basic I/O redirection:

```
$ command < input_file  # Input redirection
$ command > output_file # Output redirection
```

## Command History

Command history is automatically saved to `.my_shell_history` in the current directory.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
