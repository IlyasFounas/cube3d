/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 04:32:55 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/28 17:13:40 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_texture(char *s)
{
	int	i;

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

bool	check_paths(t_map_infos *map)
{
	if (!check_xpm_file(map))
		return (false);
	if (!safe_open(map->no_path.name, &map->no_path.fd))
		return (false);
	if (!safe_open(map->so_path.name, &map->so_path.fd))
		return (false);
	if (!safe_open(map->we_path.name, &map->we_path.fd))
		return (false);
	if (!safe_open(map->ea_path.name, &map->ea_path.fd))
		return (false);
	return (true);
}

void	save_texture(t_map_infos *map, char *msg, char *path, t_fd *fd)
{
	if (fd->name)
	{
		free(path);
		exit_if(true, map, msg, EXIT_FAILURE);
	}
	init_fd(map, fd, path, -1);
}

void	trait_textures(t_map_infos *map, char *line, char *path)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		save_texture(map, MSG_ERR_TX_NO, path, &map->no_path);
	else if (ft_strncmp(line, "SO", 2) == 0)
		save_texture(map, MSG_ERR_TX_SO, path, &map->so_path);
	else if (ft_strncmp(line, "WE", 2) == 0)
		save_texture(map, MSG_ERR_TX_WE, path, &map->we_path);
	else if (ft_strncmp(line, "EA", 2) == 0)
		save_texture(map, MSG_ERR_TX_EA, path, &map->ea_path);
}

void	parse_textures(t_map_infos *map)
{
	int		i;
	int		textures_found;
	char	*path;

	i = 0;
	textures_found = 0;
	while (map->tmp_map[i])
	{
		exit_if(is_map(map->tmp_map[i]) && textures_found < 4, map,
			MSG_ERR_MAP_L, EXIT_FAILURE);
		if (is_texture(map->tmp_map[i]))
		{
			textures_found++;
			path = ft_strtrim(map->tmp_map[i] + 2, " \t\v\f\r");
			exit_if(!path, map, MSG_ERR_ML_ER, EXIT_FAILURE);
			trait_textures(map, map->tmp_map[i], path);
			free(path);
		}
		i++;
	}
	exit_if(textures_found < 4, map, MSG_ERR_TX_MS, EXIT_FAILURE);
	exit_if(!check_paths(map), map, NULL, EXIT_FAILURE);
}
