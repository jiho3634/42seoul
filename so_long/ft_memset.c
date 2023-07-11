/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:59:24 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/25 11:55:28 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b2;
	unsigned char	c2;
	size_t			i;

	b2 = (unsigned char *) b;
	c2 = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		*(b2 + i) = c2;
		i++;
	}
	return (b);
}
