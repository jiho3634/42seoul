/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:11:40 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_tok_is_cmd(t_mini *mini, t_lst *lst, int i)
{
	lst->cmd = (char **)ft_calloc(mini, 2, sizeof(char *));
	lst->cmd[0] = mini->tok.arr[i];
	mini->tok.arr[i] = NULL;
}

int	ft_tok_is_arg(t_mini *mini, t_lst *lst, int i)
{
	char	**temp;
	int		j;

	temp = (char **)ft_calloc(mini, (sizeof(lst) + 2), sizeof(char *));
	j = -1;
	while (lst->cmd[++j])
		temp[j] = lst->cmd[j];
	free(lst->cmd);
	temp[j] = mini->tok.arr[i];
	mini->tok.arr[i] = NULL;
	lst->cmd = temp;
	return (1);
}

void	ft_add_to_cmd(t_mini *mini, t_lst *lst, int i)
{
	if (!lst->cmd)
		ft_tok_is_cmd(mini, lst, i);
	else
		ft_tok_is_arg(mini, lst, i);
}

void	ft_add_to_red(t_mini *mini, t_lst *lst, int i, int type)
{
	t_red	*red;

	if (type == INPUT || type == HEREDOC)
	{
		red = ft_red_last(lst->red_in);
		if (!red)
			lst->red_in = ft_red_new(mini, mini->tok.arr, i, type);
		else
			red->next = ft_red_new(mini, mini->tok.arr, i, type);
	}
	else if (type == OUTPUT || type == APPEND)
	{
		red = ft_red_last(lst->red_out);
		if (!red)
			lst->red_out = ft_red_new(mini, mini ->tok.arr, i, type);
		else
			red->next = ft_red_new(mini, mini->tok.arr, i, type);
	}
	free(mini->tok.arr[i]);
}
