/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:15:32 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/23 12:25:07 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int x;

	x = -256;
	while (x++ <= 255)
	{
		printf("  %d : %d\n", x, isascii(x));
		printf("ft%d : %d\n", x, ft_isascii(x));
	}
	return (0);
}
*/
