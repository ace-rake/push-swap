/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:59:33 by vdenisse          #+#    #+#             */
/*   Updated: 2023/05/08 13:44:54 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

static int	ft_int_len(unsigned long long n)
{
	size_t	len;

	len = 0;
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_gen(char *result, unsigned long long nbr, int len)
{
	if (nbr != 0)
		result = malloc(sizeof(char) * (len + 1));
	else
		return (result = ft_strdup("0"));
	if (!result)
		return (0);
	result[len] = '\0';
	while (len--)
	{
		result[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}

char	*ft_ulltoa(unsigned long long nbr)
{
	int		len;
	char	*result;

	len = ft_int_len(nbr);
	result = 0;
	result = ft_gen(result, nbr, len);
	if (!result)
		return (0);
	return (result);
}
