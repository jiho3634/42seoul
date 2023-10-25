#include "../inc/cub3d.h"

void	ft_mlx_xpm_file_to_image(t_mlx *mlx, int width, int height)
{
	mlx->img.img[0] = mlx_xpm_file_to_image(mlx->mlx, "blue.xpm", &width, &height);
	mlx->img.img[1] = mlx_xpm_file_to_image(mlx->mlx, "grey.xpm", &width, &height);
	mlx->img.img[2] = mlx_xpm_file_to_image(mlx->mlx, "purple.xpm", &width, &height);
	mlx->img.img[3] = mlx_xpm_file_to_image(mlx->mlx, "red.xpm", &width, &height);
}

void	ft_mlx_get_data_addr(t_mlx *mlx, int bpp, int size, int endian)
{
	mlx->img.addr[0] = mlx_get_data_addr(mlx->img.img[0], &bpp, &size, &endian);
	mlx->img.addr[1] = mlx_get_data_addr(mlx->img.img[1], &bpp, &size, &endian);
	mlx->img.addr[2] = mlx_get_data_addr(mlx->img.img[2], &bpp, &size, &endian);
	mlx->img.addr[3] = mlx_get_data_addr(mlx->img.img[3], &bpp, &size, &endian);
}

void	ft_print_addr(t_mlx *mlx)
{
	char			*addr;
	unsigned int	color;
	unsigned int	x;
	unsigned int	y;
	
	addr = mlx->img.addr[0];
	y = 0;
	while (y < 63)
	{
		x = 0;
		while (x < 64)
		{
			color = *((unsigned int *)addr + y * 64 + x);
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_mlx_img(t_mlx *mlx)
{
	ft_mlx_xpm_file_to_image(mlx, 64, 64);
	ft_mlx_get_data_addr(mlx, 32, 256, 0);
	// ft_print_addr(mlx);
}
