/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjaecho <minjaecho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:09:05 by minjaecho         #+#    #+#             */
/*   Updated: 2022/10/09 20:43:59 by minjaecho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "c_stl.h"
#include "arr_helper.h"

int	arr_iterator(int **perms, int checks[], int arr[])
{
	int	i;
	int	xy;
	int	c;
	int	vals[4];

	i = 0;
	while (i < 16)
	{
		xy = get_index(i)[0] * 10 + get_index(i)[1];
		c = 0;
		while (c < 4)
		{
			vals[c] = perms[arr[xy / 10]][xy % 10];
			xy += get_index(i)[2] * 10 + get_index(i)[3];
			c++;
		}
		if (vals[0] + vals[1] + vals[2] + vals[3] != 10)
		{
			break ;
		}
		if (!checker(vals[0] * 10 + vals[1], vals[2] * 10 + vals[3], checks[i]))
			break ;
		i++;
	}
	return (i);
}

int	arr_printer(int **perms, int checks[], int arr[], int depth)
{
	int	flag;
	int	i;

	flag = 0;
	i = arr_iterator(perms, checks, arr);
	if (i == 16)
		flag = 1;
	if (flag)
	{
		i = 0;
		while (i < depth)
		{
			print_arr(perms[arr[i]], depth);
			i++;
		}
		return (1);
	}
	return (0);
}

int	do_arr(int arr[], int depth, int checks[], int **perms)
{
	int			val;
	static int	flag = 0;

	if (4 == depth)
	{
		flag += arr_printer(perms, checks, arr, depth);
		return (flag);
	}
	val = 0;
	while (val < 24)
	{
		arr[depth] = val;
		do_arr(arr, depth + 1, checks, perms);
		val++;
	}
	return (flag);
}

void	solve(int checks[])
{
	int	i;
	int	*temp_arr;
	int	*perms[24];
	int	arr2[4];
	int	flag;

	i = 0;
	temp_arr = (int *)malloc(4 * sizeof(int));
	while (i < 4)
	{
		temp_arr[i] = i + 1;
		i++;
	}
	same_permutation(temp_arr, 4, 0, perms);
	free(temp_arr);
	flag = do_arr(arr2, 0, checks, perms);
	if (flag < 1)
		write(1, "Error\n", 6);
}

int	main(int argc, char **argv)
{
	int	arr[16];

	if (argc == 2)
	{
		if (!check_str(argv[1], arr))
			write(1, "Error\n", 6);
		else
			solve(arr);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
