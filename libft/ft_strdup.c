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
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1);
	if (len == 0)
	{
		ptr = malloc (sizeof(char));
		if (!ptr)
			return (0);
		*ptr = 0;
		return (ptr);
	}
	else
	{
		ptr = (char *) malloc (sizeof(char) * (len + 1));
		if (!ptr)
			return (0);
		*(ptr + len) = 0;
		while (len-- > 0)
			*(ptr + len) = *(s1 + len);
	}
	return (ptr);
}
/*
#include <stdio.h>
int main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";

	printf("%s\n", ft_strdup(str));
	return (0);
}
*/