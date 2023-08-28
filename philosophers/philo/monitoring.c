/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/21 12:27:11 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_full(t_philo *philo)
{
	unsigned int	temp;

	pthread_mutex_lock(&philo -> full_mutex);
	temp = philo -> full;
	pthread_mutex_unlock(&philo -> full_mutex);
	return (temp);
}

int	check_time(t_philo *philo)
{
	struct timeval	temp;
	unsigned int	past;
	unsigned int	now;

	gettimeofday(&temp, NULL);
	now = (temp.tv_sec * 1000) + temp.tv_usec / 1000;
	pthread_mutex_lock(&philo -> ate_mutex);
	if (philo -> ate_time == 0)
	{
		pthread_mutex_unlock(&philo -> ate_mutex);
		return (0);
	}
	past = (now - philo -> ate_time);
	pthread_mutex_unlock(&philo -> ate_mutex);
	return (past - philo -> t_die);
}

int	is_die(t_philo *philo)
{
	if (check_full(philo))
	{
		if (check_time(philo) > 0)
		{
			pthread_mutex_lock(&(philo -> share)-> alive_mutex);
			(philo -> share)-> alive_number = 0;
			pthread_mutex_unlock(&(philo -> share)-> alive_mutex);
			print_died(philo, "died\n");
			return (1);
		}
	}
	return (0);
}

int	monitoring(t_philo *philo)
{
	unsigned int	philo_number;
	unsigned int	i;

	philo_number = philo[0].philo_number;
	while (check_alive_philo(philo))
	{
		i = 0;
		while (i < philo_number)
		{
			if (is_die(&philo[i]))
				return (0);
			i++;
			usleep(100);
		}
	}
	return (1);
}
