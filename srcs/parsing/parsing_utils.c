/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 04:31:05 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/25 17:45:36 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_content(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}

bool	is_spacestr(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_invalid(t_map_infos *map)
{
	int	i;

	i = 0;
	while (map->tmp_map[i])
	{
		if (!is_texture(map->tmp_map[i]) && !is_map(map->tmp_map[i])
			&& !is_spacestr(map->tmp_map[i]) && !((map->tmp_map[i][0] == 'F'
				|| map->tmp_map[i][0] == 'C') && is_color(map->tmp_map[i])))
		{
			printf("Error\nCub3d: wrong file configuration at line %d", i + 1);
			return (false);
		}
		i++;
	}
	return (true);
}
