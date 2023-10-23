/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/08 11:26:29 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_add_to_ev(t_mini *mini, char *cmd)
{
	char	**tmp;
	int		i;
	int		j;

	i = ft_arrlen(mini->envp);
	tmp = (char **)ft_calloc(mini, (i + 1) + 1, sizeof(char *));
	j = ft_strlen(cmd);
	tmp[i] = (char *)ft_calloc(mini, j + 1, sizeof(char));
	while (--j >= 0)
		tmp[i][j] = cmd[j];
	while (--i >= 0)
		tmp[i] = mini->envp[i];
	free(mini->envp);
	mini->envp = tmp;
}

int	ft_is_cmd_valid(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[0] == '\0' || cmd[0] == '=' || (cmd[0] >= '0' && cmd[0] <= '9'))
		return (1);
	while (cmd[i] && cmd[i] != '=')
	{
		if (!((cmd[i] >= 'a' && cmd[i] <= 'z') || \
			(cmd[i] >= 'A' && cmd[i] <= 'Z') || \
			(cmd[i] >= '0' && cmd[i] <= '9')))
			return (1);
		i++;
	}
	if (cmd[i] == '\0')
		return (2);
	return (0);
}

int	ft_envcmp(t_mini *mini, char *cmd, int i)
{
	int	j;

	j = 0;
	while (mini->envp[i][j] == cmd[j] && \
			mini->envp[i][j] != '=' && \
						cmd[j] != '=')
		j++;
	if (mini->envp[i][j] == '=' && (cmd[j] == '=' || cmd[j] == '\0'))
		return (TRUE);
	return (FALSE);
}

int	ft_find_env_export(t_mini *mini, char *cmd)
{
	int	i;

	i = -1;
	while (mini->envp[++i])
	{
		if (ft_envcmp(mini, cmd, i) == TRUE)
		{
			free(mini->envp[i]);
			ft_strcpy(mini, &mini->envp[i], cmd, ft_strlen(cmd));
			return (TRUE);
		}
	}
	return (FALSE);
}

int	ft_built_in_export(t_mini *mini, t_lst *lst)
{
	int	i;
	int	valid;

	i = 0;
	while (lst->cmd[++i])
	{
		valid = ft_is_cmd_valid(lst->cmd[i]);
		if (valid == 1)
		{
			ft_err_msg(lst->cmd[0], lst->cmd[i], "not a valid identifier", 1);
			continue ;
		}
		else if (valid == 2)
			continue ;
		else
		{
			if (ft_find_env_export(mini, lst->cmd[i]) == FALSE)
				ft_add_to_ev(mini, lst->cmd[i]);
			g_global = 0;
		}
	}
	return (0);
}
