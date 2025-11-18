/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:13:24 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/18 17:06:56 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	check_xpm_file(t_map_infos *map)
{
	if (!is_xpm_file(map->no_path.name))
	{
		printf("Error\nCub3d: invalid file extension for NO texture `%s'\n",
			map->no_path.name);
		return (false);
	}
	if (!is_xpm_file(map->so_path.name))
	{
		printf("Error\nCub3d: invalid file extension for SO texture `%s'\n",
			map->so_path.name);
		return (false);
	}
	if (!is_xpm_file(map->we_path.name))
	{
		printf("Error\nCub3d: invalid file extension for WE texture `%s'\n",
			map->we_path.name);
		return (false);
	}
	if (!is_xpm_file(map->ea_path.name))
	{
		printf("Error\nCub3d: invalid file extension for EA texture `%s'\n",
			map->ea_path.name);
		return (false);
	}
	return (true);
}

void	*free_tab(int **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

void	fill_cells(t_map_infos *map, int **f_map, int x, int y)
{
	if (is_space(map->tmp_map[x][y]))
		f_map[x][y] = 8;
	else if (is_player(map->tmp_map[x][y]))
		f_map[x][y] = 0;
	else
		f_map[x][y] = map->tmp_map[x][y] - '0';
}
