#include "cube3d.h"

void	parse_infos(void)
{
}

void	wall_rendering(t_global_infos *infos, t_data *img, int i, int y)
{
	// int		fd;
	// char	*s;

    // (void)i;
    // (void)img;
    // (void)y;
	(void)infos;
	my_mlx_pixel_put(img, i, y, 0x00FF0000);
	// fd = open(infos->textures->north_t, O_RDONLY);
	// if (!fd)
	// 	free_rendering(infos);
	// do
	// {
	// 	s = get_next_line(fd);
	// 	printf("%s\n", s);
	// 	if (s)
	// 		free(s);
	// } while (s);
	// exit(1);
}
