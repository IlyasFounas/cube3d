#ifndef CUBE3D_STRUCTS_H
# define CUBE3D_STRUCTS_H

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_keys
{
	int W;
	int A;
	int S;
	int D;
}	t_keys;

typedef struct s_map_infos
{
	int			height;
	int			width;
	int			x;
	int			y;
}				t_map_infos;

typedef struct s_ray_infos
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_ray_infos;

typedef struct s_global_infos
{
	double		px;
	double		py;
	void		*mlx;
	void		*mlx_win;
	int			**map;
	double		p_angle;
	double		ray_angle;
	t_ray_infos	*ray_infos;
	t_map_infos	*map_infos;
	t_keys		*keys;
}				t_global_infos;

#endif