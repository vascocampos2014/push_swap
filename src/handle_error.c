/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:21:06 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/20 15:19:38 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_value(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	repeated_values(char **array)
{
	int		i;
	int		j;
	long	num1;
	long	num2;

	if (!array || !array[0])
		return (0);
	i = 0;
	while (array[i])
	{
		num1 = ft_atol(array[i]);
		if (check_value(num1))
			return (1);
		j = i + 1;
		while (array[j])
		{
			num2 = ft_atol(array[j]);
			if (check_value(num2) || num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	invalid_arg(const char *str)
{
	int	i;

	if (!str || !*str)
		return (1);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!str[i + 1])
			return (1);
		i++;
	}
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_args(char **argv, int i)
{
	long	nbr;

	while (argv[i])
	{
		if (invalid_arg(argv[i]))
			return (1);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

void	handle_errors(t_pile **pile, char **argv, bool allocated)
{
	int		error;
	char	**arr;
	int		i;

	i = 0;
	if (!allocated)
		i = 1;
	error = check_args(argv, i);
	if (allocated)
		arr = argv;
	else
		arr = argv + 1;
	error += repeated_values(arr);
	if (error)
	{
		if (allocated)
			free_split(argv);
		free_pile(pile);
		write(2, "Error\n", 6);
		exit(1);
	}
}
