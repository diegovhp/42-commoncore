*This project has been created as part of the 42 curriculum by diegovhp.*

# Get Next Line

## Description

Get Next Line (GNL) is a C function that reads and returns one line at a time from a
file descriptor. Calling it repeatedly in a loop reads a file line by line until EOF.
The project teaches the concept of **static variables** — local variables that persist
their value between successive calls to the same function.

The returned line includes the terminating `\n` character, except on the last line of a
file that does not end with `\n`. Returns `NULL` when there is nothing left to read or
when an error occurs.

## Instructions

### Compilation

Compile with a custom buffer size (mandatory part):
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Compile with the default buffer size (defined as 42 in the header):
```
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```

Compile the bonus (multiple file descriptors):
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

Build with Makefile:
```
make        # builds get_next_line.a
make bonus  # builds get_next_line_bonus.a
make re     # rebuild from scratch
make clean  # remove object files
make fclean # remove object files and archives
```

### Usage example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int   fd;
    char  *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm

### Overview

The algorithm uses a **static `char *` variable** (`leftover`) to store bytes that were
read from the file descriptor but not yet returned to the caller. This leftover persists
across calls, enabling line-by-line extraction regardless of buffer boundaries.

### Step-by-step

1. **Guard**: Return `NULL` immediately if `fd` is invalid or `BUFFER_SIZE <= 0`.
2. **Read loop**: Allocate a temporary buffer of `BUFFER_SIZE + 1` bytes. Read chunks
   from `fd` into the buffer until a `\n` is found in `leftover` **or** `read()`
   returns 0 (EOF).
3. **Accumulate**: After each read, append the buffer content to `leftover` via
   `ft_strjoin` (which also frees the old `leftover`).
4. **Extract**: Once the loop exits, call `ft_extract_line` to copy from `leftover` up
   to and including the first `\n` (or to `\0` if no `\n`). This is the returned line.
5. **Update**: Call `ft_update_leftover` to discard the extracted line from `leftover`,
   keeping only the bytes after the `\n` for the next call. If no bytes remain,
   `leftover` is freed and set to `NULL`.

### Why this design?

- **Static variable**: Persists between calls without heap allocation of the state
  itself. Zero-initialized by the C runtime on the first call.
- **`ft_strjoin` frees `s1`**: Avoids double-tracking the old pointer — the caller
  simply reassigns `leftover = ft_strjoin(leftover, buf)`.
- **Buffer size independence**: Works correctly for `BUFFER_SIZE=1` (one byte at a
  time) up to very large values; the algorithm never reads more than necessary past the
  first `\n` found.

### Bonus: multiple file descriptors

The bonus replaces the single static pointer with a static array:

```c
static char *leftover[MAX_FD];  /* one slot per file descriptor */
```

This is still **one static variable** (an array). Each fd index is fully independent,
so interleaved calls on different fds never interfere. `MAX_FD` is defined as 1024.

## Resources

- `man 2 read` — read() syscall reference
- `man 3 malloc` / `man 3 free` — dynamic memory management
- [Static variables in C — cppreference](https://en.cppreference.com/w/c/language/storage_duration)
- [42 Norminette v3](https://github.com/42School/norminette) — code style rules

### AI usage

Claude Code was used to:
- Verify Norm v3 compliance (line count, variable count, formatting)
- Review correctness of edge cases: empty files, files without trailing `\n`, `BUFFER_SIZE=1`, multiple consecutive calls after EOF
- Draft the README structure and algorithm explanation
