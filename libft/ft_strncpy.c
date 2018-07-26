/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:25:22 by arcohen           #+#    #+#             */
/*   Updated: 2018/05/24 10:28:52 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;
	int boo;

	boo = 1;
	i = 0;
	while (len > 0)
	{
		if (src[i] && boo)
			dst[i] = src[i];
		else
		{
			boo = 0;
			dst[i] = 0;
		}
		i++;
		len--;
	}
	return (dst);
}
