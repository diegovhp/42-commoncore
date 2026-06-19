CC		= cc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= libftprintf.a

SRCS		= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
			  ft_puthex.c ft_putptr.c ft_format.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
