/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:28 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/15 20:45:03 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	word_counter(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

static int	word_size(char *str, int pos)
{
	int	len;

	len = -1;
	while (str[pos] && str[pos] != ' ')
	{
		len++;
		pos++;
	}
	return (len + 1);
}

static char	*get_word(char *str, int pos)
{
	char	*arg;
	int		size;
	int		i;

	size = word_size(str, pos);
	arg = (char *)malloc(sizeof(char) * (size));
	if (!arg)
		return (NULL);
	i = 0;
	while (str[pos] && str[pos] != ' ')
		arg[i++] = str[pos++];
	arg[i] = '\0';
	return (arg);
}

char	**ft_split(char *str)
{
	char	**args;
	int		scount;
	int		i;
	int		pos_args;

	i = 0;
	pos_args = 0;
	scount = word_counter(str);
	args = (char **)malloc((sizeof(char *)) * (scount + 1));
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			args[pos_args++] = get_word(str, i++);
		while (str[i] && str[i] != ' ')
			i++;
	}
	args[pos_args] = NULL;
	return (args);
}

void	free_split(char **str)
{
	int	string;

	string = 0;
	while (str[string])
		free (str[string++]);
	free (str[string]);
	free (str);
}
