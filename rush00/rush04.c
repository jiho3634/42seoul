/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:34:23 by yejlee2           #+#    #+#             */
/*   Updated: 2022/10/02 09:26:47 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

void	print_first_last_column(int chk_first_last_row, int col, int row)
{
	if (chk_first_last_row)
	{
		if (col == 1 && row == 1)
			ft_putchar('A');
		else if (col == 1 && row != 1)
			ft_putchar('C');
		else if (col != 1 && row == 1)
			ft_putchar('C');
		else
			ft_putchar('A');
	}
	else
		ft_putchar('B');
}

void	print_middle_column(int chk_first_last_row)
{
	if (chk_first_last_row)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	col;
	int	row;
	int	chk_first_last_row;

	if (x <= 0 || y <= 0)
		return ;
	row = 0;
	while (row++ < y)
	{
		if (row == 1 || row == y)
			chk_first_last_row = 1;
		col = 0;
		while (col++ < x)
		{
			if (col == 1 || col == x)
				print_first_last_column(chk_first_last_row, col, row);
			else
				print_middle_column(chk_first_last_row);
		}
		chk_first_last_row = 0;
		ft_putchar('\n');
	}
}
