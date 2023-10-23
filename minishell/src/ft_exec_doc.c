/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/06 16:11:43 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strjoin_hd(t_mini *mini, char *path, char *cmd)
{
	int		path_len;
	int		cmd_len;
	char	*temp;

	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	temp = (char *)ft_calloc(mini, (path_len + cmd_len + 1), sizeof(char));
	while (--cmd_len >= 0)
		temp[path_len + cmd_len] = cmd[cmd_len];
	while (--path_len >= 0)
		temp[path_len] = path[path_len];
	return (temp);
}

void	ft_heredoc_child(t_mini *mini, t_red *red)
{
	ft_signal(SIGINT, SIG_DFL);
	while (1)
	{
		red->line = readline("> ");
		if (!red->line)
			break ;
		else if (ft_strcmp(red->file, red->line))
		{
			free(red->line);
			break ;
		}
		else
		{
			ft_exp_heredoc(mini, red);
			write(red->fd, red->line, ft_strlen(red->line));
			write(red->fd, "\n", 1);
			free(red->line);
		}
	}
	red->line = NULL;
	close(red->fd);
	exit(0);
}

int	ft_heredoc(t_mini *mini, t_red *red)
{
	pid_t	pid;
	int		status;

	red->fd = open(red->doc_no, O_CREAT | O_WRONLY | O_APPEND, 0777);
	ft_signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		ft_heredoc_child(mini, red);
	waitpid(pid, &status, 0);
	ft_signal(SIGINT, ft_handler_sigint);
	if (status == 2)
	{
		g_global = 1;
		return (status);
	}
	return (0);
}

int	ft_doc(t_mini *mini, t_red *red)
{
	char	*tmp;
	int		i;

	while (red)
	{
		if (red->type == HEREDOC)
		{
			i = INT32_MIN;
			while (i)
			{
				tmp = ft_set_itoa(mini, i);
				red->doc_no = ft_strjoin_hd(mini, ".", tmp);
				free(tmp);
				if (access(red->doc_no, F_OK) == -1)
					break ;
				free(red->doc_no);
				i++;
			}
			if (ft_heredoc(mini, red) == 2)
				return (g_global);
		}
		red = red->next;
	}
	return (0);
}
