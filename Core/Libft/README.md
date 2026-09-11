*This project has been created as part of the 42 curriculum by olmirosh.*

# Libft

## Description

Libft is a custom C library created as part of the 42 curriculum.

The goal of the project is to recreate a set of standard C library functions and to implement additional utility functions that are useful for future C projects.

The project focuses on low-level programming concepts such as:

- pointers and memory addresses;
- manual memory management;
- string manipulation;
- raw memory operations;
- dynamic allocation with `malloc`;
- file descriptors and `write`;
- function pointers;
- singly linked lists;
- static libraries and Makefiles.

The final result is a static library named `libft.a`.

## Library Description

The library contains 43 functions divided into several groups.

### Character Classification

- `ft_isalpha` — checks whether a character is alphabetic.
- `ft_isdigit` — checks whether a character is a decimal digit.
- `ft_isalnum` — checks whether a character is alphabetic or a digit.
- `ft_isascii` — checks whether a value belongs to the ASCII range.
- `ft_isprint` — checks whether a character is printable.

### Character Conversion

- `ft_toupper` — converts a lowercase letter to uppercase.
- `ft_tolower` — converts an uppercase letter to lowercase.

### String Functions

- `ft_strlen` — returns the length of a string.
- `ft_strchr` — finds the first occurrence of a character in a string.
- `ft_strrchr` — finds the last occurrence of a character in a string.
- `ft_strncmp` — compares two strings up to a specified number of characters.
- `ft_strlcpy` — copies a string into a destination buffer with a size limit.
- `ft_strlcat` — appends one string to another with a size limit.
- `ft_strnstr` — searches for a substring inside a limited part of another string.
- `ft_strdup` — creates a dynamically allocated copy of a string.
- `ft_substr` — creates a substring from a source string.
- `ft_strjoin` — joins two strings into a new string.
- `ft_strtrim` — removes selected characters from the beginning and end of a string.
- `ft_split` — splits a string into an array of strings using a delimiter.
- `ft_strmapi` — creates a new string by applying a function to every character.
- `ft_striteri` — applies a function to every character of a string.

### Memory Functions

- `ft_memset` — fills a memory block with a byte value.
- `ft_bzero` — fills a memory block with zeroes.
- `ft_memcpy` — copies a block of memory.
- `ft_memmove` — copies memory safely when source and destination overlap.
- `ft_memchr` — searches for a byte inside a memory block.
- `ft_memcmp` — compares two memory blocks.
- `ft_calloc` — allocates memory and initializes it to zero.

### Conversion Functions

- `ft_atoi` — converts a string to an integer.
- `ft_itoa` — converts an integer to a dynamically allocated string.

### File Descriptor Output

- `ft_putchar_fd` — writes one character to a file descriptor.
- `ft_putstr_fd` — writes a string to a file descriptor.
- `ft_putendl_fd` — writes a string followed by a newline to a file descriptor.
- `ft_putnbr_fd` — writes an integer to a file descriptor.

### Linked List Functions

The library also includes functions for working with a singly linked list.

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Functions:

- `ft_lstnew` — creates a new list node.
- `ft_lstadd_front` — adds a node to the beginning of a list.
- `ft_lstsize` — returns the number of nodes in a list.
- `ft_lstlast` — returns the last node of a list.
- `ft_lstadd_back` — adds a node to the end of a list.
- `ft_lstdelone` — deletes one node and its content using a provided function.
- `ft_lstclear` — deletes an entire list.
- `ft_lstiter` — applies a function to the content of every node.
- `ft_lstmap` — creates a new list by applying a function to every node.

## Instructions

### Compilation

Compile the library with:

```bash
make
```

This creates the static library:

```text
libft.a
```

### Makefile Rules

Remove object files:

```bash
make clean
```

Remove object files and the library:

```bash
make fclean
```

Rebuild the project:

```bash
make re
```

### Using the Library

Include the header in your C source file:

```c
#include "libft.h"
```

Example compilation:

```bash
cc -Wall -Wextra -Werror main.c libft.a -o program
```

Run the program with:

```bash
./program
```

### Norminette

To check the source files with Norminette:

```bash
norminette *.c *.h
```

## Resources

The following resources were used while working on the project:

- Official 42 Libft subject.
- C manual pages, especially `man 2 write`, `man 3 malloc`, and the manual pages for standard C functions recreated in the project.
- Standard C documentation and references for strings, memory management, and linked lists.
- Compiler diagnostics from `cc` / `clang`.
- Norminette output for checking compliance with the 42 coding standard.
- External Libft testers for additional validation during development.

### External Testing

For additional testing, Tripouille's Libft tester can be used.

From the root of the Libft project:

```bash
mkdir -p ../Testers
git clone https://github.com/Tripouille/libftTester.git ../Testers/tripouille
```

Run the tester with:

```bash
make -C ../Testers/tripouille LIBFT_PATH="$(pwd)"
```

To test only one function, for example `ft_split`:

```bash
make -C ../Testers/tripouille split LIBFT_PATH="$(pwd)"
```

### AI Usage

AI was used as a learning and debugging assistant during the project.

It was used for:

- explaining C concepts such as memory allocation, function pointers, and linked lists;
- explaining compiler errors and Norminette errors;
- helping analyze why specific tests failed;
- reviewing code and suggesting possible corrections;
- helping organize and write the project documentation.
