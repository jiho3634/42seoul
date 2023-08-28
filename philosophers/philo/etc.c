/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/23 11:32:34 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_ate(t_philo *philo)
{
	struct timeval	temp;

	pthread_mutex_lock(&philo -> ate_mutex);
	gettimeofday(&temp, NULL);
	philo -> ate_time = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	pthread_mutex_unlock(&philo -> ate_mutex);
}

void	decrease_alive_philo(t_philo *philo)
{
	pthread_mutex_lock(&(philo -> share)-> alive_mutex);
	if ((philo -> share)-> alive_number != 0)
		(philo -> share)-> alive_number--;
	pthread_mutex_unlock(&(philo -> share)-> alive_mutex);
}

void	i_am_full(t_philo *philo)
{
	pthread_mutex_lock(&philo -> full_mutex);
	philo -> full = 0;
	pthread_mutex_unlock(&philo -> full_mutex);
}

int	check_alive_philo(t_philo *philo)
{
	unsigned int	temp;

	pthread_mutex_lock(&(philo -> share)-> alive_mutex);
	temp = (philo -> share)-> alive_number;
	pthread_mutex_unlock(&(philo -> share)-> alive_mutex);
	return (temp);
}

void	ft_usleep(t_philo *philo, unsigned int time)
{
	struct timeval	s_start;
	struct timeval	s_now;
	unsigned int	start;
	unsigned int	now;
	unsigned int	temp;

	gettimeofday(&s_start, NULL);
	start = (s_start.tv_sec * 1000) + (s_start.tv_usec / 1000);
	if (time > philo -> t_die)
		temp = philo -> t_die * 1000;
	else
		temp = time * 1000;
	while (1)
	{
		temp /= 2;
		usleep(temp);
		gettimeofday(&s_now, NULL);
		now = (s_now.tv_sec * 1000) + (s_now.tv_usec / 1000);
		if (now - start >= time || now - start >= philo -> t_die)
			return ;
	}
}
