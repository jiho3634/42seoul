#include "../inc/cub3d.h"

int	ft_end_game(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mini);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	ft_is_wall(t_mlx *mlx, double px, double py)
{
    double	angle;
	double	r;
	int		x;
	int		y;

	r = mlx->ray.radius;
    for (int i = 0; i < 360; i += 10)
	{
        angle = i * 2.0 * M_PI / 360;
		x = (int)(px + r * cos(angle)) / mlx->ray.grid_width;
		y = (int)(py + r * sin(angle)) / mlx->ray.grid_height;
		if (map[y][x] == 1)
			return (1);
	}
	return (0);
}	

void	ft_remove_screen(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < screenHeight)
	{
		j = -1;
		while (++j < screenWidth)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, j, i, 0x000000);
			mlx_pixel_put(mlx->mlx, mlx->mini, j, i, 0x000000);
		}
	}
}

void	ft_move(t_mlx *mlx, double theta)
{
	double	rx;
	double	ry;
	double	px;
	double	py;

	px =  mlx->ray.posX;
	py =  mlx->ray.posY;
    rx = mlx->ray.dirX * cos(theta) -  mlx->ray.dirY * sin(theta);
    ry = mlx->ray.dirX * sin(theta) +  mlx->ray.dirY * cos(theta);
	px += (int)(rx * 10);
	py += (int)(ry * 10);
	if (ft_is_wall(mlx, px, py) == 1)
		return ;
    // ft_draw_cam_plane(mlx, 0x000000, 0x000000, 0x000000);
	// ft_draw_player(mlx, 0x000000);
	ft_remove_screen(mlx);
	ft_draw_grid(mlx, 0, 0xFFFFFF);
	ft_draw_grid(mlx, 1, 0xFF0000);
	mlx->ray.posX = px;
	mlx->ray.posY = py;
	ft_draw_player(mlx, 0xFFFF00);
    ft_draw_cam_plane(mlx, 0x00FF00, 0x0000FF, 0x808080);
}

int	ft_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		ft_end_game(mlx);
	else if (keycode != 0 && keycode != 1 && keycode != 2 \
			&& keycode != 13 && keycode != 123 && keycode != 124)
		return (0);
	if (keycode == 0)
		ft_move(mlx, -M_PI / 2);
	else if (keycode == 1)
		ft_move(mlx, M_PI);
	else if (keycode == 2)
		ft_move(mlx, M_PI / 2);
	else if (keycode == 13)
		ft_move(mlx, 0);
	else if (keycode == 123)
		ft_rotate(mlx, -M_PI / 18);
	else if (keycode == 124)
		ft_rotate(mlx, M_PI / 18);
	return (keycode);
}
