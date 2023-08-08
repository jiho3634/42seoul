/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/04 19:02:39 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	get_start_time(t_philo *philo, int number)
{
	int	temp;
	int	i;

	gettimeofday(&((philo -> arg)-> s_start), NULL);
	temp = (((philo -> arg)-> s_start).tv_sec * 1000) + \
					(((philo -> arg)-> s_start).tv_usec / 1000);
	i = -1;
	while (++i < number)
		philo[i].start = temp;
}

void	thread_init(t_philo *philo, t_arg *arg)
{
	int	i;
	int	number;

	number = arg -> number;
	i = 0;
	get_start_time(philo, number);
	while (i < number)
	{
		pthread_create(&philo[i].thread, NULL, &routine_odd, &philo[i]);
		i += 2;
	}
	i = 1;
	while (i < number)
	{
		pthread_create(&philo[i].thread, NULL, &routine_even, &philo[i]);
		i += 2;
	}
}

void	threads_join(t_philo *philo)
{
	int	i;
	int	number;

	number = philo[0].arg -> number;
	i = -1;
	while (++i < number)
		pthread_join(philo[i].thread, NULL);
}
