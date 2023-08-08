/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/07 19:55:26 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_ate(t_philo *philo)
{
	pthread_mutex_lock(&philo -> ate_mutex);
	gettimeofday(&philo -> s_ate, NULL);
	philo -> ate = ((philo -> s_ate).tv_sec * 1000) + \
					((philo -> s_ate).tv_usec / 1000);
	pthread_mutex_unlock(&philo -> ate_mutex);
}

static void	decrease_alive_philo(t_philo *philo)
{
	pthread_mutex_lock(&(philo -> arg)-> alive_mutex);
	if ((philo -> arg)-> alive_philo != 0)
		(philo -> arg)-> alive_philo--;
	pthread_mutex_unlock(&(philo -> arg)-> alive_mutex);
}

static void	i_am_full(t_philo *philo)
{
	pthread_mutex_lock(&philo -> live_mutex);
	philo -> full = 0;
	pthread_mutex_unlock(&philo -> live_mutex);
}

void	*routine_odd(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	get_ate(philo);
	while (philo -> must_eat--)
	{
		if (!check_alive_philo(philo))
			return (NULL);
		eating_odd(philo);
		print(philo, "is sleeping\n");
		ft_usleep(philo -> t_sleep);
		print(philo, "is thinking\n");
		ft_usleep((philo -> t_die - philo -> t_eat - philo -> t_sleep) / 10);
	}
	decrease_alive_philo(philo);
	i_am_full(philo);
	return (NULL);
}

void	*routine_even(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	get_ate(philo);
	while (philo -> must_eat--)
	{
		print(philo, "is thinking\n");
		ft_usleep((philo -> t_die - philo -> t_eat - philo -> t_sleep) / 10);
		if (!check_alive_philo(philo))
			return (NULL);
		eating_even(philo);
		print(philo, "is sleeping\n");
		ft_usleep(philo -> t_sleep);
	}
	decrease_alive_philo(philo);
	i_am_full(philo);
	return (NULL);
}
