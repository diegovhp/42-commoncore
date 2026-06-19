#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;
	int	i;

	if (!str)
		str = "(null)";
	count = 0;
	i = 0;
	while (str[i])
		count += ft_putchar(str[i++]);
	return (count);
}
