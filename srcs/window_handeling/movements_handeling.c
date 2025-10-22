/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_handeling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:58:52 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/22 11:05:15 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// void	update_player_rotation(t_global_infos *infos)
// {
// 	t_keys		*keys;
// 	t_ray_infos	*ray;
// 	double		new_x;
// 	double		new_y;
// 	double		angle;

// 	keys = infos->keys;
// 	ray = infos->ray_infos;
// 	angle = 0.01 * (300 / infos->fps);
// 	if (keys->right == 1)
// 		angle *= -1;
// 	if (keys->left == 1 || keys->right == 1)
// 	{
// 		new_x = (ray->dir_x * cos(angle)) - (ray->dir_y * sin(angle));
// 		new_y = (ray->dir_x * sin(angle)) + (ray->dir_y * cos(angle));
// 		ray->dir_x = new_x;
// 		ray->dir_y = new_y;
// 	}
// }

void	update_player_rotation(t_global_infos *infos)
{
	t_keys		*keys;
	t_ray_infos	*ray;
	double		old_dir_x;
	double		rot_speed;

	keys = infos->keys;
	ray = infos->ray_infos;
	rot_speed = 0.02 * (300.0 / infos->fps);

	old_dir_x = ray->dir_x;
	if (keys->left)
	{
		ray->dir_x = ray->dir_x * cos(rot_speed) - ray->dir_y * sin(rot_speed);
		ray->dir_y = old_dir_x * sin(rot_speed) + ray->dir_y * cos(rot_speed);
	}
	if (keys->right)
	{
		ray->dir_x = ray->dir_x * cos(-rot_speed) - ray->dir_y * sin(-rot_speed);
		ray->dir_y = old_dir_x * sin(-rot_speed) + ray->dir_y * cos(-rot_speed);
	}
}


int	wall_collision(t_global_infos *infos, double y, double x)
{
	if (infos->map[(int)floor(y)][(int)floor(x)] != 1)
		return (1);
	return (0);
}

void	update_player_position(t_global_infos *infos)
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
	if (keys->W == 1 && wall_collision(infos, infos->py + ray->dir_y * speed,
			infos->px + ray->dir_x * speed) == 1)
	{
		infos->px += ray->dir_x * speed;
		infos->py += ray->dir_y * speed;
	}
	if (keys->S == 1 && wall_collision(infos, infos->py - ray->dir_y * speed,
			infos->px - ray->dir_x * speed) == 1)
	{
		infos->px -= ray->dir_x * speed;
		infos->py -= ray->dir_y * speed;
	}
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

int	keys_pressed(int keycode, t_global_infos *infos)
{
	t_keys	*keys;

	keys = infos->keys;
	if (keycode == 119)
		keys->W = 1;
	if (keycode == 115)
		keys->S = 1;
	if (keycode == 100)
		keys->D = 1;
	if (keycode == 97)
		keys->A = 1;
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
		keys->W = 0;
	if (keycode == 115)
		keys->S = 0;
	if (keycode == 100)
		keys->D = 0;
	if (keycode == 97)
		keys->A = 0;
	if (keycode == 65363)
		keys->left = 0;
	if (keycode == 65361)
		keys->right = 0;
	return (0);
}
