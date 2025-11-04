/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:54:22 by ifounas           #+#    #+#             */
/*   Updated: 2025/11/04 15:10:57 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	fill_textures(t_global_infos *infos, char **textures,
		t_type *types)
{
	textures[0] = infos->map_infos->no_path.name;
	textures[1] = infos->map_infos->so_path.name;
	textures[2] = infos->map_infos->ea_path.name;
	textures[3] = infos->map_infos->we_path.name;
	types[0] = NORTH;
	types[1] = SOUTH;
	types[2] = EAST;
	types[3] = WEST;
}

void	create_textures(t_global_infos *infos)
{
	int			i;
	int			malloc_failed;
	char		*textures[4];
	t_type		types[4];
	t_textures	*ptr;

	i = 0;
	malloc_failed = 0;
	fill_textures(infos, textures, types);
	infos->textures = new_node_texture(textures[i], types[i]);
	if (!infos->textures)
		malloc_error(infos);
	ptr = infos->textures;
	while (++i < 5)
	{
		init_textures(infos, ptr);
		add_back_node(&infos->textures, new_node_texture(textures[i], types[i]),
			&malloc_failed);
		if (malloc_failed == 1)
			malloc_error(infos);
		ptr = ptr->next;
	}
}
