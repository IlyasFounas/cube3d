/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handeling_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:48:57 by ifounas           #+#    #+#             */
/*   Updated: 2025/11/06 17:37:18 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	window_handeling_bonus(t_global_infos *infos)
{
	infos->mlx = mlx_init();
	if (!infos->mlx)
		malloc_error(infos);
	infos->mlx_win = mlx_new_window(infos->mlx, infos->map_infos->width,
			infos->map_infos->height, "cub3D");
	if (!infos->mlx_win)
		malloc_error(infos);
	create_textures(infos);
	load_font(infos);
	create_image(infos, &infos->img);
	mlx_hook(infos->mlx_win, 2, 1L << 0, keys_pressed, infos);
	mlx_hook(infos->mlx_win, 3, 1L << 1, keys_released, infos);
	mlx_hook(infos->mlx_win, 17, 0, close_window, infos);
	mlx_mouse_move(infos->mlx, infos->mlx_win, infos->map_infos->width / 2,
		infos->map_infos->height / 2);
	mlx_loop_hook(infos->mlx, raycasting_bonus, infos);
	mlx_loop(infos->mlx);
}
