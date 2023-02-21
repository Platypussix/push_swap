/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:01:08 by amedioun          #+#    #+#             */
/*   Updated: 2023/02/21 10:32:29 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				ac;
	struct s_list	*next;
}				t_list;

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

t_list	*ft_lstnew(int value, int ac);
void	ft_lstadd_front(t_list **stack, t_list *new);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		ft_lstsize(t_list *head);

int		main(int ac, char **av);
void	ft_error(void);
void	ft_free(char **str);
void	ft_argcheck(int ac, char **av);
void	get_index(t_list **stack);
int		get_distance(t_list **stack, int index);
void	simple_sort(t_list **stack_a, t_list **stack_b);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
long	ft_atoi(const char *str);
void	freestack(t_list **stack);
int		is_sorted(t_list **stack);
int		ft_isdigit(char g);

#endif