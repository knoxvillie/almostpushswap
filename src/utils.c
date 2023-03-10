/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:34:07 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/15 21:58:36 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_abs(int x, int y)
{
	if (y > x)
		return ((x - y) * -1);
	else
		return (x - y);
}

int	ft_avarege(int *list, int size)
{
	int	i;
	int	sum;

	if (!size)
		return (0);
	i = 0;
	sum = 0;
	while (i < size)
	{
		sum += list[i];
		i++;
	}
	return (sum / size);
}

void	print_stacks(stack a, stack b)
{
	int	i;
	int	size;

	size = a.size;
	if (b.size > a.size)
		size = b.size;
	i = 0;
	while (i < size)
	{
		if (a.size > i && b.size > i)
			ft_printf("   %d	%d   \n", a.list[i], b.list[i]);
		else if (a.size > i && b.size <= i)
			ft_printf("   %d	x   \n", a.list[i]);
		else if (a.size <= i && b.size > i)
			ft_printf("   %d	x   \n", b.list[i]);
		i++;
	}
	ft_printf("StackA	StackB\n\n");
}
