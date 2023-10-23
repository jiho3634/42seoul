/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:11:40 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_off_cmd(char *c, t_tok *tok)
{
	if (ft_is_delimeter(*(c + 1)))
		return (1);
	else if (ft_is_space(*(c + 1)))
		return (1);
	else if (ft_is_quote(*(c + 1), tok->quote))
		return (0);
	else if (ft_is_cmd(*c, tok->quote))
		return (0);
	return (0);
}

int	ft_off_delimeter(char *c, t_tok *tok)
{
	if (ft_is_cmd(*(c + 1), tok->quote))
		return (1);
	else if (ft_is_quote(*(c + 1), tok->quote))
		return (1);
	else if (ft_is_space(*(c + 1)))
		return (1);
	else if (ft_is_delimeter(*(c + 1)))
	{
		if (*c != *(c + 1))
			return (1);
		else
			return (0);
	}
	return (0);
}

int	ft_off_quote(char *c, t_tok *tok)
{
	tok->quote = *c;
	ft_check_next_quote(c + 1, tok);
	if (tok->flag)
		return (0);
	else
	{
		if (ft_is_delimeter(*(c + 1)))
			return (1);
		else if (ft_is_space(*(c + 1)))
			return (1);
		else if (ft_is_cmd(*c, tok->quote))
			return (0);
	}
	return (0);
}

int	ft_can_tok(char *c, t_tok *tok)
{
	if (!tok->flag)
	{
		if (*(c + 1) == '\0')
			return (1);
		if (ft_is_cmd(*c, tok->quote))
			return (ft_off_cmd(c, tok));
		else if (ft_is_delimeter(*c))
			return (ft_off_delimeter(c, tok));
		else if (ft_is_quote(*c, tok->quote))
			return (ft_off_quote(c, tok));
		return (0);
	}
	else if (tok->flag && ft_is_quote(*c, tok->quote))
	{
		tok->flag = 0;
		tok->quote = 0;
		if (*(c + 1) == '\0' || \
			ft_is_space(*(c + 1)) || \
			ft_is_delimeter(*(c + 1)))
			return (1);
		else if (ft_is_cmd(*(c + 1), tok->quote) || \
				ft_is_quote(*(c + 1), tok->quote))
			return (0);
	}
	return (0);
}

void	ft_tok(t_mini *mini, char *line, int i)
{
	int		j;

	while (ft_is_space(*line))
		line++;
	if (!*line)
	{
		mini->tok.arr = (char **)ft_calloc(mini, i + 1, sizeof(char *));
		return ;
	}
	j = 0;
	while (*line)
	{
		if ((!mini->tok.flag && !ft_is_space(*line)) || mini->tok.flag)
		{
			j++;
			if (ft_can_tok(line, &mini->tok))
			{
				ft_tok(mini, line + 1, i + 1);
				mini->tok.arr[i] = ft_strdup(mini, line - j + 1, j);
				break ;
			}
		}
		line++;
	}
}
