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
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
		dest[i] = '\0';
	printf("i : %zu\n", i);
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	start;
	size_t	end;

	if (!set[0])
	{
		s2 = (char *) malloc (1);
		*s2 = 0;
		return (s2);
	}
	end = ft_strlen(s1);
	printf("end : %zu\n", end);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	printf("start : %zu\n", start);
	while ((end > 0) && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	printf("end : %zu\n", end);
	s2 = (char *) malloc (end - start + 2);
	if (!s2)
		return (0);
	return (ft_strncpy(s2, &s1[start], end - start));
}

int	main(void)
{
	char s1[] = "lorem ipsum dolor sit amet";
	printf("%s\n", ft_strtrim(s1, "tel"));
	return (0);
}

