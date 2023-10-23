/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 15:39:26 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strchr(char *str, char chr)
{
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_getenv(t_mini *mini, char *str)
{
	char	*env_ptr;
	char	*temp;
	int		i;

	i = -1;
	while (mini->envp[++i])
	{
		if (ft_envcmp(mini, str, i) == TRUE)
		{
			temp = NULL;
			env_ptr = ft_strchr(mini->envp[i], '=') + 1;
			ft_strcpy(mini, &temp, env_ptr, ft_strlen(env_ptr));
			return (temp);
		}
	}
	return (NULL);
}
