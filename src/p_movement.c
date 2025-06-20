/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:19:36 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/19 14:38:05 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	insert_top_b(t_pile **pile_b, t_pile *top_a)
{
	if (*pile_b == NULL)
	{
		top_a->next = top_a;
		top_a->prev = top_a;
		*pile_b = top_a;
	}
	else
	{
		top_a->next = *pile_b;
		top_a->prev = (*pile_b)->prev;
		(*pile_b)->prev->next = top_a;
		(*pile_b)->prev = top_a;
		*pile_b = top_a;
	}
}

int	push(t_pile **pile_a, t_pile **pile_b, char letter)
{
	t_pile	*top_a;

	top_a = *pile_a;
	if (top_a->next == top_a)
		*pile_a = NULL;
	else
	{
		*pile_a = top_a->next;
		(*pile_a)->prev = top_a->prev;
		top_a->prev->next = *pile_a;
	}
	insert_top_b(pile_b, top_a);
	print_push(letter);
	return (1);
}

void	print_push(char letter)
{
	if (letter == 'a')
		ft_printf("pa\n");
	else if (letter == 'b')
		ft_printf("pb\n");
}
