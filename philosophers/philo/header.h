/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:43:57 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/21 12:00:11 by jihokim2         ###   ########.fr       */
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
	unsigned int	philo_number;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	must_eat;
}	t_arg;

typedef struct s_share
{
	unsigned int	alive_number;
	pthread_mutex_t	alive_mutex;
	pthread_mutex_t	print_mutex;
}	t_share;

typedef struct s_philo
{
	unsigned int	philo_number;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	must_eat;
	unsigned int	name;
	unsigned int	full;
	t_share			*share;
	unsigned int	start_time;
	unsigned int	ate_time;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	ate_mutex;
	pthread_mutex_t	full_mutex;
}	t_philo;

int		init(char **argv, t_philo **philo, t_share *share);
int		thread_init(t_philo *philo);
int		threads_join(t_philo *philo);
void	*routine_odd(void *void_philo);
void	*routine_even(void *void_philo);
void	eating_odd(t_philo *philo);
void	eating_even(t_philo *philo);
int		monitoring(t_philo *philo);
void	print(t_philo *philo, char *str);
void	print_died(t_philo *philo, char *str);
int		error(t_philo *philo, int n);
int		ft_strlen(char *str);
int		ft_atoi(unsigned int *value, const char *str);
char	*ft_itoa(int n);
void	ft_usleep(t_philo *philo, unsigned int time);
void	decrease_alive_philo(t_philo *philo);
void	get_ate(t_philo *philo);
int		check_alive_philo(t_philo *philo);
void	i_am_full(t_philo *philo);

#endif
