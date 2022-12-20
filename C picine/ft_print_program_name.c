/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:25:31 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/17 11:30:13 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	while (*argv[0])
	{
		write(1, argv[0], 1);
		argv[0]++;
	}
	write(1, "\n", 1);
	return (0);
}
