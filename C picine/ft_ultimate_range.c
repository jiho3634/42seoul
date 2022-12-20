/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultamate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:12:00 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/19 21:09:01 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int *) malloc(sizeof(int) * (max - min));
	if (*range == 0)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
