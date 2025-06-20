/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:18:35 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/19 14:18:36 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_pile **pile_a, char letter)
{
	t_pile	*first;
	t_pile	*second;
	t_pile	*last;

	last = (*pile_a)->prev;
	first = *pile_a;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->prev = last;
	second->next = first;
	last->next = second;
	first->prev = second;
	*pile_a = second;
	if (letter == 'a')
		ft_printf("sa\n");
	else if (letter == 'b')
		ft_printf("sb\n");
	return (1);
}

int	ss_movement(t_pile **pile_a, t_pile **pile_b)
{
	if (!pile_a || !pile_b)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	swap(pile_a, '0');
	swap(pile_b, '0');
	ft_printf("ss\n");
	return (2);
}
