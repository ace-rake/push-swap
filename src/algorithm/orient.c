/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orient.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:01:50 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/22 11:10:51 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	lowest(t_stack *stack)
{
	int	result;
	int	iter;

	result = 2000000000;
	iter = 0;
	while (stack[iter].active)
	{
		if (stack[iter].index < result)
			result = stack[iter].index;
		++iter;
	}
	return (result);
}

int	highest(t_stack *stack)
{
	int	result;
	int	iter;

	result = -1;
	iter = 0;
	while (stack[iter].active)
	{
		if (stack[iter].index > result)
			result = stack[iter].index;
		++iter;
	}
	return (result);
}

void	update_new_actions(t_list *new_actions[], int option)
{
	t_list	*tmp;

	tmp = *new_actions;
	while (tmp != NULL)
	{
		tmp->content += option;
		tmp = tmp->next;
	}
}

void	orient_start(t_stack *stack[], t_list *actions[])
{
	t_stack	*tmp;
	int		to_find;
	int		high;
	int		low;

	high = highest(*stack);
	low = lowest(*stack);
	tmp = *stack;
	while (tmp[0].index != low && tmp[0].index != high)
		exec_empty(R, actions, stack);
	if (tmp[0].index == low)
		to_find = high;
	else
		to_find = low;
	while (tmp[1].index != to_find)
	{
		exec_empty(S, actions, stack);
		exec_empty(R, actions, stack);
	}
	if (tmp[0].index == low)
		exec_empty(S, actions, stack);
	exec_empty(R, actions, stack);
}

void	orient(t_stack *stack[], int option, t_list *actions[])
{
	t_list	*new_actions;

	if ((*stack)[0].active == 0)
		return ;
	new_actions = NULL;
	orient_start(stack, &new_actions);
	update_new_actions(&new_actions, option);
	if (ft_lstlast(*actions) != NULL)
		ft_lstlast(*actions)->next = new_actions;
	else
		*actions = new_actions;
}
