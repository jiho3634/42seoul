/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:11:40 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/01 17:17:19 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**malloc_1(char const *s, char c)
{
	char	**s2;
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	s2 = (char **) malloc (sizeof(char *) * (count + 1));
	if (!s2)
		return (0);
	s2[count] = 0;
	return (s2);
}

static char	*ft_strdup(const char *s1, size_t len)
{
	char	*ptr;

	if (len == 0)
	{
		ptr = (char *)malloc (sizeof(char));
		if (!ptr)
			return (0);
		*ptr = 0;
		return (ptr);
	}
	else
	{
		ptr = (char *) malloc (sizeof(char) * (len + 1));
		if (!ptr)
			return (0);
		*(ptr + len) = 0;
		while (len-- > 0)
			*(ptr + len) = *(s1 + len);
	}
	return (ptr);
}

static char	**malloc_2(char const *s, char c, char **s2, size_t count)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != 0 && *s != c)
		{
			count++;
			if (*(s + 1) == 0 || *(s + 1) == c)
			{
				s2[i] = ft_strdup(s - count + 1, count);
				count = 0;
				if (!s2[i])
				{
					while (i >= 0)
						free (s2[i--]);
					free (s2);
					return (0);
				}
				i++;
			}
		}
		s++;
	}
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;

	s2 = malloc_1(s, c);
	if (!s2)
		return (0);
	s2 = malloc_2(s, c, s2, 0);
	if (!s2)
		return (0);
	return (s2);
}
