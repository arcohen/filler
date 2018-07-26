/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:39:42 by arcohen           #+#    #+#             */
/*   Updated: 2018/05/23 14:07:02 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s, const char *s2)
{
	int i;

	i = 0;
	while ((unsigned char)s[i] && (unsigned char)s[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s[i] - (unsigned char)s2[i]);
}
