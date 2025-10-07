#include "cube3d.h"

void	parse_infos(void)
{
}

/**
 * The goal is to take the right color for each pixels.
 */
void	wall_rendering(t_global_infos *infos, t_data *img, int i, int y)
{
	int	position;
	int	color;
	t_data *img_texture;

	img_texture = &infos->textures->n_t_data;
	position = (infos->tex_y * img_texture->line_length) + (infos->tex_x
			* (img_texture->bits_per_pixel / 8));
	color = *(int *)(img_texture->addr + position);
	my_mlx_pixel_put(img, i, y, color);
}
