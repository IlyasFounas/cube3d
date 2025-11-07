/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:01:42 by ifounas           #+#    #+#             */
/*   Updated: 2025/11/07 15:11:57 by ifounas          ###   ########.fr       */
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

static void	replace_y(t_global_infos *infos, int y, int x)
{
	if (y > infos->map_infos->height)
		mlx_mouse_move(infos->mlx, infos->mlx_win, x, infos->map_infos->height);
	else if (y < 0)
		mlx_mouse_move(infos->mlx, infos->mlx_win, x, 0);
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
	offset = old_x - x;
	if (offset < 0 && offset > -(infos->map_infos->width - 30)
		&& offset < (infos->map_infos->width - 30))
		update_player_rotation_bonus(infos, -offset * 0.001);
	else if (offset > -(infos->map_infos->width - 30)
		&& offset < (infos->map_infos->width - 30))
		update_player_rotation_bonus(infos, -offset * 0.001);
	old_x = x;
	replace_y(infos, y, x);
	if (x >= infos->map_infos->width || x > infos->map_infos->width - 5)
		mlx_mouse_move(infos->mlx, infos->mlx_win, 3, infos->map_infos->height
			/ 2);
	else if (x <= 0 || x < 2)
		mlx_mouse_move(infos->mlx, infos->mlx_win, infos->map_infos->width - 6,
			infos->map_infos->height / 2);
	return (0);
}
