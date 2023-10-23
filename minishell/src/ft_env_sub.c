/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:25:41 by sanglee2          #+#    #+#             */
/*   Updated: 2023/10/06 17:11:42 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_check_that_this_lst_is_empty_for_pipe(t_lst *lst)
{
	if (!(lst->cmd) && !(lst->red_in) && !(lst->red_out))
		return (TRUE);
	return (FALSE);
}

void	ft_exp_cmd(t_mini *mini, t_lst *lst, int i)
{
	while (lst)
	{
		i = -1;
		while (lst->cmd && lst->cmd[++i])
		{
			if (ft_exp_dq(mini, &lst->cmd[i], 0, -1) == 1)
			{
				if (lst->cmd[i][0] == '\0')
				{
					ft_delete_str_in_arr(mini, &lst->cmd, i--);
					continue ;
				}
				ft_tok(mini, lst->cmd[i], 0);
				ft_arr_to_arr(mini, lst, mini->tok.arr, &i);
				ft_free((void *)&mini->tok.arr);
				ft_bzero(&mini->tok, sizeof(t_tok));
			}
		}
		lst = lst->next;
	}
}

void	ft_space_only(t_red *red)
{
	int	i;

	i = -1;
	while ((red->file)[++i])
	{
		if (ft_is_space(red->file[i]) == 0)
			return ;
	}
	if (red->file[i] == '\0')
		ft_free((void *)&red->file);
	if (red->file == NULL)
	{
		red->type = FT_ERROR;
		printf("mysh: ambiguous redirect\n");
	}
}

void	ft_find_closed_quote_red(t_mini *mini, t_red *red)
{
	ft_bzero(&mini->env, sizeof(t_env));
	while (red)
	{
		mini->env.quote = 0;
		mini->env.flag = 0;
		ft_noname_red(mini, red, -1);
		ft_space_only(red);
		red = red->next;
	}
}

int	ft_find_closed_quote(t_mini *mini, t_lst *lst)
{
	int	i;
	int	j;

	if (!lst->cmd)
		return (FALSE);
	ft_bzero(&mini->env, sizeof(t_env));
	i = -1;
	while (lst->cmd[++i])
	{
		j = -1;
		mini->env.quote = 0;
		mini->env.flag = 0;
		while (lst->cmd[i][++j])
			ft_noname(mini, lst, i, &j);
	}
	return (TRUE);
}
