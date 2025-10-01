#ifndef CUBE3D_RENDER_H
# define CUBE3D_RENDER_H

# include "libft.h"
# include "mlx.h"
# include "structures.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/*___________hard_coded_parsing_____*/
void	init_structs(t_global_infos *infos);
int	**hard_coded_2dmap(t_global_infos *infos);

/*___________free_rendering______*/
void	free_rendering(t_global_infos *infos);

/*___________graphic_rendering______*/
void	calcul_the_fps(void);
void	graphic_rendering(double distance, t_data *img, int i,
		t_global_infos *infos);

/*___________esk_algo______*/
double	esk_algo(t_global_infos *infos);

/*___________rendering______*/
int	rendering(void *param);

/*___________movements_handeling_____*/
void	update_player_rotation(t_global_infos *infos);
void	update_player_position(t_global_infos *infos);
int	keys_pressed(int keycode, t_global_infos *infos);
int	keys_released(int keycode, t_global_infos *infos);

/*___________window_handeling_____*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	create_image(t_global_infos *infos, t_data *img);
void	destroy_image(t_global_infos *infos, t_data *img);
void	window_handeling(t_global_infos *infos);

#endif