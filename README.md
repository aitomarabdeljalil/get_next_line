# Get Next Line

This project implements the function `get_next_line`, which reads a line from a file descriptor and returns it. It is designed to work with any file descriptor and handle reading line by line. The project adheres to the constraints provided by the 42 curriculum.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Author](#author)
- [License](#license)

## Overview

The `get_next_line` function reads a line from a given file descriptor, terminating at a newline or EOF, and returns it. This function is useful for reading files incrementally, processing them one line at a time.

### Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters:
- `fd`: The file descriptor to read from.

### Return Value:
- A pointer to the next line from the file (including the newline, if present).
- `NULL` if there is nothing more to read or if an error occurs.

### Requirements:
- Memory must be allocated for each line dynamically.
- The function must handle multiple file descriptors simultaneously.

### Files

- get_next_line.c: Main implementation of the get_next_line function
- get_next_line_utils.c: Utility functions
- get_next_line.h: Header file
- get_next_line_bonus.c: Bonus implementation for multiple file descriptors
- get_next_line_utils_bonus.c: Utility functions for bonus part
- get_next_line_bonus.h: Header file for bonus part

## Features

- **Buffer Size Control**: The size of the buffer used for reading is determined by the `BUFFER_SIZE` macro.
- **Multi-file Support**: The function can handle multiple file descriptors in parallel.
- **Memory Management**: Each line is dynamically allocated and must be freed after use to prevent memory leaks.
- **Customizable Buffer Size**: You can define the buffer size by setting the `BUFFER_SIZE` macro during compilation.


## Installation

Clone this repository to your local machine:

```bash
git clone https://github.com/aitomarabdeljalil/get_next_line.git
cd get_next_line
```

## Usage

1. Include the `get_next_line` function in your project.
2. Compile the code with your preferred compiler and ensure to define the `BUFFER_SIZE`:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 -o gnl get_next_line.c get_next_line_utils.c
```

3. Run your program and use the `get_next_line` function to read lines from a file descriptor:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line);
}
close(fd);
```

## Testing

You can test the function using provided test files, or create your own by using different files as input. For example:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 -o test_gnl get_next_line.c get_next_line_utils.c main.c
./test_gnl
```

## Author

Ait Omar Abdeljalil (aait-oma@student.1337.ma)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
