/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:01:59 by ifounas           #+#    #+#             */
/*   Updated: 2025/11/13 17:18:19 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <sys/time.h>

static int	return_color(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = color.r;
	g = color.g;
	b = color.b;
	return ((r << 16) | (g << 8) | (b));
}

void	calcul_the_fps(t_global_infos *infos)
{
	static double			elapsed_seconds;
	static int				frame_count;
	static struct timeval	current_time;
	static struct timeval	last_time;

	frame_count++;
	gettimeofday(&current_time, NULL);
	elapsed_seconds = (current_time.tv_sec - last_time.tv_sec)
		+ (current_time.tv_usec - last_time.tv_usec) / 1000000.0;
	if (elapsed_seconds >= 1.0)
	{
		if (frame_count == 1)
			infos->fps = 30;
		else if (frame_count > 100)
			infos->fps = 100;
		else if (frame_count > 200)
			infos->fps = 150;
		else
			infos->fps = frame_count;
		if (infos->draw_fps)
			printf("fps: %d\n", infos->fps);
		last_time = current_time;
		elapsed_seconds = 0;
		frame_count = 0;
	}
}

void	draw_wall(t_global_infos *infos, t_data *img, int i, int y)
{
	infos->tex_y = (int)infos->tex_pos % infos->textures->t_height;
	infos->tex_pos += infos->tex_step;
	wall_rendering(infos, img, i, y);
}

void	graphic_rendering(double distance, t_data *img, int i,
		t_global_infos *infos)
{
	int	wall_height;
	int	start_y;
	int	end_y;
	int	y;

	y = 0;
	wall_height = (int)(infos->map_infos->height / distance);
	start_y = (infos->map_infos->height - wall_height) * 0.5;
	if (start_y < 0)
		start_y = 0;
	end_y = start_y + wall_height;
	texture_start(infos, wall_height, start_y);
	while (y < infos->map_infos->height)
	{
		if (y < start_y)
			my_mlx_pixel_put(img, i, y,
				return_color(infos->map_infos->ceiling_color));
		else if (y >= start_y && y < end_y)
			draw_wall(infos, img, i, y);
		else
			my_mlx_pixel_put(img, i, y,
				return_color(infos->map_infos->floor_color));
		y++;
	}
}
