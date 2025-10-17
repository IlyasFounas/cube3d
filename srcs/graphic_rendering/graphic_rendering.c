/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:01:59 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/17 16:25:13 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <sys/time.h>

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
		printf("FPS: %d\n", frame_count);
		if (frame_count == 1)
			infos->fps = 30;
		else if (frame_count > 100)
			infos->fps = 100;
		else
			infos->fps = frame_count;
		last_time = current_time;
		elapsed_seconds = 0;
		frame_count = 0;
	}
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
	if (wall_height > infos->map_infos->height)
		wall_height = infos->map_infos->height;
	start_y = (infos->map_infos->height - wall_height) * 0.5;
	if (start_y < 0)
		start_y = 0;
	end_y = start_y + wall_height;
	if (end_y < 0)
		end_y = 0;
	while (y < infos->map_infos->height)
	{
		if (y < start_y)
			my_mlx_pixel_put(img, i, y, 0x00666666);
		else if (y >= start_y && y < end_y)
		{
			infos->tex_y = ((double)(y - start_y) / wall_height)
				* infos->textures->t_height;
			wall_rendering(infos, img, i, y);
		}
		else
			my_mlx_pixel_put(img, i, y, 0x042f09);
		y++;
	}
}
