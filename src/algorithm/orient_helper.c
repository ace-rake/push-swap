/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orient_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:23:30 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/29 11:40:42 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	case_finder(int lowest_pos, int highest_pos, int size)
{
	int	casef;
	int	caseb;
	int	casefb;
	int	casebf;

	casef = highest_pos;
	if (lowest_pos > highest_pos)
		casef = lowest_pos;
	caseb = size - highest_pos;
	if (lowest_pos < highest_pos)
		caseb = size - highest_pos;
	casefb = 2 * (size - caseb) + (size - casef);
	casebf = 2 * (size - casef) + (size - caseb);
	if (casef <= caseb && casef <= casefb && casef <= casebf)
		return (11);
	if (caseb <= casef && caseb <= casefb && caseb <= casebf)
		return (22);
	if (casefb <= caseb && casefb <= casef && casefb <= casebf)
		return (12);
	if (casebf <= caseb && casebf <= casef && casebf <= casefb)
		return (21);
	return (0);
}

int	smart_orient_finder(t_stack stack[], int highest, int lowest)
{
	int	lowest_pos;
	int	highest_pos;
	int	size;

	size = last_active(stack)->pos;
	lowest_pos = 0;
	highest_pos = 0;
	while (stack[lowest_pos].index != lowest)
		lowest_pos++;
	while (stack[highest_pos].index != highest)
		highest_pos++;
	return (case_finder(lowest_pos, highest_pos, size));
}
