/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:12:10 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/26 16:45:56 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	exit_if(bool cnd, t_map_infos *map, char *msg, int code)
{
	if (cnd == true)
	{
		free_map(map);
		if (msg)
			printf("%s\n", msg);
		exit(code);
	}
}

bool	error_text(char *err)
{
	printf("%s", err);
	return (false);
}

void	free_fd(t_fd *fd)
{
	if (fd->name)
		free(fd->name);
	fd->name = NULL;
	if (fd->fd >= 0)
		close(fd->fd);
	fd->fd = -1;
}

bool	check_wrong_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ','
			&& !is_space(str[i]))
			return (false);
		i++;
	}
	return (true);
}
