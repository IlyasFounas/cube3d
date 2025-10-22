/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_linear_equa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:32:09 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/22 16:32:03 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	return_t(t_global_infos *infos, t_linear_equa *linear_ray)
{
	if (linear_ray->map_y >= 0 && linear_ray->map_y < infos->map_infos->y
		&& linear_ray->map_x >= 0 && linear_ray->map_x < infos->map_infos->x)
	{
		if (infos->map[linear_ray->map_y][linear_ray->map_x] == 1)
			return (1);
	}
	return (-1);
}

static double	vertical_linear_equa(t_global_infos *infos,
		t_linear_equa *linear_ray)
{
	double	t;

	linear_ray->x = linear_ray->start_x;
	while (linear_ray->x >= 0 && linear_ray->x < infos->map_infos->x)
	{
		t = (linear_ray->x - infos->px) / infos->ray_infos->ray_dir_x;
		if (t > 0)
		{
			linear_ray->iy = infos->py + (infos->ray_infos->ray_dir_y * t);
			if (linear_ray->iy >= 0 && linear_ray->iy < infos->map_infos->y)
			{
				linear_ray->map_y = floor(linear_ray->iy);
				if (infos->ray_infos->ray_dir_x > 0)
					linear_ray->map_x = linear_ray->x;
				else
					linear_ray->map_x = linear_ray->x - 1;
				if (return_t(infos, linear_ray) > -1)
					return (t);
			}
		}
		linear_ray->x += linear_ray->step_x;
	}
	return (-1);
}

static double	horizontal_linear_equa(t_global_infos *infos,
		t_linear_equa *linear_ray)
{
	double	t;

	linear_ray->y = linear_ray->start_y;
	while (linear_ray->y >= 0 && linear_ray->y < infos->map_infos->y)
	{
		t = (linear_ray->y - infos->py) / infos->ray_infos->ray_dir_y;
		if (t > 0)
		{
			linear_ray->ix = infos->px + (infos->ray_infos->ray_dir_x * t);
			if (linear_ray->ix >= 0 && linear_ray->ix < infos->map_infos->x)
			{
				linear_ray->map_x = floor(linear_ray->ix);
				if (infos->ray_infos->ray_dir_y > 0)
					linear_ray->map_y = linear_ray->y;
				else
					linear_ray->map_y = linear_ray->y - 1;
				if (return_t(infos, linear_ray) > -1)
					return (t);
			}
		}
		linear_ray->y += linear_ray->step_y;
	}
	return (-1);
}

/**
 * Solves linear equations for ray-grid intersections
 *
 * Uses parametric ray equations to find intersections with vertical/horizontal
 * grid lines. Returns the smallest valid 't' distance to wall collision.
 * Mathematical alternative to DDA stepping.
 */
double	solving_linear_equa(t_global_infos *infos)
{
	t_linear_equa	linear_ray;

	ft_memset(&linear_ray, 0, sizeof(t_linear_equa));
	init_linear_ray(infos, &linear_ray);
	linear_ray.t_vertical = vertical_linear_equa(infos, &linear_ray);
	linear_ray.t_horizontal = horizontal_linear_equa(infos, &linear_ray);
	linear_ray.shortest_t = fmin(linear_ray.t_vertical,
			linear_ray.t_horizontal);
	if (linear_ray.t_vertical == -1)
		linear_ray.shortest_t = linear_ray.t_horizontal;
	if (linear_ray.t_horizontal == -1)
		linear_ray.shortest_t = linear_ray.t_vertical;
	if (linear_ray.shortest_t != -1)
	{
		setting_the_right_texture(infos, &linear_ray);
		return (linear_ray.shortest_t * cos(infos->p_angle - infos->ray_angle ));
	}
	return (0);
}
