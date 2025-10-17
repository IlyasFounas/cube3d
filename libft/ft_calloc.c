/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:32:52 by ifounas           #+#    #+#             */
/*   Updated: 2025/04/27 23:50:41 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size == 0 || nmemb == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (nmemb > SIZE_MAX / size || size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (ft_calloc(1, new_size));
	new_ptr = ft_calloc(1, new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (old_size < new_size)
		ft_memcpy(new_ptr, ptr, old_size);
	else
		ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

/*
int	main(void)
{
	size_t n;
	size_t i;
	size_t *ptr;
	size_t *ptr2;

	n = 10;
	i = 0;
	ptr = calloc(n, sizeof(size_t));
	ptr2 = ft_calloc(n, sizeof(size_t));
	if (ptr == NULL)
		exit(0);
	if (ptr2 == NULL)
		exit(0);
	printf("calloc | ft_calloc\n");
	while (++i < n)
	{
		printf("   %zu   ", ptr[i]);
		printf("|     %zu\n", ptr2[i]);
	}
	free(ptr);
	free(ptr2);
} */