/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:32:31 by arcohen           #+#    #+#             */
/*   Updated: 2018/05/30 14:35:59 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*nstr;
	int		i;

	i = -1;
	if (!s || !f)
		return (0);
	if (!(nstr = ft_strdup(s)))
		return (0);
	while (nstr[++i])
		nstr[i] = f(nstr[i]);
	return (nstr);
}
