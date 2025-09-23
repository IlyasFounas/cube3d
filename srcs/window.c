#include "cube3d_render.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	show_window(t_player_infos *infos)
{
	infos->mlx = mlx_init();
	infos->mlx_win = mlx_new_window(infos->mlx, infos->map_infos->width,
			infos->map_infos->height, "cube3D");
	mlx_loop_hook(infos->mlx, render_algo, infos);
	mlx_loop(infos->mlx);
}
