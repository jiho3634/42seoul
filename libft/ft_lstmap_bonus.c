/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:54:57 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/05 19:58:35 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp_struct;
	t_list	*new_lst;
	void	*temp_content;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		temp_content = f(lst -> content);
		temp_struct = ft_lstnew(temp_content);
		if (!temp_struct)
		{
			del(temp_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp_struct);
		lst = lst -> next;
	}
	return (new_lst);
}
