#include "../inc/cub3d.h"

void    ft_distance(t_mlx *mlx)
{
    double  posX = mlx->ray.posX;
    double  posY = mlx->ray.posY;
    double  rayX = mlx->ddd.rayX;
    double  rayY = mlx->ddd.rayY;
    double  dx;
    double  dy;

    dx = rayX - posX;
    dy = rayY - posY;
    mlx->ddd.d = sqrt(dx * dx + dy * dy);
}

void    ft_draw_wall(t_mlx *mlx, double x, int color)
{
    double  height;
    int     i;
    int     j;

    height = screenHeight * (1 - mlx->ddd.d / mlx->ddd.diagonal) / 2;
    i = (int)(height / 2);
    j = - screenHeight / 2;
    while (j < -i)
    {
        mlx_pixel_put(mlx->mlx, mlx->win, x, screenHeight / 2 + j, color);
        j++;
    }
    j = -i;
    while (j <= i) 
    {
        mlx_pixel_put(mlx->mlx, mlx->win, x, screenHeight / 2 + j, color);
        j++;
    }
    while (j <= screenHeight / 2) 
    {
        mlx_pixel_put(mlx->mlx, mlx->win, x, screenHeight / 2 + j, color);
        j++;
    }
}

void    ft_draw_ceiling(t_mlx *mlx, double x, int color)
{
    double  height;
    int     i;
    int     j;

    height = screenHeight * (1 - mlx->ddd.d / mlx->ddd.diagonal) / 2;
    i = (int)(height / 2);
    j = i + 1;
    while (j <= screenHeight / 2) 
    {
        mlx_pixel_put(mlx->mlx, mlx->win, x, screenHeight / 2 + j, color);
        j++;
    }
}

void    ft_draw_floor(t_mlx *mlx, double x, int color)
{
    double  height;
    int     i;
    int     j;

    height = screenHeight * (1 - mlx->ddd.d / mlx->ddd.diagonal) / 2;
    i = (int)(height / 2);
    j = - screenHeight / 2;
    while (j < -i)
    {
        mlx_pixel_put(mlx->mlx, mlx->win, x, screenHeight / 2 + j, color);
        j++;
    }
}
