/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:01:38 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/25 15:07:54 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static double	return_wall_distance(t_global_infos *infos)
{
	double	current_x;
	double	current_y;
	double	step;
	double	dx;
	double	dy;

	current_x = infos->px;
	current_y = infos->py;
	step = 0.01;
	while (current_x >= 0 && current_x < infos->map_infos->x && current_y >= 0
		&& current_y < infos->map_infos->y)
	{
		current_x += infos->ray_infos->ray_dir_x * step;
		current_y += infos->ray_infos->ray_dir_y * step;
		if (infos->map[(int)current_x][(int)current_y] == 1)
		{
			dx = current_x - infos->px;
			dy = current_y - infos->py;
			return (sqrt(dx * dx + dy * dy) * cos(infos->ray_angle
					- infos->p_angle));
		}
	}
	return (0);
}

static void	calculs_of_vectors(t_global_infos *infos, int i)
{
	double	camera_x;

	infos->ray_angle = atan2(infos->ray_infos->ray_dir_y,
			infos->ray_infos->ray_dir_x);
	camera_x = 2 * i / (double)infos->map_infos->width - 1;
	infos->ray_infos->ray_dir_x = infos->ray_infos->dir_x
		+ infos->ray_infos->plane_x * camera_x;
	infos->ray_infos->ray_dir_y = infos->ray_infos->dir_y
		+ infos->ray_infos->plane_y * camera_x;
}

/**
 * Real-time 3D rendering using raycasting technique:
 * - Casts multiple rays across the field of view (one per screen column)
 * - For each ray, calculates intersection distance with walls in the 2D map
 * - Uses distance to determine wall height and render ceiling/wall/floor 
 * segments
 * - Applies fisheye correction for proper perspective projection
 */
int	rendering(void *param)
{
	t_global_infos	*infos;
	int				i;
	double			distance;
	t_data			img;

	infos = (t_global_infos *)param;
	infos->p_angle = atan2(infos->ray_infos->dir_y, infos->ray_infos->dir_x);
	i = 0;
	calcul_the_fps();
	update_position(infos);
	create_image(infos, &img);
	while (i < infos->map_infos->width)
	{
		calculs_of_vectors(infos, i);
		distance = return_wall_distance(infos);
		graphic_rendering(distance, &img, i, infos);
		i++;
	}
	destroy_image(infos, &img);
	return (0);
}
