/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handeling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:08:58 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/25 15:08:58 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	create_image(t_global_infos *infos, t_data *img)
{
	img->img = mlx_new_image(infos->mlx, infos->map_infos->width,
			infos->map_infos->height);
	if (!img->img)
		mlx_error(infos);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		mlx_error(infos);
}

int	close_window(t_global_infos *infos)
{
	free_rendering(infos);
	exit(0);
	return (0);
}

void	window_handeling(t_global_infos *infos)
{
	infos->mlx = mlx_init();
	if (!infos->mlx)
		malloc_error(infos);
	infos->mlx_win = mlx_new_window(infos->mlx, infos->map_infos->width,
			infos->map_infos->height, "cub3D");
	if (!infos->mlx_win)
		malloc_error(infos);
	create_textures(infos);
	create_image(infos, &infos->img);
	mlx_hook(infos->mlx_win, 2, 1L << 0, keys_pressed, infos);
	mlx_hook(infos->mlx_win, 3, 1L << 1, keys_released, infos);
	mlx_hook(infos->mlx_win, 17, 0, close_window, infos);
	mlx_loop_hook(infos->mlx, raycasting, infos);
	mlx_loop(infos->mlx);
}
