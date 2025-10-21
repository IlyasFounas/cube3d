/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 04:32:19 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/21 13:09:39 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_dbl_char(char **tab, int start, int end)
{
	int	i;

	if (!tab)
		return ;
	i = start;
	while (i < end)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
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

bool	safe_open(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		printf("Cub3d: cannot open file `%s'\n", filename);
		return (false);
	}
	return (true);
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
		exit_if(!fd->name, map, "Cub3d: malloc error", EXIT_FAILURE);
	}
	fd->fd = fd_i;
}

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
