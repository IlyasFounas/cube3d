/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:43:12 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/04 16:17:38 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlcpy_g(char *dst, const char *src, size_t size);
size_t	ft_strlen_g(char const *s, int c);
char	*ft_strjoin_g(char *s1, char const *s2);
size_t	ft_strlcat_g(char *dst, const char *src, size_t size);
char	*ft_substr_g(char *s, unsigned int start, size_t len);

#endif
