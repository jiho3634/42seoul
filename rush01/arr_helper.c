/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjaecho <minjaecho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:09:05 by minjaecho         #+#    #+#             */
/*   Updated: 2022/10/09 21:23:19 by minjaecho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	checker(int i0, int i2, int target)
{
	int	can_see;
	int	max_val;
	int	iter[4];
	int	i;

	iter[0] = i0 / 10;
	iter[1] = i0 % 10;
	iter[2] = i2 / 10;
	iter[3] = i2 % 10;
	can_see = 0;
	max_val = 0;
	i = 0;
	while (i < 4)
	{
		if (iter[i] > max_val)
		{
			max_val = iter[i];
			can_see += 1;
		}
		i++;
	}
	return (can_see == target);
}

void	get_index_arrupdate(int arr[], int s_i, int i_i, int i_j)
{
	arr[0] = s_i / 10;
	arr[1] = s_i % 10;
	arr[2] = i_i;
	arr[3] = i_j;
}

int	*get_index(int ind)
{
	int	*r;

	r = (int *)malloc(4 * sizeof(int));
	if (ind / 4 == 0)
		get_index_arrupdate(r, 0 * 10 + ind % 4, 1, 0);
	else if (ind / 4 == 1)
		get_index_arrupdate(r, 3 * 10 + ind % 4, -1, 0);
	else if (ind / 4 == 2)
		get_index_arrupdate(r, ind % 4 * 10 + 0, 0, 1);
	else if (ind / 4 == 3)
		get_index_arrupdate(r, ind % 4 * 10 + 3, 0, -1);
	return (r);
}

int	check_str(char *str, int *arr)
{
	int		index;
	int		cnt;
	char	temp;

	index = 0;
	cnt = 0;
	while (*str)
	{
		if (cnt % 2 == 0)
		{
			temp = *str;
			if (temp > '4' || temp < '1')
				return (0);
			arr[index] = temp - '0';
			index++;
		}
		else
			if (*str != ' ')
				return (0);
		str++;
		cnt++;
	}
	if (cnt != 31)
		return (0);
	return (1);
}
