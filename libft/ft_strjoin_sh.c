/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:15:29 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/02 10:54:38 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sh(char *s1, char const *s2, int free_s1)
{
	char	*dst;

	if (!s1)
		return (NULL);
	if (!s2)
	{
		free(s1);
		return (0);
	}
	dst = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!dst)
	{
		free(s1);
		return (0);
	}
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	ft_strlcat(dst, " ", ft_strlen(dst) + 2);
	ft_strlcat(dst, s2, ft_strlen(dst) + ft_strlen(s2) + 1);
	if (free_s1 == 1)
		free(s1);
	return (dst);
}
