/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:21:47 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/19 14:26:05 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	sort_three_helper(t_pile **pile, t_pile *head, t_pile *second,
			t_pile *third)
{
	int	moves;

	moves = 0;
	if (head->content > second->content && second->content > third->content)
	{
		moves += rotate(pile, 'a');
		moves += swap(pile, 'a');
	}
	else if (head->content > second->content && head->content > third->content)
		moves += rotate(pile, 'a');
	else if (head->content > second->content && head->content < third->content)
		moves += swap(pile, 'a');
	else if (head->content < second->content && head->content > third->content)
		moves += reverse_rotate(pile, 'a');
	else if (second->content > third->content)
	{
		moves += reverse_rotate(pile, 'a');
		moves += swap(pile, 'a');
	}
	return (moves);
}

int	sort_three(t_pile **pile)
{
	t_pile	*head;
	t_pile	*second;
	t_pile	*third;

	head = *pile;
	second = head->next;
	third = second->next;
	return (sort_three_helper(pile, head, second, third));
}

void	put_node_top(t_pile **pile, t_pile *node, char letter)
{
	t_pile	*head;

	if (!pile || !*pile || !node)
		return ;
	head = *pile;
	if (head == node)
		return ;
	while (head != node)
	{
		if (node->above_median)
			reverse_rotate(pile, letter);
		else
			rotate(pile, letter);
		head = *pile;
	}
}

void	from_atob(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest_node;

	cheapest_node = find_cheapest(*pile_a);
	put_node_top(pile_a, cheapest_node, 'a');
	put_node_top(pile_b, cheapest_node->target_node, 'b');
	push(pile_a, pile_b, 'b');
	init_nodes(*pile_a, *pile_b);
}

void	from_btoa(t_pile **pile_a, t_pile **pile_b)
{
	put_node_top(pile_a, (*pile_b)->target_node, 'a');
	push(pile_b, pile_a, 'a');
}
