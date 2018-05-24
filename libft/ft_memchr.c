/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:25:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/23 13:46:38 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_void	ft_memchr(t_cvoid str, int c, size_t n)
{
	t_ustr		ret;
	size_t		i;

	i = 0;
	ret = (t_ustr)str;
	while (i < n)
	{
		if (ret[i] == (unsigned char)c)
			return (ret + i);
		i++;
	}
	return (NULL);
}
