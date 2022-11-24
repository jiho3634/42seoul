/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:57:27 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 14:04:05 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (s == 0 && c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) malloc (len);
	if (*ptr == 0)
		return (0);
	i = 0;
	while (i <= len)
	{
		*(ptr + i) = *(s + start + i);
		i++;
	}
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*s2;
	unsigned int	len;
	unsigned int	start;

	len = ft_strlen(s1);
	s2 = (char *) malloc (sizeof(char) * (len + 1));
	ft_strncpy((char *)s1, s2, len);
	start = 0;
	while (ft_strchr(set, s2[start]))
		start++;
	while (ft_strchr(set, s2[len]))
		len--;
	if (start > len)
	{
		*s2 = 0;
		return (s2);
	}
	s2 = ft_substr(s1, start, len - start);
	return (s2);
}
