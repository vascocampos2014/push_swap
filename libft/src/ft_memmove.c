/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:10:58 by vaires-m          #+#    #+#             */
/*   Updated: 2024/05/08 13:10:06 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src;

	dst = (unsigned char *)str1;
	src = (const unsigned char *)str2;
	if (dst == src)
	{
		return (dst);
	}
	if (dst < src)
	{
		while (n--)
			*dst++ = *src++;
	}
	else
	{
		dst += n;
		src += n;
		while (n--)
			*--dst = *--src;
	}
	return ((char *)str1);
}

/*
int main()
{
    char dest[24];
    char src[] = "lorem ipsum dolor sit a";
    printf("%s\n",ft_memmove(dest, src, 24));
} 
*/