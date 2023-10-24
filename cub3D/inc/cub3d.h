#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define screenWidth 961
# define screenHeight 961
# define mapWidth 24
# define mapHeight 24

typedef struct  s_ray
{
	double	posX;
	double	posY;
	double	radius;
	int		grid_width;
	int		grid_height;
	double	dirX;
	double	dirY;
	double	cam_plane_len;
}	t_ray;

typedef struct	s_3d
{
	double	diagonal;
	double	rayX;
	double	rayY;
	double	d;
	double	ratio;
}	t_3d;

typedef struct s_mlx
{
	t_ray	ray;
	t_3d	ddd;	
	void	*mlx;
	void	*win;
	void	*mini;
}	t_mlx;

extern int map[mapWidth][mapHeight];

/*		ft_etc.c		*/
int		ft_end_game(t_mlx *mlx);
void	ft_init(t_mlx *mlx, int ac, char **av);

/*		ft_draw.c		*/
void	ft_draw_rectagle(t_mlx *mlx, int x, int y, int color);
void	ft_draw_grid(t_mlx *mlx, int val, int color);
void	ft_draw_player(t_mlx *mlx, int color);

/*		ft_key_press.c		*/
int		ft_is_wall(t_mlx *mlx, double px, double py);
void	ft_move(t_mlx *mlx, double theta);
int		ft_key_press(int keycode, t_mlx *mlx);

/*		ft_draw_ray.c		*/
// void    ft_draw_ray(t_mlx *mlx, double dirX, double dirY, int color);
// void    ft_draw_range_of_ray(t_mlx *mlx, int color);
void    ft_rotate(t_mlx *mlx, double angle);

/*		ft_draw_cam_line.c		*/
void    ft_draw_cam_ray(t_mlx *mlx, double dirX, double dirY, int color);
void    ft_draw_line(t_mlx *mlx, double x[2], double y[2], int wall, int ceiling, int floor);
void    ft_draw_cam_plane(t_mlx *mlx, int wall, int ceiling, int floor);

/*		ft_distance.c		*/
void    ft_distance(t_mlx *mlx);
void    ft_draw_wall(t_mlx *mlx, double x, int color);
void    ft_draw_ceiling(t_mlx *mlx, double x, int color);
void    ft_draw_floor(t_mlx *mlx, double x, int color);

#endif
