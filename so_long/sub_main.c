/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@studen.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:05:55 by jihokim2          #+#    #+#             */
/*   Updated: 2023/05/17 03:10:44 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	argc_argv_check(int argc, char *argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "Error\nthe argc is not 2\n", 24);
		exit (1);
	}
	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 4] != '.' || argv[i - 3] != 'b' || \
		argv[i - 2] != 'e' || argv[i - 1] != 'r')
	{
		write(1, "Error\nfile extention error\n", 27);
		exit(1);
	}
	return ;
}

t_data	*set_param(void)
{
	t_data	*param;

	param = (t_data *)malloc(sizeof(t_data));
	if (param == NULL)
		error(param);
	else
	{
		ft_memset(param, 0, sizeof(t_data));
		param -> d[0] = 0;
		param -> d[1] = -1;
		param -> d[2] = 0;
		param -> d[3] = 1;
	}
	return (param);
}

void	make_map1(t_data *param, char *path, int i, int j)
{
	param -> fd = open(path, O_RDWR);
	if (param -> fd == -1)
		error(param);
	while (1)
	{
		param -> line = get_next_line(param -> fd);
		if (!param -> line)
			break ;
		if (param ->map1)
			param -> temp = param -> map1;
		param -> map1 = (char **)malloc(sizeof(char *) * (i + 2));
		if (!param -> map1)
			error(param);
		j = 0;
		while (j < i)
		{
			param -> map1[j] = param -> temp[j];
			j++;
		}
		if (param -> temp)
			free (param -> temp);
		param -> map1[i++] = param -> line;
		param -> map1[i] = NULL;
	}
}

void	map_check(t_data *param)
{
	if (param -> map1 == NULL)
		write(1, "Error\nempty map\n", 16);
	else if (!rectangle(param, 0, 0))
		write(1, "Error\nnot rectangle\n", 20);
	else if (!outline(param, 0, 0))
		write(1, "Error\nnot only 1 in outline\n", 28);
	else if (!pec10(param, 0, 0))
		write(1, "Error\nPEC10\n", 12);
	else if (param -> row > 30 || param -> column > 50)
		write(1, "Error\nThe map is too bin\n", 25);
	else
		return ;
	error(param);
}

int	path_check(t_data *param)
{
	make_map2(param, 0, 0);
	findp(param, 0, 0);
	recursive(param, param -> pi, param -> pj, 0);
	if (!only_one(param, 0, 0))
	{
		write(1, "Error\nNo path\n", 14);
		error(param);
	}
	return (1);
}
