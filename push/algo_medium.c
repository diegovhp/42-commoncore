/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:00:00 by divan-he          #+#    #+#             */
/*   Updated: 2026/06/07 00:00:00 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size_med(int n)
{
	int	sz;

	sz = 1;
	while (sz * sz < n)
		sz++;
	return (sz);
}

static void	push_waves(t_data *data, t_bench *bench, int n)
{
	int	chunk;
	int	limit;

	chunk = chunk_size_med(n);
	limit = chunk;
	while (data->a->size > 3)
	{
		if (data->a->top->index < limit)
		{
			pb(data, bench);
			if (data->b->size > 1
				&& data->b->top->index < data->b->top->next->index)
				rb(data, bench);
			if (data->b->size >= limit)
				limit += chunk;
		}
		else
			ra(data, bench);
	}
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

static void	rotate_b_to(t_data *data, t_bench *bench, int pos)
{
	if (pos <= data->b->size / 2)
	{
		while (pos-- > 0)
			rb(data, bench);
	}
	else
	{
		pos = data->b->size - pos;
		while (pos-- > 0)
			rrb(data, bench);
	}
}

static int	a_rot_cost(t_stack *a, int idx)
{
	int	target;

	target = find_target_a(a, idx);
	if (target <= a->size / 2)
		return (target);
	return (a->size - target);
}

static int	best_b_for_a(t_data *data, int *out_a)
{
	t_node	*node;
	int		pos_b;
	int		best_b;
	int		best_cost;
	int		cost;

	node = data->b->top;
	pos_b = 0;
	best_b = 0;
	best_cost = data->a->size + 1;
	*out_a = 0;
	while (node)
	{
		cost = a_rot_cost(data->a, node->index);
		if (cost < best_cost)
		{
			best_cost = cost;
			best_b = pos_b;
			*out_a = find_target_a(data->a, node->index);
		}
		node = node->next;
		pos_b++;
	}
	return (best_b);
}

static void	pull_med(t_data *data, t_bench *bench)
{
	int	pos_b;
	int	target_a;

	while (data->b->size > 0)
	{
		pos_b = best_b_for_a(data, &target_a);
		rotate_b_to(data, bench, pos_b);
		rotate_a_to(data, bench, target_a);
		pa(data, bench);
	}
}

void	sort_medium(t_data *data, t_bench *bench)
{
	int	n;
	int	min_pos;

	n = data->a->size;
	push_waves(data, bench, n);
	sort_three(data, bench);
	pull_med(data, bench);
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
