/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:00:21 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/01 10:56:43 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	rotate(t_stack *stack[])
{
	t_stack	tmp;
	int		i;
	t_stack	*tmp_stack;
	int		last_active_pos;

	tmp_stack = *stack;
	if (tmp_stack[0].active == 0 || tmp_stack[1].active == 0)
		return (0);
	tmp = tmp_stack[0];
	last_active_pos = last_active(*stack)->pos;
	i = 0;
	while (i < last_active_pos)
	{
		tmp_stack[i].content = tmp_stack[i + 1].content;
		tmp_stack[i].index = tmp_stack[i + 1].index;
		++i;
	}
	tmp_stack[last_active_pos].index = tmp.index;
	tmp_stack[last_active_pos].content = tmp.content;
	*stack = tmp_stack;
	return (1);
}
