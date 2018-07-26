/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:04:06 by arcohen           #+#    #+#             */
/*   Updated: 2018/06/01 10:34:09 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int			i;
	long int	nb;

	nb = n;
	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int			i;
	long int	nb;
	char		*str;

	nb = n;
	i = intlen(nb);
	if (!(str = ft_strnew(i + 1)))
		return (0);
	if (!nb)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		i++;
		nb *= -1;
		str[0] = '-';
	}
	while (nb)
	{
		str[--i] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
