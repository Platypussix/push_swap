/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:20:22 by amedioun          #+#    #+#             */
/*   Updated: 2023/04/11 11:50:19 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push(t_list **stack_dest, t_list **stack_src)
{
	t_list	*tmp;
	t_list	*head_src;
	t_list	*head_dest;

	if (!ft_lstsize(*stack_src))
		return (-1);
	head_dest = *stack_dest;
	head_src = *stack_src;
	tmp = head_src;
	head_src = head_src->next;
	*stack_src = head_src;
	if (!head_dest)
	{
		head_dest = tmp;
		head_dest->next = NULL;
		*stack_dest = head_dest;
	}
	else
	{
		tmp->next = head_dest;
		*stack_dest = tmp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == (-1))
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == (-1))
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
