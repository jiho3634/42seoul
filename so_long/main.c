/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:34:44 by jihokim2          #+#    #+#             */
/*   Updated: 2023/05/17 02:37:38 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*param;

	argc_argv_check(argc, argv[1]);
	param = set_param();
	make_map1(param, argv[1], 0, 0);
	map_check(param);
	path_check(param);
	param -> mlx = mlx_init();
	param -> win = mlx_new_window(param -> mlx, 64 * (param -> column - 1), \
													64 * param -> row, "Dunk");
	ft_xpm_file_to_image(param);
	draw_map(param, 0, 0);
	mlx_hook(param -> win, 2, 0, &key_press, param);
	mlx_hook(param -> win, 17, 0, &end_game, param);
	mlx_loop(param -> mlx);
}
