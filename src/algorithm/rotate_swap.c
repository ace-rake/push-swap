/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:06:29 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/22 12:02:40 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	reverse_done(t_stack stack[])
{
	int	size;
	int	i;

	i = 0;
	size = last_active(stack)->pos;
	while (i < size)
	{
		if (stack[i].index < stack[i + 1].index)
			return (0);
		++i;
	}
	return (1);
}

void	backward_swap(t_stack *stack[], t_list *actions[], int highest)
{
	while ((*stack)[0].index != highest)
	{
		if ((*stack)[0].index < (*stack)[1].index)
			exec_empty(S, actions, stack);
		else
			exec_empty(Rr, actions, stack);
	}
}

void	forward_swap(t_stack *stack[], t_list *actions[], int lowest)
{
	while ((*stack)[1].index != lowest)
	{
		if ((*stack)[0].index < (*stack)[1].index)
			exec_empty(S, actions, stack);
		exec_empty(R, actions, stack);
	}
}

void	rotate_swap_start(t_stack *stack[], t_list *actions[])
{
	int	lowest;
	int	highest;

	lowest = lowest_index(*stack);
	highest = highest_index(*stack);
	while (!reverse_done(*stack))
	{
		if ((*stack)[0].index < (*stack)[1].index)
			if (!((*stack)[0].index == lowest && (*stack)[1].index == highest))
				exec_empty(S, actions, stack);
		exec_empty(R, actions, stack);
	}
}
void	rotate_swap_start_v2(t_stack *stack[], t_list *actions[])
{
	int	lowest;
	int	highest;

	lowest = lowest_index(*stack);
	highest = highest_index(*stack);
	while (!reverse_done(*stack))
	{
		forward_swap(stack, actions, lowest);
		backward_swap(stack, actions, highest);
	}
}

void	rotate_swap(t_stack *stack[], t_list *actions[], int option)
{
	t_list	*new_actions;

	orient(stack, option, actions);
	new_actions = NULL;
	exec_empty(Rr, &new_actions, stack);
	exec_empty(S, &new_actions, stack);
	exec_empty(R, &new_actions, stack);
	rotate_swap_start_v2(stack, &new_actions);
	update_new_actions(&new_actions, option);
	if (ft_lstlast(*actions) != NULL)
		ft_lstlast(*actions)->next = new_actions;
	else
		*actions = new_actions;
}
