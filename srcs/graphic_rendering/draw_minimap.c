/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:47:47 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/07 15:44:07 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	digit_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	draw_scaled(t_data *img, t_drawable drawable, int scale)
{
	int		i;
	int		j;
	double	m_x;
	double	m_y;

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
	return (x >= 0 && x < infos->map_infos->x && y >= 0
		&& y < infos->map_infos->y);
}

void	draw_square(t_global_infos *infos, t_point d_p, t_point i_p)
{
	if (!is_in_range(infos, i_p.x, i_p.y))
		draw_scaled(&infos->img, (t_drawable){d_p.x, d_p.y, 30, 30,
			COLOR_GRAY_LIGHT}, 7);
	else if (is_in_range(infos, i_p.x, i_p.y)
		&& infos->map[(int)i_p.y][(int)i_p.x] == 1)
		draw_scaled(&infos->img, (t_drawable){d_p.x, d_p.y, 30, 30,
			COLOR_BLACK_TRANS}, 7);
	else if (is_in_range(infos, i_p.x, i_p.y)
		&& infos->map[(int)i_p.y][(int)i_p.x] == 0)
		draw_scaled(&infos->img, (t_drawable){d_p.x, d_p.y, 30, 30,
			COLOR_GRAY_TRANS}, 7);
	else
		draw_scaled(&infos->img, (t_drawable){d_p.x, d_p.y, 30, 30,
			COLOR_GRAY_LIGHT}, 7);
}

void	draw_minimap(t_global_infos *infos)
{
	int	y;
	int	x;
	int	d_x;
	int	d_y;

	y = floor(infos->py) - MINIMAP_Y;
	d_y = 0.0;
	while (y < floor(infos->py) + MINIMAP_Y)
	{
		x = floor(infos->px) - MINIMAP_X;
		d_x = 0.0;
		while (x < floor(infos->px) + MINIMAP_X)
		{
			draw_square(infos, (t_point){d_x, d_y}, (t_point){x, y});
			x++;
			d_x++;
		}
		d_y++;
		y++;
	}
	draw_scaled(&infos->img, (t_drawable){MINIMAP_X, MINIMAP_Y, 30, 30,
		COLOR_RED_TRANS}, 7);
}
