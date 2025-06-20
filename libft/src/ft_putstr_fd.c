/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:21:04 by vaires-m          #+#    #+#             */
/*   Updated: 2024/04/22 12:21:04 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		i++;
	}
	write(fd, s, i);
}

/*
// Test function to demonstrate and verify functionality
void test_ft_putstr_fd() {
    int fd;
    char *filename = "test_output.txt";
    char *test_string = "Testing ft_putstr_fd function!";
    char buffer[256];  // Buffer for reading back the file contents

    // Open a file for writing 
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    // Use ft_putstr_fd to write the test string to the file
    ft_putstr_fd(test_string, fd);

    // Close the file after writing
    close(fd);

    // Open the file again, this time for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        return;
    }

    // Read the contents of the file to verify
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        return;
    }

    buffer[bytes_read] = '\0';  // Null-terminate the read data

    // Close the file
    close(fd);

    // Output the results
    printf("Written to file: '%s'\n", test_string);
    printf("Read from file: '%s'\n", buffer);
}

int main() {
    test_ft_putstr_fd();
    return 0;
}
*/