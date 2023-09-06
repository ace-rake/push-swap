/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_high_enough.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:35:15 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/26 14:13:35 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	lowest_from_highest(t_stack *stack)
{
	int	i;
	int	size;

	size = highest_index(stack);
	i = size - 1;
	while (stack[i].index != size)
		--i;
	while (stack[i].index - 1 == stack[i - 1].index)
		--i;
	return (stack[i].index);
}
static int	highest_from_lowest(t_stack *stack)
{
	int	i;
	int	lowest;

	lowest = lowest_index(stack);
	i = 0;
	while (stack[i].index != lowest)
		++i;
	while (stack[i].index + 1 == stack[i + 1].index)
		++i;
	return (stack[i].index);
}
int	high_enough(t_stack *stack)
{
	int	lowest_highest;

	//	int	highest_lowest;
	//	int	unsorted;
	lowest_highest = lowest_from_highest(stack);
	//	highest_lowest = highest_from_lowest(stack);
	//	unsorted = lowest_highest - highest_lowest;
	if (stack[0].index > lowest_highest - 50)
		return (1);
	return (0);
}
int	low_enough(t_stack *stack)
{
	int	highest_lowest;

	//	int	lowest_highest;
	//	int	unsorted;
	//	lowest_highest = lowest_from_highest(stack);
	highest_lowest = highest_from_lowest(stack);
	//	unsorted = lowest_highest - highest_lowest;
	if (stack[0].index < highest_lowest + 50)
		return (1);
	return (0);
}
