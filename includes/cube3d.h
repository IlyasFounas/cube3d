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
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

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

/*___________parsing___________*/
bool	safe_open(char *filename, int *fd);
bool	get_map_width(t_map_infos *map);
bool	parse_scene(t_map_infos *map);
void	copy_file(t_map_infos *map);
bool 	is_surr_by_wall(t_map_infos *map);
bool	check_map_validity(t_map_infos *map);

void	init_map(t_map_infos *map);
void	init_fd(t_map_infos *map, t_fd *fd, char *name, int fd_i);

bool	is_texture(char *s);
bool	is_color(char *str);
bool	is_map(char *s);
bool	is_null_color(t_color color);

void	exit_if(bool cnd, t_map_infos *map, char *msg, int code);
void	free_dbl_char(char **tab, int start, int end);

#endif