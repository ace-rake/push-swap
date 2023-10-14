/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:03:59 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/14 12:38:49 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

const char	*get_macro_name(int value)
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
	else if (value == SS)
		return ("ss");
	return (NULL);
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
