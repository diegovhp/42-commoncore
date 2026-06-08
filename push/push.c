/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:00:22 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/20 14:00:22 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data, t_bench *benchmark)
{
	t_node	*node;

	if (!data || !data->b || !data->b->top)
		return ;
	node = data->b->top;
	data->b->top = node->next;
	if (data->b->top)
		data->b->top->prev = NULL;
	data->b->size--;
	node->next = data->a->top;
	node->prev = NULL;
	if (data->a->top)
		data->a->top->prev = node;
	data->a->top = node;
	data->a->size++;
	benchmark->pa++;
	benchmark->total_ops++;
	write(1, "pa\n", 3);
}

void	pb(t_data *data, t_bench *benchmark)
{
	t_node	*node;

	if (!data || !data->a || !data->a->top)
		return ;
	node = data->a->top;
	data->a->top = node->next;
	if (data->a->top)
		data->a->top->prev = NULL;
	data->a->size--;
	node->next = data->b->top;
	node->prev = NULL;
	if (data->b->top)
		data->b->top->prev = node;
	data->b->top = node;
	data->b->size++;
	benchmark->pb++;
	benchmark->total_ops++;
	write(1, "pb\n", 3);
}
