/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:59:24 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 13:50:25 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned long len)
{
	unsigned char	*b_uc;
	unsigned char	c_uc;
	unsigned long	i;

	b_uc = (unsigned char *) b;
	c_uc = (unsigned char) c;
	i = 0;
	while (len - i > 0)
	{
		*(b_uc + i) = c_uc;
		i++;
	}
	return (b);
}
/*

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	b[5];
	char	b_ft[5];

	for (int i = 0; i < 5; i++)
		printf("%d ", b[i]);
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%d ", b_ft[i]);
	printf("\n");
	for (int j = 0; j <= 127; j++)
	{
		memset(b_ft, j, 5);
		ft_memset(b, j, 5);
		for (int i = 0; i < 5; i++)
			printf("%d ", b[i]);
		printf("\n");
		for (int i = 0; i < 5; i++)
			printf("%d ", b_ft[i]);
		printf("\n");
	}
	return (0);
}
*/
