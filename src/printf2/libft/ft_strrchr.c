/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:02:13 by vdenisse          #+#    #+#             */
/*   Updated: 2023/04/04 14:31:52 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	while (*s != '\0')
		++s;
	if ((char)c != '\0')
		--s;
	while ((char)c != *s)
	{
		if (*s == '\0' || i == len)
			return (0);
		++i;
		--s;
	}
	return ((char *)s);
}
