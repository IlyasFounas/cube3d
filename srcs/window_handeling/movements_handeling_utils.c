/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_handeling_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:40:30 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/23 12:40:31 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	wall_collision(t_global_infos *infos, double y, double x)
{
	if (infos->map[(int)floor(y)][(int)floor(x)] != 1)
		return (1);
	return (1);
}

void	straf_position(t_global_infos *infos, t_keys *keys, t_ray_infos *ray,
		double speed)
{
	double	straf_x;
	double	straf_y;

	straf_x = -ray->dir_y;
	straf_y = ray->dir_x;
	if (keys->A == 1 && wall_collision(infos, infos->py - straf_y * speed,
			infos->px + straf_x * speed) == 1)
	{
		infos->px -= straf_x * speed;
		infos->py -= straf_y * speed;
	}
	if (keys->D == 1 && wall_collision(infos, infos->py + straf_y * speed,
			infos->px - straf_x * speed) == 1)
	{
		infos->px += straf_x * speed;
		infos->py += straf_y * speed;
	}
}
