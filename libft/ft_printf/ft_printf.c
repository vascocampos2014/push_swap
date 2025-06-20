/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:07:49 by vaires-m          #+#    #+#             */
/*   Updated: 2024/10/29 13:43:01 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	check_letter(va_list args, const char letter)
{
	int	len;

	len = 0;
	if (letter == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (letter == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (letter == 'p')
		len += ft_print_ptr(va_arg(args, uintptr_t));
	else if (letter == 'd' || letter == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (letter == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (letter == 'x' || letter == 'X')
		len += ft_printhex(va_arg(args, unsigned int), letter);
	else if (letter == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	va_start(args, placeholders);
	len = 0;
	i = 0;
	while (placeholders[i] != '\0')
	{
		if (placeholders[i] == '%')
		{
			i++;
			len += check_letter(args, placeholders[i]);
		}
		else
			len += ft_putchar(placeholders[i]);
		i++;
	}
	va_end(args);
	return (len);
}
