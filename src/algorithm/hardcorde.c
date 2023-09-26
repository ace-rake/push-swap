/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcorde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <vdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:12:26 by vdenisse          #+#    #+#             */
/*   Updated: 2023/09/26 10:38:00 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	hardcode_2(t_stack *stack_a[], t_list *actions[])
{
	if ((*stack_a)[0].index > (*stack_a)[1].index)
		exec_a_only(SA, actions, stack_a);
}

void	hardcode_3(t_stack *stack_a[], t_list *actions[])
{
	if ((*stack_a)[0].index != lowest_index(*stack_a)
		&& (*stack_a)[1].index == highest_index(*stack_a))
		exec_a_only(RRA, actions, stack_a);
	if ((*stack_a)[0].index == highest_index(*stack_a)
		&& (*stack_a)[1].index == lowest_index(*stack_a))
		exec_a_only(RA, actions, stack_a);
	if (is_done(stack_a))
		return ;
	exec_a_only(SA, actions, stack_a);
	if ((*stack_a)[0].index != lowest_index(*stack_a)
		&& (*stack_a)[1].index == highest_index(*stack_a))
		exec_a_only(RRA, actions, stack_a);
	if ((*stack_a)[0].index == highest_index(*stack_a)
		&& (*stack_a)[1].index == lowest_index(*stack_a))
		exec_a_only(RA, actions, stack_a);
}

void	hardcode_4(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[])
{
	exec(PB, actions, stack_a, stack_b);
	hardcode_3(stack_a, actions);
	if ((*stack_b)[0].index < lowest_index(*stack_a)
		|| (*stack_b)[0].index > highest_index(*stack_a))
	{
		exec(PA, actions, stack_a, stack_b);
		if ((*stack_a)[0].index == highest_index(*stack_a))
			exec(RA, actions, stack_a, stack_b);
	}
	else if ((*stack_b)[0].index > (*stack_a)[0].index
			&& (*stack_b)[0].index < (*stack_a)[1].index)
	{
		exec(RA, actions, stack_a, stack_b);
		exec(PA, actions, stack_a, stack_b);
		exec(RRA, actions, stack_a, stack_b);
	}
	else if ((*stack_b)[0].index > (*stack_a)[1].index
			&& (*stack_b)[0].index < (*stack_a)[2].index)
	{
		exec(RRA, actions, stack_a, stack_b);
		exec(PA, actions, stack_a, stack_b);
		exec(RA, actions, stack_a, stack_b);
		exec(RA, actions, stack_a, stack_b);
	}
}

void	hardcode_5(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[])
{
	int	size;

	exec(PB, actions, stack_a, stack_b);
	exec(PB, actions, stack_a, stack_b);
	size = last_active(*stack_a)->pos;
	hardcode_3(stack_a, actions);
	while ((*stack_b)[0].active != 0)
	{
		if ((*stack_a)[0].index - 1 == (*stack_b)[0].index
			|| (*stack_a)[size].index + 1 == (*stack_b)[0].index)
		{
			exec(PA, actions, stack_a, stack_b);
			size++;
		}
		else if (((*stack_a)[0].index - 1 == (*stack_b)[1].index
					|| (*stack_a)[size].index + 1 == (*stack_b)[1].index)
				&& (*stack_b)[1].active == 1)
		{
			exec(RB, actions, stack_a, stack_b);
			exec(PA, actions, stack_a, stack_b);
			size++;
		}
		else
			exec(RA, actions, stack_a, stack_b);
	}
	if ((*stack_a)[0].index >= 3)
		while ((*stack_a)->index != 0)
			exec(RA, actions, stack_a, stack_b);
	else
		while ((*stack_a)->index != 0)
			exec(RRA, actions, stack_a, stack_b);
}

void	hardcode(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[])
{
	int	size;

	size = last_active(*stack_a)->pos + 1;
	if (size == 2)
		hardcode_2(stack_a, actions);
	else if (size == 3)
		hardcode_3(stack_a, actions);
	else if (size == 4)
		hardcode_4(stack_a, stack_b, actions);
	else if (size == 5)
		hardcode_5(stack_a, stack_b, actions);
	(void)stack_b;
}
