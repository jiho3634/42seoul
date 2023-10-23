/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/08 12:02:43 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_access(char *cmd, int *flag)
{
	if (!access(cmd, F_OK))
	{
		if (!access(cmd, X_OK))
			return (0);
		else
			*flag = 1;
	}
	return (-1);
}

int	ft_is_cmd_filename(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '/')
			return (0);
	}
	return (1);
}

void	ft_execve_absolute_path(t_lst *lst, int flag)
{
	int	ret;

	ret = ft_is_dir(lst->cmd[0]);
	if (ret == 1)
	{
		ft_err_msg(lst->cmd[0], NULL, "is a directory", 126);
		return ;
	}
	else if (ret == 2)
	{
		if (ft_access(lst->cmd[0], &flag) == 0)
		{
			if (execve(lst->cmd[0], lst->cmd, 0) == -1)
			{
				g_global = errno;
				perror("mysh: execve: ");
				exit(g_global);
			}
		}
	}
	if (flag == 1)
		ft_err_msg(lst->cmd[0], 0, "Permission denied", 126);
	else
		ft_err_msg(lst->cmd[0], 0, "No such file or directory", 127);
}	

void	ft_execve_env_path(t_mini *mini, t_lst *lst, int flag, int i)
{
	if (lst->cmd[0][0] != '\0')
	{
		ft_set_path(mini, lst);
		while (lst->path && lst->path[++i])
		{
			if (ft_access(lst->path[i], &flag) == 0)
			{
				if (execve(lst->path[i], lst->cmd, 0) == -1)
				{
					g_global = errno;
					perror("mysh: execve: ");
					exit(g_global);
				}
			}
		}
	}
	if (flag == 1)
		ft_err_msg(lst->cmd[0], 0, "Permission denied", 126);
	else if (lst->path == NULL && flag == 0)
		ft_err_msg(lst->cmd[0], 0, "No such file or directory", 127);
	else
		ft_err_msg(lst->cmd[0], 0, "command not found", 127);
}
