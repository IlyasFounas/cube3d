/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_rendering_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:37:55 by ifounas           #+#    #+#             */
/*   Updated: 2025/11/05 15:21:31 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * The goal is to take the right color for each pixels.
 */
void	wall_rendering_bonus(t_global_infos *infos, t_data *img, int i, int y)
{
	int			position;
	int			color;
	t_data		*img_texture;
	t_textures	*ptr;

	ptr = infos->textures;
	while (ptr && ptr->type != infos->actual_orientation)
		ptr = ptr->next;
	img_texture = &ptr->data;
	if (infos->tex_x < 0)
		infos->tex_x = 0;
	if (infos->tex_y < 0)
		infos->tex_y = 0;
	if (infos->tex_x >= ptr->t_width)
		infos->tex_x = ptr->t_width - 1;
	if (infos->tex_y >= ptr->t_height)
		infos->tex_y = ptr->t_height - 1;
	position = (infos->tex_y * img_texture->line_length) + (infos->tex_x
			* (img_texture->bits_per_pixel * 0.125));
	color = *(int *)(img_texture->addr + position);
	my_mlx_pixel_put(img, i, y, return_ult_darken_color(infos, color, y, 0));
}

void	draw_wall_bonus(t_global_infos *infos, t_data *img, int i, int y)
{
	infos->tex_y = (int)infos->tex_pos % infos->textures->t_height;
	infos->tex_pos += infos->tex_step;
	wall_rendering_bonus(infos, img, i, y);
}

void	graphic_rendering_bonus(double distance, t_data *img, int i,
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
	infos->fog_ratio = distance;
	while (y < infos->map_infos->height)
	{
		if (y < start_y)
			my_mlx_pixel_put(img, i, y, return_ult_darken_color(infos,
					return_color_bonus(infos->map_infos->ceiling_color), y, 1));
		else if (y >= start_y && y < end_y)
			draw_wall_bonus(infos, img, i, y);
		else
			my_mlx_pixel_put(img, i, y, return_ult_darken_color(infos,
					return_color_bonus(infos->map_infos->floor_color), y, 1));
		y++;
	}
}
