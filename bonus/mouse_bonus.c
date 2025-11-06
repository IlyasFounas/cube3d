/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:01:42 by ifounas           #+#    #+#             */
/*   Updated: 2025/11/06 17:50:56 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <sys/time.h>

static void	update_player_rotation_bonus(t_global_infos *infos, double angle)
{
	t_keys		*keys;
	t_ray_infos	*ray;
	double		new_x;
	double		new_y;

	keys = infos->keys;
	ray = infos->ray_infos;
	new_x = (ray->dir_x * cos(angle)) - (ray->dir_y * sin(angle));
	new_y = (ray->dir_x * sin(angle)) + (ray->dir_y * cos(angle));
	ray->dir_x = new_x;
	ray->dir_y = new_y;
	new_x = (ray->plane_x * cos(angle)) - (ray->plane_y * sin(angle));
	new_y = (ray->plane_x * sin(angle)) + (ray->plane_y * cos(angle));
	ray->plane_x = new_x;
	ray->plane_y = new_y;
}

int	handle_mouse_movements(t_global_infos *infos)
{
	static int	old_x;
	int			offset;
	int			x;
	int			y;

	mlx_mouse_get_pos(infos->mlx, infos->mlx_win, &x, &y);
	if (old_x == 0)
		old_x = x;
	if (y > 0 && x < infos->map_infos->width && y < infos->map_infos->height)
	{
		offset = old_x - x;
		if (offset < 0)
			update_player_rotation_bonus(infos, -offset * 0.002);
		else
			update_player_rotation_bonus(infos, -offset * 0.002);
		if (x == infos->map_infos->width - 1)
			mlx_mouse_move(infos->mlx, infos->mlx_win, 3,
				infos->map_infos->height / 2);
		else if (x < 2)
			mlx_mouse_move(infos->mlx, infos->mlx_win, infos->map_infos->width
				- 2, infos->map_infos->height / 2);
		old_x = x;
	}
	return (0);
}
