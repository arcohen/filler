/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:26:10 by arcohen           #+#    #+#             */
/*   Updated: 2018/07/20 12:22:43 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_map
{
	char		**map;
	int			map_size_x;
	int			map_size_y;
	char		**token;
	int			token_size_x;
	int			token_size_y;
	char		player;
	char		enemy;
	int			hot_y;
	int			hot_x;
	int			hottest;
	int			first;
	int			fail;
}				t_map;

void			extract(t_map *map);
void			find_heat(t_map *map);

#endif
