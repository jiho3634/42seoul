/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:25:41 by sanglee2          #+#    #+#             */
/*   Updated: 2023/10/06 16:57:13 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_env(t_mini *mini, t_lst *lst)
{
	while (lst)
	{
		if (ft_check_that_this_lst_is_empty_for_pipe(lst) == TRUE)
			return (FALSE);
		ft_exp_cmd(mini, mini->lst, -1);
		ft_find_closed_quote(mini, lst);
		ft_find_closed_quote_red(mini, lst->red_in);
		ft_find_closed_quote_red(mini, lst->red_out);
		lst = lst->next;
	}
	return (TRUE);
}

int	ft_arrlen(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
