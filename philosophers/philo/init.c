/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/21 12:27:11 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	mutex_init(t_philo *philo)
{
	if (pthread_mutex_init(&philo -> left_fork, NULL))
		return (0);
	if (pthread_mutex_init(&philo -> ate_mutex, NULL))
		return (0);
	if (pthread_mutex_init(&philo -> full_mutex, NULL))
		return (0);
	return (1);
}

void	arg_copy(t_philo *philo, t_share *share, t_arg *arg, unsigned int i)
{
	philo -> philo_number = arg -> philo_number ;
	philo -> t_die = arg -> t_die ;
	philo -> t_eat = arg -> t_eat;
	philo -> t_sleep = arg -> t_sleep;
	philo -> must_eat = arg -> must_eat;
	philo -> name = i + 1;
	philo -> full = 1;
	philo -> share = share;
}

int	philo_init(t_philo **philo, t_share *share, t_arg *arg)
{
	unsigned int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * (arg -> philo_number));
	if (*philo == 0)
		return (error(0, 4));
	i = 0;
	while (i < arg -> philo_number)
	{
		arg_copy(&(*philo)[i], share, arg, i);
		if (!mutex_init(&(*philo)[i]))
			return (error(*philo, 5));
		(*philo)[i].right_fork = \
							&(*philo)[(i + 1) % arg -> philo_number].left_fork;
		i++;
	}
	return (1);
}

int	arg_and_share_init(char **argv, t_share *share, t_arg *arg)
{
	if (!ft_atoi(&(arg -> philo_number), argv[1]))
		return (error(0, 2));
	if (!ft_atoi(&(arg -> t_die), argv[2]))
		return (error(0, 2));
	if (!ft_atoi(&(arg -> t_eat), argv[3]))
		return (error(0, 2));
	if (!ft_atoi(&(arg -> t_sleep), argv[4]))
		return (error(0, 2));
	if (!ft_atoi(&(arg -> must_eat), argv[5]))
		return (error(0, 2));
	share -> alive_number = arg -> philo_number;
	if (pthread_mutex_init(&share -> print_mutex, NULL))
		return (error(0, 3));
	if (pthread_mutex_init(&share -> alive_mutex, NULL))
		return (error(0, 3));
	return (1);
}

int	init(char **argv, t_philo **philo, t_share *share)
{
	t_arg	arg;

	if (!arg_and_share_init(argv, share, &arg))
		return (0);
	if (!philo_init(philo, share, &arg))
		return (0);
	if (!thread_init(*philo))
		return (error(0, 6));
	return (1);
}
