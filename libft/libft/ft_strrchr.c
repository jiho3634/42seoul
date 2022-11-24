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

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c2;

	c2 = (unsigned char) c;
	if (*s == 0 && c == 0)
		return ((char *)s);
	while (*s)
		s++;
	if (*s == 0 && c == 0)
		return ((char *)s);
	while (*(--s))
	{
		if (*s == c)
			return ((char *)s);
	}
	if (*s == 0 && c == 0)
		return ((char *)s);
	return ((void *)0);
}
