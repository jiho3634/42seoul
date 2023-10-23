/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_exp_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:14 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_exp_change_val_heredoc(t_mini *mini, t_env *env, t_red *red, int *j)
{
	int		cmd_len;
	char	*temp;
	int		i;
	int		l;
	int		m;

	env->env_len = ft_strlen(env->env_ptr);
	cmd_len = ft_strlen(red->line);
	cmd_len = cmd_len - (env->val_len + 1) + env->env_len;
	temp = (char *)ft_calloc(mini, cmd_len + 1, sizeof(char));
	i = -1;
	while (++i < env->dollar_index)
		temp[i] = red->line[i];
	l = -1;
	while (env->env_ptr && ++l < env->env_len)
		temp[i + l] = env->env_ptr[l];
	if (!env->env_ptr)
		l = 0;
	*j = i + l;
	m = -1;
	while (red->line[env->dollar_index + (env->val_len + 1) + (++m)])
		temp[i + l + m] = red->line[env->dollar_index + \
													(env->val_len + 1) + m];
	red->line = temp;
}

char	*ft_exp_behind_dollar_heredoc(t_mini *mini, t_env *env, t_red *red)
{
	char	*temp;
	int		len;
	int		j;
	int		k;

	len = 0;
	k = env->dollar_index + 1;
	if (red->line[k] == '?')
	{
		env->val_len = 1;
		return (NULL);
	}
	while (ft_is_dollar_valid(red->line[k + len]))
		len++;
	env->val_len = len;
	temp = (char *)ft_calloc(mini, len + 1, sizeof(char));
	j = -1;
	while (++j < len)
		temp[j] = red->line[k + j];
	return (temp);
}

int	ft_exp_cp_val_heredoc(t_mini *mini, t_env *env, t_red *red, int *i)
{
	env->dollar_index = *i;
	env->temp = ft_exp_behind_dollar_heredoc(mini, env, red);
	if (!env->temp)
	{
		env->env_ptr = ft_set_itoa(mini, g_global);
		ft_exp_change_val_heredoc(mini, env, red, i);
		ft_free((void *)&env->env_ptr);
	}
	else
	{
		env->env_ptr = ft_getenv(mini, env->temp);
		ft_free((void *)&env->temp);
		ft_exp_change_val_heredoc(mini, env, red, i);
		ft_free((void *)&env->env_ptr);
		return (1);
	}
	return (0);
}

void	ft_exp_heredoc(t_mini *mini, t_red *red)
{
	int		i;

	i = -1;
	while (red->line[++i])
	{
		if (red->line[i] == '$' && ft_is_dollar_valid(red->line[i + 1]))
			ft_exp_cp_val_heredoc(mini, &mini->env, red, &i);
	}
}
