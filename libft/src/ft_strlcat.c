/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:33:25 by vaires-m          #+#    #+#             */
/*   Updated: 2024/05/13 13:56:30 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	src_length = 0;
	while (src[src_length])
		src_length++;
	dest_length = 0;
	while (dst[dest_length] && dest_length < size)
		dest_length++;
	j = dest_length;
	i = 0;
	if (dest_length < size - 1 && size > 0)
	{
		while (src[i] && dest_length + i < size - 1)
		{
			dst[j++] = src[i++];
		}
		dst[j] = '\0';
	}
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}

/*
int main()
{
    char *s = "hello duplicates";
    char target[128] = "target buffersdss#";
    int c;

    printf("Hello World: \"%s\"\n", target);
    c = ft_strlcat(target, s, 24);
    printf("New target: \"%s\"\n", target);
    return 0; 
}
*/