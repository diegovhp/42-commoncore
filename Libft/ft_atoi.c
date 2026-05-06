/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:34:12 by divan-he          #+#    #+#             */
/*   Updated: 2026/05/05 19:29:06 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_sign(const char *str, int *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			(*i)++;
			return (-1);
		}
		(*i)++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	res = 0;
	sign = parse_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (LLONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// char *str = " -1239flj409";
// char *str1 = " +123721nbv119";
// char *str2 = " +-783f1";
// char *str3 = " --2132334fk";
// char *str4 = " -9223372036854775807";
// char *str5 = " +4294967295";

// printf("String: \"%s\" --> %d\n", str, ft_atoi(str));
// printf("StringA: \"%s\" --> %d\n", str, atoi(str));
// printf("String: \"%s\" --> %d\n", str1, ft_atoi(str1));
// printf("StringA: \"%s\" --> %d\n", str1, atoi(str1));
// printf("String: \"%s\" --> %d\n", str2, ft_atoi(str2));
// printf("StringA: \"%s\" --> %d\n", str2, atoi(str2));
// printf("String: \"%s\" --> %d\n", str3, ft_atoi(str3));
// printf("StringA: \"%s\" --> %d\n", str3, atoi(str3));
// printf("String: \"%s\" --> %d\n", str4, ft_atoi(str4));
// printf("StringA: \"%s\" --> %d\n", str4, atoi(str4));
// printf("String: \"%s\" --> %d\n", str5, ft_atoi(str5));
// printf("StringA: \"%s\" --> %d\n", str5, atoi(str5));
// return (0);
// }