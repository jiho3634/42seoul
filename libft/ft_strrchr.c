/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:53:33 by jihokim2          #+#    #+#             */
/*   Updated: 2022/11/24 19:26:11 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c2;

	c2 = (char) c;
	i = 0;
	while (s[i])
		i++;
	if (!c2)
		return ((char *) &s[i]);
	while (--i >= 0)
	{
		if (s[i] == c2)
			return ((char *) &s[i]);
	}
	return (0);
}
