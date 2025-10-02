/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:02:47 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/25 15:08:04 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_rendering(t_global_infos *infos)
{
	int	i;

	i = -1;
	if (infos->map)
	{
		while (++i < 4)
			free(infos->map[i]);
		free(infos->map);
		infos->map = NULL;
	}
	if (infos->map_infos)
	{
		free(infos->map);
		infos->map = NULL;
	}
	if (infos->ray_infos)
	{
		free(infos->ray_infos);
		infos->ray_infos = NULL;
	}
}
