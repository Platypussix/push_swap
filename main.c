/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:00:23 by amedioun          #+#    #+#             */
/*   Updated: 2023/02/15 16:41:49 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_maker(t_list **stack, int ac, char **av)
{
	int		i;
	char	**args;
	t_list	*new_stack;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		new_stack = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new_stack);
		i++;
	}
	get_index(stack);
	if (ac == 2)
		ft_free(args);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
//	else
//		big_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		return (-1);
	ft_argcheck(ac, av);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	stack_maker(stack_a, ac, av);
	if (is_sorted(stack_a))
	{
		freestack(stack_a);
		freestack(stack_b);
		return (0);
	}
	push_swap(stack_a, stack_b);
	freestack(stack_a);
	freestack(stack_b);
	return (0);
}
