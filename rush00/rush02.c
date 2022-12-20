/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:23:11 by yejlee2           #+#    #+#             */
/*   Updated: 2022/10/02 09:27:42 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

void	print_column(int chk_row)
{
	if (chk_row == 1)
		ft_putchar('A');
	else if (chk_row == 2)
		ft_putchar('B');
	else if (chk_row == 3)
		ft_putchar('C');
	else if (chk_row == 0)
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	row;
	int	column;
	int	chk_row_col;

	if (x <= 0 || y <= 0)
		return ;
	row = 0;
	while (row++ < y)
	{
		column = 0;
		while (column++ < x)
		{
			if (row == 1 && (column == 1 || column == x))
				chk_row_col = 1;
			else if (row == y && (column == 1 || column == x))
				chk_row_col = 3;
			else if (row == 1 || row == y || column == 1 || column == x)
				chk_row_col = 2;
			else
				chk_row_col = 0;
			print_column(chk_row_col);
		}
		ft_putchar('\n');
	}
}
