/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:46:00 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/22 17:46:52 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_map(char *s)
{
	int	i;

	i = 0;
	while (s[i] && is_space(s[i]))
		i++;
	if (s[i] == '\0')
		return (false);
	if (s[i] == '1' || s[i] == '0')
		return (true);
	return (false);
}

char	found_first(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '1' && line[i] != '0')
		i++;
	return (line[i]);
}

char	found_last(char *line)
{
	int	i;

	i = ft_strlen(line);
	while (i >= 0 && line[i] != '1' && line[i] != '0')
		i--;
	return (line[i]);
}

bool	is_surr_floor(t_map_infos *map, int x, int y)
{
	if (is_space(map->tmp_map[x][y + 1]) || is_space(map->tmp_map[x][y - 1])
		|| is_space(map->tmp_map[x + 1][y]) || is_space(map->tmp_map[x - 1][y]))
	{
		return (false);
	}
	return (true);
}

void	add_tab(char *line, int *i)
{
	line[*i] = ' ';
	line[*i + 1] = ' ';
	line[*i + 2] = ' ';
	line[*i + 3] = ' ';
	*i += 4;
}
