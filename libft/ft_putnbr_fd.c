/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:42:09 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 13:54:30 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char		arr[10];
	long long	nbr;
	size_t		i;

	nbr = (long long) n;
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	i = 0;
	while (nbr)
	{
		arr[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	while (i-- >= 1)
		write(fd, &arr[i], 1);
}
