#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "libft.h"
#include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// utils.c
void display_error(void);
void free_map(int **map);
int **hard_coded_2dmap(void);

// window.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void create_window();

#endif