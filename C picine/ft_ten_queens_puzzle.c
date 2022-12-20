/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:21:43 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/18 12:18:09 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ab(int a, int b)
{
	if (a - b < 0)
		return (b - a);
	return (a - b);
}

int	check(char *arr, int x)
{
	int	now_x;

	now_x = x;
	x = 0;
	while (x < now_x)
	{
		if (arr[x] == arr[now_x])
			return (0);
		else if (ab(arr[now_x], arr[x]) == ab(now_x, x))
			return (0);
		x++;
	}
	return (1);
}

void	recursion(char *arr, int x, int *count)
{
	int	y;

	if (x == 10)
	{
		write(1, arr, 10);
		write(1, "\n", 1);
		*count++;
		return ;
	}
	y = 0;
	while (y < 10)
	{
		arr[x] = y + '0';
		if (check(arr, x) == 1)
			recursion(arr, x + 1, count);
		y++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	arr[11];
	int		count;

	count = 0;
	recursion(arr, 0, &count);
	return (count);
}
