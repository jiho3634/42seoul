/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/07 19:55:26 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_now_thread(t_philo *philo)
{
	int	now;

	gettimeofday(&(philo -> now_thread), NULL);
	now = ((philo -> now_thread).tv_sec * 1000) + \
			((philo -> now_thread).tv_usec / 1000);
	return (now);
}

static int	get_stamp(t_philo *philo)
{
	int	now;
	int	stamp;

	now = get_now_thread(philo);
	stamp = now - philo -> start;
	return (stamp);
}

void	print(t_philo *philo, char *str)
{
	int		i_stamp;
	char	*a_stamp;
	char	*a_name;

	if (!check_alive_philo(philo))
		return ;
	pthread_mutex_lock(&(philo -> arg)-> print_mutex);
	i_stamp = get_stamp(philo);
	a_stamp = ft_itoa(i_stamp);
	a_name = ft_itoa(philo -> name);
	write(1, a_stamp, ft_strlen(a_stamp));
	write(1, " ", 1);
	write(1, a_name, ft_strlen(a_name));
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&(philo -> arg)-> print_mutex);
	free(a_stamp);
	free(a_name);
}

void	print_died(t_philo *philo, char *str)
{
	int		i_stamp;
	char	*a_stamp;
	char	*a_name;

	pthread_mutex_lock(&(philo -> arg)-> print_mutex);
	i_stamp = get_stamp(philo);
	a_stamp = ft_itoa(i_stamp);
	a_name = ft_itoa(philo -> name);
	write(1, a_stamp, ft_strlen(a_stamp));
	write(1, " ", 1);
	write(1, a_name, ft_strlen(a_name));
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&(philo -> arg)-> print_mutex);
	free(a_stamp);
	free(a_name);
}
