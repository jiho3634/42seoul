/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:09:04 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/15 16:27:32 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		div;
	int		mod;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32) || str[i] >= 127)
		{
			div = (unsigned char)str[i] / 16;
			mod = (unsigned char)str[i] % 16;
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[div], 1);
			write(1, &"0123456789abcdef"[mod], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
