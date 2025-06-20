/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:35:36 by vaires-m          #+#    #+#             */
/*   Updated: 2024/04/22 13:35:36 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	str_len(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*alloc(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
	{
		return (NULL);
	}
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*res;
	int		i;

	if (!s || !f)
	{
		return (NULL);
	}
	str = alloc(str_len(s));
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	res = str;
	while (*s)
	{
		*str++ = f(i++, *s++);
	}
	*str = '\0';
	return (res);
}
/*
char capitalize(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

int main()
{
    char str[] = "o432";
    char *dup = ft_strmapi(str, capitalize);
    if(dup)
    {
    printf("%s\n",dup);
    free(dup);
    }
    else
    {
        printf("alloocation failed");
    }
    return(0);
}
*/