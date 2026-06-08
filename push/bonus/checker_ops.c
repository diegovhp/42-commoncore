/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 00:00:00 by divan-he          #+#    #+#             */
/*   Updated: 2026/06/08 00:00:00 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_top(t_stack *s)
{
	int	tmp_v;
	int	tmp_i;

	if (s->size < 2)
		return ;
	tmp_v = s->top->value;
	tmp_i = s->top->index;
	s->top->value = s->top->next->value;
	s->top->index = s->top->next->index;
	s->top->next->value = tmp_v;
	s->top->next->index = tmp_i;
}

static void	push_to(t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (!src->top)
		return ;
	node = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	src->size--;
	node->next = dst->top;
	node->prev = NULL;
	if (dst->top)
		dst->top->prev = node;
	dst->top = node;
	dst->size++;
}

static void	rotate_fwd(t_stack *s)
{
	t_node	*node;

	if (s->size < 2)
		return ;
	node = s->top;
	s->top = node->next;
	s->top->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	s->size--;
	ft_stack_add_bottom(s, node);
}

static t_node	*get_bottom(t_stack *s)
{
	t_node	*node;

	node = s->top;
	while (node->next)
		node = node->next;
	return (node);
}

static void	rotate_bwd(t_stack *s)
{
	t_node	*bottom;

	if (s->size < 2)
		return ;
	bottom = get_bottom(s);
	bottom->prev->next = NULL;
	bottom->prev = NULL;
	bottom->next = s->top;
	s->top->prev = bottom;
	s->top = bottom;
}

static int	apply_swaps(t_data *d, char *op)
{
	if (!ft_strcmp(op, "sa"))
	{
		swap_top(d->a);
		return (1);
	}
	if (!ft_strcmp(op, "sb"))
	{
		swap_top(d->b);
		return (1);
	}
	if (!ft_strcmp(op, "ss"))
	{
		swap_top(d->a);
		swap_top(d->b);
		return (1);
	}
	return (0);
}

static int	apply_pushes(t_data *d, char *op)
{
	if (!ft_strcmp(op, "pa"))
	{
		push_to(d->b, d->a);
		return (1);
	}
	if (!ft_strcmp(op, "pb"))
	{
		push_to(d->a, d->b);
		return (1);
	}
	return (0);
}

static int	apply_fwd(t_data *d, char *op)
{
	if (!ft_strcmp(op, "ra"))
	{
		rotate_fwd(d->a);
		return (1);
	}
	if (!ft_strcmp(op, "rb"))
	{
		rotate_fwd(d->b);
		return (1);
	}
	if (!ft_strcmp(op, "rr"))
	{
		rotate_fwd(d->a);
		rotate_fwd(d->b);
		return (1);
	}
	return (0);
}

static int	apply_bwd(t_data *d, char *op)
{
	if (!ft_strcmp(op, "rra"))
	{
		rotate_bwd(d->a);
		return (1);
	}
	if (!ft_strcmp(op, "rrb"))
	{
		rotate_bwd(d->b);
		return (1);
	}
	if (!ft_strcmp(op, "rrr"))
	{
		rotate_bwd(d->a);
		rotate_bwd(d->b);
		return (1);
	}
	return (0);
}

int	apply_op(t_data *d, char *op)
{
	if (*op == '\0')
		return (1);
	if (apply_swaps(d, op))
		return (1);
	if (apply_pushes(d, op))
		return (1);
	if (apply_fwd(d, op))
		return (1);
	return (apply_bwd(d, op));
}
