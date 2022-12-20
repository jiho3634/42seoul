/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:15:35 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/17 16:10:51 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	base_validation_check(char *base)
{
	int	left;
	int	right;

	if (base[0] == 0 || base[1] == 0)
		return (0);
	left = 0;
	while (base[left])
	{	
		if (base[left] == '+' || base[left] == '-')
			return (0);
		right = left + 1;
		while (base[right])
		{
			if (base[left] == base[right])
				return (0);
			right++;
		}
		left++;
	}
	return (left);
}

void	int_to_char(long long number, char *base, long long base_length)
{
	if (number < base_length)
	{
		write(1, &base[number], 1);
		return ;
	}
	int_to_char(number / base_length, base, base_length);
	write(1, &base[number % base_length], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	base_length;
	long long	number;

	if (base_validation_check(base) == 0)
		return ;
	base_length = base_validation_check(base);
	number = (long long) nbr;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	int_to_char(number, base, base_length);
}
