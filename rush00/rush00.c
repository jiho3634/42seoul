/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 08:46:33 by yejlee2           #+#    #+#             */
/*   Updated: 2022/10/01 08:46:36 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

void	print_first_last_column(int chk_first_last_row)
{
	if (chk_first_last_row)
		ft_putchar('o');
	else
		ft_putchar('|');
}

void	print_middle_column(int chk_first_last_row)
{
	if (chk_first_last_row)
		ft_putchar('-');
	else
		ft_putchar(' ');
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
			if (column == 1 || column == x)
				print_first_last_column(chk_first_last_row);
			else
				print_middle_column(chk_first_last_row);
		}
		chk_first_last_row = 0;
		ft_putchar('\n');
	}
}
