#include "ft_printf.h"

int	ft_format(va_list args, const char *fmt, int *i)
{
	if (fmt[*i] == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	if (fmt[*i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (fmt[*i] == 'p')
		return (ft_putptr((uintptr_t)va_arg(args, void *)));
	if (fmt[*i] == 'd' || fmt[*i] == 'i')
		return (ft_putnbr((long)va_arg(args, int)));
	if (fmt[*i] == 'u')
		return (ft_putunbr((unsigned long)va_arg(args, unsigned int)));
	if (fmt[*i] == 'x')
		return (ft_puthex((unsigned long)va_arg(args, unsigned int), 0));
	if (fmt[*i] == 'X')
		return (ft_puthex((unsigned long)va_arg(args, unsigned int), 1));
	if (fmt[*i] == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%') + ft_putchar(fmt[*i]));
}
