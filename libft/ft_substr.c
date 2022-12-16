/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:50:03 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/25 12:26:00 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (ft_strlen(s) <= start)
	{
		ptr = (char *) malloc (sizeof(char));
		if (!ptr)
			return (0);
		*ptr = 0;
		return (ptr);
	}
	else if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	ptr = (char *) malloc (sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	char *s;
	unsigned int start;
	size_t len;

	s = "lorem ipsum dolor sit amet";
	start = 0;
	len = 10; 
	printf("%s\n", ft_substr(s, start, len));
	return (0);
}
*/
