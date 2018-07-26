/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:42:11 by arcohen           #+#    #+#             */
/*   Updated: 2018/05/31 20:30:58 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*dst2;
	unsigned char	*src2;

	cc = (unsigned char)c;
	dst2 = dst;
	src2 = (unsigned char *)src;
	while (n--)
	{
		*dst2++ = *src2++;
		if (*(src2 - 1) == cc)
			return (unsigned char *)(dst2);
	}
	dst = 0;
	return (unsigned char *)(dst);
}
