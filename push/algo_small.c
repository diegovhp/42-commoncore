/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:11:08 by divan-he          #+#    #+#             */
/*   Updated: 2026/06/07 05:27:42 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data, t_bench *bench)
{
	if (data->a->top->index > data->a->top->next->index)
		sa(data, bench);
}

static void	sort_three_end(t_data *data, t_bench *bench, int a, int c)
{
	if (a < c)
	{
		rra(data, bench);
		sa(data, bench);
	}
	else
	{
		sa(data, bench);
		rra(data, bench);
	}
}

void	sort_three(t_data *data, t_bench *bench)
{
	int	a;
	int	b;
	int	c;

	a = data->a->top->index;
	b = data->a->top->next->index;
	c = data->a->top->next->next->index;
	if (a < b && b < c)
		return ;
	if (b < a && a < c)
		sa(data, bench);
	else if (c < a && a < b)
		rra(data, bench);
	else if (b < c && c < a)
		ra(data, bench);
	else
		sort_three_end(data, bench, a, c);
}

static void	push_two_smallest(t_data *data, t_bench *bench)
{
	while (data->b->size < 2)
	{
		if (data->a->top->index <= 1)
			pb(data, bench);
		else
			ra(data, bench);
	}
	if (data->b->top->index < data->b->top->next->index)
		sb(data, bench);
}

void	sort_five(t_data *data, t_bench *bench)
{
	if (data->a->size == 4)
	{
		while (data->a->top->index != 0)
			ra(data, bench);
		pb(data, bench);
		sort_three(data, bench);
		pa(data, bench);
		return ;
	}
	push_two_smallest(data, bench);
	sort_three(data, bench);
	pa(data, bench);
	pa(data, bench);
}
