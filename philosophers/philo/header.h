/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:43:57 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/07 19:55:26 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_arg
{
	int				number;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	int				alive_philo;
	struct timeval	s_start;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	alive_mutex;
}	t_arg;

typedef struct s_philo
{
	pthread_t		thread;
	t_arg			*arg;
	int				name;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	int				start;
	int				ate;
	int				full;
	pthread_mutex_t	lfork;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	ate_mutex;
	pthread_mutex_t	live_mutex;
	struct timeval	s_ate;
	struct timeval	now_thread;
	struct timeval	now_monitor;
}	t_philo;

int		init(char **argv, t_philo **philo, t_arg *arg);
void	thread_init(t_philo *philo, t_arg *arg);
void	threads_join(t_philo *philo);
void	*routine_odd(void *void_philo);
void	*routine_even(void *void_philo);
void	eating_odd(t_philo *philo);
void	eating_even(t_philo *philo);
int		monitoring(t_philo *philo, int number);
void	print(t_philo *philo, char *str);
void	print_died(t_philo *philo, char *str);
void	get_ate(t_philo *philo);
int		check_alive_philo(t_philo *philo);
int		error(t_philo *philo, int n);
int		ft_strlen(char *str);
void	ft_usleep(long long time);
int		ft_atoi(int *value, const char *str);
char	*ft_itoa(int n);

#endif
