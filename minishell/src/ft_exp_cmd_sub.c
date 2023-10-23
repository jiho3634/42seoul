/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_cmd_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:01:42 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_exp_dq(t_mini *mini, char **line, int flag, int j)
{
	while ((*line)[++j])
	{
		if (mini->env.flag == 0 && (*line)[j] == '$')
			flag = ft_exp_cp_val(mini, &mini->env, line, &j);
		else if (!mini->env.flag && ft_is_quote((*line)[j], mini->env.quote))
		{
			mini->env.quote = (*line)[j];
			mini->env.flag = 1;
			mini->env.first = j;
		}
		else if (mini->env.flag && ft_is_quote((*line)[j], mini->env.quote))
		{
			mini->env.second = j;
			if (mini->env.quote == '\"')
			{
				ft_exp_find_dollar(mini, &mini->env, line);
				j = mini->env.second;
			}
			mini->env.quote = 0;
			mini->env.flag = 0;
		}
	}
	return (flag);
}

void	ft_arr_to_arr(t_mini *mini, t_lst *lst, char **arr, int *idx)
{
	char	**temp;
	int		i;
	int		j;

	if (arr[0] == NULL)
	{
		ft_delete_str_in_arr(mini, &lst->cmd, *idx);
		(*idx)--;
		return ;
	}
	temp = (char **)ft_calloc(mini, \
		ft_arrlen(lst->cmd) + ft_arrlen(arr), sizeof(char *));
	i = -1;
	while (++i < *idx)
		temp[i] = lst->cmd[i];
	ft_free((void *)&lst->cmd[*idx]);
	j = -1;
	while (++j < ft_arrlen(arr))
		temp[*idx + j] = arr[j];
	while (lst->cmd[++i])
		temp[i + j - 1] = lst->cmd[i];
	ft_free((void *)&lst->cmd);
	lst->cmd = temp;
}
