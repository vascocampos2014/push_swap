/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:11:34 by vaires-m          #+#    #+#             */
/*   Updated: 2024/09/23 12:46:31 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		i;
	long	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (nptr[i] != '\0' && ((nptr[i] >= 9 && nptr[i] <= 13)
			|| nptr[i] == 32))
		i++;
	if (nptr[i] != '\0' && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
	}
	nbr *= sign;
	return (nbr);
}

/*
int main()
{
    char nbr[] = "    +223231ds2";
    printf("%d\n", ft_atoi(nbr));
}
*/