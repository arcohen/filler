/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 09:52:04 by arcohen           #+#    #+#             */
/*   Updated: 2018/06/01 12:17:23 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		beg;
	int		end;
	char	*str;

	if (!s)
		return (0);
	beg = 0;
	while (s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t')
		beg++;
	if (beg == ft_strlen(s))
		return (ft_strnew(1));
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	str = ft_strsub(s, beg, (end - beg + 1));
	return (str);
}
