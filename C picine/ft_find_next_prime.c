/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:03:35 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/17 22:44:26 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 1;
	while (i <= nb / i)
	{
		if (nb % i == 0)
		{
			if (i != 1 && i != nb)
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (is_prime(nb) == 1)
		return (nb);
	else
		while (is_prime(nb) == 0)
			nb++;
	return (nb);
}
