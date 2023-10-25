#include "../inc/cub3d.h"

int map[mapWidth][mapHeight] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	ft_init(t_mlx *mlx)
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
	ft_mlx_img(mlx);
    ft_draw_cam_plane(mlx, 0x00FF00, 0x0000FF, 0x808080);
}

int	ft_is_valid_extension(int ac, char **av)
{
	if (ac != 2)
		exit(1);
	if (av == NULL)
		exit(1);
	if (av[1] == NULL)
		exit(1);
	if (av[1][0] == '\0')
		exit(1);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	ft_is_valid_arg(ac, av);
	ft_init(&mlx);
	mlx_hook(mlx.win, 2, 0, &ft_key_press, &mlx);
	mlx_hook(mlx.win, 17, 0, &ft_end_game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
