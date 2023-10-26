#include "../inc/cub3d.h"

void	ft_free(char **mem)
{
	free(*mem);
	*mem = NULL;
}

void     ft_free_mlx(t_mlx *mlx)
{
   printf("ft_free_mlx\n");
   (void)mlx;
   exit(1);
}