/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:20:49 by vaires-m          #+#    #+#             */
/*   Updated: 2024/04/22 12:20:49 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

/*
}
void test_ft_putnbr_fd() {
    int fd;
    char *filename = "test_numbers.txt";

    // Open a file for writing
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    // Test different numbers
    ft_putnbr_fd(123, fd);
    ft_putchar_fd('\n', fd); // Newline for readability
    ft_putnbr_fd(-456, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(2147483647, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-2147483648, fd);
    ft_putchar_fd('\n', fd);

    // Close the file descriptor
    close(fd);

    // Output to console that the test is complete
    printf("Test completed. Check '%s' for the output.\n", filename);
}

int main() {
    test_ft_putnbr_fd();
    return 0;
}
*/