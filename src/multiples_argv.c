/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiples_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:02:59 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/15 22:21:40 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_b(stack *b)
{
	b->list = NULL;
	b->size = 0;
	b->c = 'b';
}

static void	init_a_mult_argv(stack *a, int argc, char **argv)
{
	int	i;
	int	s;

	s = 1;
	a->c = 'a';
	a->size = argc - 1;
	a->list = (long *)malloc(sizeof(long) * a->size);
	i = 0;
	while (i < argc)
	{
		a->list[i] = ft_atol(argv[s]);
		i++;
		s++;
	}
}

void	multiples_argv(stack *a, stack *b, int argc, char **argv)
{
	init_b(b);
	init_a_mult_argv(a, argc, argv);
}
