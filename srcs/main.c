/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:01:35 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/24 12:01:35 by ifounas          ###   ########.fr       */
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
	t_map_infos	map;
	int	fd;

	fd = open("mapValid.cub", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		exit(EXIT_FAILURE);
	}
	init_map(&map);
	map.width = get_map_width(fd);
	close(fd);
	exit_if(map.width == 0, map, "No map provided in file", EXIT_FAILURE);
	fd = open("mapValid.cub", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		exit(EXIT_FAILURE);
	}
	file_map(&map, fd);
	if (is_surr_by_wall(&map))
		printf("Map surrounded by walls\n");
	else
		printf("Map invalid\n");
	free_map(&map);
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
