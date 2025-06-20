/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:07:55 by vaires-m          #+#    #+#             */
/*   Updated: 2024/09/09 13:07:55 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_put_ptr(uintptr_t num)
{
	char	buffer[50];
	int		i;
	int		len;
	int		r;

	i = 0;
	len = 0;
	r = 0;
	if (num == 0)
	{
		len += ft_putchar('0');
		return (len);
	}
	while (num)
	{
		r = num % 16;
		if (r < 10)
			buffer[i++] = r + '0';
		else
			buffer[i++] = r - 10 + 'a';
		num /= 16;
	}
	while (i > 0)
		len += ft_putchar(buffer[--i]);
	return (len);
}

int	ft_print_ptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		len += ft_put_ptr(ptr);
	}
	return (len);
}

/*
int main()
{ 
	int a = 134; 
	void *b = &a;
	ft_pointer(b, 3);
	printf("\n%p\n",b); 
	printf("%X\n",b); 
}
*/