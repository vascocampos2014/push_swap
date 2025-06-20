/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:49:04 by vaires-m          #+#    #+#             */
/*   Updated: 2024/06/20 13:06:55 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	strlen;
	char	*str;

	i = 0;
	strlen = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strrchr(set, s1[j - 1]) != NULL)
		j--;
	str = malloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[strlen] = s1[i];
		strlen++;
		i++;
	}
	str[strlen] = '\0';
	return (str);
}

/*
int main()
{
    char str[] = "ola o meu nome";
    char set[] = "o ";
    char *dup = ft_strtrim(str,set);
    printf("%s\n", dup);
}
*/