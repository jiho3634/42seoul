/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:25:09 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/21 20:47:12 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
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
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	s;

	s = "abcdefg";

	printf("%lu\n", strlen(s));
	printf("%lu\n", ft_strlen(s));

	return (0);
}
*/
