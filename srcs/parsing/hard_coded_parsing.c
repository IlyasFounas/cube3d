/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:01:30 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/24 12:01:30 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void init_structs(t_global_infos *infos)
{
    infos->px = 1.2;
    infos->py = 6.4;
	infos->ray_infos->plane_x = 0.66;
	infos->ray_infos->dir_x = 0.0;
	infos->ray_infos->dir_y = -1.0;
	infos->map_infos->x = 14;
    infos->map_infos->y = 14;
    infos->map_infos->height = 700;
    infos->map_infos->width = 700;
	infos->map = hard_coded_2dmap(infos);
}

int	**hard_coded_2dmap(t_global_infos *infos)
{
	int **res;

	res = malloc(infos->map_infos->y * sizeof(int *));
	for (int i = 0; i < infos->map_infos->x ; i++)
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
		res[13][i] = 1;
		res[i][0] = 1;
		res[i][13] = 1;
	}
	res[1][2] = 1;
	res[4][2] = 1;
	res[4][1] = 1;
	return (res);
}
