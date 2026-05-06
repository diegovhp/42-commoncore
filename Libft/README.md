*This project has been created as part of the 42 curriculum by divan-he.*

---

## Description

**Libft** is a custom C library built as part of the 42 curriculum. The idea is to simply to reimplement standard libc functions yourself so you actually understand what's really going on when you use them, then bundle everything into a static library (libft.a) you can reuse across future projects.
It covers memory and string operations, a few extra utility functions that libc doesn´t offer and a basic linked list API.

---

## Instructions

### Compilation

Clone the repository and run `make` at the root:

```bash
make
```

This produces `libft.a` at the root of the repository.

### Available Makefile rules

| Rule | Effect |
|---|---|
| `make` / `make all` | Compile all sources into `libft.a` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and `libft.a` |
| `make re` | Full rebuild (`fclean` + `all`) |
| `make bonus` | Same as `all` (linked list is mandatory in this version) |

---

## Library Reference

### Part 1 — Libc functions

| Function | Description |
|---|---|
| `ft_isalpha` | Returns 1 if `c` is alphabetic, 0 otherwise |
| `ft_isdigit` | Returns 1 if `c` is a decimal digit, 0 otherwise |
| `ft_isalnum` | Returns 1 if `c` is alphanumeric, 0 otherwise |
| `ft_isascii` | Returns 1 if `c` fits in the ASCII table, 0 otherwise |
| `ft_isprint` | Returns 1 if `c` is a printable character, 0 otherwise |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Zeroes a byte string |
| `ft_memcpy` | Copies memory area (no overlap handling) |
| `ft_memmove` | Copies memory area (overlap-safe) |
| `ft_strlcpy` | Size-bounded string copy; returns source length |
| `ft_strlcat` | Size-bounded string concatenation; returns total length |
| `ft_toupper` | Converts lowercase letter to uppercase |
| `ft_tolower` | Converts uppercase letter to lowercase |
| `ft_strchr` | Finds first occurrence of a character in a string |
| `ft_strrchr` | Finds last occurrence of a character in a string |
| `ft_strncmp` | Compares up to `n` bytes of two strings |
| `ft_memchr` | Locates a byte in a memory area |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Finds a substring within a length-bounded string |
| `ft_atoi` | Converts a string to an integer |
| `ft_calloc` | Allocates and zero-initialises memory |
| `ft_strdup` | Returns a duplicate of a string allocated with `malloc` |

### Part 2 — Additional functions

| Function | Prototype | Description |
|---|---|---|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Allocates and returns a substring of `s` starting at `start` with max length `len` |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Allocates and returns the concatenation of `s1` and `s2` |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Allocates a trimmed copy of `s1` with leading/trailing characters from `set` removed |
| `ft_split` | `char **ft_split(char const *s, char c)` | Splits `s` on delimiter `c`, returns a NULL-terminated array of strings |
| `ft_itoa` | `char *ft_itoa(int n)` | Allocates and returns the string representation of integer `n` |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies `f` to each character of `s`, returns the resulting new string |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies `f` to each character of `s` in-place, passing its index |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Outputs character `c` to file descriptor `fd` |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Outputs string `s` to file descriptor `fd` |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Outputs string `s` followed by a newline to file descriptor `fd` |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Outputs integer `n` to file descriptor `fd` |

### Part 3 — Linked list

The library exposes the following structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Prototype | Description |
|---|---|---|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Allocates and returns a new node with `content` set and `next` as NULL |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Prepends `new` to the list |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Returns the number of nodes in the list |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Returns the last node of the list |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Appends `new` to the list |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees the content of `lst` using `del`, then frees the node (does not touch `next`) |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes and frees the entire list from `lst` onward, sets `*lst` to NULL |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies `f` to the content of every node |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Creates a new list by applying `f` to each node's content; uses `del` on failure |

---

## Resources

### References

- C Standard Library
- `man` pages
- *The C Programming Language*
- w3schools

### AI usage

Claude was used during the revision phase of this project for:
- **Explaining concepts** — clarifying the difference between `size_t` and `unsigned int` for memory-size operations, the undefined behaviour in `ft_atoi`, clarifying linked lists theoretical aspects.
- **Generating this README file** — I wrote the content and Claude generated the README file.
