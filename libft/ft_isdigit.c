/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:49:27 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/23 12:12:14 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int x;

	x = -1;
	while (x++ <= 255)
	{
		printf("  %d : %d\n", x, isdigit(x));
		printf("ft%d : %d\n", x, ft_isdigit(x));
	}
	return (0);
}
*/
