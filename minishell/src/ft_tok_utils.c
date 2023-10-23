/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:11:40 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_is_delimeter(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	ft_is_quote(char c, char quote)
{
	if ((c == '\'' || c == '\"') && (!quote || quote == c))
		return (1);
	return (0);
}

int	ft_is_cmd(char c, char quote)
{
	if (!ft_is_space(c) && !ft_is_delimeter(c) && !ft_is_quote(c, quote))
		return (1);
	return (0);
}

void	ft_check_next_quote(char *c, t_tok *tok)
{
	while (*c && !ft_is_quote(*c, tok->quote))
		c++;
	if (*c)
		tok->flag = 1;
}
