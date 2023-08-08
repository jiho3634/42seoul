/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/07 19:55:26 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (error(0, 0));
	if (!init(argv, &philo, &arg))
		return (error(philo, 1));
	monitoring(philo, arg.number);
	if (arg.number == 1)
		pthread_detach(philo[0].thread);
	threads_join(philo);
	free(philo);
	return (0);
}
