/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:20:39 by ifounas           #+#    #+#             */
/*   Updated: 2025/05/16 14:47:17 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0 && s1)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	if (n <= 0 || !s1 || !s2)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && i < n - 1 && s1[i]
		&& s2[i])
		i++;
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char c[] = "test\200";
	char cc[] = "test\0";

	printf("%d\n", strncmp(c, cc, 6));
	printf("%d", ft_strncmp(c, cc, 6));
} */