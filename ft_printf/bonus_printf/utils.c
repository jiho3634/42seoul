/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:12:32 by jihokim2          #+#    #+#             */
/*   Updated: 2023/01/11 18:28:30 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_flag(char c)
{
	if (c == '-' || c  == '0' || c == '+' || c == ' ' || c == '#')
		return (plus_data(format, lst));
	return (0);
}

t_list	*ft_lstnew(t_list *lst)
{
	t_list			new;
	unsigned char	*ptr;
	size_t			i;

	new = (t_list *) malloc (sizeof(t_list));
	if (new)
	{
		ptr = (unsigned char *) new;
		i = 0;
		while (i < sizeof(t_list))
			*(ptr + i++) = 0;
		lst -> next = new;
	}
	return (new);
}
