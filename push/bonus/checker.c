/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 00:00:00 by divan-he          #+#    #+#             */
/*   Updated: 2026/06/08 00:00:00 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	apply_op(t_data *d, char *op);

static int	check_sorted(t_stack *a)
{
	t_node	*node;

	if (!a->top)
		return (1);
	node = a->top;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

static char	*read_op(char *buf)
{
	int		i;
	char	c;
	int		ret;

	i = 0;
	while ((ret = read(0, &c, 1)) == 1)
	{
		if (c == '\n')
			break ;
		if (i < 7)
			buf[i++] = c;
	}
	if (i == 0 && ret <= 0)
		return (NULL);
	buf[i] = '\0';
	return (buf);
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	buf[8];

	if (ac < 2)
		return (0);
	data = ft_new_data();
	ft_parse(data, ac, av);
	while (read_op(buf))
	{
		if (!apply_op(data, buf))
			ft_error(data);
	}
	if (check_sorted(data->a) && data->b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_data(data);
	return (0);
}
