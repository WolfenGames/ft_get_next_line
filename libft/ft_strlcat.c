/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:44:31 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/28 14:32:55 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	while (i < size && *dest && *(dest++))
		i++;
	l = size - i;
	if (!l)
		return (i + ft_strlen((char *)src));
	while (*src)
	{
		if (l != 1)
		{
			*(dest++) = *src;
			l--;
		}
		src++;
		i++;
	}
	*dest = '\0';
	return (i);
}
