/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:45:32 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/21 20:49:17 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_c;

	i = 0;
	s_c = (char *)s;
	while (i < n)
	{
		*(s_c + i) = 0;
		i++;
	}
}
/*

#include <strings.h>
#include <stdio.h>

int	main(void)
{
	char	arr[10] = {70, 71, 72, 73, 74, 75, 76, 77, 78, 79};
	char	arr_ft[10] = {70, 71, 72, 73, 74, 75, 76, 77, 78, 79};

	for (int i = 0; i < 10; i++)
		printf("%d ",arr[i]);
	printf("\n");
	for (int i = 0; i < 10; i++)
		printf("%d ",arr_ft[i]);
	printf("\n");
	
	bzero(arr, 5);
	ft_bzero(arr_ft, 5);

	for (int i = 0; i < 10; i++)
		printf("%d ",arr[i]);
	printf("\n");
	for (int i = 0; i < 10; i++)
		printf("%d ",arr_ft[i]);
	printf("\n");
	return (0);
}
*/
