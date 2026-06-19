#include "ft_printf.h"

static int	puthex_base(unsigned long n, const char *base, int len)
{
	int	count;

	count = 0;
	if (len == 0)
		return (0);
	if (len > 1)
		count += puthex_base(n / 16, base, len - 1);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_puthex(unsigned long n, int upper)
{
	const char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (puthex_base(n, base, ft_numlen(n, 16)));
}
