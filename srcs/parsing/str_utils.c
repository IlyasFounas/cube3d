/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:50:13 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/22 17:52:06 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_cub_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}

int	ft_line_len(char *line)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			size += 3;
		size++;
		i++;
	}
	return (size);
}

int	ft_strlen_trim(const char *tab)
{
	int	i;
	int	len;

	len = ft_strlen(tab);
	i = 0;
	while (i < len && is_space(tab[i]))
		i++;
	while (len > i && is_space(tab[len - 1]))
		len--;
	return (len - i);
}

int	dbl_char_len(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

void	free_dbl_char(char **tab, int start, int end, bool free_all)
{
	int	i;

	if (!tab)
		return ;
	i = start;
	while (i < end)
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	if (free_all)
	{
		free(tab);
		tab = NULL;
	}
}
