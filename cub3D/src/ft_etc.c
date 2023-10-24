#include "../inc/cub3d.h"

int	ft_end_game(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mini);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void  ft_init(t_mlx *mlx, int ac, char **av)
{
	(void)ac;
	(void)av;
	mlx->mlx = mlx_init();
	mlx_do_key_autorepeaton(mlx->mlx);
	mlx->mini = mlx_new_window(mlx->mlx, screenWidth, screenHeight, "miniMap");
	mlx->win = mlx_new_window(mlx->mlx, screenWidth, screenHeight, "cub3D");
	mlx->ray.grid_width = screenWidth / mapWidth;
	mlx->ray.grid_height = screenHeight / mapHeight;
	mlx->ray.radius = mlx->ray.grid_width / 2;
	mlx->ray.posX = 20 * mlx->ray.grid_width;
	mlx->ray.posY = 20 * mlx->ray.grid_height;
	ft_draw_grid(mlx, 0, 0xFFFFFF);
	ft_draw_grid(mlx, 1, 0xFF0000);
	ft_draw_player(mlx, 0xFFFF00);
	mlx->ray.dirX = -1;
	mlx->ray.dirY = 0;
	mlx->ray.cam_plane_len = mlx->ray.grid_width * 3;
	mlx->ddd.ratio = screenWidth / mlx->ray.cam_plane_len;
    mlx->ddd.diagonal = sqrt(screenWidth * screenWidth + screenHeight * screenHeight);
    ft_draw_cam_plane(mlx, 0x00FF00, 0x0000FF, 0x808080);
	// ft_draw_range_of_ray(mlx, 0xffff00);
}
