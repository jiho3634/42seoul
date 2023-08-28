/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/23 11:50:49 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	eating_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo -> left_fork);
	print(philo, "has taken a fork\n");
	pthread_mutex_lock(philo -> right_fork);
	print(philo, "has taken a fork\n");
	get_ate(philo);
	print(philo, "is eating\n");
	ft_usleep(philo, philo -> t_eat);
	pthread_mutex_unlock(philo -> right_fork);
	pthread_mutex_unlock(&philo -> left_fork);
}

void	eating_even(t_philo *philo)
{
	pthread_mutex_lock(philo -> right_fork);
	print(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo -> left_fork);
	print(philo, "has taken a fork\n");
	get_ate(philo);
	print(philo, "is eating\n");
	ft_usleep(philo, philo -> t_eat);
	pthread_mutex_unlock(&philo -> left_fork);
	pthread_mutex_unlock(philo -> right_fork);
}

void	*routine_odd(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	get_ate(philo);
	while (philo -> must_eat--)
	{
		eating_odd(philo);
		print(philo, "is sleeping\n");
		ft_usleep(philo, philo -> t_sleep);
		print(philo, "is thinking\n");
		if (philo -> philo_number % 2 == 1)
			ft_usleep(philo, philo -> t_eat);
		if (!check_alive_philo(philo))
			return (NULL);
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
	print(philo, "is thinking\n");
	ft_usleep(philo, philo -> t_eat);
	while (philo -> must_eat--)
	{
		eating_even(philo);
		print(philo, "is sleeping\n");
		ft_usleep(philo, philo -> t_sleep);
		print(philo, "is thinking\n");
		if (philo -> philo_number % 2 == 1)
			ft_usleep(philo, philo -> t_eat);
		if (!check_alive_philo(philo))
			return (NULL);
	}
	decrease_alive_philo(philo);
	i_am_full(philo);
	return (NULL);
}
