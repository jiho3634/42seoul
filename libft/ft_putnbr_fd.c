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

static void	print_n(int n, int fd, char *arr)
{
	int	i;

	i = 0;
	while (n)
	{
		arr[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		write(fd, &arr[i - 1], 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[10];

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
		print_n(n, fd, arr);
	}
	else if (n == 0)
		write(fd, "0", 1);
	else
		print_n(n, fd, arr);
}
