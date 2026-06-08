/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 21:23:16 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/17 21:23:16 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_free_atoi(char *str, t_data *data)
{
	long	res;
	int		sign;
	int		i;

	if (!str)
		return (ft_error(data), 0);
	i = 0;
	sign = parse_sign(str, &i);
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		if (res > 2147483648L)
			ft_error(data);
		i++;
	}
	if (sign == 1 && res > (long)INT_MAX)
		ft_error(data);
	return ((int)(sign * res));
}

int	ft_is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_same(t_stack *stack, int value)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}


void	ft_parse(t_data *data, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			continue ;
		}
		ft_parse_str(data, av[i]);
		i++;
	}
}
