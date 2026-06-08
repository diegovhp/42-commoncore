/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 00:00:00 by nwatelle          #+#    #+#             */
/*   Updated: 2026/06/08 00:00:00 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_ws(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static void	ft_get_token(t_data *data, char *str, int *i, char *tok)
{
	int	j;

	j = 0;
	while (str[*i] && !ft_is_ws(str[*i]))
	{
		if (j >= 11)
			ft_error(data);
		tok[j] = str[*i];
		j++;
		(*i)++;
	}
	tok[j] = '\0';
}

static void	ft_push_value(t_data *data, char *token)
{
	int		value;
	t_node	*node;

	if (!ft_is_valid_number(token))
		ft_error(data);
	value = ft_free_atoi(token, data);
	if (ft_is_same(data->a, value))
		ft_error(data);
	node = ft_new_node(value);
	if (!node)
		ft_error(data);
	ft_stack_add_bottom(data->a, node);
}

void	ft_parse_str(t_data *data, char *str)
{
	char	token[12];
	int		i;

	i = 0;
	while (str[i])
	{
		while (ft_is_ws(str[i]))
			i++;
		if (!str[i])
			break ;
		ft_get_token(data, str, &i, token);
		ft_push_value(data, token);
	}
}
