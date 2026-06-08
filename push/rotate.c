/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 13:58:40 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/20 13:58:40 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data, t_bench *benchmark)
{
	t_node	*top;

	if (!data || !data->a || !data->a->top)
		return ;
	top = data->a->top;
	data->a->top = top->next;
	data->a->size--;
	ft_stack_add_bottom(data->a, top);
	benchmark->ra++;
	benchmark->total_ops++;
	write(1, "ra\n", 3);
}

void	rb(t_data *data, t_bench *benchmark)
{
	t_node	*top;

	if (!data || !data->b || !data->b->top)
		return ;
	top = data->b->top;
	data->b->top = top->next;
	data->b->size--;
	ft_stack_add_bottom(data->b, top);
	benchmark->rb++;
	benchmark->total_ops++;
	write(1, "rb\n", 3);
}

static void	rotate_stack(t_stack *stack)
{
	t_node	*top;

	if (!stack || !stack->top)
		return ;
	top = stack->top;
	stack->top = top->next;
	stack->size--;
	ft_stack_add_bottom(stack, top);
}

void	rr(t_data *data, t_bench *benchmark)
{
	if (!data)
		return ;
	rotate_stack(data->a);
	rotate_stack(data->b);
	benchmark->rr++;
	benchmark->total_ops++;
	write(1, "rr\n", 3);
}
