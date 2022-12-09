/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:53:33 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 19:26:11 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	c2;

	c2 = (char) c;
	i = ft_strlen(s);
	if (!c2)
		return ((char *) &s[i]);
	while (i-- > 0)
	{
		if (s[i] == c2)
			return ((char *) &s[i]);
	}
	return (0);
}
