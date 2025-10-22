/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:26:48 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/22 16:22:21 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_textures	*new_node_texture(char *s, t_type type)
{
	t_textures	*new;

	new = malloc(sizeof(t_textures));
	if (!new)
		return (NULL);
	new->type = type;
	new->name_texture = s;
	new->data.img = NULL;
	new->data.addr = NULL;
	new->t_height = 0;
	new->t_width = 0;
	new->next = NULL;
	return (new);
}

t_textures	*last_node(t_textures *textures)
{
	t_textures	*ptr;

	ptr = NULL;
	while (textures)
	{
		ptr = textures;
		textures = textures->next;
	}
	return (ptr);
}

void	add_back_node(t_textures **textures, t_textures *new,
		int *malloc_failed)
{
	if (!new)
	{
		*malloc_failed = 1;
		return ;
	}
	if (!textures)
		*textures = new;
	else
		last_node(*textures)->next = new;
}

/**
 * The goal is to take the right color for each pixels.
 */
// void	wall_rendering(t_global_infos *infos, t_data *img, int i, int y)
// {
// 	int			position;
// 	int			color;
// 	t_data		*img_texture;
// 	t_textures	*ptr;

// 	ptr = infos->textures;
// 	while (ptr && ptr->type != infos->actual_orientation)
// 		ptr = ptr->next;
// 	img_texture = &ptr->data;
// 	position = (infos->tex_y * img_texture->line_length) + (infos->tex_x
// 			* (img_texture->bits_per_pixel * 0.125));
// 	color = *(int *)(img_texture->addr + position);
// 	my_mlx_pixel_put(img, i, y, color);
// }

void	wall_rendering(t_global_infos *infos, t_data *img, int i, int y)
{
	int			position;
	int			color;
	t_data		*img_texture;
	t_textures	*ptr;
	int			tex_pixel_y;
	int			tex_pixel_x;

	ptr = infos->textures;
	while (ptr && ptr->type != infos->actual_orientation)
		ptr = ptr->next;
	img_texture = &ptr->data;
	tex_pixel_y = (int)infos->tex_y;
	tex_pixel_x = (int)infos->tex_x;
	if (tex_pixel_x < 0)
		tex_pixel_x = 0;
	if (tex_pixel_x >= ptr->t_width)
		tex_pixel_x = ptr->t_width - 1;
	if (tex_pixel_y < 0)
		tex_pixel_y = 0;
	if (tex_pixel_y >= ptr->t_height)
		tex_pixel_y = ptr->t_height - 1;
	position = (tex_pixel_y * img_texture->line_length) + (tex_pixel_x
			* (img_texture->bits_per_pixel / 8));
	color = *(int *)(img_texture->addr + position);
	my_mlx_pixel_put(img, i, y, color);
}
