#ifndef CUBE3D_STRUCTS_H
# define CUBE3D_STRUCTS_H

# define EMPTY_SPACE '0'
# define WALL '1'
# define PLAYER_START "NSEW"

# define MSG_ERR_MP_EX "Error\nCub3d: invalid file extension `.cub' file expected\n"
# define MSG_ERR_MP_PF "Error\nCub3d: no player start position found\n"
# define MSG_ERR_MP_MP "Error\nCub3d: multiple player start positions found\n"
# define MSG_ERR_MP_IC "Error\nCub3d: invalid character '%c' in map\n"
# define MSG_ERR_MP_WL "Error\nCub3d: map is not surrounded by walls"
# define MSG_ERR_MP_MC "Error\nCub3d: missing map configuration"

# define MSG_ERR_ML_ER "Error\nCub3d: malloc error"

# define MSG_ERR_TX_NO "Error\nCub3d: multiple NO texture definition"
# define MSG_ERR_TX_SO "Error\nCub3d: multiple SO texture definition"
# define MSG_ERR_TX_WE "Error\nCub3d: multiple WE texture definition"
# define MSG_ERR_TX_EA "Error\nCub3d: multiple EA texture definition"
# define MSG_ERR_TX_MS "Error\nCub3d: missing texture files"

# define MSG_ERR_CR_MF "Error\nCub3d: multiple floor color definition"
# define MSG_ERR_CR_MC "Error\nCub3d: multiple ceiling color definition"
# define MSG_ERR_CR_IF "Error\nCub3d: invalid floor color"
# define MSG_ERR_CR_IC "Error\nCub3d: invalid ceiling color"
# define MSG_ERR_CR_MS "Error\nCub3d: missing color configuration"

# define MSG_ERR_MAP_L "Error\nCub3d: wrong file configuration map should be last"

# define FNT_0_XPM "textures/digits/0.xpm"
# define FNT_1_XPM "textures/digits/1.xpm"
# define FNT_2_XPM "textures/digits/2.xpm"
# define FNT_3_XPM "textures/digits/3.xpm"
# define FNT_4_XPM "textures/digits/4.xpm"
# define FNT_5_XPM "textures/digits/5.xpm"
# define FNT_6_XPM "textures/digits/6.xpm"
# define FNT_7_XPM "textures/digits/7.xpm"
# define FNT_8_XPM "textures/digits/8.xpm"
# define FNT_9_XPM "textures/digits/9.xpm"
# define FNT_F_XPM "textures/digits/F.xpm"
# define FNT_P_XPM "textures/digits/P.xpm"
# define FNT_S_XPM "textures/digits/S.xpm"
# define FNT_CLN_XPM "textures/digits/colon.xpm"

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
	int					W;
	int					A;
	int					S;
	int					D;
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

typedef struct s_font
{
	void				*img[16];
	int					width;
	int					height;
}						t_font;

typedef struct s_global_infos
{
	double				px;
	double				py;
	void				*mlx;
	void				*mlx_win;
	int					**map;
	double				p_angle;
	double				ray_angle;
	int					tex_x;
	int					tex_y;
	t_type				actual_orientation;
	t_ray_infos			*ray_infos;
	t_map_infos			*map_infos;
	t_textures			*textures;
	t_keys				*keys;
	t_data				img;
	int					fps;
	char				*char_fps;
	int					***digits;
	t_font				font;
}						t_global_infos;

#endif