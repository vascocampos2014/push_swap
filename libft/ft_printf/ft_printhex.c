/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:07:52 by vaires-m          #+#    #+#             */
/*   Updated: 2024/09/09 13:07:52 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_printhex(unsigned int n, const char letter)
{
	char	buffer[50];
	int		i;
	int		len;
	int		r;

	i = 0;
	len = 0;
	len += ft_hex_len(n);
	if (n == 0)
		ft_putchar('0');
	while (n)
	{
		r = n % 16;
		if (r < 10)
			buffer[i++] = r + '0';
		else if (letter == 'x')
			buffer[i++] = r - 10 + 'a';
		else if (letter == 'X')
			buffer[i++] = r - 10 + 'A';
		n /= 16;
	}
	while (i > 0)
		ft_putchar(buffer[--i]);
	return (len);
}

/*
int main()
{
	unsigned int nbr = 12344532;
	int len = ft_printhex(nbr, 'x');
	//int len = ft_hex_len(12344532);
	printf("\n%x\n", nbr);
	printf("%d\n", len);
	return 0;
}
*/