/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:05:01 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/23 16:05:01 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"
# include "structures.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*____________________________GRAPHIC_RENDERING__________________________*/
/*---free_rendering---*/
void	free_rendering(t_global_infos *infos);

/*---graphic_rendering---*/
void	calcul_the_fps(t_global_infos *infos);
void	graphic_rendering(double distance, t_data *img, int i,
			t_global_infos *infos);

/*---texture_rendering---*/
void	add_back_node(t_textures **textures, t_textures *new,
			int *malloc_failed);
void	wall_rendering(t_global_infos *infos, t_data *img, int i, int y);

/*____________________________PARSING__________________________________*/
/*---hard_coded_parsing---*/
void	init_textures(t_global_infos *infos, t_textures *textures);
void	create_textures(t_global_infos *infos);
void	init_structs(t_global_infos *infos);

/*____________________________RAYCASTING_______________________________*/
/*---raycasting---*/
int		raycasting(void *param);

/*---solving_linear_equa---*/
double	solving_linear_equa(t_global_infos *infos);

/*---solving_linear_utils---*/
void	init_linear_ray(t_global_infos *infos, t_linear_equa *linear_ray);
void	setting_the_right_texture(t_global_infos *infos,
			t_linear_equa *linear_ray);

/*____________________________WINDOW HANDELING_________________________*/
/*---movements_handeling_utils---*/
int		wall_collision(t_global_infos *infos, double y, double x);
void	straf_position(t_global_infos *infos, t_keys *keys, t_ray_infos *ray,
			double speed);

/*---movements_handeling---*/
void	update_player_rotation(t_global_infos *infos);
void	update_player_position(t_global_infos *infos);
int		keys_pressed(int keycode, t_global_infos *infos);
int		keys_released(int keycode, t_global_infos *infos);

/*---window_handeling---*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	create_image(t_global_infos *infos, t_data *img);
void	window_handeling(t_global_infos *infos);

/*____________________________PARSING_________________________________*/
int		ft_line_len(char *line);
int		dbl_char_len(char **tab);
bool	get_map_width(t_map_infos *map);
bool	is_surr_by_wall(t_map_infos *map);
bool	check_map_validity(t_map_infos *map);

void	copy_file(t_map_infos *map);
void	add_tab(char *line, int *i);
bool	parse_scene(t_map_infos *map);
void	parse_colors(t_map_infos *map);
void	parse_textures(t_map_infos *map);

char	found_last(char *line);
char	found_first(char *line);
int		**fill_map(t_map_infos *map);
char	*append_map(t_map_infos *map, char *line);
void	init_map(t_map_infos *map, char *filename);
bool	is_surr_floor(t_map_infos *map, int x, int y);

void	free_fd(t_fd *fd);
void	free_map(t_map_infos *map);
void	init_fd(t_map_infos *map, t_fd *fd, char *name, int fd_i);

bool	is_map(char *s);
bool	is_space(char c);
bool	is_player(char c);
bool	is_content(char c);
bool	is_texture(char *s);
bool	is_color(char *str);
bool	is_xpm_file(char *filename);
bool	is_cub_file(char *filename);
bool	is_null_color(t_color color);
bool	is_good_color(t_color color);

int		ft_strlen_trim(const char *tab);
bool	safe_open(char *filename, int *fd);
void	exit_if(bool cnd, t_map_infos *map, char *msg, int code);
void	free_dbl_char(char **tab, int start, int end, bool free_all);

void	load_font(t_global_infos *infos);
void	draw_fps(t_global_infos *infos);

/*____________________________MAIN_______________________________*/
void	malloc_error(t_global_infos *infos);

#endif