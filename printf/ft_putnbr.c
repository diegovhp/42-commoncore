#include "ft_printf.h"

static int	putnbr_base(unsigned long n, int len)
{
	int	count;

	count = 0;
	if (len == 0)
		return (0);
	if (len > 1)
		count += putnbr_base(n / 10, len - 1);
	count += ft_putchar((char)(n % 10 + '0'));
	return (count);
}

int	ft_putnbr(long n)
{
	unsigned long	abs_n;
	int				count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		abs_n = (unsigned long)(-n);
	}
	else
		abs_n = (unsigned long)n;
	return (count + putnbr_base(abs_n, ft_numlen(abs_n, 10)));
}

int	ft_putunbr(unsigned long n)
{
	return (putnbr_base(n, ft_numlen(n, 10)));
}
