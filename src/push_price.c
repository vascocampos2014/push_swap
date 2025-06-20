/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:19:17 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/19 14:40:52 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_price_calc(t_pile *a, int len_a, int len_b)
{
	if (a->above_median && a->target_node->above_median)
		a->push_cost = (len_a - a->index) + (len_b - a->target_node->index);
	else if (!a->above_median && !a->target_node->above_median)
		a->push_cost = a->index + a->target_node->index;
	else if (!a->above_median && a->target_node->above_median)
		a->push_cost = a->index + (len_b - a->target_node->index);
	else
		a->push_cost = (len_a - a->index) + a->target_node->index;
}

int	push_price(t_pile *a, t_pile *b)
{
	t_pile	*head;
	int		len_a;
	int		len_b;

	if (!a || !b)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	head = a;
	len_a = list_len(a);
	len_b = list_len(b);
	while (1)
	{
		push_price_calc(a, len_a, len_b);
		if (a->next == head)
			return (1);
		a = a->next;
	}
}
