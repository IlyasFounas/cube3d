#ifndef CUBE3D_RENDER_H
# define CUBE3D_RENDER_H

# include "libft.h"
# include "mlx.h"
# include "structures.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*___________hard_coded_parsing_____*/
void	init_structs(t_global_infos *infos);
int	**hard_coded_2dmap(t_global_infos *infos);

/*___________free_rendering______*/
void	free_rendering(t_global_infos *infos);

/*___________graphic_rendering______*/
void	graphic_rendering(double distance, t_data *img, int i,
		t_global_infos *infos);

/*___________rendering______*/
int	rendering(void *param);

/*___________events_handeling_____*/
int	manage_events(int keycode, t_global_infos *infos);

/*___________window_handeling_____*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	create_image(t_global_infos *infos, t_data *img);
void	destroy_image(t_global_infos *infos, t_data *img);
void	window_handeling(t_global_infos *infos);

#endif