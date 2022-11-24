/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:37:46 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 14:08:48 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;

	len = 0;
	while (*(s1 + len))
		len++;
	ptr = (char *) malloc (sizeof(char) * len);
	if (!ptr)
		return (0);
	while (*s1)
	{
		*ptr = (*(char *)s1);
		s1++;
		ptr++;
	}
	return (ptr - len);
}
