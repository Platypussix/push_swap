/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:35:59 by amedioun          #+#    #+#             */
/*   Updated: 2023/02/19 18:41:04 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_checkdouble(int nb, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-')
		i++;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_argcheck(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**args;

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
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error();
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error();
		if (ft_checkdouble(tmp, args, i))
			ft_error();
		i++;
	}
	if (ac == 2)
		ft_free(args);
}
