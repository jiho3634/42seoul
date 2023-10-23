/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/06 15:39:14 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_syntax_error(t_mini *mini, char *msg, char *c)
{
	write(2, "mysh: ", 6);
	write(2, msg, ft_strlen(msg));
	write (2, " \'", 2);
	write(2, c, ft_strlen(c));
	write(2, "\'\n", 2);
	ft_reset(mini);
	g_global = 258;
	return (1);
}

void	ft_err_msg(char *cmd, char *msg1, char *msg2, int err)
{
	if (cmd)
	{
		write(2, "mysh: ", 6);
		write(2, cmd, ft_strlen(cmd));
	}
	if (msg1)
	{
		write(2, ": ", 2);
		write(2, msg1, ft_strlen(msg1));
	}
	if (msg2)
	{
		write(2, ": ", 2);
		write(2, msg2, ft_strlen(msg2));
	}
	write(2, "\n", 1);
	if (err)
		g_global = err;
}

void	ft_error_exit(t_mini *mini, char *cmd, char *msg1, char *msg2)
{
	(void)mini;
	if (cmd || msg1 || msg2)
		ft_err_msg(cmd, msg1, msg2, 0);
	ft_reset(mini);
	exit(g_global);
}

void	ft_free(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	ft_free_arr(char **arr)
{
	int		i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			if (arr[i])
			{
				free(arr[i]);
				arr[i] = NULL;
			}
			i++;
		}
		free(arr);
	}
}
