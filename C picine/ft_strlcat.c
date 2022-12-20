/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:30:15 by jihokim2          #+#    #+#             */
/*   Updated: 2022/10/16 17:31:46 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	i;

	dest_size = 0;
	src_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[src_size])
		src_size++;
	i = 0;
	if (dest_size > size)
		return (size + src_size);
	else if (dest_size <= size)
	{
		while ((dest_size + i < size - 1) && src[i])
		{
			dest[dest_size + i] = src[i];
			i++;
		}
		dest[dest_size + i] = '\0';
		return (dest_size + src_size);
	}
	return (0);
}
