/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:05:23 by divan-he          #+#    #+#             */
/*   Updated: 2026/06/07 05:27:56 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	pos_of_min(t_stack *a)
{
	t_node	*node;
	int		pos;
	int		min_pos;
	int		min_idx;

	node = a->top;
	pos = 0;
	min_pos = 0;
	min_idx = INT_MAX;
	while (node)
	{
		if (node->index < min_idx)
		{
			min_idx = node->index;
			min_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (min_pos);
}

int	find_target_a(t_stack *a, int idx)
{
	t_node	*node;
	int		pos;
	int		best_pos;
	int		best_idx;

	node = a->top;
	pos = 0;
	best_pos = 0;
	best_idx = INT_MAX;
	while (node)
	{
		if (node->index > idx && node->index < best_idx)
		{
			best_idx = node->index;
			best_pos = pos;
		}
		node = node->next;
		pos++;
	}
	if (best_idx != INT_MAX)
		return (best_pos);
	return (pos_of_min(a));
}

static t_rot	set_rot(int a, int b, int cost)
{
	t_rot	r;

	r.a = a;
	r.b = b;
	r.cost = cost;
	return (r);
}

t_rot	calc_rot(int pa, int sa, int pb, int sb)
{
	t_rot	rot;
	int		cost;

	rot = set_rot(pa, pb, ft_max(pa, pb));
	cost = ft_max(sa - pa, sb - pb);
	if (cost < rot.cost)
		rot = set_rot(pa - sa, pb - sb, cost);
	cost = pa + sb - pb;
	if (cost < rot.cost)
		rot = set_rot(pa, pb - sb, cost);
	cost = sa - pa + pb;
	if (cost < rot.cost)
		rot = set_rot(pa - sa, pb, cost);
	return (rot);
}
