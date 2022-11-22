/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:29:15 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/16 17:41:16 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
		printf("  %d : %d\n", x, isalpha(x));
		printf("ft%d : %d\n", x, ft_isalpha(x));
	}
	return (0);
}
*/
