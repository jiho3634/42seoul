/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:01:42 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 17:56:04 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_red(t_red *red)
{
	t_red	*temp;

	if (red)
	{
		temp = red;
		while (red)
		{
			if (red->type == HEREDOC)
			{
				unlink(red->doc_no);
				if (red->doc_no)
					ft_free((void *)&red->doc_no);
			}
			red = red->next;
		}
		red = temp;
		while (red)
		{
			if (red->file)
				free(red->file);
			temp = red->next;
			free(red);
			red = temp;
		}
	}
}

void	ft_free_lst(t_mini *mini)
{
	t_lst	*lst;
	t_lst	*temp;

	if (mini->lst)
	{
		lst = mini->lst;
		while (lst)
		{
			ft_free_arr(lst->cmd);
			ft_free_arr(lst->path);
			ft_free_red(lst->red_in);
			ft_free_red(lst->red_out);
			temp = lst->next;
			free(lst);
			lst = temp;
		}
		mini->lst = 0;
	}
}

void	ft_free_env(t_mini *mini)
{
	if (mini->env.temp)
		free(mini->env.temp);
	if (mini->env.env_ptr)
		free(mini->env.env_ptr);
	ft_bzero(&(mini->env), sizeof(t_env));
}

int	ft_reset(t_mini *mini)
{
	if (mini->line)
		free(mini->line);
	mini->line = NULL;
	ft_free_env(mini);
	ft_free_lst(mini);
	return (1);
}
