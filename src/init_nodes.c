/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:20:36 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/19 14:29:04 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_nodes(t_pile *pile_a, t_pile *pile_b)
{
	set_index(pile_a);
	set_index(pile_b);
	set_target_a(pile_a, pile_b);
	set_target_b(pile_a, pile_b);
	push_price(pile_a, pile_b);
	push_price(pile_b, pile_a);
	set_cheapest(pile_a);
}

static long	ft_atol_calc(const char *str, int *i, int sign)
{
	long	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (result > (LONG_MAX - (str[*i] - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_atol_calc(str, &i, sign);
	return (result * sign);
}

void	init_node_a(t_pile **pile_a, char **argv, bool allocated)
{
	int	i;
	int	nbr;

	i = 0;
	if (!allocated)
		i = 1;
	handle_errors(pile_a, argv, allocated);
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		add_number(pile_a, nbr);
		i++;
	}
}
