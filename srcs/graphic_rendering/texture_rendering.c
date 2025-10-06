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

	position = (infos->tex_x * img->line_length) + (infos->tex_y
			* (img->bits_per_pixel / 8));
	color = *(int *)(infos->textures->north_data + position);
	my_mlx_pixel_put(img, i, y, color);
}
