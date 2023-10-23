#include "../inc/cub3d.h"

void    ft_draw_ray(t_mlx *mlx, double dirX, double dirY, int color)
{
    int rayX;
    int rayY;
    int i;

    i = 1;
    while (1)
    {
        rayX = mlx->ray.posX + i * dirX;
        rayY = mlx->ray.posY + i * dirY;
        mlx_pixel_put(mlx->mlx, mlx->mini, rayX, rayY, color);
        if (map[rayY / mlx->ray.grid_height][rayX / mlx->ray.grid_width] == 1)
            break ;
        i++;
    }
}

void    ft_draw_range_of_ray(t_mlx *mlx, int color)
{
    double  angle;
    double  rx;
    double  ry;
    double  i;

    i = 0;
    while (i <= 15)
    {
        angle = M_PI / 180 * i;
        rx = mlx->ray.dirX * cos(angle) -  mlx->ray.dirY * sin(angle);
        ry = mlx->ray.dirX * sin(angle) +  mlx->ray.dirY * cos(angle);
	    ft_draw_ray(mlx, rx, ry, color);
        angle = M_PI / 180 * -i;
        rx = mlx->ray.dirX * cos(angle) -  mlx->ray.dirY * sin(angle);
        ry = mlx->ray.dirX * sin(angle) +  mlx->ray.dirY * cos(angle);
	    ft_draw_ray(mlx, rx, ry, color);
        i = i + 1;
    }
}

void    ft_rotate(t_mlx *mlx, double angle)
{
    double rx;
    double ry;

    rx = mlx->ray.dirX * cos(angle) -  mlx->ray.dirY * sin(angle);
    ry = mlx->ray.dirX * sin(angle) +  mlx->ray.dirY * cos(angle);
	ft_draw_range_of_ray(mlx, 0x000000);
	ft_draw_player(mlx, 0x000000);
	ft_draw_grid(mlx, 0, 0xFFFFFF);
	ft_draw_grid(mlx, 1, 0xFF0000);
    mlx->ray.dirX = rx;
    mlx->ray.dirY = ry;
	ft_draw_player(mlx, 0xFFFF00);
	ft_draw_range_of_ray(mlx, 0xffff00);
}