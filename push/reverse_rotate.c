/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:00:11 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/20 14:00:11 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data, t_bench *benchmark)
{
	t_node	*last;
	t_node	*second_last;

	if (!data || !data->a || !data->a->top || !data->a->top->next)
		return ;
	last = data->a->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = data->a->top;
	data->a->top->prev = last;
	data->a->top = last;
	benchmark->rra++;
	benchmark->total_ops++;
	write(1, "rra\n", 4);
}

void	rrb(t_data *data, t_bench *benchmark)
{
	t_node	*last;
	t_node	*second_last;

	if (!data || !data->b || !data->b->top || !data->b->top->next)
		return ;
	last = data->b->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = data->b->top;
	data->b->top->prev = last;
	data->b->top = last;
	benchmark->rrb++;
	benchmark->total_ops++;
	write(1, "rrb\n", 4);
}

static void	rev_rotate_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void	rrr(t_data *data, t_bench *benchmark)
{
	if (!data)
		return ;
	rev_rotate_stack(data->a);
	rev_rotate_stack(data->b);
	benchmark->rrr++;
	benchmark->total_ops++;
	write(1, "rrr\n", 4);
}
