/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:08:07 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 13:03:25 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = 0;
	while (*(src + i++))
		srcsize++;
	if (dstsize == 0)
		return (srcsize);
	i = 0;
	while (*(src + i) && (i + 1 < dstsize))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (srcsize);
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
