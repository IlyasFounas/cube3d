/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 04:33:18 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/19 04:44:12 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool is_null_color(t_color color)
{
	return (color.r == -1 && color.g == -1 && color.b == -1);
}

bool is_color(char *str)
{
	int i;
	int colors;

	i = 0;
	colors = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == '\0')
		return (false);
	if (str[i] == 'F' || str[i] == 'C')
	{
		i++;
		if (!is_space(str[i]))
			return (false);
		while (str[i] && is_space(str[i]))
			i++;
		while (str[i] && (ft_isdigit(str[i]) || str[i] == ',') && colors < 2)
		{
			if (str[i] == ',')
				colors++;
			i++;
		}
		if (str[i] && !ft_isdigit(str[i]))
			return (false);
		return (colors == 2);
	}
	return (false);
}

void	parse_color(char *str, t_color *color)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		str++;
	if (*str == ',')
		str++;
	g = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		str++;
	if (*str == ',')
		str++;
	b = ft_atoi(str);
	color->r = r;
	color->g = g;
	color->b = b;
}

void	parse_colors(t_map_infos *map)
{
	int	i;
	int	colors_found;
	
	i = 0;
	colors_found = 0;
	while (map->tmp_map[i] && colors_found < 2)
	{
		if (is_map(map->tmp_map[i]))
			exit_if(true, map, "Cub3D: wrong file configuration map should be last", EXIT_FAILURE);
		if (is_color(map->tmp_map[i]))
		{
			// handle double color definition error
			printf("Found color: %s\n", map->tmp_map[i]);
			colors_found++;
			if (ft_strncmp(map->tmp_map[i], "F", 1) == 0)
				parse_color(map->tmp_map[i] + 1, &map->floor_color);
			else if (ft_strncmp(map->tmp_map[i], "C", 1) == 0)
				parse_color(map->tmp_map[i] + 1, &map->ceiling_color);
		}
		i++;
	}
	if (colors_found < 2)
		exit_if(true, map, "Cub3D: missing color configuration", EXIT_FAILURE);
}
