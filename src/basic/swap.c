/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:00:35 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/01 10:56:48 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	swap(t_stack *stack[])
{
	t_stack	tmp;
	t_stack	*tmp_stack;

	tmp_stack = *stack;
	tmp.content = tmp_stack[0].content;
	tmp.index = tmp_stack[0].index;
	tmp_stack[0].content = tmp_stack[1].content;
	tmp_stack[0].index = tmp_stack[1].index;
	tmp_stack[1].content = tmp.content;
	tmp_stack[1].index = tmp.index;
	*stack = tmp_stack;
	return (1);
}
