#include "../inc/cub3d.h"

int	ft_linelen(char *line)
{
	int	len;

	len = 0;
	while (line[len])
		len++;
	return (len);
}

char	*ft_linecpy(t_mlx *mlx, char *line)
{
	char	*tmp;
	int		i;

	tmp = (char *)ft_calloc(mlx, ft_linelen(line) + 1, sizeof(char));
	i = -1;
	while (line[++i])
		tmp[i] = line[i];
	return (tmp);
}

int	ft_arrlen(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
