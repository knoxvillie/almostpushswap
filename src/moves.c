/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:55:36 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/15 22:21:08 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_remove_first_elem(stack *s)
{
	long	*list;
	int		i;

	list = (long *)malloc(sizeof(int) * (s->size - 1));
	i = 0;
	while ((i + 1) < s->size)
	{
		list[i] = s->list[i + 1];
		i++;
	}
	free (s->list);
	s->list = list;
}

void	ft_swap(stack *s)
{
	long	swap;

	ft_printf("s%c\n", s->c);
	if (s->size < 2)
		return ;
	swap = s->list[0];
	s->list[0] = s->list[1];
	s->list[1] = swap;
}

void	ft_shiftup(stack *s)
{
	long	*list;
	int		i;

	ft_printf("r%c\n", s->c);
	if (s->size < 2)
		return ;
	i = 0;
	list = (long *)malloc(sizeof(long) * s->size);
	while (i <= (s->size - 2))
	{
		list[i] = s->list[i + 1];
		i++;
	}
	list[i] = s->list[0];
	free(s->list);
	s->list = list;
}

void	ft_shiftdown(stack *s)
{
	long	*list;
	int		i;

	ft_printf("rr%c\n", s->c);
	if (s->size < 2)
		return ;
	i = 0;
	list = (long *)malloc(sizeof(long) * s->size);
	while (i <= (s->size - 2))
	{
		list[i + 1] = s->list[i];
		i++;
	}
	list[0] = s->list[i];
	free(s->list);
	s->list = list;
}

void	ft_push(stack *from, stack *to)
{
	long	*list;
	int		i;

	ft_printf("p%c\n", to->c);
	if (from->size < 1)
		return ;
	list = (long *)malloc(sizeof(long) * (to->size + 1));
	i = 0;
	list[0] = from->list[0];
	while (i < to->size)
	{
		list[i + 1] = to->list[i];
		i++;
	}
	free (to->list);
	to->size++;
	to->list = list;
	ft_remove_first_elem(from);
	from->size--;
}
