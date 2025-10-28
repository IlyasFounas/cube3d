/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:13:24 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/28 17:14:59 by aboumall         ###   ########.fr       */
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
