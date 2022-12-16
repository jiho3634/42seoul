/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:16:03 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/14 12:16:27 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "ft_printf.h"

static int	ft_nbrlen(long long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len = 1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr(char *str, long long n, long long len)
{
	if (n == 0)
	{
		*str = '0';
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		*str = '-';
	}
	while (n / 10 != 0 || n % 10 != 0)
	{
		str[--len] = '0' + (n % 10);
		n /= 10;
	}
}

int	function_id(va_list ap)
{
	long long	n;
	char		*str;
	int			len;

	n = va_arg(ap, int);
	len = ft_nbrlen(n);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	ft_putnbr(str, n, len);
	str[len] = 0;
	if (write(1, str, len) < 0)
		len = -1;
	free (str);
	return (len);
}

int	function_u(va_list ap)
{
	long long	n;
	char		*str;
	int			len;

	n = va_arg(ap, unsigned int);
	len = ft_nbrlen(n);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	ft_putnbr(str, n, len);
	str[len] = 0;
	if (write(1, str, len) < 0)
		len = -1;
	free (str);
	return (len);
}
