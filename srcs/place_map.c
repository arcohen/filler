/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:32:46 by arcohen           #+#    #+#             */
/*   Updated: 2018/07/20 12:21:54 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		add(int i, int y)
{
	if (i > y)
		return (i - y);
	return (y - i);
}

int		check_plyr(t_map *map, int y, int x)
{
	char c;

	c = map->map[y][x];
	if (c == map->player || c == map->player - 32)
		return (1);
	if (c == map->enemy || c == map->enemy - 32)
		return (0);
	return (2);
}

int		get_heat_nbr(t_map *map, int i, int j)
{
	int		y;
	int		x;
	int		ret;
	float	ptweak;

	ptweak = -2;
	if (map->map_size_x > 40)
		ptweak = -1;
	y = -1;
	ret = 0;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (check_plyr(map, y, x) == 0)
				ret += (add(i, y) + add(j, x));
			if (check_plyr(map, y, x) == 1)
				ret += ptweak * (add(i, y) + add(j, x));
		}
	}
	return (ret);
}

int		check_placement(t_map *map, int i, int j)
{
	int k;
	int l;
	int count;

	if (map->token_size_x > map->map_size_x - j)
		return (0);
	if (map->token_size_y > map->map_size_y - i)
		return (0);
	k = -1;
	count = 0;
	while (map->token[++k])
	{
		l = -1;
		while (map->token[k][++l])
		{
			if (map->token[k][l] == '*' && check_plyr(map, i + k, j + l) == 1)
				count++;
			else if (map->token[k][l] == '*' && !check_plyr(map, i + k, j + l))
				return (0);
		}
	}
	if (count > 1 || count == 0)
		return (0);
	return (1);
}

void	find_heat(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->hottest = 0;
	map->hot_y = 0;
	map->hot_x = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (check_placement(map, i, j))
			{
				if (get_heat_nbr(map, i, j) < map->hottest || map->hottest == 0)
				{
					map->hottest = get_heat_nbr(map, i, j);
					map->hot_y = i;
					map->hot_x = j;
				}
			}
			j++;
		}
		i++;
	}
}
