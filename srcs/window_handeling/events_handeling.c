/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handeling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:58:52 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/24 18:12:13 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	manage_events(int keycode, t_global_infos *infos)
{
	(void)infos;
	printf("%d\n", keycode);
	if (keycode == 119)
		infos->py -= 0.1;
	if (keycode == 115)
		infos->py += 0.1;
	if (keycode == 100)
		infos->px += 0.1;
	if (keycode == 97)
		infos->px -= 0.1;
	if (keycode == 65361)
	{
		if (infos->ray_infos->dir_x > 0)
			infos->ray_infos->dir_x -= 0.01;
	}
	if (keycode == 65363)
	{
		if (infos->ray_infos->dir_x < 1)
			infos->ray_infos->dir_x += 0.01;
	}
	return (1);
}
