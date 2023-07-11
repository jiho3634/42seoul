/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:18:21 by jihokim2          #+#    #+#             */
/*   Updated: 2023/05/17 03:02:18 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rectangle(t_data *param, int i, int j)
{
	while (param -> map1[i])
		i++;
	if (i == 1)
		return (0);
	param -> row = i;
	i = 0;
	while (param -> map1[i])
	{
		j = 0;
		while (param -> map1[i][j])
			j++;
		if (j <= 2)
			return (0);
		else if (i == 0)
			param -> column = j;
		else if (j != param -> column)
			return (0);
		i++;
	}
	return (1);
}

int	outline(t_data *param, int i, int j)
{
	while (param -> map1[0][j])
	{
		if (param -> map1[0][j] != '1' && param -> map1[0][j] != '\n')
			return (0);
		j++;
	}
	while (param -> map1[i])
	{
		if (!(param -> map1[i][0] == '1' && param -> map1[i][j - 2] == '1'))
			return (0);
		i++;
	}
	j = 0;
	while (param -> map1[i - 1][j])
	{
		if (param -> map1[i - 1][j] != '1' && param -> map1[i - 1][j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

int	pec10(t_data *param, int i, int j)
{
	while (param -> map1[i])
	{
		j = 0;
		while (param -> map1[i][j])
		{
			if (param -> map1[i][j] == 'P' || param -> map1[i][j] == 'E' || \
				param -> map1[i][j] == 'C' || param -> map1[i][j] == '1' || \
				param -> map1[i][j] == '0' || param -> map1[i][j] == '\n')
			{
				if (param -> map1[i][j] == 'P')
					param -> p++;
				else if (param -> map1[i][j] == 'E')
					param -> e++;
				else if (param -> map1[i][j] == 'C')
					param -> c++;
			}
			else
				return (0);
			j++;
		}
		i++;
	}
	if (param -> p != 1 || param -> e != 1 || param -> c < 1)
		return (0);
	return (1);
}
