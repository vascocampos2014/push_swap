/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:33 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/19 14:16:36 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile	*find_max(t_pile *pile)
{
	t_pile	*max;
	t_pile	*current;

	if (!pile)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	max = pile;
	current = pile->next;
	while (current != pile)
	{
		if (current->content > max->content)
			max = current;
		current = current->next;
	}
	return (max);
}

t_pile	*closest_bigger(t_pile *a, t_pile *b)
{
	t_pile	*head_a;
	t_pile	*bigger;
	long	index;

	if (!a || !b)
		return (NULL);
	head_a = a;
	bigger = NULL;
	index = LONG_MAX;
	while (a->next != head_a)
	{
		if (a->content > b->content && a->content < index)
		{
			index = a->content;
			bigger = a;
		}
		a = a->next;
	}
	if (a->content > b->content && a->content < index)
		bigger = a;
	if (!bigger)
		return (NULL);
	return (bigger);
}

t_pile	*closest_smaller(t_pile *a, t_pile *b)
{
	t_pile	*head_b;
	long	index;
	t_pile	*smaller;

	if (!a || !b)
		return (NULL);
	head_b = b;
	smaller = NULL;
	index = LONG_MIN;
	while (b->next != head_b)
	{
		if (a->content > b->content && index < b->content)
		{
			index = b->content;
			smaller = b;
		}
		b = b->next;
	}
	if (a->content > b->content && index < b->content)
		smaller = b;
	if (!smaller)
		return (NULL);
	return (smaller);
}

void	set_target_a(t_pile *a, t_pile *b)
{
	t_pile	*head_a;
	t_pile	*target;

	head_a = a;
	while (a->next != head_a)
	{
		target = NULL;
		target = closest_smaller(a, b);
		if (!target)
			a->target_node = find_max(b);
		else if (target)
			a->target_node = target;
		a = a->next;
	}
	target = NULL;
	target = closest_smaller(a, b);
	if (!target)
		a->target_node = find_max(b);
	else if (target)
		a->target_node = target;
}

void	set_target_b(t_pile *a, t_pile *b)
{
	t_pile	*head_b;
	t_pile	*target;

	head_b = b;
	while (b->next != head_b)
	{
		target = NULL;
		target = closest_bigger(a, b);
		if (!target)
			b->target_node = find_min(a);
		else if (target)
			b->target_node = target;
		b = b->next;
	}
	target = NULL;
	target = closest_bigger(a, b);
	if (!target)
		b->target_node = find_min(a);
	else if (target)
		b->target_node = target;
}
