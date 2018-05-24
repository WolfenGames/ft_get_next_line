/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:54:20 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 15:03:01 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_void	ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;
	t_str	dest;
	t_str	src;

	dest = (t_str)str1;
	src = (t_str)str2;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
