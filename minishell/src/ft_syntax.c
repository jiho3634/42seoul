/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:17:02 by jihokim2          #+#    #+#             */
/*   Updated: 2023/09/30 09:50:36 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_is_redir(char *str)
{
	if (*str == '<' || *str == '>')
	{
		if (!(*(str + 1)))
			return (1);
		else if (*(str + 1) && !(*str + 2))
			return (1);
		else
			return (1);
	}
	return (0);
}

int	ft_is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

int	ft_syntax(t_mini *mini, t_tok tok, int i)
{
	if (tok.arr[0] == NULL)
		return (0);
	if (ft_is_pipe(tok.arr[0][0]))
		return (ft_syntax_error(mini, "syntax error near unexpected token", \
															&tok.arr[0][0]));
	while (tok.arr[i + 1])
	{
		if (ft_is_redir(tok.arr[i]) && ft_is_pipe(tok.arr[i + 1][0]))
			return (ft_syntax_error(mini, "syntax error near unexpected token", \
													&tok.arr[i + 1][0]));
		if (ft_is_redir(tok.arr[i]) && ft_is_redir(tok.arr[i + 1]))
			return (ft_syntax_error(mini, "syntax error near unexpected token", \
														&tok.arr[i + 1][0]));
		if (ft_is_pipe(tok.arr[i + 1][0]) && ft_is_pipe(tok.arr[i + 1][1]))
			return (ft_syntax_error(mini, "syntax error near unexpected token", \
														&tok.arr[i + 1][0]));
		if (ft_is_pipe(tok.arr[i][0]) && ft_is_pipe(tok.arr[i + 1][0]))
			return (ft_syntax_error(mini, "syntax error near unexpected token", \
														&tok.arr[i + 1][0]));
		i++;
	}
	if (ft_is_redir(tok.arr[i]) && !(tok.arr[i + 1]))
		return (ft_syntax_error(mini, "syntax error near unexpected token", \
																"newline"));
	return (0);
}
