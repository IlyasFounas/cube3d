#include "cube3d.h"

int	darken_color(int color, float factor)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) * factor;
	g = ((color >> 8) & 0xFF) * factor;
	b = (color & 0xFF) * factor;
	return ((r << 16) | (g << 8) | b);
}

int	return_ult_darken_color(t_global_infos *infos, int color, int y, int end_wall)
{
	float	factor;

	if (infos->fog_ratio > 2 && (y < end_wall + 50 || end_wall == 0))
	{
		factor = 1.0f - (infos->fog_ratio * 0.2f);
		if (factor < 0.0f)
			factor = 0.0f;
		color = darken_color(color, factor);
	}
	return (color);
}

/**
 * The goal is to take the right color for each pixels.
 */
void	wall_rendering_bonus(t_global_infos *infos, t_data *img, int i, int y)
{
	int			position;
	int			color;
	t_data		*img_texture;
	t_textures	*ptr;

	ptr = infos->textures;
	while (ptr && ptr->type != infos->actual_orientation)
		ptr = ptr->next;
	img_texture = &ptr->data;
	position = (infos->tex_y * img_texture->line_length) + (infos->tex_x
			* (img_texture->bits_per_pixel * 0.125));
	color = *(int *)(img_texture->addr + position);
	my_mlx_pixel_put(img, i, y, return_ult_darken_color(infos, color, y, 0));
}

void	draw_wall_bonus(t_global_infos *infos, t_data *img, int i, int y)
{
	infos->tex_y = (int)infos->tex_pos % infos->textures->t_height;
	infos->tex_pos += infos->tex_step;
	wall_rendering_bonus(infos, img, i, y);
}

void	graphic_rendering_bonus(double distance, t_data *img, int i,
		t_global_infos *infos)
{
	int	wall_height;
	int	start_y;
	int	end_y;
	int	y;

	y = 0;
	wall_height = (int)(infos->map_infos->height / distance);
	start_y = (infos->map_infos->height - wall_height) * 0.5;
	if (start_y < 0)
		start_y = 0;
	end_y = start_y + wall_height;
	infos->tex_step = (double)infos->textures->t_height / wall_height;
	infos->tex_pos = (start_y - infos->map_infos->height * 0.5 + wall_height
			* 0.5) * infos->tex_step;
	infos->fog_ratio = distance;
	while (y < infos->map_infos->height)
	{
		if (y < start_y)
			my_mlx_pixel_put(img, i, y, return_ult_darken_color(infos, 0x00666666, y, end_y));
		else if (y >= start_y && y < end_y)
			draw_wall_bonus(infos, img, i, y);
		else
			my_mlx_pixel_put(img, i, y, return_ult_darken_color(infos,
					0x042f09, y, end_y));
		y++;
	}
}
