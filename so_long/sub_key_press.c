/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:11:34 by jihokim2          #+#    #+#             */
/*   Updated: 2023/05/17 03:08:15 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_one(int keycode, t_data *param, int pi, int pj)
{
	if (keycode == 0 && param -> map1[pi][pj - 1] == '1')
		return (0);
	else if (keycode == 1 && param -> map1[pi + 1][pj] == '1')
		return (0);
	else if (keycode == 2 && param -> map1[pi][pj + 1] == '1')
		return (0);
	else if (keycode == 13 && param -> map1[pi - 1][pj] == '1')
		return (0);
	else
		return (1);
}		

void	past_place(t_data *param, int pi, int pj)
{
	mlx_put_image_to_window(param -> mlx, param -> win, param -> texture, \
														64 * pj, 64 * pi);
	if (param -> map1[pi][pj] == 'E')
		mlx_put_image_to_window(param -> mlx, param -> win, param -> exit, \
														64 * pj, 64 * pi);
	else if (param -> map1[pi][pj] == 'P')
		param -> map1[pi][pj] = '0';
}

void	move(t_data *param, int pi, int pj)
{
	if (param -> map1[pi][pj] == '0')
		mlx_put_image_to_window(param -> mlx, param -> win, param -> player, \
														64 * pj, 64 * pi);
	else if (param -> map1[pi][pj] == 'E')
	{
		if (param -> c == 0)
			end_game(param);
		else
			mlx_put_image_to_window(param -> mlx, param -> win, \
											param -> player, 64 * pj, 64 * pi);
	}
	else if (param -> map1[pi][pj] == 'C')
	{
		param -> c--;
		param -> map1[pi][pj] = '0';
		mlx_put_image_to_window(param -> mlx, param -> win, param -> texture, \
															64 * pj, 64 * pi);
		mlx_put_image_to_window(param -> mlx, param -> win, param -> player, \
															64 * pj, 64 * pi);
	}
	param -> pi = pi;
	param -> pj = pj;
}

void	number_of_movement(int count, char mov)
{
	if (count == 0)
		return ;
	number_of_movement(count / 10, 0);
	mov = count % 10 + '0';
	write(1, &mov, 1);
}

int	end_game(t_data *param)
{
	mlx_destroy_window(param -> mlx, param -> win);
	if (param -> map2)
		free_map2(param);
	if (param -> map1)
		free_map1(param);
	if (param)
		free(param);
	exit(0);
}
