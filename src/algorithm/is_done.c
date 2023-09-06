/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:06:17 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/29 11:46:56 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_done(t_stack *stack_a[])
{
	int		amount;
	int		i;
	t_stack	*tmp;

	amount = last_active(*stack_a)->pos;
	tmp = *stack_a;
	i = 0;
	while (i < amount)
	{
		if (tmp[i].index > tmp[i + 1].index)
			if (tmp[i].index != amount || tmp[i + 1].index != 0)
				return (0);
		i++;
	}
	return (1);
}
