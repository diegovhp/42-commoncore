/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 21:23:36 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/17 21:23:36 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_nbr(int n)
{
	char	res;

	if (n >= 10)
		put_nbr(n / 10);
	res = (n % 10) + '0';
	write(2, &res, 1);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	value_to_index(t_data *data)
{
	t_node	*current;
	t_node	*checker;
	int		index;

	current = data->a->top;
	while (current)
	{
		index = 0;
		checker = data->a->top;
		while (checker)
		{
			if (checker->value < current->value)
				index++;
			checker = checker->next;
		}
		current->index = index;
		current = current->next;
	}
}
