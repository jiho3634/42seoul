/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:41:57 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/13 12:23:56 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	dest_size;
	int	i;

	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	i = 0;
	while (src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest);
}
