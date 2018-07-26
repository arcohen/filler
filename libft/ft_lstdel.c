/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:13:33 by arcohen           #+#    #+#             */
/*   Updated: 2018/05/31 17:38:57 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nxt;
	t_list *crnt;

	crnt = *alst;
	while (crnt)
	{
		nxt = crnt->next;
		del(crnt->content, crnt->content_size);
		free(crnt);
		crnt = nxt;
	}
	*alst = NULL;
}
