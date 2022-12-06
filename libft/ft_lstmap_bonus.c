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

#include <stdlib.h>
#include "libft.h"

static t_list	*lstnew(void *content, void *(*f)(void *), \
		void (*del)(void *))
{
	t_list	*node;
	void	*temp;

	if (!content || !(*f) || !*del)
		return (0);
	node = (t_list *) malloc(sizeof(t_list));
	if (node)
	{
		temp = (*f)(content);
		if (!temp)
		{
			free(node);
			return (0);
		}
		node -> content = temp;
		node -> next = NULL;
	}
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*head;

	if (!lst)
		return (NULL);
	head = lstnew(lst -> content, *f, del);
	lst = lst -> next;
	while (lst && head)
	{
		temp = lstnew(lst -> content, *f, del);
		if (!temp)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, temp);
		lst = lst -> next;
	}
	return (head);
}
