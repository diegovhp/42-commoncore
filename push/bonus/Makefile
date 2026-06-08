# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/08 00:00:00 by divan-he          #+#    #+#              #
#    Updated: 2026/06/08 00:00:00 by divan-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -I..
RM		= rm -f
PARENT		= ..

BONUS_SRCS	= checker.c \
			checker_ops.c

PARENT_SRCS	= stack_inits.c \
			utils.c \
			parcers.c \
			free.c

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
PARENT_OBJS	= $(PARENT_SRCS:.c=.o)
ALL_OBJS	= $(BONUS_OBJS) $(PARENT_OBJS)

all:		$(NAME)

$(NAME):	$(ALL_OBJS)
		$(CC) $(CFLAGS) $(ALL_OBJS) -o $(NAME)
		@echo "checker compiled."

$(PARENT_OBJS): %.o: $(PARENT)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

%.o:		%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(ALL_OBJS)
		@echo "Object files removed."

fclean:		clean
		$(RM) $(NAME)
		@echo "checker removed."

re:		fclean all

.PHONY:		all clean fclean re
