/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:08:12 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/23 14:12:45 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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
}						t_global_infos;

#endif