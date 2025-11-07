/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_handeling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:58:52 by ifounas           #+#    #+#             */
/*   Updated: 2025/11/07 15:36:43 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	update_player_rotation(t_global_infos *infos)
{
	t_keys		*keys;
	t_ray_infos	*ray;
	double		new_x;
	double		new_y;
	double		angle;

	keys = infos->keys;
	ray = infos->ray_infos;
	angle = 0.01 * (300.0 / infos->fps);
	if (keys->right == 1)
		angle *= -1;
	if (keys->left == 1 || keys->right == 1)
	{
		new_x = (ray->dir_x * cos(angle)) - (ray->dir_y * sin(angle));
		new_y = (ray->dir_x * sin(angle)) + (ray->dir_y * cos(angle));
		ray->dir_x = new_x;
		ray->dir_y = new_y;
		new_x = (ray->plane_x * cos(angle)) - (ray->plane_y * sin(angle));
		new_y = (ray->plane_x * sin(angle)) + (ray->plane_y * cos(angle));
		ray->plane_x = new_x;
		ray->plane_y = new_y;
	}
}

void	update_player_position(t_global_infos *infos)
{
	t_keys		*keys;
	t_ray_infos	*ray;
	double		speed;

	keys = infos->keys;
	ray = infos->ray_infos;
	speed = 0.02 * (300.0 / infos->fps);
	if (keys->w == 1)
	{
		if (wall_collision(infos, infos->py, infos->px + ray->dir_x
				* speed) == 1)
			infos->px += ray->dir_x * speed;
		if (wall_collision(infos, infos->py + ray->dir_y * speed,
				infos->px) == 1)
			infos->py += ray->dir_y * speed;
	}
	if (keys->s == 1)
	{
		if (wall_collision(infos, infos->py, infos->px - ray->dir_x
				* speed) == 1)
			infos->px -= ray->dir_x * speed;
		if (wall_collision(infos, infos->py - ray->dir_y * speed,
				infos->px) == 1)
			infos->py -= ray->dir_y * speed;
	}
}

int	keys_pressed(int keycode, t_global_infos *infos)
{
	t_keys	*keys;

	keys = infos->keys;
	if (keycode == 119)
		keys->w = 1;
	if (keycode == 115)
		keys->s = 1;
	if (keycode == 100)
		keys->d = 1;
	if (keycode == 97)
		keys->a = 1;
	if (keycode == 107)
		keys->f = 0;
	if (keycode == 106)
		keys->f = 1;
	if (keycode == 65363)
		keys->left = 1;
	if (keycode == 65361)
		keys->right = 1;
	if (keycode == 65307)
	{
		free_rendering(infos);
		exit(0);
	}
	return (0);
}

int	keys_released(int keycode, t_global_infos *infos)
{
	t_keys	*keys;

	keys = infos->keys;
	if (keycode == 119)
		keys->w = 0;
	if (keycode == 115)
		keys->s = 0;
	if (keycode == 100)
		keys->d = 0;
	if (keycode == 97)
		keys->a = 0;
	if (keycode == 65363)
		keys->left = 0;
	if (keycode == 65361)
		keys->right = 0;
	if (keycode == 109)
		infos->draw_minimap = !infos->draw_minimap;
	if (keycode == 102)
		infos->draw_fps = !infos->draw_fps;
	return (0);
}
