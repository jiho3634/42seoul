/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:52:24 by jihokim2          #+#    #+#             */
/*   Updated: 2023/08/21 12:00:43 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi(unsigned int *value, const char *str)
{
	long long	answer;
	int			i;

	if (!str)
	{
		*value = -1;
		return (1);
	}
	i = 0;
	if (str[i] == '+')
		i++;
	if (!(str[i] >= '1' && str[i] <= '9'))
		return (0);
	answer = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		answer = answer * 10 + (str[i] - '0');
		i++;
	}
	if (!str[i] && !(i > 11 || answer > 2147483647 || answer < -2147483648))
	{
		*value = (int)answer;
		return (1);
	}
	return (0);
}

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
