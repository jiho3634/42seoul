/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:18:12 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/25 11:55:46 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memset(void *b, int c, unsigned long len)
{
	unsigned char	*b2;
	unsigned char	c2;
	unsigned long	i;

	b2 = (unsigned char *) b;
	c2 = (unsigned char) c;
	i = -1;
	while (++i < len)
		*(b2 + i) = c2;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;	

	ptr = malloc (count * size);
	if (ptr == 0)
		return (0);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
