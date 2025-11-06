/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_handeling_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:40:30 by ifounas           #+#    #+#             */
/*   Updated: 2025/11/05 14:39:53 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	wall_collision(t_global_infos *infos, double y, double x)
{
	if (infos->map[(int)floor(y)][(int)floor(x)] != 1)
		return (1);
	return (0);
}

void	straf_position(t_global_infos *infos)
{
	t_keys		*keys;
	t_ray_infos	*ray;
	double		speed;
	double		straf_x;
	double		straf_y;

	keys = infos->keys;
	ray = infos->ray_infos;
	speed = 0.01 * (300.0 / infos->fps);
	straf_x = -ray->dir_y;
	straf_y = ray->dir_x;
	if (keys->a == 1)
	{
		if (wall_collision(infos, infos->py, infos->px - straf_x * speed) == 1)
			infos->px -= straf_x * speed;
		if (wall_collision(infos, infos->py - straf_y * speed, infos->px) == 1)
			infos->py -= straf_y * speed;
	}
	if (keys->d == 1)
	{
		if (wall_collision(infos, infos->py, infos->px + straf_x * speed) == 1)
			infos->px += straf_x * speed;
		if (wall_collision(infos, infos->py + straf_y * speed, infos->px) == 1)
			infos->py += straf_y * speed;
	}
}
