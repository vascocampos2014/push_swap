/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:32:58 by vaires-m          #+#    #+#             */
/*   Updated: 2024/09/17 11:32:58 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joint;

	joint = (char *)malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (joint == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (i++ < (gnl_strlen(s1) -1))
		joint[i] = s1[i];
	while (j++ < (gnl_strlen(s2) - 1))
	{
		joint[i] = s2[j];
		i++;
	}
	joint[i] = '\0';
	if (s1)
		free (s1);
	return (joint);
}

void	*ft_polish(char *line, char *buf)
{
	int	nl;
	int	i;

	nl = ft_newline(line);
	if (nl != -1)
		line[nl + 1] = '\0';
	i = 0;
	nl = ft_newline(buf);
	if (nl != -1)
	{
		nl++;
		while (buf[nl])
		{
			buf[i++] = buf[nl++];
		}
	}
	while (i < BUFFER_SIZE)
	{
		buf[i++] = '\0';
	}
	return (line);
}

/*
int main()
{
	char str1[10] = "ola";
	char *str2 = "mano";
	ft_strcat(str1, str2);
	printf("%s\n", str1);
}
*/