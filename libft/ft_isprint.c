/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:20:50 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/16 17:41:17 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
		printf("  %d : %d\n", x, isprint(x));
		printf("ft%d : %d\n", x, ft_isprint(x));
	}
	return (0);
}
*/
