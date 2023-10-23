/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/06 17:26:27 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_set_pipe(t_mini *mini, t_lst *lst)
{
	t_lst	*tmp;

	tmp = mini->lst;
	while (tmp != lst && tmp->next != lst)
	{
		close(tmp->bpip[0]);
		close(tmp->bpip[1]);
		tmp = tmp->next;
	}
	if (lst->fpip[1])
	{
		close(lst->fpip[1]);
		dup2(lst->fpip[0], STDIN_FILENO);
	}
	if (lst->bpip[0])
	{
		close(lst->bpip[0]);
		dup2(lst->bpip[1], STDOUT_FILENO);
	}
}

void	ft_set_fd(t_mini *mini, t_lst *lst)
{
	if (lst->red_in)
		ft_set_fd_in(mini, lst->red_in);
	if (lst->red_out)
		ft_set_fd_out(mini, lst->red_out);
}

int	ft_is_built_in(char *cmd)
{
	if (ft_strcmp(cmd, "echo") || ft_strcmp(cmd, "ECHO"))
		return (FT_ECHO);
	else if (ft_strcmp(cmd, "cd") || ft_strcmp(cmd, "CD"))
		return (CD);
	else if (ft_strcmp(cmd, "pwd") || ft_strcmp(cmd, "PWD"))
		return (PWD);
	else if (ft_strcmp(cmd, "export") || ft_strcmp(cmd, "EXPORT"))
		return (EXPORT);
	else if (ft_strcmp(cmd, "unset") || ft_strcmp(cmd, "UNSET"))
		return (UNSET);
	else if (ft_strcmp(cmd, "env") || ft_strcmp(cmd, "ENV"))
		return (ENV);
	else if (ft_strcmp(cmd, "exit") || ft_strcmp(cmd, "EXIT"))
		return (EXIT);
	else
		return (0);
}

void	ft_execve(t_mini *mini, t_lst *lst)
{
	if (!lst->cmd)
		exit(g_global);
	if (ft_strcmp(lst->cmd[0], ".") || ft_strcmp(lst->cmd[0], ".."))
	{
		ft_err_msg(lst->cmd[0], 0, "command not found", 127);
		exit(g_global);
	}
	if (ft_is_cmd_filename(lst -> cmd[0]))
		ft_execve_env_path(mini, lst, 0, -1);
	else
		ft_execve_absolute_path(lst, 0);
	exit(g_global);
}

void	ft_exec_built_in(t_mini *mini, t_lst *lst)
{
	int	err;

	err = 0;
	if (lst->num == FT_ECHO)
		ft_built_in_echo(lst);
	else if (lst->num == CD)
		exit(0);
	else if (lst->num == PWD)
		err = ft_built_in_pwd();
	else if (!mini->lst->next && lst->num == EXPORT)
		exit(0);
	else if (!mini->lst->next && lst->num == UNSET)
		exit(0);
	else if (lst->num == ENV)
		ft_built_in_env(mini);
	else if (lst->num == EXIT)
		exit(0);
	if (err)
		g_global = 1;
	exit(g_global);
}
