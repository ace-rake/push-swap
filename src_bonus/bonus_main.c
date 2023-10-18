/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:00:22 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/18 10:01:19 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*actions;

	stack_a = ft_init(argc - 1, argv);
	if (error_check(argc - 1, stack_a, argv))
		return (1);
	stack_b = ft_init_empty(argc - 1);
	actions = NULL;
	if (ft_read_actions(&actions) == 0)
		ft_exec_all(&stack_a, &stack_b, actions);
	else
		write(1, "Error\n", 6);
	if (is_done(&stack_a) && stack_b[0].active == 0 && stack_a[0].index == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_a);
	free(stack_b);
	ft_lstclear(&actions);
}
