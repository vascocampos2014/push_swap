/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:07:44 by vaires-m          #+#    #+#             */
/*   Updated: 2024/09/09 13:07:44 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_nbr_len(long int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr == -9223372036854775807L - 1)
		return (20);
	if (nbr == -2147483648)
	{
		len = 11;
		return (len);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long int nbr)
{
	int	len;

	len = ft_nbr_len(nbr);
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		ft_putnbr(nbr);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + 48);
	return (len);
}

int	ft_putunsigned(unsigned int nbr)
{
	int	len;

	len = ft_nbr_len(nbr);
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + 48);
	return (len);
}

/*
int main ()
{
    unsigned int n = 213212442;
    int len = ft_nbr_len(n);
    ft_putunsigned(n);
    printf("\n%d\n", len);
}
*/