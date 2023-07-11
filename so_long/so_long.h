/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:25:19 by jihokim2          #+#    #+#             */
/*   Updated: 2023/05/17 03:10:19 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_data
{
	char	**map1;
	char	**map2;
	char	**temp;
	char	*line;
	int		fd;
	int		row;
	int		column;
	int		p;
	int		e;
	int		c;
	int		d[4];
	int		pi;
	int		pj;
	void	*texture;
	void	*player;
	void	*defense;
	void	*collection;
	void	*exit;
	void	*mlx;
	void	*win;
	int		count;
}t_data;

void	argc_argv_check(int argc, char *name);
t_data	*set_param(void);
void	make_map1(t_data *param, char *path, int i, int j);
void	map_check(t_data *param);
int		rectangle(t_data *param, int i, int j);
int		outline(t_data *param, int i, int j);
int		pec10(t_data *param, int i, int j);
int		path_check(t_data *param);
void	make_map2(t_data *param, int i, int j);
void	findp(t_data *param, int i, int j);
void	recursive(t_data *param, int i, int j, int k);
int		only_one(t_data *param, int i, int j);
void	error(t_data *param);
void	free_map1(t_data *param);
void	free_map2(t_data *param);
void	*ft_memset(void *b, int c, size_t len);
void	ft_xpm_file_to_image(t_data *param);
void	draw_map(t_data *param, int i, int j);
int		key_press(int keycode, t_data *param);
int		is_one(int keycode, t_data *param, int pi, int pj);
void	past_place(t_data *param, int pi, int pj);
void	move(t_data *param, int pi, int pj);
void	number_of_movement(int count, char mov);
int		end_game(t_data *param);

#endif
