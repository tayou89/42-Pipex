# Pipex

This project is part of the 42 school curriculum. It implements a program that simulates the behavior of the shell pipe command.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Bonus Features](#bonus-features)
- [Makefile](#makefile)

## Description

Pipex is a program that mimics the functionality of shell pipes. It takes input from a file, executes a series of commands, and outputs the result to another file. This project demonstrates understanding of processes, file descriptors, and pipes in Unix-like operating systems.

## Features

- Simulates the behavior of shell pipes
- Handles input and output redirection
- Executes multiple commands in sequence
- Error handling for various scenarios

## Installation

To compile the project, follow these steps:

1. Clone the repository:
   ```
   git clone https://github.com/your-username/pipex.git
   ```
2. Navigate to the project directory:
   ```
   cd pipex
   ```
3. Compile the project using make:
   ```
   make
   ```

## Usage

The basic syntax for using pipex is:

```
./pipex file1 cmd1 cmd2 file2
```

This is equivalent to the shell command:

```
< file1 cmd1 | cmd2 > file2
```

## Examples

1. List files and count lines:
   ```
   ./pipex infile "ls -l" "wc -l" outfile
   ```

2. Search for a pattern and count words:
   ```
   ./pipex infile "grep hello" "wc -w" outfile
   ```

## Bonus Features

This implementation includes the following bonus features:

1. Multiple pipes:
   ```
   ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
   ```
   Equivalent to: `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`

2. Here document handling:
   ```
   ./pipex here_doc LIMITER cmd cmd1 file
   ```
   Equivalent to: `cmd << LIMITER | cmd1 >> file`

## Makefile

The project includes a Makefile for easy compilation and management. Here are the available commands:

- `make`: Compiles the project and generates the executable.
- `make all`: Same as `make`.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the executable.
- `make re`: Performs a complete recompilation (equivalent to `make fclean` followed by `make`).
- `make bonus`: Compiles the project with bonus features.

The Makefile uses the following flags for compilation:
- `-Wall`: Enables all compiler's warning messages.
- `-Wextra`: Enables some extra warning flags not enabled by `-Wall`.
- `-Werror`: Treats all warnings as errors.

Example usage:
```
make        # Compile the project
make clean  # Remove object files
make bonus  # Compile with bonus features
```

For more details on usage and implementation, please refer to [the project subject](requirements/pipex.pdf).