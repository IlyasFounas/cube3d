/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_linear_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:29:01 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/17 14:25:56 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_linear_ray(t_global_infos *infos, t_linear_equa *linear_ray)
{
	t_ray_infos	*rays;

	rays = infos->ray_infos;
	linear_ray->map_x = infos->px;
	linear_ray->map_y = infos->py;
	if (rays->ray_dir_x > 0)
	{
		linear_ray->start_x = ceil(linear_ray->map_x);
		linear_ray->step_x = 1;
	}
	else
	{
		linear_ray->start_x = floor(linear_ray->map_x);
		linear_ray->step_x = -1;
	}
	if (rays->ray_dir_y > 0)
	{
		linear_ray->start_y = ceil(linear_ray->map_y);
		linear_ray->step_y = 1;
	}
	else
	{
		linear_ray->start_y = floor(linear_ray->map_y);
		linear_ray->step_y = -1;
	}
}

void	setting_the_right_texture(t_global_infos *infos,
		t_linear_equa *linear_ray)
{
	if (linear_ray->shortest_t == linear_ray->t_vertical)
	{
		infos->tex_x = (linear_ray->iy - floor(linear_ray->iy))
			* infos->textures->t_width;
		if (infos->ray_infos->ray_dir_x < 0)
			infos->actual_orientation = WEST;
		else if (infos->ray_infos->ray_dir_x > 0)
			infos->actual_orientation = EAST;
	}
	else
	{
		infos->tex_x = (linear_ray->ix - floor(linear_ray->ix))
			* infos->textures->t_width;
		if (infos->ray_infos->ray_dir_y < 0)
			infos->actual_orientation = NORTH;
		else if (infos->ray_infos->ray_dir_y > 0)
			infos->actual_orientation = SOUTH;
	}
}
