/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:05:16 by sgoffaux          #+#    #+#             */
/*   Updated: 2025/10/23 16:57:25 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Source : https://github.com/goffauxs/fdf/tree/main/get_next_line

#include "libft.h"

static char	*ft_malloc_size(char **line, char *buf)
{
	char	*ret;
	int		line_len;
	int		buf_len;

	line_len = 0;
	while (*line && (*line)[line_len] && (*line)[line_len] != '\n')
		line_len++;
	buf_len = 0;
	while (buf[buf_len] && buf[buf_len] != '\n')
		buf_len++;
	ret = (char *)malloc(sizeof(char) * (buf_len + line_len + 1));
	if (!ret)
		return (NULL);
	return (ret);
}

static int	ft_add_to_line(char **line, char *buf)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_malloc_size(line, buf);
	if (!tmp)
		return (-1);
	i = 0;
	j = 0;
	while (*line && (*line)[i] && (*line)[i] != '\n')
		tmp[i++] = (*line)[j++];
	j = 0;
	while (buf[j] && buf[j] != '\n')
		tmp[i++] = buf[j++];
	tmp[i] = buf[j];
	free(*line);
	*line = tmp;
	i = 0;
	while (buf[j])
		buf[i++] = buf[++j];
	buf[i] = '\0';
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	return (i);
}

static int	ft_get_next_line(int fd, char **line)
{
	static char		buf[1024][10 + 1];
	int				ret;
	static int		eof;

	*line = NULL;
	ret = ft_add_to_line(line, buf[fd]);
	while (ret != -1 && (*line)[ret] != '\n')
	{
		ret = read(fd, buf[fd], 10);
		if (ret < 1)
		{
			if (ret < 0 || eof)
			{
				free(*line);
				*line = NULL;
			}
			eof = 1;
			return (ret);
		}
		eof = 0;
		buf[fd][ret] = '\0';
		ret = ft_add_to_line(line, buf[fd]);
	}
	(*line)[ret] = '\0';
	return (1);
}

int	get_next_line(int fd, char **line)
{
	if (fd < 0 || fd > 1024 || !line || 10 < 1)
		return (-1);
	return (ft_get_next_line(fd, line));
}
