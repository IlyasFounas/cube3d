/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:26:48 by ifounas           #+#    #+#             */
/*   Updated: 2025/11/04 14:40:04 by ifounas          ###   ########.fr       */
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

void	texture_start(t_global_infos *infos, int wall_height, int start_y)
{
	infos->tex_step = (double)infos->textures->t_height / wall_height;
	infos->tex_pos = (start_y - infos->map_infos->height * 0.5 + wall_height
			* 0.5) * infos->tex_step;
}

/**
 * The goal is to take the right color for each pixels.
 */
void	wall_rendering(t_global_infos *infos, t_data *img, int i, int y)
{
	int			position;
	int			color;
	t_data		*img_texture;
	t_textures	*ptr;

	ptr = infos->textures;
	while (ptr && ptr->type != infos->actual_orientation)
		ptr = ptr->next;
	img_texture = &ptr->data;
	position = (infos->tex_y * img_texture->line_length) + (infos->tex_x
			* (img_texture->bits_per_pixel * 0.125));
	color = *(int *)(img_texture->addr + position);
	my_mlx_pixel_put(img, i, y, color);
}
