/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:01:38 by ifounas           #+#    #+#             */
/*   Updated: 2025/11/05 09:34:13 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	calculs_of_vectors(t_global_infos *infos, int i)
{
	double	camera_x;

	camera_x = 2 * i / (double)infos->map_infos->width - 1;
	infos->ray_infos->ray_dir_x = infos->ray_infos->dir_x
		+ infos->ray_infos->plane_x * camera_x;
	infos->ray_infos->ray_dir_y = infos->ray_infos->dir_y
		+ infos->ray_infos->plane_y * camera_x;
}

/**
 * Real-time 3D rendering using raycasting technique:
 * - Casts multiple rays across the field of view (one per screen column)
 * - For each ray, calculates intersection distance with walls in the 2D map
 * - Uses distance to determine wall height and render ceiling/wall/floor
 * segments
 * - Applies fisheye correction for proper perspective projection
 */
int	raycasting(void *param)
{
	t_global_infos	*infos;
	int				i;
	double			distance;

	infos = (t_global_infos *)param;
	i = 0;
	calcul_the_fps(infos);
	update_player_rotation(infos);
	update_player_position(infos);
	straf_position(infos);
	while (i < infos->map_infos->width)
	{
		calculs_of_vectors(infos, i);
		distance = solving_linear_equa(infos);
		graphic_rendering(distance, &infos->img, i, infos);
		i++;
	}
	mlx_put_image_to_window(infos->mlx, infos->mlx_win, infos->img.img, 0, 0);
	return (0);
}
