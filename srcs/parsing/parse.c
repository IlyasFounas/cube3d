/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:56:42 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/27 14:50:16 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	copy_file(t_map_infos *map)
{
	char	*line;
	int		i;
	char	**ptr;

	line = NULL;
	i = 0;
	ptr = NULL;
	while (get_next_line(map->fd.fd, &line, &map->err_gnl) >= 0 && line != NULL)
	{
		ptr = ft_realloc(ptr, i * sizeof(char *), (i + 2) * sizeof(char *));
		check_copy_error(!ptr, map, &line, MSG_ERR_ML_ER);
		map->tmp_map = ptr;
		ptr[i] = append_map(map, line);
		check_copy_error(!ptr[i], map, &line, NULL);
		i++;
		free(line);
	}
	free(line);
	exit_if(map->err_gnl, map, MSG_ERR_ML_ER, EXIT_FAILURE);
}

void	new_tmp_map(t_map_infos *map, char **truncated_map, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		truncated_map[i] = ft_strdup(map->tmp_map[start]);
		if (!truncated_map[i])
		{
			while (i > 0)
			{
				i--;
				free(truncated_map[i]);
			}
			exit_if(true, map, MSG_ERR_ML_ER, EXIT_FAILURE);
		}
		i++;
		start++;
	}
	truncated_map[i] = NULL;
	map->height = end - (start - i) + 1;
}

char	**truncate_scene(t_map_infos *map)
{
	int		i;
	int		start;
	int		end;
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
		exit_if(true, map, MSG_ERR_MP_MC, EXIT_FAILURE);
	truncated_map = ft_calloc((end - start + 2), sizeof(char *));
	exit_if(!truncated_map, map, MSG_ERR_ML_ER, EXIT_FAILURE);
	new_tmp_map(map, truncated_map, start, end);
	free_dbl_char(map->tmp_map, 0, dbl_char_len(map->tmp_map), true);
	return (truncated_map);
}

void	parse_map(t_map_infos *map)
{
	map->tmp_map = truncate_scene(map);
	if (!check_map_validity(map))
		exit_if(true, map, NULL, EXIT_FAILURE);
	exit_if(!map->player_found, map, MSG_ERR_MP_PF, EXIT_FAILURE);
	if (!is_surr_by_wall(map))
		exit_if(true, map, MSG_ERR_MP_WL, EXIT_FAILURE);
	if (map->player_found == 'N')
		map->start_angle = -90;
	else if (map->player_found == 'S')
		map->start_angle = 90;
	else if (map->player_found == 'E')
		map->start_angle = 0;
	else
		map->start_angle = 180;
}

bool	parse_scene(t_map_infos *map)
{
	if (!is_cub_file(map->fd.name))
	{
		printf(MSG_ERR_MP_EX);
		return (false);
	}
	if (!get_map_width(map))
		return (false);
	if (!safe_open(map->fd.name, &map->fd.fd))
		return (false);
	copy_file(map);
	exit_if(!map->tmp_map, map, "Error\nConfiguration file empty", EXIT_FAILURE);
	exit_if(!check_invalid(map), map, NULL, EXIT_FAILURE);
	parse_textures(map);
	parse_colors(map);
	parse_map(map);
	close(map->fd.fd);
	return (true);
}
