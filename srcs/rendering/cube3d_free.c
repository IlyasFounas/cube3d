/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:02:47 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/24 12:02:58 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	display_error(void)
{
	write(2, "malloc error\n", ft_strlen("malloc error\n"));
	exit(1);
}

void	free_map(int **map)
{
	int i;

	i = -1;
	while (++i < 4)
		free(map[i]);
	free(map);
}
