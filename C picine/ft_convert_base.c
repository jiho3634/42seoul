/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:32:35 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/20 16:08:47 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ato2(char *str, char *base);
int	base_validation(char *base);
int	sign_decision(char *str, int *point);
int	str_base(char *str, char *base, int point, int jinsoo);

void	itoa(char *base_to,
		long long to_len, char *result, long long *arr)
{
	long long	nbr3;
	long long	nbr_len;

	nbr3 = arr[0];
	nbr_len = arr[1];
	if (nbr3 / to_len == 0 && nbr3 % to_len == 0)
	{
		return ;
	}
	arr[0] = nbr3 / to_len;
	arr[1] = nbr_len - 1;
	itoa(base_to, to_len, result, arr);
	result[nbr_len] = base_to[nbr3 % to_len];
}

void	putn(char *base_to,
		long long to_len, char *result, long long *arr)
{
	long long	nbr3;
	long long	nbr_len;

	nbr3 = arr[0];
	nbr_len = arr[1];
	if (nbr3 < 0)
	{
		nbr3 = -nbr3;
		result[0] = '-';
	}
	else if (nbr3 == 0)
	{
		result[0] = base_to[0];
		return ;
	}
	arr[0] = nbr3;
	arr[1] = nbr_len - 1;
	itoa(base_to, to_len, result, arr);
}

int	nbr_len_come_on(long long nbr3, int to_len)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr3 <= 0)
	{
		nbr3 = -nbr3;
		nbr_len = 1;
	}
	while (nbr3 > 0)
	{
		nbr3 = nbr3 / to_len;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			nbr2;
	long long	arr[2];
	int			to_len;
	char		*result;

	if (base_validation(base_from) == 0 || base_validation(base_to) == 0)
		return (0);
	nbr2 = ato2(nbr, base_from);
	arr[0] = (long long) nbr2;
	to_len = base_validation(base_to);
	arr[1] = nbr_len_come_on(arr[0], to_len);
	result = (char *) malloc (sizeof(char) * (arr[1] + 1));
	if (!result)
		return (0);
	result[arr[1]] = 0;
	putn(base_to, to_len, result, arr);
	return (result);
}
