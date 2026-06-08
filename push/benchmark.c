/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:27:41 by nwatelle          #+#    #+#             */
/*   Updated: 2026/06/02 00:42:55 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_stack *a)
{
	t_node	*node_i;
	t_node	*node_j;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	node_i = a->top;
	while (node_i)
	{
		node_j = node_i->next;
		while (node_j)
		{
			total_pairs++;
			if (node_i->index > node_j->index)
				mistakes++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes * 10000 / total_pairs);
}

void	print_benchmark(t_bench benchmark)
{
	put_str("[bench] Total ops : ");
	put_nbr(benchmark.total_ops);
	put_str("\n[bench] sa:");
	put_nbr(benchmark.sa);
	put_str(" sb:");
	put_nbr(benchmark.sb);
	put_str(" ss:");
	put_nbr(benchmark.ss);
	put_str(" pa:");
	put_nbr(benchmark.pa);
	put_str(" pb:");
	put_nbr(benchmark.pb);
	put_str("\n[bench] ra:");
	put_nbr(benchmark.ra);
	put_str(" rb:");
	put_nbr(benchmark.rb);
	put_str(" rr:");
	put_nbr(benchmark.rr);
	put_str(" rra:");
	put_nbr(benchmark.rra);
	put_str(" rrb:");
	put_nbr(benchmark.rrb);
	put_str(" rrr:");
	put_nbr(benchmark.rrr);
	write(2, "\n", 1);
}

void	print_strategy(t_bench benchmark)
{
	if (benchmark.flag_origin == 'a')
		put_str("Adaptive / ");
	else if (benchmark.flag == 's')
		put_str("Simple / ");
	else if (benchmark.flag == 'm')
		put_str("Medium / ");
	else
		put_str("Complex / ");
	if (benchmark.flag == 's')
		put_str("O(n^2)\n");
	else if (benchmark.flag == 'm')
		put_str("O(n*sqrt(n))\n");
	else
		put_str("O(n log n)\n");
}

void	print_disorder(t_bench benchmark)
{
	int	pct;

	pct = benchmark.disorder;
	put_str("[bench] disorder: ");
	put_nbr(pct / 100);
	write(2, ".", 1);
	if (pct % 100 < 10)
		write(2, "0", 1);
	put_nbr(pct % 100);
	write(2, "%\n", 2);
	put_str("[bench] strategy: ");
	print_strategy(benchmark);
	print_benchmark(benchmark);
}
