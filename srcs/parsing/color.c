/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 04:33:18 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/25 14:46:48 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_color(char *str)
{
	int	i;

	i = 0;
	i++;
	if (!is_space(str[i]))
		return (false);
	while (str[i] && is_space(str[i]))
		i++;
	if (!str[i])
		return (false);
	if (!is_rgb_format(str + i))
		return (false);
	return (true);
}

bool	parse_color(char *str, t_color *color)
{
	int	len;

	len = 0;
	while (is_space(*str))
		str++;
	color->r = ft_atoi(str);
	while (str[len] && ft_isdigit(str[len]))
		len++;
	if (str[len] != ',' || len > 3)
		return (false);
	len++;
	color->g = ft_atoi(str + len);
	while (str[len] && ft_isdigit(str[len]))
		len++;
	if (str[len] != ',' || len > 7)
		return (false);
	len++;
	if (ft_strlen_trim(str + len) > 3)
		return (false);
	color->b = ft_atoi(str + len);
	return (true);
}

bool	check_color(t_map_infos *map, char *str)
{
	if (ft_strncmp(str, "F", 1) == 0)
	{
		if (is_good_color(map->floor_color))
		{
			printf(MSG_ERR_CR_IF);
			return (false);
		}
	}
	if (ft_strncmp(str, "C", 1) == 0)
	{
		if (is_good_color(map->ceiling_color))
		{
			printf(MSG_ERR_CR_IC);
			return (false);
		}
	}
	return (true);
}

static void	trait_colors(t_map_infos *map, char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
	{
		exit_if(!is_null_color(map->floor_color), map, MSG_ERR_CR_MF,
			EXIT_FAILURE);
		exit_if(!is_color(line), map, MSG_ERR_CR_IF, EXIT_FAILURE);
		exit_if(!parse_color(line + 1, &map->floor_color), map, MSG_ERR_CR_IF,
			EXIT_FAILURE);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		exit_if(!is_null_color(map->ceiling_color), map, MSG_ERR_CR_MC,
			EXIT_FAILURE);
		exit_if(!is_color(line), map, MSG_ERR_CR_IC, EXIT_FAILURE);
		exit_if(!parse_color(line + 1, &map->ceiling_color), map, MSG_ERR_CR_IC,
			EXIT_FAILURE);
	}
	exit_if(!check_color(map, line), map, NULL, EXIT_FAILURE);
}

void	parse_colors(t_map_infos *map)
{
	int	i;
	int	colors_found;

	i = 0;
	colors_found = 0;
	while (map->tmp_map[i])
	{
		exit_if(is_map(map->tmp_map[i]) && colors_found < 2, map, MSG_ERR_MAP_L,
			EXIT_FAILURE);
		if (map->tmp_map[i][0] == 'F' || map->tmp_map[i][0] == 'C')
		{
			colors_found++;
			trait_colors(map, map->tmp_map[i]);
		}
		i++;
	}
	exit_if(colors_found < 2, map, MSG_ERR_CR_MS, EXIT_FAILURE);
}
