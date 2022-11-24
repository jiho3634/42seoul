/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:40:57 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 21:02:49 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c2;
	unsigned char	*s2;

	c2 = (unsigned char) c;
	s2 = (unsigned char *) s;
	while (*s2 && *s2 != c2)
		s2++;
	if (*s2 == '\0' && c2 != '\0')
		return (0);
	return ((char *)s2);
}
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*str;
	int 	c = 'c';

	str = "bonr";
	printf("%p\n", ft_strchr(str,c));
	printf("%p\n", strchr(str, c));
	return (0);
}
