/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:34:12 by yejlee2           #+#    #+#             */
/*   Updated: 2022/10/02 09:28:10 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

void	print_first_column(int chk_first_last_row)
{
	if (chk_first_last_row)
		ft_putchar('A');
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

void	print_last_column(int chk_first_last_row)
{
	if (chk_first_last_row)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int	row;
	int	column;
	int	chk_first_last_row;

	if (x <= 0 || y <= 0)
		return ;
	row = 0;
	while (row++ < y)
	{
		if (row == 1 || row == y)
			chk_first_last_row = 1;
		column = 0;
		while (column++ < x)
		{
			if (column == 1)
				print_first_column(chk_first_last_row);
			else if (column == x)
				print_last_column(chk_first_last_row);
			else
				print_middle_column(chk_first_last_row);
		}
		chk_first_last_row = 0;
		ft_putchar('\n');
	}
}
