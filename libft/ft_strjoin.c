/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:23:14 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/22 17:25:37 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (*(s1 + i++))
		len++;
	i = 0;
	while (*(s2 + i++))
		len++;
	s3 = (char *) malloc (len);
	while (*s1)
		*(s3++) = *(s1++);
	while (*s2)
		*(s3++) = *(s2++);
	return (s3);
}
