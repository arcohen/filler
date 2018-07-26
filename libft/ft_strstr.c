/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:06:26 by arcohen           #+#    #+#             */
/*   Updated: 2018/05/28 17:08:33 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check(const char *hay, const char *need)
{
	while (*hay++ == *need++)
		if (!(*need))
			return (1);
	return (0);
}

char		*ft_strstr(const char *hay, const char *need)
{
	int i;

	i = 0;
	if (!need[i])
		return ((char *)hay);
	while (hay[i])
	{
		if (check((hay + i), need))
			return ((char *)hay + i);
		i++;
	}
	return (0);
}
