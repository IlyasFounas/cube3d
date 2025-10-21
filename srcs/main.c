/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/09/24 12:01:35 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/24 12:01:35 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


// static void	display_error(t_global_infos *infos)
// {
// 	write(2, "malloc error\n", ft_strlen("malloc error\n"));
// 	free_rendering(infos);
// 	exit(1);
// }

int	main(int argc, char **argv)
{
	t_map_infos map;

	if (argc != 2)
	{
		printf("Cub3d: invalid number of arguments\n");
		printf("Usage: ./cub3d <map_file.cub>\n");
		return (1);
	}
	init_map(&map);
	map.fd.name = argv[1];
	parse_scene(&map);
	// t_global_infos infos;

	// ft_memset(&infos, 0, sizeof(t_global_infos));
	// infos.map_infos = malloc(sizeof(t_map_infos));
	// infos.ray_infos = malloc(sizeof(t_ray_infos));
	// if (!infos.map_infos || !infos.ray_infos)
	// 	display_error(&infos);
	// ft_memset(infos.map_infos, 0, sizeof(t_map_infos));
	// ft_memset(infos.ray_infos, 0, sizeof(t_ray_infos));
	// init_structs(&infos);
	// window_handeling(&infos);
	// free_rendering(&infos);
	return (0);
}
