*diegovhp*

## Description

ft_printf is a reimplementation of the C standard library `printf` function as a
static library (`libftprintf.a`). It handles formatted output to standard output,
supporting the most common conversion specifiers and (as a bonus) the full set of
formatting flags.

## Instructions

### Compile

```bash
# Mandatory part (basic specifiers, no flags)
make

# Bonus part (all flags, width, precision)
make bonus
```

### Use in your project

```bash
gcc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```

Include the header in your source:

```c
#include "ft_printf.h"
```

### Supported conversions

| Specifier | Description                          |
|-----------|--------------------------------------|
| `%c`      | Single character                     |
| `%s`      | String (NULL → `(null)`)             |
| `%p`      | Pointer address (NULL → `(nil)`)     |
| `%d` `%i` | Signed decimal integer               |
| `%u`      | Unsigned decimal integer             |
| `%x`      | Unsigned hex, lowercase              |
| `%X`      | Unsigned hex, uppercase              |
| `%%`      | Literal percent sign                 |

### Bonus flags (make bonus)

| Flag      | Effect                                                   |
|-----------|----------------------------------------------------------|
| `-`       | Left-align within field width                            |
| `0`       | Zero-pad instead of space-pad (disabled when `-` or precision set) |
| `#`       | Prefix `0x`/`0X` for non-zero hex values                |
| ` `       | Prefix space for positive numbers                        |
| `+`       | Always show sign (`+` or `-`)                            |
| `*`       | Read width or precision from the argument list           |
| `.prec`   | Minimum digit count (numbers) or max length (strings)    |
| `width`   | Minimum field width                                      |

## Algorithm and data structures

The parser walks the format string one character at a time. When `%` is found it
advances the index and calls `ft_format`, which uses `ft_parse` (bonus build) to
collect flags, width, and precision into a `t_flags` struct before dispatching to
the appropriate output function.

Numbers are printed recursively: `ft_numlen` counts the digits first, then the
recursive `putnbr_base` / `puthex_base` functions descend to the most-significant
digit and print on the way back up, so no buffer allocation is needed.

Zero-padding, precision padding, sign, and field-width padding are resolved
arithmetically from `content_len` before any output is written.

## Resources

- C standard (`printf` specification): ISO/IEC 9899:2011 §7.21.6
- `man 3 printf`
- `man 2 write`
- `man 3 va_start`

AI assistance (Claude, Anthropic) was used during development for review,
edge-case analysis, and restructuring of the bonus/mandatory file split.
