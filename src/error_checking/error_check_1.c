/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:11:07 by vdenisse          #+#    #+#             */
/*   Updated: 2023/07/06 14:17:28 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	ft_nbr_small_enough(char *str)
{
	int		i;
	long	number;
	long	max;

	max = 2147483647;
	number = 0;
	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			max++;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
		if (number > max)
			return (0);
	}
	return (1);
}

int	error_check_1(int amount, char *argv[])
{
	int	iter;

	iter = 0;
	while (++iter <= amount)
	{
		if (!ft_isnumber(argv[iter]))
			return (1);
		if (!ft_nbr_small_enough(argv[iter]))
			return (1);
	}
	return (0);
}

int	error_check_2(int amount, t_stack stack[])
{
	int	i;
	int	j;

	i = 0;
	while (i <= amount)
	{
		j = i + 1;
		while (j <= amount)
			if (stack[i].content == stack[j++].content)
				return (1);
		i++;
	}
	return (0);
}

int	error_check(int amount, t_stack *stack, char *argv[])
{
	if (error_check_1(amount, argv) || error_check_2(amount, stack))
	{
		if (stack)
			free(stack);
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
