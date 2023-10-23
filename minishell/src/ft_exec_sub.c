/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/06 17:26:28 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_fork(t_mini *mini, t_lst *lst)
{
	ft_signal(SIGINT, ft_handler_nl);
	ft_signal(SIGQUIT, ft_handler_sigquit);
	lst->pid = fork();
	if (!lst->pid)
	{
		ft_signal(SIGQUIT, SIG_DFL);
		ft_signal(SIGINT, SIG_DFL);
		ft_set_pipe(mini, lst);
		ft_set_fd(mini, lst);
		if (lst->cmd)
			lst->num = ft_is_built_in(lst->cmd[0]);
		if (!lst->num)
			ft_execve(mini, lst);
		else
			ft_exec_built_in(mini, lst);
	}
}

int	ft_is_single_cd_export_unset_exit(t_mini *mini)
{
	if (ft_lst_size(mini->lst) == 1 && mini->lst->cmd)
	{
		if (ft_is_built_in(mini->lst->cmd[0]) == CD || \
			ft_is_built_in(mini->lst->cmd[0]) == EXPORT || \
			ft_is_built_in(mini->lst->cmd[0]) == UNSET || \
			ft_is_built_in(mini->lst->cmd[0]) == EXIT)
			return (TRUE);
	}
	return (FALSE);
}

void	ft_cd_export_unset_exit_in_parent_process(t_mini *mini)
{
	if (ft_is_built_in(mini->lst->cmd[0]) == CD)
		ft_built_in_cd(mini, mini->lst);
	if (ft_is_built_in(mini->lst->cmd[0]) == EXPORT)
		ft_built_in_export(mini, mini->lst);
	if (ft_is_built_in(mini->lst->cmd[0]) == UNSET)
		ft_built_in_unset(mini, mini->lst);
	if (ft_is_built_in(mini->lst->cmd[0]) == EXIT)
		ft_built_in_exit(mini, mini->lst);
}

void	ft_close_pipe(t_lst *lst)
{
	while (lst && lst->next)
	{
		close(lst->bpip[0]);
		close(lst->bpip[1]);
		lst = lst->next;
	}
}

void	ft_waitpid(t_lst *lst)
{
	int		status;

	while (lst)
	{
		waitpid(lst->pid, &status, 0);
		if (WIFEXITED(status) == TRUE)
			g_global = WEXITSTATUS(status);
		else if (WIFSIGNALED(status) == TRUE)
			g_global = WTERMSIG(status) + 128;
		if (WEXITSTATUS(status) == 255 && ft_strcmp(lst->cmd[0], "exit"))
			printf("mysh exit: %s : numeric argument required\n", lst->cmd[1]);
		lst = lst->next;
	}
	if (WIFSIGNALED(status) == TRUE)
	{
		if (WTERMSIG(status) == 3)
			printf("Quit: %d\n", WTERMSIG(status));
	}
}
