/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/07 19:55:26 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_alive_philo(t_philo *philo)
{
	int	temp;

	pthread_mutex_lock(&(philo -> arg)-> alive_mutex);
	temp = (philo -> arg)-> alive_philo;
	pthread_mutex_unlock(&(philo -> arg)-> alive_mutex);
	return (temp);
}

void	ft_usleep(long long time)
{
	struct timeval	s_start;
	struct timeval	s_now;
	long long		start;
	long long		now;
	int				temp;

	gettimeofday(&s_start, NULL);
	start = (s_start.tv_sec * 1000) + (s_start.tv_usec / 1000);
	temp = time * 1000;
	while (1)
	{
		temp /= 3;
		usleep(temp);
		gettimeofday(&s_now, NULL);
		now = (s_now.tv_sec * 1000) + (s_now.tv_usec / 1000);
		if (now - start >= time)
			return ;
	}
}

void	eating_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo -> lfork);
	print(philo, "has taken a fork\n");
	pthread_mutex_lock(philo -> rfork);
	print(philo, "has taken a fork\n");
	get_ate(philo);
	print(philo, "is eating\n");
	ft_usleep(philo -> t_eat);
	pthread_mutex_unlock(philo -> rfork);
	pthread_mutex_unlock(&philo -> lfork);
}

void	eating_even(t_philo *philo)
{
	pthread_mutex_lock(philo -> rfork);
	print(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo -> lfork);
	print(philo, "has taken a fork\n");
	get_ate(philo);
	print(philo, "is eating\n");
	ft_usleep(philo -> t_eat);
	pthread_mutex_unlock(&philo -> lfork);
	pthread_mutex_unlock(philo -> rfork);
}
