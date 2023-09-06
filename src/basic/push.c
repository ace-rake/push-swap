/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:59:42 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/01 11:45:30 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	rrotate_empty(t_stack *stack[])
{
	int		i;
	t_stack	*tmp_stack;

	tmp_stack = *stack;
	if (tmp_stack[0].active == 0)
		return (0);
	i = last_active(tmp_stack)->pos;
	i++;
	while (i > 0)
	{
		tmp_stack[i].content = tmp_stack[i - 1].content;
		tmp_stack[i].index = tmp_stack[i - 1].index;
		tmp_stack[i].active = tmp_stack[i - 1].active;
		--i;
	}
	*stack = tmp_stack;
	return (1);
}

int	push(t_stack *stack_sender[], t_stack *stack_receiver[])
{
	t_stack	to_send;
	t_stack	*sender;

	sender = *stack_sender;
	if (sender[0].active == 0)
		return (0);
	to_send = sender[0];
	rotate(&sender);
	last_active(sender)->active = 0;
	rrotate_empty(stack_receiver);
	*stack_receiver[0] = to_send;
	return (1);
}
