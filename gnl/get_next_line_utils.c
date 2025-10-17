/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:25:28 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/30 11:32:53 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy_g(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (src == NULL)
	{
		dst[0] = '\0';
		return (0);
	}
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlen_g(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != '\0' && s[i] == c)
		i++;
	return (i);
}

size_t	ft_strlcat_g(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;

	len_dest = ft_strlen_g(dst, 0);
	i = 0;
	if (size <= len_dest)
		return (ft_strlen_g((char *)src, 0) + size);
	if (size > 0)
	{
		while (src[i] && i < size - 1 - len_dest && src[i] != '\n')
		{
			dst[len_dest + i] = src[i];
			i++;
		}
		if (src[i] == '\n')
		{
			dst[len_dest + i] = '\n';
			i++;
		}
		dst[len_dest + i] = '\0';
	}
	return (ft_strlen_g((char *)src, 0) + len_dest);
}

char	*ft_strjoin_g(char *s1, char const *s2)
{
	char	*dst;

	if (!s2)
		return (free(s1), NULL);
	dst = malloc((ft_strlen_g(s1, 0) + ft_strlen_g(s2, '\n') + 1)
			* sizeof(char));
	if (!dst)
		return (free(s1), NULL);
	ft_strlcpy_g(dst, s1, ft_strlen_g(s1, 0) + 1);
	ft_strlcat_g(dst, s2, ft_strlen_g(dst, 0) + ft_strlen_g(s2, '\n') + 1);
	return (free(s1), dst);
}

char	*ft_substr_g(char *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen_g(s, 0) && s != NULL)
	{
		dst = malloc(1);
		if (!dst)
			return (dst);
		dst[0] = '\0';
		return (dst);
	}
	if (len >= ft_strlen_g(s + start, 0))
		len = ft_strlen_g(s + start, 0);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy_g(dst, s + start, len + 1);
	return (dst);
}
