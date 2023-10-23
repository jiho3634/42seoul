/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_option_check(char *cmd, int *flag)
{
	int	i;

	if (cmd && cmd[0] == '-' && cmd[1])
	{
		i = 1;
		while (cmd[i] == 'n')
			i++;
		if (!cmd[i])
		{
			*flag = 1;
			return (TRUE);
		}
	}
	return (FALSE);
}

void	ft_built_in_echo(t_lst *lst)
{
	int		flag;
	int		i;

	flag = 0;
	i = 1;
	while (ft_option_check(lst->cmd[i], &flag) == TRUE)
		i++;
	while (lst->cmd[i])
	{
		printf("%s", lst->cmd[i]);
		if (lst->cmd[i + 1] == NULL)
			break ;
		printf(" ");
		i++;
	}
	if (flag == 0)
		printf("\n");
	g_global = 0;
}
