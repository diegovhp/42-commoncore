/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:35:34 by divan-he          #+#    #+#             */
/*   Updated: 2026/05/05 20:41:18 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;

	target = (char)c;
	while (*s != '\0')
	{
		if (*s == target)
			return ((char *)s);
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int	main()
// {
// 	ft_strchr("Test", 4);
// 	strchr("Test", 4);
// }