/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:53:33 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/22 17:29:21 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	while (*s)
		s++;
	if (*s == 0 && c == 0)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
	}
	return (0);
}
