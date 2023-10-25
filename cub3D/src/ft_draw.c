#include "../inc/cub3d.h"

void	ft_draw_rectagle(t_mlx *mlx, int x, int y, int color)
{
	void	*m_m;
	void	*w_m;
	int		w;
	int		h;
	int		i;
	int		j;

	m_m = mlx->mlx;
	w_m = mlx->mini;
	w = mlx->ray.grid_width;
	h = mlx->ray.grid_height;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
				mlx_pixel_put(m_m, w_m, x * w + j, y * h + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_grid(t_mlx *mlx, int val, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapHeight)
	{
		x = 0;
		while (x < mapWidth)
		{
			if (map[y][x] == val)
				ft_draw_rectagle(mlx, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_mlx *mlx, int color)
{
	void	*m_m;
	void	*w_m;
    double	angle;
    double	r;
	double	x;
	double	y;

	m_m = mlx->mlx;
	w_m = mlx->mini;
	r = mlx->ray.radius;
	x = mlx->ray.posX;
	y = mlx->ray.posY;
    for (int i = 0; i < 360; i += 10)
	{
        angle = i * 2.0 * M_PI / 360;
		mlx_pixel_put(m_m, w_m, x + r * cos(angle), y + r * sin(angle), color);
    }
}
