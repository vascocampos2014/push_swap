/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:32:42 by vaires-m          #+#    #+#             */
/*   Updated: 2024/10/16 22:21:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	while (ft_newline(line) == -1)
	{
		if (buf[fd][0] == '\0')
		{
			count = read(fd, buf[fd], BUFFER_SIZE);
			if (count <= 0)
			{
				if (count == 0)
					return (line);
				free(line);
				return (NULL);
			}
			buf[fd][count] = '\0';
		}
		line = gnl_strjoin(line, buf[fd]);
		ft_polish (line, buf[fd]);
	}
	return (line);
}

/*
int main()
{
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);

	char *line;
	char *line2;
	char *line3;
	char *line4;

	line = get_next_line(0);
	line2 = get_next_line(fd1);
	line3 = get_next_line(fd2);
	line4 = get_next_line(fd3);

	while (line && line2 && line3 && line4)
	{
		printf("file1: %s\n", line);
		printf("file2: %s\n", line2);
		printf("file3: %s\n", line3);
		printf("file4: %s\n", line4);

		free(line);
		free(line2);
		free(line3);
		free(line4);

		line = get_next_line(0);
		line2 = get_next_line(fd1);
		line3 = get_next_line(fd2);
		line4 = get_next_line(fd3);
	}
}
*/