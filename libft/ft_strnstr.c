/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:04:36 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/22 17:27:22 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (i < len)
	{
		if (*(haystack + i) == *(needle))
		{
			j = 0;
			while (i + j < len)
			{
				if (*(haystack + i + j) != *(needle + j))
					break ;
				j++;
			}
		}
		i++;
	}
	if ((i == len) || (*(haystack + i)))
		return (0);
	return ((char *)(haystack + i));
}
