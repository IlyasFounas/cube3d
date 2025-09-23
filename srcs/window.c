#include "cube3d_render.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	create_image(t_player_infos *infos, t_data *img)
{
	img->img = mlx_new_image(infos->mlx, infos->map_infos->width,
			infos->map_infos->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	manage_events(int keycode, t_player_infos *infos)
{
	(void)infos;
	printf("%d\n", keycode);
	if (keycode == 119)
		infos->py--;
	if (keycode == 115)
		infos->py++;
	if (keycode == 100)
		infos->px++;
	if (keycode == 97)
		infos->px--;
	return (1);
}

void	show_window(t_player_infos *infos)
{
	infos->mlx = mlx_init();
	infos->mlx_win = mlx_new_window(infos->mlx, infos->map_infos->width,
			infos->map_infos->height, "cube3D");
	mlx_loop_hook(infos->mlx, render_algo, infos);
	mlx_hook(infos->mlx_win, 2, 1L << 0, manage_events, infos);
	mlx_loop(infos->mlx);
}
