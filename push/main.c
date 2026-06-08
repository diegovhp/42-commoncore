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

int	main(int ac, char **av)
{
	t_data	*data;
	t_bench	benchmark;

	benchmark = (t_bench){0};
	benchmark.flag = parse_flag(ac, av);
	benchmark.flag_origin = benchmark.flag;
	benchmark.bench_mode = parse_bench(ac, av);
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
	ft_free_data(data);
	return (0);
}
