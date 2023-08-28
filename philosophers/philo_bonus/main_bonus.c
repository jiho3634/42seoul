/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@studen.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:25:08 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/24 12:43:56 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	ft_error(t_philo *philo, int n)
{
	if (n == 1)
	{
		write(2, "argc error\n", 11);
		return (0);
	}
	if (n == 2)
		write(2, "atoi error\n", 11);
	if (n == 3)
		write(2, "pid malloc error\n", 17);
	if (n == 4)
		write(2, "fork error\n", 11);
	if (n == 5)
		write(2, "pthread_create error\n", 21);
	sem_close(philo -> fork_sem);
	sem_close(philo -> t_sem);
	sem_close(philo -> print_sem);
	sem_close(philo -> monitor_sem);
	if (philo -> pid)
		free(philo -> pid);
	return (0);
}

int	ft_init(char **argv, t_philo *philo)
{
	if (!ft_atoi(&(philo -> total), argv[1]))
		return (ft_error(philo, 1));
	if (!ft_atoi(&(philo -> t_die), argv[2]))
		return (ft_error(philo, 1));
	if (!ft_atoi(&(philo -> t_eat), argv[3]))
		return (ft_error(philo, 1));
	if (!ft_atoi(&(philo -> t_sleep), argv[4]))
		return (ft_error(philo, 1));
	if (!ft_atoi(&(philo -> must_eat), argv[5]))
		return (ft_error(philo, 1));
	philo -> name = 0;
	sem_unlink("f_sem");
	sem_unlink("t_sem");
	sem_unlink("p_sem");
	sem_unlink("m_sem");
	philo -> fork_sem = sem_open("f_sem", O_CREAT, 0644, philo -> total);
	philo -> t_sem = sem_open("t_sem", O_CREAT, 0644, (philo -> total + 1) / 2);
	philo -> print_sem = sem_open("p_sem", O_CREAT, 0644, 1);
	philo -> monitor_sem = sem_open("m_sem", O_CREAT, 0644, 1);
	return (1);
}

int	ft_wait_pid(t_philo *philo)
{
	unsigned int	i;
	int				status;

	i = 0;
	while (i < philo -> total)
	{
		waitpid(-1, &status, 0);
		if (status)
			return (0);
		i++;
	}
	return (1);
}

void	ft_kill_pid(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < philo -> total)
		kill(philo -> pid[i++], 9);
}

int	main(int argc, char **argv)
{
	t_philo			philo;

	if (argc != 5 && argc != 6)
		return (ft_error(&philo, 1));
	if (!ft_init(argv, &philo))
		return (0);
	if (!ft_fork(&philo))
		return (0);
	if (!ft_wait_pid(&philo))
		ft_kill_pid(&philo);
	return (ft_error(&philo, 0));
}
