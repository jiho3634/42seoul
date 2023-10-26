#include "../inc/cub3d.h"

void	ft_syntax_of_map(t_mlx *mlx, char *line)
{
	while (*line)
	{
		if (!(ft_is_space(*line) == TRUE || *line == '1' || *line == '0' \
			|| *line == 'N' || *line == 'S' || *line == 'W' || *line == 'E'))
			ft_free_mlx(mlx);
		line++;
	}
}

void	ft_add_line_to_arr(t_mlx *mlx)
{
	char	**tmp;
	int		i;

	if (mlx->map == NULL)
	{
		mlx->map = (char **)ft_calloc(mlx, 2, sizeof(char *));
		mlx->map[0] = ft_linecpy(mlx, mlx->data.line);
		mlx->map[1] = NULL;
	}
	else
	{
		i = ft_arrlen(mlx->map);
		tmp = (char **)ft_calloc(mlx, i + 2, sizeof(char *));
		i = -1;
		while (mlx->map[++i])
			tmp[i] = mlx->map[i];
		tmp[i] = ft_linecpy(mlx, mlx->data.line);
		free(mlx->map);
		mlx->map = tmp;
	}
}

int	ft_is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_space(line[i]) == TRUE)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

void	ft_get_map(t_mlx *mlx)
{
	while (1)
	{
		mlx->data.line = get_next_line(mlx->data.fd);
		if (mlx->data.line == NULL || mlx->data.line[0] == '\0')
			break;
		if (ft_is_empty_line(mlx->data.line) == TRUE)
		{
			ft_free(&mlx->data.line);	
			if (mlx->map)
				return ;
			continue ;
		}
		ft_syntax_of_map(mlx, mlx->data.line);
		ft_add_line_to_arr(mlx);
		ft_free(&mlx->data.line);
	}
}
