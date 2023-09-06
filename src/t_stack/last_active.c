/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_active.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:42:12 by vdenisse          #+#    #+#             */
/*   Updated: 2023/07/06 13:52:56 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	highest_index(t_stack stack[])
{
	int	i;
	int	result;

	i = 0;
	result = stack[i].index;
	if (stack[0].active == 0)
		return (-1);
	while (stack[i].active == 1)
	{
		if (stack[i].index > result)
			result = stack[i].index;
		++i;
	}
	return (result);
}

int	lowest_index(t_stack stack[])
{
	int	i;
	int	result;

	i = 0;
	result = highest_index(stack);
	if (stack[0].active == 0)
		return (-1);
	while (stack[i].active == 1)
	{
		if (stack[i].index < result)
			result = stack[i].index;
		++i;
	}
	return (result);
}

t_stack	*last_active(t_stack stack[])
{
	int	i;

	i = 0;
	if (stack[0].active == 0)
		return (ft_init_empty(1));
	while (stack[i + 1].active == 1)
		++i;
	return (&stack[i]);
}
