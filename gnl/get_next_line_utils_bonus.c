/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* get_next_line_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegovhp <diegovhp@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/02 17:00:00 by diegovhp        #+#    #+#               */
/*   Updated: 2026/05/02 17:00:00 by diegovhp       ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < len1 + len2)
	{
		if (i < len1)
			result[i] = s1[i];
		else
			result[i] = s2[i - len1];
		i++;
	}
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*ft_extract_line(char *leftover)
{
	char	*line;
	size_t	len;
	size_t	i;

	if (!leftover || !leftover[0])
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		len = i + 1;
	else
		len = i;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = leftover[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

char	*ft_update_leftover(char *leftover)
{
	char	*newline;
	char	*new_leftover;

	if (!leftover)
		return (NULL);
	newline = ft_strchr(leftover, '\n');
	if (!newline)
	{
		free(leftover);
		return (NULL);
	}
	new_leftover = ft_strjoin(NULL, newline + 1);
	free(leftover);
	return (new_leftover);
}
