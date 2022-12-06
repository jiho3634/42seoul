/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:57:06 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 12:28:39 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	if (!dst && !src)
		return (0);
	dst2 = (char *) dst;
	src2 = (char *) src;
	i = 1;
	while (i <= n)
	{
		*(dst2 + n - i) = *(src2 + n - i);
		i++;
	}
	return (dst);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	if (!dst && !src)
		return (0);
	dst2 = (char *) dst;
	src2 = (char *) src;
	i = 0;
	while (i < n)
	{
		*(dst2 + i) = *(src2 + i);
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (0);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
		ft_memrcpy(dst, src, len);
	return (dst);
}
