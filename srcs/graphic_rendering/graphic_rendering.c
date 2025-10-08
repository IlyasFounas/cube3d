/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:01:59 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/08 18:11:14 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	calcul_the_fps(void)
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
		frame_count = 0;
		last_time = current_time;
		elapsed_seconds = 0;
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
		{
			my_mlx_pixel_put(img, i, y, 0x00666666);
			// y++;
			// my_mlx_pixel_put(img, i, y, 0x00666666);
		}
		else if (y >= start_y && y < end_y)
		{
			infos->tex_y = ((double)(y - start_y) / wall_height)
				* infos->textures->t_height;
			wall_rendering(infos, img, i, y);
			// y++;
		}
		else
		{
			my_mlx_pixel_put(img, i, y, 0x00333333);
			// y++;
			// my_mlx_pixel_put(img, i, y, 0x00333333);
		}
		y++;
	}
}
