/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:42:03 by vaires-m          #+#    #+#             */
/*   Updated: 2024/04/29 13:29:28 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*
int main() 
{ 
    char *s = "hello duplicates"; 
    char target[128] = "target buffers"; 
    int c;
     
    printf("Hello World: \"%s\"\n", target); 
    c = ft_strlcpy(target, s, 16); 
    printf("New target: \"%s\"\n", target); 
    return 0; 
} 
*/