/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:37:46 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/25 12:15:51 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;

	len = 0;
	while (s1[len])
		len++;
	if (len == 0)
		return (0);
	ptr = (char *) malloc (sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	*(ptr + len) = 0;
	while (--len >= 0)
		*(ptr + len) = *(s1 + len);
	return (ptr);
}
