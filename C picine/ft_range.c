/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:06:38 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/18 08:51:26 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	*p;

	if (min >= max)
		return (0);
	range = (int *)malloc(sizeof(int) * (max - min));
	p = range;
	while (min < max)
	{
		*p = min;
		p++;
		min++;
	}
	return (range);
}
