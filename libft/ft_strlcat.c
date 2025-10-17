/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:45:52 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/06 14:22:48 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;

	len_dest = ft_strlen(dst);
	i = 0;
	if (size <= len_dest)
	{
		return (ft_strlen(src) + size);
	}
	if (size > 0)
	{
		while (src && src[i] && i < size - 1 - len_dest)
		{
			dst[len_dest + i] = src[i];
			i++;
		}
		dst[len_dest + i] = '\0';
	}
	return (ft_strlen(src) + len_dest);
}

void	ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len_dest;

	len_dest = ft_strlen(dst);
	i = 0;
	while (src[i] && i < n)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
}
/*
int	main(void)
{
	char dest[40] = "truc";
	char dests[40] = "truc";
	char src[] = "lorem ipsum dolor sit amet";
	char srcs[] = "lorem ipsum dolor sit amet";

	//dest[8] = 'a';
	//dests[8] = 'a';
	size_t size = 13;
	printf("dest : %s \nand the length : %zu\n\n", dest, strlcat(dest, src,
			size));
	printf("dest : %s \nand the length : %zu\n\n", dests, ft_strlcat(dests,
			srcs, size));
} */