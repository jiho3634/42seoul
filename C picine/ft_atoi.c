/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:15:20 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/16 10:46:37 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	if (!*str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	num = 0;
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	return (sign * num);
}
