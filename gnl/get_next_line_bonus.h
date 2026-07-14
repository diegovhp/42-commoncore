/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* get_next_line_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegovhp <diegovhp@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/02 17:00:00 by diegovhp        #+#    #+#               */
/*   Updated: 2026/05/02 17:00:00 by diegovhp       ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1024

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_extract_line(char *leftover);
char	*ft_update_leftover(char *leftover);

#endif
