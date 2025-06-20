/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:27:23 by vaires-m          #+#    #+#             */
/*   Updated: 2024/04/29 12:27:23 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int main()
{
	t_list *head = NULL;

	t_list *node1 =(t_list *)malloc(sizeof(t_list));
	t_list *node2 =(t_list *)malloc(sizeof(t_list));
	t_list *node3 =(t_list *)malloc(sizeof(t_list));

	node1->content = "hello";
	node2->content = "world";
	node3->content = "hello";

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	head = node1;
    
    // Call ft_lstsize to get the size of the list
    int size = ft_lstsize(head);
    
    // Print the size of the list
    printf("Size of the list: %d\n", size);
    
    return 0;


}
*/