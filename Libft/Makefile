# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/05 17:36:13 by divan-he          #+#    #+#              #
#    Updated: 2026/05/05 18:34:59 by divan-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c \
					ft_itoa.c ft_strrchr.c ft_strlcat.c ft_strncmp.c \
					ft_atoi.c ft_isalpha.c ft_split.c ft_strnstr.c \
					ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_putendl_fd.c \
					ft_striteri.c ft_tolower.c ft_bzero.c ft_isascii.c \
					ft_putnbr_fd.c ft_strjoin.c ft_strtrim.c ft_memmove.c \
					ft_strdup.c ft_strlen.c ft_putstr_fd.c ft_strmapi.c \
					ft_substr.c ft_toupper.c ft_calloc.c ft_isdigit.c \
					ft_memchr.c ft_memset.c ft_lstnew.c ft_lstadd_front.c \
					ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS			= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus