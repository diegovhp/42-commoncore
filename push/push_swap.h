/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 21:23:31 by nwatelle          #+#    #+#             */
/*   Updated: 2026/05/17 21:23:31 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}	t_stack;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
}	t_data;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		disorder;
	char	flag;
	char	flag_origin;
	int		total_ops;
	int		bench_mode;
}	t_bench;

typedef struct s_rot
{
	int	a;
	int	b;
	int	cost;
}	t_rot;

/*    Init    */
t_node		*ft_new_node(int value);
t_stack		*ft_new_stack(void);
t_data		*ft_new_data(void);
void		ft_stack_add_bottom(t_stack *stack, t_node *node);

/*    utils    */
int			ft_isdigit(char c);
void		value_to_index(t_data *data);
int			ft_strcmp(char *s1, char *s2);
void		put_nbr(int n);
void		put_str(char *str);

/*    Parser     */
void		ft_parse(t_data *data, int ac, char **av);
void		ft_parse_str(t_data *data, char *str);
int			ft_is_valid_number(char *str);
int			ft_is_same(t_stack *stack, int value);
int			ft_free_atoi(char *str, t_data *data);
int			parser_argsvide(int ac, char **av);
char		parse_flag(int ac, char **av);
int			parse_bench(int ac, char **av);
void		sort_adaptive(t_bench *benchmark);

/*      Memory free     */
void		ft_error(t_data *data);
void		ft_free_data(t_data *data);
void		ft_free_stack(t_stack *stack);

/*      mouvement             */
void		sa(t_data *data, t_bench *benchmark);
void		sb(t_data *data, t_bench *benchmark);
void		ss(t_data *data, t_bench *benchmark);
void		pb(t_data *data, t_bench *benchmark);
void		pa(t_data *data, t_bench *benchmark);
void		rrb(t_data *data, t_bench *benchmark);
void		rra(t_data *data, t_bench *benchmark);
void		ra(t_data *data, t_bench *benchmark);
void		rb(t_data *data, t_bench *benchmark);
void		rr(t_data *data, t_bench *benchmark);
void		rrr(t_data *data, t_bench *benchmark);

/*     benchmark       */
int			compute_disorder(t_stack *a);
void		print_disorder(t_bench benchmark);
void		print_benchmark(t_bench benchmark);

/*       algo         */
void		push_swap_sort(t_data *data, t_bench *bench);
int			is_sorted(t_data *data);
void		sort_two(t_data *data, t_bench *bench);
void		sort_three(t_data *data, t_bench *bench);
void		sort_five(t_data *data, t_bench *bench);
void		sort_simple(t_data *data, t_bench *bench);
void		sort_medium(t_data *data, t_bench *bench);
void		sort_complex(t_data *data, t_bench *bench, int n);
void		pull_greedy(t_data *data, t_bench *bench);
int			pos_of_min(t_stack *a);
int			find_target_a(t_stack *a, int idx);
t_rot		calc_rot(int pa, int sa, int pb, int sb);

#endif
