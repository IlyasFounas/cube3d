#ifndef RENDER_H
# define RENDER_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_map_infos
{
	int height;
	int width;
	int x;
	int y;
} t_map_infos;

typedef struct s_player_infos
{
	double px;
	double py;
	double ray_dir_x;
	double ray_dir_y;
	double plane_x;
	double plane_y;
	void *mlx;
	void *mlx_win;
	int **map;
	t_map_infos *map_infos;
} t_player_infos;

/*___________dda_algorithm______*/
int	render_algo(void *param);

/*___________utils_____*/
void	display_error(void);
void	free_map(int **map);
int	**hard_coded_2dmap(t_player_infos *infos);

/*___________window_____*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	show_window(t_player_infos *infos);

#endif