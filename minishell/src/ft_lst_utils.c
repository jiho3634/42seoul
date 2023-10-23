/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:11:40 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_lst_size(t_lst *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_lst	*ft_lst_new(t_mini *mini)
{
	t_lst	*new;

	new = (t_lst *)ft_calloc(mini, 1, sizeof(t_lst));
	return (new);
}

t_lst	*ft_lst_last(t_lst *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_red	*ft_red_new(t_mini *mini, char **arr, int idx, int type)
{
	t_red	*new;
	int		i;

	i = 0;
	new = (t_red *)ft_calloc(mini, 1, sizeof(t_red));
	new->type = type;
	new->file = arr[idx + 1];
	return (new);
}

t_red	*ft_red_last(t_red *red)
{
	if (red == 0)
		return (0);
	while (red->next)
		red = red->next;
	return (red);
}
