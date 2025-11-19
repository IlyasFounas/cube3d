/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:47:03 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/07 15:47:03 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MALLOC_FAILED 1
# define SUCCESS 0
# define M_PI 3.14159265358979323846

# define MSG_ERR_MP_EX "Error\nCub3d: invalid file extension `.cub'\
 file expected\n"
# define MSG_ERR_MP_PF "Error\nCub3d: no player start position found\n"
# define MSG_ERR_MP_MP "Error\nCub3d: multiple player start positions\
 found\n"
# define MSG_ERR_MP_IC "Error\nCub3d: invalid character in map\n"
# define MSG_ERR_MP_WL "Error\nCub3d: map is not surrounded by walls\n"
# define MSG_ERR_MP_MC "Error\nCub3d: missing map configuration\n"

# define MSG_ERR_ML_ER "Error\nCub3d: malloc error\n"

# define MSG_ERR_TX_NO "Error\nCub3d: multiple NO texture definition\n"
# define MSG_ERR_TX_SO "Error\nCub3d: multiple SO texture definition\n"
# define MSG_ERR_TX_WE "Error\nCub3d: multiple WE texture definition\n"
# define MSG_ERR_TX_EA "Error\nCub3d: multiple EA texture definition\n"
# define MSG_ERR_TX_MS "Error\nCub3d: missing texture files\n"

# define MSG_ERR_CR_MF "Error\nCub3d: multiple floor color definition\n"
# define MSG_ERR_CR_MC "Error\nCub3d: multiple ceiling color definition\n"
# define MSG_ERR_CR_IF "Error\nCub3d: invalid floor color\n"
# define MSG_ERR_CR_IC "Error\nCub3d: invalid ceiling color\n"
# define MSG_ERR_CR_MS "Error\nCub3d: missing color configuration\n"

# define MSG_ERR_MAP_L "Error\nCub3d: wrong file configuration map\
 should be last\n"

# define MINIMAP_X 16.0
# define MINIMAP_Y 9.0

# define COLOR_BLACK_TRANS 0x00000000
# define COLOR_GRAY_TRANS 0x88404040
# define COLOR_GRAY_LIGHT 0x88A0A0A0
# define COLOR_RED_TRANS 0x88FF0000
# define COLOR_BROWN_TRANS 0x88A52A2A

typedef struct s_point
{
	double			x;
	double			y;
}				t_point;

typedef struct s_drawable
{
	double				x;
	double				y;
	double				padding_x;
	double				padding_y;
	unsigned int		color;
}						t_drawable;

typedef struct s_color
{
	int32_t				r;
	int32_t				g;
	int32_t				b;
}						t_color;

typedef struct s_fd
{
	char				*name;
	int					fd;
}						t_fd;

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef enum e_type
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	PORTAL
}						t_type;

typedef struct s_textures
{
	int					t_width;
	int					t_height;
	t_data				data;
	t_type				type;
	char				*name_texture;
	struct s_textures	*next;
}						t_textures;

typedef struct s_linear_equa
{
	int					start_x;
	int					start_y;
	int					step_x;
	int					step_y;
	int					map_x;
	int					map_y;
	double				ix;
	double				iy;
	int					x;
	int					y;
	double				t_vertical;
	double				t_horizontal;
	double				shortest_t;
}						t_linear_equa;

typedef struct s_keys
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					f;
	int					k;
	int					left;
	int					right;
}						t_keys;

typedef struct s_map_infos
{
	int					height;
	int					width;
	int					x;
	int					y;
	char				**tmp_map;
	int					err_gnl;
	int					start_angle;
	t_fd				fd;
	t_fd				no_path;
	t_fd				so_path;
	t_fd				we_path;
	t_fd				ea_path;
	t_color				floor_color;
	t_color				ceiling_color;
	int					player_found;
}						t_map_infos;

typedef struct s_ray_infos
{
	double				ray_dir_x;
	double				ray_dir_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
}						t_ray_infos;

typedef struct s_global_infos
{
	double				px;
	double				py;
	double				tex_step;
	double				tex_pos;
	void				*mlx;
	void				*mlx_win;
	int					**map;
	int					tex_x;
	int					tex_y;
	t_type				actual_orientation;
	t_ray_infos			*ray_infos;
	t_map_infos			*map_infos;
	t_textures			*textures;
	t_keys				*keys;
	t_data				img;
	int					fps;
	int					***digits;
	int					fog_ratio;
	int					mouse_left;
	int					mouse_right;
	bool				draw_minimap;
	bool				draw_fps;
}						t_global_infos;

t_textures				*new_node_texture(char *s, t_type type);
t_textures				*last_node(t_textures *textures);

/*____________________________GRAPHIC_RENDERING__________________________*/
/*---free_rendering---*/
void					free_rendering(t_global_infos *infos);

/*---graphic_rendering---*/
void					calcul_the_fps(t_global_infos *infos);
void					draw_wall(t_global_infos *infos, t_data *img, int i,
							int y);
void					graphic_rendering(double distance, t_data *img, int i,
							t_global_infos *infos);

/*---texture_rendering---*/
void					add_back_node(t_textures **textures, t_textures *new,
							int *malloc_failed);
void					texture_start(t_global_infos *infos, int wall_height,
							int start_y);
void					wall_rendering(t_global_infos *infos, t_data *img,
							int i, int y);

/*____________________________RAYCASTING_______________________________*/
/*---raycasting---*/
int						raycasting(void *param);

/*---solving_linear_equa---*/
double					solving_linear_equa(t_global_infos *infos);

/*---solving_linear_utils---*/
void					init_linear_ray(t_global_infos *infos,
							t_linear_equa *linear_ray);
void					setting_the_right_texture(t_global_infos *infos,
							t_linear_equa *linear_ray);

/*____________________________WINDOW HANDELING_________________________*/
/*---movements_handeling_utils---*/
int						wall_collision(t_global_infos *infos, double y,
							double x);
void					straf_position(t_global_infos *infos);

/*---movements_handeling---*/
void					update_player_rotation(t_global_infos *infos);
void					update_player_position(t_global_infos *infos);
int						keys_pressed(int keycode, t_global_infos *infos);
int						keys_released(int keycode, t_global_infos *infos);

/*---window_handeling---*/
void					my_mlx_pixel_put(t_data *data, int x, int y,
							int color);
void					create_image(t_global_infos *infos, t_data *img);
int						close_window(t_global_infos *infos);
void					window_handeling(t_global_infos *infos);

/*____________________________PARSING_________________________________*/
/*---parsing_textures---*/
void					create_textures(t_global_infos *infos);

/*---parsing---*/
void					init_textures(t_global_infos *infos,
							t_textures *textures);
void					init_structs(t_global_infos *infos);

int						ft_line_len(char *line);
int						dbl_char_len(char **tab);
bool					get_map_width(t_map_infos *map);
bool					is_surr_by_wall(t_map_infos *map);
bool					check_map_validity(t_map_infos *map);

void					check_copy_error(bool cnd, t_map_infos *map,
							char **line, char *msg);
void					copy_file(t_map_infos *map);
void					add_tab(char *line, int *i);
bool					parse_scene(t_map_infos *map);
void					parse_colors(t_map_infos *map);
void					parse_textures(t_map_infos *map);
bool					check_xpm_file(t_map_infos *map);

char					found_last(char *line);
char					found_first(char *line);
void					*free_tab(int **tab, int i);
void					fill_cells(t_map_infos *map, int **f_map, int x, int y);
int						**fill_map(t_map_infos *map);
char					*append_map(t_map_infos *map, char *line);
void					init_map(t_map_infos *map, char *filename);
bool					is_surr_floor(t_map_infos *map, int x, int y);

void					free_fd(t_fd *fd);
void					free_map(t_map_infos *map);
void					init_fd(t_map_infos *map, t_fd *fd, char *name,
							int fd_i);

bool					is_map(char *s);
bool					is_space(char c);
bool					is_player(char c);
bool					is_content(char c);
bool					is_texture(char *s);
bool					is_color(char *str);
bool					is_xpm_file(char *filename);
bool					is_cub_file(char *filename);
bool					is_null_color(t_color color);
bool					is_good_color(t_color color);

bool					error_text(char *err);
int						ft_strlen_trim(const char *tab);
bool					safe_open(char *filename, int *fd);
void					exit_if(bool cnd, t_map_infos *map, char *msg,
							int code);
void					free_dbl_char(char **tab, int start, int end,
							bool free_all);

void					draw_minimap(t_global_infos *infos);
int						digit_len(int n);

/*____________________________MAIN_______________________________*/
void					malloc_error(t_global_infos *infos);
void					mlx_error(t_global_infos *infos);

/*____________________________BONUS PART_______________________________*/
int						raycasting_bonus(void *param);
void					window_handeling_bonus(t_global_infos *infos);
void					graphic_rendering_bonus(double distance, t_data *img,
							int i, t_global_infos *infos);
int						darken_color(int color, double factor);
int						return_ult_darken_color(t_global_infos *infos,
							int color, int y, int yes);
int						return_color_bonus(t_color color);
int						handle_mouse_movements(t_global_infos *infos);

#endif