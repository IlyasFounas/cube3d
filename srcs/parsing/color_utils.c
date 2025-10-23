/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:45:30 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/22 16:46:24 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_null_color(t_color color)
{
	return (color.r == -1 && color.g == -1 && color.b == -1);
}

bool	is_color(char *str)
{
	int	i;
	int	colors;

	i = 0;
	colors = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == 'F' || str[i] == 'C')
	{
		i++;
		if (!is_space(str[i]))
			return (false);
		while (str[i] && is_space(str[i]))
			i++;
		while (str[i] && (ft_isdigit(str[i]) || str[i] == ',') && colors < 2)
		{
			if (str[i] == ',')
				colors++;
			i++;
		}
		if (str[i] && !ft_isdigit(str[i]))
			return (false);
		return (colors == 2);
	}
	return (false);
}

bool	is_good_color(t_color color)
{
	return (color.r > 255 || color.g > 255 || color.b > 255 || color.r < 0
		|| color.g < 0 || color.b < 0);
}
