/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:11:40 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_type_red(char *str)
{
	if (ft_strcmp(str, "<"))
		return (INPUT);
	else if (ft_strcmp(str, ">"))
		return (OUTPUT);
	else if (ft_strcmp(str, ">>"))
		return (APPEND);
	else if (ft_strcmp(str, "<<"))
		return (HEREDOC);
	else
		return (WORD);
}

int	ft_type(char *tok)
{
	int	type;

	if (*tok == '|')
		return (PIPE);
	type = ft_type_red(tok);
	if (type == WORD)
		return (WORD);
	else
		return (type);
}

void	ft_hub(t_mini *mini, t_lst **lst, int i, int type)
{
	if (type == PIPE)
	{
		(*lst)-> next = ft_lst_new(mini);
		(*lst) = (*lst)-> next;
		free(mini->tok.arr[i]);
	}
	else if (type == WORD)
		ft_add_to_cmd(mini, *lst, i);
	else
		ft_add_to_red(mini, *lst, i, type);
}

t_lst	*ft_lst_init(t_mini *mini)
{
	if (mini->lst)
		return (ft_lst_last(mini->lst));
	mini->lst = ft_lst_new(mini);
	return (mini->lst);
}

int	ft_lst(t_mini *mini)
{
	t_lst	*lst;
	int		type;
	int		i;

	lst = ft_lst_init(mini);
	i = -1;
	while (mini->tok.arr[++i])
	{
		type = ft_type(mini->tok.arr[i]);
		ft_hub(mini, &lst, i, type);
		if (type >= 3 && type <= 6)
			i++;
	}
	free(mini->tok.arr);
	mini->tok.arr = NULL;
	mini->lst_size = ft_lst_size(lst);
	return (0);
}
