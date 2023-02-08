/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:23:40 by amedioun          #+#    #+#             */
/*   Updated: 2023/02/03 15:46:48 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*index_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		min_bool;

	min = NULL;
	head = *stack;
	min_bool = 0;
	if (!head)
		return (min);
	while (head)
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

	index = 0;
	head = index_min(stack);
	while (head)
	{
		head->index = index++;
		head = index_min(stack);
	}
}
