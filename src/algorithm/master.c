/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:30:38 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/09 10:20:46 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	master(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[])
{
	rotate_push_start(stack_a, stack_b, actions);
	(void)stack_b;
	return (0);
}
