/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:43:27 by vaires-m          #+#    #+#             */
/*   Updated: 2025/05/23 12:19:58 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_pile
{
	int				content;
	int				index;
	bool			cheapest;
	bool			above_median;
	int				push_cost;
	struct s_pile	*target_node;
	struct s_pile	*next;
	struct s_pile	*prev;
}	t_pile;

void	parse_args(int *argc, char ***argv, bool *allocated);
long	ft_atol(const char *str);
int		repeated_values(char **array);
void	print_list_backward(t_pile *root, int len);
void	move_back_to_a(t_pile **a, t_pile **b, int *moves);
void	push_two_to_b(t_pile **a, t_pile **b, int *moves);
void	free_split(char **result);
void	handle_errors(t_pile **pile, char **str, bool allocated);
char	**split(const char *s, char c);
void	init_node_a(t_pile **pile_a, char **argv, bool allocated);
void	print_push(char letter);
void	free_pile(t_pile **pile);
void	from_atob(t_pile **a, t_pile **b);
void	put_node_top(t_pile **pile, t_pile *node, char letter);
t_pile	*find_cheapest(t_pile *pile);
void	min_to_top(t_pile **pile);
void	push_swap(t_pile **pile_a, t_pile **pile_b);
void	from_btoa(t_pile **pile_a, t_pile **pile_b);
t_pile	*closest_smaller(t_pile *a, t_pile *b);
void	set_target_b(t_pile *a, t_pile *b);
int		sort_three(t_pile **pile);
void	init_nodes(t_pile *pile_a, t_pile *pile_b);
void	set_cheapest(t_pile *pile);
void	set_target_a(t_pile *a, t_pile *b);
int		push_price(t_pile *a, t_pile *b);
int		list_len(t_pile *list);
void	set_index(t_pile *pile);
void	set_target(t_pile *a, t_pile *b);
t_pile	*find_min(t_pile *pile);
t_pile	*find_max(t_pile *pile);
int		push(t_pile **a, t_pile **b, char letter);
void	add_number(t_pile **root, int nbr);
int		rotate(t_pile **pile, char letter);
int		rr(t_pile **a, t_pile **b);
int		reverse_rotate(t_pile **pile, char letter);
int		rrr(t_pile **a, t_pile **b);
int		swap(t_pile **pile, char letter);
int		ss(t_pile **a, t_pile **b);

#endif