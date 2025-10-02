#ifndef CUBE3D_RENDER_H
# define CUBE3D_RENDER_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include "structures.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/*____________________________GRAPHIC_RENDERING__________________________*/
/*---free_rendering---*/
void	free_rendering(t_global_infos *infos);

/*---graphic_rendering---*/
void	calcul_the_fps(void);
void	graphic_rendering(double distance, t_data *img, int i,
		t_global_infos *infos);

/*---texture_rendering---*/
void	wall_rendering(t_global_infos *infos, t_data *img, int i, int y);

/*____________________________PARSING__________________________________*/
/*---hard_coded_parsing---*/
void	init_structs(t_global_infos *infos);
int	**hard_coded_2dmap(t_global_infos *infos);

/*____________________________RAYCASTING_______________________________*/
/*---solving_linear_equa---*/
double	solving_linear_equa(t_global_infos *infos);

/*---raycasting---*/
int	raycasting(void *param);

/*____________________________WINDOW HANDELING_________________________*/
/*---movements_handeling---*/
void	update_player_rotation(t_global_infos *infos);
void	update_player_position(t_global_infos *infos);
int	keys_pressed(int keycode, t_global_infos *infos);
int	keys_released(int keycode, t_global_infos *infos);

/*---window_handeling---*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	create_image(t_global_infos *infos, t_data *img);
void	destroy_image(t_global_infos *infos, t_data *img);
void	window_handeling(t_global_infos *infos);

#endif