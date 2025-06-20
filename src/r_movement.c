/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:22:26 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/19 14:22:35 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_pile **pile_a, char letter)
{
	if (!pile_a)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	*pile_a = (*pile_a)->next;
	if (letter == 'a')
		ft_printf("ra\n");
	else if (letter == 'b')
		ft_printf("rb\n");
	return (1);
}

int	rr(t_pile **pile_a, t_pile **pile_b)
{
	if (!pile_a || !pile_b)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	rotate(pile_a, '0');
	rotate(pile_b, '0');
	ft_printf("rr\n");
	return (1);
}

int	reverse_rotate(t_pile **pile_a, char letter)
{
	if (!pile_a)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	*pile_a = (*pile_a)->prev;
	if (letter == 'a')
		ft_printf("rra\n");
	else if (letter == 'b')
		ft_printf("rrb\n");
	else
		return (perror("wrong letter"), 0);
	return (1);
}

int	rrr(t_pile **pile_a, t_pile **pile_b)
{
	if (!pile_a || !pile_b)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	reverse_rotate(pile_a, '0');
	reverse_rotate(pile_b, '0');
	ft_printf("rrr\n");
	return (1);
}
