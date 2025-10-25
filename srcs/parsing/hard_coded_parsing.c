/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coded_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:38 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/07 16:23:38 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_textures(t_global_infos *infos, t_textures *textures)
{
	t_data *img;

	img = &textures->data;
	img->img = mlx_xpm_file_to_image(infos->mlx, textures->name_texture,
			&textures->t_width, &textures->t_height);
	if (!img->img)
		malloc_error(infos);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		malloc_error(infos);
}

void	create_textures(t_global_infos *infos)
{
	int i;
	int malloc_failed;
	char *textures[4];
	t_type types[4];
	t_textures *ptr;

	i = 0;
	malloc_failed = 0;
	textures[0] = infos->map_infos->no_path.name;
	textures[1] = infos->map_infos->so_path.name;
	textures[2] = infos->map_infos->ea_path.name;
	textures[3] = infos->map_infos->we_path.name;
	types[0] = NORTH;
	types[1] = SOUTH;
	types[2] = EAST;
	types[3] = WEST;
	infos->textures = new_node_texture(textures[i], types[i]);
	if (!infos->textures)
		malloc_error(infos);
	ptr = infos->textures;
	while (++i < 5)
	{
		init_textures(infos, ptr);
		add_back_node(&infos->textures, new_node_texture(textures[i], types[i]),
			&malloc_failed);
		if (malloc_failed == 1)
			malloc_error(infos);
		ptr = ptr->next;
	}
}

void	set_dirs(t_global_infos *infos)
{
	t_map_infos *map;

	map = infos->map_infos;
	if (map->start_angle == 90)
	{
		infos->ray_infos->dir_x = 0.0;
		infos->ray_infos->dir_y = 1.0;
	}
	else if (map->start_angle == -90)
	{
		infos->ray_infos->dir_x = 0.0;
		infos->ray_infos->dir_y = -1.0;
	}
	else if (map->start_angle == 0)
	{
		infos->ray_infos->dir_x = 1.0;
		infos->ray_infos->dir_y = 0.0;
	}
	else if (map->start_angle == 180)
	{
		infos->ray_infos->dir_x = -1.0;
		infos->ray_infos->dir_y = 0.0;
	}
	infos->ray_infos->plane_x = (60.0 * M_PI / 180.0) / 2;
}

void	init_structs(t_global_infos *infos)
{
	t_map_infos *map;

	map = infos->map_infos;
	infos->px = (double)map->x;
	infos->py = (double)map->y;
	set_dirs(infos);
	// printf("dirx: %f\ndiry: %f\n", infos->ray_infos->dir_x, infos->ray_infos->dir_y);
	infos->map = fill_map(infos->map_infos);
	infos->map_infos->x = map->width;
	infos->map_infos->y = map->height;
	infos->map_infos->width = 1920;
	infos->map_infos->height = 1080;
	// printf("px: %f, py: %f\n", infos->px, infos->py);
	printf("m_x: %d, m_y: %d\n", infos->map_infos->x, infos->map_infos->y);
}

