/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unsorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:13:47 by vdenisse          #+#    #+#             */
/*   Updated: 2023/09/26 09:50:17 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_in_upper(t_stack stack_a[])
{
	int	i;
	int	highest;

	highest = highest_index(stack_a);
	i = 0;
	if (stack_a[0].index == highest)
		return (1);
	while (stack_a[i].index + 1 == stack_a[i + 1].index)
		i++;
	if (stack_a[i].index == highest)
		if (stack_a[i + 1].index == 0)
			return (1);
	return (0);
}

int	is_in_lower(t_stack stack_a[])
{
	int	i;
	int	lowest;
	int	highest;
	int	amount;

	amount = last_active(stack_a)->pos;
	highest = highest_index(stack_a);
	lowest = lowest_index(stack_a);
	if (stack_a[0].index == lowest)
		return (1);
	i = amount;
	if (stack_a[0].index - 1 != stack_a[amount].index)
		return (0);
	while (stack_a[i].index - 1 == stack_a[i - 1].index)
		i--;
	if (stack_a[i].index == lowest)
		if (stack_a[i - 1].index == highest)
			return (1);
	return (0);
}

int	is_unsorted(t_stack stack[])
{
	if (is_in_lower(stack))
		return (0);
	if (is_in_upper(stack))
		return (0);
	return (1);
}
