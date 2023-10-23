/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_pwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/02 23:11:07 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_built_in_pwd(void)
{
	char	pwd[1024];

	ft_bzero(pwd, sizeof(pwd));
	if (getcwd(pwd, sizeof(pwd)))
		printf("%s\n", pwd);
	else
	{
		g_global = errno;
		perror("mysh: pwd: ");
		return (1);
	}
	g_global = 0;
	return (0);
}
