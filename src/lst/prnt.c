/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:57:16 by vdenisse          #+#    #+#             */
/*   Updated: 2023/07/06 13:57:17 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_lst_prnt(t_list *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		ft_printf("[stack is empty]\n");
	while (stack != NULL)
	{
		ft_printf("id : [%d] : action : [%d]\n", i, stack->content);
		stack = stack->next;
		i++;
	}
}
