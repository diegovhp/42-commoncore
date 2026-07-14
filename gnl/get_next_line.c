/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* get_next_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegovhp <diegovhp@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/02 17:00:00 by diegovhp        #+#    #+#               */
/*   Updated: 2026/05/02 17:00:00 by diegovhp       ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_loop(int fd, char *buf, char **leftover)
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(*leftover, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(*leftover);
			*leftover = NULL;
			return (-1);
		}
		buf[bytes_read] = '\0';
		*leftover = ft_strjoin(*leftover, buf);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (read_loop(fd, buf, &leftover) < 0)
	{
		free(buf);
		return (NULL);
	}
	free(buf);
	line = ft_extract_line(leftover);
	leftover = ft_update_leftover(leftover);
	return (line);
}
