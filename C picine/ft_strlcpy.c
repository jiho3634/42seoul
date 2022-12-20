/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:42:55 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/10 14:48:25 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	length_function(const char *src)
{
	int	i;

	i = 0;
	while (*src++)
		i++;
	return (i);
}

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	length;
	unsigned int	i;

	length = length_function(src);
	i = 0;
	while (src[i] && (i + 1 < size))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}
