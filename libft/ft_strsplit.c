/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:20:19 by arcohen           #+#    #+#             */
/*   Updated: 2018/06/01 12:16:37 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rows(char const *str, char c)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == c)
			;
		else if (!i || str[i - 1] == c)
			ret++;
		i++;
	}
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	size_t	j;
	int		start;

	if (!s)
		return (0);
	if (!(ret = (char **)malloc(sizeof(char *) * (rows(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			ret[j++] = ft_strsub(s, start, (i - start));
		}
	}
	ret[j] = 0;
	return (ret);
}
