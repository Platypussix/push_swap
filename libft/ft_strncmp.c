/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:11:25 by amedioun          #+#    #+#             */
/*   Updated: 2022/11/25 15:10:13 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	if (s1[i] != s2[i] && s1[i] == '\0')
		return (-1);
	while ((s1[i] || s2[i]) && s1[i] == s2[i] && i < n - 1)
		i++;
	if (s1[i] != s2[i] && (n != 0))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
