#include "cube3d_render.h"

static void	draw_walls(double distance, t_data *img, int i,
		t_player_infos *infos)
{
	int	wall_height;
	int	start_y;
	int	end_y;

	wall_height = (int)(infos->map_infos->height / distance);
	if (wall_height > infos->map_infos->height)
		wall_height = infos->map_infos->height;
	start_y = (infos->map_infos->height - wall_height) / 2;
	if (start_y < 0)
		start_y = 0;
	end_y = start_y + wall_height;
	if (end_y < 0)
		end_y = 0;
	for (int y = 0; y < start_y; y++)
		my_mlx_pixel_put(img, i, y, 0x00666666); // ceiling
	for (int y = start_y; y < end_y; y++)
		my_mlx_pixel_put(img, i, y, 0x00FF0000); // wall
	for (int y = end_y; y < infos->map_infos->height; y++)
		my_mlx_pixel_put(img, i, y, 0x00333333); // floor
}

static double	return_wall_distance(t_player_infos *infos)
{
	double	current_x;
	double	current_y;
	double	step;
	double	dx;
	double	dy;

	current_x = infos->px;
	current_y = infos->py;
	step = 0.1;
	while (current_x >= 0 && current_x < infos->map_infos->x && current_y >= 0
		&& current_y < infos->map_infos->y)
	{
		current_x += infos->ray_infos->ray_dir_x * step;
		current_y += infos->ray_infos->ray_dir_y * step;
		if (infos->map[(int)current_x][(int)current_y] == 1)
		{
			dx = current_x - infos->px;
			dy = current_y - infos->py;
			return (sqrt(dx * dx + dy * dy));
		}
	}
	return (1000.0);
}

/**
 * this algo is sending 1 rayon throught the 2d map
 * when the ray find a wall, he return the distance
 * This algo should be optimizate to build 60~144fps
 */
int	render_algo(void *param)
{
	t_player_infos	*infos;
	int				i;
	double			distance;
	double			camera_x;
	t_data			img;

	infos = (t_player_infos *)param;
	i = 0;
	img.img = mlx_new_image(infos->mlx, infos->map_infos->width, infos->map_infos->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (i < infos->map_infos->width)
	{
		camera_x = 2 * i / (double)infos->map_infos->width - 1;
		infos->ray_infos->ray_dir_x = infos->ray_infos->dir_x + infos->ray_infos->plane_x
			* camera_x;
		infos->ray_infos->ray_dir_y = infos->ray_infos->dir_y + infos->ray_infos->plane_y
			* camera_x;
		distance = return_wall_distance(infos);
		draw_walls(distance, &img, i, infos);
		i++;
	}
	mlx_put_image_to_window(infos->mlx, infos->mlx_win, img.img, 0, 0);
	mlx_destroy_image(infos->mlx, img.img);
	return (0);
}
