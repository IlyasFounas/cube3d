/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:01:33 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/24 12:01:33 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	create_image(t_player_infos *infos, t_data *img)
{
	img->img = mlx_new_image(infos->mlx, infos->map_infos->width,
			infos->map_infos->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	manage_events(int keycode, t_player_infos *infos)
{
	(void)infos;
	if (keycode == 119)
		infos->py -= 0.2;
	if (keycode == 115)
		infos->py += 0.2;
	if (keycode == 100)
		infos->px += 0.2;
	if (keycode == 97)
		infos->px -= 0.2;
	return (1);
}

void	show_window(t_player_infos *infos)
{
	infos->mlx = mlx_init();
	infos->mlx_win = mlx_new_window(infos->mlx, infos->map_infos->width,
			infos->map_infos->height, "cube3D");
	mlx_loop_hook(infos->mlx, render_algo, infos);
	mlx_hook(infos->mlx_win, 2, 1L << 0, manage_events, infos);
	mlx_loop(infos->mlx);
}
