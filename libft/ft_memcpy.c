/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:27:33 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/01 20:02:02 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (!dst && !src)
		return (0);
	dst2 = (unsigned char *) dst;
	src2 = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
