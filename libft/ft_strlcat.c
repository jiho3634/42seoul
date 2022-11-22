/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:36:05 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/16 17:41:17 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	dest_size = 0;
	while (dst[dest_size])
		dest_size++;
	src_size = 0;
	while (src[src_size])
		src_size++;
	i = 0;
	if (dest_size > dstsize)
		return (dstsize + src_size);
	else if (dest_size <= dstsize)
	{
		while ((dest_size + i < dstsize - 1) && src[i])
		{
			dst[dest_size + i] = src[i];
			i++;
		}
		dst[dest_size + i] = '\0';
		return (dest_size + src_size);
	}
	return (0);
}
