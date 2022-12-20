/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:39:14 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/17 21:18:36 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	strcompare(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			break ;
	}
	return (str1[i] - str2[i]);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*temp;

	i = 1;
	while (i < argc - 1)
	{
		if (strcompare(argv[i], argv[i + 1]) <= 0)
			i++;
		else if (strcompare(argv[i], argv[i + 1]) > 0)
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = 1;
		}
	}
	print(argc, argv);
	return (0);
}
