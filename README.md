# Pipex

This project is part of the 42 school curriculum. It implements a program that simulates the behavior of the shell pipe command.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Bonus Features](#bonus-features)

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

For more details on usage and implementation, please refer to the project subject.