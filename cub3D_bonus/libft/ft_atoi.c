/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:48:45 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/01 15:48:57 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *nptr)
{
	int			i;
	int			neg;
	long int	nb;

	nb = 0;
	neg = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nb > ((LONG_MAX - (nptr[i] - 48)) / 10))
			return (-1);
		if (-nb < ((LONG_MIN + (nptr[i] - 48)) / 10))
			return (0);
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	return (nb * neg);
}
