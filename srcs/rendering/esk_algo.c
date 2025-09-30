/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esk_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:32:09 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/30 17:21:20 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	init_linear_ray(t_global_infos *infos,
		t_intersec_calcul *linear_ray)
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

static int	return_t(t_global_infos *infos, t_intersec_calcul *linear_ray)
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
		t_intersec_calcul *linear_ray)
{
	int		x;
	double	t;
	double	iy;

	x = linear_ray->start_x;
	while (x >= 0 && x < infos->map_infos->x)
	{
		t = (x - infos->px) / infos->ray_infos->ray_dir_x;
		if (t > 0)
		{
			iy = infos->py + (infos->ray_infos->ray_dir_y * t);
			if (iy >= 0 && iy < infos->map_infos->y)
			{
				linear_ray->map_y = floor(iy);
				if (infos->ray_infos->ray_dir_x > 0)
					linear_ray->map_x = x;
				else
					linear_ray->map_x = x - 1;
				if (return_t(infos, linear_ray) > -1)
					return (t);
			}
		}
		x += linear_ray->step_x;
	}
	return (-1);
}

static double	horizontal_linear_equa(t_global_infos *infos,
		t_intersec_calcul *linear_ray)
{
	int		y;
	double	t;
	double	ix;

	y = linear_ray->start_y;
	while (y >= 0 && y < infos->map_infos->y)
	{
		t = (y - infos->py) / infos->ray_infos->ray_dir_y;
		if (t > 0)
		{
			ix = infos->px + (infos->ray_infos->ray_dir_x * t);
			if (ix >= 0 && ix < infos->map_infos->x)
			{
				linear_ray->map_x = floor(ix);
				if (infos->ray_infos->ray_dir_y > 0)
					linear_ray->map_y = y;
				else
					linear_ray->map_y = y - 1;
				if (return_t(infos, linear_ray) > -1)
					return (t);
			}
		}
		y += linear_ray->step_y;
	}
	return (-1);
}

/**
 * eskDron_algo - Solves linear equations for ray-grid intersections
 *
 * Uses parametric ray equations to find intersections with vertical/horizontal
 * grid lines. Returns the smallest valid 't' distance to wall collision.
 * Mathematical alternative to DDA stepping.
 */
double	esk_algo(t_global_infos *infos)
{
	t_intersec_calcul	linear_ray;
	double				t_vertical;
	double				t_horizontal;
	double				shortest_t;
	double				fisheye_correc;

	ft_memset(&linear_ray, 0, sizeof(t_intersec_calcul));
	init_linear_ray(infos, &linear_ray);
	t_vertical = vertical_linear_equa(infos, &linear_ray);
	t_horizontal = horizontal_linear_equa(infos, &linear_ray);
	shortest_t = fmin(t_vertical, t_horizontal);
	if (t_vertical == -1)
		shortest_t = t_horizontal;
	if (t_horizontal == -1)
		shortest_t = t_vertical;
	if (shortest_t != -1)
	{
		fisheye_correc = infos->ray_infos->ray_dir_x * infos->ray_infos->dir_x
			+ infos->ray_infos->ray_dir_y * infos->ray_infos->dir_y;
		return (shortest_t * fisheye_correc);
	}
	return (0);
}
