/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:34:39 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/09 13:53:37 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	setup(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[], int *i)
{
	exec(PB, actions, stack_a, stack_b);
	exec(PB, actions, stack_a, stack_b);
	*i = last_active(*stack_a)->pos;
	hardcode_3(stack_a, actions);
}

void	rerotate(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[])
{
	if ((*stack_a)[0].index >= 3)
		while ((*stack_a)->index != 0)
			exec(RA, actions, stack_a, stack_b);
	else
		while ((*stack_a)->index != 0)
			exec(RRA, actions, stack_a, stack_b);
}

void	hardcode_5(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[])
{
	int	size;

	setup(stack_a, stack_b, actions, &size);
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
	rerotate(stack_a, stack_b, actions);
}
