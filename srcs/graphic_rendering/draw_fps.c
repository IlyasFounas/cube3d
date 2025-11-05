/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:24:10 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/05 17:00:21 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	font_crashed(t_global_infos *infos)
{
	int	i;

	i = 0;
	while (i < 14)
	{
		if (!infos->font.img[i])
		{
			printf("Warning\nCan't open font for fps display\n");
			return (true);
		}
		i++;
	}
	return (false);
}

void	free_fonts(t_global_infos *infos)
{
	int	i;

	i = 0;
	while (i < 14)
	{
		if (infos->font.img[i])
			mlx_destroy_image(infos->mlx, infos->font.img[i]);
		i++;
	}
}

void	load_fonts(t_global_infos *infos)
{
	int	w;
	int	h;

	infos->font.img[0] = mlx_xpm_file_to_image(infos->mlx, FNT_0_XPM, &w, &h);
	infos->font.img[1] = mlx_xpm_file_to_image(infos->mlx, FNT_1_XPM, &w, &h);
	infos->font.img[2] = mlx_xpm_file_to_image(infos->mlx, FNT_2_XPM, &w, &h);
	infos->font.img[3] = mlx_xpm_file_to_image(infos->mlx, FNT_3_XPM, &w, &h);
	infos->font.img[4] = mlx_xpm_file_to_image(infos->mlx, FNT_4_XPM, &w, &h);
	infos->font.img[5] = mlx_xpm_file_to_image(infos->mlx, FNT_5_XPM, &w, &h);
	infos->font.img[6] = mlx_xpm_file_to_image(infos->mlx, FNT_6_XPM, &w, &h);
	infos->font.img[7] = mlx_xpm_file_to_image(infos->mlx, FNT_7_XPM, &w, &h);
	infos->font.img[8] = mlx_xpm_file_to_image(infos->mlx, FNT_8_XPM, &w, &h);
	infos->font.img[9] = mlx_xpm_file_to_image(infos->mlx, FNT_9_XPM, &w, &h);
	infos->font.img[10] = mlx_xpm_file_to_image(infos->mlx, FNT_F_XPM, &w, &h);
	infos->font.img[11] = mlx_xpm_file_to_image(infos->mlx, FNT_P_XPM, &w, &h);
	infos->font.img[12] = mlx_xpm_file_to_image(infos->mlx, FNT_S_XPM, &w, &h);
	infos->font.img[13] = mlx_xpm_file_to_image(infos->mlx, FNT_CLN_XPM, &w,
			&h);
	if (font_crashed(infos))
		infos->font_crashed = true;
	infos->font.width = w;
	infos->font.height = h;
}

static void	draw_fps_txt(t_global_infos *infos, int *x)
{
	int		y;
	void	*img;

	y = 10;
	img = infos->font.img[10];
	mlx_put_image_to_window(infos->mlx, infos->mlx_win, img, (*x), y);
	(*x) += infos->font.width;
	img = infos->font.img[11];
	mlx_put_image_to_window(infos->mlx, infos->mlx_win, img, (*x), y);
	(*x) += infos->font.width;
	img = infos->font.img[12];
	mlx_put_image_to_window(infos->mlx, infos->mlx_win, img, (*x), y);
	(*x) += infos->font.width;
	img = infos->font.img[13];
	mlx_put_image_to_window(infos->mlx, infos->mlx_win, img, (*x), y);
	(*x) += infos->font.width;
}

void	draw_fps(t_global_infos *infos)
{
	int		i;
	int		x;
	int		y;
	void	*img;

	i = 0;
	x = 10;
	y = 10;
	if (!infos->char_fps)
		return ;
	draw_fps_txt(infos, &x);
	while (infos->char_fps[i])
	{
		img = NULL;
		if (infos->char_fps[i] - '0' > 0 && infos->char_fps[i] - '0' < 9)
			img = infos->font.img[infos->char_fps[i] - '0'];
		if (img)
		{
			mlx_put_image_to_window(infos->mlx, infos->mlx_win, img, x, y);
			x += infos->font.width;
		}
		else
			x += infos->font.width / 2;
		i++;
	}
}
