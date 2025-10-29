/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:47:47 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/29 22:47:55 by aboumall         ###   ########.fr       */
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

bool	is_in_range(t_global_infos *infos, int x, int y)
{
	return (x >= 0 && x < infos->map_infos->x
		&& y >= 0 && y < infos->map_infos->y);
}

void	draw_minimap2(t_global_infos *infos)
{
	int	y;
	int	x;
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;

	start_x = infos->px - 15;
	end_x = infos->px + 15;
	start_y = infos->py - 6;
	end_y = infos->py + 6;
	y = start_y;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x)
		{
			if (!is_in_range(infos, x, y))
				draw_scaled(&infos->img, (t_drawable){x, y, 30, 30,
					COLOR_BROWN_TRANS}, 5);
			if (is_in_range(infos, x, y) && infos->map[y][x] == 1)
				draw_scaled(&infos->img, (t_drawable){x, y, 30, 30,
					COLOR_BLACK_TRANS}, 5);
			if (is_in_range(infos, x, y) && infos->map[y][x] == 0)
				draw_scaled(&infos->img, (t_drawable){x, y, 30, 30,
					COLOR_GRAY_TRANS}, 5);
			x++;
		}
		y++;
	}
	// draw_scaled(&infos->img, (t_drawable){infos->px, infos->py, 30, 30,
	// 	COLOR_RED_TRANS}, 5);
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
