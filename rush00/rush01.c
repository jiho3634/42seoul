/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:03:52 by yejlee2           #+#    #+#             */
/*   Updated: 2022/10/02 15:45:29 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

void	print_first_column(int row, int y)
{	
	if (row == 1)
		ft_putchar('/');
	else if (row == y)
		ft_putchar('\\');
	else
		ft_putchar('*');
}

void	print_middle_column(int row, int y)
{
	if (row == 1 || row == y)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	print_last_column(int row, int y)
{
	if (row == 1)
		ft_putchar('\\');
	else if (row == y)
		ft_putchar('/');
	else
		ft_putchar('*');
}

void	rush(int x, int y)
{
	int	row;
	int	column;
	int	chk_last_row;

	if (x <= 0 || y <= 0)
		return ;
	row = 0;
	while (row++ < y)
	{
		column = 0;
		while (column++ < x)
		{
			if (column == 1)
				print_first_column(row, y);
			else if (column == x)
				print_last_column(row, y);
			else
				print_middle_column(row, y);
		}
		chk_last_row = 0;
		ft_putchar('\n');
	}
	return ;
}
