/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:35:31 by divan-he          #+#    #+#             */
/*   Updated: 2026/05/05 18:35:49 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static char	*ft_extract_word(const char *str, char c)
{
	char	*result;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, i + 1);
	return (result);
}

static void	ft_free_tab(char **tab)
{
	char	**pos;

	if (!tab)
		return ;
	pos = tab;
	while (*pos != NULL)
		free(*(pos++));
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		strs_len;

	if (!s)
		return (NULL);
	strs_len = ft_word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (strs_len + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < strs_len)
	{
		while (*s && *s == c)
			s++;
		result[i] = ft_extract_word(s, c);
		if (!result[i])
		{
			ft_free_tab(result);
			return (NULL);
		}
		s += ft_strlen(result[i]);
	}
	result[i] = 0;
	return (result);
}
