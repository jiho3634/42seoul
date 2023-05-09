/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@42seoul.fr>              +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:24:45 by jihokim2          #+#    #+#             */
/*   Updated: 2023/04/28 17:52:22 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	array_set(char *arr)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		arr[i] = 0;
		i++;
	}
	return ;
}

void	binary_array(int div, char *arr)
{
	int		i;

	if (div < 0)
		arr[0] = 1;
	i = 7;
	while (div)
	{
		if (div % 2 == 0)
			arr[i] = 0;
		else if (div % 2 == 1)
			arr[i] = 1;
		div = div / 2;
		i--;
	}
	return ;
}

int	ft_atoi(char *ptr)
{
	int	pid;

	pid = 0;
	while (*ptr)
	{
		pid = pid * 10 + (*ptr - '0');
		ptr += 1;
	}
	return (pid);
}

void	translation(int pid, char *arr)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (arr[i] == 0)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else if (arr[i] == 1)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int		i;
	char	arr[8];

	if (argc != 3)
		return (0);
	i = 0;
	while (argv[2][i])
	{
		array_set(arr);
		binary_array(argv[2][i], arr);
		translation(ft_atoi(argv[1]), arr);
		i++;
	}
	return (0);
}
