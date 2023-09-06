/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <vdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:00:15 by vdenisse          #+#    #+#             */
/*   Updated: 2023/07/06 12:04:55 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		amount;
	t_list	*actions;

	amount = argc - 1;
	stack_a = ft_init(amount, argv);
	if (error_check(amount, stack_a, argv))
		return (1);
	stack_b = ft_init_empty(amount);
	actions = ft_lstnew(EMPTY);
	if (amount <= 5)
		hardcode(&stack_a, &stack_b, &actions);
	else
		master(&stack_a, &stack_b, &actions);
	optimize(&actions);
	print_instructions(actions);
	free(stack_a);
	free(stack_b);
	ft_lstclear(&actions);
	return (0);
}
