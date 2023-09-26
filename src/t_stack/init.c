/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:38:56 by vdenisse          #+#    #+#             */
/*   Updated: 2023/07/06 13:54:14 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*ft_init_empty(int amount)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = (t_stack *)malloc((amount) * sizeof(t_stack));
	if (!stack)
		return (0);
	while (i < amount)
	{
		stack[i].content = 0;
		stack[i].pos = i;
		stack[i].index = -1;
		stack[i].active = 0;
		i++;
	}
	return (stack);
}

t_stack	*ft_init(int amount, char *argv[])
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = (t_stack *)malloc((amount) * sizeof(t_stack));
	if (!stack)
		return (0);
	while (i < amount)
	{
		stack[i].content = ft_atoi(argv[i + 1]);
		stack[i].pos = i;
		stack[i].index = -1;
		stack[i].active = 1;
		i++;
	}
	indexer(&stack, amount);
	return (stack);
}

void	ft_prnt_lst(t_stack *stack, int amount)
{
	int	i;

	if (stack == NULL || amount == 0)
	{
		ft_printf("stack is empty\n");
		return ;
	}
	i = -1;
	ft_printf("\n");
	while (++i < amount)
		ft_printf("pos [%d] : content [%d] : index [%d] : active [%d]\n",
					stack[i].pos,
					stack[i].content,
					stack[i].index,
					stack[i].active);
	ft_printf("\n");
}
