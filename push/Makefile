# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/17 21:23:41 by nwatelle          #+#    #+#              #
#    Updated: 2026/06/07 06:01:17 by divan-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -f

SRCS		= stack_inits.c \
			utils.c \
			parse_flag.c \
			parcers.c \
			parse_str.c \
			swap.c \
			push.c \
			rotate.c \
			reverse_rotate.c \
			free.c \
			benchmark.c \
			main.c \
			algo_small.c \
			algo_position.c \
			algo_greedy.c \
			algo_simple.c \
			algo_medium.c \
			algo_complex.c \
			algo_adaptive.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "push_swap compiled."

%.o:		%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		@echo "Object files removed."

fclean:		clean
		$(RM) $(NAME)
		@echo "push_swap removed."

re:		fclean all

.PHONY:		all clean fclean re
