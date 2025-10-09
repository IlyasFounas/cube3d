/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coded_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:38 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/07 16:23:38 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_textures(t_global_infos *infos, t_textures *textures)
{
	t_data *img;

	img = &textures->data;
	img->img = mlx_xpm_file_to_image(infos->mlx, textures->name_texture,
			&textures->t_width, &textures->t_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	create_textures(t_global_infos *infos)
{
	int i;
	int malloc_failed;
	char *textures[4];
	t_type types[4];
	t_textures *ptr;

	i = 0;
	malloc_failed = 0;
	textures[0] = "textures/cobblestone_01.xpm";
	textures[1] = "textures/cobblestone_02.xpm";
	textures[2] = "textures/cobblestone.xpm";
	textures[3] = "textures/mossy_cobblestone1.xpm";
	types[0] = NORTH;
	types[1] = SOUTH;
	types[2] = EAST;
	types[3] = WEST;
	infos->textures = new_node_texture(textures[i], types[i]);
	if (!infos->textures)
	{
		free_rendering(infos);
		exit(MALLOC_FAILED);
	}
	ptr = infos->textures;
	while (++i < 5)
	{
		init_textures(infos, ptr);
		add_back_node(&infos->textures, new_node_texture(textures[i], types[i]),
			&malloc_failed);
		if (malloc_failed == 1)
		{
			free_rendering(infos);
			exit(MALLOC_FAILED);
		}
		ptr = ptr->next;
	}
}

void	init_structs(t_global_infos *infos)
{
	infos->px = 1.0;
	infos->py = 6.0;
	infos->ray_infos->plane_x = 0.66;
	infos->ray_infos->dir_x = 0.0;
	infos->ray_infos->dir_y = -1.0;
	infos->map_infos->x = 20;
	infos->map_infos->y = 20;
	infos->map_infos->width = 840;
	infos->map_infos->height = 680;
	infos->map = hard_coded_2dmap(infos);
}

int	**hard_coded_2dmap(t_global_infos *infos)
{
	int **res;

	res = malloc(infos->map_infos->y * sizeof(int *));
	for (int i = 0; i < infos->map_infos->x; i++)
	{
		res[i] = malloc(infos->map_infos->x * sizeof(int));
		for (int j = 0; j < infos->map_infos->y; j++)
		{
			res[i][j] = 0;
		}
	}
	for (int i = 0; i < infos->map_infos->x; i++)
	{
		res[0][i] = 1;
		res[19][i] = 1;
		res[i][0] = 1;
		res[i][19] = 1;
	}
	res[4][1] = 1;
	res[4][2] = 1;
	res[4][3] = 1;
	res[4][4] = 1;
	res[4][5] = 1;
	res[4][6] = 1;
	res[4][7] = 1;
	res[4][8] = 1;
	res[4][9] = 1;
	res[4][10] = 1;
	res[5][10] = 1;
	res[6][10] = 1;
	res[7][10] = 1;
	res[8][10] = 1;
	return (res);
}
