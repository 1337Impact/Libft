/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:59:17 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/12 11:02:47 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*hold;
	t_list	*head;
	t_list	*nex;
	t_list	*new;

	head = lst;
	if (!lst)
		return (0);
	new = malloc(sizeof(t_list));
	new->content = (*f)(lst->content);
	new->next = NULL;
	hold = new;
	lst = lst->next;
	while (lst)
	{
		nex = malloc(sizeof(t_list));
		new->next = nex;
		new = nex;
		new->content = (*f)(lst->content);
		new->next = NULL;
		lst = lst->next;
	}
	ft_lstclear(&head, del);
	return(hold);
}
