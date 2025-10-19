/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 04:32:55 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/19 04:44:49 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool is_texture(char *s)
{
	int i;

	i = 0;
	while (s[i] && is_space(s[i]))
		i++;
	if (s[i] == '\0')
		return (false);
	if (is_content(s[0]) && s[0] != '1' && s[0] != '0')
	{
		i++;
		if (s[i] != 'O' && s[i] != 'E' && s[i] != 'A')
			return (false);
		i++;
		if (!is_space(s[i]))
			return (false);
		while (s[i] && is_space(s[i]))
			i++;
		return (!(s[i] == '\0'));
	}
	return (false);
}

void	parse_textures(t_map_infos *map)
{
	int	i;
	int	textures_found;
	char	*path;

	i = 0;
	textures_found = 0;
	while (map->tmp_map[i] && textures_found < 4)
	{
		if (is_map(map->tmp_map[i]))
			exit_if(true, map, "Cub3D: wrong file configuration map should be last", EXIT_FAILURE);
		if (is_texture(map->tmp_map[i]))
		{
			// handle double texture definition error
			printf("Found texture: %s\n", map->tmp_map[i]);
			textures_found++;
			path = ft_strtrim(map->tmp_map[i] + 2, " \t\v\f\r");
			exit_if(!path, map, "Cub3D: malloc error", EXIT_FAILURE);
			if (ft_strncmp(map->tmp_map[i], "NO", 2) == 0)
				init_fd(map, &map->no_path, path, -1);
			else if (ft_strncmp(map->tmp_map[i], "SO", 2) == 0)
				init_fd(map, &map->so_path, path, -1);
			else if (ft_strncmp(map->tmp_map[i], "WE", 2) == 0)
				init_fd(map, &map->we_path, path, -1);
			else if (ft_strncmp(map->tmp_map[i], "EA", 2) == 0)
				init_fd(map, &map->ea_path, path, -1);
			free(path);
		}
		i++;
	}
	if (textures_found < 4)
		exit_if(true, map, "Cub3D: missing texture files", EXIT_FAILURE);
}
