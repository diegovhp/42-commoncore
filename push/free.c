/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 21:27:02 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/17 21:27:02 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*next;

	if (!stack)
		return ;
	tmp = stack->top;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	ft_free_stack(data->a);
	ft_free_stack(data->b);
	free(data->a);
	free(data->b);
	free(data);
}

void	ft_error(t_data *data)
{
	ft_free_data(data);
	write(2, "Error\n", 6);
	exit(1);
}
