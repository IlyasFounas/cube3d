/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:10:02 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/25 15:10:02 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	display_error(t_global_infos *infos)
{
	write(2, "malloc error\n", ft_strlen("malloc error\n"));
	free_rendering(infos);
	exit(1);
}

int	main(void)
{
	t_global_infos	infos;

	ft_memset(&infos, 0, sizeof(t_global_infos));
	infos.map_infos = malloc(sizeof(t_map_infos));
	infos.ray_infos = malloc(sizeof(t_ray_infos));
	infos.keys = malloc(sizeof(t_keys));
	if (!infos.map_infos || !infos.ray_infos || !infos.keys)
		display_error(&infos);
	ft_memset(infos.map_infos, 0, sizeof(t_map_infos));
	ft_memset(infos.ray_infos, 0, sizeof(t_ray_infos));
	ft_memset(infos.keys, 0, sizeof(t_keys));
	init_structs(&infos);
	window_handeling(&infos);
	free_rendering(&infos);
	return (0);
}
