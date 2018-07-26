/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:49:32 by arcohen           #+#    #+#             */
/*   Updated: 2018/06/01 12:55:30 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(const char *hay, const char *need, int len)
{
	while (*hay && (*hay++ == *need++) && len--)
		if (!*need)
			return (1);
	return (0);
}

char			*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t i;

	i = 0;
	if (!(*need))
		return ((char *)hay);
	while (hay[i] && len)
	{
		if (check((hay + i), need, len))
			return ((char *)(hay + i));
		len--;
		i++;
	}
	return (0);
}
