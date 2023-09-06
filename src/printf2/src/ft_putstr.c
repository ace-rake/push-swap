/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:44:24 by vdenisse          #+#    #+#             */
/*   Updated: 2023/05/08 13:38:40 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_string_printer(const char *str)
{
	int	len;

	if (!str)
	{
		len = write(1, "(null)", 6);
		return (len);
	}
	else
	{
		len = (int)ft_strlen(str);
		ft_putstr_fd((char *)str, 1);
	}
	return (len);
}

int	ft_character_printer(int chr)
{
	char	str[2];

	if (!chr)
		return (write(1, "\0", 1));
	str[0] = (char)chr;
	str[1] = '\0';
	return (ft_string_printer(str));
}

//fix this
int	ft_uint_printer(unsigned int nbr)
{
	int		printed;
	char	*str;

	str = ft_ulltoa(nbr);
	printed = ft_string_printer(str);
	free(str);
	return (printed);
}

int	ft_number_printer(int nbr)
{
	char	*str;
	int		printed;

	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	printed = ft_string_printer(str);
	free(str);
	return (printed);
}
