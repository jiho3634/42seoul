/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@studen.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:04:07 by jihokim2          #+#    #+#             */
/*   Updated: 2023/05/17 02:59:08 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xpm_file_to_image(t_data *param)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	param -> texture = mlx_xpm_file_to_image(param -> mlx, "texture.xpm", \
													&img_width, &img_height);
	param -> player = mlx_xpm_file_to_image(param -> mlx, "player.xpm", \
													&img_width, &img_height);
	param -> defense = mlx_xpm_file_to_image(param -> mlx, "defense.xpm", \
													&img_width, &img_height);
	param -> collection = mlx_xpm_file_to_image(param -> mlx, \
									"collection.xpm", &img_width, &img_height);
	param -> exit = mlx_xpm_file_to_image(param -> mlx, "exit.xpm", \
													&img_width, &img_height);
}

void	draw_map(t_data *param, int i, int j)
{
	while (i < param -> row)
	{
		j = 0;
		while (j < param -> column - 1)
		{
			mlx_put_image_to_window(param -> mlx, param -> win, \
							param -> texture, 64 * j, 64 * i);
			if (param -> map1[i][j] == '1')
				mlx_put_image_to_window(param -> mlx, param -> win, \
							param -> defense, 64 * j, 64 * i);
			else if (param -> map1[i][j] == 'P')
				mlx_put_image_to_window(param -> mlx, param -> win, \
							param -> player, 64 * j, 64 * i);
			else if (param -> map1[i][j] == 'C')
				mlx_put_image_to_window(param -> mlx, param -> win, \
						param -> collection, 64 * j, 64 * i);
			else if (param -> map1[i][j] == 'E')
				mlx_put_image_to_window(param -> mlx, param -> win, \
								param -> exit, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}

int	key_press(int keycode, t_data *param)
{
	if (keycode == 53)
		end_game(param);
	else if (keycode != 0 && keycode != 1 && keycode != 2 && keycode != 13)
		return (0);
	if (is_one(keycode, param, param -> pi, param -> pj) == 0)
		return (0);
	past_place(param, param -> pi, param -> pj);
	if (keycode == 0)
		move(param, param -> pi, param -> pj - 1);
	else if (keycode == 1)
		move(param, param -> pi + 1, param -> pj);
	else if (keycode == 2)
		move(param, param -> pi, param -> pj + 1);
	else if (keycode == 13)
		move(param, param -> pi - 1, param -> pj);
	param -> count++;
	number_of_movement(param -> count, 0);
	write(1, "\n", 1);
	return (keycode);
}
