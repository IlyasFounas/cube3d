/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:47:21 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/27 10:21:25 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	check_map_validity(t_map_infos *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->tmp_map[x])
	{
		y = 0;
		while (map->tmp_map[x][y])
		{
			if (!is_content(map->tmp_map[x][y])
				&& !is_space(map->tmp_map[x][y]))
				return (printf(MSG_ERR_MP_IC, map->tmp_map[x][y]), false);
			if (is_player(map->tmp_map[x][y]))
			{
				if (map->player_found)
					return (printf(MSG_ERR_MP_MP), false);
				map->player_found = map->tmp_map[x][y];
				map->x = y;
				map->y = x;
			}
			y++;
		}
		x++;
	}
	return (true);
}

bool	north_south_walls(t_map_infos *map)
{
	int	y;

	y = 0;
	while (map->tmp_map[0][y])
	{
		if (map->tmp_map[0][y] != '1' && !is_space(map->tmp_map[0][y]))
			return (false);
		y++;
	}
	y = 0;
	while (map->tmp_map[map->height - 1][y])
	{
		if (map->tmp_map[map->height - 1][y] != '1'
			&& !is_space(map->tmp_map[map->height - 1][y]))
			return (false);
		y++;
	}
	return (true);
}

bool	is_surr_by_wall(t_map_infos *map)
{
	int	x;
	int	y;

	x = 1;
	if (!north_south_walls(map))
		return (false);
	while (x < map->height)
	{
		if (found_first(map->tmp_map[x]) != '1'
			|| found_last(map->tmp_map[x]) != '1')
			return (false);
		y = 0;
		while (map->tmp_map[x][y])
		{
			if (map->tmp_map[x][y] == '0' && !is_surr_floor(map, x, y))
				return (false);
			y++;
		}
		x++;
	}
	return (true);
}
