/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:01:59 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/24 14:20:26 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
