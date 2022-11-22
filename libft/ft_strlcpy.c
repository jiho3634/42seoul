/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:08:07 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/21 20:47:08 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	i = 0;
	while (*(src + i))
		i++;
	return (i);
}
/*
int	main(void)
{
	char	dst[10] = {0};
	char	dst_ft[10] = {0};
	char	src[12] = {'a','b','c','d','e','f','g','h','i','j','k','l'};

	printf("%s\n", dst);
	printf("%s\n", dst_ft);

	strlcpy(dst, src, 2);
	ft_strlcpy(dst_ft, src, 2);

	printf("%s\n", dst);
	printf("%s\n", dst_ft);

	return (0);
}
*/
