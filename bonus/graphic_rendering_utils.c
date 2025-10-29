/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_rendering_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:57:22 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/29 17:07:23 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int return_color_bonus(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = color.r;
	g = color.g;
	b = color.b;
	return ((r << 16) | (g << 8) | (b));
}

int	darken_color(int color, float factor)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) * factor;
	g = ((color >> 8) & 0xFF) * factor;
	b = (color & 0xFF) * factor;
	return ((r << 16) | (g << 8) | b);
}

int	return_ult_darken_color(t_global_infos *infos, int color, int y, int yes)
{
	float	factor;

	if ((y >= (infos->map_infos->height / 2) - 130
		&& y < (infos->map_infos->height / 2) + 130) || yes == 0)
	{
		if (infos->fog_ratio > 5)
		{
			factor = 1.0f - ((double)infos->fog_ratio * 0.09f);
			if (factor < 0.0f)
				factor = 0.0f;
			color = darken_color(color, factor);
		}
	}
	return (color);
}
