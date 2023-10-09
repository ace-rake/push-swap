/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:32:29 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/09 13:33:24 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	remove_next_2(t_list **pre)
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
