/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:01:30 by ifounas           #+#    #+#             */
/*   Updated: 2025/09/24 12:01:30 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	**hard_coded_2dmap(void)
{
	int **res;

	res = malloc(8 * sizeof(int *));
	for (int i = 0; i < 8; i++)
	{
		res[i] = malloc(8 * sizeof(int));
		for (int j = 0; j < 8; j++)
		{
			res[i][j] = 0;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		res[0][i] = 1;
		res[7][i] = 1;
		res[i][0] = 1;
		res[i][7] = 1;
	}
	res[1][2] = 1;
	res[4][2] = 1;
	res[4][1] = 1;
	return (res);
}
