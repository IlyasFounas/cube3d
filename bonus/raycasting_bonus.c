/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:47:10 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/29 17:40:15 by aboumall         ###   ########.fr       */
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

int	raycasting_bonus(void *param)
{
	t_global_infos	*infos;
	int				i;
	double			distance;

	infos = (t_global_infos *)param;
	i = 0;
	calcul_the_fps(infos);
	update_player_rotation(infos);
	update_player_position(infos);
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
