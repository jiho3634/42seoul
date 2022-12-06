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

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char	*ft_strncpy(char *dest, char *src, size_t n)
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

static char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c2;

	c2 = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c2)
			return ((char *) &s[i]);
		i++;
	}
	if (!c2)
		return ((char *) &s[i]);
	return (0);
}

static char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s1);
	if (len == 0)
	{
		ptr = malloc (sizeof(char));
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
		while (--len >= 0)
			*(ptr + len) = *(s1 + len);
	}
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	head;
	size_t	tail;

	if (!s1[0] || !set[0])
		s2 = ft_strdup(s1);
	else
	{
		tail = ft_strlen(s1) - 1;
		head = 0;
		while (s1[head] && ft_strchr(set, s1[head]))
			head++;
		while ((tail > head) && ft_strchr(set, s1[tail]))
			tail--;
		s2 = (char *) malloc (sizeof(char) * ((tail - head + 1) + 1));
		if (!s2)
			return (0);
		ft_strncpy(s2, (char *)s1 + head, (tail - head + 1) + 1);
		s2[tail - head + 1] = 0;
	}
	return (s2);
}
/*
#include <stdio.h>
int	main(void)
{
	char s1[] = " lorem ipsum dolor sit amet";
	printf("%s\n", ft_strtrim(s1, "l "));
	char s2[] = "lorem ipsum dolor sit amet";
	printf("%s\n", ft_strtrim(s2, "tel"));
	char s3[] = "          ";
	printf("%s\n", ft_strtrim(s3, " "));
	char s4[] = "lorem ipsum dolor sit amet";
	printf("%s\n", ft_strtrim(s4, ""));
	char s5[] = "";
	printf("%s\n", ft_strtrim(s5, ""));
	return (0);
}
*/
