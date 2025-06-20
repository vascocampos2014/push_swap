/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:31:18 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/22 15:31:35 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	copy_and_join(char *res, char *s1, char *s2, int len1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	if (len1 > 0)
		res[i++] = ' ';
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
}

static char	*strjoin_custom(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;

	len1 = 0;
	len2 = 0;
	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;
	res = malloc(len1 + len2 + 2);
	if (!res)
		return (NULL);
	copy_and_join(res, s1, s2, len1);
	free(s1);
	return (res);
}

static void	exit_on_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	parse_args(int *argc, char ***argv, bool *allocated)
{
	char	*joined;
	int		i;

	joined = NULL;
	i = 1;
	while (i < *argc)
	{
		joined = strjoin_custom(joined, (*argv)[i]);
		if (!joined)
			exit_on_error();
		i++;
	}
	*argv = split(joined, ' ');
	free(joined);
	if (!*argv)
		exit_on_error();
	*argc = 0;
	while ((*argv)[*argc])
		(*argc)++;
	*allocated = true;
}
