/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:30:12 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/01 10:26:07 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim(char const s1, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (s1 == set[i])
			return (1);
	return (0);
}

static int	is_only_set(const char *s1, const char *set)
{
	if (ft_strlen(s1) > 2)
		return (0);
	if (ft_trim(s1[0], set) && ft_trim(s1[1], set))
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	if (is_only_set(s1, set))
		return (ft_strdup(""));
	if (s1 == NULL || set == NULL || (s1 && !s1[0]))
		return (0);
	while (s1[i] && ft_trim(s1[i], set) == 1)
		i++;
	j = ft_strlen(s1) - 1;
	while (s1[j] && ft_trim(s1[j], set) == 1)
		j--;
	res = ft_substr(&s1[i], 0, j + 1 - i);
	if (!res)
		return (NULL);
	return (res);
}
/*
int	main(void)
{
	char const	*str;
	char const	*set;
	char		*dst;

	str = "aaaaaaaaa\naaa  aaHello Please Trim me !aaa a a a ";
	set = "a\n";
	dst = ft_strtrim(str, set);
	printf("t%st\n", dst);
	free(dst);
} */