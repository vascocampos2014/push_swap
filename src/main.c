/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:20:19 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/19 14:39:02 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	bool	allocated;
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc == 1)
		exit(1);
	allocated = false;
	parse_args(&argc, &argv, &allocated);
	pile_a = NULL;
	pile_b = NULL;
	init_node_a(&pile_a, argv, allocated);
	push_swap(&pile_a, &pile_b);
	free_pile(&pile_b);
	free_pile(&pile_a);
	if (allocated)
		free_split(argv);
	return (1);
}
