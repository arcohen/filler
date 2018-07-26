/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:32:31 by arcohen           #+#    #+#             */
/*   Updated: 2018/05/28 16:50:09 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*nstr;
	unsigned int	i;

	i = -1;
	if (!s || !f)
		return (0);
	nstr = ft_strdup(s);
	if (!nstr)
		return (0);
	while (nstr[++i])
		nstr[i] = f(i, nstr[i]);
	return (nstr);
}
