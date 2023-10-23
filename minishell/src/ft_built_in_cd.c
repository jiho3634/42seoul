/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/08 11:23:54 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_copy_and_change_tilde(t_mini *mini, char **cmd, int i)
{
	char	*home;
	char	*temp;
	int		j;
	int		k;
	int		l;

	home = getenv("HOME");
	temp = (char *) \
		ft_calloc(mini, ft_strlen(cmd[1]) + ft_strlen(home), sizeof(char));
	j = -1;
	while (++j < i)
		temp[j] = cmd[1][j];
	k = -1;
	while (++k < ft_strlen(home))
		temp[j + k] = home[k];
	l = -1;
	while (cmd[1][i + (++l) + 1])
		temp[j + k + l] = cmd[1][i + l + 1];
	free(cmd[1]);
	cmd[1] = temp;
}

void	ft_tilde(t_mini *mini, char **cmd)
{
	int	i;

	i = 0;
	while (cmd[1][i])
	{
		if (cmd[1][i] == '~' && cmd[1][i + 1] != '~')
		{
			if (!(cmd[1][i + 1] == '\0' || cmd[1][i + 1] == '/'))
				return ;
			ft_copy_and_change_tilde(mini, cmd, i);
			return ;
		}
		i++;
	}
	return ;
}

int	ft_home(t_mini *mini)
{
	char	*home;

	home = ft_getenv(mini, "HOME");
	if (!home)
	{
		ft_err_msg("cd", "HOME not set", 0, 1);
		return (1);
	}
	if (chdir(home) == -1)
	{
		free(home);
		g_global = 1;
		perror("mysh: cd: ");
		return (1);
	}
	free(home);
	return (0);
}

int	ft_is_dir(char *cmd)
{
	struct stat	filestat;
	int			ret;

	ret = stat(cmd, &filestat);
	if (ret == -1)
	{
		if (errno == ENOENT)
			return (3);
	}
	else if (ret == 0)
	{
		if (S_ISREG(filestat.st_mode))
			return (2);
		else if (S_ISDIR(filestat.st_mode))
			return (1);
	}
	return (ret);
}

int	ft_built_in_cd(t_mini *mini, t_lst *lst)
{
	char	path[1024];
	int		ret;

	ft_bzero(path, sizeof(path));
	if (!lst->cmd[1])
		return (ft_home(mini));
	else
	{
		ft_tilde(mini, lst->cmd);
		ret = ft_is_dir(lst->cmd[1]);
		if (ret == 1)
		{
			if (chdir(lst->cmd[1]) == -1)
				perror("mysh: chdir: ");
			else
				g_global = 0;
		}
		else if (ret == 2)
			ft_err_msg(lst->cmd[0], lst->cmd[1], "Not a directory", 1);
		else if (ret == 3)
			ft_err_msg(lst->cmd[0], NULL, "No such file or directory", 1);
		else if (ret == -1)
			perror("mysh: cd");
	}
	return (0);
}
