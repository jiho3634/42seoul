/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:50:03 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/21 20:47:46 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) malloc (len);
	if (*ptr == 0)
		return (0);
	i = 0;
	while (i <= len)
	{
		*(ptr + i) = *(s + start + i);
		i++;
	}
	return (ptr);
}
