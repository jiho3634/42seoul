/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:18:12 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 14:10:59 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) malloc (count * size);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < count)
	{
		*(ptr + i) = 0;
		i++;
	}
	return ((void *)ptr);
}
