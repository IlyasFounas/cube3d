#include "render.h"

static void	draw_walls(double distance, t_data *img, int i)
{
	int	wall_height;
	int	start_y;
	int	end_y;

	wall_height = (int)(700 / distance);
	start_y = (700 - wall_height) / 2;
	end_y = start_y + wall_height;
	for (int y = start_y; y < end_y; y++)
		my_mlx_pixel_put(img, i, y, 0x00FF0000); // wall
	for (int y = 0; y < start_y; y++)
		my_mlx_pixel_put(img, i, y, 0x00666666); // ceiling
	for (int y = end_y; y < 700; y++)
		my_mlx_pixel_put(img, i, y, 0x00333333); // floor
}

// static double	dda_algo(t_player_infos *infos)
// {
// 	int i;
// 	double	distance;
// 	double py_cpy;

// 	i = 0;
// 	distance = 0.0;
// 	py_cpy = infos->py;
// 	while (infos->px + i < infos->map_infos->x)
// 	{
// 		while (py_cpy >= 0)
// 		{
// 			distance++;
// 			if (infos->map[(int)infos->px][(int)py_cpy--] == 1)
// 				return (distance);
// 		}
// 		i++;
// 	}
// 	return (distance);
// }

static double dda_algo(t_player_infos *infos)
{
    double current_x = infos->px;
    double current_y = infos->py;
    double distance = 0.0;
    double step = 0.01;  // Précision
    
    // Suivre la direction du rayon
    while (current_x >= 0 && current_x < infos->map_infos->x &&
           current_y >= 0 && current_y < infos->map_infos->y) {
        
        current_x += infos->ray_dir_x * step;
        current_y += infos->ray_dir_y * step;
        distance += step;
        
        if (infos->map[(int)current_x][(int)current_y] == 1) {
            return (distance);
        }
    }
    return (distance);
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
	img.img = mlx_new_image(infos->mlx, 700, 700);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (i < 700)
	{
		camera_x = 2 * i / (double)700 - 1;
		infos->ray_dir_x = /* infos->dir_x */ 0 + infos->plane_x * camera_x;
		infos->ray_dir_y = /* infos->dir_y */ (-1) + infos->plane_y * camera_x;
		distance = dda_algo(infos);
		draw_walls(distance, &img, i);
		i++;
	}
	mlx_put_image_to_window(infos->mlx, infos->mlx_win, img.img, 0, 0);
	mlx_destroy_image(infos->mlx, img.img);
	return (0);
}
