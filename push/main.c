/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 21:22:55 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/17 21:22:55 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ops(t_bench benchmark)
{
	put_nbr(benchmark.total_ops);
	write(2, "\n", 1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_bench	benchmark;

	benchmark = (t_bench){0};
	benchmark.flag = parse_flag(ac, av);
	benchmark.flag_origin = benchmark.flag;
	benchmark.bench_mode = parse_bench(ac, av);
	benchmark.ops_mode = parse_ops(ac, av);
	if (ac < 2)
		return (0);
	data = ft_new_data();
	ft_parse(data, ac, av);
	value_to_index(data);
	benchmark.disorder = compute_disorder(data->a);
	if (benchmark.flag == 'a')
		sort_adaptive(&benchmark);
	push_swap_sort(data, &benchmark);
	if (benchmark.bench_mode)
		print_disorder(benchmark);
	if (benchmark.ops_mode)
		print_ops(benchmark);
	ft_free_data(data);
	return (0);
}
