/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:04:55 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/01 20:03:31 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nbrlen(long long n)
{
	long long	len;

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

char	*ft_itoa(int n)
{
	long long	n2;
	long long	len;
	char		*str;

	n2 = (long long) n;
	len = ft_nbrlen(n2);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_putnbr(str, n2, len);
	str[len] = 0;
	return (str);
}
