/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:56:42 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/19 04:44:46 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void copy_file(t_map_infos *map)
{
	char *line;
	int i;

	map->tmp_map = NULL;
	line = NULL;
	i = 0;
	while (get_next_line(map->fd.fd, &line) >= 0 && line != NULL)
	{
		// printf("Line read: %s\n", line);
		map->tmp_map = ft_realloc(map->tmp_map, i * sizeof(char *), (i + 2) * sizeof(char *));
		exit_if(!map->tmp_map, map, "Cub3D: malloc error", EXIT_FAILURE);
		map->tmp_map[i] = append_map(map, line);
		exit_if(!(map->tmp_map[i]), map, NULL, EXIT_FAILURE);
		printf("%s\n", map->tmp_map[i]);
		i++;
		free(line);
	}
	printf("\n\n");
	free(line);
}

bool	is_cub_file(char *filename)
{
	int len;
	
	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}

char	**truncate_scene(t_map_infos *map)
{
	int	i;
	int	start;
	int	end;
	char	**truncated_map;

	i = 0;
	start = -1;
	end = -1;
	while (map->tmp_map[i])
	{
		if (is_map(map->tmp_map[i]) && start == -1)
			start = i;
		if (is_map(map->tmp_map[i]))
			end = i;
		i++;
	}
	if (start == -1 || end == -1)
		exit_if(true, map, "Cub3D: missing map configuration", EXIT_FAILURE);
	truncated_map = ft_calloc((end - start + 2), sizeof(char *));
	exit_if(!truncated_map, map, "Cub3D: malloc error", EXIT_FAILURE);
	i = 0;
	while (start <= end)
	{
		truncated_map[i] = map->tmp_map[start];
		printf("%s\n", truncated_map[i]);
		i++;
		start++;
	}
	truncated_map[i] = NULL;
	map->height = end - (start - i) + 1;
	// free_dbl_char(map->tmp_map, 0, start - i);
	printf("Map height: %d\n", map->height);
	return (truncated_map);
}

void	parse_map(t_map_infos *map)
{
	map->tmp_map = truncate_scene(map);
	if (!check_map_validity(map))
		exit_if(true, map, NULL, EXIT_FAILURE);
	if (!is_surr_by_wall(map))
		exit_if(true, map, "Cub3D: map is not surrounded by walls", EXIT_FAILURE);
}

bool	parse_scene(t_map_infos *map)
{
	if (!is_cub_file(map->fd.name))
	{
		printf("Cub3d: invalid file extension `.cub' file expected\n");
		return (false);
	}
	if (!get_map_width(map))
		return (false);
	if (!safe_open(map->fd.name, &map->fd.fd))
		return (false);
	copy_file(map);
	parse_textures(map);
	parse_colors(map);
	parse_map(map);
	close(map->fd.fd);
	return (true);
}
