*This project has been created as part of the 42 curriculum by asomich.*

# Libft

## Description

Libft is a custom C library that recreates a set of standard C library
functions, adds linked list operations, and includes several utility functions
used throughout the 42 curriculum. The goal of the project is to understand how
common C library functions work, practice memory management, and build a
reusable static library for future C projects.

The project produces `libft.a`, a static archive that can be linked with other C
programs. All functions use the `ft_` prefix.

## Detailed Library Description

This library contains character checks and conversions, memory manipulation,
string manipulation, allocation helpers, file-descriptor output helpers, and
singly linked list utilities.

The first part of the library reproduces common libc behavior, such as checking
character classes, converting character case, comparing memory areas, copying
memory, searching inside strings, and converting strings to integers. The second
part adds utility functions that allocate and return new strings, split strings
by a delimiter, apply functions to string characters, and print values to a
given file descriptor. The bonus part implements a simple singly linked list
type, `t_list`, together with helpers to create, append, iterate, map, and clear
list nodes.

Character functions:

- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`

Memory functions:

- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_calloc`

String functions:

- `ft_strlen`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_strnstr`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strdup`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`

Output functions:

- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

Linked list functions:

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## Instructions

The project is compiled with the following flags:

```make
CFLAGS = -Wall -Wextra -Werror
```

Build the library:

```sh
make
```

Remove object files:

```sh
make clean
```

Remove object files and the static library:

```sh
make fclean
```

Rebuild from scratch:

```sh
make re
```

To use the library in another C file, include the header:

```c
#include "libft.h"
```

Then compile and link with `libft.a`, for example:

```sh
cc -Wall -Wextra -Werror main.c libft.a
```

To test the library, you can install and run this tester from GitHub:

```sh
git clone https://github.com/Tripouille/libftTester.git
cd libftTester
make
```

If you have problems with the `make` command, try:

```sh
TERM=xterm make CC=g++
```

## Resources

Classic references used for this project:

- The official 42 Libft subject PDF.
- Linux manual pages, for example `man strlen`, `man memcpy`, `man calloc`,
  and `man strncmp`.
- Metanit C documentation: https://metanit.com/c/ (available only in Russian).
- Stack Overflow for specific C language questions.
- GeeksforGeeks articles about linked lists: https://www.geeksforgeeks.org/
- 42 Makefile tutorial:
  https://github.com/gleal42/Makefile-Tutorial#43-rules-name-all-clean-fclean-re
- Tripouille/libftTester for local testing:
  https://github.com/Tripouille/libftTester.git
- Habr article about Makefiles:
  https://habr.com/ru/articles/155201/ (available only in Russian).
- Valgrind for checking memory leaks.

AI usage:

- AI was used to create tests for checking correct function output.
- AI was used to help format code according to Norminette rules.
- AI was used to partially draft this README. This does not mean that AI made
  the whole project; it was used as a tool.
- AI was used to find alternative approaches to solving tasks and to highlight
  how existing functions can be reused to simplify other implementations.
