/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:20:50 by amedioun          #+#    #+#             */
/*   Updated: 2023/03/29 16:52:06 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_min(t_list **stack, int nb)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != nb)
			min = head->index;
	}
	return (min);
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
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack);
		else
			rra(stack);
	}
	else
	{
		if (head->next->index == min)
			ra(stack);
		else
		{
			sa(stack);
			rra(stack);
		}
	}
}

// static void	sort_4(t_list **stack_a, t_list **stack_b)
// {
// 	int	distance;

// 	if (is_sorted(stack_a))
// 		return ;
// 	distance = get_distance(stack_a, get_min(stack_a, -1));
// 	if (distance == 1)
// 		ra(stack_a);
// 	else if (distance == 2)
// 	{
// 		ra(stack_a);
// 		ra(stack_a);
// 	}
// 	else if (distance == 3)
// 		rra(stack_a);
// 	if (is_sorted(stack_a))
// 		return ;
// 	pb(stack_a, stack_b);
// 	sort_3(stack_a);
// 	pa(stack_a, stack_b);
// }

// static void	sort_5(t_list **stack_a, t_list **stack_b)
// {
// 	int	distance;

// 	if (is_sorted(stack_a))
// 		return ;
// 	distance = get_distance(stack_a, get_min(stack_a, -1));
// 	if (distance == 1)
// 		ra(stack_a);
// 	else if (distance == 2)
// 	{
// 		ra(stack_a);
// 		ra(stack_a);
// 	}
// 	else if (distance == 3)
// 	{
// 		rra(stack_a);
// 		rra(stack_a);
// 	}
// 	else if (distance == 4)
// 		rra(stack_a);
// 	if (is_sorted(stack_a))
// 		return ;
// 	pb(stack_a, stack_b);
// 	sort_4(stack_a, stack_b);
// 	pa(stack_a, stack_b);
// }

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		min;
	int		i;

	min = get_min(stack_a, 0);
	head = *stack_a;
	i = 0;
	if (is_sorted(stack_a))
		return ;
	while (i++ < 2)
	{
		while (head->index != min)
			head = head->next;
		pb(stack_a, stack_b);
	}
	printf("%d", head->value);
	printf("%d", head->next->value);
	printf("%d", head->next->next->value);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
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
//	else if (size == 4)
//		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
