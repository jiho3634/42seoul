/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/07 19:55:26 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_full(t_philo *philo)
{
	int	temp;

	pthread_mutex_lock(&philo -> live_mutex);
	temp = philo -> full;
	pthread_mutex_unlock(&philo -> live_mutex);
	return (temp);
}

static int	check_past(t_philo *philo)
{
	int	past;
	int	now;

	gettimeofday(&(philo -> now_monitor), NULL);
	now = ((philo -> now_monitor).tv_sec * 1000) + \
			((philo -> now_monitor).tv_usec / 1000);
	pthread_mutex_lock(&philo -> ate_mutex);
	past = (now - philo -> ate);
	pthread_mutex_unlock(&philo -> ate_mutex);
	return (past - philo -> t_die);
}

static int	is_die(t_philo *philo)
{
	if (check_full(philo))
	{
		if (check_past(philo) > 0)
		{
			pthread_mutex_lock(&(philo -> arg)-> alive_mutex);
			(philo -> arg)-> alive_philo = 0;
			pthread_mutex_unlock(&(philo -> arg)-> alive_mutex);
			ft_usleep(5);
			print_died(philo, "died\n");
			return (1);
		}
	}
	return (0);
}

int	monitoring(t_philo *philo, int number)
{
	int	i;

	while (check_alive_philo(philo))
	{
		i = -1;
		while (++i < number)
		{
			if (is_die(&philo[i]))
				return (0);
		}
	}
	return (1);
}
