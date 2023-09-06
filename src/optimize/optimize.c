/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:50:08 by vdenisse          #+#    #+#             */
/*   Updated: 2023/07/06 13:56:54 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	remove_next_2(t_list **pre)
{
	t_list	*to_del;
	t_list	*two_del;
	t_list	*tmp;

	tmp = *pre;
	to_del = tmp->next;
	two_del = tmp->next->next;
	tmp->next = two_del->next;
	free(two_del);
	free(to_del);
}

int	a_check_r_rr_to_0(t_list **actions)
{
	t_list	*tmp;
	int		action_done;
	t_list	*pre;

	tmp = *actions;
	action_done = 0;
	pre = NULL;
	while (tmp->next != NULL)
	{
		if ((tmp->content == RA && tmp->next->content == RRA)
			|| (tmp->content == RRA && tmp->next->content == RA))
		{
			remove_next_2(&pre);
			action_done++;
		}
		else
		{
			pre = tmp;
			tmp = tmp->next;
		}
	}
	return (action_done);
}

int	b_check_r_rr_to_0(t_list **actions)
{
	t_list	*tmp;
	int		action_done;
	t_list	*pre;

	tmp = *actions;
	action_done = 0;
	pre = NULL;
	while (tmp->next != NULL)
	{
		if ((tmp->content == RB && tmp->next->content == RRB)
			|| (tmp->content == RRB && tmp->next->content == RB))
		{
			remove_next_2(&pre);
			action_done++;
		}
		else
		{
			pre = tmp;
			tmp = tmp->next;
		}
	}
	return (action_done);
}

int	px_py_delete(t_list *actions[])
{
	t_list	*tmp;
	int		action_done;
	t_list	*pre;

	tmp = *actions;
	action_done = 0;
	pre = tmp;
	while (tmp->next != NULL)
	{
		if ((tmp->content == PA && tmp->next->content == PB)
			|| (tmp->content == PB && tmp->next->content == PA))
		{
			remove_next_2(&pre);
			action_done++;
		}
		else
		{
			pre = tmp;
			tmp = tmp->next;
		}
	}
	return (action_done);
}

int	check_start(t_list **actions)
{
	int	action_done;

	action_done = 1;
	while (action_done != 0)
	{
		action_done = 0;
		action_done += a_check_r_rr_to_0(actions);
		action_done += b_check_r_rr_to_0(actions);
		action_done += px_py_delete(actions);
	}
	return (action_done);
}

void	optimize(t_list **actions)
{
	int	i;

	i = 0;
	if (*actions == NULL)
		return ;
	while (check_start(actions) != 0)
		i++;
}
