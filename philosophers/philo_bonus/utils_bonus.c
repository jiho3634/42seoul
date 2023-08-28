/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@studen.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:25:08 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/23 20:59:29 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_get_last_eat_time(t_philo *philo)
{
	struct timeval	temp;

	sem_wait(philo -> monitor_sem);
	gettimeofday(&temp, NULL);
	philo -> last_eat = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	sem_post(philo -> monitor_sem);
}

void	ft_usleep(t_philo *philo, unsigned int time)
{
	struct timeval	temp;
	unsigned int	start;
	unsigned int	now;
	unsigned int	tmp;

	gettimeofday(&temp, NULL);
	start = (temp.tv_sec * 1000) + (temp.tv_usec / 1000);
	if (time > philo -> t_die)
		tmp = philo -> t_die * 1000;
	else
		tmp = time * 1000;
	while (1)
	{
		tmp /= 3;
		usleep(tmp * 2);
		gettimeofday(&temp, NULL);
		now = temp.tv_sec * 1000 + temp.tv_usec / 1000;
		if (now - start >= time || now - start > philo -> t_die)
			return ;
	}
}

int	ft_get_stamp(t_philo *philo)
{
	struct timeval	temp;
	unsigned int	now;

	gettimeofday(&temp, NULL);
	now = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	return (now - philo -> start_time);
}

int	ft_print(t_philo *philo, char *str, int is_die)
{
	unsigned int	stamp;

	sem_wait(philo -> print_sem);
	stamp = ft_get_stamp(philo);
	printf("%u %d %s", stamp, philo -> name, str);
	if (is_die)
		return (1);
	sem_post(philo -> print_sem);
	return (0);
}

int	ft_atoi(unsigned int *value, const char *str)
{
	long long	answer;
	int			i;

	if (!str)
	{
		*value = -1;
		return (1);
	}
	i = 0;
	if (str[i] == '+')
		i++;
	if (!(str[i] >= '1' && str[i] <= '9'))
		return (0);
	answer = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		answer = answer * 10 + (str[i] - '0');
		i++;
	}
	if (!str[i] && !(i > 11 || answer > 2147483647 || answer < -2147483648))
	{
		*value = (unsigned int)answer;
		return (1);
	}
	return (0);
}
