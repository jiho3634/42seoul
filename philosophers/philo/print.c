/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/11 21:32:03 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_stamp(t_philo *philo)
{
	struct timeval	temp;
	int				now;
	int				stamp;

	gettimeofday(&temp, NULL);
	now = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	stamp = now - philo -> start_time;
	return (stamp);
}

void	print(t_philo *philo, char *str)
{
	int		i_stamp;
	char	*a_stamp;
	char	*a_name;

	pthread_mutex_lock(&(philo -> share)-> print_mutex);
	i_stamp = get_stamp(philo);
	a_stamp = ft_itoa(i_stamp);
	a_name = ft_itoa(philo -> name);
	if (!check_alive_philo(philo))
	{
		pthread_mutex_unlock(&(philo -> share)-> print_mutex);
		free(a_stamp);
		free(a_name);
		return ;
	}
	write(1, a_stamp, ft_strlen(a_stamp));
	write(1, " ", 1);
	write(1, a_name, ft_strlen(a_name));
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&(philo -> share)-> print_mutex);
	free(a_stamp);
	free(a_name);
}

void	print_died(t_philo *philo, char *str)
{
	int		i_stamp;
	char	*a_stamp;
	char	*a_name;

	pthread_mutex_lock(&(philo -> share)-> print_mutex);
	i_stamp = get_stamp(philo);
	a_stamp = ft_itoa(i_stamp);
	a_name = ft_itoa(philo -> name);
	write(1, a_stamp, ft_strlen(a_stamp));
	write(1, " ", 1);
	write(1, a_name, ft_strlen(a_name));
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&(philo -> share)-> print_mutex);
	free(a_stamp);
	free(a_name);
}
