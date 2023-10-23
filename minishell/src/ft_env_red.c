/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_red.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:47:50 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/06 16:28:27 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// char	*ft_exp_behind_dollar_red(t_mini *mini, t_env *env, t_red *red)
// {
// 	char	*temp;
// 	int		len;
// 	int		j;
// 	int		k;

// 	k = env->dollar_index + 1;
// 	if (red->file[k] == '?')
// 	{
// 		env->val_len = 1;
// 		return (NULL);
// 	}
// 	len = 0;
// 	while (ft_is_dollar_valid(red->file[k + len]))
// 		len++;
// 	env->val_len = len;
// 	temp = (char *)ft_calloc(mini, len + 1, sizeof(char));
// 	j = -1;
// 	while (++j < len)
// 		temp[j] = red->file[k + j];
// 	return (temp);
// }

// int	ft_copy_and_change_env_red(t_mini *mini, t_env *env, t_red *red, int *j)
// {
// 	if (!ft_is_dollar_valid(red->file[*j + 1]))
// 		return (0);
// 	mini->env.dollar_index = *j;
// 	mini->env.temp = ft_exp_behind_dollar_red(mini, &mini->env, red);
// 	if (!mini->env.temp)
// 	{
// 		mini->env.env_ptr = ft_set_itoa(mini, g_global);
// 		ft_exp_change_val(mini, env, &red->file, j);
// 		ft_free((void *)&mini->env.env_ptr);
// 	}
// 	else
// 	{
// 		mini->env.env_ptr = ft_getenv(mini, mini->env.temp);
// 		ft_free((void *)&mini->env.temp);
// 		return (ft_exp_check_filename(mini, env, red, j));
// 	}
// 	return (0);
// }

char	*ft_find_dollar_sign_red(t_mini *mini, t_red *red)
{
	int	j;

	j = mini->env.first + 1;
	while (red->file[j] != '\"')
	{
		if (red->file[j] == '$')
			ft_exp_cp_val(mini, &mini->env, &red->file, &j);
		j++;
	}
	mini->env.second = j;
	return (0);
}
