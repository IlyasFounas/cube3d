/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:06:05 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/30 11:33:11 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strrchr_g(const char *s, int c)
{
	int	i;
	int	mark;

	i = 0;
	mark = 0;
	c = (char)c;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			mark = i;
		i++;
	}
	if (s[i] == c && s[i] == '\0')
		return (0);
	else if (mark > 0 || s[mark] == c)
		return (1);
	return (0);
}

static char	*ft_get_rest(char *buf)
{
	char	*res;

	if (buf && buf[0] == '\0')
		return (NULL);
	res = ft_substr_g(buf, ft_strlen_g(buf, '\n'), ft_strlen_g(buf
				+ ft_strlen_g(buf, '\n'), 0));
	return (res);
}

static char	*ft_readline(int fd, char *buf)
{
	ssize_t	read_c;
	char	*line;

	read_c = -1;
	line = NULL;
	if (buf && buf[0] != '\0')
		line = ft_strjoin_g(line, buf);
	if (ft_strrchr_g(line, '\n') == 1 || (buf && buf[0] != '\0' && !line))
		return (line);
	while (read_c != 0)
	{
		read_c = read(fd, buf, BUFFER_SIZE);
		if (read_c < 0)
			return (free(line), NULL);
		if (read_c == 0)
			return (line);
		buf[read_c] = '\0';
		line = ft_strjoin_g(line, buf);
		if (!line)
			return (free(line), NULL);
		if ((line && ft_strrchr_g(line, '\n') == 1))
			break ;
	}
	return (line);
}

static void	ft_concat_buffer(char *buf, char *res)
{
	int	i;

	i = 0;
	while (res[i] != '\0')
	{
		buf[i] = res[i];
		i++;
	}
	buf[i] = '\0';
	free(res);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	buf[BUFFER_SIZE + 1] = "";
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_readline(fd, buf);
	res = ft_get_rest(buf);
	if (res)
		ft_concat_buffer(buf, res);
	else
		return (free(line), free(res), NULL);
	return (line);
}
