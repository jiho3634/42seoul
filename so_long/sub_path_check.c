/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihiokim2@student42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:28:53 by jihokim2          #+#    #+#             */
/*   Updated: 2023/05/17 03:04:49 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map2(t_data *param, int i, int j)
{
	param -> map2 = (char **)malloc(sizeof(char *) * (param -> row + 1));
	if (!param -> map2)
		error(param);
	param -> map2[param -> row] = NULL;
	while (param -> map1[i])
	{
		param -> map2[i] = (char *)malloc(sizeof(char) * param -> column);
		if (!param -> map2[i])
			error(param);
		param -> map2[i][param -> column - 1] = 0;
		i++;
	}
	i = 0;
	while (i < param -> row)
	{
		j = 0;
		while (j < param -> column - 1)
		{
			param -> map2[i][j] = param -> map1[i][j];
			j++;
		}
		i++;
	}
}

void	findp(t_data *param, int i, int j)
{
	while (param -> map2[i])
	{
		j = 0;
		while (param -> map2[i][j])
		{
			if (param -> map2[i][j] == 'P')
			{
				param -> pi = i;
				param -> pj = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	recursive(t_data *param, int i, int j, int k)
{
	if (param -> map2[i][j] == '1')
		return ;
	else
	{
		param -> map2[i][j] = '1';
		while (k < 4)
		{
			recursive(param, i + param -> d[k], j + param -> d[3 - k], 0);
			k++;
		}
		return ;
	}
}

int	only_one(t_data *param, int i, int j)
{
	while (param -> map2[i])
	{
		j = 0;
		while (param -> map2[i][j])
		{
			if (!(param -> map2[i][j] == '0' || param -> map2[i][j] == '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
