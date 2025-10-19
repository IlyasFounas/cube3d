/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:47:50 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/19 04:44:43 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool is_map(char *s)
{
	int i;

	i = 0;
	while (s[i] && is_space(s[i]))
		i++;
	if (s[i] == '\0')
		return (false);
	if (s[i] == '1' || s[i] == '0')
		return (true);
	return (false);
}

bool get_map_width(t_map_infos *map)
{
	int width;
	char *line;

	line = NULL;
	width = 0;
	if (!safe_open(map->fd.name, &map->fd.fd))
		return (false);
	while (get_next_line(map->fd.fd, &line) > 0 && line != NULL)
	{
		width = ft_line_len(line);
		if (width > map->width)
			map->width = width;
		free(line);
	}
	free(line);
	close(map->fd.fd);
	return (true);
}

void add_tab(char *line, int *i)
{
	// add 4 spaces for a tab
	line[*i] = ' ';
	line[*i + 1] = ' ';
	line[*i + 2] = ' ';
	line[*i + 3] = ' ';
	*i += 4;
}

char *append_map(t_map_infos *map, char *line)
{
	int i;
	int j;
	char *new_line;

	i = 0;
	j = 0;
	new_line = ft_calloc(map->width + 1, sizeof(char));
	if (!new_line)
	{
		printf("Cub3d: malloc error\n");
		return (NULL);
	}
	while (line[i])
	{
		if (line[i] == '\t')
		{
			add_tab(new_line, &j);
			i++;
			continue;
		}
		new_line[j] = line[i];
		j++;
		i++;
	}
	while (j < map->width)
	{
		new_line[j] = ' ';
		j++;
	}
	return (new_line);
}

char found_first(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '1' && line[i] != '0')
		i++;
	return (line[i]);
}

char found_last(char *line)
{
	int i;

	i = ft_strlen(line);
	while (i >= 0 && line[i] != '1' && line[i] != '0')
		i--;
	return (line[i]);
}

bool is_surr_floor(t_map_infos *map, int x, int y)
{
	if (is_space(map->tmp_map[x][y + 1]) || is_space(map->tmp_map[x][y - 1]) || is_space(map->tmp_map[x + 1][y]) || is_space(map->tmp_map[x - 1][y]))
	{
		return (false);
	}
	return (true);
}

bool	check_map_validity(t_map_infos *map)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (map->tmp_map[x])
	{
		while (map->tmp_map[x][y])
		{
			if (!is_content(map->tmp_map[x][y]) && !is_space(map->tmp_map[x][y]))
			{
				printf("Cub3D: invalid character '%c' in map\n", map->tmp_map[x][y]);
				return (false);
			}
			if (is_player(map->tmp_map[x][y]))
			{
				if (map->player_found)
				{
					printf("Cub3D: multiple player start positions found\n");
					return (false);
				}
				map->player_found = map->tmp_map[x][y];
				map->x = x;
				map->y = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (!map->player_found)
	{
		printf("Cub3D: no player start position found\n");
		return (false);
	}
	return (true);
}

bool is_surr_by_wall(t_map_infos *map)
{
	int x;
	int y;

	x = 1;
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
		if (map->tmp_map[map->height - 1][y] != '1' && !is_space(map->tmp_map[map->height - 1][y]))
			return (false);
		y++;
	}
	while (x < map->height)
	{
		if (found_first(map->tmp_map[x]) != '1')
			return (false);
		if (found_last(map->tmp_map[x]) != '1')
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

void free_map(t_map_infos *map)
{
	if (!map)
		return;
	if (map->tmp_map)
		free_dbl_char(map->tmp_map, 0, dbl_char_len(map->tmp_map));
	// free_fd(&map->fd);
	// free_fd(&map->no_path);
	// free_fd(&map->so_path);
	// free_fd(&map->we_path);
	// free_fd(&map->ea_path);
	map = NULL;
}

void init_map(t_map_infos *map)
{
	map->tmp_map = NULL;
	map->height = 0;
	map->width = 0;
	map->start_angle = 0;
	map->x = 0;
	map->y = 0;
	map->player_found = false;
	init_fd(map, &map->no_path, NULL, -1);
	init_fd(map, &map->so_path, NULL, -1);
	init_fd(map, &map->we_path, NULL, -1);
	init_fd(map, &map->ea_path, NULL, -1);
	init_fd(map, &map->fd, NULL, -1);
	map->floor_color = (t_color){-1, -1, -1};
	map->ceiling_color = (t_color){-1, -1, -1};
}