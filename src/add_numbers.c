/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:22:06 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/19 14:40:02 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	insert_back(t_pile **root, t_pile *new)
{
	t_pile	*last;

	last = (*root)->prev;
	new->next = *root;
	new->prev = last;
	last->next = new;
	(*root)->prev = new;
}

void	add_number(t_pile **root, int nbr)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return ;
	new->content = nbr;
	new->index = 0;
	new->target_node = NULL;
	new->above_median = false;
	new->push_cost = 0;
	new->cheapest = false;
	if (*root == NULL)
	{
		new->prev = new;
		new->next = new;
		*root = new;
	}
	else
		insert_back(root, new);
}

void	free_pile(t_pile **pile)
{
	t_pile	*current;
	t_pile	*next;
	int		len;

	if (!*pile)
		return ;
	len = list_len(*pile);
	current = *pile;
	while (len)
	{
		next = current->next;
		free(current);
		current = next;
		len--;
	}
	*pile = NULL;
}
