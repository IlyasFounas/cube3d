/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 04:32:19 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/28 17:12:41 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_xpm_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (ft_strncmp(filename + len - 4, ".xpm", 4) == 0);
}

bool	safe_open(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		printf("Error\nCub3d: cannot open file `%s'\n", filename);
		return (false);
	}
	return (true);
}

void	init_fd(t_map_infos *map, t_fd *fd, char *name, int fd_i)
{
	if (!name)
		fd->name = NULL;
	else
	{
		fd->name = ft_strdup(name);
		if (!fd->name)
		{
			if (name)
			{
				free(name);
				name = NULL;
			}
		}
		exit_if(!fd->name, map, MSG_ERR_ML_ER, EXIT_FAILURE);
	}
	fd->fd = fd_i;
}
