/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:53:47 by vaires-m          #+#    #+#             */
/*   Updated: 2024/05/13 13:16:57 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*a;

	i = 0;
	a = malloc(nmemb * size);
	if (a == NULL)
	{
		return (NULL);
	}
	while (i < (nmemb * size))
	{
		a[i] = '\0';
		i++;
	}
	return ((void *)a);
}

/*
int main()
{
    // Test ft_calloc with an array of integers
    int *intArray = (int *)ft_calloc(5, sizeof(int));
    if (intArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return an error code indicating failure
    }
    
    // Initialize the allocated memory with some values
    for (int i = 0; i < 5; i++) {
        intArray[i] = i + 1;
    }
    
    // Print the values of the allocated memory
    printf("Values of intArray: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");
    
    // Free the allocated memory
    free(intArray);
    
    // Test ft_calloc with an array of characters
    char *charArray = (char *)ft_calloc(8, sizeof(char));
    if (charArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return an error code indicating failure
    }
    
    // Initialize the allocated memory with a string
    strcpy(charArray, "Hello!");
    
    // Print the string stored in the allocated memory
    printf("String in charArray: %s\n", charArray);
    
    // Free the allocated memory
    free(charArray);
    
    return 0;
}
*/