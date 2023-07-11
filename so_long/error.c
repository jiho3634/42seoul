/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:18:47 by jihokim2          #+#    #+#             */
/*   Updated: 2023/05/17 03:02:56 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_data *param)
{
	if (param -> map2)
		free_map2(param);
	if (param -> map1)
		free_map1(param);
	if (param)
		free(param);
	exit(1);
}

void	free_map1(t_data *param)
{
	int	i;

	i = 0;
	while (param -> map1[i])
	{
		free(param -> map1[i]);
		i++;
	}
	free(param -> map1);
	return ;
}

void	free_map2(t_data *param)
{
	int	i;

	i = 0;
	while (param -> map2[i])
	{
		free(param -> map2[i]);
		i++;
	}
	free(param -> map2);
	return ;
}
