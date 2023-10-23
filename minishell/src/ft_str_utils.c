/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:13:26 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/05 13:37:47 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_strlen(char *str)
{
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strcpy(t_mini *mini, char **dst, char *src, int len)
{
	*dst = (char *)ft_calloc(mini, len + 1, sizeof(char));
	while (--len >= 0)
		(*dst)[len] = src[len];
}

void	ft_arrcpy(t_mini *mini, char ***dst, char **src, int i)
{
	if (!src[i])
	{
		*dst = (char **)ft_calloc(mini, i + 1, sizeof(char *));
		return ;
	}
	ft_arrcpy(mini, dst, src, i + 1);
	ft_strcpy(mini, &(*dst)[i], src[i], ft_strlen(src[i]));
}

char	*ft_strdup(t_mini *mini, char *s1, size_t len)
{
	char	*ptr;

	if (!len)
		return ((char *)ft_calloc(mini, 1, sizeof(char)));
	else
	{
		ptr = (char *)ft_calloc(mini, len + 1, sizeof(char));
		while (len-- > 0)
			*(ptr + len) = *(s1 + len);
	}
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}
