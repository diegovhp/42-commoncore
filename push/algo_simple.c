/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:00:00 by divan-he          #+#    #+#             */
/*   Updated: 2026/06/07 00:00:00 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all(t_data *data, t_bench *bench)
{
	while (data->a->size > 3)
		pb(data, bench);
}

static void	rotate_a_to(t_data *data, t_bench *bench, int pos)
{
	if (pos <= data->a->size / 2)
	{
		while (pos-- > 0)
			ra(data, bench);
	}
	else
	{
		pos = data->a->size - pos;
		while (pos-- > 0)
			rra(data, bench);
	}
}

static void	pull_top_only(t_data *data, t_bench *bench)
{
	int	target;

	while (data->b->size > 0)
	{
		target = find_target_a(data->a, data->b->top->index);
		rotate_a_to(data, bench, target);
		pa(data, bench);
	}
}

void	sort_simple(t_data *data, t_bench *bench)
{
	int	min_pos;

	push_all(data, bench);
	sort_three(data, bench);
	pull_top_only(data, bench);
	min_pos = pos_of_min(data->a);
	if (min_pos <= data->a->size / 2)
	{
		while (data->a->top->index != 0)
			ra(data, bench);
	}
	else
	{
		while (data->a->top->index != 0)
			rra(data, bench);
	}
}
