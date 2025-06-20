/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:21:27 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/20 15:19:27 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_to_top(t_pile **pile)
{
	t_pile	*min;

	min = find_min(*pile);
	while (*pile != min)
	{
		if (min->above_median)
			reverse_rotate(pile, 'a');
		else if (!min->above_median)
			rotate(pile, 'a');
	}
}

void	sort_four(t_pile **pile_a, t_pile **pile_b)
{
	push(pile_a, pile_b, 'b');
	sort_three(pile_a);
	init_nodes(*pile_a, *pile_b);
	from_btoa(pile_a, pile_b);
	min_to_top(pile_a);
}

int	is_sorted(t_pile *pile)
{
	t_pile	*head;

	if (!pile)
		return (1);
	head = pile;
	while (pile->next != head)
	{
		if (pile->content > pile->next->content)
			return (0);
		pile = pile->next;
	}
	return (1);
}

void	push_swap(t_pile **a, t_pile **b)
{
	if (list_len(*a) > 4 && !is_sorted(*a))
	{
		push(a, b, 'b');
		push(a, b, 'b');
		init_nodes(*a, *b);
	}
	if (list_len(*a) == 4 && !is_sorted(*a))
		sort_four(a, b);
	while (list_len(*a) > 3 && !is_sorted(*a))
		from_atob(a, b);
	if (list_len(*a) == 3 && !is_sorted(*a))
		sort_three(a);
	while (list_len(*b) != 0)
	{
		init_nodes(*a, *b);
		from_btoa(a, b);
	}
	set_index(*a);
	min_to_top(a);
}
