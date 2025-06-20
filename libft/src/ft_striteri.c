/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:21:25 by vaires-m          #+#    #+#             */
/*   Updated: 2024/04/22 12:21:25 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void to_uppercase(unsigned int i, char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c -= 32;
    }
}

int main()
{
    char str[] = "ola o meu nome e vasco";
    ft_striteri(str, to_uppercase);
    printf("%s\n", str);
}
*/