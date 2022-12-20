/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 08:45:58 by yejlee2           #+#    #+#             */
/*   Updated: 2022/10/02 14:05:54 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int		ft_atoi(char *str);

int	main(int argc, char *argv[])
{
	int	a;
	int	b;

	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[2]);
	(void)argc;
	rush(a, b);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (!((str[i] <= '9') && (str[i] >= '0')))
			return (0);
		i++;
	}
	i = 0;
	while ((str[i] <= '9') && (str[i] >= '0'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}
