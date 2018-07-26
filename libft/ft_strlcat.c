/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:10:38 by arcohen           #+#    #+#             */
/*   Updated: 2018/06/01 10:32:50 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	n = size;
	d = dst;
	s = src;
	while (n-- && *d)
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (!n)
		return (dlen + ft_strlen(s));
	while (*s && n-- > 1)
		*d++ = *s++;
	*d = 0;
	return (dlen + ft_strlen(src));
}
