/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:30:34 by vdenisse          #+#    #+#             */
/*   Updated: 2023/05/08 13:46:03 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total_printed;

	va_start(args, str);
	total_printed = ft_print(str, args);
	va_end(args);
	return (total_printed);
}

int	ft_print(const char *str, va_list args)
{
	int		index;
	va_list	*p_args;
	int		total_printed;

	p_args = (va_list *)args;
	index = 0;
	total_printed = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '%')
			total_printed += ft_print_chooser(str, index++, p_args);
		else
		{
			ft_putchar_fd(str[index], 1);
			++total_printed;
		}
		index++;
	}
	return (total_printed);
}

int	ft_print_chooser(const char *str, int index, va_list *args)
{
	if (str[index + 1] == 'c')
		return (ft_character_printer(va_arg(*args, int)));
	else if (str[index + 1] == 's')
		return (ft_string_printer(va_arg(*args, const char *)));
	else if (str[index + 1] == 'p')
		return (ft_ptr_printer(va_arg(*args, unsigned long long)));
	else if (str[index + 1] == 'd')
		return (ft_number_printer(va_arg(*args, int)));
	else if (str[index + 1] == 'i')
		return (ft_number_printer(va_arg(*args, int)));
	else if (str[index + 1] == 'u')
		return (ft_uint_printer(va_arg(*args, unsigned int)));
	else if (str[index + 1] == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), HEXA_LOWER));
	else if (str[index + 1] == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), HEXA_UPPER));
	else if (str[index + 1] == '%')
	{
		ft_string_printer("%");
		return (1);
	}
	return (0);
}
