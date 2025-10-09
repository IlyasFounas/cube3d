#include "cube3d.h"
#include <fcntl.h>
#include <sys/stat.h>

void	free_map(t_map_infos *map);
void	exit_if(t_bool cnd, t_map_infos *map, char *msg, int code);

t_bool	is_content(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

t_bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

t_bool	is_white_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

t_bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r');
}

t_bool	is_spacestr(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_white_space(line[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_line_len(char *line)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			size += 3;
		size++;
		i++;
	}
	return (size);
}

int	get_map_width(int fd)
{
	int	width;
	int	max_width;
	char	*line;

	line = NULL;
	max_width = 0;
	width = 0;
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		if (is_spacestr(line))
		{
			free(line);
			continue ;
		}
		width = ft_line_len(line);
		if (width > max_width)
			max_width = width;
		free(line);
	}
	free(line);
	return (max_width);
}

void	free_dbl_char(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
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
	return (true);
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
	if (!is_valid_file(&s[i]))
		return (false);
	return (true);
}

void	add_tab(char *line, int *i)
{
	int j;

	j = 4;
	while (j < 4 && line[*i])
	{
		line[*i] = ' ';
		(*i)++;
		j++;
	}
}

char	*append_map(t_map_infos *map, char *line)
{
	int	i;
	int	j;
	char *new_line;

	i = 0;
	while (line[i])
	{
		if (!is_content(line[i]) && !is_space(line[i]))
		{
			printf("Cub3d: invalid map parameter `%c'\n", line[i]);
			return (NULL);
		}
		i++;
	}
	new_line = ft_calloc(map->width + 1, sizeof(char));
	if (!new_line)
	{
		printf("Cub3d: malloc error\n");
		return (NULL);
	}
	i = 0;
	j = 0;
	while (line[i])
	{
		if (is_content(line[i]))
		{
			if (is_player(line[i]))
				map->player_found = true;
			new_line[j] = line[i];
			j++;
		}
		else if (line[i] == '\t')
		{
			int y = 0;
			while (y < 4)
			{
				new_line[j] = ' ';
				j++;
				y++;
			}
		}
		else
		{
			new_line[j] = ' ';
			j++;
		}
		i++;
	}
	while (j < map->width)
	{
		new_line[j] = ' ';
		j++;
	}
	return (new_line);
}

t_bool	file_map(t_map_infos *map, int fd)
{
	char	*line;
	int	width;

	map->tmp_map = NULL;
	line = NULL;
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		if (is_spacestr(line))
		{
			free(line);
			exit_if(true, map, "Cub3d: invalid map", EXIT_FAILURE);
		}
		width = ft_strlen(line);
		if (width > map->width)
			map->width = width;
		map->tmp_map = ft_realloc(map->tmp_map, map->height * sizeof(char *), (map->height + 2)
				* sizeof(char *));
		exit_if(!map->tmp_map, map, "Cub3D: malloc error", EXIT_FAILURE);
		map->tmp_map[map->height] = append_map(map, line);
		exit_if(!(map->tmp_map[map->height]), map, NULL, EXIT_FAILURE);
		printf("line[%d]: %s\n", map->height + 1, map->tmp_map[map->height]);
		map->height++;
		free(line);
	}
	free(line);
	exit_if(!map->player_found, map, "Cub3d: invalid map no player found", EXIT_FAILURE);
	return (true);
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

t_bool	is_surr_floor(t_map_infos *map, int x, int y)
{
	if (is_space(map->tmp_map[x][y + 1]) || is_space(map->tmp_map[x][y - 1])
		|| is_space(map->tmp_map[x + 1][y]) || is_space(map->tmp_map[x - 1][y]))
	{
		return (false);
	}
	return (true);
}

t_bool	is_surr_by_wall(t_map_infos *map)
{
	int	x;
	int	y;

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
			if (map->tmp_map[x][y] == '0' && !is_surr_floor(map , x, y))
				return (false);
			y++;
		}
		x++;
	}
	return (true);
}

void	init_fd(t_map_infos *map, t_fd *fd, char *name, int fd_i)
{
	if (!name)
		fd->name = NULL;
	else
	{
		fd->name = ft_strdup(name);
		exit_if(!fd->name, map, "Cub3d: malloc error", EXIT_FAILURE);
	}
	fd->fd = fd_i;
}

void	init_color(t_color *color, t_color new_color)
{
	color->r = new_color.r;
	color->g = new_color.g;
	color->b = new_color.b;
}

void	exit_if(t_bool cnd, t_map_infos *map, char *msg, int code)
{
	if (cnd == true)
	{
		free_map(map);
		if (msg)
			printf("%s\n", msg);
		exit(code);
	}
}

void	free_map(t_map_infos *map)
{
	if (!map)
		return ;
	if (map->tmp_map)
		free_dbl_char(map->tmp_map);
	map = NULL;
}

void	init_map(t_map_infos *map)
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
	init_color(&map->floor_color, (t_color){0, 0, 0});
}
