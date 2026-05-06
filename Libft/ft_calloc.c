/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divan-he <divan-he@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:34:19 by divan-he          #+#    #+#             */
/*   Updated: 2026/05/05 18:35:23 by divan-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	totalsz;
	void	*ptr;

	totalsz = count * size;
	if (count != 0 && totalsz / count != size)
		return (NULL);
	ptr = (void *)malloc(totalsz);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, totalsz);
	return (ptr);
}
