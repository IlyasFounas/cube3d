#ifndef CUBE3D_RENDER_H
# define CUBE3D_RENDER_H

# include "libft.h"
# include "mlx.h"
# include "cube3d_structs.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*___________dda_algorithm______*/
int	render_algo(void *param);

/*___________utils_____*/
void	display_error(void);
void	free_map(int **map);
int	**hard_coded_2dmap(void);

/*___________window_____*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	show_window(t_player_infos *infos);

#endif