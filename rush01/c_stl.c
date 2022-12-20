/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_stl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjaecho <minjaecho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:09:05 by minjaecho         #+#    #+#             */
/*   Updated: 2022/10/09 20:33:55 by minjaecho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	ft_putchar(nb + 48);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_arr(int arr[], int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		ft_putnbr(arr[i]);
		if (i != c - 1)
			ft_putchar(' ');
		i++;
	}
	write (1, "\n", 1);
}

void	same_permutation(int arr[], int n, int depth, int **perms)
{
	static int	ind = 0;
	int			i;

	if (n == depth)
	{
		perms[ind] = (int *)malloc(n * sizeof(int));
		i = 0;
		while (i < n)
		{
			perms[ind][i] = arr[i];
			i++;
		}
		ind += 1;
		return ;
	}
	i = depth;
	while (i < n)
	{
		ft_swap(&arr[i], &arr[depth]);
		same_permutation(arr, n, depth + 1, perms);
		ft_swap(&arr[i], &arr[depth]);
		i++;
	}
}
