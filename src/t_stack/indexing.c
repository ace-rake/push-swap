/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:12:37 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/30 10:17:05 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	indexer(t_stack *stack[], int amount)
{
	int		i;
	int		index;
	int		j;
	t_stack	*tmp;

	tmp = *stack;
	i = 0;
	while (i < amount)
	{
		j = 0;
		index = 0;
		while (j < amount)
		{
			if (tmp[i].content >= tmp[j].content)
				index++;
			j++;
		}
		tmp[i].index = index - 1;
		i++;
	}
}
