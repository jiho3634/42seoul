/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:25:09 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 13:58:29 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*s;

	s = 0;

	printf("%lu\n", strlen(s));
	printf("%lu\n", ft_strlen(s));

	return (0);
}
*/
