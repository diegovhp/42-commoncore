/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:00:00 by divan-he          #+#    #+#             */
/*   Updated: 2026/06/07 00:00:00 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_data *data)
{
	t_node	*node;

	if (!data->a->top)
		return (1);
	node = data->a->top;
	while (node->next)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}

static void	dispatch_algo(t_data *data, t_bench *bench, int n)
{
	if (bench->flag == 's')
		sort_simple(data, bench);
	else if (bench->flag == 'm')
		sort_medium(data, bench);
	else
		sort_complex(data, bench, n);
}

void	push_swap_sort(t_data *data, t_bench *bench)
{
	int	n;

	n = data->a->size;
	if (n <= 1 || is_sorted(data))
		return ;
	if (n == 2)
		sort_two(data, bench);
	else if (n == 3)
		sort_three(data, bench);
	else if (n <= 5 && bench->flag != 'c')
		sort_five(data, bench);
	else
		dispatch_algo(data, bench, n);
}
