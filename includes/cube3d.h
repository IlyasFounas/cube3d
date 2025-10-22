#ifndef CUBE3D_RENDER_H
# define CUBE3D_RENDER_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include "structures.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define MALLOC_FAILED 1
# define SUCCESS 0
#define M_PI 3.14159265358979323846

/*____________________________GRAPHIC_RENDERING__________________________*/
/*---free_rendering---*/
void	free_rendering(t_global_infos *infos);

/*---graphic_rendering---*/
void	calcul_the_fps(t_global_infos *infos);
void	graphic_rendering(double distance, t_data *img, int i,
		t_global_infos *infos);

/*---texture_rendering---*/
t_textures	*new_node_texture(char *s, t_type type);
t_textures	*last_node(t_textures *textures);
void	add_back_node(t_textures **textures, t_textures *new,
		int *malloc_failed);
void	wall_rendering(t_global_infos *infos, t_data *img, int i, int y);

/*____________________________PARSING__________________________________*/
/*---hard_coded_parsing---*/
void	init_textures(t_global_infos *infos, t_textures *textures);
void	create_textures(t_global_infos *infos);
void	init_structs(t_global_infos *infos);
int	**hard_coded_2dmap(t_global_infos *infos);

/*____________________________RAYCASTING_______________________________*/
/*---raycasting---*/
int	raycasting(void *param);

/*---solving_linear_equa---*/
double	solving_linear_equa(t_global_infos *infos);

/*---solving_linear_utils---*/
void	init_linear_ray(t_global_infos *infos, t_linear_equa *linear_ray);
void	setting_the_right_texture(t_global_infos *infos,
		t_linear_equa *linear_ray);

/*____________________________WINDOW HANDELING_________________________*/
/*---movements_handeling---*/
void	update_player_rotation(t_global_infos *infos);
void	update_player_position(t_global_infos *infos);
int	keys_pressed(int keycode, t_global_infos *infos);
int	keys_released(int keycode, t_global_infos *infos);

/*---window_handeling---*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	create_image(t_global_infos *infos, t_data *img);
void	window_handeling(t_global_infos *infos);

/*---main---*/
void	malloc_error(t_global_infos *infos);

#endif