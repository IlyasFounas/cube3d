/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_handeling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:58:52 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/25 17:54:40 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	update_player_position(t_global_infos *infos)
{
	t_keys	*keys;

	keys = infos->keys;
	if (keys->W == 1)
		infos->py -= 0.01;
	if (keys->S == 1)
		infos->py += 0.01;
	if (keys->A == 1)
		infos->px -= 0.01;
	if (keys->D == 1)
		infos->px += 0.01;
}

int	keys_pressed(int keycode, t_global_infos *infos)
{
	t_keys	*keys;

	keys = infos->keys;
	if (keycode == 119)
		keys->W = 1;
	if (keycode == 115)
		keys->S = 1;
	if (keycode == 100)
		keys->D = 1;
	if (keycode == 97)
		keys->A = 1;
	return (0);
}

int	keys_released(int keycode, t_global_infos *infos)
{
	t_keys	*keys;

	keys = infos->keys;
	if (keycode == 119)
		keys->W = 0;
	if (keycode == 115)
		keys->S = 0;
	if (keycode == 100)
		keys->D = 0;
	if (keycode == 97)
		keys->A = 0;
	return (0);
}
