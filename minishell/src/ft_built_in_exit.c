/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_is_num(char *cmd)
{
	int		i;

	if (!cmd)
		return (1);
	i = -1;
	if (cmd[0] == '-' || cmd[0] == '+')
		i++;
	while (cmd[++i])
	{
		if (cmd[i] < '0' || cmd[i] > '9')
			return (0);
	}
	return (1);
}

int	ft_built_in_exit(t_mini *mini, t_lst *lst)
{
	if (lst && !ft_is_num(lst->cmd[1]))
	{
		g_global = 127 + 128;
		write(1, "exit\n", 5);
		ft_error_exit(mini, "exit", lst->cmd[1], "numeric argument required");
		exit (g_global);
	}
	else if (lst && lst->cmd[1] && lst->cmd[2])
	{
		write(1, "exit\n", 5);
		ft_err_msg("exit", 0, "too many arguments", 1);
		return (1);
	}
	else if (lst && lst->cmd[1] && !lst->cmd[2])
	{
		g_global = ft_atoi(lst->cmd[1]);
		write(1, "exit\n", 5);
		exit(g_global);
	}
	g_global = 0;
	write(1, "exit\n", 5);
	exit(g_global);
}
