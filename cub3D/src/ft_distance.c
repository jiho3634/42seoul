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

void    ft_pixel_put(t_mlx *mlx, double x, double y, int dir, int texY)
{
    int    color;
    int             texX;
    unsigned int    *addr;

    addr = (unsigned int *)mlx->img.addr[dir];
    if (dir == 0 || dir == 1)
        texX = (int)mlx->ddd.rayY % mlx->ray.grid_height * 64 / mlx->ray.grid_height;
    else
        texX = (int)mlx->ddd.rayX % mlx->ray.grid_width * 64 / mlx->ray.grid_width;
    color = *(addr + texY * 64 + texX);
    mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
}

int ft_get_dir(t_mlx *mlx)
{
    if ((int)mlx->ddd.rayX % mlx->ray.grid_width == mlx->ray.grid_width - 1)
        return (0);
    else if ((int)mlx->ddd.rayX % mlx->ray.grid_width == 0)
        return (1);
    else if ((int)mlx->ddd.rayY % mlx->ray.grid_height == mlx->ray.grid_height - 1)
        return (2);
    else if ((int)mlx->ddd.rayY % mlx->ray.grid_height == 0)
        return (3);
    return (0);
}

void    ft_draw_wall(t_mlx *mlx, double x, int color)
{
    double  height;
    int     i;
    int     j;

    (void)color;
    height = screenHeight * (1 - mlx->ddd.d / mlx->ddd.diagonal) / 2;
    i = (int)(height / 2);
    j = 0;
    while (-i + j <= i)
    {
        // mlx_pixel_put(mlx->mlx, mlx->win, x, screenHeight / 2 + j, color);
        ft_pixel_put(mlx, x, screenHeight / 2 + -i + j, ft_get_dir(mlx), j * 64 / (2 * i));
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
