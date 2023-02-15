/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:05:26 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/15 22:22:28 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_a_sigle_argv(stack *a, char *str)
{
	char	**split;
	int		i;

	a->c = 'a';
	a->size = word_counter(str);
	a->list = (long *)malloc(sizeof(long) * a->size);
	split = ft_split(str);
	i = 0;
	while (split[i])
	{
		a->list[i] = ft_atol(split[i]);
		i++;
	}
	free_split(split);
}

void	single_argv(stack *a, stack *b, char *str)
{
	init_b(b);
	init_a_sigle_argv(a, str);
}
