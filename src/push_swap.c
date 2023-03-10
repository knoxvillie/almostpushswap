/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:03:04 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/15 21:17:30 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	stack	a;
	stack	b;

	if (argc < 2)
	{
		return (0);
	}
	checkarguments(&a, &b, argv, argc);
	if (a.size <= 3)
		pushswap_3(&a);
	else if (a.size <= 5)
		pushswap_5(&a, &b);
	else if (a.size <= 100)
		pushswap_100(&a, &b, 5);
	else if (a.size >= 500)
		pushswap_500(&a, &b, 2);
	free (a.list);
	free (b.list);
	return (0);
}
