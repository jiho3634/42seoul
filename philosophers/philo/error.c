/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/11 21:27:34 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	error(t_philo *philo, int n)
{
	(void)philo;
	if (n == 0)
		write(2, "argc error\n", 11);
	if (n == 2)
		write(2, "argument error\n", 15);
	if (n == 3)
		write(2, "share_pthread_mutex_init error\n", 31);
	if (n == 4)
		write(2, "philo malloc error\n", 19);
	if (n == 5)
		write(2, "philo_init error\n", 17);
	if (n == 6)
		write(2, "pthread_create error\n", 21);
	if (n == 9)
		write(2, "thread_join error\n", 18);
	if (n == 10)
		write(2, "pthread_detach error\n", 21);
	if (philo)
	{
		free(philo);
		philo = 0;
	}
	return (0);
}
