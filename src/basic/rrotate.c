/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:00:28 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/05 12:02:41 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	rrotate(t_stack *stack[])
{
	t_stack	tmp;
	int		i;
	t_stack	*tmp_stack;

	tmp_stack = *stack;
	if (tmp_stack[0].active == 0 || tmp_stack[1].active == 0)
		return (0);
	i = last_active(tmp_stack)->pos;
	tmp = tmp_stack[i];
	while (i >= 1)
	{
		tmp_stack[i].content = tmp_stack[i - 1].content;
		tmp_stack[i].index = tmp_stack[i - 1].index;
		--i;
	}
	tmp_stack[0].content = tmp.content;
	tmp_stack[0].index = tmp.index;
	*stack = tmp_stack;
	return (1);
}
