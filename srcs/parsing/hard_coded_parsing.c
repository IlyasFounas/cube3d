/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coded_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/09/25 15:11:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/25 15:11:17 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_textures(t_global_infos *infos)
{
	t_data *img;

	img = &infos->textures->n_t_data;
	if (!infos->textures->north_t)
		infos->textures->north_t = "textures/mossy_cobblestone1.xpm";
	if (!img->img)
		img->img = mlx_xpm_file_to_image(infos->mlx,
				infos->textures->north_t, &infos->textures->t_width,
				&infos->textures->t_height);
	if (!img->addr)
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
				&img->line_length, &img->endian);
}

void	init_structs(t_global_infos *infos)
{
	infos->px = 1.2;
	infos->py = 6.4;
	infos->ray_infos->plane_x = 0.66;
	infos->ray_infos->dir_x = 0.0;
	infos->ray_infos->dir_y = -1.0;
	infos->map_infos->x = 20;
	infos->map_infos->y = 20;
	infos->map_infos->width = 1040;
	infos->map_infos->height = 880;
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
	res[1][2] = 1;
	res[4][2] = 1;
	res[4][1] = 1;
	res[7][5] = 1;
	res[8][4] = 1;
	return (res);
}
