/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@studen.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:25:08 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/24 12:50:32 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	ft_is_die(t_philo *philo)
{
	struct timeval	temp;
	unsigned int	now;
	unsigned int	is_die;

	is_die = 0;
	gettimeofday(&temp, NULL);
	now = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	sem_wait(philo -> monitor_sem);
	is_die = (now - philo -> last_eat) > philo -> t_die;
	sem_post(philo -> monitor_sem);
	return (is_die);
}

void	*ft_monitor(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	while (!ft_is_die(philo))
		usleep(10000);
	exit(ft_print(philo, "died\n", 1));
}

void	ft_eat_sleep_think(t_philo *philo)
{
	sem_wait(philo -> t_sem);
	sem_wait(philo -> fork_sem);
	ft_print(philo, "has taken a fork\n", 0);
	sem_wait(philo -> fork_sem);
	ft_print(philo, "has taken a fork\n", 0);
	sem_post(philo -> t_sem);
	ft_get_last_eat_time(philo);
	ft_print(philo, "is eating\n", 0);
	ft_usleep(philo, philo -> t_eat);
	sem_post(philo -> fork_sem);
	sem_post(philo -> fork_sem);
	ft_print(philo, "is sleeping\n", 0);
	ft_usleep(philo, philo -> t_sleep);
	ft_print(philo, "is thinking\n", 0);
}

int	ft_routine(t_philo *philo)
{
	ft_get_last_eat_time(philo);
	if (pthread_create(&philo -> monitor_thread, NULL, ft_monitor, philo))
		return (ft_error(philo, 5));
	while (philo -> must_eat--)
		ft_eat_sleep_think(philo);
	return (0);
}

int	ft_fork(t_philo *philo)
{
	struct timeval	temp;

	philo -> pid = (pid_t *)malloc(sizeof(pid_t) * philo -> total);
	if (!philo -> pid)
		return (ft_error(philo, 3));
	gettimeofday(&temp, NULL);
	philo -> start_time = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	while (++philo -> name <= philo -> total)
	{
		philo -> pid[philo -> name - 1] = fork();
		if (!philo -> pid[philo -> name - 1])
			return (ft_routine(philo));
		else if (philo -> pid[philo -> name - 1] == -1)
		{
			ft_kill_pid(philo);
			return (ft_error(philo, 4));
		}
	}
	return (1);
}
