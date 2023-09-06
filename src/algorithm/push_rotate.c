/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:42:12 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/26 13:28:53 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_push_forward(t_stack *stack_a[], t_stack *stack_b[],
		t_list **actions)
{
	while (is_in_lower(*stack_a))
		exec(RA, actions, stack_a, stack_b);
	while (!is_in_upper(*stack_a))
	{
		if (high_enough(*stack_a))
			exec(PB, actions, stack_a, stack_b);
		else
			exec(RA, actions, stack_a, stack_b);
	}
}

static void	rotate_push_backward(t_stack *stack_a[], t_stack *stack_b[],
		t_list **actions)
{
	while (is_in_upper(*stack_a))
		exec(RRA, actions, stack_a, stack_b);
	while (!is_in_lower(*stack_a))
	{
		if (low_enough(*stack_a))
		{
			exec(PB, actions, stack_a, stack_b);
			exec(RRA, actions, stack_a, stack_b);
		}
		else
			exec(RRA, actions, stack_a, stack_b);
	}
}

void	main_loop_v2(t_stack *stack_a[], t_stack *stack_b[], t_list **actions)
{
	int	i;

	i = 0;
	while (!is_done(stack_a))
	{
		rotate_push_forward(stack_a, stack_b, actions);
		quick_sort(stack_a, stack_b, actions);
		while ((*stack_b)[0].active != 0)
			exec(PA, actions, stack_a, stack_b);
		if (is_done(stack_a))
			break ;
		rotate_push_backward(stack_a, stack_b, actions);
		quick_sort(stack_a, stack_b, actions);
		exec(RA, actions, stack_a, stack_b);
		while ((*stack_b)[0].active != 0)
			exec(PA, actions, stack_a, stack_b);
		if (++i == 9999)
			break ;
	}
}

void	rotate_push_start(t_stack *stack_a[], t_stack *stack_b[],
		t_list *actions[])
{
	orient(stack_a, A, actions);
	main_loop_v2(stack_a, stack_b, actions);
	orient(stack_a, A, actions);
}
