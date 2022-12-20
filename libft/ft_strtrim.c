/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:57:27 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 14:04:05 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static char	*ft_strncpy(char *dest, char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	head;
	size_t	tail;

	if (!s1[0] || !set[0])
		s2 = ft_strdup(s1);
	else
	{
		tail = ft_strlen(s1) - 1;
		head = 0;
		while (s1[head] && ft_strchr(set, s1[head]))
			head++;
		while ((tail > head) && ft_strchr(set, s1[tail]))
			tail--;
		s2 = (char *) malloc (sizeof(char) * ((tail - head + 1) + 1));
		if (!s2)
			return (0);
		ft_strncpy(s2, (char *)s1 + head, (tail - head + 1) + 1);
		s2[tail - head + 1] = 0;
	}
	return (s2);
}
