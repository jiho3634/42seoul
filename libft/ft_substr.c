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

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	if (ft_strlen(s) <= start)
	{
		ptr = (char *) malloc (sizeof(char) * 1);
		*ptr = 0;
		return (ptr);
	}
	ptr = (char *) malloc (sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (s[start] && i < len)
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
