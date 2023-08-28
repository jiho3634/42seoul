/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/21 12:01:33 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	threads_join(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < philo[0].philo_number)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (error(philo, 9));
		i++;
	}
	return (1);
}

void	get_start_time(t_philo *philo)
{
	struct timeval	temp;
	unsigned int	start_time;
	unsigned int	i;

	gettimeofday(&temp, NULL);
	start_time = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	i = -1;
	while (++i < philo -> philo_number)
		philo[i].start_time = start_time;
}

int	thread_init(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	get_start_time(philo);
	while (i < philo[0].philo_number)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine_odd, &philo[i]))
			return (0);
		i += 2;
	}
	i = 1;
	while (i < philo[0].philo_number)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine_even, &philo[i]))
			return (0);
		i += 2;
	}
	return (1);
}
