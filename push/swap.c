/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 13:58:25 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/20 13:58:25 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, t_bench *benchmark)
{
	int	tmp;

	if (!data || data->a->size < 2)
		return ;
	tmp = data->a->top->value;
	data->a->top->value = data->a->top->next->value;
	data->a->top->next->value = tmp;
	tmp = data->a->top->index;
	data->a->top->index = data->a->top->next->index;
	data->a->top->next->index = tmp;
	benchmark->sa++;
	benchmark->total_ops++;
	write(1, "sa\n", 3);
}

void	sb(t_data *data, t_bench *benchmark)
{
	int	tmp;

	if (!data || data->b->size < 2)
		return ;
	tmp = data->b->top->value;
	data->b->top->value = data->b->top->next->value;
	data->b->top->next->value = tmp;
	tmp = data->b->top->index;
	data->b->top->index = data->b->top->next->index;
	data->b->top->next->index = tmp;
	benchmark->sb++;
	benchmark->total_ops++;
	write(1, "sb\n", 3);
}

static void	swap_top(t_stack *stack)
{
	int	tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
	tmp = stack->top->index;
	stack->top->index = stack->top->next->index;
	stack->top->next->index = tmp;
}

void	ss(t_data *data, t_bench *benchmark)
{
	if (!data)
		return ;
	swap_top(data->a);
	swap_top(data->b);
	benchmark->ss++;
	benchmark->total_ops++;
	write(1, "ss\n", 3);
}
