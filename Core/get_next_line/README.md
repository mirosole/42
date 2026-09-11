*This project has been created as part of the 42 curriculum by olmirosh.*

# Get Next Line

## Description

`get_next_line` is a C project whose goal is to implement a function that reads from a file descriptor and returns one line at a time.

```c
char *get_next_line(int fd);
```

The returned line includes the terminating `\n` character when it exists.  
If there is nothing left to read, or if an error occurs, the function returns `NULL`.

The project is mainly focused on understanding:

- file descriptors;
- the `read()` system call;
- dynamic memory management with `malloc()` and `free()`;
- pointers and pointer-to-pointer usage;
- static variables;
- handling data that must remain available between function calls.

## Instructions

### Mandatory files

The mandatory part contains:

```text
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

The project can be compiled with a custom `BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

It must also compile without defining `BUFFER_SIZE`, using the default value defined in the header.

Example usage:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

### Bonus files

The bonus part contains:

```text
get_next_line_bonus.c
get_next_line_utils_bonus.c
get_next_line_bonus.h
```

The bonus version can manage several file descriptors at the same time while using only one static variable.

## Algorithm

The implementation uses a static pointer called `stash`.

The purpose of `stash` is to keep data that was already read from the file descriptor but has not yet been returned.

When `get_next_line()` is called:

1. The program checks whether `stash` already contains a newline.
2. If not, more data is read from the file descriptor.
3. Reading continues until:
   - a newline is found;
   - the end of the file is reached;
   - or `read()` returns an error.
4. The current line is extracted from `stash`.
5. The remaining data is saved for the next call.

The implementation also keeps track of:

- `used` — how many bytes are currently stored in `stash`;
- `capacity` — how much memory is currently allocated.

Before every new read, the program checks whether there is enough free space. If not, a larger block of memory is allocated, the existing data is copied into it, and the old block is freed.

New data is written directly after the existing data:

```c
read(fd, stash + used, BUFFER_SIZE);
```

This avoids repeatedly joining and copying the whole accumulated string after every read.

When a newline is found, the content is split into:

```text
line  -> data up to and including '\n'
stash -> remaining data
```

If the end of the file is reached without a final newline, the remaining content of `stash` is returned as the last line.

### Bonus algorithm

The bonus version uses one static array of pointers.

Each file descriptor has its own separate stash:

```text
stash[3] -> data for fd 3
stash[4] -> data for fd 4
stash[5] -> data for fd 5
```

This makes it possible to alternate between several file descriptors without losing the reading state of any of them.

## Resources

Resources used while working on the project:

- `man 2 read`
- `man 3 malloc`
- `man 3 free`
- 42 Get Next Line subject
- C documentation about pointers, static variables, and memory allocation

### AI usage

AI was used as a learning and debugging assistant.

It was used to:

- explain how static variables work;
- explain memory ownership and when memory should be freed;
- review compiler and Norminette errors;
- discuss edge cases and testing;
- help analyze performance problems with very small `BUFFER_SIZE` values.

The code and its behavior were reviewed step by step to make sure the implementation and the underlying concepts were understood.
