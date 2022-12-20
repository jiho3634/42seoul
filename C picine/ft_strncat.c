/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:26:16 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/13 09:35:56 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_size;
	unsigned int	src_index;

	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	src_index = 0;
	while (src[src_index] && src_index < nb)
	{
		dest[dest_size] = src[src_index];
		dest_size++;
		src_index++;
	}
	dest[dest_size] = '\0';
	return (dest);
}
