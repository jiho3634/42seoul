/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/04 16:47:22 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	int_init(t_philo **philo, t_arg *arg, int i)
{
	(*philo)[i].arg = arg;
	(*philo)[i].name = i + 1;
	(*philo)[i].t_die = arg -> t_die ;
	(*philo)[i].t_eat = arg -> t_eat;
	(*philo)[i].t_sleep = arg -> t_sleep;
	(*philo)[i].must_eat = arg -> must_eat;
	(*philo)[i].full = 1;
}

static void	mutex_init(t_philo **philo, int i)
{
	pthread_mutex_init(&(*philo)[i].lfork, NULL);
	pthread_mutex_init(&(*philo)[i].ate_mutex, NULL);
	pthread_mutex_init(&(*philo)[i].live_mutex, NULL);
}

static int	philo_init(t_philo **philo, t_arg *arg, int i)
{
	*philo = (t_philo *)malloc(sizeof(t_philo) * (arg -> number));
	if (*philo == 0)
		return (error(0, 4));
	while (++i < arg -> number)
	{
		int_init(philo, arg, i);
		mutex_init(philo, i);
		if (arg -> number == 1)
		{
			(*philo)[i].rfork = &(*philo)[i].lfork;
			break ;
		}
		(*philo)[i].rfork = &(*philo)[(i + 1) % arg -> number].lfork;
	}
	return (1);
}

static int	arg_init(char **argv, t_arg *arg)
{
	if (!ft_atoi(&(arg -> number), argv[1]))
		return (error(0, 2));
	if (!ft_atoi(&(arg -> t_die), argv[2]))
		return (error(0, 2));
	if (!ft_atoi(&(arg -> t_eat), argv[3]))
		return (error(0, 2));
	if (!ft_atoi(&(arg -> t_sleep), argv[4]))
		return (error(0, 2));
	if (!ft_atoi(&(arg -> must_eat), argv[5]))
		return (error(0, 2));
	arg -> alive_philo = arg -> number;
	pthread_mutex_init(&arg -> print_mutex, NULL);
	pthread_mutex_init(&arg -> alive_mutex, NULL);
	return (1);
}

int	init(char **argv, t_philo **philo, t_arg *arg)
{
	if (!arg_init(argv, arg))
		return (error(0, 3));
	if (!philo_init(philo, arg, -1))
		return (error(0, 5));
	thread_init(*philo, arg);
	return (1);
}
