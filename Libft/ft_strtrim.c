/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:36:01 by divan-he          #+#    #+#             */
/*   Updated: 2026/05/05 18:36:08 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;
	size_t	set_len;

	i = 0;
	set_len = ft_strlen(set);
	while (i < set_len)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	max;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	max = ft_strlen(s1);
	while (is_in_set(s1[i], set))
		i++;
	while (max > i && is_in_set(s1[max - 1], set))
		max--;
	res = ft_calloc(max - i + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + i, max - i + 1);
	return (res);
}
