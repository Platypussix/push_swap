/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:23:40 by amedioun          #+#    #+#             */
/*   Updated: 2023/02/21 10:32:39 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static t_list	*index_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		min_bool;

	head = *stack;
	min_bool = 0;
	min = head;
	while (head->next)
	{
		if (head->index == -1 && (head->value < min->value || !min_bool))
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
	int		argc;

	index = 0;
	head = index_min(stack);
	argc = head->ac - 1;
	while (index < argc)
	{
		head->index = index++;
		head = index_min(stack);
	}
}
