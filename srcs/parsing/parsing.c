/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coded_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/10/27 09:38:06 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/27 09:38:06 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_textures(t_global_infos *infos, t_textures *textures)
{
	t_data	*img;

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

void	set_dirs(t_global_infos *infos)
{
	t_map_infos	*map;

	map = infos->map_infos;
	infos->ray_infos->dir_x = cos(map->start_angle * M_PI / 180.0);
	infos->ray_infos->dir_y = sin(map->start_angle * M_PI / 180.0);
	if (map->start_angle == 90)
		infos->ray_infos->plane_x = ((60.0 * M_PI / 180.0) / 2) * -1;
	else if (map->start_angle == -90)
		infos->ray_infos->plane_x = (60.0 * M_PI / 180.0) / 2;
	else if (map->start_angle == 0)
		infos->ray_infos->plane_y = (60.0 * M_PI / 180.0) / 2;
	else if (map->start_angle == 180)
		infos->ray_infos->plane_y = ((60.0 * M_PI / 180.0) / 2) * -1;
}

void	init_structs(t_global_infos *infos)
{
	t_map_infos	*map;

	map = infos->map_infos;
	infos->px = (double)map->x;
	infos->py = (double)map->y;
	set_dirs(infos);
	infos->map = fill_map(infos->map_infos);
	infos->map_infos->x = map->width;
	infos->map_infos->y = map->height;
	infos->map_infos->width = 1920;
	infos->map_infos->height = 1080;
}
