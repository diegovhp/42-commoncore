#include "ft_printf.h"

static int	ptr_hex(uintptr_t n)
{
	const char	*base;
	int			count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ptr_hex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(uintptr_t n)
{
	if (!n)
		return (ft_putchar('(') + ft_putchar('n') + ft_putchar('i')
			+ ft_putchar('l') + ft_putchar(')'));
	return (ft_putchar('0') + ft_putchar('x') + ptr_hex(n));
}
