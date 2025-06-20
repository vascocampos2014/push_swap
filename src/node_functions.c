/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:20:03 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/20 15:20:14 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_pile *pile)
{
	int		median;
	int		i;

	if (!pile)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	median = list_len(pile) / 2;
	i = 0;
	while (list_len(pile) > i)
	{
		if (i > median)
			pile->above_median = true;
		else
			pile->above_median = false;
		pile->index = i;
		pile = pile->next;
		i++;
	}
	return ;
}

int	list_len(t_pile *list)
{
	int		len;
	t_pile	*current;

	if (!list)
		return (0);
	len = 1;
	current = list;
	while (current->next != list)
	{
		current = current->next;
		len++;
	}
	return (len);
}

t_pile	*find_min(t_pile *pile)
{
	t_pile	*min;
	t_pile	*current;

	if (!pile)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	min = pile;
	current = pile->next;
	while (current != pile)
	{
		if (current->content < min->content)
			min = current;
		current = current->next;
	}
	return (min);
}

void	set_cheapest(t_pile *pile)
{
	t_pile	*current;
	t_pile	*cheapest;
	long	push_index;

	cheapest = NULL;
	current = pile;
	push_index = LONG_MAX;
	while (1)
	{
		if (push_index > current->push_cost)
		{
			cheapest = current;
			push_index = current->push_cost;
		}
		if (current->next == pile)
		{
			cheapest->cheapest = true;
			return ;
		}
		current = current->next;
	}
}

t_pile	*find_cheapest(t_pile *pile)
{
	if (!pile)
		return (NULL);
	while (pile)
	{
		if (pile->cheapest)
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}
