/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_delete_str_in_arr(t_mini *mini, char ***arr, int i)
{
	char	**tmp;
	int		len;

	len = ft_arrlen(*arr);
	if (len == 1 && i == 0)
	{
		ft_free((void *)&(*arr)[0]);
		ft_free((void *)&(*arr));
		return ;
	}
	tmp = (char **)ft_calloc(mini, len, sizeof(char *));
	len = -1;
	while (++len < i)
		tmp[len] = (*arr)[len];
	free((*arr)[len]);
	while ((*arr)[len + 1])
	{
		tmp[len] = (*arr)[len + 1];
		len++;
	}
	ft_free((void *)arr);
	(*arr) = tmp;
}

int	ft_find_env_unset(t_mini *mini, char *cmd)
{
	int	i;
	int	j;

	i = -1;
	while (mini->envp[++i])
	{
		j = 0;
		while (mini->envp[i][j] == cmd[j] && \
				cmd[j] && mini->envp[i][j] != '=')
			j++;
		if (mini->envp[i][j] == '=' && !cmd[j])
		{
			ft_delete_str_in_arr(mini, &(mini->envp), i);
			return (0);
		}
	}
	return (0);
}

int	ft_is_cmd_valid_unset(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[0] == '=')
		return (1);
	while (cmd[i])
	{
		if (cmd[i] == '=' || ft_is_space(cmd[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_built_in_unset(t_mini *mini, t_lst *lst)
{
	int	i;

	i = 0;
	while (lst->cmd[++i])
	{
		if (ft_is_cmd_valid_unset(lst->cmd[i]) == 1)
		{
			printf("mysh: unset: %s: ", lst->cmd[i]);
			printf("not a valid identifier\n");
			return (1);
		}
		if (ft_find_env_unset(mini, lst->cmd[i]))
			return (1);
	}
	g_global = 0;
	return (0);
}
