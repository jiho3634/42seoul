/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_close_quote_sub.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:25:41 by sanglee2          #+#    #+#             */
/*   Updated: 2023/10/06 16:28:10 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_noname(t_mini *mini, t_lst *lst, int i, int *j)
{
	if (!mini->env.flag && \
			ft_is_quote(lst->cmd[i][*j], mini->env.quote))
	{
		mini->env.quote = lst->cmd[i][*j];
		mini->env.flag = 1;
		mini->env.first = *j;
	}
	else if (mini->env.flag && \
			ft_is_quote(lst->cmd[i][*j], mini->env.quote))
	{
		mini->env.i = i;
		mini->env.second = *j;
		ft_delete_closed_quote(mini, lst);
		*j = *j - 2;
		mini->env.quote = 0;
		mini->env.flag = 0;
	}
}

void	ft_noname_red(t_mini *mini, t_red *red, int j)
{
	while (red->file[++j])
	{
		if (!mini->env.flag && red->file[j] == '$' && red->type != HEREDOC)
			ft_exp_cp_val(mini, &mini->env, &red->file, &j);
		else if (!mini->env.flag && ft_is_quote(red->file[j], mini->env.quote))
		{
			mini->env.quote = red->file[j];
			mini->env.flag = 1;
			mini->env.first = j;
		}
		else if (mini->env.flag && ft_is_quote(red->file[j], mini->env.quote))
		{
			mini->env.second = j;
			if (mini->env.quote == '\"' && red->type != HEREDOC)
			{
				ft_find_dollar_sign_red(mini, red);
				j = mini->env.second;
			}
			ft_delete_closed_quote_red(mini, red);
			j = j - 2;
			mini->env.quote = 0;
			mini->env.flag = 0;
		}
	}
}
