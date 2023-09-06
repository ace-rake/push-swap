/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:03:59 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/29 13:09:30 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static const char	*get_macro_name(int value)
{
	if (value == EMPTY)
		return ("");
	if (value == RA)
		return ("ra");
	else if (value == RB)
		return ("rb");
	else if (value == RR)
		return ("rr");
	else if (value == RRA)
		return ("rra");
	else if (value == RRB)
		return ("rrb");
	else if (value == RRR)
		return ("rrr");
	else if (value == PA)
		return ("pa");
	else if (value == PB)
		return ("pb");
	else if (value == SA)
		return ("sa");
	else if (value == SB)
		return ("sb");
	else
		return ("ss");
}

void	print_instructions(t_list *actions)
{
	if (actions->content == EMPTY)
		actions = actions->next;
	while (actions != NULL)
	{
		ft_printf("%s\n", get_macro_name(actions->content));
		actions = actions->next;
	}
}
