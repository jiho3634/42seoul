/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/23 11:20:33 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_share	share;

	if (argc != 5 && argc != 6)
		return (error(0, 0));
	if (!init(argv, &philo, &share))
		return (0);
	monitoring(philo);
	if (philo -> philo_number == 1)
	{
		if (pthread_detach(philo[0].thread))
			return (error(philo, 10));
	}
	else if (!threads_join(philo))
		return (0);
	if (philo)
	{
		free(philo);
		philo = 0;
	}
	return (0);
}
