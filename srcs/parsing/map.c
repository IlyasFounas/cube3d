#include "cube3d.h"
#include <sys/stat.h>
#include <fcntl.h>

t_bool	is_content(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

t_bool	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	get_map_width(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	free_dbl_char(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i]);
	free(tab);
	tab = NULL;
}

t_bool	has_minimum_texture_size(char *s)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (!is_space(s[i]))
			size++;
		i++;
	}
	return (size >= 3);
}

t_bool	is_valid_file(char *s)
{
	if (open(s, O_RDONLY) < 0)
		return (false);
}

t_bool	is_texture(char *s)
{
	int	i;

	i = 2;
	if (!has_minimum_texture_size(s))
		return (false);
	if (is_content(s[0]) && s[0] != '1' && s[0] != '0')
	{
		if (s[1] != 'O' || s[1] != 'E' || s[1] != 'A')
			return (false);
		while (is_space(s[i]))
			i++;
	}
	if (!is_valid_file(s&[i]))
		return (false);
}

t_bool	file_to_char(t_map *map, int fd, char **res)
{
	char	*line;

	res = NULL;
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		if (map->width == 0)
			map->width = get_map_width(line);
		else if (get_map_width(line) != map->width)
		{
			ft_putendl_fd("cub3D: map must be a square", 2);
			free_dbl_char(res);
			return (false);
		}
		res = ft_realloc(res, map->height * sizeof(char *), map->height
				* sizeof(char *) + 2);
		res[map->height] = ft_strdup(line);
		if (res[map->height] == NULL)
		{
			ft_putendl_fd("cub3D: malloc error", 2);
			free_dbl_char(res);
			return (false);
		}
		map->height++;
	}
	return (true);
}

t_bool	is_surr_by_wall(t_map *map, char **tmp_map)
{
	int i;

	i = 0;
	while (tmp_map[0][i])
	{
		if (tmp_map[0][i] != '0' || !is_space(tmp_map[0][i]))
			return (false);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (tmp_map[i][0] != '0' || !is_space(tmp_map[i][0]))
			return (false);
		if (tmp_map[i][map->height] != '0' || !is_space(tmp_map[i][map->height]))
			return (false);
	}
	return (true);
}

t_bool	is_valid_map(t_map *map, int fd)
{
	char	**tmp_map;
	int	i;
	int j

	i = 0;
	if (file_to_char(map, fd, tmp_map) == false)
		return (false);
	if (is_surr_by_wall(map, tmp_map) == false)
	{
		ft_putendl_fd("cub3D: map should be surrounded by walls", 2);
		free_dbl_char(tmp_map);
		return (false);
	}
	while (tmp_map[i])
	{
		j = 0;
		while(tmp_map[i][j])
		{
			if (j > 0 && is_content(tmp_map[i][j]) && !is_space(tmp_map[i][j - 1]))
			{
				ft_putendl_fd("cub3D: map content should only be separetad by spaces", 2);
				return (false);
			}
			j++;
		}
	}
}

void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->start_angle = 0;
	map->x = 0;
	map->y = 0;
}
