/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 03:39:01 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/26 03:39:01 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parser_argsvide(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while (av[i][j])
			j++;
		i++;
	}
	return (1);
}

static int	ft_is_known_flag(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	if (ft_strcmp(str, "--medium") == 0)
		return (1);
	if (ft_strcmp(str, "--complex") == 0)
		return (1);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(str, "--bench") == 0)
		return (1);
	if (ft_strcmp(str, "--ops") == 0)
		return (1);
	return (0);
}

char	parse_flag(int ac, char **av)
{
	char	flag;
	int		i;

	flag = 'a';
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-' && !ft_is_known_flag(av[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (ft_strcmp(av[i], "--simple") == 0)
			flag = 's';
		else if (ft_strcmp(av[i], "--medium") == 0)
			flag = 'm';
		else if (ft_strcmp(av[i], "--complex") == 0)
			flag = 'c';
		else if (ft_strcmp(av[i], "--adaptive") == 0)
			flag = 'a';
		i++;
	}
	return (flag);
}

int	parse_bench(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--bench") == 0)
			return (1);
		i++;
	}
	return (0);
}

void	sort_adaptive(t_bench *benchmark)
{
	if (benchmark->disorder < 2000)
		benchmark->flag = 's';
	else if (benchmark->disorder < 5000)
		benchmark->flag = 'm';
	else
		benchmark->flag = 'c';
}
