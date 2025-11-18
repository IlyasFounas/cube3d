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

void	malloc_error(t_global_infos *infos)
{
	write(2, MSG_ERR_ML_ER, ft_strlen(MSG_ERR_ML_ER));
	free_rendering(infos);
	exit(MALLOC_FAILED);
}

void	mlx_error(t_global_infos *infos)
{
	char	*error;

	error = "Error\nCub3d: mlx failed";
	write(2, error, ft_strlen(error));
	free_rendering(infos);
	exit(MALLOC_FAILED);
}

int	main(int argc, char **argv)
{
	t_global_infos	infos;
	t_map_infos		map;

	if (argc != 2)
	{
		printf("Cub3d: invalid number of arguments\n");
		printf("Usage: ./cub3d <map_file.cub>\n");
		return (1);
	}
	ft_memset(&infos, 0, sizeof(t_global_infos));
	init_map(&map, argv[1]);
	exit_if(!parse_scene(&map), &map, NULL, EXIT_FAILURE);
	infos.map_infos = &map;
	infos.ray_infos = malloc(sizeof(t_ray_infos));
	infos.keys = malloc(sizeof(t_keys));
	if (!infos.ray_infos || !infos.keys)
		malloc_error(&infos);
	ft_memset(infos.ray_infos, 0, sizeof(t_ray_infos));
	ft_memset(infos.keys, 0, sizeof(t_keys));
	init_structs(&infos);
	window_handeling(&infos);
	free_rendering(&infos);
	return (SUCCESS);
}
