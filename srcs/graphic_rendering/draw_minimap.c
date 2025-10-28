/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:47:47 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/28 14:14:55 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_scaled(t_data *img, t_drawable drawable, int scale)
{
	int	i;
	int	j;
	int	m_x;
	int	m_y;

	j = 0;
	while (j < scale)
	{
		i = 0;
		m_x = drawable.padding_x + drawable.x * scale;
		m_y = drawable.padding_y + drawable.y * scale;
		while (i < scale)
		{
			my_mlx_pixel_put(img, m_x + i, m_y + j, drawable.color);
			i++;
		}
		j++;
	}
}

void	draw_minimap(t_global_infos *infos)
{
	int	x;
	int	y;

	y = 0;
	while (y < infos->map_infos->y)
	{
		x = 0;
		while (x < infos->map_infos->x)
		{
			if (infos->map[y][x] == 1)
				draw_scaled(&infos->img, (t_drawable){x, y, 30, 30,
					COLOR_BLACK_TRANS}, 5);
			if (infos->map[y][x] == 0)
				draw_scaled(&infos->img, (t_drawable){x, y, 30, 30,
					COLOR_GRAY_TRANS}, 5);
			x++;
		}
		y++;
	}
	draw_scaled(&infos->img, (t_drawable){infos->px, infos->py, 30, 30,
		COLOR_RED_TRANS}, 5);
}
