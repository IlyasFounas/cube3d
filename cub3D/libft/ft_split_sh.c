/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:02:34 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/27 14:38:41 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_se(char c, char *se)
{
	int	i;

	i = 0;
	while (se[i])
	{
		if (c == se[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *s, char *se)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (i == 0 && !is_se(s[i], se))
			word++;
		if (is_se(s[i], se) && s[i + 1] && !is_se(s[i + 1], se))
			word++;
		i++;
	}
	return (word);
}

void	free_all(char **split, int i)
{
	while (i >= 0)
		free(split[i]);
	free(split);
}

char	*get_word(char *s, char *se)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len] && !is_se(s[len], se))
		len++;
	word = ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	while (*s && !is_se(*s, se))
	{
		word[i] = *s;
		i++;
		s++;
	}
	return (word);
}

char	**ft_split_sh(char *s, char *se)
{
	char	**split;
	int		i;
	int		j;

	split = ft_calloc(count_word(s, se) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_se(s[i], se))
			i++;
		if (s[i])
		{
			split[j] = get_word(s + i, se);
			if (!split[j])
				return (free_all(split, j), NULL);
			j++;
			while (s[i] && !is_se(s[i], se))
				i++;
		}
	}
	return (split);
}
