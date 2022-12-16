/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:12:07 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/14 15:26:21 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int	recursive_x(unsigned int adrs, unsigned int size)
{
	char	temp;

	if (!size)
		return (0);
	temp = "0123456789abcdef" [adrs % 16];
	if (recursive_x (adrs / 16, size - 1) < 0)
		return (-1);
	return (write(1, &temp, 1));
}

int	function_x(va_list ap)
{
	int				temp;
	unsigned int	nbr;
	int				size;

	temp = va_arg(ap, int);
	nbr = (unsigned int) temp;
	if (!nbr)
		return (write(1, "0", 1));
	size = 0;
	while (nbr)
	{
		nbr /= 16;
		size++;
	}
	nbr = (unsigned int) temp;
	if (recursive_x(nbr, size) < 0)
		return (-1);
	return (size);
}

static int	recursive_xx(unsigned int adrs, unsigned int size)
{
	char	temp;

	if (!size)
		return (0);
	temp = "0123456789ABCDEF" [adrs % 16];
	if (recursive_xx (adrs / 16, size - 1) < 0)
		return (-1);
	return (write(1, &temp, 1));
}

int	function_xx(va_list ap)
{
	int				temp;
	unsigned int	nbr;
	int				size;

	temp = va_arg(ap, int);
	nbr = (unsigned int) temp;
	if (nbr == 0)
		return (write(1, "0", 1));
	size = 0;
	while (nbr)
	{
		nbr /= 16;
		size++;
	}
	nbr = (unsigned int) temp;
	if (recursive_xx(nbr, size) < 0)
		return (-1);
	return (size);
}
