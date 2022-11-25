/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:04:55 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 13:48:13 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_nbrlen(long long n)
{
	long long	len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr(char *str, long long n, long long len)
{
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		str[0] = '-';
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
/*
int	main(void)
{
	int n = -2147483648;
	int n2 = 0;
	printf("%s\n", ft_itoa(n));
	printf("%s\n", ft_itoa(n2));
	return (0);
}
*/
