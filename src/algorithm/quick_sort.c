/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:41:05 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/26 13:23:53 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	highest_finder(t_stack *stack)
{
	int	iter;
	int	size;

	size = last_active(stack)->pos;
	iter = 0;
	while (iter < size / 2)
	{
		if (stack[iter].index == highest_index(stack))
			return (1);
		if (stack[size - iter].index == highest_index(stack))
			return (0);
		iter++;
	}
	return (-1);
}

static void	smart_push_a(t_stack *stack_a[], t_stack *stack_b[],
		t_list *actions[])
{
	while (is_in_lower(*stack_a))
		exec(RA, actions, stack_a, stack_b);
	while ((*stack_b)[0].active != 0)
	{
		if (highest_finder(*stack_b))
		{
			while ((*stack_b)[0].index != highest_index(*stack_b))
				exec(RB, actions, stack_a, stack_b);
			exec(PA, actions, stack_a, stack_b);
		}
		else
		{
			while ((*stack_b)[0].index != highest_index(*stack_b))
				exec(RRB, actions, stack_a, stack_b);
			exec(PA, actions, stack_a, stack_b);
		}
	}
}

static int	push_to_a(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[],
		int pivot)
{
	int	size;
	int	iter;
	int	pushed;

	pushed = 0;
	size = last_active(*stack_b)->pos;
	iter = 0;
	while (iter <= size)
	{
		if ((*stack_b)->index >= pivot)
		{
			exec(PA, actions, stack_a, stack_b);
			if ((*stack_a)->index == pivot)
				exec(RA, actions, stack_a, stack_b);
			pushed++;
		}
		else if ((*stack_b)->index < pivot)
			exec(RB, actions, stack_a, stack_b);
		iter++;
	}
	return (pushed);
}

int	quick_sort(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[])
{
	int	pushed;
	int	iter;
	int	pivot;

	pivot = ((highest_index(*stack_b) - lowest_index(*stack_b)) / 2)
		+ lowest_index(*stack_b);
	iter = 0;
	pushed = push_to_a(stack_a, stack_b, actions, pivot);
	if (last_active(*stack_a)->index == pivot)
		exec(RRA, actions, stack_a, stack_b);
	while (iter++ < pushed)
		exec(PB, actions, stack_a, stack_b);
	smart_push_a(stack_a, stack_b, actions);
	return (0);
}
