/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:20:50 by amedioun          #+#    #+#             */
/*   Updated: 2023/02/13 14:22:06 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list **stack, int nb)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if (head->index < min && head->index != nb)
			min = head->index;
		return (min);
	}
}

static void	sort_3(t_list **stack)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack;
	min = get_min(stack, -1);
	next_min = get_min(stack, min);
	if (is_sorted(stack))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack);
		else
			rra(stack);
	}
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) <= 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
