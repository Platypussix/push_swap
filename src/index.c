/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:23:40 by amedioun          #+#    #+#             */
/*   Updated: 2023/03/10 17:32:50 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static t_list	*index_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		min_bool;

	min = NULL;
	min_bool = 0;
	head = *stack;
	while (head->next)
	{
		if ((head->index == -1) && (!min_bool || head->value < min->value))
		{
			min = head;
			min_bool = 1;
		}
		head = head->next;
	}
	return (min);
}

void	get_index(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = index_min(stack);
	while (head)
	{
		head->index = index++;
		head = index_min(stack);
	}
}

// void	get_index(t_list **stack)
// {
// 	t_list	*head;
// 	int		index;
// 	int		argc;

// 	index = 0;
// 	head = index_min(stack);
// 	argc = head->ac - 2;
// 	while (index < argc)
// 	{
// 		head->index = index++;
// 		head = index_min(stack);
// 	}
// }
