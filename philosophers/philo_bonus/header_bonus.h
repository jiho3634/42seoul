/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@studen.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:25:08 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:29 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_philo
{
	unsigned int	total;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	must_eat;
	unsigned int	name;
	unsigned int	start_time;
	unsigned int	last_eat;
	pthread_t		monitor_thread;
	pid_t			*pid;
	sem_t			*fork_sem;
	sem_t			*t_sem;
	sem_t			*print_sem;
	sem_t			*monitor_sem;
	sem_t			*f_sem;
}	t_philo;

int		ft_error(t_philo *philo, int n);
int		ft_fork(t_philo *philo);
void	ft_kill_pid(t_philo *philo);
void	*ft_memset(void *b, int c, size_t len);
void	ft_get_last_eat_time(t_philo *philo);
void	ft_usleep(t_philo *philo, unsigned int time);
int		ft_get_stamp(t_philo *philo);
int		ft_print(t_philo *philo, char *str, int is_die);
int		ft_atoi(unsigned int *value, const char *str);

#endif
