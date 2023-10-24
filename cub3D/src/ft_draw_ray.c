#include "../inc/cub3d.h"

// void    ft_draw_ray(t_mlx *mlx, double dirX, double dirY, int color)
// {
//     int rayX;
//     int rayY;
//     int i;

//     i = 1;
//     while (1)
//     {
//         rayX = mlx->ray.posX + i * dirX;
//         rayY = mlx->ray.posY + i * dirY;
//         mlx_pixel_put(mlx->mlx, mlx->mini, rayX, rayY, color);
//         if (map[rayY / mlx->ray.grid_height][rayX / mlx->ray.grid_width] == 1)
//         {
//             mlx->ddd.rayX = rayX;
//             mlx->ddd.rayY = rayY;
//             break ;
//         }
//         i++;
//     }
// }

// void    ft_draw_range_of_ray(t_mlx *mlx, int color)
// {
//     double  angle;
//     double  rx;
//     double  ry;
//     double  bisect;
//     double  i;

//     bisect = 120;
//     i = -bisect / 2;
//     while (i <= bisect / 2)
//     {
//         angle = M_PI / 180 / 2 * i;
//         rx = mlx->ray.dirX * cos(angle) -  mlx->ray.dirY * sin(angle);
//         ry = mlx->ray.dirX * sin(angle) +  mlx->ray.dirY * cos(angle);
// 	    ft_draw_ray(mlx, rx, ry, color);
//         ft_distance(mlx);
//         ft_draw_wall(mlx, screenWidth / 2 * (1 + i / (bisect / 2)), color);
//         i = i + 1;
//     }
// }

// void    ft_draw_line(t_mlx *mlx, double x[2], double y[2], int color)
// {
//     double  camX;
//     double  camY;
//     double  end;

//     if (x[0] == x[1])
//     {
//         if (y[0] < y[1])
//         {
//             camY = y[0];
//             end = y[1];
//         }
//         else
//         {
//             camY = y[1];
//             end = y[0];
//         }
//         while (camY <= end) 
//         {
//             mlx_pixel_put(mlx->mlx, mlx->mini, x[0], camY, color);
//             camY += 1;
//         }
//         return ;
//     }
//     if (x[0] < x[1])
//     {
//         camX = x[0];
//         end = x[1];
//     }
//     else
//     {
//         camX = x[1];
//         end = x[0];
//     }
//     while (camX <= end)
//     {
//         camY = ((y[1] - y[0]) / (x[1] - x[0]) * (camX - x[0])) + y[0];
//         mlx_pixel_put(mlx->mlx, mlx->mini, camX, camY, color);
//         camX += 1;
//     }
// }

// void    ft_draw_cam_plane(t_mlx *mlx, int color)
// {
//     double  x[2];
//     double  y[2];
//     double  len;

//     len = 40;
//     x[0] = mlx->ray.posX + len * (mlx->ray.dirX * cos(M_PI/ 2) -  mlx->ray.dirY * sin(M_PI / 2));
//     y[0] = mlx->ray.posY + len * (mlx->ray.dirX * sin(M_PI / 2) +  mlx->ray.dirY * cos(M_PI / 2));
//     x[1] = mlx->ray.posX + len * (mlx->ray.dirX * cos(-M_PI/ 2) -  mlx->ray.dirY * sin(-M_PI / 2));
//     y[1] = mlx->ray.posY + len * (mlx->ray.dirX * sin(-M_PI / 2) +  mlx->ray.dirY * cos(-M_PI / 2));
//     ft_draw_line(mlx, x, y, color);
// }

void    ft_rotate(t_mlx *mlx, double angle)
{
    double rx;
    double ry;

    rx = mlx->ray.dirX * cos(angle) -  mlx->ray.dirY * sin(angle);
    ry = mlx->ray.dirX * sin(angle) +  mlx->ray.dirY * cos(angle);
    ft_draw_cam_plane(mlx, 0x000000, 0x000000, 0x000000);
	ft_draw_player(mlx, 0x000000);
	ft_draw_grid(mlx, 0, 0xFFFFFF);
	ft_draw_grid(mlx, 1, 0xFF0000);
    mlx->ray.dirX = rx;
    mlx->ray.dirY = ry;
	ft_draw_player(mlx, 0xFFFF00);
    ft_draw_cam_plane(mlx, 0x00FF00, 0x0000FF, 0x808080);
}