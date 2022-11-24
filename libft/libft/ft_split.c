/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:11:40 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 13:55:48 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check(char str, char *charset)
{
	int	i;

	if (str == 0)
		return (0);
	i = 0;
	while (charset[i])
	{
		if (str == charset[i])
			return (0);
		else
			i++;
	}
	return (1);
}

int	word_count(const char *str, char *charset)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i])
	{
		if ((flag == 0) && (check(str[i], charset) == 1))
		{
			count++;
			flag = 1;
		}
		else if ((flag == 1) && (check(str[i], charset) == 0))
			flag = 0;
		i++;
	}
	return (count);
}

void	char_count(const char *str, char *charset, char **split, int word_count)
{
	int	arr[4];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	while (arr[0] < word_count)
	{
		if (check(str[arr[1]], charset) == 1)
		{
			arr[2]++;
			if (arr[3] == 0)
				arr[3] = 1;
		}
		else if ((arr[3] == 1 && check(str[arr[1]], charset) == 0))
		{
			split[arr[0]] = (char *) malloc (sizeof(char) * (arr[2] + 1));
			arr[2] = 0;
			arr[0]++;
			arr[3] = 0;
		}
		arr[1]++;
	}
}

void	copy(const char *str, char *charset, char **split, int index)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 0;
	j = 0;
	while (i < index)
	{
		if (check(*str, charset) == 1)
		{
			split[i][j] = *str;
			j++;
			if (flag == 0)
				flag = 1;
		}
		else if ((flag == 1) && check(*str, charset) == 0)
		{
			split[i][j] = 0;
			j = 0;
			i++;
			flag = 0;
		}
		str++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		index;

	index = word_count(s, &c);
	split = (char **) malloc (sizeof(char *) * (index + 1));
	if (split == 0)
		return (0);
	split[index] = 0;
	char_count(s, &c, split, index);
	copy(s, &c, split, index);
	return (split);
}
