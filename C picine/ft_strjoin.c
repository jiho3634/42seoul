/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:22:49 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/19 18:06:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_length_come_on(int size, char **str)
{
	int	i;
	int	index;
	int	count;

	i = 0;
	count = 0;
	while (count < size)
	{
		index = 0;
		while (str[count][index])
		{
			index++;
			i++;
		}
		count++;
	}
	return (i);
}

int	sep_length_come_on(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

void	cooking_strs_and_sep(int size, char **str, char *sep, char *joined_str)
{
	int		count;
	int		i;
	int		j;

	i = 0;
	count = 0;
	while (count < size)
	{
		j = 0;
		while (str[count][j])
		{
			joined_str[i] = str[count][j];
			i++;
			j++;
		}
		j = 0;
		while (sep[j] && ((count + 1) != size))
		{
			joined_str[i] = sep[j];
			i++;
			j++;
		}
		count++;
	}
	joined_str[i] = 0;
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	int		str_length;
	int		sep_length;
	int		total_length;
	char	*joined_str;

	if (size == 0)
	{
		joined_str = malloc (sizeof(char) * 1);
		joined_str[0] = 0;
		return (joined_str);
	}
	else
	{
		str_length = str_length_come_on(size, str);
		sep_length = sep_length_come_on(sep);
		total_length = str_length + sep_length * (size - 1);
		joined_str = (char *) malloc (sizeof (char) * (total_length + 1));
		if (joined_str == 0)
			return (0);
		cooking_strs_and_sep(size, str, sep, joined_str);
	}
	return (joined_str);
}
