/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fd_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/06 17:01:25 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_access_in(t_mini *mini, t_red *red, char *file)
{
	if (access(file, F_OK) == 0)
	{
		if (access(file, R_OK) == 0)
				red->fd = open(file, O_RDONLY, 0777);
		else
		{
			g_global = 1;
			ft_error_exit(mini, file, 0, "Permission denied");
		}
	}
	else
	{
		g_global = 1;
		ft_error_exit(mini, 0, file, "No such file or directory");
	}
}

void	ft_set_fd_in(t_mini *mini, t_red *red)
{
	int	fd;

	if (red == NULL)
		return ;
	fd = 0;
	while (red)
	{
		if (red->type == FT_ERROR)
			ft_error_exit(mini, 0, 0, 0);
		else if (red->type == HEREDOC)
			ft_access_in(mini, red, red->doc_no);
		else
			ft_access_in(mini, red, red->file);
		fd = red -> fd;
		if (red->next == NULL)
			break ;
		if (red->fd)
			close(red->fd);
		red = red->next;
	}
	if (fd)
		dup2(fd, STDIN_FILENO);
}

void	ft_access_out(t_mini *mini, t_red *red)
{
	if (access(red->file, F_OK) == 0 && access(red->file, W_OK) != 0)
	{
		g_global = 1;
		ft_error_exit(mini, red->file, 0, "Permission denied");
	}
	if (red->type == OUTPUT)
		red->fd = open(red->file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (red->type == APPEND)
		red->fd = open(red->file, O_CREAT | O_WRONLY | O_APPEND, 0777);
}

void	ft_set_fd_out(t_mini *mini, t_red *red)
{
	if (red == NULL)
		return ;
	while (red)
	{
		if (red->type == FT_ERROR)
			ft_error_exit(mini, 0, 0, 0);
		ft_access_out(mini, red);
		if (red->next == NULL)
			break ;
		close(red->fd);
		red = red->next;
	}
	dup2(red->fd, STDOUT_FILENO);
}
