/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:23:08 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/29 02:12:30 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cc;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	cc = malloc(s_len + 1);
	if (cc == NULL)
		return (0);
	while (i < s_len)
	{
		cc[i] = s[i];
		i++;
	}
	cc[i] = '\0';
	return (cc);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*result;
	size_t	i;

	if (!str)
		return (NULL);
	if (n > ft_strlen(str))
		n = ft_strlen(str);
	result = malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	// char str[] = "lorem ipsum dolor sit amet";
	char *str = NULL;
	char *strccpy;
	//char *strccpy2;

	strccpy = strdup(str);
	//strccpy2 = ft_strdup(str);
	// printf("strdup : \noriginal : %s \ncopy     : %s", str, strccpy);
	// printf("\n\nft_strdup : \noriginal : %s \ncopy     : %s", str, strccpy2);
} */