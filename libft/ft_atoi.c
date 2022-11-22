/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:43:12 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/22 17:32:01 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	answer;
	int	sign;

	while ((*str >= 8 && *str <= 12) || *str == 32)
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
