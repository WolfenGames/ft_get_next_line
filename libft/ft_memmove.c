/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:16:25 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/23 13:48:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_void	ft_memmove(void *str1, const void *str2, size_t n)
{
	t_str	dest;
	t_str	src;
	size_t	i;

	dest = (t_str)str1;
	src = (t_str)str2;
	i = 0;
	if (str2 < str1)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest[i] = src[i];
		}
	}
	else
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
