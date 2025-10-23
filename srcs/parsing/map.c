/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:47:50 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/23 17:27:36 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	get_map_width(t_map_infos *map)
{
	int		width;
	char	*line;

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

char	*append_map(t_map_infos *map, char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = ft_calloc(map->width + 1, sizeof(char));
	if (!new_line)
		return (printf(MSG_ERR_ML_ER "\n"), NULL);
	while (line[i])
	{
		if (line[i] == '\t')
		{
			add_tab(new_line, &j);
			i++;
			continue ;
		}
		new_line[j] = line[i];
		j++;
		i++;
	}
	while (j < map->width)
		new_line[j++] = ' ';
	return (new_line);
}

int	**fill_map(t_map_infos *map)
{
	int	**f_map;
	int	x;
	int	y;

	f_map = malloc(map->height * sizeof(int *));
	exit_if(!f_map, map, MSG_ERR_ML_ER, EXIT_FAILURE);
	x = 0;
	while (x < map->height)
	{
		y = 0;
		f_map[x] = malloc(map->width * sizeof(int));
		exit_if(!f_map[x], map, MSG_ERR_ML_ER, EXIT_FAILURE);
		while (y < map->width)
		{
			if (is_space(map->tmp_map[x][y]))
				f_map[x][y] = 8;
			else if (is_player(map->tmp_map[x][y]))
				f_map[x][y] = 0;
			else
				f_map[x][y] = map->tmp_map[x][y] - '0';
			y++;
		}
		x++;
	}
	return (f_map);
}

void	free_map(t_map_infos *map)
{
	if (!map)
		return ;
	if (map->tmp_map)
		free_dbl_char(map->tmp_map, 0, dbl_char_len(map->tmp_map), true);
	free_fd(&map->fd);
	free_fd(&map->no_path);
	free_fd(&map->so_path);
	free_fd(&map->we_path);
	free_fd(&map->ea_path);
	map = NULL;
}

void	init_map(t_map_infos *map, char *filename)
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
	init_fd(map, &map->fd, filename, -1);
	map->floor_color = (t_color){-1, -1, -1};
	map->ceiling_color = (t_color){-1, -1, -1};
}
