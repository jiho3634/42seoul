/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_dq_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:01:42 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 16:05:49 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_is_dollar_valid(char c)
{
	if (!ft_is_space(c) && c != '\'' && c != '\"' && c != '$' && c != '\0')
		return (1);
	return (0);
}

void	ft_exp_change_val(t_mini *mini, t_env *env, char **line, int *j)
{
	int		cmd_len;
	char	*temp;
	int		i;
	int		l;
	int		m;

	env->env_len = ft_strlen(env->env_ptr);
	cmd_len = ft_strlen(*line);
	cmd_len = cmd_len - (env->val_len + 1) + env->env_len;
	temp = (char *)ft_calloc(mini, cmd_len + 1, sizeof(char));
	i = -1;
	while (++i < env->dollar_index)
		temp[i] = (*line)[i];
	l = -1;
	while (env->env_ptr && ++l < env->env_len)
		temp[i + l] = env->env_ptr[l];
	if (!env->env_ptr)
		l = 0;
	*j = i + l - 1;
	m = -1;
	while ((*line)[env->dollar_index + (env->val_len + 1) + (++m)])
		temp[i + l + m] = (*line)[env->dollar_index + \
												(env->val_len + 1) + m];
	ft_free((void *)line);
	*line = temp;
}

char	*ft_exp_behind_dollar(t_mini *mini, t_env *env, char **line)
{
	char	*temp;
	int		len;
	int		j;
	int		k;

	len = 0;
	k = env->dollar_index + 1;
	if ((*line)[k] == '?')
	{
		env->val_len = 1;
		return (NULL);
	}
	while (ft_is_dollar_valid((*line)[k + len]))
		len++;
	env->val_len = len;
	temp = (char *)ft_calloc(mini, len + 1, sizeof(char));
	j = -1;
	while (++j < len)
		temp[j] = (*line)[k + j];
	return (temp);
}

int	ft_exp_cp_val(t_mini *mini, t_env *env, char **line, int *j)
{
	if (!ft_is_dollar_valid((*line)[*j + 1]))
		return (0);
	env->dollar_index = *j;
	env->temp = ft_exp_behind_dollar(mini, env, line);
	if (!env->temp)
	{
		env->env_ptr = ft_set_itoa(mini, g_global);
		ft_exp_change_val(mini, env, line, j);
		ft_free((void *)&env->env_ptr);
	}
	else
	{
		env->env_ptr = ft_getenv(mini, env->temp);
		ft_free((void *)&env->temp);
		ft_exp_change_val(mini, env, line, j);
		ft_free((void *)&env->env_ptr);
		return (1);
	}
	return (0);
}

char	*ft_exp_find_dollar(t_mini *mini, t_env *env, char **line)
{
	int	j;

	j = env->first + 1;
	while ((*line)[j] != '\"')
	{
		if ((*line)[j] == '$')
		{
			if (ft_exp_cp_val(mini, env, line, &j))
			{
				j = env->dollar_index + env->env_len - 1;
				continue ;
			}
		}
		j++;
	}
	env->second = j;
	return (0);
}
