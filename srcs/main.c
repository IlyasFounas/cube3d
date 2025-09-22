#include "render.h"

int	main(void)
{
    t_player_infos infos;

    ft_memset(&infos, 0, sizeof(t_player_infos));
    infos.px = 3.0;
    infos.py = 5.0;
	infos.map_infos = malloc(sizeof(t_map_infos));
	if (!infos.map_infos)
		return (1);
    ft_memset(infos.map_infos, 0, sizeof(t_map_infos));
	infos.map = hard_coded_2dmap(&infos);
	show_window(&infos);
	free_map(infos.map);
	return (0);
}
