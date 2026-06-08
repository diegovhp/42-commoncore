/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:04:15 by divan-he          #+#    #+#             */
/*   Updated: 2026/06/07 05:44:59 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_rot	find_best(t_data *data)
{
	t_node	*node;
	t_rot	best;
	t_rot	cur;
	int		pos;

	node = data->b->top;
	pos = 0;
	best.cost = INT_MAX;
	while (node)
	{
		cur = calc_rot(
				find_target_a(data->a, node->index),
				data->a->size, pos, data->b->size);
		if (cur.cost < best.cost)
			best = cur;
		node = node->next;
		pos++;
	}
	return (best);
}

static void	apply_rot_a(t_data *data, t_bench *bench, int cnt)
{
	while (cnt > 0)
	{
		ra(data, bench);
		cnt--;
	}
	while (cnt < 0)
	{
		rra(data, bench);
		cnt++;
	}
}

static void	apply_rot_b(t_data *data, t_bench *bench, int cnt)
{
	while (cnt > 0)
	{
		rb(data, bench);
		cnt--;
	}
	while (cnt < 0)
	{
		rrb(data, bench);
		cnt++;
	}
}

static void	apply_rot(t_data *data, t_bench *bench, t_rot rot)
{
	while (rot.a > 0 && rot.b > 0)
	{
		rr(data, bench);
		rot.a--;
		rot.b--;
	}
	while (rot.a < 0 && rot.b < 0)
	{
		rrr(data, bench);
		rot.a++;
		rot.b++;
	}
	apply_rot_a(data, bench, rot.a);
	apply_rot_b(data, bench, rot.b);
}

void	pull_greedy(t_data *data, t_bench *bench)
{
	t_rot	best;

	while (data->b->size > 0)
	{
		best = find_best(data);
		apply_rot(data, bench, best);
		pa(data, bench);
	}
}
