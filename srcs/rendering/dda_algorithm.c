/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:01:38 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/24 12:01:39 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	draw_walls(double distance, t_data *img, int i,
		t_player_infos *infos)
{
	int	wall_height;
	int	start_y;
	int	end_y;
	int y = 0;

	wall_height = (int)(infos->map_infos->height / distance);
	if (wall_height > infos->map_infos->height)
		wall_height = infos->map_infos->height;
	start_y = (infos->map_infos->height - wall_height) / 2;
	if (start_y < 0)
		start_y = 0;
	end_y = start_y + wall_height;
	if (end_y < 0)
		end_y = 0;
	while (y < infos->map_infos->height)
	{
		if (y < start_y)
			my_mlx_pixel_put(img, i, y, 0x00666666); // ceiling
		else if (y >= start_y && y < end_y)
			my_mlx_pixel_put(img, i, y, 0x00FF0000); // wall
		else
			my_mlx_pixel_put(img, i, y, 0x00333333); // floor
		y++;
	}
}

static double	return_wall_distance(t_player_infos *infos)
{
	double	current_x;
	double	current_y;
	double	step;
	double	dx;
	double	dy;

	current_x = infos->px;
	current_y = infos->py;
	step = 0.01;
	while (current_x >= 0 && current_x < infos->map_infos->x && current_y >= 0
		&& current_y < infos->map_infos->y)
	{
		current_x += infos->ray_infos->ray_dir_x * step;
		current_y += infos->ray_infos->ray_dir_y * step;
		if (infos->map[(int)current_x][(int)current_y] == 1)
		{
			dx = current_x - infos->px;
			dy = current_y - infos->py;
			return (sqrt(dx * dx + dy * dy) * cos(infos->angle_rayon - infos->angle_joueur));
		}
	}
	return (1000.0);
}

static void	calculs_of_vectors(t_player_infos *infos, int i)
{
	double	camera_x;

	infos->angle_rayon = atan2(infos->ray_infos->ray_dir_y,
			infos->ray_infos->ray_dir_x);
	camera_x = 2 * i / (double)infos->map_infos->width - 1;
	infos->ray_infos->ray_dir_x = infos->ray_infos->dir_x
		+ infos->ray_infos->plane_x * camera_x;
	infos->ray_infos->ray_dir_y = infos->ray_infos->dir_y
		+ infos->ray_infos->plane_y * camera_x;
}

/**
 * The goal is simple : 
 * Send x ray with an certain angle in the 2d and 3d map
 * When the ray touch a wall, he return the distance traveled.
 * With the distance we know what is a ceiling, wall and floor.
 */
int	render_algo(void *param)
{
	t_player_infos	*infos;
	int				i;
	double			distance;
	t_data			img;

	infos = (t_player_infos *)param;
	infos->angle_joueur = atan2(infos->ray_infos->dir_y, infos->ray_infos->dir_x);
	i = 0;
	create_image(infos, &img);
	while (i < infos->map_infos->width)
	{
		calculs_of_vectors(infos, i);
		distance = return_wall_distance(infos);
		draw_walls(distance, &img, i, infos);
		i++;
	}
	mlx_put_image_to_window(infos->mlx, infos->mlx_win, img.img, 0, 0);
	mlx_destroy_image(infos->mlx, img.img);
	return (0);
}
