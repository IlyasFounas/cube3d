/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:45:30 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/26 16:22:18 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_null_color(t_color color)
{
	return (color.r == -1 && color.g == -1 && color.b == -1);
}

static int	full_size(char *rgb)
{
	int	len;

	len = ft_strlen(rgb) - 1;
	while (len > 0 && is_space(rgb[len]))
		len--;
	return (len + 1);
}

static bool	check_digits(char *str, int *i, int *rgb)
{
	int	digits;

	digits = 0;
	if (!ft_isdigit(str[(*i)]))
		return (false);
	while (str[(*i)] && ft_isdigit(str[(*i)]))
	{
		digits++;
		(*i)++;
	}
	if (digits > 3 || digits == 0)
		return (false);
	(*rgb)++;
	return (true);
}

bool	is_rgb_format(char *str)
{
	int	i;
	int	rgb;
	int	commas;
	int	end;

	i = 0;
	commas = 0;
	rgb = 0;
	end = full_size(str) - 1;
	while (str[i] && i < end)
	{
		if (!check_digits(str, &i, &rgb))
			return (false);
		if (str[i] && str[i] != ',' && commas < 2)
			return (false);
		else if (str[i] == ',')
			commas++;
		if (commas > 2)
			return (false);
		i++;
		if (str[i] == ',')
			return (false);
	}
	return (rgb == 3);
}

bool	is_good_color(t_color color)
{
	return (color.r > 255 || color.g > 255 || color.b > 255 || color.r < 0
		|| color.g < 0 || color.b < 0);
}
