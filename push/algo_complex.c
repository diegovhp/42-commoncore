/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:00:00 by divan-he          #+#    #+#             */
/*   Updated: 2026/06/07 00:00:00 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_sz(int n)
{
	if (n <= 100)
		return (43);
	return (215);
}

static void	push_chunks(t_data *data, t_bench *bench, int n)
{
	int	chunk;
	int	limit;

	chunk = chunk_sz(n);
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

static void	rotate_to_min(t_data *data, t_bench *bench)
{
	int	min_pos;

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

void	sort_complex(t_data *data, t_bench *bench, int n)
{
	push_chunks(data, bench, n);
	sort_three(data, bench);
	pull_greedy(data, bench);
	rotate_to_min(data, bench);
}
