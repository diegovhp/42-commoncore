#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_numlen(unsigned long n, int base);
int	ft_putstr(char *str);
int	ft_putnbr(long n);
int	ft_putunbr(unsigned long n);
int	ft_puthex(unsigned long n, int upper);
int	ft_putptr(uintptr_t n);
int	ft_format(va_list args, const char *fmt, int *i);

#endif
