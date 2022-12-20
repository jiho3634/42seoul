/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:13:50 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/17 22:33:37 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	answer;

	if (power < 0)
		return (0);
	else if ((nb == 0) && (power == 0))
		return (1);
	answer = 1;
	while (power > 0)
	{
		answer = answer * nb;
		power--;
	}
	return (answer);
}
