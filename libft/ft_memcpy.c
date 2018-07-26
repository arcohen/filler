/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:51:39 by arcohen           #+#    #+#             */
/*   Updated: 2018/05/18 14:25:44 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *ptr1;
	char *ptr2;

	ptr1 = dst;
	ptr2 = (char *)src;
	while (n--)
		*ptr1++ = *ptr2++;
	return (dst);
}
