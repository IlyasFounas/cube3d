/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:02:47 by ifounas           #+#    #+#             */
/*   Updated: 2025/10/15 16:28:27 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_global_info(t_global_infos *infos)
{
	if (infos->map_infos)
	{
		free(infos->map_infos);
		infos->map_infos = NULL;
	}
	if (infos->ray_infos)
	{
		free(infos->ray_infos);
		infos->ray_infos = NULL;
	}
	if (infos->keys)
	{
		free(infos->keys);
		infos->keys = NULL;
	}
}

void	free_textures(t_global_infos *infos, t_textures *textures)
{
	t_textures	*ptr;
	t_textures	*next;

	if (!textures)
		return ;
	ptr = textures;
	while (ptr)
	{
		next = ptr->next;
		if (ptr && ptr->data.img)
			mlx_destroy_image(infos->mlx, ptr->data.img);
		free(ptr);
		ptr = next;
	}
}

void	free_mlx(t_global_infos *infos)
{
	if (infos->mlx_win && infos->mlx)
		mlx_destroy_window(infos->mlx, infos->mlx_win);
	if (infos->mlx)
	{
		if (infos->img.img)
			mlx_destroy_image(infos->mlx, infos->img.img);
		mlx_destroy_display(infos->mlx);
		free(infos->mlx);
	}
}

void	free_rendering(t_global_infos *infos)
{
	int	i;

	i = -1;
	if (infos->map)
	{
		while (++i < infos->map_infos->x)
			free(infos->map[i]);
		free(infos->map);
		infos->map = NULL;
	}
	free_global_info(infos);
	free_textures(infos, infos->textures);
	free_mlx(infos);
}
