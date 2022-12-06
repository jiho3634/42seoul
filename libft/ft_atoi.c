/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:43:12 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 20:15:29 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long	answer;
	long	sign;

	if (*str == 0)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	answer = 0;
	while (*str >= '0' && *str <= '9')
	{
		answer = answer * 10 + sign * (*str - '0');
		str++;
	}
	return (answer);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	char	*str;

	str = "214748364880";
	printf("atoi : %d\n", atoi(str));
	printf("ft_atoi : %d\n", ft_atoi(str));

	printf("INT_MAX : %d\n", INT_MAX);
	printf("LONG_MAX : %ld\n", LONG_MAX);
	printf("LONG_MIN : %ld\n", LONG_MIN);
	printf("LLONG_MAX : %lld\n", LLONG_MAX);
	printf("LLONG_MIN : %lld\n", LLONG_MIN);

	printf("atoi(LONG_MAX) : %d\n", atoi("9223372036854775807"));
	printf("ft_atoi(LONG_MAX) : %d\n", ft_atoi("9223372036854775807"));
	printf("atoi(LONG_MAX) : %d\n", atoi("-92233720368547758089"));
	printf("ft_atoi(LONG_MAX) : %d\n", ft_atoi("-92233720368547758089"));

	return (0);
}
*/
