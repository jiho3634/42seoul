/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:35:49 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/22 18:07:31 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((*(unsigned char *) s1) -(*(unsigned char *) s2));
}
