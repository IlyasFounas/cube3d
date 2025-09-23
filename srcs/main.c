#include "cube3d_render.h"

void init_structs(t_player_infos *infos)
{
    infos->px = 1.2;
    infos->py = 6.4;
	infos->ray_infos->plane_x = 0.66;
	infos->ray_infos->dir_x = 0.7;
	infos->ray_infos->dir_y = -1;
	infos->map_infos->x = 8;
    infos->map_infos->y = 8;
    infos->map_infos->height = 1000;
    infos->map_infos->width = 1000;
	infos->map = hard_coded_2dmap();
}

int	main(void)
{
    t_player_infos infos;

    ft_memset(&infos, 0, sizeof(t_player_infos));
	infos.map_infos = malloc(sizeof(t_map_infos));
	infos.ray_infos = malloc(sizeof(t_ray_infos)); 
	if (!infos.map_infos || !infos.ray_infos)
		// CALL A GARBAGE COLLECTOR
		return (1);
    ft_memset(infos.map_infos, 0, sizeof(t_map_infos));
    ft_memset(infos.ray_infos, 0, sizeof(t_ray_infos));
	init_structs(&infos);
	show_window(&infos);
	// CALL A GARBAGE COLLECTOR
	return (0);
}
