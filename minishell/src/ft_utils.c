/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:01:42 by jihokim2          #+#    #+#             */
/*   Updated: 2023/09/27 22:05:31 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_bzero(void *str, size_t size)
{
	unsigned char	*ptr;

	if (!size)
		return ;
	ptr = (unsigned char *)str;
	while (--size > 0)
		ptr[size] = 0;
	ptr[size] = 0;
}

void	*ft_calloc(t_mini *mini, size_t count, size_t size)
{
	void	*arr;

	arr = (void *)malloc(count * size);
	if (!arr)
		ft_error_exit(mini, "malloc", 0, "can not allocate memory");
	ft_bzero (arr, (count * size));
	return (arr);
}

char	*ft_put_itoa(t_mini *mini, int len, long long num)
{
	char	*str;

	str = (char *)ft_calloc(mini, len + 1, sizeof(char));
	len = len - 1;
	if (num == 0)
		str[len] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}

char	*ft_set_itoa(t_mini *mini, int nbr)
{
	int			len;
	int			temp;
	long long	num;

	num = (long long)nbr;
	len = 0;
	temp = nbr;
	if (temp <= 0)
		len++;
	while (temp)
	{
		temp = temp / 10;
		len++;
	}
	return (ft_put_itoa(mini, len, num));
}

int	ft_atoi(char *nptr)
{
	size_t			i;
	int				sign;
	long long int	num_integer;

	i = 0;
	sign = 1;
	num_integer = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' )
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num_integer = num_integer * 10 + nptr[i] - '0';
		i++;
	}
	num_integer = num_integer * sign;
	if (num_integer > INT32_MAX || num_integer < INT32_MIN)
		return (-1);
	return (num_integer);
}
