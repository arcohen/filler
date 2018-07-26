/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:26:48 by arcohen           #+#    #+#             */
/*   Updated: 2018/05/31 20:36:11 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *head;
	t_list *prev;

	if (!lst)
		return (NULL);
	if (!(head = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	head = f(lst);
	lst = lst->next;
	prev = head;
	while (lst)
	{
		if (!(new = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new = f(lst);
		prev->next = new;
		prev = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (head);
}
