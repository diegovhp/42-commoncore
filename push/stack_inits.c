/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 21:23:45 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/17 21:23:45 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*ft_new_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_data	*ft_new_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = ft_new_stack();
	data->b = ft_new_stack();
	if (!data->a || !data->b)
	{
		free(data->a);
		free(data->b);
		free(data);
		return (NULL);
	}
	return (data);
}

void	ft_stack_add_bottom(t_stack *stack, t_node *node)
{
	t_node	*tmp_lst;

	if (!stack->top)
	{
		stack->top = node;
		stack->size++;
		return ;
	}
	tmp_lst = stack->top;
	while (tmp_lst->next)
		tmp_lst = tmp_lst->next;
	node->next = NULL;
	node->prev = tmp_lst;
	tmp_lst->next = node;
	stack->size++;
}
