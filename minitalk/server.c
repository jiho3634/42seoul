/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:20:56 by jihokim2          #+#    #+#             */
/*   Updated: 2023/04/28 17:47:18 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

char	g_letter;

void	ft_itoa(pid_t temp)
{
	char	pid[5];
	int		i;

	i = 0;
	while (i <= 4)
	{
		pid[i] = temp % 10 + '0';
		temp /= 10;
		i++;
	}
	while (i >= 0)
	{
		write(1, &pid[i], 1);
		i--;
	}
	write(1, "\n", 1);
	return ;
}

void	handler(int sig)
{
	if (sig == 30)
		g_letter = g_letter << 1;
	else if (sig == 31)
	{
		g_letter = g_letter << 1;
		g_letter = g_letter | 1;
	}
}

int	main(void)
{
	int		i;

	ft_itoa(getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	i = 0;
	while (1)
	{
		pause ();
		i++;
		if (i == 8)
		{
			write(1, &g_letter, 1);
			g_letter = 0;
			i = 0;
		}
	}
	return (0);
}
