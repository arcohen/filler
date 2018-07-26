/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:59:08 by arcohen           #+#    #+#             */
/*   Updated: 2018/05/28 16:39:05 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *dest;
	char *srce;

	dest = (char *)dst;
	srce = (char *)src;
	if (dest > srce)
		while (len--)
			*(dest + len) = *(srce + len);
	else
		while (len--)
		{
			*dest++ = *srce++;
		}
	return (dst);
}
