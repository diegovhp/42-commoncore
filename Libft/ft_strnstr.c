/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:35:55 by divan-he          #+#    #+#             */
/*   Updated: 2026/05/06 17:03:18 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	i = 0;
	if (!haystack && len)
		return ((char *)(size_t)haystack[0]);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (len < needle_len)
		return (NULL);
	while (haystack[i] && i <= len - needle_len)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
