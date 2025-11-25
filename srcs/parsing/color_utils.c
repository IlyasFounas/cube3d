/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:45:30 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/25 12:22:21 by aboumall         ###   ########.fr       */
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
	return (len);
}

static bool	check_digits(char *str, int *i)
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
	if (digits > 3)
		return (false);
	return (true);
}

bool	is_rgb_format(char *str)
{
	int	i;
	int	commas;
	int	end;

	i = 0;
	commas = 0;
	end = full_size(str) - 1;
	while (str[i] && i < end - 2)
	{
		if (!check_digits(str, &i))
			return (false);
		if (str[i] && str[i] != ',')
			return (false);
		else
			commas++;
		if (commas > 2)
			return (false);
		i++;
		if (str[i] == ',')
			return (false);
	}
	return (true);
}

bool	is_color(char *str)
{
	int	i;

	i = 0;
	i++;
	if (!is_space(str[i]))
		return (false);
	while (str[i] && is_space(str[i]))
		i++;
	if (!is_rgb_format(str + i))
		return (false);
	return (true);
}

bool	is_good_color(t_color color)
{
	return (color.r > 255 || color.g > 255 || color.b > 255 || color.r < 0
		|| color.g < 0 || color.b < 0);
}
