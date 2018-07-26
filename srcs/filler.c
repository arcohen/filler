/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:50:55 by arcohen           #+#    #+#             */
/*   Updated: 2018/07/20 12:23:48 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	map->first = 1;
	map->fail = 1;
	while (map->fail)
	{
		extract(map);
		find_heat(map);
		if (map->hottest == 0)
			map->fail = 0;
		ft_putnbr(map->hot_y);
		ft_putchar(' ');
		ft_putnbr(map->hot_x);
		ft_putchar('\n');
		free(map->token);
		free(map->map);
	}
	free(map);
	return (0);
}
