/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:30:38 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/20 15:18:43 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	master(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[])
{
	if (is_done(stack_a) && stack_a[0]->index == 0)
		return (0);
	rotate_push_start(stack_a, stack_b, actions);
	return (0);
}
