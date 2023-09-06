/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:19:01 by vdenisse          #+#    #+#             */
/*   Updated: 2023/07/06 13:51:35 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	exec_2(int action, t_stack *stack_a[], t_stack *stack_b[])
{
	if (action == PA)
		push(stack_b, stack_a);
	if (action == PB)
		push(stack_a, stack_b);
	if (action == SA)
		swap(stack_a);
	if (action == SB)
		swap(stack_b);
	if (action == SS)
	{
		swap(stack_a);
		swap(stack_b);
	}
}

void	exec(int action, t_list *actions[], t_stack *stack_a[],
		t_stack *stack_b[])
{
	t_list	*new;

	new = ft_lstnew(action);
	ft_lstadd_back(actions, new);
	if (action == RA)
		rotate(stack_a);
	if (action == RB)
		rotate(stack_b);
	if (action == RR)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (action == RRA)
		rrotate(stack_a);
	if (action == RRB)
		rrotate(stack_b);
	if (action == RRR)
	{
		rrotate(stack_a);
		rrotate(stack_b);
	}
	exec_2(action, stack_a, stack_b);
}

void	exec_a_only(int action, t_list *actions[], t_stack *stack_a[])
{
	exec(action, actions, stack_a, NULL);
}

void	exec_b_only(int action, t_list *actions[], t_stack *stack_b[])
{
	exec(action, actions, NULL, stack_b);
}

void	exec_empty(int action, t_list *actions[], t_stack *stack[])
{
	t_list	*new;

	new = ft_lstnew(action);
	ft_lstadd_back(actions, new);
	if (action == R)
		rotate(stack);
	else if (action == Rr)
		rrotate(stack);
	else if (action == S)
		swap(stack);
}
