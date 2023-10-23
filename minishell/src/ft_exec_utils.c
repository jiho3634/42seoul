/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/08 11:50:40 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_split(t_mini *mini, char *path, int j)
{
	int		i;

	if (!path)
		return ;
	if (!path[0])
		mini->split = (char **)ft_calloc(mini, (j + 1), sizeof(char *));
	i = -1;
	while (path[++i])
	{
		if (path[i] == ':' || !path[i + 1])
		{
			ft_split(mini, &path[i] + 1, j + 1);
			if (!path[i + 1])
				i++;
			mini->split[j] = (char *)ft_calloc(mini, i + 1, sizeof(char));
			while (--i >= 0)
				mini->split[j][i] = path[i];
			break ;
		}
	}
}

char	*ft_strjoin(t_mini *mini, char *path, char *cmd)
{
	int		path_len;
	int		cmd_len;
	char	*temp;

	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	temp = (char *)ft_calloc(mini, (path_len + 1 + cmd_len + 1), sizeof(char));
	while (--cmd_len >= 0)
		temp[path_len + 1 + cmd_len] = cmd[cmd_len];
	temp[path_len] = '/';
	while (--path_len >= 0)
		temp[path_len] = path[path_len];
	return (temp);
}

void	ft_set_path(t_mini *mini, t_lst *lst)
{
	char	*path;
	char	*tmp;
	int		i;

	path = ft_getenv(mini, "PATH");
	ft_split(mini, path, 0);
	lst->path = mini->split;
	mini->split = 0;
	if (!lst->path)
		return ;
	i = -1;
	while (lst->path[++i])
	{
		tmp = ft_strjoin(mini, lst->path[i], lst->cmd[0]);
		free(lst->path[i]);
		lst->path[i] = tmp;
	}
}
