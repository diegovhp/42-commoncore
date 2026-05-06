/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:35:43 by divan-he          #+#    #+#             */
/*   Updated: 2026/05/05 21:32:43 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_l;
	size_t	src_l;
	size_t	a;
	size_t	b;

	dest_l = 0;
	src_l = 0;
	a = 0;
	b = 0;
	while (dest_l < size && dest[dest_l])
		dest_l++;
	while (src[src_l])
		src_l++;
	if (size == dest_l)
		return (size + src_l);
	a = dest_l;
	while (src[b] && a < size - 1)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest_l + src_l);
}
