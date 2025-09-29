/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:32:09 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/30 00:04:55 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cube3d.h"

static double	return_distance(t_global_infos *infos, t_intersec_calcul *ray,
		double current_x, double current_y)
{
	double	dx;
	double	dy;
	double	step_x;
	double	step_y;

	step_x = 1;
	step_y = 1;
	if (ray->tv_x < ray->tv_y)
	{
		if (infos->ray_infos->ray_dir_x < 0)
			step_x = -1;
	}
	else
	{
		if (infos->ray_infos->ray_dir_y < 0)
			step_y = -1;
	}
	if (((int)(current_x + step_x) < 0) || ((int)(current_y + step_y) < 0))
		return (-1);
	if (infos->map[(int)(current_y + step_y)][(int)(current_x + step_x)]== 1)
	{
		dx = current_x - infos->px;
		dy = current_y - infos->py;
		return (sqrt(dx * dx + dy * dy) * cos(infos->ray_angle
				- infos->p_angle));
	}
	return (-1);
}

static void	calcul_ray_intersection(t_global_infos *infos,
		t_intersec_calcul *ray, double current_x, double current_y)
{
	if (infos->ray_infos->ray_dir_x > 0)
		ray->sideV_x = floor(current_x) + 1;
	else
		ray->sideV_x = floor(current_x) - 1;
	if (infos->ray_infos->ray_dir_y > 0)
		ray->sideH_y = floor(current_y) + 1;
	else
		ray->sideH_y = floor(current_y) - 1;
	ray->tv_x = (ray->sideV_x - current_x) / infos->ray_infos->ray_dir_x;
	ray->tv_y = (ray->sideH_y - current_y) / infos->ray_infos->ray_dir_y;
    ray->deltadist_x = fabs(1 / infos->ray_infos->ray_dir_x);
	ray->deltadist_y = fabs(1 / infos->ray_infos->ray_dir_y);
}

double	dda_intersection_algo(t_global_infos *infos)
{
	double				current_x;
	double				current_y;
	double				distance;
	t_intersec_calcul	ray;

	current_x = infos->px;
	current_y = infos->py;
	calcul_ray_intersection(infos, &ray, infos->px, infos->py);
	while (current_x >= 0 && current_x < infos->map_infos->x && current_y >= 0
		&& current_y < infos->map_infos->y)
	{
		if (ray.tv_x < ray.tv_y)
		{
			current_x = ray.sideV_x;
			current_y = current_y + ray.tv_x * infos->ray_infos->ray_dir_y;
			distance = return_distance(infos, &ray, current_x, current_y);
			if (distance != -1)
				return (distance);
			ray.sideV_x += (infos->ray_infos->ray_dir_x > 0 ? 1 : -1);
			ray.tv_x += ray.deltadist_x;
		}
		else
		{
			current_x = current_x + ray.tv_y * infos->ray_infos->ray_dir_x;
			current_y = ray.sideH_y;
			distance = return_distance(infos, &ray, current_x, current_y);
			if (distance != -1)
				return (distance);
			ray.sideH_y += (infos->ray_infos->ray_dir_y > 0 ? 1 : -1);
			ray.tv_y += ray.deltadist_y;
		}
	}
	return (0);
}
