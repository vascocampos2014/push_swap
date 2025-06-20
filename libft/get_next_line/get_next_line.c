/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:32:23 by vaires-m          #+#    #+#             */
/*   Updated: 2024/09/17 11:32:23 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			count;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	while (ft_newline(line) == -1)
	{
		if (buf[0] == '\0')
		{
			count = read(fd, buf, BUFFER_SIZE);
			if (count <= 0)
			{
				if (count == 0)
					return (line);
				free(line);
				return (NULL);
			}
			buf[count] = '\0';
		}
		line = gnl_strjoin(line, buf);
		ft_polish (line, buf);
	}
	return (line);
}

/*int	main ()
{
	int	fd;
	char *line;
	int	line_count = 0;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	if (fd < 0)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}

	// Read lines until NULL is returned (end of file or error)
	while ((line = get_next_line(fd)) != NULL)
	{
		// Output the line with a counter
		printf("Line %d; %s\n", ++line_count, line);
		free(line); // Free the line once is used
	}

	// Close the file descriptor
	close(fd);
	return (EXIT_SUCCESS);
}*/