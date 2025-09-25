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
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	destroy_image(t_global_infos *infos, t_data *img)
{
	mlx_put_image_to_window(infos->mlx, infos->mlx_win, img->img, 0, 0);
	mlx_destroy_image(infos->mlx, img->img);
}

static int	close_window(t_global_infos *infos)
{
	(void)infos;
	exit(0);
	return (0);
}

void	window_handeling(t_global_infos *infos)
{
	infos->mlx = mlx_init();
	infos->mlx_win = mlx_new_window(infos->mlx, infos->map_infos->width,
			infos->map_infos->height, "cube3D");
	mlx_loop_hook(infos->mlx, rendering, infos);
	mlx_hook(infos->mlx_win, 2, 1L << 0, keys_pressed, infos);
	mlx_hook(infos->mlx_win, 3, 1L << 1, keys_released, infos);
	mlx_hook(infos->mlx_win, 17, 0, close_window, infos);
	mlx_loop(infos->mlx);
}
