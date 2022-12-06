/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:27:33 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/01 20:02:02 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (!dst && !src)
		return (0);
	dst2 = (unsigned char *) dst;
	src2 = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	char	dst[16] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'};
	char	src[11] = {'0','1','2','3','4','5','6','7','8','9'};
	char	dst_ft[16] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'};
	char	src_ft[11] = {'0','1','2','3','4','5','6','7','8','9'};
	int		dst2[16] = {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	int		src2[11] = {21,22,23,24,25,26,27,28,29,30};
	int		dst2_ft[16] = {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	int		src2_ft[11] = {21,22,23,24,25,26,27,28,29,30};
	size_t	n;
	int	i = 0;

	printf("before\n");
	printf("dst     : %s\n", dst);
	printf("dst_ft  : %s\n", dst_ft);
	printf("dst2    : ");
	while (*(dst2 + i))
	{
		printf("%d ", *(dst2 + i));
		i++;
	}
	printf("\ndst2_ft : ");
	i = 0;
	while (*(dst2_ft + i))
	{
		printf("%d ", *(dst2_ft + i));
		i++;
	}
	printf("\n");

	n = 13;
	memcpy(dst, src, n);
	ft_memcpy(dst_ft, src_ft, n);

	memcpy(dst2, src2, n);
	ft_memcpy(dst2_ft, src2_ft, n);

	printf("\nafter\n");
	printf("dst     : %s\n", dst);
	write(1, dst, 16);
	write(1, "\n", 1);
	printf("dst_ft  : %s\n", dst_ft);
	printf("dst2    : ");
	i = 0;
	while (*(dst2 + i))
	{
		printf("%d ", *(dst2 + i));
		i++;
	}
	printf("\ndst2_ft : ");
	i = 0;
	while (*(dst2_ft + i))
	{
		printf("%d ", *(dst2_ft + i));
		i++;
	}
	printf("\n");
	
	return (0);
}
*/
