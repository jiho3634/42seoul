/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:59:54 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/22 18:05:33 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	jh_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*s2;
	int		i;

	len = jh_strlen(s);
	s2 = (char *) malloc (len + 1);
	if (!s2)
		return (0);
	*(s2 + len) = 0;
	i = 0;
	while (*(s2 + i))
	{
		*(s2 + i) = f(i, *(s + i));
		i++;
	}
	return (s2);
}
