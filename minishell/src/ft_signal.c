/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:14:53 by sanglee2          #+#    #+#             */
/*   Updated: 2023/10/06 16:28:23 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_handler_nl(int sig)
{
	if (sig == SIGINT)
		printf("^C\n");
}

void	ft_handler_sigquit(int sig)
{
	if (sig == SIGQUIT)
		printf("^\\");
}

void	ft_handler_sigint(int sig)
{
	if (sig == SIGINT)
	{
		g_global = 1;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	ft_signal(int sig, void (*new_handler)(int))
{
	void	(*prev_handler)(int);

	prev_handler = signal(sig, new_handler);
	if (prev_handler == SIG_ERR)
	{
		perror("mysh: signal");
		g_global = errno;
		exit(g_global);
	}
}

void	ft_set_term(t_mini *mini)
{
	tcgetattr(STDIN_FILENO, &mini->original);
	mini->new = mini->original;
	mini->new.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &mini->new);
}
