/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:47:50 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_delete_closed_quote_red(t_mini *mini, t_red *lst)
{
	char	*temp;
	int		len;
	int		i;

	len = ft_strlen(lst->file) - 2;
	temp = (char *)ft_calloc(mini, len + 1, sizeof(char));
	i = -1;
	while (++i < mini->env.first)
		temp[i] = lst->file[i];
	while (i + 1 < mini->env.second)
	{
		temp[i] = lst->file[i + 1];
		i++;
	}
	while (i < len)
	{
		temp[i] = lst->file[i + 2];
		i++;
	}
	temp[i] = '\0';
	if (lst->file)
		free(lst->file);
	lst->file = temp;
	temp = 0;
}

void	ft_delete_closed_quote(t_mini *mini, t_lst *lst)
{
	char	*temp;
	int		len;
	int		j;

	len = ft_strlen(lst->cmd[mini->env.i]) - 2;
	temp = (char *)ft_calloc(mini, len + 1, sizeof(char));
	j = -1;
	while (++j < mini->env.first)
		temp[j] = lst->cmd[mini->env.i][j];
	while (j + 1 < mini->env.second)
	{
		temp[j] = lst->cmd[mini->env.i][j + 1];
		j++;
	}
	while (j < len)
	{
		temp[j] = lst->cmd[mini->env.i][j + 2];
		j++;
	}
	temp[j] = '\0';
	if (lst->cmd[mini->env.i])
		free(lst->cmd[mini->env.i]);
	lst->cmd[mini->env.i] = temp;
	temp = 0;
}
