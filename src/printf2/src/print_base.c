/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:55:03 by vdenisse          #+#    #+#             */
/*   Updated: 2023/05/08 12:59:10 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_string_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr_base(unsigned int nr, char *base)
{
	int		baselen;
	char	digits[100];
	int		digit;
	int		printed;

	if (nr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	baselen = ft_string_len(base);
	digit = 0;
	printed = 0;
	while (nr > 0)
	{
		digits[digit++] = base[nr % baselen];
		nr /= baselen;
	}
	while (--digit >= 0)
	{
		write(1, &digits[digit], 1);
		++printed;
	}
	return (printed);
}
