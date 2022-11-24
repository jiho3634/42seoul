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

static int	nlen(int n)
{
	int	len;

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

static void	putn(char *result, int n, int len)
{
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	else if (n == 0)
	{
		result[0] = 0;
		return ;
	}
	while (n / 10 != 0 || n % 10 != 0)
	{
		result[len] = n % 10;
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = nlen(n);
	result = (char *) malloc (sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = 0;
	putn(result, n, len);
	return (result);
}
