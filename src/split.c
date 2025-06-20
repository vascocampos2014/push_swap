/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:17:52 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/19 14:18:17 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(const char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	inside_word = false;
	while (*s)
	{
		if (*s != c && !inside_word)
		{
			inside_word = true;
			count++;
		}
		else if (*s == c)
			inside_word = false;
		s++;
	}
	return (count);
}

static char	*get_next_word(const char *s, char c, int *cursor)
{
	int		len;
	int		i;
	char	*next_word;

	len = 0;
	i = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	while (s[*cursor + len] && s[*cursor + len] != c)
		len++;
	next_word = malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while (s[*cursor] && s[*cursor] != c)
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(const char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;
	int		cursor;

	words_count = count_words(s, c);
	result_array = malloc(sizeof(char *) * (words_count + 1));
	if (!result_array)
		return (NULL);
	i = 0;
	cursor = 0;
	while (i < words_count)
	{
		result_array[i] = get_next_word(s, c, &cursor);
		if (!result_array[i])
		{
			while (i > 0)
				free(result_array[--i]);
			free(result_array);
			return (NULL);
		}
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}

void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}
