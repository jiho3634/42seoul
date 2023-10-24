#include "../inc/cub3d.h"

void    ft_draw_cam_ray(t_mlx *mlx, double camX, double camY, int color)
{
    int rayX;
    int rayY;
    int i;

    i = 1;
    while (1)
    {
        rayX = camX + i * mlx->ray.dirX;
        rayY = camY + i * mlx->ray.dirY;
        mlx_pixel_put(mlx->mlx, mlx->mini, rayX, rayY, color);
        if (map[rayY / mlx->ray.grid_height][rayX / mlx->ray.grid_width] == 1)
        {
            mlx->ddd.rayX = rayX;
            mlx->ddd.rayY = rayY;
            break ;
        }
        i++;
    }
}

void    ft_draw_line(t_mlx *mlx, double x[2], double y[2], int wall, int ceiling, int floor)
{
    double  m;
    double  camX;
    double  camY;
    double  i;

    i = 0;
    m = mlx->ray.dirY / mlx->ray.dirX; 
    if (m < 1 && m > -1) 
    {
        if (y[0] < y[1])
        {
            mlx->ddd.ratio = screenWidth / (y[1] - y[0]);
            while (y[0] + i <= y[1])
            {
                camY = y[0] + i;
                camX = (camY - mlx->ray.posY) * (-m) + mlx->ray.posX;
                mlx_pixel_put(mlx->mlx, mlx->mini, camX, camY, wall);
                ft_draw_cam_ray(mlx, camX, camY, wall);
                ft_distance(mlx);
                ft_draw_wall(mlx, screenWidth - i * mlx->ddd.ratio, wall);
                ft_draw_ceiling(mlx, screenWidth - i * mlx->ddd.ratio, ceiling);
                ft_draw_floor(mlx, screenWidth - i * mlx->ddd.ratio, floor);
                i += 1;
            }
        }
        else
        {
            mlx->ddd.ratio = screenWidth / (y[0] - y[1]);
            while (y[1] + i <= y[0])
            {
                camY = y[1] + i;
                camX = (camY - mlx->ray.posY) * (-m) + mlx->ray.posX;
                mlx_pixel_put(mlx->mlx, mlx->mini, camX, camY, wall);
                ft_draw_cam_ray(mlx, camX, camY, wall);
                ft_distance(mlx);
                ft_draw_wall(mlx, i * mlx->ddd.ratio, wall);
                ft_draw_ceiling(mlx, i * mlx->ddd.ratio, ceiling);
                ft_draw_floor(mlx, i * mlx->ddd.ratio, floor);
                i += 1;
            }
        }
        camX = (camY - mlx->ray.posY) * m + mlx->ray.posX;
    }
    else 
    {
        if (x[0] < x[1])
        {
            mlx->ddd.ratio = screenWidth / (x[1] - x[0]);
            while (x[0] + i <= x[1])
            {
                camX = x[0] + i;
                camY = (camX - x[0]) / (-m) + y[0];
                mlx_pixel_put(mlx->mlx, mlx->mini, camX, camY, wall);
                ft_draw_cam_ray(mlx, camX, camY, wall);
                ft_distance(mlx);
                ft_draw_wall(mlx, screenWidth - i * mlx->ddd.ratio, wall);
                ft_draw_ceiling(mlx, screenWidth - i * mlx->ddd.ratio, ceiling);
                ft_draw_floor(mlx, screenWidth - i * mlx->ddd.ratio, floor);
                i += 1;
            }
        }
        else
        {
            mlx->ddd.ratio = screenWidth / (x[0] - x[1]);
            while (x[1] + i <= x[0])
            {
                camX = x[1] + i;
                camY = (camX - x[0]) / (-m) + y[0];
                mlx_pixel_put(mlx->mlx, mlx->mini, camX, camY, wall);
                ft_draw_cam_ray(mlx, camX, camY, wall);
                ft_distance(mlx);
                ft_draw_wall(mlx, i * mlx->ddd.ratio, wall);
                ft_draw_ceiling(mlx, i * mlx->ddd.ratio, ceiling);
                ft_draw_floor(mlx, i * mlx->ddd.ratio, floor);
                i += 1;
            }
        }
    }
}

void    ft_draw_cam_plane(t_mlx *mlx, int wall, int ceiling, int floor)
{
    double  x[2];
    double  y[2];
    double  len;

    len = mlx->ray.cam_plane_len;
    x[0] = mlx->ray.posX + len * (mlx->ray.dirX * cos(M_PI/ 2) -  mlx->ray.dirY * sin(M_PI / 2));
    y[0] = mlx->ray.posY + len * (mlx->ray.dirX * sin(M_PI / 2) +  mlx->ray.dirY * cos(M_PI / 2));
    x[1] = mlx->ray.posX + len * (mlx->ray.dirX * cos(-M_PI/ 2) -  mlx->ray.dirY * sin(-M_PI / 2));
    y[1] = mlx->ray.posY + len * (mlx->ray.dirX * sin(-M_PI / 2) +  mlx->ray.dirY * cos(-M_PI / 2));
    ft_draw_line(mlx, x, y, wall, ceiling, floor);
}
